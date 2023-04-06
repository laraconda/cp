#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        vector<int> guide(s.size());

        int res = 0;
        vector<int> rem;

        // twone
        for (int i=0; i<(int)s.size()-4; i++) {
            string samp = "twone";
            bool subs = true;
            for (int j=i; j<i+5; j++) {
                if (samp[j-i] != s[j]) {
                    subs = false;
                }
            } 

            if (subs) {
                res++;
                rem.push_back(i+2);
                guide[i] += -1;
                if (i+5 < s.size())
                    guide[i+5] += 1;
            }
        }

        // one
        int count = 0;
        for (int i=0; i<(int)s.size()-2; i++) {
            string samp = "one";
            count += guide[i];
            bool subs = true;
            for (int j=i; j<i+3; j++) {
                if (samp[j-i] != s[j]) {
                    subs = false;
                }
            }
            if (count < 0) subs = false;
            if (subs) {
                rem.push_back(i+1);
                res++;
            }
        }

        // two
        count = 0;
        for (int i=0; i<(int)s.size()-2; i++) {
            string samp = "two";
            count += guide[i];
            bool subs = true;
            for (int j=i; j<i+3; j++) {
                if (samp[j-i] != s[j]) {
                    subs = false;
                }
            }
            if (count < 0) subs = false;
            if (subs) {
                rem.push_back(i+1);
                res++;
            }
        }

        cout << res << endl;
        for (int i=0; i<(int)rem.size()-1; i++) {
            cout << rem[i] + 1 << " ";
        }
        if (rem.size() > 0)
            cout << rem.back() + 1;
        cout << endl;
    }
}
