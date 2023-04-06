#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;

        string s3 = "";
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] == s2[i])
                s3.push_back('.');
            else
                s3.push_back('*');
        }

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
    }
}
