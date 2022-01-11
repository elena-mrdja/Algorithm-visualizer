## Functionalities

    - What will your project do, precisely?

Algorithm Visualizer will be a tool where user will be able to input C++ code in the code cell and get the flowchart visualization of the execution of it. The graphics interface will have Code cell, Viewer cell and a tool bar. Our project will allow the user to see line by line the evolution of his code execution and observe the state of variable values at each line.

## Deadlines and deliverables

    - What intermediate deadlines do you have, and what subset of functionalities will you deliver in each deadline?

* Week 1:
    * Virgile - Research on AST and parsing. Make sure you understand the task of your team throughout the project and get familiar with the process.
    * Elsa - Research on AST and parsing. Make sure you understand the task of your team throughout the project and get familiar with the process.
    * Stefan - Research on AST and parsing. Make sure you understand the task of your team throughout the project and get familiar with the process.
    * Matea - Research on AST. Make sure you understand the task of your team throughout the project and get familiar with the process.
    * Dasha - Research on AST. Make sure you understand the task of your team throughout the project and get familiar with the process. 
    * Evdokia - Research on AST. Make sure you understand the task of your team throughout the project and get familiar with the process.
    * Elena - Make Github repository, teach other team members on how to commit, pull and push. Start doing the QT Graphics course. 
    * John - Start doing the QT Graphics course.
    * Katia - Research on AST and parsing. Make sure you understand the task of your team throughout the project and get familiar with the process, decide with Mina which library to use for the parsing. Agree on grammar we will use (talk to Mina)
    * Milena -  Research on AST. Make sure you understand the task of your team throughout the project and get familiar with the process. Agree on grammar and tokens we will use (talk to Mina). Figure out the global inheritance of classes and organization of the grammar (hyperclasses and child classes, talk to Mina).
    * Mina - Find the course on QT Graphics, find library to use for parsing (talk to Katia), define grammar and tokens we will use. Make sure people have material to start getting familiar with the backend process of the project (parsing, tokenization, AST creation and construction of interpreter)
    

    
* Week 2:
    * Virgile - Work on the ANTLR library and its implementation. Write test functions we will further use to test our library output.
    * Elsa -  Work on the ANTLR library and its implementation. More precisely, understsnd the ANTLR .g4 syntax and use predefined grammar from Github to make our own parsing and lexing files.
    * Stefan -  Work on the ANTLR library and its implementation (together with Katia).
    * Matea - Start tackling different problems and challenges you will have in your part of the project. Finish the resesrch so that you are thooretically backedup for the implementation. Write setter and getter funcitons.
    * Dasha - Start tackling different problems and challenges you will have in your part of the project. Finish the resesrch so that you are thooretically backedup for the implementation. Write setter and getter funcitons.
    * Evdokia - Start tackling different problems and challenges you will have in your part of the project. Finish the resesrch so that you are thooretically backedup for the implementation. Write setter and getter funcitons.
    * Elena - Finish the Qt graphics course, decide with John and Mina the shapes we will use and exact look of the interface. 
    * John - Finish the Qt graphics course, decide with John and Mina the shapes we will use and exact look of the interface. 
    * Katia - Work on the ANTLR library and its implementation (together with Stefan).
    * Milena - Start tackling different problems and challenges you will have in your part of the project. Finish the resesrch so that you are thooretically backedup for the implementation. Write outline of the functions.
    * Mina - Finish the Qt graphics course, decide with John and Mina the shapes we will use and exact look of the interface. Find documentation and sources for ANTLR installation and use. 

* Week 3:
    * Virgile - Work on the ANTLR library and its implementation. Fix the buggs in the test files.
    * Elsa - Work on the ANTLR library and its implementation. More precisely, understsnd the ANTLR .g4 syntax and use predefined grammar from Github to make our own parsing and lexing files.
    * Stefan - Try to have working ANTLR by the ned of the week (very important). Split tasks with Katia.
    * Matea - Take time to understand and work on the variable tracking. Understand what GUI team will be using and start working on the cache function.
    * Dasha - Write a type_check fucntion for every enumeration type in our classes.
    * Evdokia - Write a get_type and get_subtype() fucntions. 
    * Elena - Work on the ViewCell, define shapes (with Mina). Make better organization of the Github.
    * John - Figure out how to make a TextEditor cell (which is quite a challenge). Figure out the color code and lines counter.
    * Katia - Try to have working ANTLR by the ned of the week (very important). Split taks with Stefan. Make the library work with already existing grammar files and test for our own grammar. 
    * Milena - Finish the classes. Start communicating with GUI and Pasrsing team to start having a better picture of the merging points.
    * Mina - Make our Cells scrollable and ifugre out how to comfortably use PushButton on click. Make sure that the .g4 grammar files are ready to be tested and that they work on ANTLR.
    
* Week 4:
    * Virgile - Take signatures of classes Block, Statement, ArrayType and prepare them for the AST implementation. Make ANTLR functional on your computer (work on this with Katia).
    * Elsa - Take signatures of classes Print, Return, Assign, VarDec, Type and prepare them for the AST implementation. Make ANTLR functional on your computer (work on this with Katia).
    * Stefan - Take signatures of classes While, Ifelse, Ifrest and prepare them for the AST implementation.
    * Matea - Do the cachce class to be able to track and store the variables and their values.
    * Dasha - Work on expression values.
    * Evdokia - Do the cachce class to be able to track and store the variables and their values.
    * Elena - Seek for better solutions other than parametrized shapes. Fix all the bugs in the code snd merge ViewCell with the rest of GUI.
    * John - Merge the TextEditor with other components of the GUI (work with Elena and Mina).
    * Katia - Take signatures of classes BinOp, UnOp, Jump, BoolType and prepare them for the AST implementation. Be available for ANTLR installation.
    * Milena - Organize the work in the subteam. Template the classes (and talk to the professor about this idea).
    * Mina -  Seek for better solutions other than parametrized shapes. Fix all the bugs in the code and merge CodeCell and PushButtons with the rest of GUI.  

* Week 5:
    * Virgile - Finish tasks from the last week.
    * Elsa - Finish tasks from the last week.
    * Stefan - Finish tasks from the last week.
    * Matea - Finish tasks from the last week.
    * Dasha - Work on the AST walker with a model of AST you will get.
    * Evdokia - Work on getting values of BinOp and UnOp expressions. Find alternative for templating..
    * Elena - Start wokring on the Diagram Scene.
    * John - Update the TextEditor so that is has matching opening and closing parenthesis. Make indentation smaller and make it respect the previous line (also try  to make automatic indentation when needed (for example after main, while etc)).
    * Katia -  Work on including all the classes made into CMakeLists.txt file and making sure that it compiles with ANTLR library. Start mergin with Milena and Mina.
    * Milena - Start mergin with Katia and Mina.
    * Mina - Fix the layout of the GUI. Reorganize teams a little bit (get some help to the Perse team) and make sure Backend teams start collaborating closely. 

* Week 6:
    * Virgile – Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make while class work (a must: talk to Milena and Katia for help and for discussing). Make documentation of funcitons for team 2.
	* Elsa - Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make Return (urgent) and work on Exp (BInOp priority) (a must: talk to Milena and Katia for help and for discussing)
	* Stefan - Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make Ifelse and Ifrest classes work (after return) class work (a must: talk to Milena and Katia for help and for discussing)
	* Matea – AST walker (a must: talk to Milena and Katia and with Dasha and Evdokia; communicate to the GUI team what you are giving them and make sure they actually do get what they need.)
	* Dasha – AST walker (a must: talk to Milena and Katia and with Matea and Evdokia; same as Matea)
	* Evdokia – variable tracking (communication very important! You already know how get_value() works, read Cache and ask Matea about it; then while the walker is being made you need to think about how to add tracking. So you have to work together a lot)
	* Elena – figure out Diagram Scene and make it work. Fix the Github organization (work with Mina)
	* John – Finish the text editor (by Tuesday meeting) and make a function that takes a current code from the text editor and convert it into a file.
	* Katia – make VarDec, Assign, Block, Stmt, work with Elsa on Exp and BinOp.
	* Milena – merge Assign class + as many others as possible
	* Mina - make Diagram Scene work with Elena, make very clear mergin interfaces (Milena and Katia help). Make sure Github organization is fixed (work with Elena).
	
* Week 7:
    * Virgile - Jump, UnOp classes
    * Elsa - Negation, Print claases 
    * Stefan - ArrayType (start upgrading our grammar)
    * Matea -  Finish new cache, write function that reads while, add tracking to walker.
    * Dasha - Merge backend with Milena.
    * Evdokia - Write a function that reads Ifelse.
    * Elena - Test the variableTracker cell for VarDec, Assign, While and If/else. Find a solution for nested loops (work with John).
    * John - Figure out how to position text in shapes. Implement lines to connect shapes (while/if special challenge work with Elena).
    * Katia - Do the AST class, make sure other team members are respecting the deadlines. Work on merging the textEditor with Mina. Fix the bug with childrensize in block with Elsa.
    * Milena - Merge backend.
    * Mina - Write all of the limitations of our porgram for the user. Write down the ANTLR guideline in the README. Test the shapes drawing. Merge text editor with Katia and test.
 



## Software Architecture

    - How are you sub-dividing your project? Which modules are you implementing?

We will have one team working on making the parser. Basically, this team will, in the first stage of the project define initial tokens and “grammar” we will use. With help of the library, they will allow the lexical analysis of the code typed by the user (that will have restrictions we will talk later about). After making the parser, this team will work on creating an AST structure.

    - What is the interface of each module?

 You can define the interface with the public section of your class headers (note that not all classes need to be "exposed" from one module to the others).

    - What external dependencies do you have? Why?

We will use the ANTLR4 library during the lexing and parsing process and for now that seems to be the only external dependency we have.

## Initial grammar we defined:

* < file > = ‘’’ < libray > < main >‘’’ 
* < main > = ‘’’ INT MAIN LP RP <block> ‘’’ 
* < block > = ’’’LCB < stmts > RCB ‘’’
* < stmts > = ‘’’ < varDec > |< assign > |< print > |< while > |< jump > |< ifelse > |< return > | < exp > SEMICOLON | < library >‘’’
* < varDec > = ‘’’< type > < variable > EQ < exp > SEMICOMMA’’’
* < type > = ‘’’ | INT | BOOL | STR | DOUBLE ’’’
* < assign > = ‘’’VAR EQ < exp > SEMICOLON’’’
* < while > = ‘’’WHILE LP < exp > RP <block>’’’
* < ifelse > = ‘’’IF LP < exp > RP < block > < ifrest >’’’
* < ifrest > = ’’’ELSE < block > |ELSE < ifelse >‘’’ 
* < jump > = ‘’’  CONT | BREAK ’’’
* < return > = ‘’’RETURN < exp > SEMICOLON’’’
* < exp > = ‘’’< integerType > | < doubleType >| < boolType >| < string >| LP < exp > RP| < exp > < binOp > < exp > | < unop > < exp >| < exp > < unop >| < negation > | < variable >‘’’   
* < negation > = MINUS < exp >
* < boolType > = TRUE| FALSE
* < binOp > =  PLUS | MINUS | TIMES| DIV | MOD | XOR | XAND | EQQ | NOTEQQ | LT | MT | LEQ | MEQ
* < unop > = PLUSPLUS | MINUSMINUS





