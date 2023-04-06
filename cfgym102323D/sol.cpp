#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int j=1; j<= n; j++) {
        int as;
        cin >> as;
        vector<int> autos;
        for (int i=0; i<as; i++) {
            int ai;
            cin >> ai;
            autos.push_back(ai);
        }
        string ppl;
        cin.ignore();
        getline(cin, ppl);
        vector<int> pps;
        string acc = "";
        for (int i=0; i<ppl.size(); i++) {
            if (ppl[i] == ' ') {
                pps.push_back(stoi(acc));
                acc = "";
            } else {
                acc.push_back(ppl[i]);
            }
        }
        pps.push_back(stoi(acc));

        sort(autos.begin(), autos.end());
        sort(pps.begin(), pps.end(), greater<int>());

        int i = -1;
        int maxtime = 0;
        for (int z=0; z<pps.size(); z++) {
            if (z % 4 == 0) i++;
            int time = pps[z] + autos[i];
            maxtime = max(maxtime, time);
        }
        cout << "Trip #" << j << ": " << maxtime << endl; 

    }
}
