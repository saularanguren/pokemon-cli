#include "utils.hpp"

/**
 * @brief fun aux para generar un salto de linea simple
 */
void saltoLinea()
{
    std::cout << std::endl;
}

/**
 * @brief fun aux para leer la entrada por parte del usuario
 * 
 * @param str dato string para leer cualquier entrada
 * @param prompt indicador, puede ser simbolo o descriptivo 
 */
void getEntrada(std::string& str, const std::string& prompt)
{
    std::cout << prompt << std::ends;
    std::getline(std::cin, str);
}

/**
 * @brief fun aux para determinar si una entrada es un numero
 * @return true = correcto | false = incorrecto
 */
bool esValidoEntero(std::string& str)
{
    // comprobar que la cadena no venga vacia
    if(str.empty())
    {
        return false;
    }

    int comienzo = 0;

    // comprobar que si existe un negativo sea el primer caracter
    if(str[0] == '-')
    {
        if(str.size() == 1)
        {
            return false;
        }

        comienzo = 1;
    }

    // revisa que no existan 0's de relleno
    if(str[comienzo] == 0 && str.size() > 1)
    {
        return false;
    }

    for(std::size_t i = comienzo; i < str.size(); i++)
    {
        // si algun caracter no es un digito nos salimos
        if(!std::isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}