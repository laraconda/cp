#include <bits/stdc++.h>
using namespace std;

int first(string s) {
    int count = 0;
    char cu = s[0];
    for (int i=1; i<s.size(); i++) {
        if (s[i] != cu)
            count++;
        if (s[i] != 'U')
            count++;
        cu = 'U';
    }
    return count;
}

int second(string s) {
    int count = 0;
    char cu = s[0];
    for (int i=1; i<s.size(); i++) {
        if (s[i] != cu)
            count++;
        if (s[i] != 'D')
            count++;
        cu = 'D';
    }
    return count;
}

int third(string s) {
    int count = 0;
    char cu = s[0];
    for (int i=1; i<s.size(); i++) {
        if (s[i] != cu)
            count++;
        cu = s[i];
    }
    return count;
}

int main() {
    string s;
    cin >> s;

    cout << first(s) << endl 
    << second(s) << endl
    << third(s) << endl;
}
