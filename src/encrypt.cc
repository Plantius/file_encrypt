#include "encrypt.h"


/*
* Return value has to be freed
*/
char*
password_encrypt(const std::string pwd, const char* buffer, const size_t size)
{
    char* outbuffer = new char[size];

    outbuffer[0] = uint8_t(buffer[0] + hash_function(pwd)) % SHIFT;   
    for (size_t i = 1; i < size; i++)
        outbuffer[i] = uint8_t(outbuffer[i-1] + buffer[i] + hash_function(pwd)) % SHIFT;   
    
    return outbuffer;
}

/*
* Return value has to be freed
*/
char*
password_decrypt(const std::string pwd, const char* buffer, const size_t size)
{
    char* outbuffer = new char[size];

    outbuffer[0] = uint8_t(buffer[0] - hash_function(pwd)) % SHIFT;   
    for (size_t i = 1; i < size; i++)
        outbuffer[i] = uint8_t(buffer[i] - buffer[i-1] - hash_function(pwd) + SHIFT) % SHIFT;   
    
    return outbuffer;
}

int
hash_function(const std::string pwd)
{
    int hash = 0;
    for (size_t i = 0; i < pwd.size(); i++)
        hash += int(pwd[i]);
    
    return (hash * sec2) % sec1;
}