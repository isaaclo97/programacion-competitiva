#include <bits/stdc++.h>

using namespace std;

int main() {
    string sol[3][3][6] = {
        {
            {"o", "as", "a", "amos", "ais", "an"},
            {"e", "aste", "o", "amos", "asteis", "aron"},
            {"are", "aras", "ara", "aremos", "areis", "aran"},
        },
        {
            {"o", "es", "e", "emos", "eis", "en"},
            {"i", "iste", "io", "imos", "isteis", "ieron"},
            {"ere", "eras", "era", "eremos", "ereis", "eran"},
        },
        {
            {"o", "es", "e", "imos", "is", "en"},
            {"i", "iste", "io", "imos", "isteis", "ieron"},
            {"ire", "iras", "ira", "iremos", "ireis", "iran"}
        }
    };

    string p[6] = {"yo", "tu", "el", "nosotros", "vosotros", "ellos"};
    string s, t;
    while (cin >> s >> t && t != "T") {
        int r,j;
        if (s[s.length()-2] == 'a')  r = 0;
        else if (s[s.length()-2] == 'e') r = 1;
        else if (s[s.length()-2] == 'i')  r = 2;
        if (t == "A") j = 0;
        else if (t == "P") j = 1;
        else if (t == "F") j = 2;
        for (int i = 0; i < 6; i++)
            printf("%s %s%s\n", p[i].c_str(), s.substr(0, s.length()-2).c_str(), sol[r][j][i].c_str());
    }

    return 0;
}
