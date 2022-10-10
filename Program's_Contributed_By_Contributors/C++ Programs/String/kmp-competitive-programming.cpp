/// O(n+m)
int kmp(string &s, string &p) {
  int n = s.size(), m = p.size(), cnt = 0;
  vector<int> pf = prefix_function(p);
  for (int i = 0, j = 0; i < n; i++) {
    while (j && s[i] != p[j])
      j = pf[j - 1];
    if (s[i] == p[j])
      j++;
    if (j == m) {
      cnt++;
      j = pf[j - 1];
    }
  }
  return cnt;
}
