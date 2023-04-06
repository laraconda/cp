#include <bits/stdc++.h>
using namespace std;

vector<long long> all;
vector<long long> peaks;

vector<long long> ones;
vector<long long> twos;
vector<long long> tro;
vector<long long> onesp;
vector<long long> twosp;
vector<long long> trop;

long long fpeaks(int n);

void setup() {
    all.push_back(1);
    peaks.push_back(0);

    ones.push_back(0);
    onesp.push_back(0);
    
    twos.push_back(0);
    twosp.push_back(0);
    
    tro.push_back(0);
    trop.push_back(0);
   
    
    all.push_back(2);
    peaks.push_back(0);

    ones.push_back(2);
    onesp.push_back(0);
    
    twos.push_back(1);
    twosp.push_back(0);
    
    tro.push_back(0);
    trop.push_back(0);
   

    all.push_back(11);
    peaks.push_back(4);

    ones.push_back(16);
    onesp.push_back(2);

    twos.push_back(8);
    twosp.push_back(2);

    tro.push_back(4);
    trop.push_back(2);
}

long long fall(int n) {
    if ((int)all.size() > n) {
        return all[n];    
    }
    long long res = fall(n-1) * 2 + fall(n-2) * 7 + fpeaks(n-1) * 2;
    all.push_back(res);
    ones.push_back(ones[n-1] * 2 + fall(n-1) * 2 + ones[n-2] * 7 + fall(n-2) * 8 + onesp[n-1] * 2 + fpeaks(n-1));
    twos.push_back(twos[n-1] * 2 + fall(n-1)     + twos[n-2] * 7 + fall(n-2) * 4 + twosp[n-1] * 2 + fpeaks(n-1));
    tro.push_back(tro[n-1] * 2   +               + tro[n-2]  * 7 + fall(n-2) * 4 + trop[n-1]  * 2 + fpeaks(n-1));

    onesp.push_back(ones[n-2] * 4 + fall(n-2) * 2 + onesp[n-1]);
    twosp.push_back(twos[n-2] * 4 + fall(n-2) * 2 + twosp[n-1] + fpeaks(n-1));
    trop.push_back(tro[n-2] * 4 + fall(n-2) * 2 + trop[n-1]);
    return res;
}

long long fpeaks(int n) {
    if ((int)peaks.size() > n) {
        return peaks[n]; 
    }
    long long res = fall(n - 2) * 4 + fpeaks(n-1);
    peaks.push_back(res);
    return res;
}

int main() {
    setup();
    int n;
    cin >> n;
    if (n == 0)
        cout << 1 << " " << 0 << " " << 0 << " " << 0 << endl;
    else {
        long long res = fall(n);
        cout << res << " " << ones[n] << " " << twos[n] << " " << tro[n] << endl;
    }

}
