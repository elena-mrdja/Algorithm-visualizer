# Week 2 - Reports

#### John Levy 
This week my focus was mainly on getting the Code Editor cell to completely work in a seperate project from our main window. 
The TD on Thursday was completely dedicated to understanding and implementing the QSyntaxHighlighter class and main function highlighBlock(). 
Although I faced a couple issues, they have all been solved now, so next week I will implement the code cell in the main window code of the project and I will add some features and upgrades the one I have already made. 
I will also meet with the GUI team to know what is the next important step in the project.

#### Darya Todoskova
This week, I managed to achieve my expected goals. I added basic methods to our classes in ast.hpp. Indeed, I did a type_check for every enumeration type in our classes. I also managed to set up ANTLR on macOS and visualize the files it generates for us (lexer and parser). Together with some teammates, I am also currently looking into methods to walk through the AST (useful for the transition to the GUI team). For this coming week, I plan on adjusting the ast.cpp file by adding constructors for our Statement classes (for when a dictionary is passed by reference as an argument to it). I also have to work with my teammates to work on the tests and the interpreter that the GUI team will need.

#### Evdokia Gneusheva
This week I implemented an abstract method get_type() in our hyper class AST in ast.hpp file (branch: Workspace) which I defined in subclasses of  AST - Statement and Expression. Similary, I implemented get_subtype() defined in sub-subclasses of Statement and Expressions. get_type() checks if an object is of type Statement or Expression. Then, get_subtype() checks if this object is of type Block, or Declaration, or Binary operation, and etc. This will be used by GUI Team; knowing the type of an object they work with will be decisive for their following steps. I also fixed the syntaxe of Inheritance of classes in ast.hpp file and added the class Decision so that IfElse and While subclasses could be inherited from Decision class.
Next week I will work on the interpreter and tests for GUI Team.

#### Elena Mrdja

#### Matea Gjika
On Monday, I met with the project leader to update and organise the Trello tasks for the week. We also discussed different features that could be implemented. My first task for the week is to write functions that use the AST to keep track of the changes to variables. In order to do this, I first implemented a private variable cache, which is a dictionary that stores the name of the variables as a string and an array of the values. This cache will be used by classes that change the value of variables, namely: Block, Declaration, Assignment, UnOps, so I created a sample constructor for Block, in which the cache is passed by reference, so that all of these variables amend the same dictionary. Milena will implement the constructors for the remaining classes. 
On Thursday, I worked on separating the classes we constructed for the project into individual files. As we were coding, we noticed a lot of git conflicts, so breaking down the classes seems to be the best option to give everyone room to work. Then I did some research on implementing the variable tracking feauture.
This week I have to implement the AST walk and variable tracking features.


#### Mina Goranovic
As part of GUI team, this week I make our widgets scrollable and we defined with Elena the look of our flowchart shapes. Before we start merging, we will start working on functions for recognizing and connecting shapes with the AST interpreter.
As the team leader, I reorganized a little bit the structure of the teams. This means that the second team lead by Milena will work on the interpreter from now and the first team, lead by Ekaterina, will (after successfully maiking the ANTLR Library work) use the visitor class to make the AST. This way, first team has more work to do before we start merging and the second team can already start working on the interpreter. Also, as we wanted to have our own predefined grammar, we spent some time this week on making that happen. I wrote .g4 files which we debugged later on with Ekaterina and Elsa and made them work accordingly with the library. Next week, my main goal is to make sure every team finished their individual tasks and that we can start merging


#### Elsa Bismuth



#### Virgile Martin 

#### Milena Nedeljkovic



#### Stefan Vayl

#### Ekaterina Borisova



