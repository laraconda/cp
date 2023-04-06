#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string sounds;
        getline(cin, sounds);
        map<string,bool> mm;
        while (true) {
            string si;
            getline(cin, si);
            if (si == "what does the fox say?") {
                break;
            } else {
                string so;
                int spa = 0;
                for (int i=0; i<si.size(); i++) {
                    if (spa == 2) so.push_back(si[i]);
                    if (si[i] == ' ') spa++;
                }
                mm[so] = true;

            }
        }
        string ans;
        string cu;
        for (int i=0; i<sounds.size(); i++) {
            if (sounds[i] == ' ') {
                if (!mm[cu]) {
                    ans.append(cu); 
                    ans.push_back(' ');
                }
                cu = "";
            } else {
                cu.push_back(sounds[i]);
            }
        }
        if (!mm[cu]) {
            ans.append(cu); 
        }
        cout << ans << endl;
    }
}
