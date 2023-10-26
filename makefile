# -*- Makefile -*-

# -----
# target: dependencies
# 	action

# all: test 

# test: test_bst.cpp 
# 	g++ test_bst.cpp -o test

# usecase: main.cpp 
# 	g++ main.cpp usecase.cpp -o usecase

# main.o: main.cpp usecase.cpp bst.cpp bst.h
# 	g++ -c main.cpp

# clean:
# 	rm test usecase

# -----

# test: bst.cpp #change to test_bst later
#	g++ bst.cpp -o test

# usecase: main.cpp
# 	g++ main.cpp -o usecase

# driver: main.o test_bst.o
# 	g++ -o test test_bst.o
# 	g++ -o usecase main.o

#driver: test_bst.o
#	g++ -o test test_bst.o

# main.o: main.cpp usecase.cpp bst.cpp bst.h
# 	g++ -c main.cpp

#test_bst.o: bst.cpp bst.h test_bst.cpp
##	g++ -c test_bst.cpp

# clean:
# 	rm test usecase

driver: main.o 
	g++ -o usecase main.o

main.o: main.cpp usecase.cpp bst.cpp bst.h
	g++ -c main.cpp
