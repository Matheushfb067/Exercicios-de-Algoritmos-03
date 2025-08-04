// Loja de Itens
/*
Poles está organizando os itens disponíveis para venda em sua loja online. Ele quer criar um
sistema de compra e venda de itens.
Para isso ele tem uma lista com diversos itens e suas informações (código, nome e preço). Ele
precisa cadastrar essa lista em uma tabela hash de tamanho M = 43 para facilitar as buscas. A
função hash usada para a inserção deve ser pelo método do módulo, considerando o código do
item e o valor M, com tratamento de colisão por sondagem linear.
Em seguida ele quer que, dada uma lista de itens sejam inseridos em uma fila de de vendas e uma
lista de itens sejam inseridos em uma pilha de compras.
Por fim, ele vai entrar com dois números inteiros V e C, indicando respectivamente a quantidade
de vendas e compras ele quer realizar. As vendas e compras devem ser processadas das
respectivas listas. Ele quer saber o lucro total das operações. Sabe-se que o lucro L é o valor total
VT das vendas realizadas subtraído do valor total VC das compras realizadas ( L = VT - VC ).
Entrada
A entrada é divida em quatro partes. Na primeira parte é informado um número inteiro N (0 < N
<= 43) que é a quantidade de itens e em seguida são entradas N linhas, cada uma contendo as
informações de cada item i, sendo elas um número inteiro indicando o código do item, uma cadeia
de caracteres (sem espaço) indicando o nome do item e um número inteiro indicando o preço do
item. Na segunda parte serão informados vários números inteiros vi, indicando os códigos dos
itens a serem vendidos (a entrada termina com vi = -1). Esses itens devem ser inseridos em uma
fila. Na terceira parte serão informados vários números inteiros ci, indicando os códigos dos itens
a serem comprados (a entrada termina com ci = -1). Esses itens devem ser inseridos em uma pilha.
Na última parte, são informado dois números inteiros V e C indicando respectivamente a
quantidade de itens a serem processados da fila dos vendidos e a quantidade de itens a serem
processados da pilha dos comprados.
Saída
Deve exibir um número inteiro com o lucro total obtido seguido dos caracteres " moeda(s).".

Exemplo de Entrada:                Exemplo de Saída:
4                                  20 moeda(s).
3477 arco 20
5455 escudo 15
2125 espada 12
3474 flecha 10
3477 5455 -1
2125 3474 -1
1 0
---------------------------------//---------------------------------
4                                  25 moeda(s).
3477 arco 20
5455 escudo 15
2125 espada 12
3474 flecha 10
3477 5455 -1
2125 3474 -1
2 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Item
{
    int codigo;
    string nome;
    int preco;
};

class TabelaHash
{
private:
    static const int M = 43;
    Item *tabela[M];
    bool ocupado[M];

public:
    TabelaHash()
    {
        for (int i = 0; i < M; i++)
        {
            tabela[i] = nullptr;
            ocupado[i] = false;
        }
    }

    ~TabelaHash()
    {
        for (int i = 0; i < M; i++)
        {
            if (tabela[i] != nullptr)
            {
                delete tabela[i];
            }
        }
    }

    int hash(int codigo)
    {
        return codigo % M;
    }

    void inserir(Item item)
    {
        int pos = hash(item.codigo);
        int originalPos = pos;

        while (ocupado[pos])
        {
            pos = (pos + 1) % M;
            if (pos == originalPos)
            {
                return; // Tabela cheia
            }
        }

        tabela[pos] = new Item{item.codigo, item.nome, item.preco};
        ocupado[pos] = true;
    }

    Item *buscar(int codigo)
    {
        int pos = hash(codigo);
        int originalPos = pos;

        while (ocupado[pos])
        {
            if (tabela[pos]->codigo == codigo)
            {
                return tabela[pos];
            }
            pos = (pos + 1) % M;
            if (pos == originalPos)
            {
                break;
            }
        }

        return nullptr;
    }
};

int main()
{
    TabelaHash hashTable;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Item item;
        cin >> item.codigo >> item.nome >> item.preco;
        hashTable.inserir(item);
    }

    queue<Item *> filaVendas;
    stack<Item *> pilhaCompras;

    // Leitura dos itens para venda
    int vi;
    while (cin >> vi, vi != -1)
    {
        Item *item = hashTable.buscar(vi);
        if (item != nullptr)
        {
            filaVendas.push(item);
        }
    }

    // Leitura dos itens para compra
    int ci;
    while (cin >> ci, ci != -1)
    {
        Item *item = hashTable.buscar(ci);
        if (item != nullptr)
        {
            pilhaCompras.push(item);
        }
    }

    int V, C;
    cin >> V >> C;

    int totalVendas = 0;
    int totalCompras = 0;

    // Processar vendas
    for (int i = 0; i < V && !filaVendas.empty(); i++)
    {
        Item *item = filaVendas.front();
        filaVendas.pop();
        totalVendas += item->preco;
    }

    // Processar compras
    for (int i = 0; i < C && !pilhaCompras.empty(); i++)
    {
        Item *item = pilhaCompras.top();
        pilhaCompras.pop();
        totalCompras += item->preco;
    }

    int lucro = totalVendas - totalCompras;
    cout << lucro << " moeda(s)." << endl;

    return 0;
}