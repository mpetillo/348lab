#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILESIZE 512

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
//this is meant to make printing the month names easier
//a note on the %: the number before anything else is the column size. negative means its left adjusted and positive means right adjusted. makes the prints look *that* much nicer.

void readfile(float monthlyamounts[]){
    FILE * fin;
    char filename[MAXFILESIZE];
    //code begins here
    printf("Enter file name: ");
    scanf("%s", filename);
    fin = fopen(filename, "r");
    int i = 0;
    rewind(fin);
    //guts of it - reads every line in the file (in theory, there should only be 12!) and passes to monthlyamounts
    while (fscanf(fin, "%f\n", &monthlyamounts[i]) == 1){
        printf("%f", monthlyamounts[i]);
        i++;
    }
    fclose(fin);
    return; //empty since we passed to pointer
}

void monthlyreport(float monthlyamounts[]){
    int i = 0;
    //setup
    printf("Monthly sales report for 2022:\n\n");
    printf("%-15s%s\n\n", "Month", "Sales");
    //loops through array and prints attached month, amount
    for (i = 0; i < 12; i++){
        printf("%-15s$%.2f\n", months[i], monthlyamounts[i]);        
    }
}

void minmaxav(float monthlyamounts[]){
    float min = 10000000000000000000000.00; //unless this is a fortune 500 company, nothing is going to be bigger than this 
    int minpos = 0;
    float max = 0.00;
    int maxpos = 0;
    float average = 0.00;
    int i = 0;
    //setup
    printf("\nSales Summary:\n\n");
    //guts of the operation - testing to see if each number is smaller/bigger than the given min/max + adding to average
    for (i = 0; i < 12; i++){
        if (monthlyamounts[i] < min){
            min = monthlyamounts[i];
            minpos = i;
        }
        if (monthlyamounts[i] > max){
            max = monthlyamounts[i];
            maxpos = i;
        }
        average += monthlyamounts[i];
    }
    printf("%-20s$%-10.2f%c%s%c\n", "Min Amount:", min, '(', months[minpos], ')');
    printf("%-20s$%-10.2f%c%s%c\n", "Max Amount:", max, '(', months[maxpos], ')');
    printf("%-20s$%-10.2f\n", "Average Amount:", (average / 12)); //it's not really necessary to divide before here
}

void sixmonthaverage(float monthlyamounts[]){
    printf("\nSix-Month Moving Average Report:\n\n");
    //loops through each six-pack of months and spits out an average
    int i = 0;
    for (i = 0; i < 7; i++){
        int j = 0;
        float average = 0;
        for (j = i; j < 6+i; j++){
            average += monthlyamounts[j];
        }
        printf("%-15s%-5c%-15s$%.2f\n", months[i], '-', months[i+5], average / 6); //divided by six instead of 12
    }
}

void sortbyamount(float monthlyamounts[]){
    int n = 12;
    printf("\nSales Reports (Highest to Lowest)\n\n");
    printf("%-15s%-15s\n\n", "Month", "Sales");
    int tempmonth[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //this is the fun one! the sort is done via shell sort
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            float temp = monthlyamounts[i];
            int tempm = tempmonth[i];
            int j = 0;
            for (j = i; j >= interval && monthlyamounts[j - interval] > temp; j -= interval) {
                monthlyamounts[j] = monthlyamounts[j - interval];
                tempmonth[j] = tempmonth[j - interval];
            }
        monthlyamounts[j] = temp; //if there was no switch, this will not impact anything
        tempmonth[j] = tempm;
        }
    }
    for (int i = 11; i > -1; i--){
        printf("%-15s$%.2f\n", months[tempmonth[i]], monthlyamounts[i]);
    }
}

int main(){
    float monthlyamounts[12];
    //the glob of subroutines
    readfile(monthlyamounts);
    monthlyreport(monthlyamounts);
    minmaxav(monthlyamounts);
    sixmonthaverage(monthlyamounts);
    sortbyamount(monthlyamounts);
}