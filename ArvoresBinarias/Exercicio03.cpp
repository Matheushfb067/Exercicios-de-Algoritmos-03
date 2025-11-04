//Plataforma de Streaming
/*
Contexto:
Você está trabalhando em uma nova rede de streaming, e para organizar os filmes na plataforma, 
decidiu utilizar uma árvore binária de busca ordenada pelos nomes dos filmes. Faça um programa 
que insira o nome, gênero, duração em minutos, classificação de idade e ano de cada filme na 
árvore, e que, dado o nome de um determinado filme, faça uma pesquisa e mostre as informações 
do mesmo.

Entradas:
A entrada terá 3 opções: 1 para inserir um filme, 2 para pesquisar um filme por nome e 0 para 
sair do programa. Ao escolher a opção 1, o usuário deve entrar com o nome, gênero, duração, 
classificação e ano do filme. Para a opção 2, entrar apenas com o nome do filme que deseja 
pesquisar.

Saída:
Quando um filme for pesquisado, se ele estiver na árvore, mostre todas as suas informações, 
se não, mostre a mensagem "Filme nao encontrado". Adicionalmente, se um usuário entrar com uma 
opção que não seja uma das três anteriores, mostre a mensagem "Operação inválida".


Exemplo de entrada:             | Exemplo de saída:
---------------------------------------------------------------------------
1                               | 
Hereditario                     | Nome: Aniquilacao          
Terror                          | Gênero: Terror             
127                             | Duração: 115 minutos       
16                              | Classificação: 14 anos     
2018                            | Ano: 2018                 
1                               | Operacao invalida
Aniquilacao                     | Filme nao encontrado
Terror                          | Nome: Ex_machina - Instinto Artificial
115                             | Gênero: Sci-fi
14                              | Duração: 108 minutos
2018                            | Classificação: 14 anos
1                               | Ano: 2018
Maze Runner - Correr ou Morrer  |
Acao                            |
114                             |
14                              |
2014                            |
1                               |
O Preco do Amanha               |
Sci-fi                          |
109                             |
12                              |
2011                            |
1                               |
Ex_machina - Instinto Artificial|
Sci-fi                          |
108                             |
14                              |
2015                            |
2                               |
Aniquilacao                     |
4                               |
2                               |
Forrest Gump                    |
2                               |
Ex_machina - Instinto Artificial|
0                               |

*/

#define MAXF 100 //maximo de filmes
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

int main (){
    
    string nome[MAXF], genero[MAXF];
    int duracao[MAXF], classificacao[MAXF], ano[MAXF];
    int total = 0; //numero de filmes
    int id = 0;
    
    treenode* arvore = NULL; //arvore vazia
    int op;
    
    cin >> op;
    cin.ignore();
    
    while(op != 0){
        
        switch(op){
            case 1: 
                //Inserindo Filmes
                getline(cin, nome[total]);
                getline(cin, genero[total]);
                cin >> duracao[total] >> classificacao[total] >> ano[total];
                cin.ignore();
                
                id = total + 1; // proximo filme.
                tInsert(arvore, id);
                total++; //pela pro proximo indice do vetor!
                
                break;
                
            case 2: {
                //busca:
                string nomeBusca;
                getline(cin, nomeBusca);
                
                int idEncontrado = -1;
                //Procurar o ID correspondente ao nome digitado
                for(int i = 0; i < total; i++){
                    if(nome[i] == nomeBusca){
                        idEncontrado = i;
                        break;
                    }
                }
                
                if (idEncontrado != -1 && tSearch(arvore, idEncontrado + 1) != NULL) {
                    int i = idEncontrado; // índice real do vetor
                    cout << "Nome: " << nome[i] << endl;
                    cout << "Genero: " << genero[i] << endl;
                    cout << "Duracao: " << duracao[i] << " mins" << endl;
                    cout << "Classificacao: " << classificacao[i] << endl;
                    cout << "Ano: " << ano[i] << endl;
                } else {
                    cout << "Filme nao encontrado" << endl;
                }
                
                break;
                
            }
            default:
                cout << "Operacao invalida" << endl;
                break;
        }
        
        cin >> op;
        cin.ignore();
    
    }
    
    return 0;
}