#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE test_ip

#include "../filter.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ip_filter_tests)

BOOST_AUTO_TEST_CASE(test_split)
{
    {
        const auto res = split<int>("123.12.14.34", '.');
        std::vector<int> gold = { 123, 12, 14, 34};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gold.begin(), gold.end());
    }
    {
        const auto res = split<std::string>("123.12.14.34", '.');
        std::vector<std::string> gold = { "123", "12", "14", "34"};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gold.begin(), gold.end());
    }
    {
        const auto res = split<std::string>("", '.');
        std::vector<std::string> gold = { ""};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gold.begin(), gold.end());
    }
    {
        const auto res = split<std::string>(".", '.');
        std::vector<std::string> gold = { "", ""};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gold.begin(), gold.end());
    }
    {
        const auto res = split<std::string>("11.", '.');
        std::vector<std::string> gold = { "11", ""};
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gold.begin(), gold.end());
    }
}

BOOST_AUTO_TEST_CASE(test_filter)
{
    {
        ipPool_t ipPool =
            {
                {123, 23, 45, 67},
                {24, 23, 95, 67},
                {123, 90, 456, 23},
                {45, 34, 0, 45},
                {89, 23, 9, 43}
            };
        ipPool_t gold =
            {
                {123, 23, 45, 67},
                {24, 23, 95, 67},
                {89, 23, 9, 43}
            };

        ipPool_t res = filter(ipPool, 23, 1);

        BOOST_CHECK_EQUAL(res.size(), gold.size());
    }

    {
        ipPool_t ipPool =
                {
                        {123, 23, 45, 67},
                        {24, 23, 95, 67},
                        {123, 90, 456, 23},
                        {45, 34, 0, 45},
                        {89, 23, 9, 123}
                };
        ipPool_t gold =
                {
                        {123, 23, 45, 67},
                        {123, 90, 456, 23},
                        {89, 23, 9, 123}
                };

        ipPool_t res = filter(ipPool, 123);

        BOOST_CHECK_EQUAL(res.size(), gold.size());
    }
}

BOOST_AUTO_TEST_SUITE_END() // split test