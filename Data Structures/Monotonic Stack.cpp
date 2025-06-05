#include <bits/stdc++.h>
using namespace std;

using sdata = int;  // can be changed to the type of the item

struct monotonicStack {
  stack<pair<sdata, sdata>> st;  // pair<val, mx>

  void push(const sdata& a) {
    if (st.empty()) {
      st.emplace(a, a);
    } else {
      st.emplace(a, ::max(st.top().second, a));
    }
  }

  void pop() { st.pop(); }
  size_t size() { return st.size(); }
  bool empty() { return st.empty(); }
  const sdata& top() { return st.top().first; }
  const sdata& max() { return st.top().second; }
};

int main() {
  int n;
  cin >> n;

  monotonicStack st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
    cout << st.max() << endl;
  }
  while (!st.empty()) {
    int u = st.top();
    cout << u << endl;
    st.pop();
  }
}
