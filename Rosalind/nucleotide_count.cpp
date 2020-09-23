#include<iostream>
#include<boost/algorithm/string.hpp>



int main()
{
    std::string userName{ "Dominique" };
    std::string prefix{ "Pomin" };

    std::cout << boost::algorithm::starts_with(userName, prefix);
}