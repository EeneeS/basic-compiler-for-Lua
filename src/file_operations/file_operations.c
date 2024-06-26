#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *filename) {
  FILE *fptr;
  char *source_code;
  long file_size;

  fptr = fopen(filename, "r");

  if (fptr == NULL) {
    perror("Error opening file");
    return NULL;
  }

  fseek(fptr, 0, SEEK_END);
  file_size = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);

  source_code = malloc(file_size + 1);
  if (source_code == NULL) {
    perror("Error allocating memory");
    fclose(fptr);
    return NULL;
  }

  if (fread(source_code, 1, file_size, fptr) != file_size) {
    perror("Error reading file");
    free(source_code);
    fclose(fptr);
    return NULL;
  }

  source_code[file_size] = '\0';
  fclose(fptr);
  return source_code;
}
