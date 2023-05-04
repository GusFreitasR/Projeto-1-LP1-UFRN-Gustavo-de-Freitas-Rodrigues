#include "agenda.hpp"
#include "medicos.hpp"
#include <iostream>

using namespace std;

void carry_dados() // Função para carregamento dos dados
{
    carregar_agenda();
    carregar_medicos();
}

void menu_atendente() // Fazendo o menu com as opções do(a) atendente
{
    int opcao = -1;
    while (opcao != 0)
    {
        cout << "----------------------Menu do Atendente----------------------" << endl;
        cout << "1. Listar médicos" << endl;
        cout << "2. Listar especialidades" << endl;
        cout << "3. Agendar horário para médico" << endl;
        cout << "4. Ver agendamentos de médico" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        long long int id;
        string name_medico, horario;
        string name_med;
        switch (opcao)
        {
        case 1:
            list_medicos();
            break;
        case 2:
            count_specs();
            break;
        case 3:
            cout << "----------------------------------------------------" << endl;
            cout << "Primeiro, qual o seu cpf que deseja marcar consulta? Apenas números" << endl;
            cin >> id;
            cin.ignore();
            cout << "Com qual médico você deseja marcar horário? " << endl;
            getline(cin, name_medico);
            cout << "Ótimo! Agora, em que horário deseja se consultar? " << endl;
            cin.ignore();
            getline(cin, horario);
            add_agendamento(id, name_medico, horario);
            break;
        case 4:
            cout << "Qual médico você desejaria verificar os horários? " << endl;
            cin.ignore();
            getline(cin, name_med);
            cin.ignore();
            show_agendamento_by_name(name_med);
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }
    }
    return;
}

void menu_gestor() // Fazendo o menu com as opções do(a) gestor(a)
{
    int opcao = -1;
    while (opcao != 0)
    {
        cout << "----------------------Menu do gestor----------------------" << endl;
        cout << "1. Listar médicos" << endl;
        cout << "2. Listar especialidades" << endl;
        cout << "3. Adicionar um novo médico" << endl;
        cout << "4. Ver agendamentos de médico" << endl;
        cout << "5. Alterar especialidade de um médico" << endl;
        cout << "6. Demitir um médico " << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        long long int id;
        string name_medico, especialidade;
        string name_med;
        switch (opcao)
        {
        case 1:
            list_medicos();
            break;
        case 2:
            count_specs();
            break;
        case 3:
            cout << "----------------------------------------------------" << endl;
            cout << "Primeiro, qual a identificação do médico (CRM):" << endl;
            cin >> id;
            cout << "Qual o nome do médico? " << endl;
            cin.ignore();
            getline(cin, name_medico);
            cout << "Ótimo! Agora, em que horário deseja se consultar? " << endl;
            cin.ignore();
            getline(cin, especialidade);
            cin.ignore();
            add_medico(id, name_medico, especialidade);
            break;
        case 4:

            cout << "Qual médico você desejaria verificar os horários? " << endl;
            cin.ignore();
            getline(cin, name_med);
            show_agendamento_by_name(name_med);
            break;
        case 5:
            cout << "Qual o CRM do médico que você deseja alterar a especialidade?" << endl;
            cin >> id;
            cout << "Para qual especialidade você deseja alterar?" << endl;
            cin.ignore();
            getline(cin, especialidade);
            atualizar_especialidade(id, especialidade);
            break;
        case 6:
            cout << "Digite o CRM do médico você deseja demitir?" << endl;
            cin >> id;
            cin.ignore();
            delete_medico(id);
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }
    }
    return;
}