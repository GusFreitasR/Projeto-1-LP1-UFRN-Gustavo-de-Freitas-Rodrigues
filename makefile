	g++ -c main.cpp utils\functions\agenda.hpp utils\functions\medicos.hpp utils\functions\menus.hpp
	g++ -o meu_P main.o utils\functions\agenda.o utils\functions\medicos.o utils\functions\menus.o
	./meu_P
