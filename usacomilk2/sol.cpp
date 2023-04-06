/*
ID: larachi1
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    
    int n;
    fin >> n;

    vector<pair<int, int>> ms;
    for (int i=0; i<n; i++) {
        int a, b;
        fin >> a >> b;
        ms.push_back({a, b});
    }

    sort(ms.begin(), ms.end());

    int lonmilk = 0;
    for (int i=0; i<n; i++) {
        auto m = ms[i];
        int end = m.second;
        int beg = m.first;
        for (int j=i-1; j>=0; j--) {
            if (ms[j].second >= m.first) {
                if (ms[j].first < m.first) {
                    m = ms[j];
                    beg = m.first;
                }
            }
        
        }
        lonmilk = max(lonmilk, end - beg);
    }

    int lonvoid = 0;
    for (int i=1; i<n; i++) {
        auto m = ms[i];
        int end = m.first;
        int beg = 0;
        for (int j=i-1; j>=0; j--) {
            beg = max(beg, ms[j].second);
            if (beg > m.first) {
                break;
            }
        }

        lonvoid = max(end - beg, lonvoid);
    }

    fout << lonmilk << " " << lonvoid << endl;
}
