#include <iostream>
using namespace std;

struct Gladiador
{
    string nome;
    int forca, habilidade, idade, vida;
};

int potencia(int base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    return base * potencia(base, exp - 1);
}

int ataque(Gladiador gladiador)
{
    return gladiador.forca + potencia(2, gladiador.habilidade);
}

bool combate(Gladiador g1, Gladiador g2)
{
    while (g1.vida > 0 && g2.vida > 0)
    {
        g2.vida -= ataque(g1);
        g1.vida -= ataque(g2);
    }
    return g2.vida <= 0; // true se g1 venceu
}

int main()
{
    Gladiador gladiadores[1000];
    int quantidade = 0;
    int opcao;

    do
    {
        cout << "Escolha uma opcao:\n";
        cout << "1 - Cadastrar gladiador\n";
        cout << "2 - Fazer batalha\n";
        cout << "3 - Sair\n";
        cin >> opcao;

        if (opcao == 1)
        {
            // Cadastro
            string nome;
            int forca, habilidade, idade;
            cout << "Nome: ";
            cin >> nome;
            cout << "Forca: ";
            cin >> forca;
            cout << "Habilidade: ";
            cin >> habilidade;
            cout << "Idade: ";
            cin >> idade;
            gladiadores[quantidade] = {nome, forca, habilidade, idade, 100};
            quantidade++;
        }
        else if (opcao == 2)
        {
            if (quantidade < 2)
            {
                cout << "Cadastre pelo menos dois gladiadores antes de batalhar.\n";
                continue;
            }
            int g1, g2;
            cout << "Digite os indices dos gladiadores (0 a " << quantidade - 1 << "): ";
            cin >> g1 >> g2;
            if (g1 < 0 || g1 >= quantidade || g2 < 0 || g2 >= quantidade || g1 == g2)
            {
                cout << "Indices invalidos.\n";
                continue;
            }
            if (combate(gladiadores[g1], gladiadores[g2]))
            {
                cout << gladiadores[g1].nome << " ganhou a batalha contra " << gladiadores[g2].nome << ".\n";
            }
            else
            {
                cout << gladiadores[g2].nome << " ganhou a batalha contra " << gladiadores[g1].nome << ".\n";
            }
        }
        else if (opcao == 3)
        {
            cout << "Saindo do sistema...\n";
        }
        else
        {
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 3);

    return 0;
}
