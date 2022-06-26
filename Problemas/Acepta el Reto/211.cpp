#include <bits/stdc++.h>
using namespace std;

string arr[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int main(){
    string text,copy;
    while(cin>>text){
        copy=text;
        transform(text.begin(), text.end(), text.begin(),
                         [](unsigned char c){ return tolower(c); });
        string res = "";
        for(unsigned int i=0; i<text.length();i++){
            if(text[i]=='o') res+='-';
            else if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='u') res+='.';
        }
        if(res==arr[text[0]-97]) cout<<copy<<' '<<"OK\n";
        else cout<<copy<<' '<<"X\n";
    }
    return 0;
}
