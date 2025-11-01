//Biblioteca de Alexandria:
/*
Contexto

Imagine que você é um bibliotecário na renomada Biblioteca de Alexandria. Sua tarefa é organizar uma vasta 
coleção de manuscritos usando uma técnica antiga, mas incrivelmente eficaz, conhecida como Árvore Binária de 
Busca (BST). Cada manuscrito é representado por um número único e deve ser facilmente acessível. Seu desafio é 
desenvolver um sistema para inserir números de manuscritos na BST de modo que possam ser recuperados rapidamente 
quando pesquisados. A eficiência do seu sistema será testada através de uma série de inserções e buscas, refletindo o 
trabalho diário de catalogar e localizar manuscritos na biblioteca.

Entradas:

    Número de Operações (N): O primeiro número inteiro na entrada (1 ≤ N ≤ 100) indica quantas operações serão realizadas.
    Operações: Cada uma das próximas N linhas descreve uma operação e pode ser de dois tipos:
        i x: Insere o inteiro x, representando o número de um manuscrito, na árvore binária (onde -10^9 ≤ x ≤ 10^9).
        b x: Busca o inteiro x, o número do manuscrito, na árvore binária e retorna se o manuscrito está catalogado ou não.

Saída:
    Para cada operação de busca (b x), imprima "Sim" se o manuscrito está catalogado na árvore e "Não" se não está.

Exemplo de entrada:     |   Exemplo de saída:   
-----------------------------------------------
5                       |   Sim
i 1023                  |   Não
i 581                   |
i 2048                  |
b 581                   |  
b 9999                  | 
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

int main () {
    
    int n;
    treenode* arvore = NULL; //arvore vazia
    
    do{
        cin >> n;
    }while(n < 1 || n > 100);
    
    for(int i = 0; i < n; i++){
        char op;
        int x; 
        
        cin >> op >> x;
        
        if(op == 'i'){
            tInsert(arvore, x);
        }else if(op == 'b'){
            if(tSearch(arvore, x) != NULL)
                cout << "Sim" << endl;
            else
                cout << "Não" << endl;
        }
    }
    
    return 0;
}