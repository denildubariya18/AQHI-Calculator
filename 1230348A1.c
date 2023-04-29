/********* 1230348A1.c *********
Student Name : Mann Modi         Student ID : 1230348
Due Date: Friday, 10th February 2023, at 11:59 pm        Course Name: CIS*1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity; and
2) I have completed assigned video on academic integrity.
I assert that this work is my own. I have appropriately acknowledged any and all material (code, data,
images, ideas or words) that I have used, whether directly quoted or paraphrase. Furthermore, I certify that
this assignment was prepared by me specifically for this course.
*********************
This file contains the tool to calculate Air Quality Health Index based on taken data from user. It uses stdio.h and math.h header files
to give outputs and do mathematics respectively. It also has many variables declared. For Instance, num, month, ans_1, AQHI, glOzone, pm_1, no2 etc.
This Program is able to calculate the Air Quality Health Index based on standard conditions and season-based conditions as well. It takes input of
ground level ozone, particulate matter & nitrogen dioxode.
This Program includes printf, scanf, if else statements, conditions, etc.
Basically, what this program does is, gives 3 options to  user and takes input, if input doesn't vary between 1 and 3, it gives error
and program exits. If user gives a valid input then program moves forward to take data from user. Also, if user inputs negative values
it gives error saying value must be greater than or equal to 0. If user inputs values in decimals, the program rounds off the final
answer to the nearest integer, which is helful to the user. The Range of health risk varies in 4 settings such as Low, moderate,
high & very high, and gives health message accordingly.
*********************
The program should be compiled using the following flags:
-std=c99
-Wall

Compiling:
gcc -Wall -std=c99 1230348A1.c -lm -o 1230348A1

Running the program:
./1230348A1
*********************/

#include <stdio.h>
#include <math.h>

int main()
{

    int num = 0;
    int month = 0;
    float AQHI_final = 0;
    float AQHI_final_2 = 0;
    float AQHI_final_3 = 0;
    float glOzone = 0;
    float glOzone_2 = 0;
    float pm_1 = 0;
    float pm_2 = 0;
    float pm_3 = 0;
    float no2 = 0;
    float no2_2 = 0;
    float no2_3 = 0;

    printf("Welcome to the Air Quality Index Generator!\n\n");

    printf("Choose your AQHI settings : \n");
    printf("\t1. Calculate in Standard Conditions\n");
    printf("\t2. Calculate Season-based Conditions\n");
    printf("\t3. Exit\n");

    scanf("%d", &num);

    if (num == 1)
    {
        printf("\nPlease enter the concentration of ground-level ozone : \n");
        scanf("%f", &glOzone);

        if (glOzone < 0)
        {
            printf("Error : Invalid Input, Value must be greater than or equal to 0. Exiting Program...\n");
            return 0;
        }

        printf("\nPlease enter the concentration of fine particulate matter : \n");
        scanf("%f", &pm_1);
        if (pm_1 < 0)
        {
            printf("Error : Invalid Input, Value must be greater than or equal to 0. Exiting Program...\n");
            return 0;
        }

        printf("\nPlease enter the concentration of nitrogen dioxide : \n");
        scanf("%f", &no2);

        if (no2 < 0)
        {
            printf("Error : Invalid Input, Value must be greater than or equal to 0. Exiting Program...\n\n");
            return 0;
            printf("\n\n");
        }

        AQHI_final = ceil((1000 / 10.4) * ((exp(0.000537 * glOzone) - 1) + (exp(0.000871 * no2) - 1) + (exp(0.000487 * pm_1) - 1))); //AQHI_final is the  formula to calculate AQHI for the given standard conditions, also ceil function is used to get the nearest integer output given by AQHI_final which can be float as well//

        printf("\nAQHI for standard conditions : \n\n");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

        if (AQHI_final < 4)
        {
            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final, "Low", "Ideal Air Quality for outdoor activities.");
            printf("---------------------------------------------------------------------------------------------------\n");
        }
        else if (AQHI_final >= 4 && AQHI_final <= 6)
        {
            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final, "Moderate", "No need to modify your outdoor activities.");
            printf("---------------------------------------------------------------------------------------------------\n");
        }
        else if (AQHI_final >= 7 && AQHI_final <= 10)
        {
            printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final, "High", "Consider reducing or rescheduling activities outdoors.");
            printf("---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("| %-10s| %-10s| %-12s| %-58s|\n", "Guelph", "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
            printf("---------------------------------------------------------------------------------------------------\n");
        }
    }

    else if (num == 2)
    {
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
            printf("\nPlease enter the concentration of fine particulate matter : \n");
            scanf("%f", &pm_2);
            if (pm_2 < 0)
            {
                printf("Error : Invalid Input, Value must be greater than or equal to 0. Exiting Program...\n");
                printf("\n");
                return 0;
            }
            printf("\nPlease enter the concentration of nitrogen dioxode : \n");
            scanf("%f", &no2_2);
            if (no2_2 < 0)
            {
                printf("Error : Invalid Input, value must be greater than or equal to 0. Exiting Program...\n");
                printf("\n\n");
                return 0;
            }

            AQHI_final_2 = ceil((1000 / 6.43) * ((exp(0.000457 * no2_2) - 1) + (exp(0.000462 * pm_2) - 1))); //AQHI_final_2 refers to the AQHI for cool conditions, also ceil function is used to get the nearest integer output//

            printf("\nAQHI for cool conditions : \n\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
            printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

            if (AQHI_final_2 < 4)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_2, "Low", "Ideal Air Quality for outdoor activities.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_2 >= 4 && AQHI_final_2 <= 6)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_2, "Moderate", "No need to modify your outdoor activities.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_2 >= 7 && AQHI_final_2 <= 10)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_2, "High", "Consider reducing or rescheduling activities outdoors.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_2 > 10)
            {
                printf("| %-10s| %-10s| %-12s| %-58s|\n", "Guelph", "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
                printf("---------------------------------------------------------------------------------------------------\n\n");
            }
        }

        if (month > 3 && month < 10)
        {
            printf("\nPlease enter the concentration of ground-level ozone : \n");
            scanf("%f", &glOzone_2);
            if (glOzone_2 < 0)
            {
                printf("Error : Invalid Input, value must be greater than or equal to 0. Exiting Program...\n");
                printf("\n");
                return 0;
            }
            printf("\nPlease enter the concentration of fine particulate matter : \n");
            scanf("%f", &pm_3);
            if (pm_3 < 0)
            {
                printf("Error : Invalid Input, value must be greater than or equal to 0. Exiting Program...\n");
                printf("\n");
                return 0;
            }
            printf("\nPlease enter the concentration of nitrogen dioxode : \n");
            scanf("%f", &no2_3);
            if (no2_3 < 0)
            {
                printf("Error : Invalid Input, value must be greater than or equal to 0. Exiting Program...\n");
                printf("\n\n");
                return 0;
            }

            AQHI_final_3 = ceil((1000 / 12.8) * ((exp(0.00104 * glOzone_2) - 1) + (exp(0.00101 * no2_3) - 1) + (exp(0.000621 * pm_3) - 1))); //AQHI_final_3 refers to AQHI related to warm conditions//

            printf("\nAQHI for warm conditions : \n\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
            printf("| %-10s| %-10s| %-12s| %-58s|\n", "Location", "AQHI", "Health Risk", "Health Message");

            if (AQHI_final_3 < 4)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_3, "Low", "Ideal Air Quality for outdoor activities.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_3 >= 4 && AQHI_final_3 <= 6)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_3, "Moderate", "No need to modify your outdoor activities.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_3 >= 7 && AQHI_final_3 <= 10)
            {
                printf("| %-10s| %-10.2f| %-12s| %-58s|\n", "Guelph", AQHI_final_3, "High", "Consider reducing or rescheduling activities outdoors.");
                printf("---------------------------------------------------------------------------------------------------\n");
            }
            if (AQHI_final_3 > 10)
            {
                printf("| %-10s| %-10s| %-12s| %-58s|\n", "Guelph", "Above 10", "Very High", "Reduce or reschedule strenuous activities outdoors.");
                printf("---------------------------------------------------------------------------------------------------\n\n");
            }
        }
    }
    else if (num == 3)
    {
        printf("\n");
        printf("Thank you for using the Air Quality Index Generator! Exiting Program...\n");
        printf("\n");
        return 0;
    }

    else
    {
        printf("Invalid Option - Input must be between 1 and 3. Exiting Program...\n");
    }
}