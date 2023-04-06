#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string last = "";
    int inc = 0;
    int dec = 0;
    while (n--) {
        string name;
        cin >> name;
        if (last != "") {
            if (name > last) {
                inc++; 
            } else {
                dec++;
            }
        }
        last = name;
    }

    if (dec == 0) {
        cout << "INCREASING" << endl;
    } else if (inc == 0) {
        cout << "DECREASING" << endl;
    } else {
        cout << "NEITHER" << endl;
    }
}
