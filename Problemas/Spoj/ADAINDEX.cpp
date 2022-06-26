#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
const int put = 26;
struct TrieNode
{
    struct TrieNode *children[put];
    int num;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->num=0;
    for (int i = 0; i < put; i++)  pNode->children[i] = NULL;
    return pNode;
}
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl->num++;
        pCrawl = pCrawl->children[index];
    }
    pCrawl->num++;
}

int search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) return 0;
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->num;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
    string word;
    struct TrieNode *root = getNode();
    for(int i=0; i<n;i++) {cin>>word; insert(root,word);}
    for(int i=0; i<m;i++) {cin>>word; cout<<search(root,word)<<'\n';}
    }
    return 0;
}
