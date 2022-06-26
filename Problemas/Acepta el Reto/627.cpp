
#include <bits/stdc++.h>
using namespace std;

inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}


int main(){
    int day,month,year,anios,meses,dias;
    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d/%d/%d",&day,&month,&year)==3){
        fastInput(anios); fastInput(meses); fastInput(dias);
        if(day==0&&month==0&&year==0&&anios==0&&meses==0&&dias==0)
            break;

        int totalDays = ((anios*12+meses)*28)+dias;

        //fast Years
        /*if(day==29 && month==2 && totalDays>0) {totalDays--; month=3; day=1;}
        while(totalDays>=365){
            if(year%4==0 && month<=2 && day<=28 && totalDays>=366){
                year++;
                totalDays-=366;
            }
            else{
                year++;
                totalDays-=365;
            }
        }*/
        //end fast Years

        if (year%4==0) monthDays[1] = 29;
        else monthDays[1] = 28;

        for(int i=0; i<totalDays;i++){
            //day++;
            int restante = monthDays[month-1] - day + 1;
            if((totalDays-i)>restante){
                day += restante;
                i+=restante-1;
            }
            else day++;
            if(monthDays[month-1]<day){
                day=1;
                month++;
                if(month==13){
                    year++;
                    day=month=1;
                    if (year%4==0) monthDays[1] = 29;
                    else monthDays[1] = 28;
                }
            }
        }
        printf("%02d/%02d/%04d\n",day,month,year);
    }
    return 0;
}
