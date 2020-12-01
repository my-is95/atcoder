#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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
    int N, K; cin >> N >> K;
    set<int> S;
    rep(i,K){
        int d; cin >> d;
        rep(j,d){
            int A; cin >> A;
            S.insert(A);
        }
    }
    int sum = 0;
    for(int i=1; i<=N; i++){
        if(!S.count(i)) sum++;
    }
    cout << sum << endl;
}