#include <bits/stdc++.h>
using namespace std;

bool years[10001];

void preprocess() {
    for (int i=0; i < 10002; i++) {
        years[i] = false;
    }
    
    years[2018] = true;
    int year = 2018;
    int month = 3;
    while (year <= 10001) {
        year = year + (month + 26)/12;
        month = (month + 26) % 12;
        years[year] = true;
    }

}

int main() {
    preprocess();
    int n;
    cin >> n;
    string res;
    if (years[n])
        res = "yes";
    else
        res = "no";
    cout << res << endl;
}
