#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;


int main() {
  int n;
  ll m;
  cin >> n >> m;
  vi a(n);
  cin >> a;
  sort(rng(a));

  // 累積和を求めている、
  vl s(n+1,0);
  rep(i,n) s[i+1] = s[i]+a[i];

  // 肝になる関数（ラムダ式、[&]はmain関数に含まれている関数外の変数を触ることができるようにするために必要
  // ラムダ式は名前なし関数である。
  auto calc = [&](int x){
    ll tot = 0, num = 0;
    rep(i,n){
      // 行ごとに見ている感じ,合計がx以上になるのが何個あるか見る
      int j = lower_bound(rng(a), x-a[i]) - a.begin();
      num += n-j;
      tot += s[n]-s[j];
      tot += a[i]*ll(n-j);
    }
    return make_pair(tot,num);
  };

  // 二分探索
  int l = 0, r = 200005;  // rは(Ai+Aj)のとりうる最大値
  while(l+1<r){
    int c = (l+r)/2;
    if(calc(c).second >= m) l = c; else r = c;
  }

  auto p = calc(l);
  ll ans = p.first;
  ans -= (p.second-m)*l;
  cout << ans << endl;
  return 0;
}
