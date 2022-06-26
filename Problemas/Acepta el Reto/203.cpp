#include <bits/stdc++.h>
using namespace std;

template <class T>
class bintree {
protected:
    struct TreeNode;
    using Link = shared_ptr<TreeNode>;

    struct TreeNode {
        TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
        T elem;
        Link left, right;
    };
    bintree(Link const& r) : raiz(r) {}
    Link raiz;

    private:
    void mostrar(Link const& raiz){
        if (raiz != this->raiz) printf(" ");
        if (raiz != nullptr){
            cout << raiz->elem;
            mostrar(raiz->left);
            mostrar(raiz->right);
        }
        else printf("-1");
    }
    void sumaleArbol(Link & raiz1, Link const & raiz2){
        if (raiz1 != nullptr && raiz2 != nullptr) {
            raiz1->elem += raiz2->elem;
            sumaleArbol(raiz1->left, raiz2->left);
            sumaleArbol(raiz1->right, raiz2->right);
        }
        else if (raiz1 == nullptr && raiz2 != nullptr) {
            raiz1 = raiz2;
        }

    }

public:
    void muestraArbol(){
        mostrar(raiz);
    }
    void sumaSobreArbol(bintree<T> const& arbol2){
        sumaleArbol(this->raiz, arbol2.raiz);
    }
    bintree() : raiz(nullptr) {}
    bintree(T const& e) :
        raiz(make_shared<TreeNode>(nullptr, e, nullptr)) {}
    bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
        raiz(make_shared<TreeNode>(l.raiz, e, r.raiz)) {}
    bool empty() const {
        return raiz == nullptr;
    }
};

template <typename T>
inline bintree<T> leerArbol(T vacio) {
    T raiz;
    cin >> raiz;
    if (raiz == vacio) {
        return{};
    }
    else {
        auto iz = leerArbol(vacio);
        auto dr = leerArbol(vacio);
        return{ iz, raiz, dr };
    }
}
bool resuelveCaso() {
    bintree <int> arbol1, arbol2;
    arbol1 = leerArbol(-1);
    arbol2 = leerArbol(-1);
    if (arbol1.empty() && arbol2.empty()) return false;
    arbol1.sumaSobreArbol(arbol2);
    arbol1.muestraArbol();
    printf("\n");
    return true;
}
int main() {
    while (resuelveCaso());
    return 0;
}
