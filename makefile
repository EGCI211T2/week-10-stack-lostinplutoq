
CC = g++
CFLAGS = -I.
DEPS = node.h stack.h


all: stack1 stack2

# Exercise 1: Compile main.cpp
stack1: main.cpp $(DEPS)
	$(CC) main.cpp -o stack1

# Exercise 2: Compile main2.cpp
stack2: main2.cpp $(DEPS)
	$(CC) main2.cpp -o stack2

compile: stack1
compile2: stack2

# Run Exercise 1 
run: stack1
	./stack1 10 20 30 x 40 x

# Tests for Exercise 2 
test1: stack2
	./stack2 "{[]}[]" "{[]]" "[]" "{{ }}"

test2: stack2
	./stack2 "{[]}[]"

test3: stack2
	./stack2 "{[]"

test4: stack2
	./stack2 "{[}]"

test5: stack2
	./stack2 "{{"

test6: stack2
	./stack2 "{{}}"

# Clean up files
clean:
	rm -f stack1 stack2