// ################# DO NOT MODIFY ANYTHING IN THIS FILE ####################
// "Include Guards"
#ifndef A2_FUNCTIONS_H_
#define A2_FUNCTIONS_H_

/* Mandatory global symbolic constants. 
 * Use these for array sizes. Ex:
 * float AQHIs[3][MAX_LOCATIONS];
*/
#define MAX_LOCATIONS 10 
#define MAX_STRING_SIZE 50 

/* optional global symbolic constants. 
 * They could be used to keep track of data locations in arrays. Ex:
 * AQHIs[WARM_AQHI] = ...
 * Or they could be used to return values from functions.
*/
#define STANDARD_AQHI 0
#define WARM_AQHI 1
#define COOL_AQHI 2

// Input/Output Functions
int printMenuGetSelection();
void getInputs(char location[MAX_STRING_SIZE], float pollutants[3]);
void printTable(char equationName[MAX_STRING_SIZE], int numLocations, char locations[MAX_LOCATIONS][MAX_STRING_SIZE], float AQHIs[MAX_LOCATIONS]);

// Math Functions
float roundAQHI(float aqhi);
float standardAQHI(float O3, float NO2, float PM2_5);
float coolAQHI(float NO2, float PM2_5);
float warmAQHI(float O3, float NO2, float PM2_5);

#endif
// ################# DO NOT MODIFY ANYTHING IN THIS FILE ####################