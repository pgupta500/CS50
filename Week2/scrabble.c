#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    string first = get_string("Player 1: ");
    string second = get_string("Player 2: ");

    int length1 = strlen(first);
    int length2 = strlen(second);
    int sum1=0;
    int sum2=0;
    char character1[length1];
    char character2[length2];

    for(int i=0;i<length1;i++){
        character1[i]=toupper(first[i]);
        if (
            character1[i] == 'A' ||
            character1[i] == 'E' ||
            character1[i] == 'I' ||
            character1[i] == 'L' ||
            character1[i] == 'N' ||
            character1[i] == 'O' ||
            character1[i] == 'R' ||
            character1[i] == 'S' ||
            character1[i] == 'T' ||
            character1[i] == 'U'){
                sum1 = sum1 + 1;
            }

        else if (character1[i] == 'D' || character1[i] =='G' ){
            sum1 = sum1+2;
        }
        else if (character1[i] == 'B' || character1[i] == 'C' || character1[i] == 'M' || character1[i] == 'P'){
            sum1 = sum1+3;
        }
        else if(character1[i] == 'F' || character1[i] == 'H' || character1[i] == 'V' || character1[i] == 'W' || character1[i] == 'Y' ){
            sum1 = sum1+4;
        }
        else if(character1[i] == 'K' ){
            sum1=sum1+5;
        }
        else if(character1[i] == 'J' || character1[i] == 'X' ){
            sum1=sum1+8;
        }
        else if(character1[i] == 'Q' || character1[i] == 'Z'){
            sum1=sum1+10;
        }
        else{
            sum1 = sum1 + 0;
        }
    }
    for (int i = 0; i < length2; i++) {
        character2[i] = toupper(second[i]);
        if (
            character2[i] == 'A' ||
            character2[i] == 'E' ||
            character2[i] == 'I' ||
            character2[i] == 'L' ||
            character2[i] == 'N' ||
            character2[i] == 'O' ||
            character2[i] == 'R' ||
            character2[i] == 'S' ||
            character2[i] == 'T' ||
            character2[i] == 'U'
        ) {
            sum2 = sum2 + 1;
        }
        else if (character2[i] == 'D' || character2[i] == 'G') {
            sum2 = sum2 + 2;
        }
        else if (character2[i] == 'B' || character2[i] == 'C' || character2[i] == 'M' || character2[i] == 'P') {
            sum2 = sum2 + 3;
        }
        else if (character2[i] == 'F' || character2[i] == 'H' || character2[i] == 'V' || character2[i] == 'W' || character2[i] == 'Y') {
            sum2 = sum2 + 4;
        }
        else if (character2[i] == 'K') {
            sum2 = sum2 + 5;
        }
        else if (character2[i] == 'J' || character2[i] == 'X') {
            sum2 = sum2 + 8;
        }
        else if (character2[i] == 'Q' || character2[i] == 'Z') {
            sum2 = sum2 + 10;
        }
        else{
            sum2 = sum2 + 0;
        }
    }


    if(sum1 == sum2){
        printf("Tie!\n ");
    }

    else if (sum1 > sum2){
        printf("Player 1 wins!\n ");
    }
    else if (sum2 > sum1){
        printf("Player 2 wins!\n ");
    }
}
