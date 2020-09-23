#include <boost/algorithm/string/erase.hpp>
#include <boost/format.hpp>
#include <regex>
#include <map>
#include <iostream>
#include <fstream>

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
    boost::erase_all(line, "\n");
    return line;
}

/**
* @brief Count the number of occurences of each nucleotide in DNA
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
        }
    }
    return nucleotideDict;
}

/**
* @brief Check if only nucleotide symbols are present in the DNA sequence
* 
* @param dnaSeq: str, represents a DNA sequence
* @return: bool, 1 if the sequence is valid and 0 otherwise
**/
bool isValidSeq(std::string dnaSeq)
{
    std::regex pattern("[ACGT]*");

    if (std::regex_match(dnaSeq, pattern))
    {
        return 1;
    }
    else
    {
        std::cout << "Sequence contains unknown characters\n";
        return 0;
    }
}

int main()
{
    std::string dnaSeq{ readFile("test.txt") };
    if (!isValidSeq(dnaSeq))
    {
        std::cout << "Halting...\n";
        return -1;
    }
    std::map<char, int> nucleotideDict{ countNucleotide(dnaSeq) };
    std::cout << boost::format("%1% %2% %3% %4%") % nucleotideDict['A'] % 
        nucleotideDict['C'] % nucleotideDict['G'] % nucleotideDict['T'];
    return 0;
}