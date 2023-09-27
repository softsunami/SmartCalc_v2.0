.PHONY: tests

CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

TEST_SRC = $(wildcard tests/*.cc)
MODEL_SRC = model/arithmetic_calc.cc model/finance_calc.cc model/graph.cc model/validator.cc

all:
	$(MAKE) clean
	$(MAKE) uninstall
	$(MAKE) install


tests:
	$(CC) $(CFLAGS) $(TEST_SRC) $(MODEL_SRC) -lgtest -o test_calc
	./test_calc

install:
	$(MAKE) uninstall
	mkdir SmartCalc
	cd SmartCalc && qmake "../" && make && make clean && rm Makefile && rm .qmake.stash

uninstall:
	rm -rf SmartCalc

dvi:
	open ../README.md
dist:
	cd .. && tar -cf src.tar src && mv src.tar src

clean:
	@rm -rf *.tar SmartCalc test_calc

style:
	clang-format -style=Google -n controller/* model/* view/*.cc view/*.h tests/*
