#include <bits/stdc++.h>

using namespace std;

void sol(int N, vector<int>& ans) {
    if (N == 2 || N == 4) ans.push_back(N);
    if (N == 6) {
        ans.push_back(2);
        ans.push_back(4);
    } else if (N == 8) {
        ans.push_back(2);
        ans.push_back(6);
    }
    else if ((N/2) % 2 == 0) {
        ans.push_back(N/2);
        sol(N/2, ans);
    } else {
        ans.push_back(N/2 - 1);
        sol(N/2 + 1, ans);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> ans;
    sol(N, ans);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    long long s = 0;
    for (int x : ans) s+=x;
    cout << "s: " << s << endl;
}

