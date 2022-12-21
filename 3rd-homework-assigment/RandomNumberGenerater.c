#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers() {
  FILE* fp = fopen("750_000numbers.txt", "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  srand(time(NULL)); // seed the random number generator

  for (int i = 0; i < 750000; i++) {
    int r = rand(); 
    fprintf(fp, "%d\n", r);
  }

  fclose(fp);
}

int main()
{
  generate_random_numbers();
  return 0;
}
