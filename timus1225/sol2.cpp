#include <bits/stdc++.h>
using namespace std;

long long a[50];


int main() {
    int n;
    cin >> n;

    a[1] = 2;
    a[2] = 2;
    a[3] = 4;
    a[4] = 6;
    for (int i=5; i<=n; i++)
        a[i] = a[i-1] + a[i-2]; 
     
    cout << a[n] << endl;

}
