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
    
    /*long fileSize = ftell(fp); // get size of file
    char *buffer = malloc(fileSize + 1);
    fread(buffer, 1, fileSize, fp);
    fclose(fp);
    printf("%s", buffer);
    c++;*/
    char *buffer = NULL;
    size_t buffsize = 0;
    ssize_t read;

    // go line by line
    while ((read = getline(&buffer, &buffsize, fp)) != -1) {
      fread(stdout, 1, 4, fp);
      fread(stdout, 1, 1, fp);
    }
    c++;
  }

}
