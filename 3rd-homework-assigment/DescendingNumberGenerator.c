#include <stdio.h>
#include <stdlib.h>


void generate_random_numbers() {
  FILE* fp = fopen("500_000DescendingNumbers.txt", "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  for (int i = 500000; i > 0; i--) {
    int r = i; 
    fprintf(fp, "%d\n", r);
  }

  fclose(fp);
}

int main()
{
  generate_random_numbers();
  return 0;
}
