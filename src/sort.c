/*
 *
 * sort.c
 *
 * Baltasar Dinis 89416
 * IAED project
 *
 * defines sorting functions
 *
 */

#include "sort.h"
#include "sparse.h"

/* gets the first key: row of the position */
unsigned long key_row(item a)
{
  return row(pos(a));
}

/* gets the second key: col of the position */
unsigned long key_col(item a)
{
  return col(pos(a));
}


/* 
 * implements the counting sort using a certain compare function
 * 
 * l: leftmost position to consider
 * r: rightmost position to consider
 * m: minimum value of the key of the items of the list
 * M: maximum value of the key of the items of the list
 * key: returns the key to be considered
 */
void counting_sort(item list[], int l, int r, unsigned long m, unsigned long M, unsigned long (*key)(item))
{
  /* size_cnt is the number of possible keys */
  /* size_aux is the number of elements in list */
  int i;
  int size_cnt = M - m + 1, size_aux = r - l + 1;
  int cnt[size_cnt];
  item aux[size_aux];
  
  for (i = 0; i < size_cnt; cnt[i++] = 0);

  /* count; -m shifts input from at [m, M] to [0, M - m] */
  for (i = l; i <= r; i++) {
    cnt[(*key)(list[i]) - m + 1]++; 
  }

  /* accumulate */
  for (i = 1; i < size_cnt; i++) {
    cnt[i] += cnt[i - 1];
  }

  /* construct auxiliar */
  for (i = l; i <= r; i++) {
    aux[cnt[(*key)(list[i]) - m]++] = list[i];
  }

  /* copy to list */
  for (i = l; i <= r; i++) {
    list[i] = aux[i - l];
  }
}
/* implements radix sort LSD using a n key functions, 
 * given in a list of function pointers, with ascending significant
 *
 * ex: order a list of pairs of integers (x, y), with y being the 
 * least significant
 *
 * radix_sort(list, l, r, m_list, M_list, 
 * {<function that selects y>, <function that selects, x>, 2)
 */
void radix_sort(item list[], int l, int r, unsigned long m_list[], 
    unsigned long M_list[], unsigned long (*key_arr[])(item), int arglen)
{
  int i;
  for (i = 0; i < arglen; i++) {
    counting_sort(list, l, r, m_list[i], M_list[i], key_arr[i]);
  }
}


