import random

class Codec:

    def encode(self, l):
        pre,post= l.split('//')
        pre+='//'
        uri=post.split('/')
        domain=uri[0]+'/'
        uri.pop(0)
        url='/'.join(uri)        
        n = random.randint(47890665,99999999) 
        self.dic={}
        self.dic['pre']=pre
        self.dic['domain']=domain
        self.dic[str(n)] = url
        s=str(pre)+'tinyurl.com/'+str(n)
        return s


    def decode(self, s):
        tst,n=s.split('.com/')
        ans=self.dic['pre']+self.dic['domain']+self.dic[str(n)]        
        return an
