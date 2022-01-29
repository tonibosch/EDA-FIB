#include <iostream>
#include <vector>
using namespace std;

void escriure_sol(const vector<int>& v, const vector<bool>& vis, int n){
    cout << "{";
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(vis[i]){
            if(primer) primer = false;
            else cout << ",";
            cout << v[i];
        }
    }
    cout << "}" << endl;
}

void sumesiguals1(const vector<int>& v,vector<bool>& vis, int i, int n, int s, int suma){
    if(i == n) {
        if(s == suma) escriure_sol(v,vis,n);
    }
    else {
        vis[i] = true;
        suma += v[i];
        sumesiguals1(v,vis,i+1,n,s,suma);

        vis[i] = false;
        suma -= v[i];
        sumesiguals1(v,vis,i+1,n,s,suma);
    }
}

int main(){
    int s,n;
    cin >> s >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<bool> vis(n);

    sumesiguals1(v,vis,0,n,s,0);
}