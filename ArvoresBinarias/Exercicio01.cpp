//ARV - Pesquisa em árvores
/*
Faça um programa que leia N números inteiros e os insira em uma árvore binária.
Depois o programa deve ler um outro número X e verificar se o mesmo está ou não na árvore

Entrada:
A entrada consiste de três linhas:

    a primeira consiste de um único inteiro N, que corresponde à quantidade de números a serem inseridos na árvore.
    a segunda linha irá conter N números inteiros, que devem ser inseridos na árvore.
    a última linha contém um único inteiro X, que é o elemento a ser procurado

Saída:
Na saída, o programa deve mostrar a mensagem "Encontrado", se X estiver na árvore, ou a mensagem "Nao encontrado", 
caso contrário.

Exemplo de entrada:   |   Exemplo de saída:
8                     |   Encontrado
10 7 15 2 8 12 20 3   |
3                     |
----------------------------------------------
 8                    |   Nao Encontrado
10 7 15 2 8 12 20 3   |
1                     |
*/

#include <iostream>
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

int main (){
    int n, x;
    int aux = 0;
    
    treenode* arvore = NULL;
    
    cin >> n; 
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        
        if(aux != -1)
            tInsert(arvore, aux);
    }   
    
    
    //procurando o elemento
    cin >> x;
    
    if(tSearch(arvore, x) != NULL)
        cout << "Encontrado" << endl;    
    else
        cout << "Nao Encontrado" << endl;
        
    return 0;
}