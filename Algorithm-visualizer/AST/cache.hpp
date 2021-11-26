#include <iostream>
#include <map>
#include <string>

#ifndef CACHE_HPP
#define CACHE_HPP


class Cache
{
public:
    Cache(){};
    ~Cache();
    void extend(std::string variable);
    void new_var(std::string name, char value);
    void append(std::string name, char value);

private:
    std::map<std::string, char*> variables = {};
    std::map<std::string, int> sizes = {};
};

#endif // CACHE_HPP
