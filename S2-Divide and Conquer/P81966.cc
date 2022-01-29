#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
    if(esq > dre) return -1;
    int m = (esq+dre)/2;
    if(v[m] == x) return m;
    if(v[m] < x) return posicio(x,v,m+1,dre);
    if(v[m] > x) return posicio(x,v,esq,m-1);
    return -1;
}

/*
int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    double x;
    cin >> x;
    cout <<  posicio(x,v,0,v.size()-1) << endl;
}
*/