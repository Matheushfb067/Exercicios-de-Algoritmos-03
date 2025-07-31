// Batalha de Gladiadores:
/*
A Sony, a principal empresa de videogames do mundo, está recrutando desenvolvedores de jogos para
integrar seu seleto time de desenvolvimento. Para selecionar os melhores talentos, eles propuseram um
desafio de programação, no qual os participantes têm a oportunidade de começar suas carreiras no
emocionante mundo dos games.

O desafio consiste em desenvolver um sistema de batalha entre gladiadores, que opera da seguinte
maneira:

1. O jogador deve cadastrar 5 gladiadores, fornecendo os seguintes atributos para cada um: Nome
(String), Força (int), Habilidade (int) e Idade(int). Tanto a força quanto a habilidade variam de 0 a
10.
2. Após cadastrar os 5 gladiadores, o jogador pode escolher quais gladiadores irão se enfrentar.
3. As batalhas ocorrem da seguinte forma:
a. Cada gladiador inicia com 100 pontos de vida.
b. O primeiro gladiador selecionado ataca primeiro.
c. O dano causado durante um ataque é calculado como "DANO = força + (2^habilidade)".
d. Após o ataque do primeiro gladiador, é a vez do próximo gladiador, e assim por diante,
até que um dos dois seja derrotado (quando sua vida atinge 0).
4. Para sair do jogo, o jogador deve digitar '-1'.
5. Ao final do código, forneça comentários indicando a complexidade assintótica do seu código e a
complexidade, no modelo RAM, das funções do seu código (Coloque como comentários no
próprio código).

Dicas:
1. Utilize uma struct para armazenar os gladiadores.
2. Separe a solução do exercício em funções para facilitar a resolução e deixar seu código mais
organizado. Por exemplo:
bool combate(gladiador g1, gladiador g2){
    //Código que retornará 0 caso g1 ganhe ou 1 caso g2 ganhe
}
*/

#include <iostream>
#include <string>
using namespace std;

struct Gladiador
{
    string nome;
    int forca;
    int habilidade;
    int idade;
};

void escolha(int &gladiador1, int &gladiador2)
{
    cout << "Escolha o numero do primeiro gladiador (0 a 4): ";
    cin >> gladiador1;
    while (gladiador1 < 0 || gladiador1 > 4)
    {
        cin >> gladiador1;
    }

    cout << "Escolha o numero do segundo gladiador (0 a 4): ";
    cin >> gladiador2;
    while (gladiador2 < 0 || gladiador2 > 4 || gladiador2 == gladiador1)
    {
        cout << "Valor invalido! escolha novamente o segundo gladiador: ";
        cin >> gladiador2;
    }
}

bool batalha(Gladiador g1, Gladiador g2)
{
    int vida1 = 100;
    int vida2 = 100;

    int dano = g1.forca + (2 ^ g1.habilidade);

    while (vida1 > 0 && vida2 > 0)
    {
        vida2 -= dano;
        if (vida2 <= 0)
            break;

        vida1 -= dano;
        if (vida1 <= 0)
            break;
    }

    if (vida1 > vida2)
    {
        cout << g1.nome << " venceu!" << endl;
        return true;
    }
    else
    {
        cout << g2.nome << " venceu!" << endl;
        return false;
    }
}

int main()
{
    Gladiador Gladiadores[5];
    int gladiador1, gladiador2;

    for (int i = 0; i < 5; i++)
    {
        getline(cin, Gladiadores[i].nome);
        cin >> Gladiadores[i].forca;
        while (Gladiadores[i].forca < 0 || Gladiadores[i].forca > 10)
        {
            cout << "Entre com a força" << endl;
            cin >> Gladiadores[i].forca;
        }
        cin >> Gladiadores[i].habilidade;
        while (Gladiadores[i].habilidade < 0 || Gladiadores[i].habilidade > 10)
        {
            cout << "Entre com a habilidade" << endl;
            cin >> Gladiadores[i].habilidade;
        }
        cin >> Gladiadores[i].idade;
        cin.ignore();
    }

    escolha(gladiador1, gladiador2);
    batalha(Gladiadores[gladiador1], Gladiadores[gladiador2]);

    int op;
    cout << "Digite -1 para sair" << endl;
    cin >> op;
    while (op != -1)
    {
        escolha(gladiador1, gladiador2);
        batalha(Gladiadores[gladiador1], Gladiadores[gladiador2]);
        cin >> op;
    }

    return 0;
}