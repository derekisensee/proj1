#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  // if given no files
  if (argc == 1) {
    printf("tzip:  file1 [file2 ...]\n");
    exit(1);
  }

  FILE *fp;
  int c = 1;
  // for every file given...
  while (c < argc) {
    fp = fopen(argv[c], "r"); // the current file we're on
    // check if valid
    if (fp == NULL) {
      printf("tzip: cannot open file\n");
      exit(1);
    }

    // now do the work

    // vars for line-by-line stuff
    char *line = NULL;
    size_t linesize = 0;
    ssize_t read;

    // for every line in the file
    while ((read = getline(&line, &linesize, fp)) != -1) {
      int a;
      int c_count; // our char-counter
      for (a = 0; line[a] != '\0'; ++a) { // while we don't encounter the line termination char, keep printing 
	//printf("%c", line[a]); // for testing
	
      }
    }
    c++;
  }
}
