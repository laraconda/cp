#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int j = 1;
    long long rea = 0;
    stack<int> st;
    for (int i=1; i<=2*n; i++) {
        string insi;
        cin >> insi;
        if (insi == "remove") {
            if (st.empty() || (!st.empty() && st.top() == j)) {
                if (!st.empty()) st.pop();
            } else {
                st = stack<int>();
                rea++;
            }
            j++;
        } else {
            int aj;
            cin >> aj;
            st.push(aj);  
        }
    }

    cout << rea << endl;
}
