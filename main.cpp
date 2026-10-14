#include "Pokemon.hpp"
#include "utils.hpp"
#include "game.hpp"

int main()
{
    std::string buffer;

    Pokemon pokedex[] = 
    {
        // --- Pokemon(name, type, hp, atk, def, vel, s_atk, s_def) ---

        Pokemon ("Bulbasaur",  TypePokemon::PLANTA, 150, 39, 39, 35, 55, 55),
        Pokemon ("Charmander", TypePokemon::FUEGO,  150, 42, 33, 55, 50, 40),
        Pokemon ("Squirtle",   TypePokemon::AGUA,   150, 38, 55, 33, 40, 54),
    };

    int tamPokedex = sizeof(pokedex) / sizeof(pokedex[0]);
    int indiceTuPokemon;

    std::cout << "\t=== POKEMON CLI v1.0 ===" << std::endl;

    while(true)
    {
        listarPokemones(pokedex, tamPokedex);
        
        while(true)
        {
            getEntrada(buffer, promptDefecto);

            if(esValidoEntero(buffer))
            {
                if(std::stoi(buffer) >= 0 && std::stoi(buffer) <= tamPokedex)
                {
                    break;
                }
            }

            std::cout << "Opción no válida. Elige un número del " << 1 << " al " << tamPokedex << "." << std::endl;
        }

        indiceTuPokemon = std::stoi(buffer);

        if (indiceTuPokemon == 0) 
        {
            std::cout << "Hasta pronto, entrenador pokémon!" << std::endl;
            return EXIT_SUCCESS; 
        }

        // me aseguro de estar dentro de los rangos reales de las posiones del arreglo
        indiceTuPokemon--;
        std::cout << "Has seleccionado a [" << pokedex[indiceTuPokemon].getNombre() << "]." << std::endl;
        
        if(confirmarPokemon(pokedex, buffer, indiceTuPokemon)) { break; }
    }

    std::cout << "!" << pokedex[indiceTuPokemon].getNombre() << ", es hora de la batalla!" << std::endl;

    int indiceTuRival = buscandoRival(pokedex, indiceTuPokemon, tamPokedex);

    std::cout << "--- ¡Comienza la Batalla! ---" << std::endl;
    std::cout << "[" << pokedex[indiceTuPokemon].getNombre() << "] vs [" << pokedex[indiceTuRival].getNombre() << "]" << std::endl;
    saltoLinea();

    /**
     * el Pokémon con mayor velocidad será el primero en atacar
     */
    bool tuTurno = pokedex[indiceTuPokemon].getVel() > pokedex[indiceTuRival].getVel();
    std::cout << "Comparando velocidad..." << std::endl;

    std::cout << "    " << pokedex[indiceTuRival].getNombre()   << "\tVEl(" << pokedex[indiceTuRival].getVel()   << ")" << std::endl;
    std::cout << "    " << pokedex[indiceTuPokemon].getNombre() << "\tVEl(" << pokedex[indiceTuPokemon].getVel() << ") *tú" << std::endl;
    
    saltoLinea();
    std::cout << "¡" << (tuTurno ? pokedex[indiceTuPokemon].getNombre() : pokedex[indiceTuRival].getNombre()) << " es más rápido y atacará primero!" << std::endl;

    (tuTurno) ? std::cout << "    << ¡Toma la iniciativa, " << pokedex[indiceTuPokemon].getNombre() << " (tú)!" << std::endl :
    std::cout << "    << ¡Cuidado, " << pokedex[indiceTuPokemon].getNombre() << "! El rival toma la iniciativa." << std::endl;
    
    int desenlaceBatalla = batallaPokemon(pokedex, indiceTuPokemon, indiceTuRival, tuTurno, buffer);

    if(desenlaceBatalla == EXIT_FAILURE) { return EXIT_FAILURE; }

    saltoLinea();

    if(pokedex[indiceTuPokemon].islive())
    {
        std::cout << "Con tú último golpe " << pokedex[indiceTuPokemon].getNombre() << ", tu rival [" << pokedex[indiceTuRival].getNombre() << "] cae. La victoria es tuya." << std::endl;
        saltoLinea();

        pokedex[indiceTuPokemon].mostrarIlustracion("assets/" + pokedex[indiceTuPokemon].getNombre() + ".txt");
        pokedex[indiceTuPokemon].mostrarInformacion(false);

        return EXIT_SUCCESS;
    }

    std::cout << "El último golpe de " << pokedex[indiceTuRival].getNombre() << " sella tu destino. Has perdido la batalla." << std::endl;
    saltoLinea();
    
    pokedex[indiceTuRival].mostrarIlustracion("assets/" + pokedex[indiceTuRival].getNombre() + ".txt");
    pokedex[indiceTuRival].mostrarInformacion(false);

    return EXIT_SUCCESS;
}