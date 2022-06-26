#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<long long int> collar,aux;
    long long int perla;
    cin >> perla;
    while(perla!=0)
    {
    while(perla!=0){
        collar.push_back(perla);
        cin>>perla;  
    }
    for(long long int y=0;y<collar.size();y++)
    {
        aux.push_back(collar[y]);
    }
    int sepuede=1;
    sort(collar.begin(),collar.end());

    for (long long int i =0;i<collar.size() && sepuede==1;i++){
        if(i%2==1){
            if (collar[i]!=collar[i-1]||collar.size()%2==0){
                sepuede=0;
            }
        }
    }
    if (sepuede==1){
        int f=0;
        for (int j =0;j<collar.size();j+=2){
            if (j!=collar.size()-1){
                aux[f]=collar[j];
                aux[aux.size()-1-f]=collar[j+1];
            }
            else
                aux[f]=collar[j];
            f++;
        }
        for (long long int k=0;k<aux.size();k++){
            if(k!=aux.size()-1)
            cout<<aux[k]<<" ";
            else
                cout<<aux[k];
        }
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
    cin>>perla; 
 collar.clear();
 aux.clear();
    }
    return 0;
}
