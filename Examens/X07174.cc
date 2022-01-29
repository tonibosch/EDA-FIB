#include <iostream>
#include <vector>
using namespace std;

bool es_multiplo(const vector<int>& no, int y)
{
    for (int i = 0; i < no.size(); ++i)
    {

        if (y % no[i] == 0) return true;
    }
    return false;
}


void escribir_sol(const vector<int>& sol, int n)
{
    for (int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void back (const vector<int>& no, vector<int>& sol, int n, int m, int i, int num, vector<bool>& vis,int sum)
{
    if (i == n) escribir_sol(sol,n);
    else if (num < 10)
    {
        if(not vis[num])
        {
            if (i == 0)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if(not es_multiplo(no,sum+j))
                    {
                        sol.push_back(j);
                        back(no,sol,n,m,i+1,num+1,vis,sum+j); 
                        sol.pop_back();
                    }
                }
            }
            else
            {
                for (int j = 0; j < 10; ++j)
                {
                    if(not es_multiplo(no,sum*10+j))
                    {
                        sol.push_back(j);
                        back(no,sol,n,m,i+1,num+1,vis,sum*10+j); 
                        sol.pop_back();
                    }
                }
            }
        }
    }
}

int main(){
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> no(m);
        for (int i = 0; i < m ; ++i) cin >> no[i];
        vector<int> sol;
        vector<bool> vis(9,false);
        back(no,sol,n,m,0,0,vis,0);
        cout << "----------" << endl;
    }
}