function arrayDiff(a, b) {
  return a.filter(element => b.indexOf(element) == -1);
}
