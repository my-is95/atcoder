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
// int getInt(){int x;scanf("%d",&x);return x;}
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
  int h, w; cin >> h >> w;
  int n, m; cin >> n >> m;
  int light[h][w];
  int block[h][w];
  int mass[h][w];
  int mass2[h][w];
  rep(i,h) rep(j,w){
    mass[i][j] = 0;
    mass2[i][j] = 0;
    light[i][j] = 0;
    block[i][j] = 0;
  }
  rep(i,n){
    int ai, bi; cin >> ai >> bi; --ai,--bi;
    light[ai][bi] = 1;
  }

  rep(i,m){
    int ci,di; cin >> ci >> di; --ci,--di;
    block[ci][di] = 1;
  }


  rep(i,h){
    rep(j,w){
      int bjdg = block[i][j];
      int ljdg = light[i][j];
      if(bjdg == 1){
        continue;
      }else if(ljdg == 1){
        mass[i][j] = 1;
      }else{
        if(j != 0 && mass[i][j-1] == 1) mass[i][j] = 1;
      }
    }
  }

  rep(i,h){
    for(int j=w-1; j>=0; j--){
      int bjdg = block[i][j];
      int ljdg = light[i][j];
      if(bjdg == 1){
        continue;
      }else if(ljdg == 1){
        mass[i][j] = 1;
      }else{
        if(j != w-1 && mass[i][j+1] == 1) mass[i][j] = 1;
      }
    }
  }

  rep(j,w){
    rep(i,h){
      int bjdg = block[i][j];
      int ljdg = light[i][j];
      if(bjdg == 1){
        continue;
      }else if(ljdg == 1){
        mass2[i][j] = 1;
      }else{
        if(i != 0 && mass2[i-1][j] == 1) mass2[i][j] = 1;
      }
    }
  }

  rep(j,w){
    for(int i=h-1;i>=0; i--){
      int bjdg = block[i][j];
      int ljdg = light[i][j];
      if(bjdg == 1){
        continue;
      }else if(ljdg == 1){
        mass2[i][j] = 1;
      }else{
        if(i != h-1 && mass2[i+1][j] == 1) mass2[i][j] = 1;
      }
    }
  }
  /*
  rep(i,h){
    rep(j,w) cout << mass[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  rep(i,h){
    rep(j,w) cout << mass2[i][j] << " ";
    cout << endl;
  }
  */

  int cnt = 0;
  rep(i,h) rep(j,w){
    if(mass[i][j] == 1 || mass2[i][j] == 1) cnt++;
  }
  cout << cnt << endl;
  return 0;
}