#include <stdio.h>
#include <math.h>
#include <string.h>
#include "A3_functions.h"
#include "A3_functions.c"

int main()
{

    int choice = 0;
    Location locationStructionArray[MAX_LOCATIONS];
    int numLocation = 0;
    printf("Welcome to the Air Quality Index Generator!\n");

    // TODO ADD CODE
    choice = printMenuGetSelection();
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            printTableByLocation(locationStructionArray, numLocation);
            choice = printMenuGetSelection();
            break;
        case 2:
            printTablebydate(locationStructionArray, numLocation);
            choice = printMenuGetSelection();
            break;
        case 3:
            locationStructionArray[numLocation] = readData();
            numLocation++;
            choice = printMenuGetSelection();
            break;
        default:
            break;
        }
    }
    printf("Thankyou for using the Air Quality Index Generator Exiting Program...");

        // TODO ADD CODE

        return 0;
}