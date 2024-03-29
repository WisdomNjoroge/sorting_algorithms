#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

int lomuto_partition(int *array, size_t size, int low, int high);
void quick_sort_recursive(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(int *a, int *b);
int LargestKnuthGap(int n);
void reduceGap(int *gap);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void cocktail_sort_list(listint_t **list);
void cocktail_sort_list(listint_t **list);

#endif
