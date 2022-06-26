#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casos;
    cin>>casos;
    cin.ignore();
    while(casos--)
    {
        bool gal=false,ro=false,go=false,gr=false,no=false,br=false,hi=false,in=false,pic=false;
        int contador=0;
        string nombre;
        getline(cin,nombre);
        if(nombre[nombre.length()-2]=='I'&&nombre[nombre.length()-1]=='X')
           {
            gal=true; contador++;
            }
        if((nombre[nombre.length()-2]=='U'&&nombre[nombre.length()-1]=='S')||(nombre[nombre.length()-2]=='U'&&nombre[nombre.length()-1]=='M'))
        {
         ro=true; contador++;
         }
        if(nombre[nombre.length()-2]=='I'&&nombre[nombre.length()-1]=='C')
        {
         go=true; contador++;
         }
        if(nombre[nombre.length()-2]=='A'&&nombre[nombre.length()-1]=='S')
        {
         gr=true; contador++;
         }
        if(nombre[nombre.length()-2]=='A'&&nombre[nombre.length()-1]=='F')
        {
         no=true; contador++;
         }
        if((nombre[nombre.length()-2]=='I'&&nombre[nombre.length()-1]=='S')||(nombre[nombre.length()-2]=='O'&&nombre[nombre.length()-1]=='S')||(nombre[nombre.length()-2]=='A'&&nombre[nombre.length()-1]=='X'))
        {
         br=true; contador++;
         }
        if(nombre[nombre.length()-2]=='E'&&nombre[nombre.length()-1]=='Z')
        {
         hi=true; contador++;
         }
        if(nombre[nombre.length()-1]=='A')
        {
         in=true; contador++;
         }
        if(nombre[0]=='M'&&nombre[1]=='A'&&nombre[2]=='C')
        {
         pic=true;contador++;
        }

        if(contador==1)
        {
                         if(gal)
                         {
                            cout<<"GALO"<<endl;
                            continue;
                         }
                         if(ro)
                         {
                             cout<<"ROMANO"<<endl;
                             continue;
                         }
                         if(go)
                         {
                             cout<<"GODO"<<endl;
                             continue;
                         }
                         if(gr)
                         {
                             cout<<"GRIEGO"<<endl;
                             continue;
                         }
                         if(no)
                         {
                             cout<<"NORMANDO"<<endl;
                             continue;
                         }
                         if(br)
                         {
                             cout<<"BRETON"<<endl;
                             continue;
                         }
                         if(hi)
                         {
                             cout<<"HISPANO"<<endl;
                             continue;
                         }
                         if(in)
                         {
                             cout<<"INDIO"<<endl;
                             continue;
                         }
                         if(pic)
                         {
                             cout<<"PICTO"<<endl;
                             continue;
                         }
        }
       else if(contador==0)
            cout<<"PLUS ULTRA"<<endl;
        else
            cout<<"MULATO"<<endl;
    }
    return 0;
}
