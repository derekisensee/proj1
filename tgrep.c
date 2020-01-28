#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main(int argc, char* argv[]) {
  if (argc == 1) { // if no args passed
    printf("tgrep: searchterm [file...]\n");
    exit(1);
  }

  // searching from keyboard input (stdin)
  if (argc == 2) {
    char *searchWord = argv[1];
    
    char in[4096];
    fgets(in, sizeof(in), stdin); // fgets takes input and saves it to "in"
    //getline(&in, &sizeof(in), stdin);

    if (strstr(in, searchWord)) {
      printf("%s", in);
    }
  }

  // searching in a file
  if (argc >= 3) {
    int c = 2;
    char *searchWord = argv[1]; // the string we're searching for
    while(c < argc) {
      FILE *fp; // our file
      fp = fopen(argv[c], "r");
      // check if valid
      if (fp == NULL) {
	printf("tgrep: cannot open file\n");
	exit(1);
      }
    
      // line stuff
      char *buffer = NULL;
      size_t buffsize = 0;
      ssize_t read;

      // get first line
      while ((read = getline(&buffer, &buffsize, fp)) != -1) {
	if (strstr(buffer, searchWord)) {
	  printf("%s", buffer);
	}
      }

      // ... and close.
      c++;
      fclose(fp);
    }
  }
}
