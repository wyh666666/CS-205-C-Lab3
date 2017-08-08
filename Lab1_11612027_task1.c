#include <stdio.h>
/*
Designed by 11612027 Andrew Zhang (ZHANG JINPENG).
This program can welcome you to the C and C++ world.
*/
int main()
{
    int stuID;/*define student ID*/
    char name[100];/*define name*/

    /*user enter name*/
    printf("Please enter your name :");
    scanf("%s", &name);

    /*user enter student ID*/
    printf("Please enter your student ID (number only) :");
    scanf("%d", &stuID);

    /*print the welcome senctence*/
    printf("\nWelcome %d %s to the C and C++ world!\n", stuID, name);
    return 0;
}
