#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
int *read_numbers(const char *filename, int *num_elements);

// Driver function
int main()
{
  // int arr[] = {12, 11, 13, 5, 6, 7};
  // int arr_size = sizeof(arr) / sizeof(arr[0]);
  
  double sum = 0;
  for (int i = 0; i < 10; i++)
  {
    // int n = sizeof(array) / sizeof(array[0]);
    int num_elements; 
    int *array = read_numbers("./Study_2/5_000DescendingNumbers.txt", &num_elements);

    clock_t start = clock();

    merge_sort(array, 0, num_elements - 1);

    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    sum += elapsed_time;
    printf("%d.Test: Time taken by Merge sort: %f seconds\n", i+1, elapsed_time);
    // for (int i = 0; i < num_elements; i++)
    // {
    //   printf("%d ", array[i]);
    // }

  }
 
  printf("Average is %f \n", sum / 10.0);

  // for (int i=0; i < arr_size; i++)
  //   printf("%d ", arr[i]);
  // printf("\n");
  return 0;
}



void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;


  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
  // Merge the temporary arrays back into arr[l..r]
  i = 0; 
  j = 0; 
  k = l; 
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to sort an array using merge sort
void merge_sort(int arr[], int l, int r)
{
  if (l < r)
  {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort the first and second halves
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
      
    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

int *read_numbers(const char *filename, int *num_elements)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  int count = 0;
  int num;
  while (fscanf(fp, "%d", &num) == 1)
  {
    count++;
  }

  int *arr = (int*)malloc(count * sizeof(int));
  if (arr == NULL)
  {
    printf("Error allocating memory!\n");
    exit(1);
  }

  *num_elements = count;
  rewind(fp); 
  
  int i = 0;
  while (fscanf(fp, "%d", &arr[i]) == 1)
  {
    i++;
  }

  fclose(fp);

  return arr; 
}