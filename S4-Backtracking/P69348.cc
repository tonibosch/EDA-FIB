#include <iostream>
#include <vector>
using namespace std;

void escribir_solucion(vector<int>& sol){
    int n = sol.size();
    cout << '(' << sol[0];
    for(int i = 1; i < n; ++i) cout << ',' << sol[i];
    cout << ')' << endl;
}

void un_a_ena(int i,vector<int>& sol,vector<bool>& vis){
   if(i == sol.size()) escribir_solucion(sol);
   else {
       int n = sol.size();
       for(int j = 0; j < n; ++j){
           if(not vis[j]){
               sol[i] = j + 1;
               vis[j] = true;
               un_a_ena(i+1,sol,vis);
               vis[j] = false;
           }
       }
   }
}

int main() {
    int n,u;
    cin >> n;

    vector<int> sol(n);
    vector<bool> vis(n,false);

    un_a_ena(0,sol,vis);

}