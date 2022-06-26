#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string fi="",se="";
int diff(string C,string T)
{
    int arr[130];
    memset(arr,0,sizeof(arr));
    int res = 0;
    for(unsigned int i=0; i<C.length();i++) arr[(int)C[i]]++;
    for(unsigned int i=0; i<T.length();i++) arr[(int)T[i]]--;
    for(unsigned int i=0; i<C.length();i++) if(arr[(int)C[i]]!=0) res++;
    return res;
}
int orden(string C,string T)
{
     int arr[130];
     memset(arr,0,sizeof(arr));
     int res = 0;
     int ml = min(C.length(),T.length());
     for(int i=0; i<ml;i++) if(arr[(int)C[i]]!=arr[(int)T[i]]) res++;
     return res+abs(C.length()-T.length());
}
int pueden(string C,string T)
{
    int arr[130];
    memset(arr,0,sizeof(arr));
    int res = 0;
    int ml = max(C.length(),T.length());
    for(unsigned int i=0; i<C.length();i++) arr[(int)C[i]]++;
    for(unsigned int i=0; i<T.length();i++) arr[(int)T[i]]--;
    for(int i=0; i<ml;i++) if(arr[(int)C[i]]!=0) res++;
    return res;
}
void cambiar(string C,string T)
{
    int flag = 0;
    for(unsigned int i=0; i<C.length();i++)
    {
        if(C[i]!=T[i]&&flag==0) { fi=C[i]; flag=1;}
        if(C[i]!=T[i]&&flag==1)  se=C[i];
    }
}
char insertar(string &C,string &T)
{
    int arr[130];
    memset(arr,0,sizeof(arr));
    for(unsigned int i=0; i<C.length();i++) arr[(int)C[i]]++;
    for(unsigned int i=0; i<T.length();i++) arr[(int)T[i]]--;
    for(unsigned int i=0; i<C.length();i++) if(arr[(int)C[i]]!=0) return C[i];
    return C[0];
}
string solution(string &S,string &T)
{
    int Cl = S.length();
    int Tl = T.length();
    if(S==T) return "NOTHING";
    else if(abs(Cl-Tl)>1) return "IMPOSSIBLE"; //tienen mas de dos de longitud
    else if((pueden(S,T)>1 && Cl!=Tl) || (pueden(S,T)>2 && Cl==Tl) || orden(S,T)>1) return "IMPOSSIBLE"; //se diferencian en más de dos
    else{
        if(Cl>Tl) {string re = "DELETE ";
            re+=insertar(S,T);
                   return re; }
        else if(Cl<Tl){  string re = "INSERT ";
                       re+=insertar(T,S);
                       return re;
                      }
        else {
            if(diff(S,T)!=0) return "IMPOSSIBLE";
            cambiar(S,T);
            string aux = "SWAP "+fi+" "+se;
            return aux;
        }
    }
}
int main()
{
    string a = "nice";
    string b = "niece";
    cout<<solution(a,b)<<'\n';
    a="form"; b="from";
    cout<<solution(a,b)<<'\n';
    a="o"; b="odd";
    cout<<solution(a,b)<<'\n';
    a="prueba"; b="prueba";
    cout<<solution(a,b)<<'\n';
    a="pruebha"; b="prueba";
    cout<<solution(a,b)<<'\n';
    a="asdf"; b="oian";
    cout<<solution(a,b)<<'\n';
    a="ask"; b="an";
    cout<<solution(a,b)<<'\n';
    a="a"; b="ab";
    cout<<solution(a,b)<<'\n';
    a="a"; b="";
    cout<<solution(a,b)<<'\n';
    a="ab"; b="b";
    cout<<solution(a,b)<<'\n';
    a=""; b="";
    cout<<solution(a,b)<<'\n';
    a=""; b="a";
    cout<<solution(a,b)<<'\n';
    a="as"; b="an";
    cout<<solution(a,b)<<'\n';
    a="as"; b="sa";
    cout<<solution(a,b)<<'\n';
    return 0;
}
