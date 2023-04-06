#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    int con[102];
    int ind[102];

    for(int j=0;j<102;j++) con[j]=0;

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> ind[i];
        con[ind[i]]++;
    }
    
    int a=0,b=0;
    bool m = false;
    for(int i=0;i<102;i++){
        if(con[i]==1) 
            a++;
        if(con[i]>2){
            m=true;
            b=i;
        }
    }

    bool c = true;
    if(a%2==0){
        cout << "YES\n";
        for(int i=1; i<=n; i++){
            if(con[ind[i]]==1){
                if(c){
                    cout << "A";
                    c = false;
                }
                else{
                    cout << "B";
                    c = true;
                }
            }
            else{
                cout << "B";
            }
        }
    }
    else{
        bool k = true;
        if(m){
            cout << "YES";
            for(int i=1; i<=n; i++){
                if(con[ind[i]]==1){
                    if(c){
                        cout << "A";
                        c=false;
                    }
                    else{
                        cout << "B";
                        c=true;
                    }
                }
                else{
                    if(ind[i]==b && k){
                        cout << "A";
                        k = false;
                    }
                    else{
                        cout << "A";
                    }
                }
            }
        }
        else{
            cout << "NO";
        }
    }
}
