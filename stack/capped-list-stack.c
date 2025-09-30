#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void* next;
  int32_t value;
} node_t;

typedef struct {
  node_t* top;
} list_t;

int32_t stack_init(list_t* self) {
  self->top = NULL;
  return 0;
}

int32_t stack_push(list_t* self, int32_t value) {
  node_t* new_top = malloc(sizeof(node_t));
  new_top->next = self->top;
  new_top->value = value;
  self->top = new_top;
  return 0;
}

int32_t stack_pop(list_t* self, int32_t* returns) {
  *returns = self->top->value;
  node_t* new_top = self->top->next;
  free(self->top);
  self->top = new_top;
  return 0;
}

int32_t stack_free(list_t* self) {
  while (self->top != NULL) {
    node_t* new_top = self->top->next;
    free(self->top);
    self->top = new_top;
  }
  return 0;
}

int32_t stack_get_length(list_t* self) {
  int32_t count = 0;
  for (node_t* now = self->top; now != NULL; now = now->next) {
    count++;
  }
  return count;
}

int32_t stack_debug(list_t* self) {
  printf("[DEBUG: stack]\n");
  
  int32_t count = 0;
  for (node_t* now = self->top; now != NULL; now = now->next) {
    printf("[%d], %d\n", count, now->value);
    count++;
  }
  return 0;
}

int main() {
  list_t* a = malloc(sizeof(list_t));
  stack_init(a);
  
  stack_push(a, 0);
  stack_push(a, 30);
  int32_t b;
  stack_pop(a, &b);
  stack_debug(a);
  // printf("%d\n", b);
  stack_free(a);
  return 0;
}
