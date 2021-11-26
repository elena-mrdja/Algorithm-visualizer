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
    void extend(std::string variable); // extends the array of a variable when the max size is reacher
    void new_var(std::string name, char value); // creates a new entry in the dictionary for a new variable
    void append(std::string name, char value); // Adds a new value to the array of the variable in the dictionary

private:
    std::map<std::string, char*> variables = {}; // Dictionary, variable names as strings as keys, array of characters as values, type of array may change
    std::map<std::string, int> sizes = {}; // Dictionary, variable names as strings as keys, stores size of character's array in variables as int.
};

#endif // CACHE_HPP
