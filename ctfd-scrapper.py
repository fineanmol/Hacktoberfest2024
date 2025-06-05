#!/usr/bin/env python2
from halo import Halo
from cloudscraper import create_scraper
from threading import Thread, Lock
from requests import session
from argparse import Namespace, ArgumentParser
from bs4 import BeautifulSoup
from shutil import make_archive
import logging as log
import requests, json
import sys, os
import re, time

try:
 import queue
except ImportError:
 import Queue as queue

class CTFdScrape(object):
  __userAgent = 'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36'
  __urlParse  = re.compile('(?P<scheme>http.*://)?(?P<host>[^:/ ]+):?(?P<port>[0-9]*)')

  def __init__(self, args):
    self.auth      = dict(name=args.user, password=args.passwd)
    self.url       = self.__parseUrl(args.url)
    self.worker    = args.worker
    self.scheme    = args.scheme
    self.override  = args.override
    self.nofile    = args.no_download
    self.basepath  = args.path
    self.proxies   = args.proxy
    self.cloud     = args.enable_cloud
    self.config    = args.data
    self.archived  = args.export 
    self.starTime  = time.time()
    self.__setEnVar()
     
  def __bypassCloudflareProtection(self):
    with Halo(text='Checking for DDOS Protection') as sp:
      if self.ses.get(self.url, timeout=10).status_code == 503:
        self.ses = create_scraper()
        sp.succeed('DDOS Protection Found')

  def __setEnVar(self):
    # CTFd params
    self.keys    = 'data'
    self.version = 'v.1.0'
    self.dlSize  = 0.0
    self.chcount = 0
    self.files   = []
    self.warns   = []
    self.chals   = {}

    # Persistent session
    self.ses     = session()
    self.helper  = Helper(self.ses)
    self.ses.headers.update({'User-Agent' : self.__userAgent})
    if self.proxies:
      proxy = {'http'  : 'http://%s'%(self.proxies),
               'https' : 'https://%s'%(self.proxies)}
      self.ses.proxies.update(proxy)

    # CTFd Endpoint
    self.ch_url  = self.url + '/api/v1/challenges'
    self.hi_url  = self.url + '/api/v1/hints'
    self.lg_url  = self.url + '/login'

    # Other     
    self.charlst = re.escape('\/:*?"<>|.')
    self.regex   = re.compile(r'(\/files\/)?([a-f0-9]*\/.*\.*\w*)')
    self.escape  = re.compile(r'[%s]|(\s )'%(self.charlst))
    self.travers = True

    #Logging
    if not os.path.exists('logs'):
      os.makedirs('logs')
    m = '\n[%(asctime)s]\n[%(lineno)d-th line] %(message)s\n'
    log.basicConfig(level=log.INFO, filename='logs/debug.log', format=m)
    self.dlError = '{} couldn\'t be downloaded'

  def __login(self):
    try:
      resp  = self.ses.get(self.lg_url)
      soup  = BeautifulSoup(resp.text,'lxml')
      nonce = soup.find('input', {'name':'nonce'}).get('value')
      self.auth['nonce'] = nonce
      self.title = soup.title.string
      resp  = self.ses.post(self.lg_url, data=self.auth)
      return 'incorrect' not in resp.text
    except Exception as e:
      log.error('%s'%(e))

  def __manageVersion(self):
    resp = self.ses.get(self.ch_url)
    if '404' in resp.text:
      self.keys    = 'game'
      self.version = 'v.1.2.0'
      self.ch_url  = self.url + '/chals'
      self.hi_url  = self.url + '/hints'
      self.sol_url = self.ch_url + '/solves'

  def __parseUrl(self, url):
    matches = self.__urlParse.search(url)
    if matches:
      url = matches.group() if matches.group('scheme') else\
      '%s://%s' % (self.scheme, matches.group())
    return url

  def __getHintById(self, id):
    resp = self.ses.get('%s/%s' % (self.hi_url,id)).json()
    return resp['data']['content']

  def __getHints(self, data):
    res = [] 
    for hint in data:
      if hint['cost'] == 0:
        if self.version != 'v.1.2.0':
          res.append(self.__getHintById(hint['id']))
        else:
          res.append(hint['hint'])
    if not res: res.append('-')
    return res

  def __getSolves(self, data):
    if self.version != 'v.1.2.0':
      return data['solves']
    else:
      try:
        return self.solves[str(data['id'])]
      except:
        self.solves = self.ses.get(self.sol_url).json()
        return self.solves[str(data['id'])]

  def __getChallById(self, id):
    try:
      resp = self.ses.get('%s/%s' % (self.ch_url,id)).json()
      return self.__parseData(resp['data'])
    except Exception as e:
      log.error('%s'%(e)) 

  def __getChall(self, q):
    while not q.empty():
      id = q.get()
      ch = self.chals[id]
      if self.auth['name'] and self.auth['password']:
        if self.version != 'v.1.2.0':
          self.chals[id] = self.__getChallById(id)
        else:
          try:
            if self.traverseable:
              self.chals[id] = self.__getChallById(id)
            else:
              self.chals[id] = self.__parseData(ch)
          except:
            self.traverseable = False
            self.chals[id] = self.__parseData(ch)
        self.chals.pop(id) if not self.chals[id] else None
      q.task_done()
    return True

  def __parseData(self, data):
    if data:
      entry = {
        'id'          : data['id'],
        'name'        : self.escape.sub('', data['name']),
        'points'      : data['value'],
        'description' : data['description'],
        'files'       : data['files'],
        'category'    : self.escape.sub('', data['category']),
        'solves'      : self.__getSolves(data),
        'hints'       : self.__getHints(data['hints'])
      }
      # print(json.dumps(entry, sort_keys=True, indent=4))
      return entry

  def __identifyCloudDrive(self, text, path):
    text = text.decode('utf-8')
    if self.cloud:
      drives  = re.compile(r'(drive.google.com)|(dropbox.com)')
      matches = drives.search(text)
      if matches:
        baseurl = matches.group()
        if 'drive.google.com' in baseurl:
          rule  = re.compile(r'(https://)?drive.google.com.*id=([\?/\w=_-]*)')
          match = [id[-1] for id in rule.findall(text)]
          url   = 'https://drive.google.com/uc?id={}'
          return [(path, url.format(id)) for id in match]
        else:
          rule = re.compile(r'(https://)?(www.dropbox.com/.*dl=)')
          matches = rule.findall(text)
          return [(path,''.join(i)+'1') for i in matches]
    return []

  def __downloadHandler(self, data):
    path, url = data  
    if 'google.com' in url:
      self.dlSize += self.helper.gdown(url, path, self.override)
    else:
      rule  = re.compile(r'\?.*')
      name  = rule.sub('', url.split('/')[-1])
      if 'dropbox' not in url:
        url = '%s/files/%s' % (self.url, url)
    
      path = os.path.join(path, name)
      if not os.path.exists(path) or self.override:
        response = self.ses.get(url, stream=True)
        filesize = self.helper.get_content_len(response)
        self.helper.download(response, path)
        if os.path.exists(path):
          self.dlSize += filesize
        else:
          self.warns.append(self.dlError.format(url))

  def __download(self, q):
    while not q.empty():
      data = q.get()
      if not self.nofile or self.override:
        try:
          self.__downloadHandler(data)
        except Exception as e:
          if not self.nofile:
            log.exception('%s'%(e))
      q.task_done()
    return True
      
  def __populate(self, q):
    while not q.empty():
      vals = self.chals[q.get()]
      ns   = Namespace(**vals)
      path = os.path.join(self.path, ns.category, ns.name)
      if not os.path.exists(path):
        os.makedirs(path)

      with open(os.path.join(path, 'README.md'),'wb') as f:
        desc  = ns.description.encode('utf-8').strip()
        name  = ns.name.encode('utf-8').strip()
        cat   = ns.category.encode('utf-8').strip()
        solve = str(ns.solves).encode('utf-8').strip()
        hint  = '\n* '.join(ns.hints).encode('utf-8')
        cont  = '# %s [%s pts]\n\n' % (name, ns.points)
        cont += '**Category:** %s\n' % (cat)
        cont += '**Solves:** %s\n\n' % (solve)
        cont += '## Description\n>%s\n\n' % (desc)
        cont += '**Hint**\n* %s\n\n' % (hint)
        cont += '## Solution\n\n'
        cont += '### Flag\n\n'

        if sys.version_info.major == 2:
          f.write(cont)
        else:
          cont = re.sub(r"(b\')|\'",'',cont)
          f.write(bytes(cont.encode()))

      self.files += [(path, self.regex.search(i).group(2)) for i in ns.files]
      self.files += self.__identifyCloudDrive(desc, path)
      data = self.entry['data'].get(ns.category, list())
      if not data:
        self.entry['data'][ns.category] = data
      data.append(vals)
      q.task_done()
    return True

  def __listChall(self, sp):
    for key,val in self.entry['data'].items():
      sp.start('{0:<30}({1:<0})'.format(key, len(val)))
      sp.succeed()

  def __listWarn(self, sp):
    for val in self.warns:
      sp.warn(val)

  def __Threader(self, elements, action=None):
    que = queue.Queue()
    [que.put(_) for _ in elements]

    for i in range(self.worker):
      worker = Thread(target=action, args=(que, ))
      worker.setDaemon(True)
      worker.start()
    que.join()
    del que

  def authenticate(self):
    self.__bypassCloudflareProtection()
    with Halo(text='\n Authenticating') as sp:
      if not self.__login():
        sp.fail(' Login Failed :(')
        sys.exit()
      sp.succeed(' Login Success')
    self.__manageVersion()
    path = os.path.join(self.basepath, self.title, 'challs.json')
    if os.path.exists(path):
      self.config = path
    if self.config:
      self.parseConfig(self.config)

  def getChallenges(self):
    with Halo(text='\n Collecting challs') as sp:
      try:
        chals = self.ses.get(self.ch_url).json()[self.keys]
        chals = sorted(chals, key=lambda _: _['category']) 
        for chal in chals:
          if not self.chals.get(chal['id']):
            self.chcount += 1
          self.chals[chal['id']] = chal

        if self.chcount > 0:    
          sp.succeed('Found %s new challenges'%(self.chcount))
        else:
      
          sp.warn('There are no new challenges')
      except Exception as e:
        sp.fail('No challenges found :(')
        sys.exit()
    return True

  def createArchive(self):
    orig_path  = os.getcwd()
    self.path  = os.path.join(orig_path, self.basepath, self.title)
    self.entry = dict(url=self.url, title=self.title, data={})
    if not os.path.exists(self.path):
      os.makedirs(self.path)
    os.chdir(self.path)

    with Halo(text='\n Updating Assets') as sp:
      self.__Threader(self.chals, self.__getChall)
      self.__Threader(self.chals, self.__populate)
      self.__Threader(self.files, self.__download)
      # The size output may be wrong (false positive)
      # due to the usage of request.get(url, stream=True) 
      # in order to get the 'Content-Length' header  
      sp.succeed('Found {0:} files ({1:.1f} MB downloaded)'\
        .format(len(self.files),self.dlSize/10**6))
      if self.warns:
        self.__listWarn(sp)

    with open('challs.json','wb') as f:
      data = json.dumps(self.entry ,sort_keys=True, indent=4)
      if sys.version_info.major == 2:
        f.write(data)
      else:
        f.write(bytes(data.encode()))

    if self.archived:
      target = os.path.join(orig_path, self.title)
      with Halo('Saving archive as ZIP') as sp:
        make_archive(target, 'zip', '.')
        sp.succeed('The archive were saved successfully')

  def review(self):
    print('\n[Summary]')
    self.__listChall(Halo())
    print('\n[Finished in {0:.2f} second]'.format(time.time() - self.starTime))

  def parseConfig(self, path):
    with Halo(text='\n Loading an existing data') as sp:
      try:
        with open(path) as config:
          data = json.loads(config.read())
        for vals in data['data'].values():
          for val in vals:
            id = val['id']
            self.chals[id] = val
        if not self.url:
          self.url = data.get('url','')
        self.title = data.get('title','')
        sp.succeed('Loaded %s challs from challs.json'%(len(self.chals)))
      except Exception as e:
        log.error('%s'%(e))
        sp.fail('challs.json No such file or directory')
        sys.exit()

class Helper(object):
  def __init__(self, session):
    self.session = session
 
  def get_confirm_token(self, response):
    for key, value in response.cookies.items():
      if key.startswith('download_warning'):
        return value
    return None

  def find(self, val, text, offset):
    soup = BeautifulSoup(text, 'lxml')
    match = soup.find_all(val)
    if match:
      return match[offset].text
    return ''

  def get_content_len(self, response, val=0):
    headers = response.headers
    val = float(headers.get('Content-Length', 0))
    if not val:
      val  = self.find('span', response.text, -1)
      if val:
        size = val.split()[-1][1:-1]
        if 'M' in size:
          val = float(size[:-1])*10**6
        elif 'G' in size:
          val = float(size[:-1])*10**9
    return val
    
  def get_gdrive_name(self, response):
    head  = response.headers
    rule  = re.compile(r'filename="(.*)"')
    match = rule.search(head.get("Content-Disposition",''))
    if match:
      return match.group(1)
    return self.find('a', response.text, -4)

  def gdown(self, url, path, enable=False):
    baseurl  = 'https://docs.google.com/uc?export=download'
    fileid   = url.split('id=')[1]
    params   = {'id' : fileid}
    session  = requests.session()
    response = session.get(baseurl, params=params, stream=True)
    tokens   = self.get_confirm_token(response)
    filename = self.get_gdrive_name(response)
    filesize = self.get_content_len(response)

    if tokens:
      params.update(dict(confirm=tokens))
    path = os.path.join(path, filename)
    if not os.path.exists(path) or enable:
      respons = session.get(baseurl, params=params, stream=True)
      self.download(respons, path)
      # if os.path.exists(path):
      #   print('success')
    return filesize
      
  def download(self, response, path):
    if response.status_code == 200:
      with open(path, 'wb') as f:
        for chunk in response.iter_content(512*1024):
          if chunk:
            f.write(chunk)
def main():
  parser = ArgumentParser(description='Simple CTFd-based scraper for challenges gathering')
  parser.add_argument('user', nargs='?', metavar='user', type=str, help='Username/email')
  parser.add_argument('passwd', nargs='?', metavar='passwd', type=str, help='Password')
  parser.add_argument('url', nargs='?',  metavar='url', type=str, default='', help='CTFd platform url')
  parser.add_argument('--data', metavar='data', type=str, help='Populate from challs.json')
  parser.add_argument('--proxy', metavar='proxy', type=str, help='Request behind proxy server')
  parser.add_argument('--path', metavar='path', type=str, help='Target directory, default: CTF', default='CTF')
  parser.add_argument('--worker',  metavar='worker', type=int, help='Number of threads, default: 10', default=10)
  parser.add_argument('--scheme',  metavar='scheme', type=str, help='URL scheme, default: https', default='https')
  parser.add_argument('--enable-cloud', help='Permit file download from a cloud drive, default=False', action='store_true')
  parser.add_argument('--override', help='Override existed chall file', action='store_true')
  parser.add_argument('--no-download', help='Don\'t download chall file', action='store_true')
  parser.add_argument('--export', help='Export challenges directory as zip, default=False', action='store_true')
  
  args = parser.parse_args()
  ctf  = CTFdScrape(args)
  
  if args.data or args.url:
    if args.user and args.passwd:
      ctf.authenticate()
      ctf.getChallenges()
    else:
      ctf.parseConfig(args.data)
      ctf.nofile = True
    ctf.createArchive()
    ctf.review()
  else:
    parser.error('too few arguments')

if __name__ == '__main__':
  main()
