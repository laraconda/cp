#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> del;
    int i=0;
    int j=n-1;
    while (i < j) {
        if (s[i] == '(') {
            if (s[j] == ')') {
                del.push_back(++i);
                del.push_back(j + 1);
                j--;
            } else j--;
        } else i++;
    }
    if (del.size())
        cout << 1 << endl;
    cout << del.size() << endl;
    sort(del.begin(), del.end());
    for (int i=0; i<(int)del.size() - 1; i++) {
        cout << del[i] << " ";
    }
    if (!del.empty()) cout << del.back() << endl;
}
