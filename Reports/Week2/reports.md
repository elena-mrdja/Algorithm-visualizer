# Week 2 - Reports

#### Elena Mrdja
This week I worked on grasping all the necessary knowledge in Qt graphics we will need. As planned, I finished the Qt Graphics course we found, and I implemented the gathered skills through making a trial project where I created a main window with different shapes and their class methods, which will be of great help as I progress with coding the project.
After everyone in GUI team was done with the course, I set up a meeting to decide on all the custom classes and the shape types we want to have in our project. When this was decided, I started coding the main window of our project's GUI, adding the classes and creating a simple structure we plan to build upon next week. Next week our goal is to finish the text editor cell and implement all the shapes we decided to use.
As the git leader, I created a tutorial document with all of the important git hub commands, so that everyone was sure on how to use it, and was there to help my teammates out with any git hub problems.

#### Matea Gjika

This week was dedicated to research. Since this is a complex project, where we need to build a parser and interpreter and learn about multiple libraries and complex data structures, it is very important for everyone to take some time to study and understand the main principles. I had 3 jobs this week: research a parses, research the antlr library, and research parser trees. 
The first resource I studied was a 19-part article “Let’s build an Interpreter”, which walks you through parsing, tokenising, grammars, parser trees and ASTs. I have completed 8/19 parts, so my goal is to finish this series by Tuesday.
I also browsed the ANTLR documentation, and looked at some functions that specifically deal with parser trees. 
The next step is to start building the AST classes and methods with the rest of my team.
The first resource I studied was a 19-part article “Let’s build an Interpreter”, which walks you through parsing, tokenising, grammars, parser trees and ASTs. I have completed 8/19 parts, so my goal is to finish this series by Tuesday.
I also browsed the ANTLR documentation, and looked at some functions that specifically deal with parser trees. 
The next step is to start building the AST classes and methods with the rest of my team. After a team meeting, we started to work on our AST classes. I was tasked with writing the setter and getter functions, as well as editing the classes that inherited from the Statement file found under ast.hpp.


#### Elsa Bismuth

This week, I deepened my knowledge in ANTLR and tokenization by doing some research on internet. I defined more in details the grammar and I started to code the first token. Next week, I will try to finish to code the first 2 tokens.

#### Virgile Martin 

This week I worked on the implementation of tests to understand and verify that our library works. This also allows us to check the different functionalities of the library and what it returns. I created different tests of different complexity. The goal is to have the library 100% functional by the end of the week.

#### Milena Nedeljkovic
Things done this week:
- more research on ANTLR, we will use Visitor to walk through the parsing tree
- definiton of the class AST
- distributed the work for filling up already defined classes to the team (they are only outlined; I didn't write setters or getters,
and we all need to give input into which attributes we need)


#### Darya Todoskova
During the second week, I did a more profound research on ANTLR, in order to know what output we will be receiving from Team 1. I also met a couple of times with my team to discuss our progress and to define specific tasks for each one of us to do. Indeed, I defined all the AST-inherited getters and setters in the ast.hpp file. Finally, I am currently trying to set up ANTLR on mac0S just like team 1, who has been trying to set it up on Windows. For the following week, I plan on refining our ast.hpp file and working on the exact output we are going to give to the GUI team, in order to make the transition smoother.

#### Evdokia Gneusheva

This week Team 1 came up with the idea to use ANTLR library for parsing so as a member of Team 2 my job was to get familier with this library in order to be able to convert parser trees created by Team 1 into AST. Precisely, to convert a parser tree into AST we need to use ANTLR4 visitor. Thus, I accomplished an online tutorial on how to use visitor class. But also, the most importantly, Team 2 started defining AST by creating multiple classes in ast.hpp file (on Workspace branch), where I coded set() and get() methods for all classes inherited from Expression class.  
Next week I will continue working on AST classes and start the conversion of parser tree created by Team 1 into AST, as well as working on the output of our AST which we will pass to the Team 3.

#### Stefan Vayl
Throughout the whole week I have been working on installation of ANTRL library. I have managed to install it on my computer even though there were many difficulties that I had to face. I managed to test this library on small grammar files that I found online. From those grammar files it created Lexer and Parser files. Although, there is still work to be done next week especially I am planning to find out how can I be using those automatically generated files in order to create parsing tree.

#### Ekaterina Borisova

This week I have been working on installing ANTRLv.4 library. There were many ideas on how we should be implementing our backend but in the end we came to an understanding that ANTRL library should work well for our project. I have managed to install it on my computer and try to run it on different libraries including a C++ library. I have found some grammar files that I can use for testing and from which I managed to create tokens using the library. Next week I am planning to get better understanding on how to use this library in order to create parsing tree because right now I am struggling to get it.

#### Mina Goranovic
This week I found us resources and tutorial for antlr library the parsing team will use. I downloaded all of the needed setup for the library, but it is still not working. What I need to do next week is to learn how to get the graph output of the parse tree instead of the graphical representation. 
Next, I finished the course on the Qt graphics and decided with the GUI team on how we want our main window to look like.
I made us a grammar file for parsing. 
For next week I need to find out how exactly we will make an interpreter from AST that we will connect to flowchart elements.


#### John Levy 
