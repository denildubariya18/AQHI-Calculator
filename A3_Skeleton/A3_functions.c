#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "A3_functions.h"

// TODO create (at least) 5 these functions:

float getAverage(float pollutants[24])
{
    float sum = 0;
    float avg;
    int counter = 0;
    for (int i = 0; i < 24; i++)
    {
        if (pollutants[i] >= 0 && pollutants[i] != 9999)
        {
            sum += pollutants[i];
            counter++;
        }
    }
    // printf("%f\n",sum/counter);
    return (counter == 0) ? 0 : (sum / counter);
}

int readAPollutantFile(char filename[], char location[], float pollutantAverages[], char dates[][MAX_STRING_SIZE])
{
    char line[1000];
    char *token;
    float pollutants[24];
    int lineCounter = 1;
    int i = 0;
    int len = strlen(filename);
    FILE *filePointer = fopen(filename, "r");
    if (filePointer == NULL)
    {
        // printf("Couldn't open file.");
        return 0;
    }
    while (fgets(line, sizeof(line), filePointer) != NULL)
    {
        char substr[] = "H24";
        if (lineCounter == 4)
        {
            token = strtok(line, ",");
            for (int k = 0; k < len; k++)
            {
                if (token[k] == ' ')
                {
                    break;
                }
                location[k] = token[k];
            }
            lineCounter++;
            continue;
        }
        else if (strstr(line, substr) != NULL)
        {
            break;
        }
        else
        {
            lineCounter++;
        }
    }
    while (fgets(line, sizeof(line), filePointer) != NULL)
    {
        if (i == 31)
        {
            break;
        }
        token = strtok(line, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        strcpy(dates[i], token);
        for (int j = 0; j < 24; j++)
        {
            token = strtok(NULL, ",");
            pollutants[j] = atof(token);
            // printf("%f ", pollutants[j]);
        }
        // printf("\n");
        pollutantAverages[i] = getAverage(pollutants);
        // printf("%d-%f\n", i, pollutantAverages[i]);
        i++;
    }
    fclose(filePointer);
}
struct Location readData()
{
    struct Location locationStructure_1;
    char filename1[MAX_STRING_SIZE];
    char filename2[MAX_STRING_SIZE];
    char filename3[MAX_STRING_SIZE];
    FILE *fp;
    // Taking the input for file-1
    while (1)
    {
        printf("Please Enter the filename for the O3 csv file.\n");
        scanf("%s", filename1);
        if (fopen(filename1, "r") == NULL)
        {
            printf("ERROR: File %s does not exist\n", filename1);
        }
        else if (fopen(filename1, "r") != NULL)
        {
            break;
        }
    }
    // Reading the first file and storing the value of location in loc variable
    readAPollutantFile(filename1, locationStructure_1.locationName, locationStructure_1.pollutantAverages[0], locationStructure_1.dates);

    char loc[MAX_STRING_SIZE];
    strcpy(loc, locationStructure_1.locationName);
    while (1)
    {
        printf("Please enter the filename for the NO2 csv file for %s.\n", loc);
        scanf("%s", filename2);
        readAPollutantFile(filename2, locationStructure_1.locationName, locationStructure_1.pollutantAverages[1], locationStructure_1.dates);
        if (fopen(filename2, "r") == NULL)
        {
            printf("ERROR: File %s does not exist\n", filename2);
        }
        else if (strcmp(loc, locationStructure_1.locationName) != 0)
        {
            continue;
        }
        else if (fopen(filename2, "r") != NULL && strcmp(loc, locationStructure_1.locationName) == 0)
        {
            break;
        }
    }
    // Taking input and reading file 2
    while (1)
    {
        printf("Please enter the filename for the PM2_5 csv file for %s.\n", loc);
        scanf("%s", filename3);
        readAPollutantFile(filename3, locationStructure_1.locationName, locationStructure_1.pollutantAverages[2], locationStructure_1.dates);
        if (fopen(filename3, "r") == NULL)
        {
            printf("ERROR: File %s does not exist\n", filename3);
        }
        else if (strcmp(loc, locationStructure_1.locationName) != 0)
        {
            continue;
        }
        else if (fopen(filename3, "r") != NULL && strcmp(loc, locationStructure_1.locationName) == 0)
        {
            break;
        }
    }
    char *tok;
    char months[50];
    for (int i = 0; i < strlen(locationStructure_1.dates[0]); i++)
    {
        months[i] = locationStructure_1.dates[0][i];
    }
    tok = strtok(months, "-");
    tok = strtok(NULL, "-");
    int month = atoi(tok);
    // printf("hello %d\n", month);
    for (int i = 0; i < MAX_DATES; i++)
    {
        locationStructure_1.standardAQHIs[i] = roundAQHI(standardAQHI(locationStructure_1.pollutantAverages[0][i], locationStructure_1.pollutantAverages[1][i], locationStructure_1.pollutantAverages[2][i]));
        if (month <= 0 || month > 12)
        {
            printf("invalid month");
        }
        else if (month >= 4 && month <= 9)
        {
            locationStructure_1.seasonalAQHIs[i] = roundAQHI(warmAQHI(locationStructure_1.pollutantAverages[0][i], locationStructure_1.pollutantAverages[1][i], locationStructure_1.pollutantAverages[2][i]));
            // printf("%d-%f\n",i,locationStructure_1.seasonalAQHIs[i]);
        }
        // else if (month >= 10 && month <= 3)
        // {
        //     locationStructure_1.seasonalAQHIs[i] = roundAQHI(coolAQHI(locationStructure_1.pollutantAverages[1][i], locationStructure_1.pollutantAverages[2][i]));
        //     // printf("%d-%f\n",i,locationStructure_1.seasonalAQHIs[i]);
        // }
        else
        {
            locationStructure_1.seasonalAQHIs[i] = roundAQHI(coolAQHI(locationStructure_1.pollutantAverages[1][i], locationStructure_1.pollutantAverages[2][i]));
            // printf("%d-%f\n",i,locationStructure_1.seasonalAQHIs[i]);
            // printf("\n\nhello world\n\n");
        }
    }
    return locationStructure_1;
}

void printTablebydate(Location locations[], int numLocations)
{
    int con = 0;
    char date[MAX_STRING_SIZE]; // Variable to read date
    char *type;                 // Variable to read type
    char colname[MAX_STRING_SIZE] = "Location";
    int flag = 0;
    if (numLocations == 0)
    {
        printf("No location data has been entered. Please enter new location and data and try again.\n");
        return;
    }
    do
    {
        printf("Choose your AQHI settings: \n\t1.Calculate Standard Conditions\n\t2.Calculate Seasonal Conditions\n");
        scanf("%d", &con);
        if (con == 1 || con == 2)
        {
            break;
        }
        else if (con != 1 || con != 2)
        {
            printf("Incorrect input\n");
        }

    } while (1);
    printf("Please enter a date.\n");
    scanf("%s", date);

    if (con == 1)
    {
        type = "Standard";

        printTableHead(date, type, colname, numLocations);
        for (int i = 0; i < numLocations; i++)
        {
            for (int j = 0; j < MAX_DATES; j++)
            {
                if (strcmp(locations[i].dates[j], date) == 0)
                {
                    printTableRow(locations[i].locationName, locations[i].standardAQHIs[j]);
                    flag++;
                }
            }
        }
        if (flag == 0)
        {
            printf("%s not found.\n", date);
        }

        printTableFoot();
    }
    else if (con == 2)
    {
        type = "Seasonal";
        printTableHead(date, type, colname, numLocations);
        for (int i = 0; i < numLocations; i++)
        {
            for (int j = 0; j < MAX_DATES; j++)
            {
                if (strcmp(locations[i].dates[j], date) == 0)
                {
                    printTableRow(locations[i].locationName, locations[i].seasonalAQHIs[j]);
                    flag++;
                }
            }
        }
        if (flag == 0)
        {
            printf("%s not found.\n", date);
        }
        printTableFoot();
    }
}

void printTableByLocation(Location locations[], int numLocations)
{
    int con = 0;
    char loc[MAX_STRING_SIZE];
    char *type;
    char colname[MAX_STRING_SIZE] = "Date";
    int flag = 0;
    if (numLocations == 0)
    {
        printf("No location data has been entered. Please enter new location and data and try again.\n");
        return;
    }
    do
    {
        printf("Choose your AQHI settings: \n\t1.Calculate Standard Conditions\n\t2.Calculate Seasonal Conditions\n");
        scanf("%d", &con);
        if (con == 1 || con == 2)
        {
            break;
        }
        else if (con != 1 || con != 2)
        {
            printf("Incorrect input\n");
            continue;
        }
    } while (1);
    printf("Please enter the name of a Location.\n");
    scanf("%s", loc);
    if (con == 1)
    {
        type = "Standard";
        printTableHead(loc, type, colname, numLocations);
        for (int i = 0; i < numLocations; i++)
        {
            if (strcmp(locations[i].locationName, loc) == 0)
            {
                for (int j = 0; j < MAX_DATES; j++)
                {
                    // printf("%d-%f\n", j, locations[i].standardAQHIs[j]);
                    printTableRow(locations[i].dates[j], locations[i].standardAQHIs[j]);
                    flag++;
                }
            }
        }
        if (flag == 0)
        {
            printf("%s not found\n");
        }
        printTableFoot();
    }
    else if (con == 2)
    {
        type = "Seasonal";
        printTableHead(loc, type, colname, numLocations);
        for (int i = 0; i < numLocations; i++)
        {
            if (strcmp(locations[i].locationName, loc) == 0)
            {
                for (int j = 0; j < MAX_DATES; j++)
                {

                    printTableRow(locations[i].dates[j], locations[i].seasonalAQHIs[j]);
                    flag++;
                }
            }
        }
        if (flag == 0)
        {
            printf("%s not found\n");
        }
        printTableFoot();
    }
}

// ################# DO NOT MODIFY ANYTHING BELOW HERE  ####################
int printMenuGetSelection()
{
    int choice = -1;

    do
    {
        printf("\nSelect an option from the Menu:\n");
        printf("\t1. Calculate AQHI for Location\n");
        printf("\t2. Calculate AQHI for Date\n");
        printf("\t3. Read Data From a File\n");
        printf("\t4. Exit\n");

        scanf(" %d", &choice);

        if (choice < 1 || choice > 4)
        {
            printf("\nError: invalid option - input must be between 1 and 4.\n");
        }
    } while (choice < 1 || choice > 4);
    if (choice == 4)
    {
        return -1;
    }

    return choice;
}

void printTableHead(char label[MAX_STRING_SIZE], char equationName[MAX_STRING_SIZE], char col1Name[MAX_STRING_SIZE], int numLocations)
{
    if (numLocations == 0)
    {
        printf("\nNo location data has been entered. Please enter new location and data and try again. \n");
        return;
    }

    printf("\nAQHI for %s conditions at %s:", equationName, label);
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("| %-10.10s| %-10s| %-12s| %-58s|\n", col1Name, "AQHI", "Health Risk", "Health Message");

    printf("---------------------------------------------------------------------------------------------------\n");
}

void printTableRow(char label[MAX_STRING_SIZE], float aqhi)
{
    char healthRisk;

    if (aqhi < 4)
    {
        healthRisk = 'L';
    }
    else if (aqhi < 7)
    {
        healthRisk = 'M';
    }
    else if (aqhi < 11)
    {
        healthRisk = 'H';
    }
    else
    {
        healthRisk = 'V';
    }

    if (aqhi <= 10)
    {
        printf("| %-10.10s| %-10.2f| ", label, aqhi);
    }
    else
    {
        printf("| %-10.10s| %-10s| ", label, "Above 10");
    }

    switch (healthRisk)
    {
    case 'L':
        printf("%-12s|", "Low");
        printf(" %-58s|\n", "Ideal air quality for outdoor activities.");
        break;
    case 'M':
        printf("%-12s|", "Moderate");
        printf(" %-58s|\n", "No need to modify your outdoor activities.");
        break;
    case 'H':
        printf("%-12s|", "High");
        printf(" %-58s|\n", "Consider reducing or rescheduling activities outdoors.");
        break;
    case 'V':
        printf("%-12s|", "Very High");
        printf(" %-58s|\n", "Reduce or reschedule strenuous activities outdoors.");
        break;
    }
}

void printTableFoot()
{
    printf("---------------------------------------------------------------------------------------------------\n");
}

float roundAQHI(float aqhi)
{
    if (aqhi < 0.5)
        return 1;
    return round(aqhi);
}

float standardAQHI(float O3, float NO2, float PM2_5)
{
    return (1000 / 10.4) * ((exp(0.000537 * O3) - 1) + (exp(0.000871 * NO2) - 1) + (exp(0.000487 * PM2_5) - 1));
}

float coolAQHI(float NO2, float PM2_5)
{
    return (1000 / 6.43) * ((exp(0.000457 * NO2) - 1) + (exp(0.000462 * PM2_5) - 1));
}

float warmAQHI(float O3, float NO2, float PM2_5)
{
    return (1000 / 12.8) * ((exp(0.00104 * O3) - 1) + (exp(0.00101 * NO2) - 1) + (exp(0.000621 * PM2_5) - 1));
}
