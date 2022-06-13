/*
  How to C aka learning C by example

Resources:
 - GNU C Reference Manual: www.gnu.org/software/gcc/gcc.html
 - Lectures: home.agh.edu.pl/~pszwed/wiki/doku.php?id=programowanie_imperatywne
 - C reference: https://en.cppreference.com/w/c
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef __STDC_NO_COMPLEX__
#include <complex.h>
#endif

void htc_complex() {
#ifdef __STDC_NO_COMPLEX___
  printf("- Complex numbers are not supported\n");
#else
  printf("- Complex numbers are supported\n");
  double complex z0 = CMPLX(3.0, 4.0);
  float complex z1 = CMPLXF(-sqrt(2) / 2, sqrt(2) / 2);
  long double complex z2 = CMPLXL(1.1, -6.7);

  printf("z0 = (%f, %f)\t|z0| = %f\t\n", creal(z0), cimag(z0), cabs(z0));
  printf("z1 = (%f, %f)\t|z1| = %f\n", crealf(z1), cimagf(z1), cabsf(z1));
  printf("z2 = (%Lf, %Lf)\t|z2| = %Lf\n", creall(z2), cimagl(z2), cabsl(z2));

  double _Complex z3 = cexp(M_PI_2 * I);
  double _Complex z4 = csin(M_PI_4 * I);
  printf("z3 = (%f, %f)\t|z3| = %f\n", creal(z3), cimag(z3), cabs(z3));
  printf("z4 = (%f, %f)\t|z4| = %f\n", creal(z4), cimag(z4), cabs(z4));
#endif
}

void htc_random() {
  printf("- Random numbers from range [0, RAND_MAX=%d]\n", RAND_MAX);
  srand(time(NULL));
  printf("r0 = %d\n", rand());
  printf("r1 = %d\n", rand());
  printf("r2 = %d\n", rand());
}

int cmp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

void htc_algorithms() {
  printf("- QuickSort algorithm\n");
  size_t n = (size_t)(rand() % 10 + 5);
  int* t = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    t[i] = rand() % 99 + 1;
    printf("%d ", t[i]);
  }
  printf("--> ");

  qsort(t, n, sizeof(int), cmp);

  for (int i = 0; i < n; i++)
    printf("%d ", t[i]);
  printf("\n");

  printf("- BinarySearch algorithm\n");
  for (size_t i = 0; i < n; i++) {
    void* v = bsearch(&t[i], t, n, sizeof(int), cmp);
    printf("%d ", *(int*)v);
  }
  printf("\n");
}

void print_mat(size_t w, size_t h, int t[w][h]) {
  printf("- Printing matrix using nice function header\n");
  for (size_t i = 0; i < w; i++) {
    for (size_t j = 0; j < h; j++) {
      printf("%d ", t[i][j]);
    }
    printf("\n");
  }
}

void htc_matrix() {
  printf("- Creating matrix using designated initializers\n");
  int m[4][4] = {[0][0] = 1, [1][2] = 2};
  print_mat(4, 4, m);
}

void htc_vla() {
  printf("- Variable-length array\n");
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int t[n];
  for (int i = 0; i < n; i++) {
    t[i] = rand() % 100;
    printf("%d ", t[i]);
  }
  printf("\n");
}

void htc_enum() {
#define enum_str(val) #val
  printf("- Enums\n");

  enum color { red, green, blue };

  printf("%s = %d\n", enum_str(red), red);
  printf("%s = %d\n", enum_str(green), green);
  printf("%s = %d\n", enum_str(blue), blue);
}

void htc_strings() {
  printf("- Strings operations\n");
  char* s = "--> Hello World 2022 <--";
  printf("s = %s\n", s);
}

size_t len(float ptr[]) {
  return sizeof(ptr) / sizeof(ptr[0]);
}

void htc_sizeof() {
  printf("- Sizeof operations\n");
  float tab[] = {-2.1, -0.4, -5, -4.11, -34, -11.2};

  printf("sizeof(float) = %ld\n", sizeof(float));
  printf("sizeof(float*) = %ld\n", sizeof(float*));
  printf("sizeof(t[0]) = %ld\n", sizeof(tab[0]));
  printf("sizeof(*t) = %ld\n", sizeof(*tab));
  printf("sizeof(&*t) = %ld\n", sizeof(&*tab));
  printf("sizeof(t) = %ld\n", sizeof(tab));
  printf("sizeof(t) / sizeof(t[0]) = %ld\n", sizeof(tab) / sizeof(tab[0]));
  printf("len(t) = %ld\n", len(tab));
}

void htc_stack(int n) {
  register unsigned esp __asm__("esp");
  printf("- Stack: %u\n", esp);
  if (n)
    htc_stack(n - 1);
}

void htc_struct_sizeof() {
  printf("- Sizeof operations for structs\n");
  struct {
    unsigned char ch;
    unsigned short sh;
    double d;
  } s = {255, 65535, 0};

  struct __attribute__((packed)) {
    unsigned char ch;
    unsigned short sh;
    double d;
  } s_packed = {255, 65535, 0};

  printf("sizeof(s) = %ld\n", sizeof(s));
  printf("sizeof(s_packed) = %ld\n", sizeof(s_packed));
  printf("sizeof(...) = %ld\n", sizeof(char) + sizeof(short) + sizeof(double));

  for (u_char* i = &s; i < (u_char*)&s + sizeof(s); i++) {
    int a = *i;
    printf("%p: %u \n", i, *i);
  }
}

int main(int argc, char* argv[]) {
  htc_complex();
  htc_random();
  htc_algorithms();
  htc_strings();
  htc_sizeof();
  htc_enum();
  htc_vla();
  htc_matrix();
  htc_stack(5);
  htc_struct_sizeof();

  return 0;
}