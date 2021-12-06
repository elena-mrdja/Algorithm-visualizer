# Week 5 - Reports

#### John Levy 
This week my focus was mainly centered on completing the goals that had been personally assigned to me. Thus, I kept working on the TextEditor Cell of the mainwindow, namely implementing parenthesis matching highlighting, autocompleting of parenthesis and auto indentation. I encountered many problems doing this and in consequence I have not been able to work on other parts of the project. 
However, this week we will try to start implementing some visualization of simple code, as we are about to start merging code with the other parts of the project.
#### Elena Mrdja
This week, my main task was implementing the Diagram scene library which will allow us to connect different shapes with arrows in order to create flowchart representations for our algorithms. To do this I had to implement four classes: Arrow where the arrow shape is created in a certain position, DiagramItem where the objects we want to connect are declared and connected with arrows, DiagramScene where all the mouse events are defined and DiagramTextItem which will serve for adding text to our shapes. I also had to update our mainwindow files in order to connect all the classes. Since I had some problems with compilations, all of the new files are commited to my personal branch for now, and this week's task is to solve these bugs and merge the diagram classes with our GUI, as well as updating the viewer cell in order to be compatible with the Diagram scene.

#### Darya Todoskova
This week I started implementing the walker for the AST, and I’ll continue working on it with Matea this week. I also had to get in touch with the GUI team to know how they wanted their cells to look like. For instance a square or a circle depending on the expression, etc. by modifying the Block classes. I also had to implement the counter for the lists we have. I spent a lot of time researching the walker, as it is a very abstract and new notion to me. For this following week, I will continue refining our interpreter and the classes that Team 1 is working on. I will also try to hopefully finalize the walker by the end of the week, because it might take some time.
#### Evdokia Gneusheva
This week I mainly worked on a problem of being able to get value of binary expressions. Instead of having templates for each type of binary operations, I started separating them into different classes such as Addition, Multiplication and etc. I did the same thing for unitary operations.

Next week I will work on putting everything that the Team AST have done so far together so that the GUI Team can test their code.
#### Matea Gjika
This week I worked on writing a walked that iterates through the statements in a Block and evaluates them. I had to make a few adjustments to the Block class in oder to do so, however it is still not complete as I need to check on some dependencies with other coders.

This week, I hope to finalise this class.

#### Mina Goranovic
This week we had three challenges: 
•	make another project in CMake 
•	Redefine the way we create shapes in GUI
•	Start merging (start with Assign class and then add more of them)

As the project leader, I made sure two backend teams start communicating closely and merging their code. I talked with Milena and Ekaterina who worked on the merging while others had their individual tasks to complete.
In the GUI team, we had different tasks: John finished the text editor and Elena and me worked on putting in place different shape drawing system. She worked on Diagram Scene application which I tried to debug afterwards (still not working), while I was implementing the QGraphicsView, QGraphicsScene and QGraphicsItem which have predefined shapes. This could be a nice solution as it should be enough for merging, even though we would like to upgrade it and use Diagram Scene. Now, I am able to draw shapes easily and put text into them, but I have some troubles integrating it in the rest of the code (for the same reasons as before, problem with MainWindow class and namespace ui). I was also able to connect PushButton with the function that draws different shapes.

#### Ekaterina Borisova 
This week I have been working on fixing some bugs that we got when creating classes. By now Team 1 has created all classes needed but now we are working on talking down with Team 2 on what we have to modify so that the output to that team can be of the most use. In order to do that I am working on trying out some most simple stuff to work so that when we understand the final concept of our output I could split tasks in my team and implement it for the rest of functions needed for our minimal goal and more. Also we have been working on how to start the merge process since it is very important by this point of the project to start merging.

#### Stefan Vayl
During past week I’ve implemented classes for while, ifelse and some other statements. This classes are callable as children of block statement and we need them to identify needed properties for particular AST nodes. This classes also allow us to call its children, for example, while statement consist of iteration condition and block, so I created a link to identify these leafs as classes of expression and block. Further next week, I am planning to work on implementation of AST. To do that we need to bound all the written classes, define the tree constructor and find the way to properly traverse parse tree.
#### Milena Nedeljkovic
For this week I split the team to two of us to work on getting the value of expressions and two to work on the beginning of the AST walker. After some attempts I realized that, since we are restricting ourselves to booleans and numerical variables, we can keep the value of the Variable as a double, adding (keeping) the additional attribute type if type is numeric, then the value is simply the number it is keeping; if type is bool, then values can be 0 and 1. Since 0 and 1 behave the same way with logical operations,this finally allows us to work with only one get_value function. This is important because we had a lot of inheritance and overloading problems when we were trying to allow some version of get_value function to return a boolean. With this, we found a way to calculate values of expressions.
Goals for next week: Ekaterina and I are planning to build an entirely new project from scratch and slowly add everybody's contributions. We will start by adding AST, Expression, Statement, Block, Assignment and Variable classes, make programs that consist only of assignments work, then add all other classes one by one.
Goals for my team: Working on the AST walker and making it work for each following class me and Katia add, making the plusplus operator into separate Statement, working on variable tracking.
#### Virgile Martin 
This week we finished writing our classes. Personally, I still had to write the Block and ArrayType classes. The particularity of these classes is that we do not know the number of elements they contain. 
Finally, while waiting for a new task to be assigned to me, I wrote new tests for our program.
#### Elsa Bismuth
This week, Team 1 (my team) and Team 2 tried to put in common the work done on classes. Indeed, as we both worked on the AST, there was a need to check if all the classes we wrote worked with their code, and if we were going in the same direction. The goal for next week is finally finishing the AST,  putting everything in common, and try to go from the beginning to the end of the process with easy examples to check if our project works.
