#include<iostream>
#include <map>
#include <string>
using namespace std;

int main () {
    map<string,int> m;
    string s,op;
    map<string,int>::iterator it = m.end();
    while(cin >> s >> op){
        map<string,int>::iterator it = m.find(s);
        if(op == "enters"){
            if (it == m.end()) m.insert(make_pair(s,0));
            else cout << s << " is already in the casino" << endl;
        }
        else if(op == "wins"){
            int num;
            cin >> num;
            if (it == m.end()) cout << s << " is not in the casino" << endl;
            else (*it).second += num;
        }
        else if(op == "leaves"){
            if (it == m.end()) cout << s << " is not in the casino" << endl;
            else {
                cout << s << " has won " << (*it).second << endl;
                m.erase(it);
            }
        }
    }
    cout << "----------" << endl;
    it = m.begin();
    while(it != m.end()){
        cout << (*it).first << " is winning " << (*it).second << endl;
        m.erase(it);
        ++it;
    }

}