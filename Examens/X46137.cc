#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<char>& sol, int n){
    for(int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void paraules_compensadoes(vector<char>& sol, int i, int n, int na, int nb) {
    if(i == n) escriure_sol(sol,n);
    else {
        if(abs((na+1)-nb) <= 2) {
            sol[i] = 'a';
            paraules_compensadoes(sol,i+1,n,na+1,nb);
        }
        if(abs(na-(nb+1)) <= 2) {
            sol[i] = 'b';
            paraules_compensadoes(sol,i+1,n,na,nb+1);
        }
    }
}

int main() {
    int n; 
    cin >> n;

    vector<char> sol(n);

    paraules_compensadoes(sol,0,n,0,0);
}

/*    Versio 2
#include <iostream>
#include <string>
using namespace std;

void paraules_comp(string& sol, int n, int na, int nb){
    if(abs(na-nb) > 2) return; 
    if(sol.size() == n) cout << sol << endl;
    else {
        sol.push_back('a');
        paraules_comp(sol,n,na+1,nb);
        sol.pop_back();
    
        sol.push_back('b');
        paraules_comp(sol,n,na,nb+1);
        sol.pop_back();
        
    }
}

int main(){
    int n;
    cin >> n;

    string sol;
    paraules_comp(sol,n,0,0);
}
*/