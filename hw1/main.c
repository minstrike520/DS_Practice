#include <stdio.h>
#include <stdint.h>

#define PLN_ALLOC_SIZE 100

typedef struct {
  int32_t coef;
  int32_t exp;
} pln_unit_t;

// (3, 4) -> 3x^4
// note: chr(0) = 48
int32_t pln_unit_exp(pln_unit_t *pln_unit, char *buf) {
  sprintf(buf, "%dx^%d", pln_unit->coef, pln_unit->exp);
  return 0;
}

int32_t pln_highest_exp(pln_unit_t *pln[], int32_t size) {
  int32_t exp = 0;
  for (int32_t i = 0; i < size; i++) {
    if (pln[i]->exp > exp) {
      exp = pln[i]->exp;
    }
  }
  return exp;
}

int32_t pln_nonzero_count(pln_unit_t *pln[], int32_t size) {
  int32_t count = 0;
  for (int32_t i = 0; i < size; i++) {
    if (pln[i]->coef != 0) {
      count++;
    }
  }
  return count;
}

int32_t pln_parse(char *str, pln_unit_t *pln[]) {
  int32_t arr[PLN_ALLOC_SIZE * 2];
  int32_t arr_p = 0;

  char buf[100];
  int32_t buf_p = 0;
  for (int32_t i = 0; i < 100; i++) {
    buf[i] = '\0';
  }
  bool after_some = true;
  for (int32_t i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      if (after_some) {
        arr[arr_p] = atol(buf);
        arr_p++;;
      }
      after_some = false;
      continue;
    }
    after_some = true;
    buf[buf_p] = str[i];
    buf_p++;
  }
  return 0;
}

void test_pln_unit_exp() {
  pln_unit_t a = { 3, 5 };
  char b[100];
  pln_unit_exp(&a, b);
  printf("%s", b);
}

void test_pln_parse() {

}

int main() {
  test_pln_unit_exp();
}
