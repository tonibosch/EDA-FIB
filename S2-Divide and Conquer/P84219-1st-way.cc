#include <iostream>
#include <vector>
using namespace std;

int i_first_occurrence(double x, const vector<double>& v, int e, int d) {
    if(e > d) return -1;
    else if(e == d){                    //Hay un elemento
        if(v[e] == x) return e;         //El único elemento que hay es el que toca
        else return -1;
    }
    else {                              //Quedan umás de un elemento
        int m = (e+d)/2;
        if(x <= v[m]) return i_first_occurrence(x,v,e,m);
        else return i_first_occurrence(x,v,m+1,d);
    }
}


int first_occurrence(double x, const vector<double>& v) {
    return i_first_occurrence(x,v,0,v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
