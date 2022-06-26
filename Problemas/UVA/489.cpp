#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
 int round;
  while (scanf("%d", &round) != EOF && round != -1) {
    int ch, letter[26] = {0}, tmp = 7, win = 1;
    while (getchar() != '\n') continue;
    while ((ch = getchar()) != '\n') letter[ch - 'a'] = 1;
    while ((ch = getchar()) != '\n' && tmp) {
      if (!letter[ch - 'a']) --tmp;
      letter[ch - 'a'] = 2;
    }
    if (ch != '\n') while (getchar() != '\n') continue;
    for (int i = 0; i < 26 && win; ++i) if (letter[i] == 1) win = 0;
    printf("Round %d\nYou ", round);
    if (tmp && !win) puts("chickened out.");
    else if (win) puts("win.");
    else puts("lose.");
  }
    return 0;
}
