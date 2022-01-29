#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<string>& sol, const vector<bool>& vis, int n){
    for(int i = 0; i < n; ++i) {
        if(vis[i]) cout << sol[i];
    }
    cout << endl;
}

void backtracking(const vector<string>& pal, vector<string>& sol, vector<bool>& vis, int i, int n){
    if(i == n) escriure_sol(sol,vis,n);
    else {
        for(int j = 0; j < n; ++j) {
            if(not vis[j]){
                if(i == 0 or sol[i-1].back() != pal[j][0]) {
                    vis[j] = true;
                    sol[i] = pal[j];
                    backtracking(pal,sol,vis,i+1,n);
                    vis[j] = false;
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<string> pal(n);
    for(int i = 0; i < n; ++i) cin >> pal[i];

    vector<string> sol(n);
    vector<bool> vis(n,false);

    backtracking(pal,sol,vis,0,n);
}