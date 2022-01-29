#include <iostream>
#include <vector>
using namespace std;

int i_first_ocurrence(double x, const vector<double>& v, int esq, int dre){
    if(esq > dre) return -1;
    int m = (esq+dre)/2;
    if(v[m] == x){
        if(v[m-1] != x) return m;
        else return i_first_ocurrence(x,v,esq,m-1); 
    }
    if(v[m] < x) return i_first_ocurrence(x,v,m+1,dre);
    if(v[m] > x) return i_first_ocurrence(x,v,esq,m-1);
    return -1;
}

int first_occurrence(double x, const vector<double>& v){
    return i_first_ocurrence(x,v,0,v.size()-1);
}

/*
int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    double x;
    cin >> x;
    cout <<  first_occurrence(x,v) << endl;
} 
*/
