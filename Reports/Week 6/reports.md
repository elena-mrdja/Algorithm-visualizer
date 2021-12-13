# Week 6

#### Milena NedeljkovicThis:
- finalized the structure of cache for variable tracking with my team and Mina
- wrote the struct Value and ValueList inspired by Cache; this will most likely be used in the final version for variable tracking
- moved class method definitions from ast_classes.hpp to ast_classes.cpp
- started writing the interpreter: read_statement and draw_chart functions
- talked about ast building with Katia; i gave Evdokia the task to make the functions for the final step towards the AST and they are coming together
Goals for next week:
- finalize all functions and get involved into finalizing the AST builder with Katia and Evdokia
- having a meeting with the other team leaders like we do every Monday before the lecture to finalize everybody's tasks for the week
- we will all have to work together on the same functions as this point, so my goal is to overlook everything, help where needed and connect it all
#### Darya Todoskova
This week I met up many times with my teammates to discuss how we were finally going to implement the AST walker, and we’re getting very close to the final result! I personally wrote tests for the expression evaluator, since we didn’t have any. I am now seeing with Evdokia how to split tasks for the AST, and then we’ll be able to pass the functions on to the GUI team to use for the flowchart.
#### Evdokia Gneusheva
This week my team leader assigned me the task to create a function create_ast_from_parse (in ast_builder.cpp file on Interpreter branch). The input of my function are objects created by Team 1 as a result of parsing, and the output are objects of AST classes. So I basically made a function which creates ASTs from what Team 1 passes to our Team 2.
Next week I will work on the function which draws different shapes.
#### Elena Mrdja
This week was one of the most important ones for the GUI team. Mina, John and I improved the Viewer and merged our work this week. 
The main task was to enable the QGraphicsScene so that we can draw multiple shapes with the desired coordinates in the Viewer, which we accomplished successfully.

#### Matea Gjika
This week I worked on the cache again. As we reach the final stages of the project, after many discussions with the backend teams, we realised that we needed the cache to have different functionalities, due to changes made to the code by other team members. The format of the cache that we agreed on now is very similar to the last iteration. It involves storing an array of pointers to maps , where the key is a Variable* and the value is a ValueList. ValueList is a class that will store the list of values of every variable. Every dictionary will store the current values of the variables declared up to and including its respective line. Most of these lists will only have 1 node per variable, however in the case of while loops, the variables will be updated more than once, but while loops still correspond to only one line numbers. So the linked list will allow us to traverse the values and print the next one when the button is clicked. 
I have been working with Mina, Elena and Milena on merging the code, specifically regarding the variable tracking methods, which is why I have had to update the cache so many times, in order to match the necessary functionalities that we need in the end. One of the biggest problems we faced was the while loop, and all of the updates to the cache were generally related to finding a way to store the values of the variables as they go through the while loop. 
During our discussions for the while loop we decided that it would be a good idea to write a method that deals with walking the while loop in the While class. This method will evaluate the condition and update the cache at each iteration. This will make the process a lot cleaner and easier to edit later on. Once all the classes are finalised and the walker is completer, I will then go in and update all of the functions to update the cache.

#### Mina Goranovic
As project leader, I made sure that AST team has the output needed for the Interpreter team to start merging. I decided with Milena on the structure GUI team will use for shapes drawing and the variable tracking. 
As part of the GUI team, I made DiagramScene and GraphicsView work with Elena and we fixed some pointer issues we had to visualize shapes on Viewer widget. Then, I tested some visualization to make sure I understand the way coordinate system works in QtGRaphics.

#### Ekaterina Borisova 
This week our team has made a major break through. During the week our team was working on making sure that the main classes are ready for merging and by the end of the week we have managed to meet our goal and implement all the classes need for simple merging. Personally, in the begining of the week I have been working on modifying Assign and Declaration classes which would include modifying Statement and Block classes as they are the parent and most essential classes. Then in the middle of the week we faced a huge problem with ANTLR, since on Tuesday evening it stopped working and we couldn't find the reason for it for two days, which in the end was the change that was done on ANTLR github. So on Thursday we manage to fix ANTLR and so we made sure that it works on every computer of our subteam, which was not done before this week. Finally, since Mina was asking to finish more classes before the end of the week, I picked Expression and BinOp to modify and implement. Therefore, by the end of Suncday we have all essential classes finished and on the next week we will continue to modify and add some tools to existent classes and we will implement less essential but also important classes such as print and arraytype.
#### Stefan Vayl
This week I worked on adoptation and fixing of classes I already implemented. At the begining of the week we realized that we need to extend our classes in order to add more functionality. So, I modified the code I've already implemented. Since our team already modified most of vital classes we are planning to continue our work on implementation of AST and hopefully we will succeed this week.
#### Virgile Martin 
This week, with team 1, we have made a lot of progress. First of all, we finally managed to fix the ANTLR4 compilation problems. I personally spent hours and hours trying to find the error or errors that prevented the program from working properly. In the end, not much was missing to make it work, just a line of code in the middle of the rest to add... Afterwards, we continued with the implementation of our classes, and more personally with the While Loop. We also had to create tests to check that the functions of our classes were returning what we wanted. Finally, I wrote a document that explains each function of the classes already implemented, so that each member of the project can understand what we did.
#### Elsa Bismuth
This week, I worked with Katia to finalize the classes. I mainly worked on the « Return » class. Indeed, after talking with Team 2, we had to modify the classes. It was hard to put everything together and merge all the classes to make the process work from the beginning to the end, because some classes depended on others, such as Expression and BinOp. I tried the Return class on different examples to be sure that it worked. The goal for next week is to finalize the project and make sure every class works well. Finally, we will merge everything together by finalizing the AST.
