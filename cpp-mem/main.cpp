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
    std::vector<std::string> fileOnetokens{std::istream_iterator<std::string>{fileOneStream}, std::istream_iterator<std::string>{}};

    std::ifstream fileTwoStream(argv[2]);
    std::vector<std::string> fileTwotokens{std::istream_iterator<std::string>{fileTwoStream}, std::istream_iterator<std::string>{}};

    for (auto &fileOneStr: fileOnetokens)
    {
        for (auto &fileTwoStr: fileTwotokens)
        {
            std::cout << fileOneStr << fileTwoStr << "\n";  // std::endl causes a flush, which takes time
        }
    }
}

