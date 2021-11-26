#include <cstdlib>
#include "cache.hpp"

void Cache::extend(std::string variable){
    char* old = variables[variable];
    char* current = new char[sizes[variable] + 50];
    for (int i = 0; i<sizes[variable]; i++){
        current[i] = old[i];
    }
    sizes[variable] += 50;
    delete[] old;
    variables[variable] = current;

}

void Cache::new_var(std::string name, char value){
    variables[name] = new char[50];
    sizes[name] = 50;
    variables[name][0] = value;
    variables[name][1] = ' ';
}


void Cache::append(std::string name, char value){
    int i = 0;
    int max_size = sizes[name];
    while (i< max_size && variables[name][i] != ' '){
        i++;
    }
    if (i >= max_size - 1){
        this->extend(name);
    }
    variables[name][i] = value;
    variables[name][i+1] = ' ';

}

