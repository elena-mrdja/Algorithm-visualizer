#include <iostream>
#include <map>
#include <string>

#ifndef CACHE_HPP
#define CACHE_HPP


class Cache
{
public:
    Cache(){max_size = 100;};
    ~Cache();
    void extend(std::string variable);
    void new_var(std::string name, char value);
    void append(std::string name, char value);

private:
    std::map<std::string, char*> variables = {};
    int max_size;
};

#endif // CACHE_HPP
