This folder is our second successful tryout of the ANTLR library that we have managed to do. All the work that has been done while working on the things that are 
included here, will be used for the final product. The difference of this tryout is that we have fixed some important bugs, included our own grammar and included 
the folder with examples which you can use in order to test the library.

SETUP:
  1) Download the files
  2) Download Java (you might use this link for that: https://www.oracle.com/java/technologies/downloads/#java11-windows)
  2) Creat an empty folder called (ex. build) (inside the test_antlr4 folder)
  3) In the Terminal direct yourself into build folder
  4) Call: cmake ../ (you might need to download and install cmake)
  5) Call: make
  6) Now your project is configurated and you can open it in QT (use CMakeLists.txt file to configurate QT project)
 
Now when all is set up, open the main.cpp file and if you run it, it will do the lexing and parsing, creating a parse tree as the final product.

Folder ResultParseTree contains the png files which represent the parse tree obtained from the example files in the folder Examples.
