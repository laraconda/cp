/*
ID: larachi1
TASK: namenum
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

vector<char> ops[20];
unordered_map<string, bool> names;
vector<string> vn;

void mfill() {
    string all = "ABCDEFGHIJKLMNOPRSTUVWXY";
    int j = 1;
    for (int i=0; i<(int)all.size(); i++) {
        if (i % 3 == 0)
            j++;
        ops[j].push_back(all[i]);
    }

    ifstream namesin("dict.txt");
    string s;
    while (namesin >> s) {
        names[s] = true;
    }
    namesin.close();
}

void backtrack(string& name, string& s, int i) {
    if (name.size() == s.size() || (s.size() == 13 && (int)name.size() > 3)) {
        if (names.count(name)) {
            vn.push_back(name);
        }
    } else {
        char& num = s[i];
        int n = num - '0';
        for (int j=0; j<3; j++) {
            name.push_back(ops[n][j]);
            backtrack(name, s, i + 1);
            name.pop_back();
        } 
    }
    return;
}

/*
void dfs(string& s) {
    string name = "";
    vector<int> vis(20);
    stack<pair<char&, int>> st;
    char& num = s[0];
    int n = num - '0';
    for (int j=0; j<3; j++) {
        st.push({ops[n][j], 0});
    }
    while(!st.empty()) {
        auto& v = st.top();
        int i = v.second;
        if (vis[i]) {
            vis[i] = 0;
            name.pop_back();
            st.pop();
            continue;
        }
        name.push_back(v.first);
        vis[i] = 1;
        
        if (i + 1 < (int)s.size()) {
            num = s[i + 1];
            n = num - '0';
            for (int j=0; j<3; j++) {
                st.push({ops[n][j], i + 1});
            }
        }

        if (i + 1 == (int)s.size()) {
            if (names[name])
                vn.push_back(name);
        }
    }
}
*/

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    
    mfill();

    string s;
    fin >> s;
    

    if (s.back() == ' ')
        s.pop_back();
    
    string name;
    backtrack(name, s, 0);
    // dfs(s);

    sort(vn.begin(), vn.end());

    if ((int)vn.size() == 0) {
        fout << "NONE" << endl; 
    } else {
        for (string& name : vn) {
            fout << name << endl;
        }
    }
}
