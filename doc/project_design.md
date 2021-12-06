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
    * Virgile -
    * Elsa -
    * Stefan -
    * Matea -
    * Dasha - 
    * Evdokia - 
    * Elena - 
    * John - 
    * Katia - 
    * Milena - 
    * Mina - 

* Week 3:
    * Virgile -
    * Elsa -
    * Stefan -
    * Matea -
    * Dasha - 
    * Evdokia - 
    * Elena - 
    * John - 
    * Katia - 
    * Milena - 
    * Mina - 
    
* Week 4:
    * Virgile -
    * Elsa -
    * Stefan -
    * Matea -
    * Dasha - 
    * Evdokia - 
    * Elena - 
    * John - 
    * Katia - 
    * Milena - 
    * Mina - 

* Week 5:
    * Virgile -
    * Elsa -
    * Stefan -
    * Matea -
    * Dasha - 
    * Evdokia - 
    * Elena - 
    * John - 
    * Katia - 
    * Milena - 
    * Mina - 

* Week 6:
    * Virgile – Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make BinOp classes (do first) and UnOp class work (a must: talk to Milena and Katia for help and for discussing)
	* Elsa - Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make Return (urgent) and While (after return) class work (a must: talk to Milena and Katia for help and for discussing)
	* Stefan - Setup the ANTLR on your computer so that you can write classes and test the code (by Tuesday meeting). Make Expr, Ifelse and Ifrest classes work (after return) class work (a must: talk to Milena and Katia for help and for discussing)
	* Matea – AST walker (a must: talk to Milena and Katia and with Dasha and Evdokia; communicate to the GUI team what you are giving them and make sure they actually do get what they need.)
	* Dasha – AST walker (a must: talk to Milena and Katia and with Matea and Evdokia; same as Matea)
	* Evdokia – variable tracking (communication very important! You already know how get_value() works, read Cache and ask Matea about it; then while the walker is being made you need to think about how to add tracking. So you have to work together a lot)
	* Elena – figure out Diagram Scene and make it work. Fix the gitHub organization (work with Mina)
	* John – Finish the text editor (by Tuesday meeting) and make a function that takes a current code from the text editor and convert it into a file.
	* Katia – merge Assign class + as many others as possible 
	* Milena – merge Assign class + as many others as possible
	* Mina - merge Assign class + as many others as possible, do Diagram Scene with Elena, make very clear interfaces (Milena and Katia help)
	
* Week 7:
    * Virgile -
    * Elsa -
    * Stefan -
    * Matea -
    * Dasha - 
    * Evdokia - 
    * Elena - 
    * John - 
    * Katia - merge Expr, While, Ifelse, Ifrest, Binop, Unop
    * Milena - merge Expr, While, Ifelse, Ifrest, Binop, Unop
    * Mina - merge Expr, While, Ifelse, Ifrest, Binop, Unop
 



## Software Architecture

    - How are you sub-dividing your project? Which modules are you implementing?

We will have one team working on making the parser. Basically, this team will, in the first stage of the project define initial tokens and “grammar” we will use. With help of the library, they will allow the lexical analysis of the code typed by the user (that will have restrictions we will talk later about). After making the parser, this team will work on advanced functionalities and potentially help GUI team.

    - What is the interface of each module?

 You can define the interface with the public section of your class headers (note that not all classes need to be "exposed" from one module to the others).

    - What external dependencies do you have? Why?

We will use a library during the lexing process and for now that seems to be the only external dependency we have.

## Initial grammar we defined:

* < program > = ‘’’ INT MAIN LP RP <block> ‘’’ 
* < block > = ’’’LCB < stmts > RCB ‘’’
* < stmts > = ‘’’ < varDec > < stmts > |< block >  < stmts > |< assign > < stmts > |< print > < stmts > |< while > < stmts > |< jump > < stmts >  |< ifelse > < stmts > |< return > < stmts > | ‘’’
* < varDec > = ‘’’< type > VAR ASSIGN < exp > SEMICOMMA’’’
* < type > = ‘’’ | INT | BOOL | STR | DOUBLE ’’’
* < assign > = ‘’’VAR EQ < exp > SEMICOLON’’’
* < while > = ‘’’WHILE LP < exp > RP <block>’’’
* < ifelse > = ‘’’IF LP < exp > RP < block > < ifrest >’’’
* < ifrest > = ’’’|ELSE < block > |ELSE < ifelse > | ‘’’ 
* < jump > = ‘’’ | CONT| BREAK ’’’
* < return > = ‘’’RETURN < exp > SEMICOLON’’’
* < exp > = ‘’’|VAR |TRUE |FALSE |LP < exp > RP |< exp >  < binop > < exp > |< unop > < exp > | < exp > < unop >‘’’    



