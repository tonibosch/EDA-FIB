#include <iostream>
#include <vector>
using namespace std;

int cercar_jota(const vector<int>& v, int esq, int dre) {
    if(dre > esq) {
        int m = (dre+esq)/2;
        if(v[m] > v[m+1] and v[m] > v[m-1]) return m;
        else return max(cercar_jota(v,esq,m-1),cercar_jota(v,m+1,dre));
    }
    else if(esq == 0 and v[esq] > v[esq+1]) return esq;
    return -1;
}

bool cerca_dicotomica(int x, const vector<int>& v, int izq, int dre) {
	if (izq > dre) return false;
	int m = (izq + dre)/2;
	if (v[m] > x) return cerca_dicotomica(x, v, izq, m-1);
	else if (v[m] < x) return cerca_dicotomica(x, v, m+1, dre);
	return true;
}

bool search(int x, const vector<int>& v) {
    int j = cercar_jota(v,0,v.size()-1);
    return cerca_dicotomica(x,v,0,j) or cerca_dicotomica(x,v,j+1,v.size()-1);  
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
