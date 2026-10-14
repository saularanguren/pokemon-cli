#pragma once

#include <iostream>
#include <fstream>

enum class TypePokemon
{
    AGUA,
    FUEGO,
    PLANTA,
};

class Pokemon
{
private:
    // --- atributos ---
    std::string nombre;
    TypePokemon tipo;

    int hp;
    
    int atk;
    int def;
    int vel;
    
    int s_atk;
    int s_def;

public:
    // --- constructor y destructor ---
    Pokemon(
        std::string _nombre, 
        TypePokemon _tipo, 
        int _hp, 
        int _atk, 
        int _def, 
        int _vel, 
        int _s_atk, 
        int _s_def
    );
    ~Pokemon();
    
    static constexpr int MAX_VALUE = 150;
    static constexpr int MIN_VALUE = 0;

    // --- getters ---
    std::string getNombre() const;
    std::string getTipo() const;

    int getHp() const;

    int getAtk() const;
    int getDef() const;
    int getVel() const;

    int getS_Atk() const;
    int getS_Def() const;

    // --- metodos ---
    bool islive();

    void take_d(int dmg);
    void atack(Pokemon& otro);
    void s_atack(Pokemon& otro);

    void mostrarInformacion(bool enLinea = true);
    void mostrarIlustracion(std::string path);
};