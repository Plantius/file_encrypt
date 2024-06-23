#include "standard.h"

std::string 
get_pwd()
{
    std::string pwd = {};
    std::cout << "Enter a password:\n Max size 256 characters\n Only ASCII characters\nPassword: ";
    std::getline(std::cin, pwd);
    
    if (pwd.size() > MAX_PWD)
        throw (-4);
    for (size_t i = 0; i < pwd.size(); i++)
        if (!isascii(pwd[i])) throw(-3);

    return pwd;
}

void 
main_menu()
{
    const std::string options[MAX_OPT] = {"Password", "Key", "Pincode"};
    std::cout << "Choose an encryption method: \n";
    for (size_t i = 1; i <= MAX_OPT; i++)
        std::cout << i << ": " << options[i-1] << "\n";
}