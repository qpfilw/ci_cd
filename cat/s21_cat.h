#ifndef SRC_S21_CAT_H_
#define SRC_S21_CAT_H_

#include <getopt.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int countFiles;
} CatFlags;

void scan_flags(int argc, char *argv[], CatFlags *catFlags, int *error);
FILE *check_flags(FILE *file, CatFlags *catFlags);
void print_flags(char *buf, CatFlags *catFlags);
void flag_t(char arr_chars, int *change_chars);
void flag_e(char *buf, size_t i, int *change_chars, CatFlags *catFlags);
void flags_n_b(CatFlags *catFlags, int *count_line, char *arr_chars);
void flag_v(char no_print, int *change_chars);
void count_empty_str(char *arr_chars, int *empty_strings);

#endif