#include <bits/stdc++.h>
using namespace std;

bool isVowel(char a){
    return tolower(a) == 'a' || tolower(a) == 'e' || tolower(a) == 'i' ||
           tolower(a) == 'o' || tolower(a) == 'u';
}

//Una silaba es hasta leer la segunda vocal incluida
bool isConsonante(string a, string b){
    //Tiene 2 vocales -> consonante
    if(a.length()==b.length() && a.length()==2)
        return isVowel(a[0]) && isVowel(a[1]) && a==b;
    //Tiene 2 vocales y 1 o más consonantes que son iguales -> consonante
    return a==b && a.length()>1;
}
//Tiene 2 vocales y 1 o más consonantes que son diferentes -> asonante
bool isAsonante(string a, string b){
    string vowelA="", vowelB="";
    for(int i=0; i<a.length();i++) {
        if(isVowel(a[i])) vowelA+=a[i];
    }
    for(int i=0; i<b.length();i++) {
        if(isVowel(b[i])) vowelB+=b[i];
    }
    return vowelA==vowelB && a!=b && vowelA.length()>1 && vowelB.length()>1;
}
int main() {
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\110_random.in","r",stdin);
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\110_random_isaac.ans","w",stdout);
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        string line;
        cin.ignore();
        vector<string> rimas;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            string rima = "";
            int vowel = 0;
            string line2 = "";
            for (int j = 0; j < line.length(); j++) {
                if(tolower(line[j])>='a' && tolower(line[j])<='z') line2+=tolower(line[j]);
            }
            line = line2;
            for (int j = line.length() - 1; j >= 0; j--) {
                if (isVowel(line[j])) vowel++;
                rima=line[j]+rima;
                if(vowel == 2)
                    break;
            }
           rimas.push_back(rima);
        }
        bool print = false;
        if(n==2) {
            //Pareado: rima consonante AA.
            if(isConsonante(rimas[0],rimas[1])) {
                print = true;
                printf("PAREADO\n");
            }
        }
        else if(n==3){
            //Terceto: rima consonante en el primer y último verso (A-A). Ten en cuenta que AAA no se considerará terceto.
            if(isConsonante(rimas[0],rimas[2]) && !isConsonante(rimas[0],rimas[1])) {
                print = true;
                printf("TERCETO\n");
            }
        }
        else if(n==4){
            if(isConsonante(rimas[0],rimas[3]) && isConsonante(rimas[1],rimas[2]) && !isConsonante(rimas[0],rimas[1])) {
                //Cuarteto: rima consonante ABBA.
                print = true;
                printf("CUARTETO\n");
            }
            else if (isConsonante(rimas[0],rimas[1]) && isConsonante(rimas[1],rimas[2]) && isConsonante(rimas[2],rimas[3])) {
                //Cuaderna via: rima consonante igual en todos los versos (AAAA).
                print = true;
                printf("CUADERNA VIA\n");
            }
            else if (isConsonante(rimas[0],rimas[2]) && isConsonante(rimas[1],rimas[3]) && !isConsonante(rimas[0],rimas[1])) {
                //Cuarteta: rima consonante ABAB.
                print = true;
                printf("CUARTETA\n");
            } else if(isAsonante(rimas[1],rimas[3])
                      && !isAsonante(rimas[0],rimas[1])
                      && !isAsonante(rimas[0],rimas[2])
                      && !isAsonante(rimas[0],rimas[3])
                      && !isAsonante(rimas[1],rimas[2])
                      && !isAsonante(rimas[2],rimas[3])
                      && !isConsonante(rimas[0],rimas[1])
                      && !isConsonante(rimas[0],rimas[2])
                      && !isConsonante(rimas[0],rimas[3])
                      && !isConsonante(rimas[1],rimas[2])
                      && !isConsonante(rimas[1],rimas[3])
                      && !isConsonante(rimas[2],rimas[3])) {
                //Seguidilla: rima asonante en los pares (-a-a).
                // Ten en cuenta que otras combinaciones con más rimas o con rima consonante
                // en lugar de asonante (por ejemplo -aaa o -A-A) no se consideran seguidillas.
                print = true;
                printf("SEGUIDILLA\n");
            }
        }
        if(!print)
            printf("DESCONOCIDO\n");
    }
    return 0;
}