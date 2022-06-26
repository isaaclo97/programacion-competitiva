#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F

struct node {
   long long int pa;
   long long int pc;
};
node join(node left,node right)
{
    node res;
    int n = min(left.pa, right.pc);
    res.pa = right.pa + left.pa - n;
    res.pc = left.pc + right.pc - n;
    return res;
}
void buildTree(node *tree,string a,int index,int s,int e)
{
    //base case
    if(s>e) return;
    //reached leaf node
    if(s==e)
    {
        if(a[s]==')') { tree[index].pc=1; tree[index].pa=0;}
        else { tree[index].pa=1;tree[index].pc=0; }
        return ;
    }
    //now build the segment tree in bottom up manner
    int m = (s+e)/2;
    buildTree(tree,a,2*index,s,m);
    buildTree(tree,a,2*index+1,m+1,e);
    node left = tree[2*index]; node right = tree[2*index+1];
    tree[index]=join(left,right);
    return;
}

//function to query the segment tree for RSQ
node query(node *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe) return node{INF,INF};
    //complete overlap
    if(s>=qs && e<=qe) return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    node left = query(tree,2*index,s,m,qs,qe);
    node right = query(tree,2*index+1,m+1,e,qs,qe);
    return join(left,right);
}

void updateNode(node *tree,int index,int s,int e,int pos)
{
    if(pos<s || pos>e) return ;
    if(s==e)
    {
        if(tree[index].pc==1) { tree[index].pc=0; tree[index].pa=1; }
        else { tree[index].pc=1; tree[index].pa=0; }
        return;
    }
    int m = (s+e)/2;
    updateNode(tree,2*index,s,m,pos);
    updateNode(tree,2*index+1,m+1,e,pos);
    tree[index] = join(tree[2*index],tree[2*index+1]);
    return;
}
int main()
{
    int n,c,ca=1;
    while(scanf("%d",&n)==1)
    {
        string a;
        cin.ignore();
        getline(cin,a);
        node*tree = new node[4*n+1];                                    //array to store the segment tree
        int index = 1;												  //index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);								  //now tree has been built
        scanf("%d",&c);
        printf("Test %d:\n",ca++);
        for(int i=0; i<c;i++)
        {
            int f; scanf("%d",&f);
            if(f==0)
            {
                node aux = query(tree,index,s,e,0,n);
                if(aux.pa==0 && aux.pc==0) printf("YES\n");
                else printf("NO\n");
            }
            else updateNode(tree,index,s,e,f-1);
        }
    }
    return 0;
}
