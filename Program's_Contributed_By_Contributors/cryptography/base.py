# base64 from hex
#import base64
#from binascii import unhexlify

#hex = unhexlify('72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf')
#flag = base64.b64encode(hex)
#print(flag)


#bytes and big integers
from Crypto.Util.number import bytes_to_long
from Crypto.Util.number import long_to_bytes

data = 11515195063862318899931685488813747395775516287289682636499965282714637259206269
bytes = long_to_bytes(data)
print(bytes)