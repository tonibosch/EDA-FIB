#include <iostream>
#include <vector>
using namespace std;

bool i_resistant_search(double x, const vector<double>& v, int e, int d){
    if(e > d )return false;                     //x isn't belong to the vector
    int m = (e+d)/2;
    if(x == v[m]) return true;                  //x belongs to the vector
    else if(x > v[m]){
        if(m > e and x == v[m-1]) return true;     //Hay que mirar si m > e por si hay un solo elemento
        else return i_resistant_search(x,v,m+1,d);
    }
    else {                  //x < v[m]
        if(m < d and x == v[m+1]) return true;      //Hay que mirar si m < d por si hay un solo elemento
        else return i_resistant_search(x,v,e,m-1);

    }

}

bool resistant_search(double x, const vector<double>& v){
    return (i_resistant_search(x,v,0,v.size()-1));
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
            cout << resistant_search(x, V) << endl;
        }
    }
}
