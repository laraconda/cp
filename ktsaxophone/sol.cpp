#include <bits/stdc++.h>
using namespace std;


map<char, vector<int>> notes = {
    {'c', {2,3,4,7,8,9,10}},    
    {'d', {2,3,4,7,8,9}},
    {'e', {2,3,4,7,8}},
    {'f', {2,3,4,7}},
    {'g', {2,3,4}},
    {'a', {2,3}},
    {'b', {2}},
    {'C', {3}},
    {'D', {1,2,3,4,7,8,9}},
    {'E', {1,2,3,4,7,8}},
    {'F', {1,2,3,4,7}},
    {'G', {1,2,3,4}},
    {'A', {1,2,3}},
    {'B', {1,2}},

};

bool inlist(int fing, char c) {
    for (int x : notes[c]) {
        if (x == fing) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    cin.ignore();
    while (t--) {
        vector<int> fin(11);
        vector<bool> press(11);

        for (int i=0; i<11; i++) {
            fin[i] = 0;
            press[i] = false;
        }
        string s;
        
        getline(cin, s);
        
        for (int i=0; i<(int)s.size(); i++) {
            for (int j=1; j<11; j++) {
                bool a = inlist(j, s[i]);
                if (!press[j] && a) {
                    press[j] = true;
                    fin[j]++;
                } else if (!a) {
                    press[j] = false;
                } 
            }
        }

        for (int i=1; i<10; i++) {
            cout << fin[i] << " ";
        }
        cout << fin[10] << endl;
    }

}
