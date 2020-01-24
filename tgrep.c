#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

int main(int argc, char* argv[]) {
  if (argc == 1) { // if no args passed
    printf("tgrep: searchterm [file...]\n");
  }

  // searching from keyboard input (stdin)
  if (argc == 2) {

  }

  // searching in a file
  if (argc == 3) {
    char *searchWord = argv[1]; // the string we're searching for
    FILE *fp; // our file
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
      printf("tgrep: cannot open file\n");
      exit(1);
    }
    
    // line stuff
    char *buffer;
    size_t buffsize = 32;
    size_t chars;

    buffer = (char *)malloc(buffsize * sizeof(char));
    chars = getline(&buffer, &buffsize, fp);
    // ? now what ?

    // ... and close.
    fclose(fp);
  }
}
