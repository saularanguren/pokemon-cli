#pragma once

#include <iostream>
#include <string>

#include "utils.hpp"
#include "Pokemon.hpp"

void listarPokemones (Pokemon *array, const int& tam);
bool confirmarPokemon(Pokemon *array, std::string& str, int tuEleccion);

int buscandoRival (Pokemon *array, const int& tuPokemon, const int& tamArray);
int batallaPokemon(Pokemon *array, const int& tuPokemon, const int& pokemonRival, bool tuTurno, std::string& str);