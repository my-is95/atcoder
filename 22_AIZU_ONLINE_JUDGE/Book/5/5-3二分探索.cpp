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

bool linearSearch(int A[], int k, int n){
    A[n] = k;
    int i = 0;
    while(A[i] != k){
        i++;
    }
    // printf("i: %d\n", i);
    return i!=n;
}

bool linearSearch2(int A[], int k, int n){
    rep(i,n){
        if(A[i] == k) return true;
    }
    return false;
}

bool binarySearch(int A[], int k, int n){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] == k) return true;
        else if(A[mid] > k){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return false;
}

int main()
{
    int n; cin >> n;
    int A[n+1];
    rep(i,n) cin >> A[i];
    int q; cin >> q;
    int sum = 0;
    rep(_,q){
        int x; cin >> x;
        if(binarySearch(A, x, n)) sum++;
    }
    cout << sum << endl;

    return 0;
}