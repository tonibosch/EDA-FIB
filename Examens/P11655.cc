#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<int>& sol) {
    int mida = sol.size();
    cout << "{" << sol[0];
    for(int i = 1; i < mida; ++i){
        cout << "," << sol[i];
    }
    cout << "}" << endl;
}

void sumes_iguals3(vector<int>& sol, int i, int n, const vector<int>& numeros, ) {
    if(i == n) {
        if(s == suma) escriure_sol(sol);
    }
    else {
        if(suma + v[i] <= s) {
            sol.push_back(v[i]);
            sumes_iguals3(s,n,v,sol,i+1,suma+v[i]);
            sol.pop_back();
            sumes_iguals3(s,n,v,sol,i+1,suma);
        }
        else if(suma <= s){
            sumes_iguals3(s,n,v,sol,i+1,suma);
        }         
    }
}


int main(){
    int s, n;
    cin >> s >> n;
    vector<int> num(n);       
    vector<int> sol(n);  
    in total = 0;  
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        total += c[i];
    }

    if(total >= num) sumes_iguals3(sol,0,n,c,num,0,total)
}


/*
#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<int>& sol) {
    int mida = sol.size();
    cout << "{" << sol[0];
    for(int i = 1; i < mida; ++i){
        cout << "," << sol[i];
    }
    cout << "}" << endl;
}

void sumes_iguals3(int s, int n, const vector<int>& v, vector<int>& sol, int i, int suma) {
    if(i == n) {
        if(s == suma) escriure_sol(sol);
    }
    else {
        if(suma + v[i] <= s) {
            sol.push_back(v[i]);
            sumes_iguals3(s,n,v,sol,i+1,suma+v[i]);
            sol.pop_back();
            sumes_iguals3(s,n,v,sol,i+1,suma);
        }
        else if(suma <= s){
            sumes_iguals3(s,n,v,sol,i+1,suma);
        }         
    }
}


int main(){
    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<int> sol;

    sumes_iguals3(s,n,v,sol,0,0);
}

*/

/*
#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(int n,const vector<int>& v,const vector<bool>& vis) {
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(vis[i]){
            if(primer) {
                primer = false;
                cout << "{" << v[i];
            }
            else cout << "," << v[i];
        }
    }
    cout << "}" << endl;
}

void sumes_iguals3(int s, int n, const vector<int>& v, vector<bool>& vis, int i, int suma) {
    if(i == n) {
        if(s == suma) escriure_sol(n,v,vis);
    }
    else {
        if(suma + v[i] <= s) {
            vis[i] = true;
            sumes_iguals3(s,n,v,vis,i+1,suma+v[i]);
            vis[i] = false;
        }
        if(suma <= s){
            vis[i] = false;
            sumes_iguals3(s,n,v,vis,i+1,suma);
        }         
    }
}


int main(){
    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<bool> vis(n,false);

    sumes_iguals3(s,n,v,vis,0,0);
}
*/