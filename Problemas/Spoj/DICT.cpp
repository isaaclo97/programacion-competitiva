#include <bits/stdc++.h>
using namespace std;

const int put = 26; //alphabet size
struct TrieNode {
struct TrieNode *children[put];
bool isEndOfWord;
int num;
};
struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->num=0;
    for (int i = 0; i < put; i++) pNode->children[i] =NULL;
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
    pCrawl->isEndOfWord = true;
}

int search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (unsigned int i = 0; i < key.length(); i++)
        {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) return 0;
        pCrawl = pCrawl->children[index];
        }
return pCrawl->num;
}
char str[26000];
int sizel;
void display(struct TrieNode* root, char str[], int level)
{
    if (root->isEndOfWord && sizel!=level)  { str[level] = '\0'; cout << str << endl;}
    for (int i = 0; i < put; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}
void searchPrefix(struct TrieNode *root, string key) {
     struct TrieNode *pCrawl = root;
    for (unsigned int i = 0; i < key.length(); i++)
        {
        str[i]=key[i];
        int index = key[i] - 'a';
        pCrawl = pCrawl->children[index];
        }
   sizel=key.length();
   display(pCrawl,str,key.length());
   memset(str,'\0',sizeof(str));
}

int main(){
    int n,m,c=1;
    while(scanf("%d",&n)==1)
    {
    string word; struct TrieNode *root = getNode();
    for(int i=0; i<n;i++) {cin>>word; insert(root,word);}
    scanf("%d",&m);
    for(int i=0; i<m;i++) {
        cin>>word;
        int aux = search(root,word);
        printf("Case #%d:\n",c++);
        if(aux==0) printf("No match.\n");
        else searchPrefix(root,word);
    }
    }
    return 0;
}
