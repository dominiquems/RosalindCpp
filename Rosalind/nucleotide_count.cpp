#include<boost/algorithm/string.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

/**
* @brief A function that reads and returns a line from a text file
* 
* @param: fileName, name of the text file to read from
* @return: string, represents a DNA sequence
**/
std::string readFile(std::string fileName)
{
    std::ifstream infile(fileName);
    std::string line{};

    std::getline(infile, line);
    return line;
}


int main()
{
    readFile("test.txt");
}