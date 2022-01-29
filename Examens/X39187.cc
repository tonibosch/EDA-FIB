#include <iostream>
#include <string>
using namespace std;

void escriure_sol(string& sol, int n) {
    for(int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void comprant_accions(string& sol, int i, int n, int c, int naccions) {
    if(i == n) escriure_sol(sol,n);
    else {
        if(c > 0) {
            sol[i] = 'b';
            comprant_accions(sol,i+1,n,c-1,naccions+1);
        }
        if(naccions > 0){
            sol[i] = 's';
            comprant_accions(sol,i+1,n,c+1,naccions-1);
        }
    }
}

int main() {
    int n,c;
    cin >> n >> c;


    string sol = string(n,' ');

    comprant_accions(sol,0,n,c,0);
}