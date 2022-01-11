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
*	Milena Nedeljković
*	Matea Gjika
*	Darya Todoskova
*	Evdokia Guenievna

## GUI
This is the frontend team that will code the interface part of the project which the user will directly interact with. 
*	Elena Mrdja
*	John Levy
*	Mina Goranović




# Additional dependencies

Our project is using the ANTLR4. The folder with the path Algorithm-visualizer/AST in the brach "Workspace" contains all of the files needed to run the code. In order to install ANTLR and be able to compile the project, please follow the following steps:

  1) Download all the files.
  2) Download Java (you might use this link for that: https://www.oracle.com/java/technologies/downloads/#java11-windows).
  2) Creat an empty folder called (ex. build) (inside the AST folder).
  3) In the Terminal direct yourself into build folder.
  4) Call: cmake ../ (you might need to download and install cmake).
  If you have the Cmake, then make sure you configure and generate the project:
  <img width="1431" alt="cmake2" src="https://user-images.githubusercontent.com/91254922/148872728-f0860d32-4b4d-418d-9547-0318b1c53cee.png">
  5) Call: make
  6) Now your project is configurated and you can open it in QT (use CMakeLists.txt file to configurate QT project)
  <img width="821" alt="open" src="https://user-images.githubusercontent.com/91254922/148872974-bc3b60e8-1e0f-419c-9421-87bcff1f975b.png">

 
# Limitations:
- Our program work only with the function main.
- It works only with the grammar we defined, which can be found in the doc/project_design.md file.
<img width="1299" alt="grammar" src="https://user-images.githubusercontent.com/91254922/148873551-6745520a-17e5-4a9c-a299-e07de9e80d99.png">
- When declaring a variable, user has to assing to it its inital value .
- When using Unop, the user is asked to write the Unop after the variable (i.e please write i++ instead of ++i).
- User is asked to not write more than 100 statements (where one statement is basically one line of code excluding the lines containing only brackets or declaration of while loop/if/else).
- The user is expected to write a code that can be compiled.
- The user is asked to not write inifite loops.


# Functionalities:

Write the code in the CodeCell and click the “Done” button.  Our program will read your code you allow you two simultaneous actions on click of the corresponding buttons:
<a href="https://user-images.githubusercontent.com/91254922/148877205-275e3975-e643-4417-96ff-7a9152d83e64.mp4" title="Link Title"><img src="https://user-images.githubusercontent.com/91254922/148872728-f0860d32-4b4d-418d-9547-0318b1c53cee.png" alt="Alternate Text" /></a>
<video width="320" height="240" controls>
  <source src="https://user-images.githubusercontent.com/91254922/148877205-275e3975-e643-4417-96ff-7a9152d83e64.mp4" type="video/mp4">
</video>

- Visualization of the structure of your code in the shape of a flowchart. Click on the “Visualize” button and the corresponding flowchart will appear in the ViewCell. 
- Our program allows you to zoom in and out so that you can have a better overview for long codes and large, nested loops.
- The variabls tracking for each line of the code. Click on the “Show me variables state” button to see the state of variable in the first line. Every following click will update the state of all declared variables at the following line.
- When it comes to loops, our VariableTrack cell displays all of the variables states during the execution of the loop at a single click.


# Improvements and features done in some of the teams:
- We are working on the expansion of the grammar the user can use. Currently, there are some structures, such as array type, that are defined in the AST, but still need their implementation in the Interpreter part of the backend and the GUI.
- We have a half done function that uploads a .cpp file from the user’s computer.
- We have backend potential to connect the View cell and the VarTrack cell so that user can clearly see which part of the code are actually being executed.
- In the future, we would like to be able to visualize also the python code.


# Demo video on some examples:

