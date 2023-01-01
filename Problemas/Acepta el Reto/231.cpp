#include <bits/stdc++.h>
using namespace std;

struct n {
    char d;
    n *l;
    n *r;
};

int top = -1;
n *a[20005];

void push(n *tree) {
    top++;
    a[top] = tree;
}
n *pop() {
    top--;
    return a[top + 1];
}
void construct_expression_tree(string s) {
    n *newl, *p1, *p2;
    for (int i = 0; i<s.length(); i++) {
        if (! (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]== '/' || s[i]== '%')) {
            newl = new n;
            newl->d = s[i];
            newl->l = NULL;
            newl->r = NULL;
            push(newl);
        } else {
            p1 = pop();
            p2 = pop();
            newl = new n;
            newl->d = s[i];
            newl->l = p2;
            newl->r = p1;
            push(newl);
        }
    }
}

vector<char> levelOrder(n *tree){
    vector<char> levels;
     if (tree != NULL) {
            queue<n*> pendientes;
            pendientes.push(tree);
            while (!pendientes.empty()) {
                n *sig = pendientes.front();
                pendientes.pop();
                levels.push_back(sig->d);
                if (sig->l != NULL)
                    pendientes.push(sig->l);
                if (sig->r != NULL)
                    pendientes.push(sig->r);
            }
    }
    return levels;
}

void inOrder(n *tree) {
    if (tree != NULL) {
        inOrder(tree->l);
        inOrder(tree->r);
        delete tree;
    }
}

int main() {
    string pf;
    while(getline(cin,pf)) {
        top = -1;
        construct_expression_tree(pf);
        vector<char> sol = levelOrder(a[0]);
        for (int i = sol.size() -1; i >= 0; i--){
            cout << sol[i];
        }
        printf("\n");
        inOrder(a[0]);
    }
    return 0;
}