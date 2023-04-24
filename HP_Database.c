#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

typedef struct{
    int id;
    char firstname[MAX];
    char lastname[MAX];
    char house[MAX];
    double gpa;
}record;

record *hardcodesix(record *rarray);
record *insertrecord(record *rarray, int *size, int *index);
void display(record *rarray, int size);
int removerecord(record *arr, int size);
void searchrecords(record *rarray, int size);
void exitandwrite(record *rarray, int size);

int main()
{


    record rarray[MAX];
    hardcodesix(rarray);
    int choice = -1;
    int size = 6;//starts size of array at 6 since 0-5 are hardcoded
    int idindex = 7;//starts id's at 7 since the first 6 are hardcoded in
    while(choice != 0)
    {
        printf("What would you like to do?\n");
        printf("A: Add Student Record\n");
        printf("R: Remove Student Record\n");
        printf("D: Display All Student Records\n");
        printf("L: Lookup Student Record\n");
        printf("E: Exit Program\n");
        printf("Enter an option:");
        char option;
        scanf(" %c", &option);
        option = toupper(option);//makes option always uppercase
        switch(option)
        {
            case 'A':
                printf("*************************************************************\n");
                printf("Adding new student to the system.\n");
                insertrecord(rarray, &size, &idindex);
                printf("*************************************************************\n");
                break;
            case 'R':
                printf("*************************************************************\n");
                printf("Removing student from the system.\n");
                size = removerecord(rarray, size);
                printf("*************************************************************\n");
                break;
            case 'D':
                printf("*************************************************************\n");
                printf("Displaying all student records.\n");
                display(rarray, size);
                printf("*************************************************************\n");
                break;
            case 'L':
                printf("*************************************************************\n");
                printf("Looking up a student record.\n");
                searchrecords(rarray, size);
                printf("*************************************************************\n");
                break;
            case 'E':
                printf("*************************************************************\n");

                printf("Exiting the system and saving records to a text file called records.txt.\n");
                exitandwrite(rarray,size);
                choice = 0;//terminates loop
                printf("*************************************************************\n");
                break;
            default://if an option is entered that is not part of the menu, asks for input again
                printf("*************************************************************\n");
                printf("Invalid Selection...\n");
                printf("*************************************************************\n");
        }
    }

    return 0;
}

record *hardcodesix(record *rarray)
{
    rarray[0].id = 1;//hardcodes the first 6 elements of the struct array with student records
    strcpy(rarray[0].firstname, "Harry");
    strcpy(rarray[0].lastname, "Potter");
    strcpy(rarray[0].house, "Gryffindor");
    rarray[0].gpa = 3.87;

    rarray[1].id = 2;
    strcpy(rarray[1].firstname, "Ron");
    strcpy(rarray[1].lastname, "Weasley");
    strcpy(rarray[1].house, "Gryffindor");
    rarray[1].gpa = 3.01;

    rarray[2].id = 3;
    strcpy(rarray[2].firstname, "Hermione");
    strcpy(rarray[2].lastname, "Granger");
    strcpy(rarray[2].house, "Gryffindor");
    rarray[2].gpa = 4.00;

    rarray[3].id = 4;
    strcpy(rarray[3].firstname, "Draco");
    strcpy(rarray[3].lastname, "Malfoy");
    strcpy(rarray[3].house, "Slytherin");
    rarray[3].gpa = 2.57;

    rarray[4].id = 5;
    strcpy(rarray[4].firstname, "Luna");
    strcpy(rarray[4].lastname, "Lovegood");
    strcpy(rarray[4].house, "Ravenclaw");
    rarray[4].gpa = 3.42;

    rarray[5].id = 6;
    strcpy(rarray[5].firstname, "Cedric");
    strcpy(rarray[5].lastname, "Diggory");
    strcpy(rarray[5].house, "Hufflepuff");
    rarray[5].gpa = 3.38;


    return rarray;//returns the hardcoded arrays
}

record *insertrecord(record *rarray, int *size, int *idindex)
{
    printf("Enter the student's first name:");
    scanf(" %s", rarray[*size].firstname);//takes user input for first and last name and inputs into array starting at next index
    printf("Enter the student's last name:");
    scanf(" %s", rarray[*size].lastname);
    rarray[*size].id = *idindex;//assigns id number to student, then pointer updates after each student inputted, so none have same id
    ++*idindex;

    int choice = 1;

    while(choice == 1)
    {
        printf("Please select one of the following for the students house.\n");
        printf("1: Gryffindor\n");
        printf("2: Hufflepuff\n");
        printf("3: Ravenclaw\n");
        printf("4: Slytherin\n");
        printf("Enter key:");
        char option;//takes user input as char to avoid infinite loop from incorrect inputs
        scanf(" %c", &option);

        if(isdigit(option) != 0)
        {
            switch(option)//menu that assigns house to student record based on user input
            {
                case '1':
                {
                    strcpy(rarray[*size].house, "Gryffindor");//copies name of house into string for the struck
                    printf("Gryffindor Selected\n");
                    choice = 0;
                    break;
                }
                case '2':
                {
                    strcpy(rarray[*size].house, "Hufflepuff");//copies name of house into string
                    printf("Hufflepuff Selected\n");
                    choice = 0;
                    break;
                }
                case '3':
                {
                    strcpy(rarray[*size].house, "Ravenclaw");//copies name of house into string
                    printf("Ravenclaw Selected\n");
                    choice = 0;
                    break;
                }
                case '4':
                {
                    strcpy(rarray[*size].house, "Slytherin");//copies name of house into string
                    printf("Slytherin Selected\n");
                    choice = 0;
                    break;
                }
                default:
                {
                    printf("Sorry! Invalid input. Please try again\n");
                    choice = 1;//loops again if user inputs option not on menu
                    break;
                }
            }
        }
        if(isdigit(option) == 0)
        {
            printf("Invalid input. Please try again.\n");
            choice = 1;//loops again if user inputs option not a digit
        }
    }
    printf("What is the student's GPA:");
    scanf(" %lf", &rarray[*size].gpa);//takes user input for gpa
    ++*size;//increments size after record is entered so total array size is updated
    return rarray;
}

void display(record *rarray, int size)
{
    printf("*********************************\n");
    for(int x = 0; x < size; ++x)//loops through all elements in struct array and prints each one
    {
        printf("Id:                %d\n", (x + rarray)->id);//x + increments through the struct of arrays so it prints the next element
        printf("First Name:        %s\n", (x + rarray)->firstname);
        printf("Last Name:         %s\n", (x + rarray)->lastname);
        printf("House:             %s\n", (x + rarray)->house);
        printf("GPA:               %0.2f\n", (x + rarray)->gpa);
        printf("*********************************\n");
    }
}

int removerecord(record *arr, int size)
{
    printf("*********************************\n");
    printf("Removing Student Function Invoked\n");
    printf("Enter the Student's first name:");
    char firstindex[MAX];
    scanf(" %s", firstindex);
    printf("Enter the Student's last name:");
    char lastindex[MAX];
    scanf(" %s", lastindex);//takes user input for first and last name and enters them into their own array


    for(int i = 0; i < size; i++)
    {
        if(strcmp(firstindex, arr[i].firstname) == 0 && strcmp(lastindex, arr[i].lastname) == 0)//compares user inputted array with array in structs
        {
            for(i = i; i <= size - 1; i++)//loops through indexes starting at struct to be removed
            {
                arr[i].id = arr[i+1].id;
                strcpy(arr[i].firstname, arr[i+1].firstname);//shifts the first names down 1 index, and thus removing the first name part of struct at desired index
                strcpy(arr[i].lastname, arr[i+1].lastname);//shifts the last names down 1 index, and thus removing the last name part of struct at desired index
                strcpy(arr[i].house, arr[i+1].house);//shifts the house names down 1 index, and thus removing the house part of struct at desired index
                arr[i].gpa = arr[i+1].gpa;//shifts the gpa down by 1, also removing the gpa from the desired index
            }
            return size - 1;//decrements current size by 1 since a record has been removed
        }
    }
    printf("Sorry! You did not enter a valid index. Please try again.\n");
    return size;//if the name entered is not in the record database it returns the unchanged size
}

void searchrecords(record *rarray, int size)
{
    printf("Enter the Student's first name:");//
    char firstindex[MAX];
    scanf(" %s", firstindex);
    printf("Enter the Student's last name:");
    char lastindex[MAX];
    scanf(" %s", lastindex);//takes user input and puts them into array to be compared
    int i;
    int x = 0;
    for( i = 0; i <= size -1; i++)
    {
        if(strcmp(firstindex, rarray[i].firstname) == 0 && strcmp(lastindex, rarray[i].lastname) == 0)//compares first and last name with structs to see if they match
        {
            printf("Here is the student info.\n");//prints student info if the user input matches any of the records
            printf("*********************************\n");
            printf("Id:                %d\n", rarray[i].id);
            printf("First Name:        %s\n", rarray[i].firstname);
            printf("Last Name:         %s\n", rarray[i].lastname);
            printf("House:             %s\n", rarray[i].house);
            printf("GPA:               %0.2f\n", rarray[i].gpa);
            printf("*********************************\n");
            x = 1;
        }
    }

    if(x == 0)//if after looping through array and name does not match, prints sorry message
    {
        printf("Sorry! You did not enter a valid name.\n");
    }

}

void exitandwrite(record *rarray, int size)
{
    FILE *outp;//file pointer
    outp = fopen("records.txt","w");//opens file to write into
    int i = 0;//starts at first element of array
    while (i < size)//starts at zero and loops until it reaches 1 before the size of the array and prints into file
    {
        fprintf(outp, "Id:                %d\n", rarray[i].id);//prints each part of struct into file
        fprintf(outp, "First Name:        %s\n", rarray[i].firstname);
        fprintf(outp, "Last Name:         %s\n", rarray[i].lastname);
        fprintf(outp, "House:             %s\n", rarray[i].house);
        fprintf(outp, "GPA:               %0.2f\n", rarray[i].gpa);
        fprintf(outp, "*********************************\n");
        i++;
    }
    fclose(outp);//closes file
}

