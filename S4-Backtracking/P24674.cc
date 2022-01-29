#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<string>& sol, int n){
    cout << "(" << sol[0];
    for(int i = 1; i < n; ++i){
        cout << "," << sol[i];
    }
    cout << ")" << endl;
}

void permutacions(const vector<string>& pal, int i, int n, vector<bool> & vis, vector<string>& sol){
    if(i == n) escriure_sol(sol,n);
    else {
        for(int j = 0; j < n; ++j){
            if(not vis[j]){
                vis[j] = true;
                sol[i] = pal[j];
                permutacions(pal,i+1,n,vis,sol);
                vis[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> paraules(n);
    for(int i = 0; i < n; ++i) cin >> paraules[i];
    vector<string> sol(n);
    vector<bool> vis(n,false);

    permutacions(paraules,0,n,vis,sol);
}

/* 2na SOLUCIO
#include <iostream>
#include <vector>
using namespace std;

void escribir_solucion(vector<int>& sol,vector<string>& pal, int n){
    cout << '(' << pal[sol[0]];
    for(int i = 1; i < n; ++i) cout << ',' << pal[sol[i]];
    cout << ')' << endl;
}

void permutacion(int n,vector<string>& palabras,vector<int>& sol,vector<bool>& vis){
   if(n == sol.size()) escribir_solucion(sol,palabras,n);
   else {
       for(int j = 0; j < n; ++j){
           if(not vis[j]){
               sol.push_back(j);
               vis[j] = true;
               permutacion(n,palabras,sol,vis);
               vis[j] = false;
               sol.pop_back();
           }
       }
   }
}

int main() {
    int n,u;
    cin >> n;

    vector<string> palabras(n);
    for(int i = 0; i < n; ++i)

    vector<int> sol;                 //Para no repetir   
    vector<bool> vis(n,false);

    permutacion(n,palabras,sol,vis);

}
*/