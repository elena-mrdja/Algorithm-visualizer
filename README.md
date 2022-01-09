# Algorithm visualizer

Algorithm Visualizer is a tool that will help you see the visual representation of the C++ code and be able to help both student and coders to debug their code. 

## Members 
1. Mina Goranovic, goranovic37, minagoranovic2, Project lead
2. Elena Mrdja, elena-mrdja, elenamrdja, Github master, GUI team lead
3. Milena Nedeljkovic, milenanedeljkovic, milenanedeljkovic4, AST team lead
4. Ekaterina Borisova, ekaterina-borisova, ekaterina97024145 , parser team lead
5. Matea Gjika, mattea777, mateagjika1, Trello master
6. Virgile Martin, VirgileMartinBX23, virgilemartin1, parser team
7. Elsa Bismuth, elsa-bismuth, elsa_bis, parser team
8. Stefan Vayln, StefanVaylBX2023, stefanvayl, parser team
9. Darya Todoskova, zorkotdasha, daryatodoskova, AST team
10. Evdokia Guenievna, Evdokia0, evdokia_gneusheva, AST team
11. John Levy, The11Doctor, johnnyboy34, GUI team

# Teams:

## Parsing/AST team
This team will be working on the tokenization and the lexical analysis of the code. They will after construct the AST needed for the interpreter team.
* Ekaterina Borisova
*	Stefan Vayln
*	Virgile Martin
* Elsa Bismuth

## AST/Interpreter team 
This team will be working on AST classes, but mostly on the way we will interpret the code. They will make two interfaces: one will use for drawing toe flowchart and on the other that we will use for tracking the variables.
*	Milena Nedeljkovic
*	Matea Gjika
*	Darya Todoskova
*	Evdokia Guenievna

## GUI
This is the frontend team that will code the interface part of the project which the user will directly interact with. 
*	Elena Mrdja
*	John Levy
*	Mina Goranovic




##Additional dependencies

Our project is using the ANTLR4. The folder with the path Algorithm-visualizer/AST in the brach "Workspace" contains all of the files needed to run the code. In order to install ANTLR and be able to compile the project, please follow the following steps:

  1) Download all the files
  2) Download Java (you might use this link for that: https://www.oracle.com/java/technologies/downloads/#java11-windows)
  2) Creat an empty folder called (ex. build) (inside the test_antlr4 folder)
  3) In the Terminal direct yourself into build folder
  4) Call: cmake ../ (you might need to download and install cmake)
  5) Call: make
  6) Now your project is configurated and you can open it in QT (use CMakeLists.txt file to configurate QT project)
 

