#include<bits/stdc++.h>
using namespace std;
int main() {
    string line;
    while(getline(cin,line)) {
    int arr[10];
    memset(arr,0,sizeof(arr));
    int num;
    for(unsigned int i=0; i<line.length();i++)
    {
        if(i==0) num=line[i]-48;
        arr[line[i]-48]++;
    }
    int num1 = arr[num];
    bool sol=true;
    for(unsigned int i=0; i<10;i++)
    {
        if(arr[i]!=num1)
        {
            sol=false;
            break;
        }

    }
    if(sol)
    cout<<"subnormal"<<endl;
    else
        cout<<"no subnormal"<<endl;
    }
    return 0;
}
