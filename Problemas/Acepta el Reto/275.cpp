#include <bits/stdc++.h>
using namespace std;

string a;
int pos,sol;

int findDepth() {
    pos++;
    if(a[pos]=='.') return 0;
    int leftDepth = findDepth();      // left subtree depth
    if(leftDepth==-1) return -1;
    int rightDepth = findDepth();    // right subtree depth
    if(rightDepth==-1) return -1;
    if(abs(leftDepth-rightDepth)>1) return -1;
    return max(leftDepth,rightDepth)+1;
}

int main()
{
    int cases;
    scanf("%d",&cases); cin.ignore();
    while(cases--)
    {
       getline(cin,a);
       pos=-1;
       sol=0;
       if(findDepth()!=-1) printf("SI\n");
       else printf("NO\n");
    }
    return 0;
}
