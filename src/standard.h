#ifndef STANDARD_H
#define STANDARD_H
#include <iostream>


#define ENCRYPT "e"
#define DECRYPT "d"

const size_t MAX_OPT = 3;
const int MAX_PWD = 256;
const uint32_t secret = 947;
const int SHIFT = 1 << 8;

std::string get_pwd(); 

void main_menu();


#endif