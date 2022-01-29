#include <iostream>
#include <vector>
using namespace std;

int cercar_pic(const vector<int>& v, int esq, int dre){
    if(dre == esq+1) {
        if(v[esq] > v[dre]) return esq;
        else return dre;
    }
    if(dre == esq) return esq;
    int m = (dre+esq)/2;
    if(v[m] > v[m+1]) return cercar_pic(v,esq,m-1);
    else if(v[m] > v[m-1]) return cercar_pic(v,m+1,dre);
    return m;
}

bool searc_part_esq(const vector<int>& v,int x, int esq, int dre){
    if(dre < esq) return false;
    if(dre > esq) {
        int m = (dre+esq)/2;
        if(v[m] == x) return true;
        if(v[m] < x) return searc_part_esq(v,x,m+1,dre);
        return searc_part_esq(v,x,esq,m-1);
    }
}

bool searc_part_dre(const vector<int>& v,int x, int esq, int dre){
    if(dre < esq) return false;
    if(dre > esq) {
        int m = (dre+esq)/2;
        if(v[m] == x) return true;
        if(v[m] < x) return searc_part_dre(v,x,esq,m-1);
        return searc_part_dre(v,x,m+1,dre);
    }
}

bool search(int x, const vector<int>& v){
    int pic = cercar_pic(v,0,v.size()-1);
    if(v[pic] == x) return true;
    return searc_part_esq(v,x,0,pic-1) or searc_part_dre(v,x,pic+1,v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}