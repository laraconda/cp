#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << s.size() << endl;

    istringstream ss(s);
    
    int i=0;
    do {
        i++;
        string si;
        ss >> si;
        cout << si << endl;
    } while(ss);
    cout << i << endl;
}
