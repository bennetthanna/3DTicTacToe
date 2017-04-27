all: tic_tac_toe.cpp
	g++ -Wall -o main tic_tac_toe.cpp

clean:
	$(RM) main