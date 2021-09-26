/*
 * Author: Your name
 * Purpose: Reads airport data from a file, calculate yearly averages, and prints.
 * Language: C
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototypes
// reads data from the .csv file
int read_data(double aircraft_data[][4], FILE * fp);
// calculate yearly averages and save in aircraft_avg array
int yearly_avg(double aircraft_data[][4], double aircraft_avg[][3], int rows);
// print the aircraft_avg array
void print_array(double aircraft_avg[6][3], int rows);

int main() {

	// creates file pointer to aircraft arrivals and departures dataset
	FILE * fp;
	fp = fopen("aircraft_arrivals_departures.csv", "r");	
	
	// creates arrays to hold aircraft data and aircraft data averages
	double aircraft_data[100][4] = {0};
	double aircraft_avg[10][3] = {0};

	// checks if file pointer is null
	if (fp == NULL) {
		printf("ERROR");
		return -1;
	}

	// reads data from file to array and stores number of data points (rows) read
	int read = read_data(aircraft_data, fp);	

	// prints error message if error occurs while reading file
	if (feof(fp) == 0) {
		printf("File reading error. End of file was not reached.\n");
	}

	// averages data and stores in new array and stores number of rows in averages array
	int rows_avg = yearly_avg(aircraft_data, aircraft_avg, read);
    
    print_array(aircraft_avg, rows_avg);

	fclose(fp);

	return 0;
}

// reads data from file into multidimensional array and returns number of lines read
int read_data(double aircraft_data[][4], FILE * fp) {
	char buff[255];		// buffer
	char *token;		// line from file

	// array row
	int r = 0;

        //reads header
        fgets(buff, 255, fp);

	// reads line of data from file and stores in array
        while(fgets(buff, 255, fp) != NULL) {
		// array column
                int c = 0;

		// reads token with delimeters - and ,
                token = strtok(buff, "-,");
		// stores data in array
                while (token != NULL) {
                        aircraft_data[r][c] = atof(token);
                        token = strtok(NULL, "-,");
                        c++;
                }
                r++;

        }
	return r + 1;
}

// calculates yearly averages from monthly data points and
// stores in aircraft_avg array and returns number of rows in aircraft_avg array
int yearly_avg(double aircraft_data[][4], double aircraft_avg[][3], int rows) {
	
    
    
    // You only need to complete this function
    
    
    
}


// prints formatted chart of aircraft data (year, arrivals, departures)
// you need to pass a 2D array with 3 columns as well as the number of rows
/*
 2010         10980.75         10985.33
 2011         12568.92         12573.67
 2012         13529.08         13531.08
 2013         14320.83         14326.25
 2014         14223.33         14225.50
 2015         14429.33         14431.83
 */
void print_array(double aircraft_avg[][3], int rows) {
	// prints header
	printf("%-8s %-13s %-13s\n", "Year", "Arrivals", "Departures");
	// prints data from array - 3 columns
	for (int i = 0; i < rows; i++) {
		printf("%-8.0lf %-13.2lf %-13.2lf\n", aircraft_avg[i][0], aircraft_avg[i][1], aircraft_avg[i][2]);
	}
	printf("\n");
}

