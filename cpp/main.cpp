#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


int main( int argc, char **argv )
{
    if( argc < 3 ) return -1;

    std::ios_base::sync_with_stdio(false);  // for faster cout

    std::ifstream fileOneStream(argv[1]);
    std::string fileOneStr;
    while(std::getline(fileOneStream, fileOneStr))
    {
        std::ifstream fileTwoStream(argv[2]);
        std::string fileTwoStr;
        while(std::getline(fileTwoStream, fileTwoStr))
        {
            std::cout << fileOneStr << fileTwoStr << "\n";  // std::endl causes a flush, which takes time
        }
    }
}

