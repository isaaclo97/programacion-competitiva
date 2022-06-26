#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int n,m;
char matrix[201][201];
int sx[]={1,-1,0,0,1,-1,-1,1};
int sy[]={0,0,1,-1,1,-1,1,-1};
const int put = 2;
struct TrieNode
{
    struct TrieNode *children[put];
    bool isEndOfWord;
    int num;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    pNode->num=0;
    for (int i = 0; i < put; i++)  pNode->children[i] = NULL;
    return pNode;
}
struct TrieNode *auxNode;
struct TrieNode *auxNode1;
struct TrieNode *auxNode2;
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int search(char key,int a)
{
   int index = key - '0';
   if (!auxNode->children[index]) return -1;
   auxNode = auxNode->children[index];
   if(auxNode->isEndOfWord) auxNode->num++;
   if (a==1) auxNode2=auxNode;
   return 0;
}
int searchN(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->num;
}

void getWord(int x,int y, int i)
{
    if(x < n && y <m && x >= 0 && y >= 0) {
                if(search(matrix[x][y],0)==-1) return;
                getWord(x+sx[i], y+sy[i],i);
            }
}

void addWords(int i,int j)
{
    auxNode = auxNode1;
    if(search(matrix[i][j],1)==-1) return;
    for(int k=0; k<8;k++)
    {
        auxNode = auxNode2;
        getWord(i+sx[k],j+sy[k],k);
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)==2)
    {
    map<string,int> M;
    for(int i=0; i<n;i++)
        for(int j=0; j<m;j++) cin>>matrix[i][j];
    struct TrieNode *root = getNode();
    auxNode1 = root;
    int t; cin>>t;
    while(t--)
    {
     string check;
     cin>>check;
     M[check]=0;
    insert(root, check);
    }
    for(int i=0; i<n;i++)
        for(int j=0; j<m;j++) addWords(i,j);

    for(auto m:M)
    {
        int aux = searchN(root,m.first);
        if(aux!=0) cout<<m.first<<" "<<aux<<'\n';
    }
    cout<<"---\n";
    }
    return 0;
}
