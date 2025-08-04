// Pilha e Hashing
/*
Considere a inserção de elementos em uma pilha e quando um elemento for removido ele deve ser
inserido em uma tabela hash de comprimento M usando endereçamento aberto. Mostre o resultado da
inserção dessas chaves utilizando hash duplo com h1(k) = k mod m e h2(k) = 1 + (k mod (m − 1)).
A entrada consiste em três linha onde a primeira é o valor de M, a segunda é a quantidade de elementos
que serão inseridos e a terceira são os elementos que devem ser armazenados.
A saída deve mostrar os elemetos depois de serem inserido na tabela hash.
obs.: Nas posições que não forem armazenado nenhum elemento deve mostrar -1.

Exemplo de Entrada:                Exemplo de Saída:
11                                 88 10 28 22 59 -1 17 -1 31 4 15
9
10 22 31 4 15 28 17 88 59
---------------------------------//---------------------------------
7                                  -1 43 23 -1 -1 12 6
4
12 23 6 43
*/

#include <iostream>
#include <list>
using namespace std;

int h1(int k, int m)
{
    int h;

    h = k % m;

    if (h < 0)
    {
        h += m;
    }

    return h;
}

int h2(int k, int m)
{
    int h;

    h = 1 + (k % (m - 1));

    if (h < 0)
        h = h + m;
    return h;
}

int dhash(int k, int m, int i)
{
    int h;

    h = (h1(k, m) + (i * h2(k, m))) % m;
    if (h < 0)
        h = h + m;

    return h;
}

int main()
{

    int m, qtd;
    double elementos[100];
    int vetor[100];
    list<int> pilha;

    cin >> m >> qtd;

    for (int i = 0; i < qtd; i++)
    {
        cin >> elementos[i];
        pilha.push_back(elementos[i]);
    }

    // Inicializa a tabela hash com -1
    for (int i = 0; i < m; i++)
    {
        vetor[i] = -1;
    }

    int elementos_restantes = qtd;

    while (elementos_restantes > 0)
    {
        int elemento = pilha.back(); // Pega o último elemento
        pilha.pop_back();            // Remove da pilha
        elementos_restantes--;       // Decrementa o contador

        int i = 0;
        int pos;
        do
        {
            pos = elemento % m; // h1(k)
            if (pos < 0)
                pos += m;

            int h2 = 1 + (elemento % (m - 1)); // h2(k)
            if (h2 < 0)
                h2 += (m - 1);

            pos = (pos + i * h2) % m; // dhash(k, i)
            if (pos < 0)
                pos += m;

            if (vetor[pos] == -1)
            {
                vetor[pos] = elemento;
                break;
            }
            i++;
        } while (i < m);
    }

    // Imprime a tabela hash
    for (int i = 0; i < m; i++)
    {
        cout << vetor[i];
        if (i < m - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}