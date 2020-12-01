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

const int MAX_N = 20;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    set<int> s;

    rep(i,(1<<n)){
        bitset<MAX_N> b(i);

        int sum = 0;
        rep(j,n){
            if(b.test(j)) sum += a[j];
        }
        s.insert(sum);
    }

    int m; cin >> m;
    rep(_,m){
        int mi; cin >> mi;

        if(s.count(mi)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}