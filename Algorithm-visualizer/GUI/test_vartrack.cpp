#ifndef VAR_TRACK
#define VAR_TRACK
#include "test_vartrack.hpp"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>

//only decl
vector<vector<pair<vector<string>,vector<int>>>> test1(){

    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"x"};
    pair1.second = {5};

    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<vector<pair<vector<string>,vector<int>>>> list;
    list = {vec1};

    return list;
};

//declaration + assign
vector<vector<pair<vector<string>,vector<int>>>> test10(){

    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"x"};
    pair1.second = {-2};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"x"};
    pair2.second = {-10};

    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair2};

    vector<vector<pair<vector<string>,vector<int>>>> list;
    list = {vec1, vec2};

    return list;
};

//simple ifelse
vector<vector<pair<vector<string>,vector<int>>>> test11(){

    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"a"};
    pair1.second = {10};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"b"};
    pair2.second = {16};

    pair<vector<string>,vector<int>> pair3;
    pair2.first = {"a"};
    pair2.second = {11};

    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair1, pair2};

    vector<pair<vector<string>,vector<int>>> vec3;
    vec3 = {pair3, pair2};

    vector<vector<pair<vector<string>,vector<int>>>> list;
    list = {vec1, vec2, vec3};

    return list;
};

//GCD
vector<vector<pair<vector<string>,vector<int>>>> test14(){

    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"a"};
    pair1.second = {181};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"b"};
    pair2.second = {69};

    pair<vector<string>,vector<int>> pair3;
    pair3.first = {"a"};
    pair3.second = {112,43,43,17,17,8,8,7,6,5,4,3,2,1};


    pair<vector<string>,vector<int>> pair4;
    pair4.first = {"b"};
    pair4.second = {69,69,26,26,9,9,1,1,1,1,1,1,1,1};

    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair1, pair2};

    vector<pair<vector<string>,vector<int>>> vec3;
    vec3 = {pair3, pair2};

    vector<vector<pair<vector<string>,vector<int>>>> list;
    list = {vec1, vec2, vec3};

    return list;
};

//is_prime
vector<vector<pair<vector<string>,vector<int>>>> test15(){

    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"n"};
    pair1.second = {31};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"i"};
    pair2.second = {2};

    pair<vector<string>,vector<int>> pair3;
    pair3.first = {"prime"};
    pair3.second = {true};


    pair<vector<string>,vector<int>> pair4;
    pair4.first = {"n"};
    pair4.second = {31,31,31,31,31,31,31,31,31,31,31,31,31,31};

    pair<vector<string>,vector<int>> pair5;
    pair5.first = {"i"};
    pair5.second = {3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    pair<vector<string>,vector<int>> pair6;
    pair6.first = {"prime"};
    pair6.second = {true,true,true,true,true,true,true,true,true,true,true,true,true,true,};

    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair1, pair2};

    vector<pair<vector<string>,vector<int>>> vec3;
    vec3 = {pair1, pair2, pair3};

    vector<pair<vector<string>,vector<int>>> vec4;
    vec4 = {pair4, pair5, pair6};

    vector<vector<pair<vector<string>,vector<int>>>> list;
    list = {vec1, vec2, vec3, vec4};

    return list;
};



vector<vector<pair<vector<string>,vector<int>>>> test6();

vector<vector<pair<vector<string>,vector<int>>>> test7();

vector<vector<pair<vector<string>,vector<int>>>> test8();

vector<vector<pair<vector<string>,vector<int>>>> test9();

vector<vector<pair<vector<string>,vector<int>>>> test10();

vector<vector<pair<vector<string>,vector<int>>>> test11();

vector<vector<pair<vector<string>,vector<int>>>> test12();

vector<vector<pair<vector<string>,vector<int>>>> test13();

vector<vector<pair<vector<string>,vector<int>>>> test14();

vector<vector<pair<vector<string>,vector<int>>>> test15();

vector<vector<pair<vector<string>,vector<int>>>> test16();


//multiplication with while
vector<vector<pair<vector<string>,vector<int>>>> test17(){

    //list of lists of pairs, where both elements of the pair are vectors (first one with always lenght one, a string/name of var)
    //and the other one having 1 or more elements (in loop case)
    vector<vector<pair<vector<string>,vector<int>>>> list;


    //i fill manually the evolution of the code
    pair<vector<string>,vector<int>> pair1;
    pair1.first = {"i"};
    pair1.second = {1};

    pair<vector<string>,vector<int>> pair2;
    pair2.first = {"n"};
    pair2.second = {7};



    pair<vector<string>,vector<int>> pair3;
    pair3.first = {"multiplication"};
    pair3.second = {0};

    pair<vector<string>,vector<int>> pair41;
    pair41.first = {"i"};
    pair41.second = {2,3,4,5,6,7,8,9,10,11};

    pair<vector<string>,vector<int>> pair42;
    pair42.first = {"n"};
    pair42.second = {7,7,7,7,7,7,7,7,7,7};

    pair<vector<string>,vector<int>> pair43;
    pair43.first = {"multiplication"};
    pair43.second = {7,14,21,28,35,42,49,56,63,70};


    vector<pair<vector<string>,vector<int>>> vec1;
    vec1 = {pair1};

    vector<pair<vector<string>,vector<int>>> vec2;
    vec2 = {pair1, pair2};


    vector<pair<vector<string>,vector<int>>> vec3;
    vec3 = {pair1, pair2, pair3};

    vector<pair<vector<string>,vector<int>>> vec4;
    vec4 = {pair42, pair43, pair41};

    //this is the final list
    //on button clicked take an element from the list and print it resp
    list = {vec1, vec2, vec3, vec4};

    return list;
 }

vector<vector<pair<vector<string>,vector<int>>>> test18();

vector<vector<pair<vector<string>,vector<int>>>> test19();

vector<vector<pair<vector<string>,vector<int>>>> test20();

vector<vector<pair<vector<string>,vector<int>>>> test21();

vector<vector<pair<vector<string>,vector<int>>>> test22();






#endif
