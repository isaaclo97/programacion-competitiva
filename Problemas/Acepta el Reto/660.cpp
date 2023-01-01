#include <bits/stdc++.h>
using namespace std;

set<string> total;

// La letra y no se considera vocal.
bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

void checkSilabas(const string &word) {
    for(int j=0; j<word.size();j++){
        //Vocal + consonante (si al final van dos consonantes seguidas). AL
        if(isVowel(word[j]) && (j+1)<word.size() && !isVowel(word[j+1])  && (j+2>=word.size() ||((j+2)<word.size() && !isVowel(word[j+2])))) {
            string res = ""; res+=word[j]; res+=word[j+1];
            total.insert(res);
            j++;
        }
        //Consonante + vocal + consonante (si al final van dos consonantes seguidas). DEL E GIP TO
        if(!isVowel(word[j]) && (j+1)<word.size() && isVowel(word[j+1]) && (j+2)<word.size() && !isVowel(word[j+2])  && (j+3>=word.size() ||((j+3)<word.size() && !isVowel(word[j+3])))) {
            string res = ""; res+=word[j]; res+=word[j+1]; res+=word[j+2];
            total.insert(res);
            j += 2;
        }
        //Vocal sola A
        else if(isVowel(word[j])) {
            string res = ""; res+=word[j];
            total.insert(res);
        }
        //Consonante + vocal (si no va seguida de dos consonantes). CA SA
        else if(!isVowel(word[j]) && (j+1)<word.size() && isVowel(word[j+1])) {
            string res = ""; res+=word[j]; res+=word[j+1];
            total.insert(res);
            j++;
        }
    }
}


int main(){
    int lines;
    while(scanf("%d",&lines)==1) {
        cin.ignore();
        while (lines--) {
            total.clear();
            string line;
            getline(cin, line);
            string word = "";
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    checkSilabas(word);
                    word = "";
                } else {
                    word += tolower(line[i]);
                }
            }
            checkSilabas(word);
            //for(auto s:total)
            //    cout<<s<<endl;
            printf("%d\n", total.size());
        }
    }
    return 0;
}