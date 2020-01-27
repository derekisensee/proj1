#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("tzip:  file1 [file2 ...]\n");
    exit(1);
  }

  FILE *fp;
  int c = 1;
  // for every file given...
  while(c < argc) {
    fp = fopen(argv[c], "rb"); // need the 'b'?
    if (fp == NULL) {
      printf("tunzip:  cannot open file\n");
      int errnum = errno;
      printf(strerror(errnum));
      exit(1);
    }
    // create and allocate memory for int
    int out;
    char charOut; // the character
    fread(&out, sizeof(int), 1, fp);
    while(!feof(fp)) { 
      fread(&charOut, 1, 1, fp);
      printf("%d, %c\n", out, charOut);
      fread(&out, sizeof(int), 1, fp);
      //fread(&charOut, 1, 1, fp);
    }
    c++;
  }
}
