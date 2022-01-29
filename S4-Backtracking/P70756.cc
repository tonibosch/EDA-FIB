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
            v[i] = j+1;                   //Dius a quin grup a d'anar
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

/*
void escriure_solucio(const vector<string>& pal, const vector<int>& sol, int n,int p){
    for(int i = 0; i < p; ++i){
        cout << "subconjunt " << i+1 << ":{ ";
        bool primer = true;
        for(int j = 0; j < n;++j){
            if(sol[j] == i){
                if(primer) primer = false;
                else cout << ","; 
                cout << pal[j];
            }
        }
        cout << "}" << endl; 
    }
    cout << endl;
}

void particions(const vector<string>& pal, int n, int p, int i, vector<int>& sol){
    if(i == n) (pal,sol,n,p);
    else {
        for(int j = 0; j < p; ++j){     //El pots posar a p subgrups. 
            sol[i] = j;     //A la palabra i le asigno el subconjunto j+1 porque empieza por el subjc 1
            //sol.push_back(j)
            particions(pal,n,p,i+1,sol);
            //sol.pop_back();
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

    vector<int> sol(n);
    //vector<int> sol(n);
    particions(pal,n,p,0,sol);
}
*/