#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int put = 11; //alphabet size
struct TrieNode
{
    struct TrieNode *children[put];
    bool isEndOfWord = false;
    int num = 0;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->num=0;
    pNode->isEndOfWord=false;
    for (int i = 0; i < put; i++)  pNode->children[i] = NULL;
    return pNode;
}
int insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl->num++; //add to get repetitions
        if(pCrawl->isEndOfWord) return true;
        pCrawl = pCrawl->children[index];
    }
    pCrawl->num++;
    pCrawl->isEndOfWord = true;
    return  pCrawl->num!=1;
}


int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        struct TrieNode *root = getNode();
        int phones; scanf("%d",&phones); cin.ignore();
        bool flag=true;
        for(int i=0; i<phones;i++)
        {
            string num;
            getline(cin,num);
            if(flag && insert(root,num)) flag=false;
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
