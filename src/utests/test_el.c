/*
 * 
 * test_el.c
 *
 * Baltasar Dinis 89416
 * IAED project
 *
 * defines interaction to test the element datatype
 */


/*
 * TODO: Change
 * testing environment:
 *
 * receives as input a sequence of strings, each one is a position
 * converts them to positions (tests valid_pos and str_to_pos)
 * finds the maximum and minimum position (tests max_pos and min_pos)
 * prints all columns (test selector)
 * prints all rows (test selector)
 * prints all positions (test out_pos)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../el.h"

int main()
{
  int size;
  int i, j;
  pos *list;
  pos max, min;
  char *input = malloc(BUFFER_OUT_POS * sizeof(int));

  fscanf(stdin, "%d", &size);
  list = malloc(size * sizeof(pos));

  for (i = j = 0; i < size; i++) {
    if (fgets(input, size, stdin) != NULL) {
      if (valid_pos(input)) {
        printf("%d: valid input\n", i);
        list[j] = str_to_pos(input);

        if (j == 0) {
          max = min = list[i];
        }
        max = max_pos(max, list[j]);
        min = min_pos(min, list[j]);
        j++;
      }
    }
  }
  printf("\n");

  for (i = 0; i < j; i++) printf("col: %u\n", col(list[i])); 
  printf("\n");
  for (i = 0; i < j; i++) printf("row: %u\n", row(list[i])); 
  printf("\n");
  for (i = 0; i < j; i++) printf("%s\n", out_pos(list[i])); 

  return 0;
}



