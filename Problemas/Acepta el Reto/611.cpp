
#include <bits/stdc++.h>
using namespace std;

int main(){
    int year,year_book,books;
    while(scanf("%d",&year)==1){
        cin.ignore();
        string name,book_name,final_book; getline(cin,name);
        scanf("%d",&books);
        cin.ignore();
        bool todos = true;
        bool ninguno = true;
        int final_year = 0x3f3f3f3f;
        for(int i=0; i<books;i++){
            scanf("%d",&year_book); cin.ignore();
            getline(cin,book_name);
            if(year_book<year) todos=false;
            //desde ese año en adelante
            if(year_book>=year) ninguno=false;
            if(year_book>=year && final_year>year_book){
                final_year = year_book;
                final_book = book_name;
            }
        }
        if(ninguno) printf("NINGUNA\n");
        else if(todos) printf("TODAS\n");
        else cout<<final_book<<'\n';
    }
    return 0;
}
