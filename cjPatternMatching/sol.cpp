#include <bits/stdc++.h>
using namespace std;

void remas(string& s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '*') {
           s.erase(s.begin() + i); 
        }
    }
}

int getas(string a) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '*') return i;
    }
}

bool mmatch(string a, string b) {
    int i = getas(a);
    int j = getas(b);
    if (i < j) {
        for (int ii = 0; ii<i; ii++) {
            if (a[ii] != b[ii]) return false;
        }
    } else {
        for (int ii = 0; ii<j; ii++) {
            if (a[ii] != b[ii]) return false;
        }
    }
    for (int z=0; z < min((int)a.size() - i - 1, (int)b.size() - j - 1); z++) {
        if (a[(int)a.size() - 1 - z] != b[(int)b.size() - 1 - z]) return false;
    }
    return true;
}


bool createstr(string a, string b, string& str) {
    str.clear();
    if (!mmatch(a, b)) return false;
    int i = getas(a);
    int j = getas(b);
    if (i < j) {
        for (int z=0; z<j; z++) {
            str.push_back(b[z]);    
        }
    } else {
        for (int z=0; z<i; z++) {
            str.push_back(a[z]);    
        }
    }
    str.push_back('*');
    if ((int)a.size() - i > (int)b.size() - j) {
        for (int ii = i+1; ii<(int)a.size(); ii++) {
            str.push_back(a[ii]);
        }
    } else {
        for (int ii = j+1; ii<(int)b.size(); ii++) {
            str.push_back(b[ii]);
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        vector<string> ss(N);
        for (int i=0; i<N;i++) {
            cin >> ss[i]; 
        }

        string str;
        bool m = createstr(ss[0], ss[1], str);
        int i = 2;
        bool pos = m;
        while (i < N && pos) {
            m = createstr(str, ss[i], str);
            if (!m) {
                pos = false;
                break;
            }
            i++;
        }
        string res;
        if (pos) {
            res = str; 
            remas(res);
        } else res = "*";
        cout << "Case #" << t << ": " << res << endl;
    }
}
