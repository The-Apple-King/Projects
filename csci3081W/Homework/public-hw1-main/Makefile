CXX = g++

all: fruit
all: main
all: passwords_a
all: passwords_b


%.o: %.cc
	$(CXX) -c $< -o $@

passwords_a: passwords_a.o
	$(CXX) -o $@.out $^

passwords_b: passwords_b.o
	$(CXX) -o $@.out $^

fruit: fruit_class.o
	$(CXX) -o $@.out $^

main: main.o
	$(CXX) -o $@.out $^

duck: 
	g++ mallard.cc duck.cc canvasback.cc rubber.cc -o out.out

.PHONY: clean
clean:
	rm -f *.o *.out

