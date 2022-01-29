#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

void llegir_cues(vector<queue<string>>& v, int n){
    string s;
    getline(cin,s);         //Necessari per llegir correctament
    for(int i = 0; i < n; ++i){
        getline(cin,s);
        istringstream llegir(s);

        string par;
        while(llegir >> par) v[i].push(par);
    }
}

void escriure_cues(vector<queue<string>>& v, int n){
    for(int i = 0; i < n; ++i){
        cout << "cua " << i+1 << ':';
        while(not v[i].empty()){
            cout << " " << v[i].front();
            v[i].pop();
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<queue<string>> v(n);
    llegir_cues(v,n);

    cout << "SORTIDES" << endl << "--------" << endl;

    string op;
    while(cin >> op){
        if(op == "SURT"){
            int n_cua;
            cin >> n_cua;
            if(n_cua > 0 and n_cua <= n and not v[n_cua-1].empty()) {
                cout << v[n_cua-1].front() << endl;
                v[n_cua-1].pop();
            }
        }
        else {      //op == "ENTRA"
            string nom;
            int n_cua;
            cin >> nom >> n_cua;
            if(n_cua > 0 and n_cua <= n) v[n_cua-1].push(nom);
        }
    }

    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    escriure_cues(v,n);
}