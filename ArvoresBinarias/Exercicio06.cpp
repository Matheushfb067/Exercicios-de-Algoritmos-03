//Remover nós
/*
Faça um programa que leia vários números inteiros e os insira em uma árvore binária.

Depois o programa deve ler um inteiro x e remover todos os nós cujo campo info seja 
igual a x, e mostrar os elementos restantes, em ordem crescente.

Entrada:

A entrada consiste de duas linhas:
- a primeira linha tem vários números inteiros, que devem ser ineridos na árvore. 
Esta linha termina com o número 0, que não deve ser inserido na árvore

- a segunda linha tem o valor de x

Saída:
Após remover os nós cujo campo info é igual a x, o programa deve mostrar os nós restantes, 
em ordem crescente, como no exemplo abaixo.

Exemplo de entrada:   | Exemplo de saída:
-----------------------------------------
10 7 4 2 4 5 0        | 2 5 7 10
4                     |   
*/

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

struct treenode{
  int info;
  struct treenode * left;
  struct treenode * right;
};

void tInsert(treenode* &p, int x){
    if(p == NULL){
        p = new treenode;
        p -> info = x;
        p -> left = NULL;
        p -> right = NULL;
    }else if(x < p -> info){
        tInsert(p -> left, x);
    }else{ 
        tInsert(p -> right, x);
    }
}

treenode* tSearch(treenode* p, int x){
    if(p == NULL){
        return NULL;
    }else if(x == p -> info){
        return p;
    }else{
        if(x < p-> info)
            return tSearch(p -> left, x);
        else
            return tSearch(p -> right, x);
    }
}

//Algoritimo de Remoção
treenode* tPointSmaller(treenode* &p){
    treenode* t = p;
    if(p -> left == NULL){
        p = p -> right;
        return t;
    }else
        return tPointSmaller(p -> left);
}

bool tRemove(treenode* &p, int x){
    treenode* t;
    if(p == NULL) return false;
    if(x == p -> info){
        t = p;
        if(p -> left == NULL)
            p = p -> right;
        else if(p -> right == NULL)
            p = p -> left;
        else{
            t = tPointSmaller(p -> right);
            p -> info = t -> info;
        }
        delete t;
        return true;
    }else if(x < p -> info)
        return tRemove(p -> left, x);
    else
        return tRemove(p -> right, x);
}

//Percurso em profundidade EM-ORDEM
void tInOrder(treenode* p){
    if(p != NULL){
        tInOrder(p -> left);
        cout << p -> info << " ";
        tInOrder(p -> right);
    }
    
}

int main (){
    
    treenode* arvore = NULL;
    int n, x;
    
    cin >> n;
    while(n != 0){
        tInsert(arvore, n);
        cin >> n;
    }
    
    // leitura de x
    cin >> x;
    
    /* 
    Remove todos os nós iguais a x:
    - retorna true se conseguiu remover um nó com valor x;
    - retorna false quando não existe mais nenhum nó com valor x.
    Função vazia intensionalmente!
    Então, o while apenas repete a remoção até que tRemove() retorne false.
    Força remoções sucessivas
    Continua removendo enquanto existir o valor x
    */
   
    while(tRemove(arvore, x)){}
    
    
    /*A função não precisa estar dentro do cout, uma vez que já está printando
    nela propria*/
    tInOrder(arvore);
    cout << endl;
    
    
    return 0;
}