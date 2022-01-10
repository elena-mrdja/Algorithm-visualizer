#ifndef TEST_FLOWCHART_HPP
#define TEST_FLOWCHART_HPP
#include "test_flowchart.hpp"
#include "viewer.h"
#include <string>
#include <iostream>
using namespace std;

enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
    };

//struct flowchart {
//    int chart_shape;
//    string text;
//    int first_block; // num of stmts in the first block (if in if and the only block in while)
//    int second_block; // num of stmts in else
//};

flowchart arr1[3] = {{0, "Statement 1", 0,0},
                     {0, "Statement 2", 0,0},
                     {0, "Statement 2", 0,0}};

flowchart arr2[3] = {{1, "If n°1", 2,0},
                        {0, "Statement 1", 0,0},
                       {0, "Statement 2", 0,0}};

flowchart arr3[5] = {{1, "If n°1", 2,2},
                        {0, "Statement 1 in if", 0,0},
                        {0, "Statement 2 in if", 0,0},
                        {0, "Statement 1 in else", 0,0},
                       {0, "Statement 2 in else", 0,0}};

flowchart arr4[3] = {{2, "While n°1", 2,0},
                        {0, "Statement 1", 0,0},
                        {0, "Statement 2", 0,0}};

flowchart arr5[6] = {{1, "If n°1", 4, 1},
                        {0, "Statement in if n°1", 0,0},
                        {1, "If n°2", 1, 1},
                        {0, "Statement in if n°2", 0,0},
                        {0, "Statement in else n°2", 0,0},
                       {0, "Statement in else n°1", 0,0}};


flowchart arr6[9] = {{1, "If n°1", 4, 4},
                        {0, "Statement in if n°1", 0,0},
                        {1, "If n°2", 1, 1},
                        {0, "Statement in if n°2", 0,0},
                        {0, "Statement in else n°2", 0,0},
                        {0, "Statement in else n°1", 0,0},
                      {1, "If n°3", 1, 1},
                       {0, "Statement in if n°3", 0,0},
                        {0, "Statement in else n°3", 0,0}};


flowchart arr7[6] = {{2, "While n°1", 5, 0},
                        {0, "Statement 1 in while n°1",0,0},
                        {2, "While n°2", 2, 0},
                       {0, "Statement 1 in while n°2", 0,0},
                        {0, "Statement 2 in while n°2", 0,0},
                        {0, "Statement 2 in while n°1",0,0}};

flowchart arr8[12] = {{2, "While n°1", 11, 0},
                      {0, "Statement 1 in while n°1", 0,0},
                      {1, "If n°1", 4, 4},
                      {0, "Statement in if n°1", 0,0},
                      {1, "If n°2", 1, 1},
                      {0, "Statement in if n°2", 0,0},
                      {0, "Statement in else n°2", 0,0},
                      {0, "Statement in else n°1", 0,0},
                      {1, "If n°3", 1, 1},
                      {0, "Statement in if n°3", 0,0},
                      {0, "Statement in else n°3", 0,0},
                      {0, "Statement 2 in while n°1", 0,0}};

flowchart arr9[17] = {{1, "If n°1", 8,8},
                         {0, "Statement 1 in if n°1", 0,0},
                         {2, "While n°1", 5, 0},
                         {0, "Statement 1 in while n°1",0,0},
                        {1, "If n°2", 1, 1},
                         {0, "Statement 1 in if n°2", 0,0},
                         {0, "Statement 2 in else n°2", 0,0},
                         {0, "Statement 2 in while n°1",0,0},
                        {0, "Statement 2 in if n°1", 0,0},
                        {0, "Statement 1 in else n°1", 0,0},
                        {2, "While n°2", 5, 0},
                        {0, "Statement 1 in while n°2",0,0},
                        {1, "If n°2", 1, 1},
                        {0, "Statement 1 in if n°2", 0,0},
                        {0, "Statement 2 in else n°2", 0,0},
                      {0, "Statement 2 in while n°2",0,0},
                        {0, "Statement 2 in else n°1", 0,0}};

flowchart arr10[17] = {{1, "If n°1", 8,8},
                        {0, "Statement 1 in if n°1", 0,0},
                       {2, "While n°1", 5, 0},
                       {0, "Statement 1 in while n°1",0,0},
                        {2, "While n°2", 2, 0},
                        {0, "Statement 1 in while n°2", 0,0},
                        {0, "Statement 2 in while n°2", 0,0},
                        {0, "Statement 2 in while n°1",0,0},
                       {0, "Statement 2 in if n°1", 0,0},
                       {0, "Statement 1 in else n°1", 0,0},
                         {2, "While n°3", 5, 0},
                         {0, "Statement 1 in while n°3",0,0},
                         {2, "While n°4", 2, 0},
                         {0, "Statement 1 in while n°4", 0,0},
                         {0, "Statement 2 in while n°4", 0,0},
                         {0, "Statement 2 in while n°3",0,0},
                         {0, "Statement 2 in else n°1", 0,0}};


flowchart arr11[7] = {{1, "If", 2, 4},
                      {0, "S", 0,0},
                       {0, "S", 0,0},
                       {0, "S", 0,0},
                       {0, "S", 0,0},
                       {0, "S", 0,0},
                       {0,"S",0,0}};






//testing for the project...
flowchart test1[1] = {{0, "Declare x", 0,0}};



flowchart test2[2] = {{0, "Declare x", 0,0},
                     {0, "Assign x", 0,0}};



flowchart test3[1] = {{0, "Declare x", 0,0}};



flowchart test4[1] = {{0, "Declare x", 0,0}};



flowchart test5[1] = {{0, "Declare x", 0,0}};



flowchart test6[1] = {{0, "Declare x", 0,0}};



flowchart test7[1] = {{0, "Declare x", 0,0}};



flowchart test8[1] = {{0, "Declare x", 0,0}};



flowchart test9[1] = {{0, "Declare x", 0,0}};



flowchart test10[2] = {{0, "Declare x", 0,0},
                       {0, "Assign x", 0,0}};



flowchart test11[1] = {{0, "Declare x", 0,0}};



flowchart test12[1] = {{0, "Declare x", 0,0}};



flowchart test13[1] = {{0, "Declare x", 0,0}};



flowchart test14[1] = {{0, "Declare x", 0,0}};



flowchart test15[1] = {{0, "Declare x", 0,0}};



flowchart test16[1] = {{0, "Declare x", 0,0}};



flowchart test17[6] = {{0, "Declare i", 0,0},
                      {0, "Declare n", 0,0},
                      {0, "Declare multiplication", 0,0},
                      {2, "While i <= 10", 2,0},
                      {0, "Assign multiplication", 0,0},
                      {0, "Asign i", 0,0}};


flowchart test18[1] = {{0, "Declare x", 0,0}};



flowchart test19[1] = {{0, "Declare x", 0,0}};



flowchart test20[1] = {{0, "Declare x", 0,0}};


flowchart test21[1] = {{0, "Declare x", 0,0}};


flowchart test22[1] = {{0, "Declare x", 0,0}};

#endif // TEST_FLOWCHARTS_HPP
