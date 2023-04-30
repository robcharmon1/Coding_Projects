# Coding_Projects
These are a number of coding projects I've worked on sorted by language.

## C++

### Sorting Algorithm Comparison

[Program files](/Sorting_Algorithm_Comparison/)

* Implements various sorting algorithms for a data set of random integers
* Outputs run times of 6 different sorting algorithms on the same data for comparison
* Data set size is determined by user input
* Below is a plot of run times vs data set sizes for the algorithms and sample output from the program
* Insertion sort and selection sort are expected to have run times on the order of O(n<sup>2</sup>), and an exponential growth can be seen in their plots below
* The other 4 algorithms are much faster
* Shell sort has an average run time on the order of O(n<sup>1.5</sup>) and quick sort, merge sort, and radix sort have run times on the order of O(nlogn), and their much slower growth rates can be seen below

![Sort_alg_comp_output](https://user-images.githubusercontent.com/85814015/235327265-922cfea6-6dff-48a7-97d8-eff0355dfc56.png)

![Sort_alg_comp_graph](https://user-images.githubusercontent.com/85814015/235326470-49b50516-3acb-4a15-8f51-3b21e2c9f757.png)

### Record Text File Analyzer

[Program files](/Record_Text_File_Analyzer/)

* Program in C++ to turn text file records to useable data
* Reads a text file, uses a map to store items and quantities sold, and outputs data to a new file
* Displays menu for user with choices for displaying the data in different ways

## Java

### Rescue Animal Record Keeper

[Program files](/Rescue_Animal_Record_Keeper/)

* Defines an animal base class and sub classes for specific animals
* Allows user to perform functions to create new objects and display stored data
* Uses resizable arrays to easily store objects

## Python

### Create Your Own Adventure Game

[Program Files](/Create_Your_Own_Adventure_Game/)

* This is a command line choose your own adventure game written in Python
* Takes input commands to allow user to move between rooms, collect items, and complete an objective
* Main feature is a nested dictionry where:
  * The first keys represent the rooms
  * The value for each room is keys representing an item, moveable directions, and room descriptions with values for each
* Performs input validation
