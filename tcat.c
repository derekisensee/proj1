#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000
int main(int argc, char* argv[]) {
  if (argc == 1) { // if no args given
    printf("Arg error! No args given.\n");
    return 0;
  }

  int c = 1;
  FILE *fp;
  
  while (c < argc) {
    if ((fp = fopen(argv[c], "r")) == NULL) {
      printf("File error! It doesn't exist :(\n");

      exit(1);
    }

    char line[1000];
    size_t len = 0;
    ssize_t read;

    while (fgets(line, MAX_LENGTH, fp) != NULL)
      printf("%s", line);
    c = c + 1;
  }
  
  fclose(fp);
  
  return 0;
}
