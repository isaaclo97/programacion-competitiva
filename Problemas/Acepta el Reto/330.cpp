
#include <bits/stdc++.h>
using namespace std;

struct state{
  string val;
  int index;
};

string convert(string c){
    if(c.length()!=4) return c;
    string add(1, c[3]);
    string add2(1, c[3]+1);
    string add3(1, c[3]-1);
    //cout<<add<<endl;
    if(c[0]=='S'&&c[1]=='i'&&c[2]=='#') return "Do"+add2;
    else if(c[0]=='R'&&c[1]=='e'&&c[2]=='b') return "Do#"+add;
    else if(c[0]=='M'&&c[1]=='i'&&c[2]=='b') return "Re#"+add;
    else if(c[0]=='F'&&c[1]=='a'&&c[2]=='b') return "Mi"+add;
    else if(c[0]=='M'&&c[1]=='i'&&c[2]=='#') return "Fa"+add;
    else if(c[0]=='F'&&c[1]=='a'&&c[2]=='#') return "Solb"+add;
    else if(c[0]=='L'&&c[1]=='a'&&c[2]=='b') return "Sol#"+add;
    else if(c[0]=='S'&&c[1]=='i'&&c[2]=='b') return "La#"+add;
    else if(c[0]=='D'&&c[1]=='o'&&c[2]=='b') return "Si"+add3;
    return c;
}
int main(){  
    int N;
    while(scanf("%d",&N)==1 && N!=0){
        string nota;
        map<string,int> M;
        string arr[]={"Do","Do#","Re","Re#","Mi","Fa","Solb","Sol","Sol#","La","La#","Si"};
        vector<state> elements;
        for(int i=1; i<8;i++){
            for(int j=0; j<12;j++) { state aux; aux.index=(i-1)*8+j+1; aux.val=arr[j]+to_string(i); elements.push_back(aux); }
        }
        cin.ignore();
        for(int i=0; i<N;i++){
            cin>>nota;
            string r = convert(nota);
            //cout<<nota<<" ---> "<<r<<endl;
            M[r]++;
        }
        int index=0x3f3f3f3f,index2=-0x3f3f3f3f;
        for(int i= 0; i<elements.size(); i++)
            if(M[elements[i].val]!=0) { index=min(index,i); index2=max(index2,i); }

        for(int i=index; i<=index2;i++)
            if(i==index) printf("%d",M[elements[i].val]);
            else printf(" %d",M[elements[i].val]);
        printf("\n");
    }
    return 0;
}
