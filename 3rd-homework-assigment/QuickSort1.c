#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choose_pivot(int array[], int start, int end);
int partition(int array[], int start, int end, int pivot_index);
void quicksort(int array[], int start, int end);
int *read_numbers(const char *filename, int *num_elements);


int main() {
  double sum = 0;
  for (int i = 0; i < 10; i++)
  {
    // int n = sizeof(array) / sizeof(array[0]);
    int num_elements; 
    int *array = read_numbers("./Study_2/5_000DescendingNumbers.txt", &num_elements);

    clock_t start = clock();

    quicksort(array, 0, num_elements-1);


    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    sum += elapsed_time;
    printf("%d.Test: Time taken by Quick sort: %f seconds\n", i+1, elapsed_time);
    // for (int i = 0; i < num_elements; i++)
    // {
    //   printf("%d ", array[i]);
    // }
    // printf("\n ");
  }
  
  printf("Average is %f \n", sum / 10.0);
  return 0;
}

// Chooses the pivot by finding the median of the first, middle, and last element
// uses bitwise XOR operator.
int choose_pivot(int array[], int start, int end) {
  int mid = start + (end - start) / 2;

  if ((start > end) ^ (start > mid)) 
    return start;
  else if ((end < start) ^ (end < mid)) 
    return end;
  else
    return mid;
}

int partition(int array[], int start, int end, int pivot_index) {
  int pivot = array[pivot_index];


  int temp = array[end];
  array[end] = array[pivot_index];
  array[pivot_index] = temp;

  // Store the partition index
  int partition_index = start;

  // Move elements smaller than the pivot to the front of the array
  for (int i = start; i < end; i++) {
    if (array[i] < pivot) {
      temp = array[i];
      array[i] = array[partition_index];
      array[partition_index] = temp;
      partition_index++;
    }
  }

  // Swap the pivot element with the element at the partition index
  temp = array[partition_index];
  array[partition_index] = array[end];
  array[end] = temp;

  return partition_index;
}

// Recursively sorts the array using the Quicksort algorithm
void quicksort(int array[], int start, int end) {
  if (start < end) {
    int pivot_index = choose_pivot(array, start, end);
    int partition_index = partition(array, start, end, pivot_index);
    quicksort(array, start, partition_index - 1);
    quicksort(array, partition_index + 1, end);
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
  rewind(fp); // Return to the beginning of the file
  int i = 0;
  while (fscanf(fp, "%d", &arr[i]) == 1)
  {
    i++;
  }

  fclose(fp);

  return arr; 
}