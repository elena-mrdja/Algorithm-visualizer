# Week 2 - Reports

#### John Levy 
This week my focus was mainly on getting the Code Editor cell to completely work in a seperate project from our main window. 
The TD on Thursday was completely dedicated to understanding and implementing the QSyntaxHighlighter class and main function highlighBlock(). 
Although I faced a couple issues, they have all been solved now, so next week I will implement the code cell in the main window code of the project and I will add some features and upgrades the one I have already made. 
I will also meet with the GUI team to know what is the next important step in the project.

#### Elena Mrdja
This week I organized and divided the tasks for the GUI team, every member was given a task which we all successfully finished. I was in charge of making the cell where the visualisation of algorithms happens, the Viewer cell. I finished all the class types and methods needed to visualize our main shapes and added them to the Viewer. I was also able to fix bugs we had while using Qmainwindow class, which is crucial for continuing with the project. Now that the Viewer cell is mainly finished, the goal for the next week is to start connecting the shapes with the AST interpreter and to make methods for connecting different shapes into a flowchart. .

#### Darya Todoskova
This week, I managed to achieve my expected goals. I added basic methods to our classes in ast.hpp. Indeed, I did a type_check for every enumeration type in our classes. I also managed to set up ANTLR on macOS and visualize the files it generates for us (lexer and parser). Together with some teammates, I am also currently looking into methods to walk through the AST (useful for the transition to the GUI team). For this coming week, I plan on adjusting the ast.cpp file by adding constructors for our Statement classes (for when a dictionary is passed by reference as an argument to it). I also have to work with my teammates to work on the tests and the interpreter that the GUI team will need.

#### Evdokia Gneusheva
This week I implemented an abstract method get_type() in our hyper class AST in ast.hpp file (branch: Workspace) which I defined in subclasses of  AST - Statement and Expression. Similary, I implemented get_subtype() defined in sub-subclasses of Statement and Expressions. get_type() checks if an object is of type Statement or Expression. Then, get_subtype() checks if this object is of type Block, or Declaration, or Binary operation, and etc. This will be used by GUI Team; knowing the type of an object they work with will be decisive for their following steps. I also fixed the syntaxe of Inheritance of classes in ast.hpp file and added the class Decision so that IfElse and While subclasses could be inherited from Decision class.
Next week I will work on the interpreter and tests for GUI Team.

#### Matea Gjika
On Monday, I met with the project leader to update and organise the Trello tasks for the week. We also discussed different features that could be implemented. My first task for the week is to write functions that use the AST to keep track of the changes to variables. In order to do this, I first implemented a private variable cache, which is a dictionary that stores the name of the variables as a string and an array of the values. This cache will be used by classes that change the value of variables, namely: Block, Declaration, Assignment, UnOps, so I created a sample constructor for Block, in which the cache is passed by reference, so that all of these variables amend the same dictionary. Milena will implement the constructors for the remaining classes. 
On Thursday, I worked on separating the classes we constructed for the project into individual files. As we were coding, we noticed a lot of git conflicts, so breaking down the classes seems to be the best option to give everyone room to work. Then I did some research on implementing the variable tracking feauture.
This week I have to implement the AST walk and variable tracking features.


#### Mina Goranovic
As part of GUI team, this week I make our widgets scrollable and we defined with Elena the look of our flowchart shapes. Before we start merging, we will start working on functions for recognizing and connecting shapes with the AST interpreter.
As the team leader, I reorganized a little bit the structure of the teams. This means that the second team lead by Milena will work on the interpreter from now and the first team, lead by Ekaterina, will (after successfully maiking the ANTLR Library work) use the visitor class to make the AST. This way, first team has more work to do before we start merging and the second team can already start working on the interpreter. Also, as we wanted to have our own predefined grammar, we spent some time this week on making that happen. I wrote .g4 files which we debugged later on with Ekaterina and Elsa and made them work accordingly with the library. Next week, my main goal is to make sure every team finished their individual tasks and that we can start merging

#### Ekaterina Borisova

During this week, I continued working on implementing the ANTLR4 library such that it configures the project in C++. Moreover I had lot’s of problems and researches on how to make CMakeLists.txt file work for cmake since in the process of implementing the library I found out that ANTLR library works only with the cmake. By Wednesday night I have managed to make the library work and we got our first Parse Tree. However, when doing my testing I was using the open source grammar for C++ and so since for the project we want to use our own library, the second half of the week I have been working on integrating the grammar that Elsa and Mina created into our project. In the end, I am happy to admit that by the end of the week, we have a fully working ANTLR4 library and as an output we get a well constructed Parse Tree. The targets for the next week are to implement a class that will convert Parse Tree into AST. As a sub leader of Team 1, I will split the work between all the members of our subgroup such that everyone will get a class/ classes to work on.

#### Stefan Vayl

During this week, I have been first working on implementing the ANTLR4 library. In the end I have managed to make it work for java, which was later used by Ekaterina in order to set the library up running for the C++. The rest of the week following the tasks given, I have been researching on how to convert Parse Tree into AST. I have found some useful open source projects which gave a proper understanding on how to make this working for our project. So during the upcoming week, I will be concentrated on working with my team on converting Parse Tree into AST.

#### Milena Nedeljkovic
This week wes dedicated to finalizing the AST classes so that they are ready to be used. OUr work had to be manually merged which me and Matea finished at the TD.
We now have a good basis to conitnue working on the interpreter. I communicated with the GUI team about creating test ASTs.
Writing the interpreter and the tests are the main goals for my team for the next week.
Creating the AST from the parsing tree wes handed over to Team 1 and I have their group leader the explanation of our classes.

#### Virgile Martin 
This week I have been working on two things. The first thing was to finish the tests for our programme. There was an error with the "std::cin" function that I couldn't solve, so I had to ask my teachers for help and they explained that there was a problem with Qt creator. Then I joined Katia and Stefan in the part where we have to transform the Parse Tree into AST. This part being quite complicated, our work was mainly documentation to understand how it worked. We found some interesting articles that will help us a lot. Finally we had a meeting to collect our ideas and talk about what we will do next week.

#### Elsa Bismuth
This week, I completed the grammar file done by Mina, and then debugged it with her. Those files then generated a Lexer and a Parser, that were integrated to our program by Katia. Then, with team 1, we did a research on AST, so that we could transform the parse tree into AST using ANTLR librairy. For next week, I will implement at least one class for the AST.
