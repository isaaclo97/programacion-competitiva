
#include <bits/stdc++.h>
using namespace std;


int main(){
    int cases; scanf("%d",&cases);
    map<char,int> M; M['T']=0; M['R']=1; M['W']=2; M['A']=3; M['G']=4;
    M['M']=5; M['Y']=6; M['F']=7; M['P']=8; M['D']=9; M['X']=10; M['B']=11;
    M['N']=12; M['J']=13; M['Z']=14; M['S']=15; M['Q']=16; M['V']=17; M['H']=18;
    M['L']=19; M['C']=20; M['K']=21; M['E']=22;
    while(cases--){
      string DNI; cin>>DNI;
      int resto;
      int remaining=0;
      char word = DNI[DNI.length()-1];
      resto = M[word];
      vector<int> V;
      for(unsigned int i=0; i<DNI.length()-1;i++){
          if(DNI[i]=='?') { remaining++; V.push_back(i);}
      }
      int res = 0;
      if(remaining==1){
          for(int i=0; i<=9;i++){
              DNI[V[0]]=i+'0';
              if(stoi(DNI)%23==resto) res++;
          }
      }
      if(remaining==2){
          for(int i=0; i<=9;i++){
              for(int j=0; j<=9;j++){
                  DNI[V[0]]=i+'0';
                  DNI[V[1]]=j+'0';
                  if(stoi(DNI)%23==resto) res++;
              }
          }
      }
      if(remaining==3){
          for(int i=0; i<=9;i++){
              for(int j=0; j<=9;j++){
                  for(int k=0; k<=9;k++){
                      DNI[V[0]]=i+'0';
                      DNI[V[1]]=j+'0';
                      DNI[V[2]]=k+'0';
                      if(stoi(DNI)%23==resto) res++;
                  }
              }
          }
      }
      if(remaining==4){
          for(int i=0; i<=9;i++){
              for(int j=0; j<=9;j++){
                  for(int k=0; k<=9;k++){
                      for(int l=0; l<=9;l++){
                          DNI[V[0]]=i+'0';
                          DNI[V[1]]=j+'0';
                          DNI[V[2]]=k+'0';
                          DNI[V[3]]=l+'0';
                        if(stoi(DNI)%23==resto) res++;
                      }
                  }
              }
          }
      }
      printf("%d\n",res);
    }
  return 0;
}
