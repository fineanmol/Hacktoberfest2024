class Base64 {
  encode(str) {
    return Buffer.from(str).toString('base64');
  }

  decode(base64) {
    return Buffer.from(base64String, 'base64').toString('ascii');
  }
}
