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


int main(int args, char *argv[])
{
	/* Sprawdzenie poprawności uruchomienia */
	if(args > 2)
	{
		std::cout<<"Należy podać tylko jeden parametr!"<<std::endl;
		return -1;	
	}

	THREAD_NUM = (int)(*argv[1]) - 48; /* wyłuskujemy wartość spod wskaźnika */
	pthread_t Threads[THREAD_NUM]; 

	/*Tworzenie naszybch zasobów*/
	cinemaHall = new CinemaHall(0); /* ustawiamy obecny czas sali */
	cashBox = new Cashbox(20); /* 20 biletów = 4 premiery po 5 klientow */
	cashBox->GenerateTickets(); /* tworzymy bielty naszego automatu */

	
	for(auto i = 0; i<THREAD_NUM; i++)
	{
		threadCallback = pthread_create(&Threads[i], NULL, NULL, (void*)i);
		if(threadCallback)
		{
			std::cout<<"Błąd podczas tworzenia wątku"<<std::endl;
			return -1;
		}
	} 

	char endFlag = 0;
	do
	{
		noecho();
		endFlag = getch();
	}
	while(endFlag != 'q'); /* pryzcisk 'q' kończy działanie aplikacji */

	for(auto i=0;i<THREAD_NUM;i++)
	{
		if(pthread_join(Threads[i], NULL) != 0)
		{
			std::cout<<"Klient zepsuł Multikino, przepraszamy za utrudnienia..."<<std::endl;
			return -1;
		}
		std::cout<<"Klient: "<<i<<" opuszcza Multikino"<<std::endl;
	}

	std::cout<<"Koniec programu..."<<std::endl;
    pthread_exit(NULL);
}