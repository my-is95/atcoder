#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/



int main()
{
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;

    string t;
    cin >> t;

    int add[n][3];
    rep(i,n) rep(j,3) add[i][j] = 0;
    rep(i,n){
        if(t[i] == 's') add[i][0] = r;
        else if(t[i] == 'p') add[i][1] = s;
        else add[i][2] = p;
    }

    rep(i,n){
        rep(j,3){
            rep(l,3){
                if(i >= k && j == l) continue;
                dp[i][]
            }
        }
    }
}