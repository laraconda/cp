#include <bits/stdc++.h>
using namespace std;

const int MAXT = 3000;

map<string, string> go;
map<string, string> back;

string decode(string s) {
    string ss = "";
    vector<int> lv;
    for (int i=0; i<s.size(); i++) {
        string ns = go[string(1, s[i])];
        ss += ns;
        lv.push_back(ns.size());
    }
    
    reverse(lv.begin(), lv.end());

    string dec = "";
    int i=0;
    for (int x : lv) {
        string ns = "";
        for (int j=0; j<x; j++)
            ns += string(1, ss[i+j]);
        dec += back[ns];
        i += x;
    }
    return dec;
}

int main() {
    string s;

    go["A"] = ".-";
    go["B"] = "-...";
    go["C"] = "-.-.";
    go["D"] = "-..";
    go["E"] = ".";
    go["F"] = "..-.";
    go["G"] = "--.";
    go["H"] = "....";
    go["I"] = "..";
    go["J"] = ".---";
    go["K"] = "-.-";
    go["L"] = ".-..";
    go["M"] = "--";
    go["N"] = "-.";
    go["O"] = "---";
    go["P"] = ".--.";
    go["Q"] = "--.-";
    go["R"] = ".-.";
    go["S"] = "...";
    go["T"] = "-";
    go["U"] = "..-";
    go["V"] = "...-";
    go["W"] = ".--";
    go["X"] = "-..-";
    go["Y"] = "-.--";
    go["Z"] = "--..";

    go["_"] = "..--";
    go[","] = ".-.-";
    go["."] = "---.";
    go["?"] = "----";
    
    back["..--"] = "_";
    back[".-.-"] = ",";
    back["---."] = ".";
    back["----"] = "?";
    
    back[".-"] = "A";
    back["-..."] = "B";
    back["-.-."] = "C";
    back["-.."] = "D";
    back["."] = "E";
    back["..-."] = "F";
    back["--."] = "G";
    back["...."] = "H";
    back[".."] = "I";
    back[".---"] = "J";
    back["-.-"] = "K";
    back[".-.."] = "L";
    back["--"] = "M";
    back["-."] = "N";
    back["---"] = "O";
    back[".--."] = "P";
    back["--.-"] = "Q";
    back[".-."] = "R";
    back["..."] = "S";
    back["-"] = "T";
    back["..-"] = "U";
    back["...-"] = "V";
    back[".--"] = "W";
    back["-..-"] = "X";
    back["-.--"] = "Y";
    back["--.."] = "Z";

    while (cin >> s) {
        cout << decode(s) << endl;
    }
}
