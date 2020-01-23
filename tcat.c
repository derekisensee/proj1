#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000
int main(int argc, char* argv[]) {
  if (argc == 1) { // if no args given
    printf("Arg error! No args given.\n");
    return 0;
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("File error! It doesn't exist :(\n");

    exit(1);
  }

  //char * line = NULL;
  char line[1000];
  size_t len = 0;
  ssize_t read;

  /*while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s", line);
  }*/

  while (fgets(line, MAX_LENGTH, fp) != NULL)
    printf("%s", line);

  fclose(fp);
  
  return 0;
}
