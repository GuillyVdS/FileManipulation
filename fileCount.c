#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//this program will read a single line in a text file.
int main(int argc, char *argv[]){
  // initialises two character arrays: one for the file name, the second for the file content.
  char inputFile[50];
  char fileContent[100];
  char character;
  int counter;

  /*takes the name of the file to be read as an argument on the command line when running this program and stores it in the inputFile string
  if the argument exceeds 50 characters, it will return an error and exit the program.
  */
  if(strlen(argv[1]) > 50)
  {
    printf("Argument exceeds allowed length.\n" );
    exit(1);
  }
  strcpy(inputFile, argv[1]);





  FILE *fileToRead;
  if ((fileToRead = fopen(inputFile, "r")) == NULL){
    printf("Unable to read file.\n" );
  }
  for( character = getc(fileToRead); character  != EOF; character = getc(fileToRead))
  {
    if(character == '\n')
    {counter += 1; }
  }
  //find out size of file and print amount of bytes
  fseek(fileToRead, 0L , SEEK_END);
  printf("This file has a size of %ld bytes", ftell(fileToRead));
  /*
  scanf(fileToRead, "%[^\n]", fileContent);
  printf("%s \n" , fileContent);
  */

  printf("This file contains %d lines. \n", counter );
  fclose(fileToRead);
}
