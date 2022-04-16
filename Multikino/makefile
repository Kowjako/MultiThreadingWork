# sudo apt-get install libncurses5-dev
multithread: main.cpp
	g++ -pthread main.cpp Cashbox.cpp Cashbox.h CinemaHall.cpp CinemaHall.h Client.cpp Client.h -o main -lncurses

clean:
	rm *.o