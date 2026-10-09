#include "Pokemon.hpp"

int main()
{
    Pokemon pokedex[] = 
    {
        // --- Pokemon(name, type, hp, atk, def, vel, s_atk, s_def) ---

        Pokemon ("Bulbasaur",  TypePokemon::PLANTA, 150, 39, 39, 35, 55, 55),
        Pokemon ("Charmander", TypePokemon::FUEGO,  150, 42, 33, 55, 50, 40),
        Pokemon ("Squirtle",   TypePokemon::AGUA,   150, 38, 55, 33, 40, 54),
    };

    return EXIT_SUCCESS;
}