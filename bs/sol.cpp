#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string S) {
  cerr << "Tip: Use cerr to write debug messages on the output tab.";
  int ans = 1;
  for (int i=0; i<S.size(); i++) {
    for (int j=i+1; j<=S.size(); j++) {
      map<char, int> m;
      for (int z=i; z<j; z++) {
        m[S[z]]++;
      }
      int val = -1;
      bool p = true;
      for (auto x : m) {
        if (val == -1) val = x.second;
        if (val != x.second) p = false;
      }
      if (p) ans = max(ans, j - i);
    }
  }
  return ans;
}
