//Problema D
//caso espacio entre consonante y vocal
//Notas de canciones solo consonante vocal
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string m;
    int k;
    cin>>k;
    cin.ignore();
    while(k--)
    {
    int resultado=0;
    bool consonante=false;
    getline(cin,m);
    for(unsigned int i=0; i<m.length();i++)
    {
        if(consonante&&(m[i]=='a'||m[i]=='e'||m[i]=='i'||m[i]=='o'||m[i]=='u'))
        {
            resultado++;
            consonante=false;
        }
        else if(m[i]==' ')
        {
            consonante=false;
        }
        else
        {
            consonante=true;
        }
    }
    cout<<resultado<<endl;
    }
    return 0;
}
*/
//Problema D con espaciador deespacios

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string m;
    int k;
    cin>>k;
    cin.ignore();
    while(k--)
    {
    long long int resultado=0;
    bool res = true;
    getline(cin,m);
    for(unsigned int i=0; i<m.length();i++)
    {
        if((m[i]=='a'||m[i]=='e'||m[i]=='i'||m[i]=='o'||m[i]=='u')&&res)
        {
            resultado++;
            res =false;

        }
        else if((m[i]=='a'||m[i]=='e'||m[i]=='i'||m[i]=='o'||m[i]=='u'))
            continue;
        else
        {
            res = true;
        }
    }
    cout<<resultado<<endl;
    }
    return 0;
}