#include <bits/stdc++.h>
using namespace std;

const int msize = 10e5 + 1;
vector<int> g[msize];
int grades[msize];

bool isbus(int n) {
    return (grades[2] == n-2 && grades[1] == 2);
}

bool isring(int n) {
    return (grades[2] == n);
}

bool isstar(int n) {
    return (grades[1] == n-1 && grades[n-1] == 1);
}


int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        grades[g[i].size()]++;
    }

    if (isbus(n)) {
        cout << "bus topology" << endl;
    } else if (isring(n)) {
        cout << "ring topology" << endl;
    } else if (isstar(n)){
        cout << "star topology" << endl;
    } else {
        cout << "unknown topology" << endl;
    }
}
