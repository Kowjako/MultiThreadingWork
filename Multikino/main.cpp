#include <pthread.h>
#include <ncurses.h>
#include <stdlib.h> /* rand */
#include <unistd.h> /* sleep */
#include <iostream>

#include "CinemaHall.h"
#include "Cashbox.h"

int THREAD_NUM;

/* Deklaracja naszych zasobów */
CinemaHall* cinemaHall;
Cashbox* cashBox;

const char* names[15] = {"Adam", "Robert", "John", "Charles", "William",
					     "Richard", "Thomas", "Daniel", "Matthew", "Anthony",
					     "Mark", "Donald", "Steven", "Paul", "Andrew"};
const char* surnames[15] = {"Smith", "Jones", "Taylor", "Williams", "Brown",
							"White", "Harris", "Martin", "Davies","Wilson",
							"Nixdorf","Evans","King","Green","Clark"};

void* startSimulation(void* args)
{
	Client* client = new Client(names[rand()%15], surnames[rand()%15]);
	client->BuyTicket(cashBox->GetTicket());
	pthread_exit(NULL);
}

int main(int args, char *argv[])
{
	srand(time(NULL));

	/* Sprawdzenie poprawności uruchomienia */
	if(args > 2)
	{
		std::cout<<"Należy podać tylko jeden parametr!"<<std::endl;
		return -1;	
	}

	initscr(); /* uruchomienie nowego okna */
	start_color(); /* uruchamiamy RGB */
	init_pair(1, COLOR_RED, COLOR_BLACK);

	attron(A_DIM);
	printw("Witamy w Multikino v2\n");
	attroff(A_DIM);
	refresh();

	THREAD_NUM = (int)(*argv[1]) - 48; /* wyłuskujemy wartość spod wskaźnika */
	pthread_t Threads[THREAD_NUM]; 

	/*Tworzenie naszybch zasobów*/
	cinemaHall = new CinemaHall(0); /* ustawiamy obecny czas sali */
	cashBox = new Cashbox(20); /* 20 biletów = 4 premiery po 5 klientow */
	cashBox->GenerateTickets(); /* tworzymy bielty naszego automatu */

	
	for(auto i = 0; i<THREAD_NUM; i++)
	{
		if(pthread_create(&Threads[i], NULL, &startSimulation, (void*)i) != 0)
		{
			std::cout<<"Błąd podczas tworzenia wątku"<<std::endl;
			return -1;
		}
		else
		{
			attron(COLOR_PAIR(1));
			printw("Klient: %d wchodzi do Multikina\n",i);
			attroff(COLOR_PAIR(1));
			refresh();
		}
	} 

	int endFlag = 0;
	do
	{
		noecho();
		endFlag = getch();;
	}
	while(endFlag != 'q'); /* pryzcisk 'q' kończy działanie aplikacji */

	for(auto i=0;i<THREAD_NUM;i++)
	{
		if(pthread_join(Threads[i], NULL) != 0)
		{
			std::cout<<"Klient zepsuł Multikino, przepraszamy za utrudnienia..."<<std::endl;
			return -1;
		}
		printw("Klient: %d opuszcza Multikino\n",i);
		refresh();
	}

	sleep(1);
	refresh();
	endwin(); /*zamykamy ncurses */

	std::cout<<"Koniec programu..."<<std::endl;
    pthread_exit(NULL);
}