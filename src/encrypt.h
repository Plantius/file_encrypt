#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <string>
#include "standard.h"

char* password_encrypt(const std::string pwd, 
                       const char* buffer, 
                       const size_t size);
char* password_decrypt(const std::string pwd, 
                       const char* buffer, 
                       const size_t size);


#endif