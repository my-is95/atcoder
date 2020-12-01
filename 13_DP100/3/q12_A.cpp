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
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Unionfind
struct uf{
  vi d;
  uf() {};
  uf(int mx) : d(mx,-1) {};
  int root(int x){
    if(d[x]<0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x){ return -d[root(x)];}
  int operator[] (int x) {return root(x);}
  int operator() (int x) {return size(x);}
};

int main() {
  int n,m,W; cin >> n >> m >> W;
  uf dis(n);
  vi w(n), v(n);
  rep(i,n){
    cin >> w[i] >> v[i];
  }
  rep(i,m){
    int a,b; cin >> a >> b; --a,--b;
    dis.unite(a,b);
  }
  vi w2(n,0), v2(n,0);
  rep(i,n){
    w2[dis.root(i)] += w[i];
    v2[dis.root(i)] += v[i];
  }
  int dp[n+1][W+1];
  rep(i,n+1) rep(j,W+1) dp[i][j] = 0;

  rep(i,n){
    rep(j,W+1){
      if(w2[i] == 0 && v2[i] == 0){
        dp[i+1][j] = dp[i][j];
        continue;
      }
      if(j<w2[i]) dp[i+1][j] = dp[i][j];
      else{
        dp[i+1][j] = max(dp[i][j], dp[i][j-w2[i]]+v2[i]);
      }
    }
  }
  cout << dp[n][W] << endl;

  return 0;
}
