#include "game.hpp"

void pokemonSeleccionado()
{

    std::cout << "--- ¿Qué quieres hacer? ---" << std::endl;

    std::cout << "[1] Confirmar         " << std::endl;
    std::cout << "[2] Ver detalles      " << std::endl;
    std::cout << "[3] Cambiar de Pokémon" << std::endl;
}

void panelControlBatalla()
{
    std::cout << "---|                              PANEL DE CONTROL                                |---" << std::endl;
    std::cout << "---|  [1] Ataque básico | [2] Ataque Especial | [3] Estadisticas | [4] Retirarse  |---" << std::endl;
}

void listarPokemones(Pokemon *array, const int& tam)
{
    saltoLinea();

    std::cout << "--- Selecciona tu Pokémon ---" << std::endl;

    for(int i = 0; i < tam; i++)
    {
        std::cout << "[" << i + 1 << "] " << array[i].getNombre() << std::endl;
    }

    std::cout << "[0] Salir" << std::endl;

    saltoLinea();
}

bool confirmarPokemon(Pokemon *array, std::string& str, int tuEleccion)
{
    saltoLinea();
    pokemonSeleccionado();
    saltoLinea();

    while(true)
    {
        getEntrada(str, promptDefecto);

        if(str == "1") { return true; }

        if(str == "2")
        {
            saltoLinea();
            array[tuEleccion].mostrarIlustracion("assets/" + array[tuEleccion].getNombre() + ".txt");
            array[tuEleccion].mostrarInformacion(false);

            saltoLinea();
            std::cout << "¿Deseas continuar con " << array[tuEleccion].getNombre() << "? [S/n]" << std::ends;

            while(true)
            {
                getEntrada(str, ": ");

                if(str == "S" || str == "s") { return true; }

                if(str == "N" || str == "n") { break; }

                std::cout << "Opcion no valida. Escribe [S/n]" << std::ends;
            }

            saltoLinea();
            pokemonSeleccionado();

            continue;
        }

        if(str == "3") { return false; }

        std::cout << "Opción no válida. Elige un número del 1 al 3." << std::endl;
    }
}

int buscandoRival(Pokemon *array, const int& tuPokemon, const int& tamArray)
{
    saltoLinea();
    std::cout << "buscando rival..." << std::endl;

    while(true)
    {
        srand(time(NULL));
        int indiceRival = rand() % tamArray;
    
        if(!(array[indiceRival].getNombre() == array[tuPokemon].getNombre()))
        {
            std::cout << "<< rival encontrado: [" << array[indiceRival].getNombre() << "]" << std::endl;
            saltoLinea();

            return indiceRival;
        }
    }
}

int batallaPokemon(Pokemon *array, const int& tuPokemon, const int& pokemonRival, bool tuTurno, std::string& str)
{
    do
    {
        if(tuTurno)
        {
            /**
             * Panel de control de batalla
             *
             * Validación de la entrada del usuario según las acciones permitidas.
             */

            saltoLinea();
            panelControlBatalla();

            while(true)
            {
                getEntrada(str, promptDefecto);
    
                if(str == "1")
                {
                    array[tuPokemon].atack(array[pokemonRival]);
                    break;
                }
    
                if(str == "2")
                {
                    array[tuPokemon].s_atack(array[pokemonRival]);
                    break;
                }
    
                if(str == "3")
                {
                    saltoLinea();
    
                    std::cout << "Tú Pokémon: " << std::ends;
                    array[tuPokemon].mostrarInformacion();
                    
                    std::cout << "     Rival: " << std::ends;
                    array[pokemonRival].mostrarInformacion();

                    saltoLinea();
                    panelControlBatalla();

                    continue;
                }
    
                if(str == "4")
                {
                    saltoLinea();
                    std::cout << "¡No hay problema! ¡Huye cuando quieras!" << std::endl;
                    return EXIT_FAILURE;
                }
            }
        }
        else
        {
            /**
             * Inteligencia del Pokémon rival
             * 
             * Genera un número aleatorio del 1 al 2 y, según el valor generado,
             * asigna el ataque correspondiente.
             */
            srand(time(NULL));
            int accion = (rand() % 2) + 1;
    
            if(accion == 1)
            {
                array[pokemonRival].atack(array[tuPokemon]);
            }
    
            if(accion == 2)
            {
                array[pokemonRival].s_atack(array[tuPokemon]);
            }
        }

        /**
         * invertir el turno
         */
        tuTurno = !tuTurno;
    }
    while(array[tuPokemon].islive() && array[pokemonRival].islive());

    return EXIT_SUCCESS;
}