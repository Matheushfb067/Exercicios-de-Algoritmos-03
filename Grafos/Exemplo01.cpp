#define MAXV 1000 // constante de definição de maximo de vertices
#include <list>
#include <iostream>
using namespace std;

struct Aresta
{
    int destino, peso;
};

int main()
{
    // o que temos que definir antes de construir um grafo é se ele é ponderado ou não, e se são direcionados ou não
    // bool matriz_adj[MAXV][MAXV]; // não ponderada - booleano
    // Transformando o matriz_ajs em int, transformamos a matriz em ponderada e adicionamos a variavel de peso.
    int matriz_adj[MAXV][MAXV];
    int vertices, arestas, origem, destino, peso;

    cin >> vertices >> arestas;

    // Incializando a matriz com falso em todas as posições! - boa pratica
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matriz_adj[i][j] = -1;
        }
    }

    for (int i = 0; i < arestas; i++)
    {
        cin >> origem >> destino >> peso;
        // Exibindo matriz a partir do indice 1.
        origem--;
        destino--;
        // matriz espelhada montada!
        matriz_adj[origem][destino] = peso;
        // matriz_adj[destino][origem] = true; - comentando isso transformamos a matriz em direcionada
    }

    // Exibindo a matriz
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matriz_adj[i][j] << " ";
        }
        cout << endl;
    }

    /*-----------------------------------------------------------------------------*/

    // lista de adjacencia:
    list<Aresta> listas_adj[MAXV];
    // não é necessaria inicialização!
    cin >> vertices >> arestas;

    for (int i = 0; i < arestas; i++)
    {
        cin >> origem >> destino >> peso;
        listas_adj[origem].push_back({destino, peso}); // adição a lista metodo push_back
        // listas_adj[destino].push_back(origem); // adição a lista metodo push_back
    }

    // Como não é uma matriz, eu não posso ir do 0 até o vertice

    list<Aresta>::iterator it; // com ele podemos apontar para o inicio da lista ate o final dela!
    for (int i = 0; i < vertices; i++)
    {
        cout << i << ": ";
        for (it = listas_adj[i].begin(); it != listas_adj[i].end(); it++)
        {
            cout << "(" << it->destino << ", " << it->peso << ") ";
        }
        cout << endl;
    }

    return 0;
}