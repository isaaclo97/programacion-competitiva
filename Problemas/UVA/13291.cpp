
//Problema J Swerc 2017 Frosting on the Cake

#include <bits/stdc++.h>
using namespace std;
int main(){
long long int y,p,w; int cases;
    while(scanf("%d",&cases)!=EOF)
    {
        y=0; p=0; w=0;
        int arr1[cases]; int arr2[cases];
        for(int i=0; i<cases;i++) cin>>arr1[i];
        for(int i=0; i<cases;i++) cin>>arr2[i];

        long long int aw=0,ay=0,ap=0,aw1=0,ay1=0,ap1=0,aw2=0,ay2=0,ap2=0,aw3=0,ay3=0,ap3=0;

        for(int i=0; i<cases;i++)
        {
            if(i<3)
            {
                for(int j=0; j<cases;j++)
                {
                    if(i==0){      aw+=arr1[j]; if(j+1>=cases) break; j++; ay+=arr1[j]; if(j+1>=cases) break; j++; ap+=arr1[j];  }
                    else if(i==1){ ay+=arr1[j]; if(j+1>=cases) break; j++; ap+=arr1[j]; if(j+1>=cases) break; j++; aw+=arr1[j];  }
                    else{          ap+=arr1[j]; if(j+1>=cases) break; j++; aw+=arr1[j]; if(j+1>=cases) break; j++; ay+=arr1[j];  }
                }
                if(i==0){ ap1=ap; aw1=aw; ay1=ay; }
                else if(i==1){ ap2=ap; aw2=aw; ay2=ay; }
                else{ ap3=ap; aw3=aw; ay3=ay; }
                y+=arr2[i]*ay; p+=arr2[i]*ap; w+=arr2[i]*aw; ap=0; aw=0; ay=0;
            }
            else
            {
                if(i%3==0){       y+=arr2[i]*ay1; p+=arr2[i]*ap1; w+=arr2[i]*aw1; }
                else if(i%3==1){  y+=arr2[i]*ay2; p+=arr2[i]*ap2; w+=arr2[i]*aw2; }
                else{             y+=arr2[i]*ay3; p+=arr2[i]*ap3; w+=arr2[i]*aw3; }
            }
        }
        cout<<y<<" "<<p<<" "<<w<<endl;
    }
    return 0;
}

//Problema J Swerc 2017 Frosting on the Cake CON MATRIZ
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
long long int y,p,w; int cases;
    while(scanf("%d",&cases)!=EOF)
    {
        y=0; p=0; w=0;
        int arr1[cases]; int arr2[cases];
        for(int i=0; i<cases;i++) cin>>arr1[i];
        for(int i=0; i<cases;i++) cin>>arr2[i];

        long long int vals[3][3];
        memset(vals,0,sizeof(vals));
        for(int i=0; i<cases;i++)
        {
            if(i<3)
            {
                for(int j=0; j<cases;j++)
                {
                    vals[i][(j+i)%3]+=arr1[j];
                }
                w+=(arr2[i]*vals[i][0]); y+=(arr2[i]*vals[i][1]); p+=(arr2[i]*vals[i][2]);
            }
            else
            {
                 w+=(arr2[i]*vals[i%3][0]); y+=(arr2[i]*vals[i%3][1]); p+=(arr2[i]*vals[i%3][2]);
            }
        }
        cout<<y<<" "<<p<<" "<<w<<endl;
    }
    return 0;
}
*/