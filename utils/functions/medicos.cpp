#include <iostream>
#include <fstream>
#include "../defs/MEDICOS.hpp"
#include <vector>
#include <map>
#include <set>

using namespace std;
std::ofstream f_medicos("medicos.txt", ios::app | ios::out); // Cria um novo arquivo para a escrita

map<long int, Medico> medicos;

void carregar_medicos(){ // Carrega os valores dos médicos que já estavam no arquivo antes da execução do programa.
  fstream new_file;
  new_file.open("medicos.txt", ios::out | ios::app);
  new_file.close();
  
  fstream read_file;
  read_file.open("medicos.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  while(getline(read_file, linha)){
    vetor.push_back(linha);
  }

  read_file.close();
  
  for(int i = 0; i< vetor.size(); i+=3){
    long int id = stoll(vetor[i]);
    medicos[id].nome = vetor[i+1];
    medicos[id].especialidade = vetor[i+2];
  }
}

void add_medico(long int id, string name, string especialidade){ // Adiciona um novo médico ao arquivo
    if(f_medicos.is_open()){ // Verifica se dá pr abrir o arquivo
        f_medicos <<  id << endl;
        f_medicos << name << endl;
        f_medicos << especialidade << endl;
        medicos[id].nome = name;
        medicos[id].especialidade = especialidade;
        f_medicos.close();
        cout << "Medico cadastrado ao sistema!" << endl;
    }else{
        cout << "Erro ao tentar abrir o arquivo." << endl;
    }
}

void list_medicos(){ // Listando todos os médicos do sistema
    if(f_medicos.is_open()){
    cout << "\n####  Lista de médicos   ####\n\n";
    cout << "------------------------------------" << endl;
    for(auto i : medicos){
    cout << "Identificação: "<< i.first << endl;
    cout << "Nome: "<< i.second.nome << endl;
    cout << "Especialidade: "<< i.second.especialidade << endl;
    cout << "------------------------------------" << endl;
  }
    }
}

void count_specs(){ // Mostrando todas as especialidades do sistema juntamente com a quantidade de médicos de cada uma
    map<string, int> specs;
    for(auto i: medicos){
        if((specs.find(i.second.especialidade) == specs.end())){
            specs[i.second.especialidade] = 1;
        }else{
             specs[i.second.especialidade] = specs[i.second.especialidade]++;
        }
       
    }
    cout << "*********************************************************************************" << endl;
    cout << "Ao todo, temos " << specs.size() << " especialidades, sendo elas: " << endl;
    for(auto i: specs){
        cout << i.first << " com " << i.second << " médicos nessa especialidade "<< endl;
        cout << "---------------------------------------------" << endl;
    }

}


void atualizar_medicos(){ // Atualizar o arquivo de médicos para atualizar a especialidade
  fstream arquivo;
  arquivo.open(".../medicos.txt", ios::out);
  
  for(auto i : medicos){
    arquivo << i.first << endl;
    arquivo << i.second.nome << endl;
    arquivo << i.second.especialidade << endl;
    
  }
}

void atualizar_especialidade(long int id_med, string new_spec){ // Atualizando a especialidade de um médico
    for(auto i: medicos){
        if(i.first == id_med){
            i.second.especialidade = new_spec;
            atualizar_medicos();
            cout << "Especialidade atualizada com sucesso!" << endl;
            return;
        }
       
    }
    cout << "Médico não foi encontrado!" << endl;
}

void delete_medico( long int id_med){ // Excludino um médio pelo id
  for(auto i : medicos){
    if(i.first == id_med){
      medicos.erase(id_med);
      atualizar_medicos();
      cout << "Médico excluido com sucesso" << endl;
      return;
    }   
  }
  cout << "Médico não encontrado!!!" << endl;
}
