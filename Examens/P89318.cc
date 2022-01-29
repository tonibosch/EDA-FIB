#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtraking(string& sol,vector<char>& vis, int i, int n){
    if(i == n) {
        for(int j = 0; j < n; ++j) cout <<sol[j];
        cout << endl;
    }
    else {
        for(int j = 0; j < n; ++j) {
            if(not vis[j]) {
                if(i == 0) {
                    sol[i] = ('a'+ j);
                    vis[j] = true;
                    backtraking(sol,vis,i+1,n);
                    vis[j] = false;
                }
                else if(sol[i-1] != ('a'+j-1)){
                    sol[i] = ('a'+ j);
                    vis[j] = true;
                    backtraking(sol,vis,i+1,n);
                    vis[j] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
/*
    string lletres = string(n,' ');
    for(int i = 0;i < n; ++i){
        lletres[i] = ('a'+i);
    }
*/
    string sol = string(n,' ');
    vector<char> vis(n,false);
    backtraking(sol,vis,0,n);
}