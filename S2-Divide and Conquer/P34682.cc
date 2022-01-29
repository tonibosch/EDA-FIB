#include <iostream>
#include <vector>
using namespace std;

int fixed_points(vector<int>& v, int a, int esq, int dre){
    if(esq <= dre){
        int m = (esq+dre)/2;
        if(v[m]+a < m+1) return fixed_points(v,a,m+1,dre);
        if(v[m]+a > m+1) return fixed_points(v,a,esq,m-1);
        if(v[m]+a == m+1) {
            int x = fixed_points(v,a,esq,m-1);
            if(x != -1) return x;
            return m+1;
        }
    }
    return -1;
}

int main() {
    int n;
    int num_seq = 0;
    while(cin >> n){
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];

        int m; 
        cin >> m;
        ++num_seq;
        cout << "Sequence #" << num_seq << endl;
        for(int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            int res = fixed_points(v,a,0,n-1);
            if(res != -1) cout << "fixed point for " << a << ": " << res << endl;
            else cout << "no fixed point for " << a << endl;
        }
        cout << endl;
    }
}