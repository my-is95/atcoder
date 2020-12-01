#include <bits/stdc++.h>
#define fi first
#define se second
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
int getInt(){int x;scanf("%d",&x);return x;}
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
  int n, m; ll l; cin >> n >> m >> l;
  ll dis[n][n];
  rep(i,n){
    rep(j,n){
      dis[i][j] = LINF;
    }
    dis[i][i] = 0;
  }

  rep(i,m){
    int a,b,c; cin >> a >> b >> c; --a,--b;
    if(c<=l) dis[a][b] = dis[b][a] = c;
  }

  rep(k,n){
    rep(i,n){
      if(dis[i][k] == LINF) continue;
      rep(j,n){
        if(dis[k][j] == LINF) continue;
        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
  }

  ll dis2[n][n];
  rep(i,n) {
    rep(j,n){
      dis2[i][j] = LINF;
      if(dis[i][j]<=l) dis2[i][j] = 1;
    }
    dis2[i][i] = 0;
  }

  rep(k,n){
    rep(i,n){
      if(dis2[i][k] == LINF) continue;
      rep(j,n){
        if(dis2[k][j] == LINF) continue;
        dis2[i][j] = min(dis2[i][j], dis2[i][k]+dis2[k][j]);
      }
    }
  }

  int q; cin >> q;
  vl ans;
  rep(_,q){
    int s,t; cin >> s >> t; --s,--t;
    if(dis2[s][t] == LINF) ans.push_back(-1);
    else{
      ans.push_back(dis2[s][t]-1);
    }
  }
  for(ll res: ans) cout << res << endl;
  return 0;
}
