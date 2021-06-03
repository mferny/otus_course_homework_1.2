#pragma once

#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using ipPool_t = std::vector<std::vector<int>>;

template<typename returnType>
std::vector<returnType> split(const std::string& str, char d)
{
    std::vector<returnType> r;

    std::string::size_type iter = 0;
    while (iter != std::string::npos)
    {
        auto delimiterPos = str.find_first_of(d, iter);
        if constexpr (std::is_same<returnType, int>())
        {
            r.push_back(std::stoi(str.substr(iter,delimiterPos - iter)));
        }
        else if constexpr (std::is_same<returnType, std::string>())
        {
            r.push_back(str.substr(iter,delimiterPos - iter));
        }
        else
        {
            std::cerr << "Supported types for split function are integer and string" << std::endl;
        }

        iter = delimiterPos == std::string::npos ? std::string::npos : delimiterPos + 1;
    }

    return r;
}

// position - fixed position in vector, from 0 to 3
ipPool_t filter(const ipPool_t& ip_pool, int value, int position)
{
    ipPool_t res;
    res.resize(ip_pool.size());
    std::size_t matches = 0;

    std::copy_if(ip_pool.begin(), ip_pool.end(), res.begin(),
         [&](const std::vector<int>& ip)
         {
            if (ip[position] == value)
            {
                matches++;
                return true;
            }
            return false;
         });

    res.resize(matches);

    return res;
}

ipPool_t filter(const ipPool_t& ip_pool, int value)
{
    ipPool_t res;
    res.resize(ip_pool.size());
    std::size_t matches = 0;

    std::copy_if(ip_pool.begin(), ip_pool.end(), res.begin(),
         [&](const std::vector<int>& ip)
         {
             if (ip.end() != std::find(ip.begin(), ip.end(), value))
             {
                 matches++;
                 return true;
             }
             return false;
         });

    res.resize(matches);

    return res;
}

