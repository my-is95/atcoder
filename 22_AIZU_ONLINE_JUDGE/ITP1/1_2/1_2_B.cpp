#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if((a<b) && (b<c)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}