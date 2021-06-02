#include "filter.h"

#include <iostream>
#include <vector>

void print(const ipPool_t& ipPool)
{
    for (const auto& ip : ipPool)
    {
        for (std::size_t i = 0; i < ip.size(); i++)
        {
            std::cout << ip[i];

            if (i != ip.size() - 1)
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    try
    {
        ipPool_t ipPool;

        for (std::string line; std::getline(std::cin, line);)
        {
            auto v = split<std::string>(line, '\t');
            ipPool.push_back(split<int>(v.at(0), '.'));
        }

        std::sort(ipPool.begin(), ipPool.end(), std::greater<>());
        print(ipPool);

        {
            ipPool_t filteredByFirst = filter(ipPool, 1, 0);
            print(filteredByFirst);
        }

        {
            ipPool_t filteredByFirst = filter(ipPool, 46, 0);
            ipPool_t filteredBySecond = filter(filteredByFirst, 70, 1);
            print(filteredBySecond);
        }

        {
            ipPool_t filteredByAny = filter(ipPool, 46);
            print(filteredByAny);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}