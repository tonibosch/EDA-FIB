#include <iostream>
#include <vector>
using namespace std;


void escriu (const vector<bool>& v, const vector<int>& s) {
   bool primer = true;
   cout << "{";
   for (int i = 0; i < v.size(); ++i) {
	   if (v[i]) {
		   if (primer) primer = false;
		   else if (not primer) cout << ",";		 
		   cout << s[i];
	   }
   }
   cout << "}" << endl;
}

void back(vector<bool>& sol, int i, int n, const vector<int>& numeros, int num, int suma_act, int total) {
	if (i == n) {
		if (suma_act == num) escriu(sol, numeros);
	}
	else if (suma_act <= num and suma_act + total >= num) {
		sol[i] = false;
		back(sol, i+1, n, numeros, num, suma_act, total-numeros[i]);
		sol[i] = true;
		back(sol, i+1, n, numeros, num, suma_act+numeros[i], total-numeros[i]);
	}
}

int main () {
   int num, n;
   cin >> num >> n;
   vector<int> c(n);
   vector<bool> sol(n);
   int total = 0;
   for (int i = 0; i < n; ++i) {
      cin >> c[i];
      total += c[i];
   }
   if(total >= num) back(sol,0,n,c,num,0,total);
}