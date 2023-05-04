#include <iostream>
#include "utils/functions/menus.hpp"
using namespace std;

int main()
{

    cout << "\n#############################\n";
    cout << "### Hospital JANIHERYSON ###\n";
    cout << "#############################\n\n";


   
    int opt;

    string senha;
    carry_dados(); // Carregando os dados dos medicos.txt e agenda.txt
    do
    {
        cout << "Escolha o perfil que voce deseja acessar" << endl;    // Escolhendo o perfil que o usuário quer acessar;
        cout << "1. Atendente" << endl;
        cout << "2. Gestor" << endl;
        cout << "0. Sair do hospital" << endl;
        cin >> opt;
        switch (opt) // Escolhendo o menu a ser mostrado;
        {
        case 1:
            cin.ignore();
            menu_atendente();
            break;

        case 2:
            cout << "Para acessar o menu do gestor, você precisa de uma senha." << endl;
            cout << "Digite a senha : ";
            cin.ignore();
            getline(cin, senha);
            if (senha == "admin")
            {
                menu_gestor();
            }
            else
            {
                cout << "Senha incorreta!!!" << endl;
                break;
            }
            break;
        default:
            if(opt != 0){
                cout << "Digite uma opcao valida!";
            }

            break;
        }
    } while (opt != 0);

    return 0;
}