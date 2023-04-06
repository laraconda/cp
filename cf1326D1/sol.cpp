#include <bits/stdc++.h>
using namespace std;

bool ispal(int i, int j, string& s) {
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            return false; 
        }
    }
    return true;
}

void findl(int i, int j, string& midd, string& s) {
    if (i > j) return;
    if (i == j) {
        midd.push_back(s[i]);
        return;
    }
    int m = 0;
    int ii;
    int jj;
    for (int z=i; z<=j; z++) {
        if (ispal(i, z, s)) {
            if (z - i + 1 > m) {
                m = z-i+1;
                ii=i;
                jj=z;
            }
        }
    }
    for (int z=j; z>=i; z--) {
        if (ispal(z, j, s)) {
            if (j - z + 1 > m) {
                m = j-z+1;
                ii=z;
                jj=j;
            }
        }
    }
    midd = s.substr(ii, jj-ii+1);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int lasti = -1;
        int lastj = n;
        for (int i=0; i<n/2; i++) {
            if (s[i] != s[n - 1 - i]) {
                break;
            } else {
                lasti = i;
                lastj = n - 1 - i;
            }
        }

        string midd;
        findl(lasti+1, lastj-1, midd, s);
        string res;
        for (int i=0; i<=lasti; i++) {
            res.push_back(s[i]);
        } 
        for (int i=0; i<midd.size(); i++) {
            res.push_back(midd[i]);
        } 
        for (int i=lastj; i<s.size(); i++) {
            res.push_back(s[i]);
        }
        cout << res << endl;
    }
}
