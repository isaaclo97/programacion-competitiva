#include<bits/stdc++.h>
using namespace std;
int main() {
    string line;
    while(getline(cin,line)) {
        int count=0,letras=0;
      for(int i=0; i<line.length();i++)
      {
          if(line[i]=='!')
              count++;
          else if((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))
              letras++;
      }

    if(count<=letras)
        cout<<"escrito\n";
    else
        cout<<"ESGRITO\n";
    }
    return 0;
}
