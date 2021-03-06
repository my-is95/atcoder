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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int N; cin >> N;
    vector<int> W;
    rep(i,N){
        int Wi; cin >> Wi;
        W.push_back(Wi);
    }
    int minS1_S2 = pow(10,5);
    rep(T, N){
        int S1 = 0;
        int S2 = 0;
        for(int i=0; i<=T; i++){
            S1 += W[i];
        }
        for(int i=T+1; i<N; i++){
            S2 += W[i];
        }
        int S1_S2 = abs(S1-S2);
        if(minS1_S2 > S1_S2) minS1_S2 = S1_S2;
    }
    cout << minS1_S2 << endl;
}