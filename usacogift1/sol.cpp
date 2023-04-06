/*
ID: larachi1
TASK: gift1
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<string> nlist;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    fin >> n;

    for (int i=0; i<n; i++) {
        string name;
        fin >> name;
        nlist.push_back(name);
        m[name] = 0;
    }

    for (int i=0; i<n; i++) {
        string name;
        fin >> name;
        int money, friends;
        fin >> money >> friends;

        int eachm = 0;
        if (friends != 0)
            eachm = money/friends;
        for (int j=0; j<friends; j++) {
            string mfriend;
            fin >> mfriend;
            m[mfriend] += eachm;
            m[name] -= eachm;
        }
         
    }

    for (string name: nlist) {
       fout << name << " " << m[name] << endl;
    }
}
