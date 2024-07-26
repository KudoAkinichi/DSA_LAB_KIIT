#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outFile("example.txt");

    if (!outFile)
    {
        std::cerr << "File could not be created!" << std::endl;
        return 1;
    }

    outFile << "Hello, World!" << std::endl;
    outFile << "This is an example of writing to a text file." << std::endl;

    outFile.close();
    std::cout << "File created and text written successfully." << std::endl;

    return 0;
}
