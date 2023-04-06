#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1002;
int a[MAXN];
vector<tuple<int, int, int> > rules;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair <int, int> > ones;

    for (int i=n; i>0; i--)
        a[n - i + 1] = i;

    int ti, li, ri;
    for (int i=0; i<m; i++) {
        cin >> ti >> li >> ri;
        if (ti == 0)
            rules.push_back(make_tuple(0, li, ri));
        else {
            ones.push_back(make_pair(li, 0)); 
            ones.push_back(make_pair(ri, 1));
        }
    }

    sort(ones.begin(), ones.end());

    stack<int> q;
    for (int i=0; i<ones.size(); i++) {
        if (ones[i].second == 0)
            q.push(ones[i].first);
        else {
            int l = q.top();
            q.pop();
            if (q.empty()) {
                rules.push_back(make_tuple(1, l, ones[i].first));
            }
        }
    }
 
    m = rules.size();
    bool pos = true;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (get<0>(rules[i]) == 1 && get<0>(rules[j]) == 0) {
                if (get<1>(rules[i]) <= get<1>(rules[j]) &&
                    get<2>(rules[j]) <= get<2>(rules[i])) {
                    pos = false;
                }
            }
        }
    }

    if (pos) {
        cout << "YES" << endl;
        for (int i=0; i<m; i++) {
            if (get<0>(rules[i]) == 1) {
                if (a[get<1>(rules[i])] != n+1)
                    a[get<1>(rules[i])] = 1;
                for (int j=get<1>(rules[i]) + 1; j<=get<2>(rules[i]); j++)
                    a[j] = n+1;
            }
        }

        for (int i=1; i<=n-1; i++) {
            cout << a[i] << " ";
        }
        cout << a[n] << endl;
    
    } else {
        cout << "NO" << endl;
    }
}
