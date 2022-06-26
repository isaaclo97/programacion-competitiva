#include <bits/stdc++.h>
using namespace std;

int myNumber;
string myLetters;
int compare(int number, string letters){
    if(letters==myLetters) return myNumber<number;
    //printf("Orden: %d \n", lexicographical_compare(myLetters.begin(), myLetters.end(), letters.begin(), letters.end()));
    return lexicographical_compare(myLetters.begin(), myLetters.end(), letters.begin(), letters.end());
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int number; string letters;
        long long int oldCar=0,newCar=0;
        scanf("%d",&myNumber); cin>>myLetters;
        //0001BBB 0002BBB 0000BBB 9999BBB 0 -> 1 2
        while(cin>>letters && letters.length()!=1)
        {
            number = stoi(letters.substr(0,4));
            letters = letters.substr(4,7);
            //cout<<number<<" "<<letters<<endl;
            if(compare(number,letters)==1) newCar++;
            else oldCar++;
        }
        printf("%lld %lld\n",oldCar,newCar);
    }
    return 0;
}
