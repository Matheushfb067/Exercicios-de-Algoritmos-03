// Pastelaria do Dudu (Sequencial)
/*
Eduardo estava cuidando do estoque da pastelaria da família e teve a ideia de chamar um aluno
do Inatel para ajudar a registrar os itens para verificar com mais facilidade se possui ou não determinado
produto. Ajude Eduardo a criar um sistema que armazene nome e quantidade de cada produto em um
vetor, e imprima uma mensagem informando se existe ou não em estoque.

Entrada:
A primeira linha consiste num valor inteiro N correspondente à quantidade de produtos cadastrados. E as
demais N linhas consistem em uma string correspondente ao nome do produto e um valor inteiro
correspondente à quantidade (unidade(s) ou pacote(s)) em estoque. Em seguida deve ser colocado o
nome do produto que deseja buscar.

Saída:
A saída consiste em uma mensagem dizendo se tem em estoque ou não. O produto deve ser impresso na
mensagem.

Exemplo de Entrada:                Exemplo de Saída:
4                                  Ovo em estoque!
Farinha 2
Ovo 12
Oleo 1
Sal 1
Ovo
-------------------------------//-------------------------------
Exemplo de Entrada:                Exemplo de Saída:
3                                  Nao existe Banana em estoque!
Frango 5
Calabresa 4
Queijo 9
Banana
*/

#include <iostream>
#include <string>
using namespace std;

struct produto
{
    string nome;
    int quantidade;
};

int main()
{
    int N, i;
    produto produtos[100];
    string busca;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin.ignore();
        getline(cin, produtos[i].nome);
        cin >> produtos[i].quantidade;
    }

    cin.ignore();
    getline(cin, busca);

    for (i = 0; i < N; i++)
    {
        if (busca == produtos[i].nome)
        {
            cout << produtos[i].nome << " em estoque!" << endl;
            return 0; // Encerra o programa
        }
    }

    cout << "Nao existe " << busca << " em estoque!" << endl;

    return 0;
}