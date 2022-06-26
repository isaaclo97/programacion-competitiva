#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num,aux=1,a=1;
    cin>>num;
    char arr[num];
    memset(arr,'o',sizeof(arr));
    while(aux<=num){
            arr[aux-1]='O';
            int t = aux;
            aux+=a;
            a=t;
        }
    for(int i=0; i<num;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}
