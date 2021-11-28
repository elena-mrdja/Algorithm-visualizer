## Functionalities

    - What will your project do, precisely?

Algorithm Visualizer will be a tool where user will be able to input C++ code in the code cell and get the flowchart visualization of the execution of it. The graphics interface will have Code cell, Viewer cell and a tool bar. Our project will allow the user to see line by line the evolution of his code execution and observe the state of variable values at each line.

## Deadlines and deliverables

    - What intermediate deadlines do you have, and what subset of functionalities will you deliver in each deadline?

* Week 1-3: Create a parser, AST and the look of the user interface.
* Weeks 3-6 (possibly 4-7 because we might not have assumed all of the problems we might have with using libraries and making a functional parser with tree representation): Add extra functionalities and represent graphically execution of the code presented in the AST.


## Software Architecture

    - How are you sub-dividing your project? Which modules are you implementing?

We will have one team working on making the parser and the AST. Basically, this team will, in the first stage of the project define initial tokens and “grammar” we will use. With help of the library ANTLR4, they will allow the lexical analysis and parsing of the code typed by the user (that will have restrictions we will talk later about). After making the parser, this team will create from the parse tree the AST. The other team will, in the first time, be working on creating the signatures of the classes inheritance for grammar we use and writing methods that wil be used for merging backend with GUI. In the second time, this team will be wokring on the interpreter that will work with AST and allow our varCell to interpret state of variables. Last but not the least, the GUI team will firstly learn basics of QtGraphics and then create simple version of the mainwindow. In the second part of the project, GUI team will work on merging graphics with the backend.

    - What is the interface of each module?

 You can define the interface with the public section of your class headers (note that not all classes need to be "exposed" from one module to the others).

    - What external dependencies do you have? Why?

We will use a library during the lexing process and parsing. The library we use is ANTLR4.

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




