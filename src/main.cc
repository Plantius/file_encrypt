#include <filesystem>
#include <fstream>
#include "encrypt.h"
#include "standard.h"





int 
main(int argc, char const *argv[])
{
    char* buffer = nullptr; 
    char* outbuffer = nullptr;
    int outcode = 0;
    try
    {
        if (argc < 2)
            throw (-1);
        std::filesystem::path p(argv[1]);
        std::string option = {}, filename = argv[0];

        std::ifstream infile(argv[1], std::ifstream::binary);
        if (!infile.is_open())
            throw(-2);
        
        const size_t size = std::filesystem::file_size(p);
        
        buffer = new char[size];
        infile.read(buffer, size);
        infile.close();
        
        main_menu();
        if (std::getline(std::cin, option)){
            switch (std::stoi(option))
            {
            case 1:
                outbuffer = password_encrypt(get_pwd(), buffer);
                break;
            
            default:
                std::cout << "Not implemented\n";
                break;
            }
        }

        // Write encrypted file to outfile
        if (argc >= 3)
            filename = argv[2];

        std::ofstream outfile(filename);
        outfile.write(buffer, size);
        outfile.close();
    }
    catch(const int err)
    {
        std::cerr << "Usage: " << argv[0] << " <input-file> [output-file]\n";
        switch (err)
        {
        case -1:
            std::cerr << "Error: No input-file and/or output-file specified.\n";
            outcode = -1;
            break;
        case -2:
            std::cerr << "Error: Invalid file.\n";
            outcode = -2;
            break;
        case -3: case -4:
            std::cerr << "Error: Invalid password.\n";
            outcode = -3;
            break;
        
        default:
            std::cerr << "Error: ???. " << err << "\n";
            break;
        }
    }
    if (buffer != nullptr )
        delete[] buffer;
    if (outbuffer != nullptr)
        delete[] outbuffer;
    return outcode;
}
