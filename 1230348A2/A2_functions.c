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
#include <malloc.h>

#include "A2_functions.h"

int getsInput(char *location, float *pollutants, int ctr);

int printMenuGetSelection()
{
    // TODO: Add code here
    int choice = 0;
    char *loc;
    float pol[3] = {0, 0, 0};
    char str;
    float AQHI_final;
    char location[MAX_STRING_SIZE];
    // float glOzone_3 = 0;
    // float pm_3 = 0;
    // float no2_3 = 0;
    int ctr = 0;

    while (choice != 4)
    {
        printf("Choose your AQHI settings:\n");
        printf("\t1. Calculate in Standard Conditions\n");
        printf("\t2. Calculate Season-based Conditions\n");
        printf("\t3. Enter new Location and Data\n");
        printf("\t4. Exit\n\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (ctr == 0)
            {
                printf("\nNo location data has been entered. Please enter new location and data and try again.\n\n");
            }
            else
            {
                // calculate AQHI in standard conditions
                //
                //

                AQHI_final = ceil((1000 / 10.4) * ((exp(0.000537 * (*pol)) - 1) + (exp(0.000871 * *(pol + 2)) - 1) + (exp(0.000487 * *(pol + 1)) - 1))); // AQHI_final is the  formula to calculate AQHI for the given standard conditions, also ceil function is used to get the nearest integer output given by AQHI_final which can be float as well//

                //					printf("in loop,%f, %f",AQHI_final ,*(pol+1));
                printf("\nAQHI for standard conditions : \n\n");
                printf("\n---------------------------------------------------------------------------------------------------\n");
                printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

                if (AQHI_final < 4)
                {
                    printf("| %-10s| %-10.2f| %-12s| %-58s|\n", *loc, AQHI_final, "Low", "Ideal Air Quality for outdoor activities.");
                    printf("---------------------------------------------------------------------------------------------------\n");
                }
                else if (AQHI_final >= 4 && AQHI_final <= 6)
                {
                    printf("| %-10s| %-10.2f| %-12s| %-58s|\n", *loc, AQHI_final, "Moderate", "No need to modify your outdoor activities.");
                    printf("---------------------------------------------------------------------------------------------------\n");
                }
                else if (AQHI_final >= 7 && AQHI_final <= 10)
                {
                    printf("| %-10s| %-10.2f| %-12s| %-58s|\n", *loc, AQHI_final, "High", "Consider reducing or rescheduling activities outdoors.");
                    printf("---------------------------------------------------------------------------------------------------\n");
                }
                else
                {
                    printf("| %-10s| %-10s| %-12s| %-58s|\n", *loc, "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
                    printf("---------------------------------------------------------------------------------------------------\n");
                }
                ctr = 0;
            }
            continue;
        }

        case 2:
        {
            int month;
            if (ctr == 0)
            {
                printf("\nNo location data has been entered. Please enter new location and data and try again.\n\n");
            }
            else
            {
                if (ctr == 0)
                {
                    printf("\nNo location data has been entered. Please enter new location and data and try again.\n\n");
                }
                else
                {
                    // calculate AQHI in season based conditions
                    printf("Enter the month for readings\n");
                    printf("(January = 1, February = 2, etc.)\n");
                    scanf("%d", &month);
                    if (month < 1 || month > 12)
                    {
                        printf("Error : Invalid Option - Input must be between 1 and 12. Exiting Program...\n");
                        return 0;
                    }
                    printf("\n");
                    if (month > 9 || month < 4)
                    {
                        float AQHI_final_2 = ceil((1000 / 6.43) * ((exp(0.000457 * *(pol + 2)) - 1) + (exp(0.000462 * *(pol + 1)) - 1))); // AQHI_final_2 refers to the AQHI for cool conditions, also ceil function is used to get the nearest integer output//

                        printf("\nAQHI for cool conditions : \n\n");
                        printf("\n---------------------------------------------------------------------------------------------------\n");
                        printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

                        if (AQHI_final_2 < 4)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_2, "Low", "Ideal Air Quality for outdoor activities.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_2 >= 4 && AQHI_final_2 <= 6)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_2, "Moderate", "No need to modify your outdoor activities.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_2 >= 7 && AQHI_final_2 <= 10)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_2, "High", "Consider reducing or rescheduling activities outdoors.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_2 > 10)
                        {
                            printf("| %-10s| %-10s| %-12s| %-58s|\n", loc, "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
                            printf("---------------------------------------------------------------------------------------------------\n\n");
                        }
                    }

                    if (month > 3 && month < 10)
                    {

                        float AQHI_final_3 = ceil((1000 / 12.8) * ((exp(0.00104 * *(pol)) - 1) + (exp(0.00101 * *(pol + 2)) - 1) + (exp(0.000621 * *(pol + 1)) - 1))); // AQHI_final_3 refers to AQHI related to warm conditions//

                        printf("\nAQHI for warm conditions : \n\n");
                        printf("\n---------------------------------------------------------------------------------------------------\n");
                        printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

                        if (AQHI_final_3 < 4)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_3, "Low", "Ideal Air Quality for outdoor activities.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_3 >= 4 && AQHI_final_3 <= 6)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_3, "Moderate", "No need to modify your outdoor activities.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_3 >= 7 && AQHI_final_3 <= 10)
                        {
                            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", loc, AQHI_final_3, "High", "Consider reducing or rescheduling activities outdoors.");
                            printf("---------------------------------------------------------------------------------------------------\n");
                        }
                        if (AQHI_final_3 > 10)
                        {
                            printf("| %-10s| %-10s| %-12s| %-58s|\n", loc, "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
                            printf("---------------------------------------------------------------------------------------------------\n\n");
                        }
                    }
                }
                continue;
                // calculate AQHI in season based conditions
            }
            continue;
        }

        case 3:
        {
            // store location details
            ctr = getsInput(loc, pol, ctr);
            continue;
        }

        case 4:
        {
            printf("\nThank you for using the Air Quality Index Generator! Exiting Program...\n\n");
            continue;
        }
        default:
            printf("\nError : Invalid option - input must be between 1 and 4.\n\n");
            break;
        }
    }
}

int getsInput(char *location, float *pollutants, int ctr)
{

    // pollutants = (float*)malloc(3 * sizeof(float));
    char *c;
    *c = *location;
    printf("\nPlease enter the location name (one word : no symbols, spaces, tabs, etc.) : \n");
    scanf("%s", location);

    printf("\nPlease enter the concentration of ground-level ozone: \n");
    scanf("%f", pollutants);
    if ((*pollutants) <= 0.0)
    {
        printf("Error: Invalid input. Value must be greater than or equal to 0. Exiting program...\n");
    }

    printf("\nPlease enter the concentration of fine particulate matter: \n");
    scanf("%f", (pollutants + 1));
    if (*(pollutants + 1) <= 0)
    {
        printf("Error: Invalid input. Value must be greater than or equal to 0. Exiting program...\n");
    }

    printf("\nPlease enter the concentration of nitrogen dioxide: \n");
    scanf("%f", (pollutants + 2));
    if (*(pollutants + 2) < 0)
    {
        printf("Error: Invalid input. Value must be greater than or equal to 0. Exiting program...\n");
    }

    ctr = ctr + 1;

    return ctr;
}

// TODO Add other function definitions here:

// void printTable(char equationName[MAX_STRING_SIZE], int numLocations, char locations[MAX_LOCATIONS][MAX_STRING_SIZE], float AQHIs[MAX_LOCATIONS]){

// }
