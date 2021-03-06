#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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

const ll mod = 1000000007;
const ll jdg = 1000100100100100100;
int n;
string s;
int d;
ll m; 

pair<ll,bool> f(ll a, ll x){
  if(x == 0) return make_pair(1,true);
  bool isok = true;
  if(a>mod && x>=2){
    isok = false;
    a %= mod;
  }
  ll res;
  if(x == 1) res = 1;
  else{
    pair<ll,bool> resp = f(a*a, x/2);
    res = resp.first;
    if(isok) isok = resp.second;
  }
  if(res>mod && a >mod){
    res %= mod;
    a %= mod;
    isok = false;
  }
  if(x%2 == 1) res *= a;
  return make_pair(res,isok);
}

ll solve(ll sinsu){
  ll res = 0;
  bool isover = false;
  for(int i=n-1; i>=0; i--){
    ll keta = n-i-1;
    ll di = s[i]-'0';
    if(di == 0) continue;
    // ここでオーバーフローすることになるので、それを防ぎたい
    ll kake = f(sinsu,keta).first;
    if(kake<0) return true;
    res += di*kake;
  }
  if(res>m){
    isover = true;
  }
  return isover;
}

int main() {
  cin >> s;
  cin >> m;
  n = s.size();
  d = 0;
  rep(i,n){
    int di = s[i]-'0';
    d = max(d,di);
  }
  ll l = d;
  ll r = 1000000000000000001;
  while(l+1<r){
    ll mid = (l+r)/2;
    if(solve(mid)){
      r = mid;
    }else{
      l = mid;
    }
    // cout << mid << endl;
  }
  ll ans = l-d;
  cout << ans << endl;
  
  
  return 0;
}