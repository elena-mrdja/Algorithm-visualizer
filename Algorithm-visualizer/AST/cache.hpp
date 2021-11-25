#include <iostream>
#include <map>

#ifndef CACHE_HPP
#define CACHE_HPP


class Cache
{
public:
    Cache(){max_size = 100;};
    ~Cache();
    void extend(char variable);
    void new_var(char name);
    void append(char name, char value);

private:
    std::map<char, char*> variables;
    int max_size;
};

#endif // CACHE_HPP
