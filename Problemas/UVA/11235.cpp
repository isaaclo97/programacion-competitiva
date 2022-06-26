#include <bits/stdc++.h>
using namespace std;

struct node {
   pair<long long int, long long int> l; //elemento y frecuencia
   pair<long long int, long long int> r;
   long long int f;
};
node join(node left,node right)
{
    node res; res.l=left.l; res.r=right.r;
    if (left.l.first==right.l.first) res.l.second+=right.l.second; //Si ambos tienen el mismo por la izquierda sumar
    if (left.r.first==right.r.first) res.r.second+=left.r.second; //Si ambos tienen el mismo por la derecha sumar
    res.f=max(max(left.r.second,right.l.second),max(left.f,right.f)); //Calcular la frecuencia
    if (left.r.first==right.l.first)res.f=max(res.f,left.r.second+right.l.second); //Si encima derecha e izquierda son iguales
    return res;
}
void buildTree(node *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e)
        return;
    //reached leaf node
    if(s==e)
    {
        tree[index].l={a[s],1}; tree[index].r={a[s],1}; tree[index].f=1;
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
    if(qs>e || s>qe)
        return node{{0,0},{0,0},0};
    //complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    node left = query(tree,2*index,s,m,qs,qe);
    node right = query(tree,2*index+1,m+1,e,qs,qe);
    return join(left,right);
}
int main()
{
    int n,c;
    while(scanf("%d",&n)==1 && n!=0)
    {
        scanf("%d",&c);
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        node*tree = new node[4*n+1];                                    //array to store the segment tree
        int index = 1;												  //index of 1st node
        int s =0,e=n-1;
        buildTree(tree,a,index,s,e);								  //now tree has been built
        for(int i=0; i<c;i++)
        {
        int j,k; scanf("%d %d",&j,&k);
        printf("%lld\n",query(tree,index,s,e,j-1,k-1).f);
        }
    }
    return 0;
}
