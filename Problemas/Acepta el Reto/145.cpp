#include <bits/stdc++.h>
using namespace std;
    int main()
    {
            string cs;
        while (getline(cin,cs)) {
            stack<char> pile;
            char c;
            int total = 0;
            for (int i = cs.length()-1; i >= 0; i--)
            {
                c = cs[i];
                if (c == 'H')
                {
                    if(!pile.empty())
                        if (pile.top() == 'M')
                        {
                             pile.pop();
                            total++;
                        }
                        else
                            while(!pile.empty())
                            {
                                pile.pop();
                            }
                }
                else if (c == 'h')
                {
                    if(!pile.empty())
                        if (pile.top() == 'm')
                        {
                            pile.pop();
                            total++;
                        }
                        else
                            while(!pile.empty())
                            {
                                pile.pop();
                            }
                }
                else if (c == 'M')
                    pile.push('M');
                else if (c == 'm')
                     pile.push('m');
                else if (c == '@')
                 {
                    while(!pile.empty())
                    {
                        pile.pop();
                    }
                }
            }
            cout<<total<<endl;
        }
        return 0;
    }
