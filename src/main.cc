#include <iostream>
#include "encrypt.h"


int main(int argc, char const *argv[])
{
    try
    {
        if (argc < 2)
            throw (-1);
    }

    catch(const int err)
    {
        switch (err)
        {
        case -1:
            std::cerr << "Error: No input-file specified.\n";
            std::cerr << "Usage: " << argv[0] << " <input-file> [output-file]\n";
            return 1;
        
        default:
            break;
        }
    }
    
    return 0;
}
