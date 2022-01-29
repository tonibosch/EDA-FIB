#include <iostream>
#include <queue>
using namespace std;

int main () {
    priority_queue<int> C;
    char s;
    while(cin >> s){
        if(s == 'A'){
            if(C.empty()) cout << "error!" << endl;
            else cout << C.top() << endl;                   //Consulta el número més gran
        }
        else if(s == 'S'){
            int x;
            cin >> x;
            C.push(x);                                      //Guarda una còpia del número x donat
        }
        else if(s == 'R'){                                  //Esborra el número més gran (un d’ells, si està repetit).
            if(C.empty()) cout << "error!" << endl;
            else C.pop();
        }
        else if(s == 'I'){
            int x;
            cin >> x;
            if(C.empty()) cout << "error!" << endl;
            else {
                int y = C.top();
                y += x;                                       //y = C.top() + x
                C.pop();
                C.push(y);


            } 
        }
        else if(s == 'D'){
            int x;
            cin >> x;
            if(C.empty()) cout << "error!" << endl;
            else {
                int y = C.top();
                y -= x;                                       //y = C.top() - x
                C.pop();
                C.push(y);
            }
        }
    }
}