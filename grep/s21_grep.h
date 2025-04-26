#ifndef SRC_S21_GREP_H_
#define SRC_S21_GREP_H_
#define _POSIX_C_SOURCE 200809L

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_LEN 1024

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int lenth;
  char pattern[MAX_PATTERN_LEN];
  int file_count;
} GrepFlags;

GrepFlags flagsParser(int argc, char* argv[]);
void pattern_add(GrepFlags* flags, char* pattern);
void add_reg_from_file(GrepFlags* flags, char* filepath);
void processFile(GrepFlags flags, char* path, regex_t* reg);
void out_allfiles(GrepFlags flags, int argc, char* argv[]);
void option_flag_o(regex_t* re, char* line, char* filename, GrepFlags flags,
                   int line_number);
void output_line(char* line, int n);

#endif
