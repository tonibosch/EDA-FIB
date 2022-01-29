#include <iostream>
#include <vector>
using namespace std;

void escribir_solucion(vector<int>& sol){
    int n = sol.size();
    cout << sol[0];
    for(int i = 1; i < n; ++i) cout << ' ' << sol[i];
    cout << endl;
}

void zerosuns(int i, vector<int>& sol){
    if (i == sol.size()) escribir_solucion(sol);
    else {
        sol[i] = 0;
        zerosuns(i+1,sol);

        sol[i] = 1;
        zerosuns(i+1,sol);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> sol(n);
    zerosuns(0,sol);
}

/*
Segona solució

#include <iostream>
#include <vector>
using namespace std;

void escriure_solucio(const vector<int>& v,int n){
    cout << v[0];
    for(int i = 1; i < n; ++i) cout << " " << v[i];
    cout << endl;
}

void backtraking(vector<int>& v, int i, int n){
    if(i == n) escriure_solucio(v,n);
    else {
        v[i] = 0;       //Marcam
        backtraking(v,i+1,n);

        v[i] = 1;
        backtraking(v,i+1,n);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int i = 0;
    backtraking(v,i,n);
}
*/