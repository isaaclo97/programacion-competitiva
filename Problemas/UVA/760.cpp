#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                              // and current suffix T+SA[i]
bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }      // compare

void countingSort(int k) {                                          // O(n)
  int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c);                          // clear frequency table
  for (i = 0; i < n; i++)       // count the frequency of each integer rank
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)                     // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
  for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
  for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
    countingSort(k);  // actually radix sort: sort based on the second item
    countingSort(0);          // then (stable) sort based on the first item
    tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
    for (i = 1; i < n; i++)                    // compare adjacent suffixes
      tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)                     // update the rank array RA
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
} }

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;                                         // default value
  for (i = 1; i < n; i++)                            // compute Phi in O(n)
    Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
    while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0);                             // L decreased max n times
  }
  for (i = 0; i < n; i++)                            // compute LCP in O(n)
    LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

vector<ii> LCS() {                 // returns a pair (the LCS length and its index)
  vector<ii> V;
  int  maxLCP = 0;
  for (int i = 1; i < n; i++)                         // O(n), start from i = 1
    if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP) {V.clear(); V.push_back(ii(LCP[i],i)); maxLCP = LCP[i]; }
    else if(owner(SA[i]) != owner(SA[i-1]) && LCP[i] == maxLCP && LCP[i]!=0) V.push_back(ii(LCP[i],i));
  return V;
}
int main() {
  int flag=1;
  while(scanf("%s\n%s",T,P)==2)
  {
      if(flag==0) printf("\n");
      n = (int)strlen(T);
      T[n++] = '$';
      m = (int)strlen(P);
      strcat(T, P);                                                 // append P
      strcat(T, "#");                                    // add '$' at the back
      n = (int)strlen(T);                                           // update n
      constructSA();                                              // O(n log n)
      computeLCP();                                                     // O(n)
      vector<ii> ans = LCS();         // find the longest common substring between T and P
      string auxi = "";
      for(unsigned int i=0; i<ans.size();i++)
      {
          string au = T+SA[ans[i].second];
          au = au.substr(0,ans[i].first);
          if(auxi==au) continue;
          auxi = au;
          printf("%s\n", au.c_str());
      }
      if(ans.size()==0) printf("No common sequence.\n");
      flag=0;
      memset(T, '\0', sizeof(T));
      memset(P, '\0', sizeof(P));
  }
  return 0;
}
