#include <iostream>
#include <fstream>
#include "../defs/AGENDA.hpp"
#include <vector>
#include <map>
#include <set>
std::ofstream f_agenda("agenda.txt", std::ios::app | std::ios::out); // Cria um novo arquivo para a escrita

using namespace std;

map<long long int, Agenda> agenda;

void carregar_agenda()
{ // Carrega os valores dos médicos que já estavam no arquivo antes da execução do programa.
    fstream new_file;
    new_file.open("agenda.txt", ios::out | ios::app);
    new_file.close();

    fstream read_file;
    read_file.open("agenda.txt", ios::in);
    string linha;
    vector<string> vetor;

    while (getline(read_file, linha))
    {
        vetor.push_back(linha);
    }

    read_file.close();

    for (int i = 0; i < vetor.size(); i += 3)
    {
        long long int id = stoll(vetor[i]);
        agenda[id].nome_medico = vetor[i + 1];
        agenda[id].horario = vetor[i + 2];
    }
}

void add_agendamento(long long int id, string name_med, string horario)
{ // Adiciona um novo médico ao arquivo
    if (f_agenda.is_open())
    { // Verifica se dá pr abrir o arquivo
        f_agenda << id << endl;
        f_agenda << name_med << endl;
        f_agenda << horario << endl;
        agenda[id].nome_medico = name_med;
        agenda[id].horario = horario;
        f_agenda.close();
        cout << "Agendamento cadastrado ao sistema com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao tentar abrir o arquivo." << endl;
    }
}

void show_agendamento_by_name(string name_med)
{ // Mostrando todas as especialidades do sistema juntamente com a quantidade de médicos de cada uma
    int check = 0;
    if (f_agenda.is_open())
    {
        cout << "\n####  Lista de horários   ####\n\n";
        cout << "------------------------------------" << endl;
        for (auto i : agenda)
        {
            if (i.second.nome_medico == name_med)
            {
                cout << "Identificação do agendamento: " << i.first << endl;
                cout << "Nome do médico: " << i.second.nome_medico << endl;
                cout << "Horário da agenda: " << i.second.horario << endl;
                cout << "------------------------------------" << endl;
                check = 1;
            }
        }
    }
    if(check !=1){
        cout << "Não há nenhum agendamento de horário com o médico em questão!" << endl;
    }
}