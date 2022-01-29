#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<char>& sol, int n){
    for(int i = 0; i < 2*n; ++i) cout << sol[i];
    cout << endl;
}

void cons_i_voc(vector<char>& sol, const vector<char>& cons, vector<bool>& vis_cons, vector<char>& voc, vector<bool>& vis_voc, int i, int n){
    if(i == 2*n) escriure_sol(sol,n);
    else {
        for(int  j= 0; j < n; ++j){
            if(i%2 == 0 and not vis_cons[j]){           //Es posarà una consonant quan estiguem en un nivell par i no s'ha d'haver visitat la consonant abans
                vis_cons[j] = true;
                sol[i] = cons[j];  
                cons_i_voc(sol,cons,vis_cons,voc,vis_voc,i+1,n);
                vis_cons[j] = false;
            } 
            else if(i%2 == 1 and not vis_voc[j]) {      //Es posarà una vocal quan estiguem en un nivell senar i no s'ha d'haver visitat la vocal abans
                vis_voc[j] = true;
                sol[i] = voc[j];
                cons_i_voc(sol,cons,vis_cons,voc,vis_voc,i+1,n);
                vis_voc[j] = false;

            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<char> cons(n);
    vector<bool> vis_cons(n,false);
    for(int i = 0; i < n; ++i) cin >> cons[i];

    vector<char> voc(n);
    vector<bool> vis_voc(n,false);
    for(int i = 0; i < n; ++i) cin >> voc[i];
    vector<char> sol(2*n);

    cons_i_voc(sol,cons,vis_cons,voc,vis_voc,0,n);
}