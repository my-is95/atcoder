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

/*
input

10
25 36 4 55 71 18 0 71 89 65
*/

int main()
{
    int n; cin >> n;
    vector<int> A;
    rep(i,n){
        int p; cin >> p;
        A.push_back(p);
    }
    sort(A.begin(), A.end(), greater<int>());
    rep(i,3){
        cout << A[i] << endl;
    }
}