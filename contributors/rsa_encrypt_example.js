const NodeRSA = require('node-rsa');

const key = new NodeRSA({b: 1024});
let secret = 'This is a secret message';

var public_key = key.exportKey('public');
var private_key = key.exportKey('private');

public_key = '-----BEGIN PUBLIC KEY-----\n' +
'MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCV8CMfmNfk28CSszBNOkee0bBq\n' +
'FSnUfOy8x7fKTCZBJ7LHOcXHzViWgmM9rXvey3w3aUx6+esbJd4lA8Nzu/UhyHmz\n' +
'6wSbRQdyI6HISuoKVe/An9NpbrDTUdYkuWiQZNovNtkizrQ0/i08IZY9ydiB3Y/5\n' +
'xVtT/v8jamBqyD/5GQIDAQAB\n' +
'-----END PUBLIC KEY-----';

private_key = '-----BEGIN RSA PRIVATE KEY-----\n' + 
'MIICXQIBAAKBgQCV8CMfmNfk28CSszBNOkee0bBqFSnUfOy8x7fKTCZBJ7LHOcXH\n' +
'zViWgmM9rXvey3w3aUx6+esbJd4lA8Nzu/UhyHmz6wSbRQdyI6HISuoKVe/An9Np\n' +
'brDTUdYkuWiQZNovNtkizrQ0/i08IZY9ydiB3Y/5xVtT/v8jamBqyD/5GQIDAQAB\n' +
'AoGAOp+hnAEOqJSjPriA8jEPP7GM4G1V5ZbSmR0dZyNO8bqr0+lqwywurupcEwl5\n' +
'nSrCboflN0/v9LVhnedSzDV5Khc9PhUPWsnEPPWL59j1AcNGgXvXMnPb/ZahpSOE\n' +
'rwntb6dSC0z2b5RewWlDTO7d5VchDnN4Km7swNg0EcoPm2ECQQD1LP2Kf1D2AIcX\n' + 
'+E1zwBDirjGatKpXgCqTmkuwXfpCvxady4gOPL2OFjsqqHKrIzyae15MHfRh5IAS\n' +
'7k7dIFdrAkEAnI7B3P1W2IID9t90jsiEwb1lHaZ57MPyU/DrmzTC57dA/g+8fXjc\n' +
'HYs8qxzjJ98Hgnoi5sA7Vjf5DTnm3ewGiwJBALt/H5p2CS1IdAfRvTGjFYa1XnwI\n' +
'ZCisfGMK4Y1MIWJADoS4LSFuNCxgNflGfwL/3I3rgM7HLahbfdJ8atVSsWcCQQCS\n' +
'sRSnG12nalOKmx/ctbfmzK6VFKrDlWpXCrPIbqx9b3DfXSFRM9CTgiZrcprJfinM\n' + 
'MOLI8a/nfnTG1s0ifYg3AkAJh5SC6awCkjUp0IcUDpTUWghqCvfTUOvWITm48X1l\n' +
'/mfquD/dlbtyKnMMNKrktAPbfHuXqePZ0NsiHwOTjzhY\n' +
'-----END RSA PRIVATE KEY-----';

let key_private = new NodeRSA(private_key);
let key_public = new NodeRSA(public_key);

var encryptedString = key_public.encrypt(secret, 'base64');

console.log('\n-----------------------------------------------------------------\n');
console.log("Encrypted message: " + encryptedString);
console.log('\n-----------------------------------------------------------------\n');

var decryptedString = key_private.decrypt(encryptedString, 'utf8');

console.log("Decrypted message: " + decryptedString);
console.log('\n-----------------------------------------------------------------\n');