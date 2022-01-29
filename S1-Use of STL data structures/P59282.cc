#include <iostream>
#include <map>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int,int> m;
    string op;
    while (cin >> op) {
        double suma, num;
        int num_total;
        if (op == "number"){
            cin >> num;
            if (m.empty()){                                                //Primer nombre del map
                m.insert(make_pair(num,1));
                suma = num;
                num_total = 1;
            }
            else {
                map<int,int>::iterator it = m.find(num);
                if (it != m.end()) ++(*it).second;                         //Es un nombre repetit
                else  m.insert(make_pair(num,1));                         //Es un nombre que no estaba al map
                
                suma += num;
                ++num_total;
            }
        }
        else if (m.begin() != m.end()){                                    // op == delete y el map no esta vacio
            suma -= (*m.begin()).first;
            --num_total;
            --(*m.begin()).second;

           if ((*m.begin()).second == 0) m.erase(m.begin());                    //S'esborra el nombre, ja que nomes hi havia una repetició
        }
        if (m.empty()) cout << "no elements" << endl;
        else cout << "minimum: " << (*m.begin()).first << ", maximum: " << (*--m.end()).first << ", average: " << suma/num_total << endl;
    }
} 