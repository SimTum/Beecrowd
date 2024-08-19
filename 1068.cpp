#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string equation;
    int ocount = 0, ccount = 0;
    bool check = 1; 
    do
    {
        getline(cin,equation);
        for (int i = 0; i < equation.size(); i++) {
            if (equation[i] == '(') 
            {
                ocount++;
            }
            if (equation[i] == ')') 
            {
                ccount++;
                if(ccount > ocount) {
                    check = 0;
                    break;
                }
            }
        }
        if (ccount != ocount) check = 0;
        cout << ((check)? "correct":"incorrect") << endl;
        equation.clear();
        check = 1;
        ccount = 0;
        ocount = 0;
    } while (equation != " ");

} 