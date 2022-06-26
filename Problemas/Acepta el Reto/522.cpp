#include <bits/stdc++.h>
using namespace std;

int main(){
    string first,second;
    while(cin>>first && cin>>second){
        int index = 0;
        for(unsigned int i=0; i<min(first.length(),second.length());i++){
            if(first[i]!=second[i])
            {
                index=i;
                if(i!=0 && ((first[i-1]=='l' && second[i-1]=='l') || (first[i-1]=='c' && second[i-1]=='c'))) index--;
                break;
            }
        }
        if((first.length()-index)>=2 && (second.length()-index)>=2){
            if(first[index]=='c' && first[index+1]=='h' && second[index]=='c' && second[index+1]!='h') cout<<second<<'\n';
            else if(second[index]=='c' && second[index+1]=='h' && first[index]=='c' && first[index+1]!='h') cout<<first<<'\n';
            else if(first[index]=='l' && first[index+1]=='l' && second[index]=='l' && second[index+1]!='l') cout<<second<<'\n';
            else if(second[index]=='l' && second[index+1]=='l' && first[index]=='l' && first[index+1]!='l') cout<<first<<'\n';
            else if(lexicographical_compare(first.begin()+index, first.end(), second.begin()+index, second.end())) cout<<first<<'\n';
            else cout<<second<<'\n';
        }
        else{
            if(lexicographical_compare(first.begin(), first.end(), second.begin(), second.end())) cout<<first<<'\n';
            else cout<<second<<'\n';
        }
    }
    return 0;
}
