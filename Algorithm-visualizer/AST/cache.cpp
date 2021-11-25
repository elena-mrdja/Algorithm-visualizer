#include <cstdlib>
#include "cache.hpp"

void Cache::extend(char variable){
    char* old = variables[variable];
    max_size += 50;
    char* current = new char[max_size];
    for (int i = 0; i<max_size; i++){
        current[i] = old[i];
    }
    delete[] old;
    variables[variable] = current;

}

void Cache::new_var(char name){
    variables[name] = new char[max_size];
    variables[name][0] = ' ';
}


void Cache::append(char name, char value){
    int i = 0;
    while (i< max_size && variables[name][i] != ' '){
        i++;
    }
    if (i >= max_size - 1){
        this->extend(name);
    }
    variables[name][i] = value;
    variables[name][i+1] = ' ';

}
