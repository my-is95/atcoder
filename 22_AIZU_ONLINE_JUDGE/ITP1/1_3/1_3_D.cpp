#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    for(int i=a; i<=b; i++){
        if(c % i == 0) count++;
    }
    cout << count << endl;
}