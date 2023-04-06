#include <bits/stdc++.h>
using namespace std;

bool more(string s) {
    int v = 0;
    int c = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'a' || 
            s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u') {
            v++;
        } else {
            c++; 
        }
    }

    return (v > c);
}

int main () {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        cout << s << endl;
        if (more(s))  
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
