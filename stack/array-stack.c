#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STACK_MAX_LENGTH 10000

typedef struct {
  int32_t array[STACK_MAX_LENGTH];
  int32_t top;
} stack_t;

int32_t stack_init(stack_t* self) {
  self->top = -1;
  return 0;
}

int32_t stack_push(stack_t* self, int32_t value) {
  self->top++;
  self->array[self->top] = value;
  return 0;
}

int32_t stack_pop(stack_t* self, int32_t* returns) {
  if (self->top == -1) {
    return -1;
  }
  *returns = self->array[self->top];
  self->top--;
  return 0;
}

int32_t stack_dbg(stack_t* self) {
  printf("[DEBUG: stack]\n");
  for (int32_t i = 0; i < self->top + 1; i++) {
    printf("[%d]: %d\n", i, self->array[i]);
  }
  return 0;
}

int main() {
  stack_t* a = malloc(sizeof(stack_t));
  stack_init(a);
  stack_push(a, 0);
  stack_push(a, 30); 
  stack_dbg(a);

  int32_t b = -1;
  stack_pop(a, &b);
  printf("%d\n", b);
  stack_dbg(a);
  return 0;
}
