/*
ID: larachi1
TASK: ride
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 47;

map<char, int> m = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10}, {'K', 11}, {'L', 12}, {'M', 13}, {'N', 14}, {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19}, {'T', 20}, {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24}, {'Y', 25}, {'Z', 26}};

int val(string s) {
    int v = 1;
    for (char x : s)
        v *= m[x] % MOD;
    return v % MOD;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    if (val(a) == val(b)) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

}
