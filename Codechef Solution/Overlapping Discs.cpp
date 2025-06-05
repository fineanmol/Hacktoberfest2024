#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define DEBUG(x) cerr << #x << " = " << x << "\n";
template<class T>
ostream& operator<<(ostream&o, const vector<T>&v) {
  o<<'{';
  FOREACH(it,v) o<<*it<<',';
  return o<<'}';
}
typedef long long LL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
string rstring() { char buf[1000]; scanf("%s",buf); return buf; }
//}}}
typedef long double ld;
class INPUT {
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *bufend;
  void grabBuffer();
 public:
  INPUT() { grabBuffer(); }
  bool eof() { return bufend==buffer; }
  char nextChar() { return *bufpos; }
  inline char readChar();
  inline void skipWS();
  inline unsigned readUnsigned();
  inline int readInt();
  inline ld readLD();
};
 
char INPUT::buffer[INPUT::BUFSIZE];
 
void INPUT::grabBuffer() {
  bufpos = buffer;
  bufend = buffer + read(0, buffer, BUFSIZE);
}
 
char INPUT::readChar() {
  char res = *bufpos++;
  if(bufpos==bufend) grabBuffer();
  return res;
}
 
inline bool myisspace(char c) { return c<=' '; }
 
void INPUT::skipWS() {
  while(!eof() && myisspace(nextChar())) readChar();
}
 
unsigned INPUT::readUnsigned() {
  skipWS();
  unsigned res = 0;
vector<Point> points;
 
void readPoints() {
  int n = input.readInt();
  points.clear(); points.reserve(n);
  ld minx = 1e100, maxx = -1e100, miny=1e100, maxy=-1e100;
  REP(i,n) {
    ld x = input.readLD();
    ld y = input.readLD();
    points.push_back(Point(x,y));
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }
  if(maxx-minx>=2 || maxy-miny >= 2) throw 0;
  Point center((minx+maxx)/2, (miny+maxy)/2);
  FOREACH(it, points) *it = *it - center;
}
 
void calcHull() {
  sort(points.begin(), points.end());
  vector<Point> hull;
  hull.push_back(points[0]);
  int st = 0;
  FOR(i,1,size(points)-1) {
    Point p = points[i];
    while(size(hull)-st >= 2 &&
          (hull[size(hull)-1] - hull[size(hull)-2]) %
          (p - hull[size(hull)-2]) <= EPS2) {
      hull.pop_back();
    }
    if(len2(p-hull[size(hull)-1]) > EPS2)
      hull.push_back(p);
  }
  st = size(hull)-1;
  FORD(i,size(points)-1,0) {
    Point p = points[i];
    while(size(hull)-st >= 2 &&
          (hull[size(hull)-1] - hull[size(hull)-2]) %
          (p - hull[size(hull)-2]) <= EPS2) {
      hull.pop_back();
    }
    if(len2(p-hull[size(hull)-1]) > EPS2)
      hull.push_back(p);
  }
  hull.pop_back();
  points.swap(hull);
}
 
vector<int> next,prev,todo;
vector<int> todoStack;
 
Point circleCenter(const Point &a, const Point &b) {
  Point c = 0.5 * (a+b);
  Point ac = c-a;
  ld x2 = len2(ac);
  ld y2 = 1-x2;
  if(y2<=0) throw 0;
  Point res =  c + sqrtl(y2/x2) * turn90(ac);
  return res;
}
 
void process(int x) {
  int a = prev[x];
  int b = next[x];
  if(a==x || b==x || a==b) return;
  Point cen = circleCenter(points[a], points[b]);
  if(len2(cen-points[x]) <= 1+EPS) {
    next[a] = b; prev[b] = a;
    next[x] = -1; prev[x] = -1;
    if(!todo[a]) { todo[a]=1; todoStack.push_back(a); }
    if(!todo[b]) { todo[b]=1; todoStack.push_back(b); }
  }
}
 
vector<Point> answerPoly;
 
void buildAnswerPoly() {
  answerPoly.clear();
  int st = 0;
  while(next[st]==-1) ++st;
  int a = st;
  do {
    int b = next[a];
    Point p = points[a];
    Point q = points[b];
    Point c = circleCenter(p,q);
    answerPoly.push_back(c);
    a = b;
  } while(a!=st);
}
 
ld calcArea() {
  int n = size(answerPoly);
  ld res = 0;
  REP(i,n) {
    Point p = answerPoly[i];
    Point q = answerPoly[(i+1)%n];
    res += 0.5 * (p%q);
    ld d = len(p-q);
    ld alpha = asinl(0.5*d);
    res += alpha;
    res -= 0.5 * sinl(2*alpha);
  }
  return res;
}
 
ld calc() {
  int n = size(points);
  if(n<2) return PI;
  next.resize(n);
  prev.resize(n);
  todo.assign(n,1);
  todoStack.resize(n);
  REP(i,n) {
    next[i] = (i+1)%n;
    prev[i] = (i+n-1)%n;
    todoStack[i] = i;
  }
  while(!todoStack.empty()) {
    int x = todoStack.back();
    todoStack.pop_back();
    todo[x] = 0;
    process(x);
  }
  buildAnswerPoly();
  return calcArea();
}
 
int main() {
  int ntc = input.readInt();
  REP(tc,ntc) {
    ld res;
    try {
      readPoints();
      calcHull();
      res = calc();
    } catch(int) { res = 0; }
    printf("%.6Lf\n", res);
  }
} 
