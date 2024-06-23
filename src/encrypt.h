#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <string>
#include <iostream>
const size_t MAX_OPT = 3;
const int MAX_PWD = 256;

char* password_encrypt(const std::string pwd, const char* buffer);


#endif