#include "s21_grep.h"
#

int main(int argc, char* argv[]) {
  GrepFlags flags = flagsParser(argc, argv);
  out_allfiles(flags, argc, argv);
  return 0;
}

void pattern_add(GrepFlags* flags, char* pattern) {
  if (flags->lenth + strlen(pattern) + 3 >= MAX_PATTERN_LEN) {
    fprintf(stderr, "Pattern is too long\n");
    exit(1);
  }
  if (flags->lenth != 0) {
    strcat(flags->pattern + flags->lenth, "|");
    flags->lenth++;
  }
  flags->lenth += sprintf(flags->pattern + flags->lenth, "(%s)", pattern);
}

void add_reg_from_file(GrepFlags* flags, char* filepath) {
  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    if (!flags->s) perror(filepath);
    exit(1);
  }
  char* line = NULL;
  size_t memlen = 0;
  ssize_t read;
  while ((read = getline(&line, &memlen, file)) != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    pattern_add(flags, line);
  }
  free(line);
  fclose(file);
}

GrepFlags flagsParser(int argc, char* argv[]) {
  GrepFlags flags = {0};
  int opt;
  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        flags.e = 1;
        pattern_add(&flags, optarg);
        break;
      case 'i':
        flags.i = REG_ICASE;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        add_reg_from_file(&flags, optarg);
        break;
      case 'o':
        flags.o = 1;
        break;
    }
  }
  flags.file_count = argc - optind;
  if (flags.lenth == 0) {
    pattern_add(&flags, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) flags.h = 1;
  return flags;
}

void output_line(char* line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}

void processFile(GrepFlags flags, char* path, regex_t* reg) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    if (!flags.s) perror(path);
    exit(1);
  }
  char* line = NULL;
  size_t memlen = 0;
  ssize_t read;
  int line_count = 1;
  int c = 0;
  while ((read = getline(&line, &memlen, file)) != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if ((result == 0 && !flags.v) || (flags.v && result != 0)) {
      if (!flags.c && !flags.l) {
        if (!flags.h && !flags.o) printf("%s:", path);
        if (flags.n && !flags.l && !flags.o) printf("%d:", line_count);
        if (flags.o) {
          option_flag_o(reg, line, path, flags, line_count);
        } else
          output_line(line, read);
      }
      c++;
    }
    line_count++;
  }
  free(line);
  if (flags.c && !flags.l) {
    if (!flags.h) printf("%s:", path);
    printf("%d\n", c);
  }
  if (flags.c && flags.l) {
    if (!flags.h) printf("%s:", path);
    printf("%d\n", c);
  }
  if (flags.l && c > 0) printf("%s\n", path);
  fclose(file);
}

void out_allfiles(GrepFlags flags, int argc, char* argv[]) {
  regex_t re;
  int error = regcomp(&re, flags.pattern, REG_EXTENDED | flags.i);
  if (error > 0) perror("ERROR");
  for (int i = optind; i < argc; i++) {
    processFile(flags, argv[i], &re);
  }
  regfree(&re);
}

void option_flag_o(regex_t* re, char* line, char* filename, GrepFlags flags,
                   int line_number) {
  regmatch_t match;
  int offset = 0;

  while (1) {
    int res = regexec(re, line + offset, 1, &match, 0);
    if (res != 0) {
      break;
    }
    if (!flags.h && flags.file_count > 1) {
      printf("%s:", filename);
    }
    if (flags.n) {
      printf("%d:", line_number);
    }
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(line[offset + i]);
    }
    puts("");
    offset += match.rm_eo;
  }
}