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
  int n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];

  ll dp[n][n];
  rep(i,n) rep(j,n) dp[i][j] = LINF;
  rep(i,n) dp[i][i] = 0;
  for(int i=2; i<=n; i++){  // 何個分のスライムを合体させるか
    rep(s,n-i+1){ // 開始位置
      int e = s+i-1;
      for(int k=s+1; k<s+i; k++){ // 区切り位置        
        ll l = (k-1 == s ? a[s] : dp[s][k-1]);
        ll r = (k == e ? a[e] : dp[k][e]);
        dp[s][e] = min(dp[s][e], dp[s][k-1]+dp[k][e]+l+r); 
      }
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
