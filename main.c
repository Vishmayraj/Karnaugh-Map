/* THIS CODE ONLY WORKS FOR KMAP UPTO 4 VARIABLES YET BECAUSE I HAVEN'T FIGURED OUT HOW TO do THE KMAP OF 5 VARIABLES LOL*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

void parse_str_into_list(int listofones[], char listasstr[], int *size);
void parse_bool_into_list(int listofones[], char bool_func[]);
void printlist(int list[], int length);
void print_bool_matrix(int rows, int columns,bool matrix[rows][columns]);

int main()
{
    // number of variables
    int var;
    printf("How many variables? ");
    scanf("%d", &var);
    
    // make a basic 2**n list
    int boxes = pow(2, var);
    int listofones[boxes];

    // this will be how many of the values are actually filled, I could use dynamic memory allocation but it's too complicated for me
    int list_size;

    // Implement how to handle rows and column with maths :)
    int rows = pow(2, var/2);
    int columns = pow(2, (var+1)/2);

    // having predefined strings to input values into
    char bool_func[MAX];
    char listasstr[MAX];

    //INPUT
    printf("Which type of question do you have:\n");
    printf("1. Boolean function\n");
    printf("2. List of Ones\n");

    int choice;
    scanf("%d", &choice);

    // making decisions based on the choice
    if (choice == 1)
    {
        printf("Enter the Boolean Function: ");
        scanf("%s", &bool_func);

        // Convert into list of ones
        printf("IN PROGRESS\n");
        parse_bool_into_list(listofones, bool_func);

        return 1;
    }

    else
    {
        printf("Enter the list of Ones seperated by commas\n");
        printf("i.e. 0,1,3 :\n");
        scanf("%s", &listasstr);
        
        parse_str_into_list(listofones, listasstr, &list_size);
    }

    // making a boolean matrix because it takes less space and 1 == true and 0 == false
    bool k_map [rows][columns];
    memset(k_map, 0, sizeof(k_map));

    // finding out where in the matrix I should put ones and where not
    for (int k = 0; k < list_size; k++) {
        int index = listofones[k];
        int i = index / columns;  // row
        int j = index % columns;  // column
        k_map[i][j] = 1;
    }

    print_bool_matrix(rows, columns, k_map);

}
























































































// turning the string intake into list
void parse_str_into_list(int listofones[], char listasstr[], int *size)
{
    int counter = 0;
    char *temp_block = strtok(listasstr, ",");

    while (temp_block != NULL)
    {
        listofones[counter] = atoi(temp_block); // convert string to integer
        counter++;
        temp_block = strtok(NULL, ","); // get next block
    }

    *size = counter;
}


// in progress
void parse_bool_into_list(int listofones[], char bool_func[])
{
    printf("I guess working");
}


// basic printing the list
void printlist(int list[], int length)
{
    printf("\nPrinting List\n");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// printing them like numpyy arrays
void print_bool_matrix(int rows, int columns,bool matrix[rows][columns])
{
    printf("Printing k_map\n");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < columns; j++) {
            printf("%d", matrix[i][j]);  // prints 0 or 1
            if (j < columns - 1) printf(" ");
        }
        printf("]\n");
    }
}