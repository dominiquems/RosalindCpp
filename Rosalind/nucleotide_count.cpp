#include <boost/format.hpp>

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

/**
* @brief A function that reads and returns a line from a text file
* 
* @param fileName: string, name of the text file to read from
* @return: string, represents a DNA sequence
**/
std::string readFile(std::string fileName)
{
    std::ifstream infile(fileName);
    std::string line{};

    std::getline(infile, line);
    return line;
}

/**
* @ brief Count the number of occurences of each nucleotide in DNA
* 
* @param dnaSeq: string, represents a DNA sequence
* @return: map, nucleotide (char): count(int)
**/
std::map<char, int> countNucleotide(std::string dnaSeq)
{
    std::map<char, int> nucleotideDict{};

    for (int i = 0; i < dnaSeq.size(); ++i)
    {
        if (nucleotideDict.find(dnaSeq[i]) == nucleotideDict.end())
        {
            nucleotideDict[dnaSeq[i]] = 1;
        }
        else
        {
            ++nucleotideDict[dnaSeq[i]];
            std::cout << dnaSeq[i] << '\n';
        }
    }
    return nucleotideDict;
}


int main()
{
    std::string dnaSeq{ readFile("test.txt") };
    std::map<char, int> nucleotideDict{ countNucleotide(dnaSeq) };
    std::cout << boost::format("%1% %2% %3% %4%") % nucleotideDict['A'] % nucleotideDict['C'] % 
        nucleotideDict['G'] % nucleotideDict['T'];
}