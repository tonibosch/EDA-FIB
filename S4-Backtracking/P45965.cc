#include <iostream>
#include <vector>
using namespace std;

void escriure_solucio(const vector<int>& v,int n){
    cout << v[0];
    for(int i = 1; i < n; ++i) cout << " " << v[i];
    cout << endl;
}

void backtraking(vector<int>& v, int n, int u,int i, int n_uns, int n_zeros){
    if(n_uns == u and n_zeros == (n - u)) escriure_solucio(v,n);
    else {
        if(n_zeros < n - u) {
            v[i] = 0;
            backtraking(v,n,u,i+1,n_uns,n_zeros+1);
        }

        if(n_uns < u) {
            v[i] = 1;
            backtraking(v,n,u,i+1,n_uns+1,n_zeros);
        }
    }
}

int main(){
    int n,u;
    cin >> n >> u;
    vector<int> v(n);

    backtraking(v,n,u,0,0,0);
}

/*
void escribir_solucion(vector<int>& sol){
    int n = sol.size();
    cout << sol[0];
    for(int i = 1; i < n; ++i) cout << ' ' << sol[i];
    cout << endl;
}

2na SOLUCIÓ
void zerosuns2(int i, vector<int>& sol, int n, int u, int num_uns){
    if (i == sol.size()) escribir_solucion(sol);
    else {
        if ((i - num_uns) < n - u){
            sol[i] = 0;
            zerosuns2(i+1,sol,n,u,num_uns);
        } 
        if (num_uns < u){
            sol[i] = 1;
            zerosuns2(i+1,sol,n,u,num_uns+1);
        }
    }
}

3ra SOLUCIÓ
void zerosuns2(int i, vector<int>& sol, int n, int u, int num_uns){
    if(num_uns > u) return;                          //Tener mas unos de lo que permiten
    if((i - num_uns) > n - u)
    if (i == sol.size()) escribir_solucion(sol);
    else {
        sol[i] = 0;
        zerosuns2(i+1,sol,n,u,num_uns);

        sol[i] = 1;
        zerosuns2(i+1,sol,n,u,num_uns+1);
    }
}

int main() {
    int n,u;
    cin >> n >> u;

    vector<int> sol(n);

    zerosuns2(0,sol,n,u,0);
}

*/

