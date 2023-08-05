/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The setup for Week 1 assignment
 *
 * This file includes all the required functions implementations in the Week 1 assignment
 *
 * @author Hung Quang Nguyen
 * @date 08/04/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char minimum;
  unsigned char maximum;
  float median;
  float mean;

  /* Statistics and Printing Functions Go Here */
  printf("The initial array: ");
  print_array(&test, SIZE); 
  printf("The sorted array: ");
  sort_array(&test, SIZE);
  print_array(&test, SIZE); 
  mean = find_mean(&test, SIZE);
  maximum = find_maximum(&test, SIZE);
  minimum = find_minimum(&test, SIZE);
  median = find_median(&test, SIZE);

  print_statistics(minimum, maximum, median, mean); 
}

/* Functions */
void print_statistics (unsigned char minimum, unsigned char maximum, float median, float mean) {
  printf("The minimum: %d \n", minimum);
  printf("The maximum: %d \n", maximum);
  printf("The median: %.2f \n", median);
  printf("The mean: %.2f \n", mean);
}

void print_array (unsigned char *array, unsigned int size){
  for ( int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  } 
  printf("\n");
  }

float find_median (unsigned char *array, unsigned int size) {
  unsigned char med;
  // Odd size array
  if (size % 2 != 0)
  {
    return (float)array[size/2];
  }
  // Even size arry
  else
  {
    unsigned char mid1 = array[size/2 - 1];
    unsigned char mid2 = array[size/2];
    return (float)((mid1 + mid2)/2);
  }
  }

float find_mean (unsigned char *array, unsigned int size) {
    int sum = 0;
    float mean = 0 ;
    for (int i = 0; i < size; i++) {
      sum = sum + array[i];
    }
    mean = ((float) sum)/size;
    return mean;
  }

unsigned char find_maximum (unsigned char *array, unsigned int size) {
  unsigned char max  = array[size - 1];
  return max;
  }

unsigned char find_minimum (unsigned char *array, unsigned int size) {
  unsigned char min = array[0];
  return min;
  }

void sort_array (unsigned char *array, unsigned int size) {
  unsigned char temp;
  unsigned char temp_min;
  for (int i = 0; i < size - 1; i++)
  {
    // Find the minimum element in unsorted array
    temp_min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < array[temp_min]) 
      {
        temp_min = j;
      }
    }
    // Swap the position
    if (temp_min != i)
    {
      temp = array[temp_min];
      array[temp_min] = array[i];
      array[i] = temp;
    }
  }
  }

