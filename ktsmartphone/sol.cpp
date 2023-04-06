#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string goal;
        string sofar;
        string s1, s2, s3;
        cin >> goal >> sofar >> s1 >> s2 >> s3;
        vector<string> pos = {sofar, s1, s2, s3};
        int minc = 1e9;
        bool suggestion = false;
        for (string po : pos) {
            int co = 0;
            int pref = 0;
            for (int i=0; i<(int)min(goal.size(), po.size()); i++) {
                if (goal[i] == po[i])
                    pref++;
                else
                    break;
            }
            co += (int)po.size() - pref;
            co += (int)goal.size() - pref;

            if (suggestion)
                co++;

            minc = min(minc, co);
            suggestion = true;
        }
        cout << minc << endl;
    }
}
