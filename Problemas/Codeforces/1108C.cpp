#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d",&n);
    string lamps; cin>>lamps;
    int count,count1;
    count=count1=0;
    string l,l1; l=l1=lamps;
    for(unsigned int i=0; i<lamps.size();i++) //RGB
    {
        if(i%3==0 && lamps[i]!='R') { l[i]='R'; count++;}
        else if(i%3==1 && lamps[i]!='G'){ l[i]='G'; count++;}
        else if(i%3==2 && lamps[i]!='B') { l[i]='B'; count++;}
    }
    for(unsigned int i=0; i<lamps.size();i++) //RBG
    {
        if(i%3==0 && lamps[i]!='R') { l1[i]='R'; count1++;}
        else if(i%3==2 && lamps[i]!='G'){ l1[i]='G'; count1++;}
        else if(i%3==1 && lamps[i]!='B'){ l1[i]='B'; count1++;}
    }
    if(count1<count) { count=count1; l=l1;}
    count1=0; l1=lamps;
    for(unsigned int i=0; i<lamps.size();i++) //GRB
    {
        if(i%3==1 && lamps[i]!='R') { l1[i]='R'; count1++;}
        else if(i%3==0 && lamps[i]!='G'){ l1[i]='G'; count1++;}
        else if(i%3==2 && lamps[i]!='B') { l1[i]='B'; count1++;}
    }
    if(count1<count) { count=count1; l=l1;}
    count1=0; l1=lamps;
    for(unsigned int i=0; i<lamps.size();i++) //GBR
    {
        if(i%3==2 && lamps[i]!='R') { l1[i]='R'; count1++;}
        else if(i%3==0 && lamps[i]!='G'){ l1[i]='G'; count1++;}
        else if(i%3==1 && lamps[i]!='B') { l1[i]='B'; count1++;}
    }
    if(count1<count) { count=count1; l=l1;}
    count1=0; l1=lamps;
    for(unsigned int i=0; i<lamps.size();i++) //BRG
    {
        if(i%3==1 && lamps[i]!='R') { l1[i]='R'; count1++;}
        else if(i%3==2 && lamps[i]!='G'){ l1[i]='G'; count1++;}
        else if(i%3==0 && lamps[i]!='B') { l1[i]='B'; count1++;}
    }
    if(count1<count) { count=count1; l=l1;}
    count1=0; l1=lamps;
    for(unsigned int i=0; i<lamps.size();i++) //BGR
    {
        if(i%3==2 && lamps[i]!='R') { l1[i]='R'; count1++;}
        else if(i%3==1 && lamps[i]!='G'){ l1[i]='G'; count1++;}
        else if(i%3==0 && lamps[i]!='B') { l1[i]='B'; count1++;}
    }
    if(count1<count) { count=count1; l=l1;}
    printf("%d\n",count);
    cout<<l;
    return 0;
}
