CC = gcc
CFLAGS = -std='c11' -Wall -Werror -Wextra
FILEPATH = ../build/

all: s21_grep style

s21_grep: s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o -o s21_grep

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c s21_grep.c

style:
	clang-format -style=Google -i *.c
	clang-format -style=Google -i *.h
	clang-format -style=Google -n *.c
	clang-format -style=Google -n *.h

clean:
	rm -f *.o s21_grep s21_grep_output1.txt grep_output1.txt s21_grep_output2.txt grep_output2.txt s21_grep_output3.txt grep_output3.txt s21_grep_output4.txt grep_output4.txt s21_grep_output5.txt grep_output5.txt s21_grep_output6.txt grep_output6.txt s21_grep_output7.txt grep_output7.txt s21_grep_output8.txt grep_output8.txt s21_grep_output9.txt grep_output9.txt s21_grep_output10.txt grep_output10.txt

rebuild: clean all

test:
	@echo "Running test 1: Basic functionality"
	@./s21_grep -e "h" test_1.txt > s21_grep_output1.txt
	@grep "h" test_1.txt > grep_output1.txt
	@diff s21_grep_output1.txt grep_output1.txt && echo "\033[32mTest 1: Basic functionality correct\033[0m" || echo "\033[31mTest 1: Basic functionality failed\033[0m"

	@echo "Running test 2: Case insensitive flag (-i)"
	@./s21_grep -i -e "int" test_2.txt > s21_grep_output2.txt
	@grep -i "int" test_2.txt > grep_output2.txt
	@diff s21_grep_output2.txt grep_output2.txt && echo "\033[32mTest 2: Case insensitive flag correct\033[0m" || echo "\033[31mTest 2: Case insensitive flag failed\033[0m"

	@echo "Running test 3: Count flag (-c)"
	@./s21_grep -c -e "he" test_3.txt > s21_grep_output3.txt
	@grep -c "he" test_3.txt > grep_output3.txt
	@diff s21_grep_output3.txt grep_output3.txt && echo "\033[32mTest 3: Count flag correct\033[0m" || echo "\033[31mTest 3: Count flag failed\033[0m"

	@echo "Running test 4: Invert match flag (-v)"
	@./s21_grep -v -e "e" test_4.txt > s21_grep_output4.txt
	@grep -v "e" test_4.txt > grep_output4.txt
	@diff s21_grep_output4.txt grep_output4.txt && echo "\033[32mTest 4: Invert match flag correct\033[0m" || echo "\033[31mTest 4: Invert match flag failed\033[0m"

	@echo "Running test 5: Line number flag (-n)"
	@./s21_grep -n -e "a" test_1.txt test_5.txt > s21_grep_output5.txt
	@grep -n "a" test_1.txt test_5.txt > grep_output5.txt
	@diff s21_grep_output5.txt grep_output5.txt && echo "\033[32mTest 5: Line number flag correct\033[0m" || echo "\033[31mTest 5: Line number flag failed\033[0m"

	@echo "Running test 6: File name flag (-h)"
	@./s21_grep -h -e "e" test_1.txt test_2.txt > s21_grep_output6.txt
	@grep -h "e" test_1.txt test_2.txt > grep_output6.txt
	@diff s21_grep_output6.txt grep_output6.txt && echo "\033[32mTest 6: File name flag correct\033[0m" || echo "\033[31mTest 6: File name flag failed\033[0m"

	@echo "Running test 7: Suppress error messages flag (-s)"
	@./s21_grep -s -e "rn" non_existent_file.txt > s21_grep_output7.txt || true
	@grep -s "rn" non_existent_file.txt > grep_output7.txt || true
	@diff s21_grep_output7.txt grep_output7.txt && echo "\033[32mTest 7: Suppress error messages flag correct\033[0m" || echo "\033[31mTest 7: Suppress error messages flag failed\033[0m"

	@echo "Running test 8: Read pattern from file flag (-f)"
	@./s21_grep -f pattern.txt test_1.txt > s21_grep_output8.txt
	@grep -f pattern.txt test_1.txt > grep_output8.txt
	@diff s21_grep_output8.txt grep_output8.txt && echo "\033[32mTest 8: Read pattern from file flag correct\033[0m" || echo "\033[31mTest 8: Read pattern from file flag failed\033[0m"

	@echo "Running test 9: Output only matching part flag (-o)"
	@./s21_grep -o -e "l" test_5.txt > s21_grep_output9.txt
	@grep -o "l" test_5.txt > grep_output9.txt
	@diff s21_grep_output9.txt grep_output9.txt && echo "\033[32mTest 9: Output only matching part flag correct\033[0m" || echo "\033[31mTest 9: Output only matching part flag failed\033[0m"

	@echo "Running test 10: Output only matching part and number of string flag (-n -o)"
	@./s21_grep -o -n "he" test_1.txt > s21_grep_output10.txt
	@grep -o -n "he" test_1.txt > grep_output10.txt
	@diff s21_grep_output10.txt grep_output10.txt && echo "\033[32mTest 10: Output only matching part and number of string flag correct\033[0m" || echo "\033[31mTest 10: Output only matching part and number of string flag failed\033[0m"
