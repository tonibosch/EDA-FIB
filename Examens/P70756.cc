#include <iostream>
#include <vector>
using namespace std;

void escriure_solcucio(const vector<string>& pal,const vector<int>& v, int n, int p) {
    
    for(int i = 0; i < p; ++i){
        cout << "subconjunt " << i+1 <<": {";
        bool primer = true;
        for(int j = 0; j < n; ++j){
            if(v[j] == i+1) {
                if(primer) primer = false;
                else cout << ",";
                cout << pal[j];
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void particions(const vector<string>& pal,vector<int>& v, int n, int i, int p){
    if(i == n) escriure_solcucio(pal,v,n,p);
    else {
        for(int j = 0; j < p; ++j){
            v[i] = j+1;                   //Dius a quin grup a d'anarÃ§
            particions(pal,v,n,i+1,p);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> pal(n);
    for(int i = 0; i < n; ++i) cin >> pal[i];
    int p;
    cin >> p;

    vector<int> v(n);
    particions(pal,v,n,0,p);
}