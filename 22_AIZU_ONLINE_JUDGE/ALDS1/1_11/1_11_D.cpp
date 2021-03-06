#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

const int INF = pow(10,6);
const int WHITE=0, GRAY=1, BLACK=2;


bool bfs(int u, int t, vector<vector<int> > G, int N){
    // 初期化
    int color[N], d[N];
    rep(i,N){
        color[i] = WHITE; d[i] = INF;
    }
    queue<int> Q;
    Q.push(u); d[u]=0; color[u]=GRAY;
    while(!Q.empty()){
        int current_u = Q.front(); Q.pop();
        for(int v: G[current_u]){
            if(color[v] == WHITE){
                Q.push(v); d[v]=d[current_u]+1;
                color[v]=GRAY;
            }
        }
        color[current_u] = BLACK;
    }
    if(d[t] == INF) return false;
    else return true;
}

int main()
{
    int N; cin >> N;
    int m; cin >> m;    // 友達関係の数
    vector<vector<int> > G(N);
    rep(i, m){
        int from, to;
        cin >> from >> to;
        G[from].push_back(to);
    }
    int q; cin >> q;
    rep(i, q){
        int f; int t;
        cin >> f >> t;
        if(bfs(f, t, G, N)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}