#include "s21_cat.h"

int main(int argc, char *argv[]) {
  CatFlags catFlags = {0};
  int error = 0;
  if (argc > 1) {
    scan_flags(argc, argv, &catFlags, &error);

    if (!error) {
      while ((catFlags.countFiles) < argc) {
        FILE *file = fopen(argv[catFlags.countFiles], "r");
        if (file != NULL)
          fclose(check_flags(file, &catFlags));
        else {
          fprintf(stderr, "ERROR: file %s does not exist\n",
                  argv[catFlags.countFiles]);
          exit(1);
        }
        catFlags.countFiles += 1;
      }
    } else
      exit(1);
  } else {
    fprintf(stderr,
            "cat: illegal option %s\n usage: cat [-belnstuv] [file ...]",
            argv[1]);
    exit(1);
  }
  return 0;
}

void scan_flags(int argc, char *argv[], CatFlags *catFlags, int *error) {
  int opt;
  const char *short_opt = "beEnstTv";
  const struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                        {"number", 0, NULL, 'n'},
                                        {"squeeze-blank", 0, NULL, 's'},
                                        {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, short_opt, long_options, 0)) != -1) {
    switch (opt) {
      case 'b':
        catFlags->b = 1;
        break;
      case 'e':
        catFlags->e = 1;
        catFlags->v = 1;
        break;
      case 'E':
        catFlags->e = 1;
        break;
      case 'n':
        catFlags->n = 1;
        break;
      case 's':
        catFlags->s = 1;
        break;
      case 't':
        catFlags->t = 1;
        catFlags->v = 1;
        break;
      case 'T':
        catFlags->t = 1;
        break;
      case 'v':
        catFlags->v = 1;
        break;
      default:
        *error = 1;
        break;
    }
  }
  if (catFlags->b == 1 && catFlags->n == 1) catFlags->n = 0;
  catFlags->countFiles = optind;
}

FILE *check_flags(FILE *file, CatFlags *catFlags) {
  char buf[9000];
  int count_line = 1;
  int empty_strings = 0;
  int no_output_string = 0;

  while (fgets(buf, sizeof(buf), file) != NULL) {
    if (catFlags->s || catFlags->b) {
      count_empty_str(buf, &empty_strings);
      if (empty_strings > 1 && catFlags->s)
        no_output_string = 1;
      else
        no_output_string = 0;
    }

    if (!no_output_string) {
      flags_n_b(catFlags, &count_line, buf);
      print_flags(buf, catFlags);
    }
  }
  return file;
}

void print_flags(char *buf, CatFlags *catFlags) {
  for (size_t i = 0; buf[i] != '\0'; i++) {
    int change_chars = 0;
    if (catFlags->v) flag_v(buf[i], &change_chars);
    if (catFlags->e) flag_e(buf, i, &change_chars, catFlags);
    if (catFlags->t) flag_t(buf[i], &change_chars);
    if (!change_chars) printf("%c", buf[i]);
  }
}

void flag_t(char arr_chars, int *change_chars) {
  if (arr_chars == '\t') {
    putchar('^');
    putchar('I');
    *change_chars += 1;
  }
}

void flag_e(char *buf, size_t i, int *change_chars, CatFlags *catFlags) {
  if (buf[i] == '\n') {
    if (i == 0 && catFlags->b == 1)
      printf("      %c%c", '\t', '$');
    else
      putchar('$');
    putchar('\n');
    *change_chars += 1;
  }
}

void flags_n_b(CatFlags *catFlags, int *count_line, char *arr_chars) {
  if (catFlags->n) {
    printf("%6d\t", *count_line);
    *count_line += 1;
  } else if (catFlags->b) {
    if (arr_chars[0] != '\n') {
      printf("%6d\t", *count_line);
      *count_line += 1;
    }
  }
}

void flag_v(char no_print, int *change_chars) {
  if (no_print < -96) {
    printf("M-^%c", no_print + 192);
    *change_chars += 1;
  } else if (no_print < 0) {
    printf("M-%c", no_print + 128);
    *change_chars += 1;
  } else if ((0 <= no_print && no_print <= 31) && (no_print != 10) &&
             (no_print != 9)) {
    putchar('^');
    putchar(no_print + 64);
    *change_chars += 1;
  } else if (no_print == 127) {
    putchar('^');
    putchar('?');
    *change_chars += 1;
  }
}

void count_empty_str(char *arr_chars, int *empty_strings) {
  if (arr_chars[0] == '\n')
    *empty_strings += 1;
  else
    *empty_strings = 0;
}
