#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<int>& sol, const vector<bool>& vis, int n) {
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(vis[i]){
            if(primer) {
                primer = false;
                cout << "(" << sol[i];
            }
            else cout << "," << sol[i];
        }
    }
    cout << ")" << endl;
}

void seq_equilibrades(vector<int>& sol, vector<bool>& vis, int i, int n, int d){
    if(i == n) escriure_sol(sol,vis,n);
    else {
        for(int j = 0; j < n; ++j) {
           if(not vis[j]){
               if(i == 0 or (abs(j+1-sol[i-1])<= d)){
                   sol[i] = j+1;
                   vis[j] = true;
                   seq_equilibrades(sol,vis,i+1,n,d);
                   vis[j] = false;
               }
           }
        }
    }
}

int main() {
    int n,d;
    cin >> n >> d;

    vector<int> sol(n);
    vector<bool> vis(n,false);

    seq_equilibrades(sol,vis,0,n,d);
}