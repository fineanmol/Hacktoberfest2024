#!/usr/bin/python3
import bencode
import sys
import signal
import itertools
import argparse
import dns.resolver
from socket import *
import hashlib
import urllib
import random
import struct
import binascii
from collections import namedtuple
from collections import OrderedDict
import urllib.request
import traceback
import codecs
import urllib.parse
import string
import time
import threading
import numpy as np
import os
import sched

lock = threading.Lock()
def msg_get_id(data):
	#0 choke
	#1 unchoke
	#2 intrested
	#3 not intrested
	#4 have
	#5 bitfield
	#6 request
	#7 piece
	#8 cancel
	try:
		msg_id = struct.unpack(">B", data[4:5])
		return msg_id[0]
	except:
		return 0	

def get_keep_alive():
	return struct.pack(">L", 0)

def get_handshake_msg(info_hash, peer_id):
	info_hash = hashlib.sha1(bencode.bencode(file_info)).hexdigest()
	packet_hashes = ""
	packet_hashes = bytearray(packet_hashes, 'utf-8') + binascii.unhexlify(info_hash)
	return chr(19).encode() + bytes("BitTorrent protocol", 'utf-8') + (chr(0) * 8).encode() + packet_hashes + peer_id.encode()

def make_piece_request(pieces, piece_length, size):
	'''
	4 bytes length (13)
	1 byte msg_id (6)
	4 byte index
	4 byte begin(offset)
	4 byte length (16 KB)
	'''
	length = 13
	msg_id = 6
	lock.acquire()
	try:
		INDEX = piece_index.index(0)
		piece_index[INDEX] = -1

	except:
		INDEX = piece_index.index(-1)
		piece_index[INDEX] = 0
	lock.release()
	begin_offset = block_offset[INDEX]
	x = piece_length - block_offset[INDEX]
	if x >= 16384:
		req_length = 16384
	else:
		req_length = x
	req_packet = struct.pack(">IBIII", length, msg_id, INDEX, begin_offset, req_length)
	return req_packet


def write_into_file(name, data, piece_length):
	global downloaded
	f = open(name, 'ab')
	length, msg_id, index, offset = struct.unpack(">IBII", data[:13])
	INDEX = index
	f.seek(int((index * piece_length) + offset), 0)
	bytes_written = f.write(data[13:])
	f.close()
	downloaded = downloaded + bytes_written
	print(downloaded)
	lock.acquire()
	if block_offset[INDEX] + bytes_written <= piece_length:
		block_offset[INDEX] = block_offset[INDEX] + bytes_written
		if block_offset[INDEX] == piece_length:
			piece_index[INDEX] = 1
	if block_offset[INDEX] + bytes_written > piece_length:
		extra = (block_offset[INDEX] + bytes_written) - piece_length
		block_offset[INDEX] = piece_length
		block_offset[INDEX + 1] = extra		
	lock.release()
	f.close()

def make_intrested_request():
	return struct.pack(">IB", 1, 2)

def make_choke():
	return struct.pack(">IB", 1, 0)

def make_unchoke():
	return struct.pack(">IB", 1, 1)

def send_piece(name, r_index, r_begin, r_length, piece_length):
	f = open(name, 'rb')
	f.seek(int((r_index * piece_length) + r_begin), 0)
	bytes_data = f.read(r_length)
	d = struct.pack(">IBII", len(bytes_data) + 9, 7, r_index, r_begin)
	return d + bytes_data

def connect_to_peers(ip_port, file_info, peer_id, pieces, piece_length, size, name):
	p_choked = True  # peer is choked
	p_intrested = False # peer is not intrested
	m_chocked = True # i am chocked
	m_intrested = False # i am not intrested
	block = b''
	clientSocket = socket(AF_INET, SOCK_STREAM)
	u = ip_port.split(':')
	ip = u[0]
	port = int(u[1])
	no_bytes = int(size / (piece_length * 8) + 6)
	try:
		clientSocket.settimeout(10)
		clientSocket.connect((ip, port))
		handshake_msg = get_handshake_msg(info_hash, peer_id)
		clientSocket.send(handshake_msg)
		time.sleep(1)
		handshake_response = clientSocket.recv(68)
		start = time.time()
		try:
			bitField = clientSocket.recv(no_bytes)
			msg_type = msg_get_id(bitField)
			if msg_type == 5:
				x = np.fromstring(bitField, dtype=np.uint8)
				m = np.unpackbits(x)
				a = list(m) #piece list
				bit_field = a[40:]
		except:
			print("Bitfield Not Sent By Peer")
			pass
		msg_type = 0 #choke
		try:
			first_msg = clientSocket.recv(5)
			msg_type = msg_get_id(first_msg)
		except:
			pass
		if msg_type != 1 :#CHOKE
			#send Intrested
			intrested_req = make_intrested_request()
			clientSocket.send(intrested_req)
			first_msg = clientSocket.recv(5)
			msg_type = msg_get_id(first_msg)
			if msg_type == 0:   #still choke
				return
		if msg_type == 1 :#UNCHOKE
			while True:
				clientSocket.settimeout(10)
				try:
					m = clientSocket.recv(5)
					if len(m) == 0:
						n = -1 #no message from peer
					else:
						n = msg_get_id(m)
					if  n == 2:
						p_intrested = True
						unchoke = make_unchoke()
						clientSocket.send(unchoke)
						p_choked = False
					elif n == 3:
						p_intrested = False
						choke = make_choke()
						clientSocket.send(choke)
						p_choked = True

					elif n == 4:
						p = clientSocket.recv(4)
						have_piece_index = struct.unpack(">L", p)
						#update in bitfiled
						#request this piece

					elif n == 6:
						try:
							print("piece request has arrived")
							p = clientSocket.recv(12)
							print(m)
							print(p)
							r_index, r_begin, r_length = struct.unpack(">LLL", p)
							print(r_index, r_begin, r_length )
							r_piece = send_piece(name, r_index, r_begin, r_length, piece_length)
							clientSocket.send(r_piece)
							print("piece SentS")
						except:
							print("error :", traceback.format_exc())
				except:	
					piece_req = make_piece_request(pieces, piece_length, size)
					clientSocket.send(piece_req)
					time.sleep(3)
					piece = clientSocket.recv(16397)
					if (len(piece) == 16397):
						if msg_get_id(piece) == 7:
							write_into_file(name, piece, piece_length)
						if downloaded == size:
							print("File downloaded successfully")
							return
					else:
						time.sleep(5)
						clientSocket.recv(16397)
	except timeout:
		print("error :", traceback.format_exc())
		clientSocket.close()
		return


def get_peer_id():
	letters = string.ascii_lowercase
	return "MS001" +''.join(random.choice(letters) for i in range(15))

def udp_transaction_id():
    return random.randint(1,65535)

def download_file():
	pass

def update_peers(trak_list, file_info, size, peer_id):
	print("trying for new peers")
	time.sleep(120)
	peers_ = []
	for m in tracker_list:
		for n in m:
			k = connect_to_tracker(j, file_info, size, peer_id)
			peers_.append(k)
	peer_1 = [i for i in peers_ if i] 
	peeers_ = list(itertools.chain(*peer_1))
	peers_ = list(set(peeers_))
	return peers_


def connect_to_tracker(hostname, file_info, size, peer_id):
	host = hostname
	url_parts = urllib.parse.urlparse(hostname)
	port = url_parts.port
	print(port)
	protocol = url_parts.scheme
	url = url_parts.hostname
	try:
		address = getaddrinfo(url, port)
	except:
		return
	ip_list = []
	ip = address[0][4][0]
	ip_list.append(ip)
	info_hash = hashlib.sha1(bencode.bencode(file_info)).hexdigest()
	if protocol == "https":
		return
	if protocol == "http":
		for i in ip_list:
			if len(i) > 15:
				return
			clientSocket = socket(AF_INET, SOCK_STREAM)
			try:
				x  = codecs.decode(info_hash, 'hex')
				headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.3'}
				req_parameters = OrderedDict()
				req_parameters['info_hash'] = x
				req_parameters['peer_id'] = peer_id
				req_parameters['port'] = 6881
				req_parameters['uploaded'] = uploaded
				req_parameters['downloaded'] = downloaded
				req_parameters['left'] = left
				req_parameters['numwant'] = 20
				req_parameters['key'] = "5fdd3f95"
				req_parameters['compact'] = 1
				req_parameters['event'] = 'started'
				request = urllib.parse.urlencode(req_parameters)
				packet = hostname + '?' + request				
				req = urllib.request.Request(packet, headers = headers)
				req1 = urllib.request.urlopen(req)
				http_resp = req1.read()
				print(http_resp)
				try :
					http_response = bencode.decode(http_resp)
				except:
					print("error :", traceback.format_exc())
					clientSocket.close()
					return
				http_peers = http_response['peers']
				peer_list = []
				n_http_peers = (len(http_peers)) // 6
				for x in range(n_http_peers):
					m = struct.unpack(">BBBBH", http_peers[x*6:(6 + x*6)])
					m = list(m)
					r = str(m[0]) + '.' + str(m[1]) + '.' + str(m[2]) + '.' + str(m[3]) + ':' + str(m[4])
					peer_list.append(r)
				clientSocket.close()
				return peer_list
			except:
				print("error :", traceback.format_exc())
				clientSocket.close()
				return
				print("error :", traceback.format_exc())
		clientSocket.close()
	else: 
		for i in ip_list:
			clientSocket = socket(AF_INET, SOCK_DGRAM)
			s_port = clientSocket.getsockname()[1]

			"""CONNECTION_ID REQUEST TO UDP TRACKER"""
			try:
				protocol_id =  0x41727101980
				transaction_id = udp_transaction_id()

				packet = struct.pack(">QLL", protocol_id, 0, transaction_id)
				# 0 is action to connect
				clientSocket.sendto(packet, (i, port))
				try:
					clientSocket.settimeout(1)
					res = clientSocket.recv(16)
				except timeout:
					clientSocket.close()	
					return
				action, transaction_id_rec, connection_id = struct.unpack(">LLQ", res)

				"""ANNOUNCE R and REQUEST TO UDP TRACKERS"""				
				transaction_id = udp_transaction_id()
				peer_id_ = peer_id.encode('utf-8')
				packet_hashes = ""
				packet_hashes = bytearray(packet_hashes, 'utf-8') + binascii.unhexlify(info_hash)
				packet = struct.pack(">QLL20s20sQQQLLLlH", connection_id, 1, transaction_id, packet_hashes, peer_id_, 0, size, 0, 2, 0, 0, -1, s_port)
				# 1 is action to announce
				clientSocket.sendto(packet, (i, port)) #sending packet
				try:
					clientSocket.settimeout(2)
					res1 = clientSocket.recvfrom(1024) #receiving Response

					# unpacking Response from UDP Tracker
					action, transaction_id_rec, interval, leechers, seeders = struct.unpack(">LLLLL", res1[0][:20])
					l = []
					peer_no = (len(res1[0]) - 20) / 6
					n = int(peer_no)
					for z in range(n):
						t = struct.unpack(">BBBBH", res1[0][20+(z*6):26+(z*6)])
						t = list(t)
						ku = ".".join(map(str,t))
						mux = ku[::-1].replace('.',':', 1)
						l.append(mux[::-1])					
				except timeout:
					pass
				
				"""SCRAPE REQUEST TO UDP TRACKERS"""	
				#sending scrape request
				packet = struct.pack(">QLL", connection_id, 2, transaction_id) + packet_hashes
				clientSocket.sendto(packet, (i, port))
				torrent_details = {}
				try:
					#receiving response for scrape request
					clientSocket.settimeout(1)
					res = clientSocket.recv(8 + 12* len(info_hash))
				except timeout:
					clientSocket.close()	
					return
				action_scrape, transaction_id_rec, seeders, completed, leechers = struct.unpack(">LLLLL", res)
				torrent_details[info_hash] = (seeders, leechers, completed)
				#print("scrape Response :")
				#print("seeders, leechers, completed", torrent_details[info_hash])
				clientSocket.close()
				return l
			except:
				pass
		clientSocket.close()


"""
	Execution starts from Below
"""

#extracting file details ->trackers, info, and other
#created by	
#info has name, length, piece length, private, pieces
#working on info
'''def keep_listening():
	serverSocket = socket(AF_INET,SOCK_STREAM)
	serverSocket.bind(('',6881))
	serverSocket.listen(100)
	while True:
		Connected, addr = serverSocket.accept()
		p_list.append(connectionSocket)
		x = crea
connectionSocket.close()
server.close()
'''

def make_files(files_details):
	time.sleep(1)


if __name__ == '__main__':
	file = open(sys.argv[1], "rb")
	MetaData = bencode.bdecode(file.read())
	file_info = MetaData["info"]
	name = file_info["name"]
	global pieces
	pieces = file_info["pieces"]
	pqr = pieces[0]
	xyz = hashlib.sha1(bencode.bencode(pqr)).hexdigest()
	mno = ""
	mno = bytearray(mno, 'utf-8') + binascii.unhexlify(xyz)
	if os.path.isfile(name):
		os.remove(name)
	try:
		created_by = MetaData["created by"]
	except:
		pass
	try:
		date = MetaData["creation date"]
	except:
		pass
	try:
		tracker_list = MetaData["announce-list"]
		announce = True		
	except:
		tracker_list = MetaData["announce"]
		announce = False
	try:
		comments = MetaData["comment"]
		print("comment: " + comments)
	except:
		pass
	try:
		encoding = d["encoding"]
		print("encoding :" +str(encoding))
	except:
		pass
	try:
		private = file_info["private"]
	except:
		pass
	piece_length = file_info["piece length"]
	files_details = []
	if "files" in file_info.keys():
		#multiple file
		single_file = False
		files_details = []
		mul_file = file_info["files"]
		for i in range(len(mul_file)):
			file_path = mul_file[i]["path"]
			file_length = mul_file[i]['length']
			files_details.append([file_length, file_path])
	else:
		#single file
		single_file = True
		size = file_info["length"]
		files_details.append([size,[name]])
		file = open(name, "w")
		file.close()

	#print(files_details)
	#make_files(files_details, name)
	file = open(name, "w")
	file.close()
	print("Name: " + 	name)
	print("Piece Length: " + str(piece_length))
	print("tracker_list:")
	print(tracker_list)
	peer_id = get_peer_id()

	try:
		print("created_by : " +created_by)
	except:
		pass
	try:
		print("comment: " + comments)
	except:
		pass
	try:
		print("encoding :" +str(encoding))
	except:
		pass
	try:
		print("private_file: " + private)
	except:
		pass
	size = 0
	for i in range(len(files_details)):
		print(files_details[i])
	for k in range(len(files_details)):
					x = files_details[k][0]
					size = x + size
	print("Size :" + str(size))

	no_of_pieces = int(size/piece_length)
	if no_of_pieces == 0:
		no_of_pieces = 1
	global piece_index
	piece_index = [0 for i in range(no_of_pieces)]
	global block_offset
	block_offset = [0 for i in range(no_of_pieces)]
	global INDEX
	global downloaded
	downloaded = 0
	global left
	left = size
	global uploaded
	uploaded = 0

	info_hash = hashlib.sha1(bencode.bencode(file_info)).hexdigest()
	print(info_hash)
	packet_hashes = ""
	packet_hashes = bytearray(packet_hashes, 'utf-8') + binascii.unhexlify(info_hash)
	peer_list = []
	if announce:
		for i in tracker_list:
			for j in i:
				p = connect_to_tracker(j, file_info, size, peer_id)
				#print(p)
				peer_list.append(p)

	else :
		p = connect_to_tracker(tracker_list[0], file_info, size, peer_id)
		peer_list.append(p)

	peer_list1 = [i for i in peer_list if i] 
	peeers = list(itertools.chain(*peer_list1))
	peers = list(set(peeers))
	print(len(peers))
	print(peers)	
	threads = []
	for i in peers:
		peer_connection = threading.Thread(target = connect_to_peers, args = (i, file_info, peer_id, pieces, piece_length, size, name))
		threads.append(peer_connection)
		peer_connection.start()
		
		
