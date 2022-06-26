
#include <bits/stdc++.h>
using namespace std;

char phone[300][300];
int maxI,maxJ;
int F,C,starti,endi;

//          0  1  2  3 4  5 6 7  8 9
int sx[] = {0,-1,-1,-1, 0,0,0, 1,1,1};
int sy[] = {0,-1, 0,1 ,-1,0,1,-1,0,1};
char simbolo[] = {' ','\\','|','/','-',' ','-','/','|','\\'};

void printPhone() {
    for(int i=0; i < maxI; i++) {
        for (int j = 0; j < maxJ; j++)
            printf("%c", phone[i][j]);
        printf("\n");
    }
    //printf("NEXT\n");
}

void generatePhone(){
    maxI = F*2+1;
    maxJ = C*2+1;
    for(int i=0; i<maxJ;i++) phone[0][i] = '-';
    for(int i=0; i<maxJ;i++) phone[maxI-1][i] = '-';
    for(int i=0; i<maxI;i++) phone[i][0] = '|';
    for(int i=0; i<maxI;i++) phone[i][maxJ-1] = '|';
    phone[0][0] = phone[maxI-1][maxJ-1] = phone[0][maxJ-1] = phone[maxI-1][0] = '+';
    for(int i=1; i<maxI;i+=2)
        for(int j=1;j<maxJ;j+=2)
            phone[i][j]='.';
}

pair<int,int> addMove(int num, int curi, int curj){
    int newcuri = curi + sx[num];
    int newcurj = curj + sy[num];
    char sim = simbolo[num];
    int posx = newcuri*2-1-sx[num];
    int posy = newcurj*2-1-sy[num];
    if((phone[posx][posy]=='\\' && sim == '/') || (phone[posx][posy]=='/' && sim == '\\'))
        phone[posx][posy]='X';
    else if(phone[posx][posy]!='X')
        phone[posx][posy]=sim;
    phone[newcuri*2-1][newcurj*2-1]='O';
    //printPhone();
    return {newcuri,newcurj};
}

int main(){
   //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\newin2.txt","r",stdin);
   while(scanf("%d %d",&F,&C)==2 && (F!=0||C!=0)) {
       memset(phone,' ',sizeof(phone));
       scanf("%d %d", &starti, &endi);
       generatePhone();
       //printPhone();
       string line; cin>>line;
       phone[starti*2-1][endi*2-1]='O';
       for(int i=0; i<line.length(); i++){
           int num = line[i]-'0';
           if(num==5) continue;
           pair<int,int> res =  addMove(num,starti,endi);
           starti = res.first; endi = res.second;
       }
       printPhone();
   }
   return 0;
}
