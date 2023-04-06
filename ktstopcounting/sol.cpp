#include <bits/stdc++.h>
using namespace std;

struct ST {
    pair<pair<long long, int>, double> data;
    int l, h;
    ST* left;
    ST* right;

    ST(int l, int h, vector<pair<pair<long long, int>, double>>& arr): l(l), h(h) {
        if (l != h) {
            int m = l + (h - l) / 2;
            left = new ST(l, m, arr);
            right = new ST(m + 1, h, arr);
            double av = max(left->data.second, right->data.second);
            if (av == left->data.second) {
                data = {{left->data.first.first, left->data.first.second}, av}; 
            } else {
                data = {{right->data.first.first, right->data.first.second}, av}; 
            }
        } else {
            data = arr[l]; 
        }
    }

    pair<pair<long long, int>, double> query(int lq, int hq) {
        if (lq <= l && h <= hq) return data;
        if (hq < l || lq > h) return {{0, 0}, -1};
        auto leftq = left->query(lq, hq);
        auto rightq = right->query(lq, hq);
        double lav = leftq.second;
        double rav = rightq.second;
        if (lav > rav) {
            return leftq;
        } else {
            return rightq; 
        }
    }
};

typedef struct ST ST;

int main() {
    int N;
    cin >> N;
    vector<long long> cards(N);
    for (int i=0; i<N; i++) {
        int ci;
        cin >> ci;
        cards[i] = ci; 
    }

    vector<double> stop(N);
    vector<pair<pair<long long, int>, double>> start(N + 1);
    start[N] = {{0, 0}, 0};

    long long sofar = 0;
    int j=0;
    for (int i=N-1; i>=0; i--) {
        sofar += cards[i];
        start[i] = {{sofar, ++j}, (double)sofar/j}; 
    }

    ST* st = new ST(0, N, start);

    sofar = 0;
    pair<pair<long long, int>, double> right = st->query(0, N);
    double res = right.second;
    for (int i=0; i<N; i++) {
        sofar += cards[i];
        right = st->query(i+1, N);
        long long totals = sofar + right.first.first;
        int totale = i + 1 + right.first.second;
        stop[i] = max((double)totals / totale, (double)sofar / (i + 1)); 
    }

    for (int i=0; i<N; i++) {
        res = max(stop[i], res);
    }

    printf("%.11f\n", res);
}
