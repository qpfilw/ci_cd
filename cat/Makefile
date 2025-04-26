CC = gcc
CFLAGS = -std='c11' -Wall -Werror -Wextra

all: s21_cat style

s21_cat: s21_cat.o
	$(CC) $(CFLAGS) s21_cat.o -o s21_cat

s21_cat.o: s21_cat.c
	$(CC) $(CFLAGS) -c s21_cat.c

style:
	clang-format -style=Google -i *.c
	clang-format -style=Google -i *.h
	clang-format -style=Google -n *.c
	clang-format -style=Google -n *.h

clean:
	rm *.o s21_cat s21_cat_output1.txt s21_cat_output2.txt s21_cat_output3.txt s21_cat_output4.txt cat_output1.txt cat_output2.txt cat_output3.txt cat_output4.txt

rebuild: clean all

test:
	@echo "\033[1;34mRunning tests for s21_cat\033[0m"
	@echo "\033[1;34mTest with no flags\033[0m"
	@./s21_cat test_1.txt > s21_cat_output1.txt
	@./s21_cat test_2.txt > s21_cat_output2.txt
	@./s21_cat test_3_hidden.txt > s21_cat_output3.txt
	@./s21_cat test_4_empty.txt > s21_cat_output4.txt
	@cat test_1.txt > cat_output1.txt
	@cat test_2.txt > cat_output2.txt
	@cat test_3_hidden.txt > cat_output3.txt
	@cat test_4_empty.txt > cat_output4.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"
	@diff s21_cat_output4.txt cat_output4.txt && echo "\033[32mTest 4 correct\033[0m" || echo "\033[31mTest 4 failed\033[0m"

	@echo "\033[1;34mTest with flag -n\033[0m"
	@./s21_cat -n test_1.txt > s21_cat_output1.txt
	@./s21_cat -n test_2.txt > s21_cat_output2.txt
	@./s21_cat -n test_3_hidden.txt > s21_cat_output3.txt
	@cat -n test_1.txt > cat_output1.txt
	@cat -n test_2.txt > cat_output2.txt
	@cat -n test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -b\033[0m"
	@./s21_cat -b test_1.txt > s21_cat_output1.txt
	@./s21_cat -b test_2.txt > s21_cat_output2.txt
	@./s21_cat -b test_3_hidden.txt > s21_cat_output3.txt
	@cat -b test_1.txt > cat_output1.txt
	@cat -b test_2.txt > cat_output2.txt
	@cat -b test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -e\033[0m"
	@./s21_cat -e test_1.txt > s21_cat_output1.txt
	@./s21_cat -e test_2.txt > s21_cat_output2.txt
	@./s21_cat -e test_3_hidden.txt > s21_cat_output3.txt
	@cat -e test_1.txt > cat_output1.txt
	@cat -e test_2.txt > cat_output2.txt
	@cat -e test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -s\033[0m"
	@./s21_cat -s test_1.txt > s21_cat_output1.txt
	@./s21_cat -s test_2.txt > s21_cat_output2.txt
	@./s21_cat -s test_3_hidden.txt > s21_cat_output3.txt
	@cat -s test_1.txt > cat_output1.txt
	@cat -s test_2.txt > cat_output2.txt
	@cat -s test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -t\033[0m"
	@./s21_cat -t test_1.txt > s21_cat_output1.txt
	@./s21_cat -t test_2.txt > s21_cat_output2.txt
	@./s21_cat -t test_3_hidden.txt > s21_cat_output3.txt
	@cat -t test_1.txt > cat_output1.txt
	@cat -t test_2.txt > cat_output2.txt
	@cat -t test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -v\033[0m"
	@./s21_cat -v test_1.txt > s21_cat_output1.txt
	@./s21_cat -v test_2.txt > s21_cat_output2.txt
	@./s21_cat -v test_3_hidden.txt > s21_cat_output3.txt
	@cat -v test_1.txt > cat_output1.txt
	@cat -v test_2.txt > cat_output2.txt
	@cat -v test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -n -b\033[0m"
	@./s21_cat -n -b test_1.txt > s21_cat_output1.txt
	@./s21_cat -n -b test_2.txt > s21_cat_output2.txt
	@./s21_cat -n -b test_3_hidden.txt > s21_cat_output3.txt
	@cat -n -b test_1.txt > cat_output1.txt
	@cat -n -b test_2.txt > cat_output2.txt
	@cat -n -b test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -s -n -e\033[0m"
	@./s21_cat -s -n -e test_1.txt > s21_cat_output1.txt
	@./s21_cat -s -n -e test_2.txt > s21_cat_output2.txt
	@./s21_cat -s -n -e test_3_hidden.txt > s21_cat_output3.txt
	@cat -s -n -e test_1.txt > cat_output1.txt
	@cat -s -n -e test_2.txt > cat_output2.txt
	@cat -s -n -e test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -n -e -s -t -v\033[0m"
	@./s21_cat -n -e -s -t -v test_1.txt > s21_cat_output1.txt
	@./s21_cat -n -e -s -t -v test_2.txt > s21_cat_output2.txt
	@./s21_cat -n -e -s -t -v test_3_hidden.txt > s21_cat_output3.txt
	@cat -n -e -s -t -v test_1.txt > cat_output1.txt
	@cat -n -e -s -t -v test_2.txt > cat_output2.txt
	@cat -n -e -s -t -v test_3_hidden.txt > cat_output3.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
	@diff s21_cat_output2.txt cat_output2.txt && echo "\033[32mTest 2 correct\033[0m" || echo "\033[31mTest 2 failed\033[0m"
	@diff s21_cat_output3.txt cat_output3.txt && echo "\033[32mTest 3 correct\033[0m" || echo "\033[31mTest 3 failed\033[0m"

	@echo "\033[1;34mTest with flag -n -e -s -t -v two files\033[0m"
	@./s21_cat -n -e -s -t -v test_1.txt test_2.txt > s21_cat_output1.txt
	@cat -n -e -s -t -v test_1.txt test_2.txt > cat_output1.txt
	@diff s21_cat_output1.txt cat_output1.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"

	@echo "\033[1;34mTest empty file\033[0m"
	@./s21_cat test_4_empty.txt > s21_cat_output4.txt
	@cat test_4_empty.txt > cat_output4.txt
	@diff s21_cat_output4.txt cat_output4.txt && echo "\033[32mTest 1 correct\033[0m" || echo "\033[31mTest 1 failed\033[0m"
