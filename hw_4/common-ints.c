#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define CAPACITY_MULTIPLIER 2

int comparator(const void * ta, const void * tb) {
  int a = *(int *) ta;
  int b = *(int *) tb;

  if(a == b) {
    return 0;
  } else if(a > b) {
    return 1;
  } else {
    return -1;
  }
}

typedef struct dynamic_array_s {
  size_t capacity;
  size_t size;
  int * items;
} dynamic_array_t;

dynamic_array_t * new_dynamic_array(int initial_capacity) {
  dynamic_array_t * a = malloc(sizeof(dynamic_array_t));
  a->capacity = initial_capacity;
  a->size = 0;
  a->items = malloc(a->capacity * sizeof(int));

  return a;
}

void delete_dynamic_array(dynamic_array_t * a) {
  free(a->items);
  free(a);
}

int main() {
  dynamic_array_t * array = new_dynamic_array(INITIAL_CAPACITY);

  while(1 == scanf("%d", &(array->items[array->size++]))) {
    if(array->size == array->capacity) {
      int new_capacity = array->capacity * CAPACITY_MULTIPLIER;
      dynamic_array_t * new_array = new_dynamic_array(new_capacity);
      memcpy(new_array->items, array->items, sizeof(int) * array->size);
      new_array->size = array->size;
      delete_dynamic_array(array);
      array = new_array;
    }
  }
  array->size--;
  scanf("---\n");
  
  qsort(array->items, array->size, sizeof(int), comparator);
  
  int t;
  while(1 == scanf("%d", &t)) {
    if(NULL != bsearch(&t, array->items, array->size
                       , sizeof(int), comparator)) {
      printf("%d\n", t);
    }
  }
  
  delete_dynamic_array(array);
  
  return EXIT_SUCCESS;
}

