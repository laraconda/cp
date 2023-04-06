#include <bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   string s;
   cin >> s;

   
   long long c = 0;
   string ns;
   int n;
   for (int i=0; i<s.size() - 1; i++) {
    ns = string() + s[i];
    n = stoi(ns);
    if (n%4 == 0)
        c++;

    ns = s.substr(i, 2);
    if (stoi(ns) % 4 == 0)
        c += i + 1;
   }
   n = stoi(string() + s[s.size()-1]);
   if (n%4 == 0) {
    c++;
   }

   cout << c << endl;

}
