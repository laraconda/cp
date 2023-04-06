#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        string name;
        cin.ignore();
        getline(cin, name);

        bool pea = false;
        bool pan = false;
        while (k--) {
            string item;
            getline(cin, item);

            if (item == "pea soup") {
                pea = true; 
            } else if (item == "pancakes") {
                pan = true;
            }

            if (pan && pea) {
                cout << name << endl;
                return 0;
            }
        }
    }
    cout << "Anywhere is fine I guess" << endl;
}
