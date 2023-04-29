/************************** 1230348A2_main.c **************************
Student Name: Mann Modi Student ID : 1230348
Due Date: Friday, 10th March 2023, at 11:59 pm Course Name: CIS*1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity; and
2) I have completed assigned video on academic integrity.
I assert that this work is my own. I have appropriately acknowledged any and all material (code, data,
images, ideas or words) that I have used, whether directly quoted or paraphrase. Furthermore, I certify that
this assignment was prepared by me specifically for this course.
***************************************************************
This file contains...
Describe the program, functions, important variables, etc.
***************************************************************
The program should be compiled using the following flags:
-std=c99
-Wall
-lm
Compiling:
gcc -Wall -std=c99 1230348A2_main.c A2_functions.c -o 1230348A2 -lm
Running the program:
./1230348A2
***************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "A2_functions.c"
#include "A2_functions.h"


int main() {
    
    printf("\nWelcome to the Air Quality Index Generator!\n\n");
    printMenuGetSelection();
    

    // getch();
    return 0;
}



