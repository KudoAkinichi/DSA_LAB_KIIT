#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inFile("example.txt");

    if (!inFile)
    {
        std::cerr << "File could not be opened!" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inFile, line))
    {
        std::cout << line << std::endl;
    }

    inFile.close();
    std::cout << "File read successfully." << std::endl;

    return 0;
}
