#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {

    string b;
    while(getline(cin,b))
    {
        stack<char> pila;
        bool correcto=true;
      for(unsigned int i=0; i<b.length();i++)
      {
          if( b[i] == '(' || b[i] == '{' || b[i] == '[' )
                      pila.push(b[i]);
          else if( b[i] == ')')
                  {
                      if(pila.empty())
                      {
                          correcto=false;
                          break;
                      }
                      if(pila.top()=='(')
                              pila.pop();
                      else
                      {
                          correcto=false;
                          break;
                      }
                  }
          else if( b[i] == '}')
                  {
                      if(pila.empty())
                      {
                          correcto=false;
                          break;
                      }

                      if(pila.top()=='{')
                              pila.pop();
                      else
                      {
                          correcto=false;
                          break;
                      }

                  }
          else if(b[i] == ']')
          {
              if(pila.empty())
              {
                  correcto=false;
                  break;
              }
              if(pila.top()=='[')
                  pila.pop();
              else
              {
                  correcto=false;
                  break;
              }
          }
          else
              continue;
      }
      if(pila.empty()&&correcto)
          cout<<"YES\n";
      else
          cout<<"NO\n";
    }
    return 0;
}
