# -*- Makefile -*-

# target: dependencies
# 	action

all: test usecase

test: bst.cpp #change to test_bst later
	g++ bst.cpp -o test
usecase: main.cpp
	g++ main.cpp -o usecase

clean:
	rm test usecase