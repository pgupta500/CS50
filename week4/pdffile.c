#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// **Files, this is what we are learning pointers for**
// fopen to open a file for future reading or writing
// FILE *f = fopen("file.txt", "r");
// fclose closes a file.
// fread, fwrite read from and write to files respectively.


FILE *text = fopen("file.txt", "r");

//fread(buffer, 1, 4, text); text is the file name, buffer is where to store the data, 1 is the size of each element to read, 4 is the number of elements to read

//DETECTING IF THE FILE IS A PDF

int main(int argc, char *argv[]){
    // ensure proper usage
    if (argc != 2){
        printf("Usage: ./detect file.pdf\n");
        return 1;
    }

    // open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Could not open file.\n");
        return 1;
    }

    // Create buffer for file

    uint8_t buffer[4];

    // Create an array of signature bytes for PDF files
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46}; // corresponds to "%PDF"

    // read first four bytes from the file
    fread(buffer, 1, 4, file);

    // check if PDF signature
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i]){
            printf("Not a PDF file.\n");
            fclose(file);
            return 0;
        }
    }

    printf("PDF file detected.\n");
    // close file
    fclose(file);
    return 0;
}