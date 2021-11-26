#include <cstdlib>
#include "cache.hpp"

void Cache::extend(std::string variable){
    // Copy old array into a variable
    char* old = variables[variable];
    // Create a new array that is +50 bigger than the size of the previous array
    char* current = new char[sizes[variable] + 50];
    //Copy old items into the new array
    for (int i = 0; i<sizes[variable]; i++){
        current[i] = old[i];
    }
    //Update the new size of the array in the sizes dictionary
    sizes[variable] += 50;
    // Free up the memory occupied by the old array
    delete[] old;
    // Update the array of the variable in the dictionary
    variables[variable] = current;

}

void Cache::new_var(std::string name, char value){
    // Initialise a new entry of size 50 in the dictionary variables
    variables[name] = new char[50];
    // Record the size of the array (50) in the sizes array
    sizes[name] = 50;
    // Set the first element of the array to the desired value
    variables[name][0] = value;
    // Set the second element to an empty space characted so that we know where to append a new value
    variables[name][1] = ' ';
}


void Cache::append(std::string name, char value){
    int i = 0;
    int max_size = sizes[name];
    // Iterate to find the empty space character
    while (i< max_size && variables[name][i] != ' '){
        i++;
    }
    // if the empty character is not found because the array is full, extend the array, and the first empty character is now the first empty cell after the old array
    if (i >= max_size - 1){
        this->extend(name);
        i = max_size;
    }
    // Set the variable i to the new value
    variables[name][i] = value;
    // If the space after the new variable is within the bounds of the array, set it to an empty space character to signal the next spot for appending.
    if (i + 1 < sizes[name]){
        variables[name][i+1] = ' ';
    }

}

