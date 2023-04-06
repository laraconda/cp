#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> records;

void frec(int g, int p) {
    int con = p % 3;
    for (int i=(p - con) / 3; i>=0; i--) {
        if (p + i - 3*i <= g) {
            int draw = p - 3*i;
            int ls = g - draw - i;

            records.push_back({{i, draw}, ls});
        } else {
            break;
        }
    }
} 

int main (){
    int n;
    cin >> n;


    for (int i=1; i<=n; i++) {
        records.clear();

        int g, p;
        cin >> g >> p;

        frec(g, p);

        cout << "Team #" << i << endl;
        cout << "Games: " << g << endl;
        cout << "Points: " << p << endl;
        cout << "Possible records: " << endl;
        for (int j=0; j < records.size(); j++) {
            cout << records[j].first.first << "-" << records[j].first.second <<
                "-" << records[j].second << endl;
        }
    }
}
