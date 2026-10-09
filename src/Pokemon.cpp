#include "Pokemon.hpp"

/**
 * @brief Pokemon(name, type, hp, atk, def, vel, s_atk, s_def)
 */
Pokemon::Pokemon(std::string _nombre, TypePokemon _tipo, int _hp, int _atk, int _def, int _vel, int _s_atk, int _s_def)
{
    this->nombre = _nombre;
    this->tipo = _tipo;

    this->hp = _hp;

    this->atk = _atk;
    this->def = _def;
    this->vel = _vel;

    this->s_atk = _s_atk;
    this->s_def = _s_def;
}

Pokemon::~Pokemon()
{
}

std::string Pokemon::getNombre() const
{
    return this->nombre;
};

std::string Pokemon::getTipo() const
{
    if(this->tipo == TypePokemon::AGUA)
    {
        return "AGUA";
    }

    if(this->tipo == TypePokemon::FUEGO)
    {
        return "FUEGO";
    }

    if(this->tipo == TypePokemon::PLANTA)
    {
        return "PLANTA";
    }

    return "DESCONOCIDO";
}

int Pokemon::getHp() const
{
    return this->hp;
}

int Pokemon::getAtk() const
{
    return this->atk;
}

int Pokemon::getDef() const
{
    return this->def;
}

int Pokemon::getVel() const
{
    return this->vel;
}

int Pokemon::getS_Atk() const
{
    return this->s_atk;
}

int Pokemon::getS_Def() const
{
    return this->s_def;
}

// --- metodos ---
bool Pokemon::islive()
{
    if(this->getHp() == MIN_VALUE)
    {
        return false;
    }

    return true;
}

void Pokemon::take_d(int dmg)
{
    this->hp = this->hp - dmg;

    if(this->hp < MIN_VALUE) { this->hp = MIN_VALUE; }
}

void Pokemon::atack(Pokemon& otro)
{
    int atack = this->getAtk() * (100 / (100.0 + otro.getDef()));

    otro.take_d(atack);

    std::cout << std::endl;
    std::cout << ">> [" << this->getNombre() << "] usa Ataque básico!" << std::endl;
    std::cout << "<< [" << otro.getNombre()  << "] recibe: " << atack << " pnts de daño. HP: " << otro.getHp() << "/" << MAX_VALUE << std::endl;
}

void Pokemon::s_atack(Pokemon& otro)
{   
    int s_atack = this->getS_Atk() * (100.0 / (100 + otro.getDef()));
    
    otro.take_d(s_atack);

    std::cout << std::endl;
    std::cout << ">> [" << this->getNombre() << "] usa Super ATAQUE!" << std::endl;
    std::cout << "<< [" << otro.getNombre()  << "] recibe: " << s_atack << " pnts de daño CRÍTICO. HP: " << otro.getHp() << "/" << MAX_VALUE << std::endl;
}

void Pokemon::mostrarInformacion(bool enLinea)
{
    // Resultado del parametro enLinea siendo true
    // Charmander · Fuego · HP 100/150 · ATK 52 · DEF 43 · VEL 65 · SpA 60 · SpD 50
    if(enLinea)
    {
        std::cout 
            << this->getNombre() << "\t" << this->getTipo() 
            << "\tHP " << this->getHp() << "/" << MAX_VALUE 
            << " · ATK " << this->getAtk() 
            << " · DEF " << this->getDef() 
            << " · VEL " << this->getVel() 
            << " · SpA " << this->getS_Atk() 
            << " · SpD " << this->getS_Def() 
        << std::endl;

        return;
    }

    // Resultado del parametro enLinea siendo false
    // Formato de Ficha Completa del Pokémon
    std::cout << "\t\t  " << this->getNombre() << std::endl;
    std::cout << "\t\t  " << this->getTipo()   << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "\t  HP          " << this->getHp() << " / " << MAX_VALUE << std::endl;

    std::cout << std::endl;
    std::cout << "\t  Ataque          " << this->getAtk() << std::endl;
    std::cout << "\t  Defensa         " << this->getDef() << std::endl;
    std::cout << "\t  Velocidad       " << this->getVel() << std::endl;
    std::cout << "\t  Atq. Esp.       " << this->getS_Atk() << std::endl;
    std::cout << "\t  Def. Esp.       " << this->getS_Def() << std::endl;
    std::cout << std::endl;
}

void Pokemon::mostrarIlustracion(std::string path)
{
    std::string bitIlustracion;
    std::ifstream ilustracion(path);

    if(!ilustracion.is_open())
    {
        std::cout << "{no se encontro la imagen.}" << std::endl;
        return;
    }

    while(getline(ilustracion, bitIlustracion))
    {
        std::cout << bitIlustracion << std::endl;
    }

    ilustracion.close();
}