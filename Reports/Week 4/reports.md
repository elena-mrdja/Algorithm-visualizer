# Week 2 - Reports

#### John Levy 
This week, I kept going with the goals set from the previous work that had been done within the GUI team. The first part of the week was dedicated to merging together the different parts of the mainwindow on which we had worked independently. We encoutered a lot of issues with this but we managed to entirely fix all the bugs. I was then able to implement the rich text editor inside the main window of the project. 
New week, my personal focus will be to finish the details of the code editor (highlighting colors, background color, indentation, etc…). I believe we will also have a meeting within the GUI team to decide on the next steps. A goal for next week could be to start being able to visualize some very simple code, like variable declaration and basic arithmetic operations on these variables.

#### Elena Mrdja
This week, I mostly dealt with debugging the current code we had, until the main window was able to compile and start working. Together with John, we discovered that the problem with building our project wasn't coming from our code but rather from the 
names of our custom classes which interfered with widget names. Once we noticed that we were able to debugg and continue with work. Simuntaniously, I was working on making the QGraphincsScene library work in our project,
but I faced some issues with the UI class which was made automatically when the project was created. One of the biggest successes of the week was finding and starting to implement the QDiagramScene class which would make it possible to connect our shapes with arrows in an easier and more dynamic way.
My biggest goal for next week is to fully implement and test the DiagramScene. In the end of the week I met with Mina and Milena to discuss the connection between the Interpreter and GUI, we agreed on the output the Interpreter team would give us, and we will be able to start connecting with the Interpreter at the end of this week.

#### Darya Todoskova
This week, there was a lot of “testing” code : I would write code then realize what is necessary and what should be modified/erased depending on the decisions we make with other teams. This is expected since we’re all discovering and learning from our “mistakes”. For instance, I modified certain classes (binop and unop) to get the values of expressions, but will have to change it’s more efficient to make them templates. The code still needs adjustements, which I have been working with Milena on. I also continued looking at how to implement a walker to go through the AST that Team 1 will hand over. And this week’s goal is for me to implement it, which will take some time. The walker is what the GUI team needs to access all that we have been working on in the backend.

#### Evdokia Gneusheva
This week I mainly worked on the problem of keeping track of variables. I worked on the implementation of Cache class in collaboration with Matea. We added methods to the classes Assignment and UnOp for changing and/or adding values of the variables in Cache. 
Next week I will continue working on the interpreter methods for the lowest classes.

#### Matea Gjika
This week I worked on designing a cache class. We decided that creating a class was more efficient to just using a dictionary, because it would allow us to manipulate and extend the arrays stored in the dictionary much more efficiently. I wrote methods to add a new variable, as well as store a new updated value of the variable. To do that, I also had to create a function to extend the arrays when need be. The cache will be passed by reference to 4 other classes. The next step will be to use templating to create the arrays, as we want to create templates for every variable.
This week I also have to figure out how to walk the AST and track the changes of the variables.

#### Mina Goranovic
This week I was mostly involved with GUI team. We had a problem with the layout so I changed the layout organization on the main window and made it fullscreen. I started working on the pushButton  to already try to visualize some simple programs, but we had some bugs with Qt which we haven’t fixed yet with Elena.  Elena discovered a library that could solve our shapes merging challenge, and we are currently trying to implement it. John merged the text editor he was working on, but now we are solving some other problems such as make indentation smaller,  respect the indentation level of the previous line, color code, automatic closing brackets etc. 
As the team leader, I fixed goals with sub-teams for next Thursday so that we can make first merged visualization from the very beginning. I made sure sub team leaders are ready for this next step and that they have the internal organization inside of their teams.
Next week, big challenge will be to merge all three components from parsing to visualization for VarDec and Assign classes.

#### Ekaterina Borisova 
Throughout this week our team has been working on creating classes for AST for all the types defined in grammar. On Tuesday evening I called a meeting in order to go through the tasks and the goal of the week and during that meeting we have equally split the work between each team member. I have personally taken the classes: BinOp, UnOp, Jump, BoolType and negation. We have all managed to complete the classes we have chosen so now I am working on including all those files into CMakeLists.txt file and making sure that it compiles with ANTLR library. The goal for the next week would be to create the parent AST class which would link all the classes created this week and making sure that it outputs AST the way needed for Team 2 to analyse it.

#### Stefan Vayl
This week, as we finished implementation of ANTLR library I started to work on converting parsing tree which outputs ANTLR to AST. In particular I've studied which opportunities ANTLR gives us for traversing parse tree and using self-generated methods I found out how to actually traverse tree, call different nodes and return particular values. Further, I started implementation of AST by creating classes for some key-statements like while, if, else and etc. Later this will allow us to construct whole AST. This week I am planning to finish implementation of some more sub-classes and then start working on construction of AST.

#### Milena Nedeljkovic
This week I started templating Expression and its subclasses; the goal for next week is finishing the templates and working on the interpreter.

#### Virgile Martin 
This week I have been working on the classes that will help us turn a Parse tree into an AST. Personally, I had to implement the Block, Array and Statement class. However, I also did the Return class after a misunderstanding. I also spent the week trying to sort out some compilation problems. Once the classes are finished, with Team1, we will start to transform the Parse tree into AST.

#### Elsa Bismuth
This week, we had a meeting with Team 1 to define the classes we needed to code for the AST. Then, we divided the classes among us. I defined the classes expression, declaration, assignment, type, print and return. Then, after checking with Katia, we started to put everything in common with Team 1 to create the AST. The goal for next week is the finish the construction of the AST.
