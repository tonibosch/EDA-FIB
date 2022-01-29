#include <iostream>
#include <map>
#include <string>
using namespace std;

int main (){
    map<string,int> m;
    string op;
    while(cin >> op){
        if(op == "minimum?"){
            if (m.empty()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << (*m.begin()).first << ", " << (*m.begin()).second << " time(s)" << endl;
        }
        else if(op == "maximum?"){
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                map<string,int>:: iterator it = --m.end();
                cout << "maximum: " << (*it).first << ", " << (*it).second << " time(s)" << endl;
            }
        }
        else if(op == "store"){
            string p;
            cin >> p;
            map<string,int>:: iterator it = m.find(p);
            if(it == m.end()) m.insert(make_pair(p,1));             //Primera aparició d'una paraula, per això la inicialitzem a 1
            else (*it).second += 1;                                 //Sumem 1, ja que la paraula està repetida
        }

        else if(op == "delete") {
            string p;
            cin >> p;
            map<string,int>:: iterator it = m.find(p);
            if ((*it).second == 1) m.erase(it);                     
            else (*it).second -= 1;                                //Esborrem una de les seves aparicions
        }
    }
}