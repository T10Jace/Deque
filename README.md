#DEQUE Program

This is the DEQUE program

It DEQUES things.

The following program can be compiled using the command: make

To run the program, simply type in the command: ./deque

When the program is ran, it will show the info of the deque as it is being modified.

The initial deque that is created before any modifications should look like the following:

20 // This is the first element located at the front of the deque [0]
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
10
20
30
40
50
60
70
80
90
100 
110
120
130
140
150
160
170
180
190
200 // This is the last element located at the back of the deque [39]

** As you can see there are 40 data points in the following deque.

# Issues and Errors
 ** When inputting too many data points into the deque, the following error pops up:
        double free or corruption (out)
        
    * I assume it has to do with the resize function, however, after numerous modifications 
       I still could not find out how to fix it.

