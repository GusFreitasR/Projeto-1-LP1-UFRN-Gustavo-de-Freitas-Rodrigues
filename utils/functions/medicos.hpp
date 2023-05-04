#include "../defs/MEDICOS.hpp"
#include <iostream>
#ifndef MEDICOS_HPP
#define MEDICOS_HPP

void carregar_medicos();
void add_medico(long int id, std::string name, std::string especialidade);
void list_medicos();
void count_specs();
void atualizar_medicos();
void atualizar_especialidade(long int id_med, std::string new_spec);
void delete_medico( long int id_med);
#endif