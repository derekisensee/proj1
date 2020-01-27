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
      for (a = 0; line[a] != '\0'; a++) { // while we don't encounter the line termination char, keep checking
	//printf("%c", line[a]); // for testing
	char curr = line[a]; // our current counter
	//int c_count[1] = {1}; // our char-counter
	int c_count = 1; 
	int b;
	// loop that counts duplicate chars. we break if we encounter a char not equal to the one we're checking
	for (b = a + 1; line[b] != '\0'; b++) {
	  if (line[b] == curr) {
	    c_count = c_count + 1;
	  }
	  else {
	    a = a + c_count - 1; // updates line counter so we don't recount lines
	    break;
	  }
	  //printf("%d", c_count[0]); // was using this to confirm what was being printed
	}	
	// done with counting, so print 4-byte binary integer | goofyiness occuring here?
	fwrite(&c_count, sizeof(int), 1, stdout);
	fwrite(&curr, sizeof(char), 1, stdout);
	//fprintf(stdout, "%c", curr);

	//printf("\n");
      }
    }
    c++;
  }
}
