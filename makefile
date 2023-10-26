# -*- Makefile -*-

# -----
# target: dependencies
# 	action

all: test usecase

test: test_bst.cpp 
	g++ test_bst.cpp -o test

usecase: main.cpp 
	g++ main.cpp -o usecase

clean:
	rm test usecase