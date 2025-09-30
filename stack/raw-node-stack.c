#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void* next;
  int32_t value;
} node_t;

// stack_init() is intentially missing. 

int32_t stack_push(node_t** self, int32_t value) {
  node_t* new_self = malloc(sizeof(node_t));
  new_self->next = *self;
  new_self->value = value;
  *self = new_self;
  return 0;
}

int32_t stack_pop(node_t** self, int32_t* returns) {
  *returns = (*self)->value;
  node_t* new_self = (*self)->next;
  free(*self);
  *self = new_self;
  return 0;
}

int32_t stack_free(node_t** self) {
  while (*self != NULL) {
    node_t* new_self = (*self)->next;
    free(*self);
    *self = new_self;
  }
  return 0;
}

int32_t stack_get_length(node_t* self) {
  int32_t count = 0;
  for (node_t* now = self; now != NULL; now = now->next) {
    count++;
  }
  return count;
}

int32_t stack_debug(node_t* self) {
  printf("[DEBUG: stack]\n");
  
  int32_t count = 0;
  for (node_t* now = self; now != NULL; now = now->next) {
    printf("[%d], %d\n", count, now->value);
    count++;
  }
  return 0;
}

int main() {
  node_t* a = NULL;
  stack_push(&a, 0);
  stack_push(&a, 30);
  int32_t b;
  // stack_pop(&a, &b);
  stack_debug(a);
  // printf("%d\n", b);
  stack_free(&a);
  return 0;
}
