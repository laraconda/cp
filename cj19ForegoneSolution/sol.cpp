#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        string s;
        cin >> s;
        string a(s);
        string bx(s.size(), '0');
        for (int j=s.size()-1; j>=0; j--) {
            if (s[j] == '4') {
               a[j] = '2';
               bx[j] = '2'; 
            }
        }
        string b = "";
        bool done = false;
        for (int j=0; j<bx.size(); j++) {
            if (bx[j] != '0')
                done = true;
            if (done)
                b.append(string(1, bx[j]));
        }
        cout << "Case #" << i << ": "<< a << " " << b << endl;
    }
}
