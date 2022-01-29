#include <iostream>
#include <vector>
using namespace std;

vector<int> mult (vector<int>& v1, vector<int>& v2) {
	int n = v1.size();
	vector<int> sol(n);
	for (int i = 0; i < n; ++i) {
		sol[i] = v1[v2[i]];
	}
	return sol;
}

void potencies (vector<int>& v, int k, vector<int>& sol) {
	if (k == 0) {
		for (int i = 0; i < v.size(); ++i) sol[i] = i;
	}
	else {
		vector<int> aux(v.size());
		potencies(v, k/2, aux);
		sol = mult(aux, aux);
		if (k%2 != 0) sol = mult(sol, v);
	}
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n), sol(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int k;
        cin >> k;
        
        potencies(v, k, sol);
        
        for (int i = 0; i < n; ++i) {
        	if (i != 0) cout << " ";
        	cout << sol[i];
        }
        cout << endl;
    }
}

