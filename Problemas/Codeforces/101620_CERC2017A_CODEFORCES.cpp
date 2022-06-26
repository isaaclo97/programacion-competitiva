#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int r,p; scanf("%d%d",&r,&p);
    int peopleleft=0, peopleright=0;
    char matrix[r+3][11];
    int numasientos[r+3][11]; memset(numasientos,0,sizeof(numasientos));
    int arr[r+3]; memset(arr,0,sizeof(arr));
    char a;
    for(int i=0; i<r+3;i++)
    {
       for(int j=0; j<11;j++)
       {
           cin>>a; matrix[i][j]=a;
           if(a=='#' && j<5) peopleleft++;
           else if(a=='#' && j>5) peopleright++;
           if(a=='#') { arr[i]++; numasientos[i][j]++;}
       }
    }
    char letra = 'a';
    for(int i=0; i<p;i++)
    {
        //solve A and B rule
        int mini = INF,row=-1;
        /*
        ........... 0
        ---.---.--- 1
        ........... 2
        ---.---.--- 3
        ........... 4

        2 + 3 = 5/2 = 2
        */
        int middlexit = (r+3)/2;
        if(arr[1]!=9 || arr[middlexit+1]!=9)
        {
            //filas no completas cerca de salidas
            if(arr[middlexit+1]<arr[1]) row=middlexit+1;
            else row=1;
        }
        else
        {
            int flag=0;
            vector<int> V;
            for(int k=0; k<r+3;k++)
            {
                if(k==0 || k==r+2 || k==middlexit) continue;
                if(mini>arr[k]) { mini=arr[k]; row=k; flag=0; V.clear();}
                else if(mini==arr[k]) { if(flag==0) V.push_back(row); flag=1; V.push_back(k); }
            }
            if(flag==1)
            {
                flag=0;
                vector<int> aux;
                mini = INF;
                for(unsigned int k1=0; k1<V.size();k1++)
                {
                    //r = 2 -> r = 5 -> 0 2 4
                    int minaux = min(abs(V[k1]-0),min(abs(V[k1]-(middlexit)),abs(V[k1]-(r+2))));
                    if(mini>minaux) { mini=minaux; row=V[k1]; flag=0; aux.clear();}
                    else if(mini==minaux) {
                        if(flag==0) aux.push_back(row); flag = 1; aux.push_back(V[k1]);
                    }
                }
                if(flag==1)
                {
                    sort(aux.begin(),aux.end());
                    row = aux[0];
                }
            }
        }
        // ---.---.---
        // 012345678910
        //Seleccionar asiento
        if(numasientos[row][4]==0 || numasientos[row][6]==0)
        {
            if(numasientos[row][4]==0 && numasientos[row][6]==0)
            {
                if(peopleleft<=peopleright)
                {
                    numasientos[row][4]++;
                    matrix[row][4]= letra;
                    peopleleft++;
                }
                else{
                    numasientos[row][6]++;
                    matrix[row][6]= letra;
                    peopleright++;
                }
            }
            else if(numasientos[row][4]==0)
            {
                peopleleft++;
                numasientos[row][4]++;
                matrix[row][4]= letra;
            }
            else{
                peopleright++;
                numasientos[row][6]++;
                matrix[row][6]= letra;
            }
        }
        else if(numasientos[row][2]==0 || numasientos[row][8]==0)
        {
            if(numasientos[row][2]==0 && numasientos[row][8]==0)
            {
                if(peopleleft<=peopleright)
                {
                    numasientos[row][2]++;
                    matrix[row][2]= letra;
                    peopleleft++;
                }
                else{
                    numasientos[row][8]++;
                    matrix[row][8]= letra;
                    peopleright++;
                }
            }
            else if(numasientos[row][2]==0)
            {
                peopleleft++;
                numasientos[row][2]++;
                matrix[row][2]= letra;
            }
            else{
                peopleright++;
                numasientos[row][8]++;
                matrix[row][8]= letra;
            }

        }
        else if(numasientos[row][0]==0 || numasientos[row][10]==0)
        {
            if(numasientos[row][0]==0 && numasientos[row][10]==0)
            {
                if(peopleleft<=peopleright)
                {
                    numasientos[row][0]++;
                    matrix[row][0]= letra;
                    peopleleft++;
                }
                else{
                    numasientos[row][10]++;
                    matrix[row][10]= letra;
                    peopleright++;
                }
            }
            else if(numasientos[row][0]==0)
            {
                numasientos[row][0]++;
                matrix[row][0]= letra;
                peopleleft++;
            }
            else{
                numasientos[row][10]++;
                matrix[row][10]= letra;
                peopleright++;
            }
        }
        else if(numasientos[row][5]==0)
        {
            numasientos[row][5]++;
            matrix[row][5] = letra;
        }
        else{
            if(numasientos[row][1]==0 && numasientos[row][9]==0)
            {
                if(peopleleft<=peopleright)
                {
                    numasientos[row][1]++;
                    matrix[row][1]= letra;
                    peopleleft++;
                }
                else{
                    peopleright++;
                    numasientos[row][9]++;
                    matrix[row][9]= letra;
                }
            }
            else if(numasientos[row][1]==0)
            {
                peopleleft++;
                numasientos[row][1]++;
                matrix[row][1]= letra;
            }
            else{
                peopleright++;
                numasientos[row][9]++;
                matrix[row][9]= letra;
            }
        }
        arr[row]++;
        letra++;
    }
    //imprimir
    for(int i=0; i<r+3;i++)
    {
       for(int j=0; j<11;j++)
       cout<<matrix[i][j];
      cout<<'\n';
    }
    return 0;
}
