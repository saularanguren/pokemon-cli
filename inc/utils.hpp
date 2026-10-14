#pragma once

#include <iostream>
#include <string>

const std::string promptDefecto = "> ";

void saltoLinea();
void getEntrada(std::string& str, const std::string& prompt);

bool esValidoEntero(std::string& str);