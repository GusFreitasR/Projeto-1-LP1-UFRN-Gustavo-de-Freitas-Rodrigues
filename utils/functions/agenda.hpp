#include<iostream>
#ifndef AGENDA_hpp
#define AGENDA_hpp


void carregar_agenda();
void add_agendamento(long long int id, std::string name_med, std::string horario);
void show_agendamento_by_name(std::string name_med);

#endif