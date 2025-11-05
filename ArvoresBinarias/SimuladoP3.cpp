//Simulado P3
/*
Soebad Saliv é um cozinheiro renomado e excêntrico. Ele costuma usar espécies exóticas 
de peixes, pescados na represa de Anatricé em seus preparos. 

Atualmente, o prato que tem feito muito sucesso e garantiu vários prêmios para Soebad é 
sua torta de jaca e peixe. Com isso, inúmeros turistas passam em seu restaurante e fazem 
pedidos online das suas tortas. 

Ele desenvolveu um sistema de precificação para facilitar a venda das tortas.

Sua missão é ajudá-lo a completar esse sistema!

Faça um programa que leia inicialmente a quantidade de tortas T a serem cadastradas 
no sistema.

Depois, o programa deve ler as características de cada torta T[i] (0 <= i < T), que 
são números reais representando a espessura da massa (EM), o peso (P), o diâmetro (D) 
e a altura (A) da torta. O preço final PF da torta é calculado de acordo com a formula: 
PF = (EM*P*A+D+A). Insira o código i e o preço final PF de cada torta T[i] em uma árvore 
binária de busca e faça uma listagem em ordem crescente do preço.

Não esqueça de liberar a memória no final do programa!

Entrada:
A primeira linha da entrada é a quantidade de tortas T.
Em seguida serão informadas T linhas com 4 números reais indicando:

- espessura da massa (EM) da torta T[i];

- peso (P) da torta T[i];

- altura (A) da torta T[i];

- e diâmetro (D) da torta T[i];

onde 0 <= i < T.

Saída:
Na saída, o programa deve mostrar número i e o preço PF de cada torta (no formato i:PF) em ordem crescente de preço.

Exemplo de entrada:   |	Exemplo de saída:
------------------------------------------
4                     | 3:97
5.1 2.8 8.1 29.8      | 0:153
4.85 3.1 7.9 31.1     | 2:154
4.98 2.89 8 30.9      | 1:157
3.8 2.1 7.95 26.5     |
------------------------------------------
3                     | 0:96
5 3.2 4 28            | 1:119
9 3.4 3 25            | 2:125
6 3.3 5 21            |
*/

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

struct treenode{
  int preco;
  int indice;
  struct treenode * left;
  struct treenode * right;
};

void tInsert(treenode* &p, int preco, int indice){
    if(p == NULL){
        p = new treenode;
        p -> preco = preco;
        p -> indice = indice;
        p -> left = NULL;
        p -> right = NULL;
    }else if(preco < p -> preco){
        tInsert(p -> left, preco, indice);
    }else{ 
        tInsert(p -> right, preco, indice);
    }
}

//Percurso em profundidade EM-ORDEM
void tInOrder(treenode* p){
    if(p != NULL){
        tInOrder(p -> left);
        cout << p -> indice << ":" << p -> preco << endl;
        tInOrder(p -> right);
    }
    
}

//Libera toda a memória alocada para a árvore
void tFree(treenode* p){
    if(p != NULL){
        tFree(p->left);      // Libera toda subárvore esquerda
        tFree(p->right);     // Libera toda subárvore direita
        delete p;            // Libera o nó atual
    }
}

int main (){

    treenode* arvore = NULL;
    int T; //quantidade de tortas

    cin >> T;

    for(int i = 0; i < T; i++){
        double EM, P, A, D;
        cin >> EM >> P >> A >> D;

        double PF = (EM * P * A + D + A);

        tInsert(arvore, PF, i);
    }

    // Imprime em ordem crescente de preço
    tInOrder(arvore);
    
    // Libera memória
    tFree(arvore);

    return 0;
}