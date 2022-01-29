#include <iostream>
#include <string>
using namespace std;

void puj_i_baix(string& sol, int n, int i, int alt){
    if(i == n) cout << sol << endl;
    else {
        if(alt > 0) {
            sol[i] = 'd';
            puj_i_baix(sol,n,i+1,alt-1);
        }
        sol[i] = 'h';
        puj_i_baix(sol,n,i+1,alt);

        sol[i] = 'u';
        puj_i_baix(sol,n,i+1,alt+1);
    }
}

int main(){
    int n;
    cin >> n;

    string sol(n,' ');
    puj_i_baix(sol,n,0,0);
}

/*   Versio 2
#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<char>& sol, int n){
    for(int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void puj_i_baix(vector<char>& sol, int i, int n, int alt) {
    if(i == n) escriure_sol(sol,n);
    else {
        if(alt > 0) {
            sol[i] = 'd';
            puj_i_baix(sol,i+1,n,alt-1);
        }

        sol[i] = 'h';
        puj_i_baix(sol,i+1,n,alt);

        sol[i] = 'u';
        puj_i_baix(sol,i+1,n,alt+1);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> sol(n);

    puj_i_baix(sol,0,n,0);
}
*/