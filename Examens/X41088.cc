#include <iostream>
#include <vector>
using namespace std;

void escribir_sol(const vector<int>& v, int n) {
    cout << '(';
    for(int i = 0; i < n; ++i) {
        if(i != 0) cout << ',';
        cout << v[i];
    }
    cout << ')' << endl;
}

bool pou(int esq, int med, int der) {
    return (esq+der > 2*med);
}

void seq_sense_pous(vector<int>& sol, int n, int i, vector<bool>& vis) {
    if(i == n) escribir_sol(sol,n);
    else {
        for(int j = 0; j < n; ++j) {
            if(not vis[j]) {
                if(i >= 2 and not pou(sol[i-2],sol[i-1],j+1)) {
                    vis[j] = true;
                    sol[i] = j+1;
                    seq_sense_pous(sol,n,i+1,vis);
                    vis[j] = false;
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> sol(n);
    vector<bool> vis(n);
    seq_sense_pous(sol,n,0,vis);
}

/*      VERSIO 2
#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<int>& sol, const vector<bool>& vis, int n) {
    bool primer = true;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) {
            if(primer) {
                primer = false;
                cout << "(" << sol[i];
            }
            else cout << "," << sol[i];
        }
    }
    cout << ")" << endl;
}

void backtracking(vector<int>& sol, vector<bool>& vis, int i, int n){
    if(i == n) escriure_sol(sol,vis,n);
    else {
        for(int j = 0; j < n; ++j) {
            if(not vis[j]) {
                if(i < 2) {
                    vis[j] = true;
                    sol[i] = j+1;
                    backtracking(sol,vis,i+1,n);
                    vis[j] = false;
                }
                else if((sol[i-2]+j+1) <= 2*sol[i-1]) {
                    vis[j] = true;
                    sol[i] = j+1;
                    backtracking(sol,vis,i+1,n);
                    vis[j] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> sol(n);
    vector<bool> vis(n,false);

    backtracking(sol,vis,0,n);
}

*/