#include <bits/stdc++.h>

using namespace std;

vector<long long> totalarr;
vector<long long> scorearr;

long long total(int i) {
    return totalarr[totalarr.size() - 1] - totalarr[i-1];
}

long long score(int i, vector<long long> &arr) {
    if (i >= arr.size())
        return 0;
    if (scorearr[i] == -1) {
        long long a = arr[i] + total(i+1) - score(i+1, arr);
        long long b = 0;
        long long c = 0;

        if (i < arr.size() - 1)
            b = arr[i] + arr[i+1] + total(i+2) - score(i+2, arr);
        if (i < arr.size() - 2)
            c = arr[i] + arr[i+1] + arr[i+2] + total(i+3) - score(i+3, arr);
        
        scorearr[i] = max(max(a, b), c);
    }
    return scorearr[i];
}

/*
 * Complete the bricksGame function below.
 */
long long bricksGame(vector<long long> &arr) {
    totalarr.push_back(arr[0]);
    scorearr.push_back(-1);
    for (int i=1; i<arr.size(); i++) {
        scorearr.push_back(-1);
        totalarr.push_back(arr[i] + totalarr[i-1]);
    }
    long long res = score(0, arr);
    totalarr.clear();
    scorearr.clear();
    return res;
}

int main() {
    int n;
    int m;
    cin >> n;
    vector<long long> arr;

    while(n--) {
        cin >> m;
        while (m--) {
            long long ai;
            cin >> ai;
            arr.push_back(ai);
        }
        long long res = bricksGame(arr);
        cout << res << endl;

        arr.clear();
    }
}

