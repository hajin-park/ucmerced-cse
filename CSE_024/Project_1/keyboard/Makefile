all:
	g++ main.cpp -g -I. -o app

.PHONY: test

test:
	g++ -Wall -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color

clean:
	rm -f app
	rm -f test