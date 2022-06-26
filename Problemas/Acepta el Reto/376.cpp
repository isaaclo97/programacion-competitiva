#include <iostream>
using namespace std;

int main()
{
    int casos;
    int resultado=0;
   do{
        resultado= 0;
        cin >> casos;
        if(casos!=0)
        {
        int picos[casos];
        for(int i=0; i<casos;i++)
        cin >> picos[i];
    for (int j=0; j<casos; j++)
    {
        if ((picos[j]-picos[j+1])>0&&j!=0&&(picos[j]-picos[j-1])>0&&j!=casos-1)
            resultado++;
        if (picos[0]-picos[casos-1]>0&&(picos[0]-picos[j+1])>0 && j==0) //caso 1º 10
            resultado++;
        if ((picos[casos-1]-picos[0])>0&&(picos[casos-1]-picos[j-1])>0&&j==casos-1) //caso ultimo 10
            resultado++;
    }
    cout << resultado << "\n";
    }
    }
    while (casos!=0);
    return 0;
}
