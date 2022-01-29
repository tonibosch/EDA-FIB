#include <iostream>
#include <map>
using namespace std;

int main(){
    string op;
    map<string,string> m;
    while(cin >> op){
        if(op == "liats"){
            string x,y;
            cin >> x >> y;

            map<string,string>::iterator it = m.find(x);
            if(it == m.end()){
                m.insert({x,y});
            }
            else {
                if(it->second != "") {           //x tenia parella
                    map<string,string>::iterator it2 = m.find(it->second);
                    it2->second = "";
                }
                it->second = y;
            }

            it = m.find(y);
            if(it == m.end()){
                m.insert({y,x});
            }
            else {
                if(it->second != "") {           //y parella
                    map<string,string>::iterator it2 = m.find(it->second);
                    it2->second = "";
                }
                it->second = x;
            }
        }
        else {          //op == "info"
            cout << "PARELLES:" << endl;
            map<string,string>::iterator it = m.begin();
            while(it != m.end()){
                if(it->second != "" and it->first < it->second) cout << it->first << " " << it->second << endl;
                ++it;
            }

            cout << "SOLS:" << endl;
            it = m.begin();
            while(it != m.end()){
                if(it->second == "") cout << it->first << endl;
                ++it;
            }

            cout << "----------" << endl;
        }
    }
}

/*
if(ir->second != "" and it-> first < it->second) Para escribir a b i no b a

cout << string(10,'-') << endl;

if(m[x] != "") (Mira si teine pareja)
*/