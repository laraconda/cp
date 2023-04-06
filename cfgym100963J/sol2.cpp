#include <bits/stdc++.h>
     
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
    #define f first
    #define s second
    #define mp make_pair
     
    void solve(ll a, ll m, ll &x, ll &y){
        bool flag = false;
        if (a > m){
            swap(a, m);
            flag = true;
        }
        if (a == 0){
            x = 0; y = 1;
            if (flag)
                swap(x, y);
            return;
        }
        ll x1, y1;
        solve(m % a, a, x1, y1);
     
        x = y1 - (m / a) * x1;
        y = x1;
     
        if (flag)
            swap(x, y);
    }
     
    int main(){
        ios::sync_with_stdio(0);cin.tie(0);
        ll n, m, a, k;
        cin >> n >> m >> a >> k;
        while(n!=0 or m!=0 or a!=0 or k!=0){
     
            ll dif = n-m-k;
            ll gcd = __gcd(a, m);
            cout << "g: " << gcd << endl;
            if (gcd == 0LL){
                if (k == n)
                    cout << k << "\n";
                else
                    cout << "Impossible\n";
                cin >> n >> m >> a >> k;
                continue;
            }
            if (dif%gcd != 0){
                cout << "Impossible\n";
                cin >> n >> m >> a >> k;
                continue;
            }
            if (a == 0LL){
                ll j = dif / (-m);
                if (j * (-m) != dif){
                    cout << "Impossible\n";
                }
                else{
                    cout << (n-m) + m * j << "\n";
                }
                cin >> n >> m >> a >> k;
                continue;
            }
            if (m == 0LL){
                ll t = dif / a;
                if (t * a != dif){
                    cout << "Impossible\n";
                }
                else
                    cout << k + a * t << "\n";
                cin >> n >> m >> a >> k;
                continue;
            }
            dif = dif / gcd;
            a = a / gcd;
            m = m / gcd;
            ll x, y;
     
            solve(a, m, x, y);
            cout << "x: " << x << " y: " << y << endl;
            assert(a*x + m*y == 1);
     
            y *= -1;
            x *= dif;
            y *= dif;
            cout << "dif: " << dif << endl;
     
            // ll x1 = m;
            // ll y1 = a;
     
     
            ll K = -x / m;
            while (x + K*m <= 0){
                K ++;
            }
            ll newX = x + K * m;
            ll newY = y + K * a;
     
            if (newY<=0){
                ll Kp = y / a;
                while (y + Kp * a <= 0){
                    Kp ++;
                }
                K = Kp;
            }
            cout << "K: " << K << endl;
            newX = x + K * m;
            newY = y + K * a;
     
            cout << k + gcd*a*(x + K * m) << "\n";
            cin >> n >> m >> a >> k;
        }
        return 0;
    }
