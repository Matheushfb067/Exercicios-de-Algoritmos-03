/*
B) Colecionador de insetos
Anderson finalmente conseguiu um espaço em seu apartamento para expor sua coleção de insetos, e
gostaria de fazê-lo de forma organizada. Cada inseto está guardado dentro de uma caixa de vidro, e
rotulado com o nome cinetífico da espécie e o tamanho em centímetros de cada um. Para otimizar seu
tempo, Anderson pediu a você para que faça um programa que, dados a quantidade de insetos que ele
possui e a informação de cada rótulo, ordene seus insetos por tamanho, e retorne apenas o nome da
espécie na ordem desejada.

Exemplo de Entrada:                Exemplo de Saída:
5                                  Apis mellifera
Bombus terrestris                  Bombus terrestris
2                                  Anoplophora glabripennis
Apis mellifera                     Danaus plexippus
1.5                                Mantis religiosa
Mantis religiosa
7.5
Danaus plexippus
3.5
Anoplophora glabripennis
3
-------------------------------//-------------------------------
Exemplo de Entrada:                Exemplo de Saída:
8                                  Tenebrio molitor
Pieris brassicae                   Forficula auricularia
2.2                                Pieris brassicae
Lucanus cervus                     Zophobas morio
7                                  Nymphalis antiopa
Papilio machaon                    Papilio machaon
3.2                                Periplaneta americana
Tenebrio molitor                   Lucanus cervus
1.5
Forficula auricularia
1.5
Nymphalis antiopa
3
Zophobas morio
2.5
Periplaneta americana
4
*/

#include <iostream>
#include <string>
using namespace std;

struct inseto
{
    string nome;
    double tamanho;
};

void bubbleSort(inseto vetor[], int tamanho)
{
    int i, j; // contadores
    inseto trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho - 1;
    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
            if (vetor[i].tamanho > vetor[i + 1].tamanho)
            {
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        limite = j;
    }
}

int main()
{
    inseto insetos[100];
    int num_insetos;

    cin >> num_insetos;

    for (int i = 0; i < num_insetos; i++)
    {
        cin.ignore();
        getline(cin, insetos[i].nome);
        cin >> insetos[i].tamanho;
    }

    bubbleSort(insetos, num_insetos);

    for (int i = 0; i < num_insetos; i++)
    {
        cout << insetos[i].nome << endl;
    }
    cout << endl;

    return 0;
}