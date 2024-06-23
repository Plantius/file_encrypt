#include <iostream>
#include <fstream>
#include "encrypt.h"


void 
main_menu()
{
    const std::string options[OPT] = {"Password", "Key", "Pincode"};
    std::cout << "Choose an encryption method: \n";
    for (size_t i = 0; i < OPT; i++)
        std::cout << i << ": " << options[i] << "\n";
}


int 
main(int argc, char const *argv[])
{
    try
    {
        if (argc < 3)
            throw (-1);

        std::ifstream infile(argv[1], std::ifstream::binary);
        if (!infile.is_open())
            throw(-2);
        main_menu();


        infile.seekg(0, std::ios::end);
        const size_t length = infile.tellg();
        infile.seekg(0, std::ios::beg);

        char buffer[length];
        infile.read(buffer, length);


        std::ofstream outfile(argv[2]);

    }

    catch(const int err)
    {
        std::cerr << "Usage: " << argv[0] << " <input-file> <output-file>\n";
        switch (err)
        {
        case -1:
            std::cerr << "Error: No input-file and/or output-file specified.\n";
            return -1;
        case -2:
            std::cerr << "Error: Invalid file.\n";
            return -2;
        
        default:
            break;
        }
    }
    
    return 0;
}
