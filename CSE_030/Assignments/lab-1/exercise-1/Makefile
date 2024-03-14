all:
	g++ main.cpp -g -I. -o app

.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	@rm -f test_all

clean:
	rm -f app
	rm -f test