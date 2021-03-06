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


int main() {
  int n,m; cin >> n >> m;
  vl a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  ll dp[n+1][m+1];
  rep(i,n+1) rep(j,m+1) dp[i][j] = 0;
  rep(i,n){
    rep(j,m){
      if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j]+1;
      else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }

  ll ans = LINF;
  rep(i,n+1){
    rep(j,m+1){
      ll now = 0;
      now += n-i;
      now += m-j;
      now += i-dp[i][j];
      now += j-dp[i][j];
      ans = min(ans, now);
    }
  }
  cout << ans << endl;
  /*
  
  rep(i,n+1){
    rep(j,m+1){
      cout << dp[i][j] << " ";
    }cout << endl;
  }
  */
  return 0;
}
