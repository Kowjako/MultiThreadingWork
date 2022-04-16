#include <pthread.h>
#include <ncurses.h>
#include <stdlib.h> /* rand */
#include <unistd.h> /* sleep */
#include <iostream>

int THREAD_NUM;

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
	
	/* for(auto i = 0; i<THREAD_NUM; i++)
	{
		threadCallback = pthread_create(&Threads[i], NULL, NULL, (void*)i);
		if(threadCallback)
		{
			std::cout<<"Błąd podczas tworzenia wątku"<<std::endl;
			return -1;
		}
	} */

	/* for(auto i = 0; i<THREAD_NUM; i++)
	{
		threadCallback = pthread_join(Threads[i], NULL); // czekamy na ukończenie wątków 
		if(threadCallback)
		{
			std::cout<<"Błąd podczas joinowania wątku"<<std::endl;
			return -1;
		}
		std::cout<<"Poprawnie ukończony watek "<<i<<std::endl;
	} */

	int endFlag = 0;
	do
	{
		noecho();
		endFlag = getch();
	}
	while(endFlag != 27);

	for(auto i=0;i<THREAD_NUM;i++)
	{
		if(pthread_join(Threads[i], NULL) != 0)
		{
			std::cout<<"Klient zepsuł Multikino"<<std::endl;
			return -1;
		}
		std::cout<<"Klient: "<<i<<" opuszcza Multikino"<<std::endl;
	}

	std::cout<<"Koniec programu..."<<std::endl;
    pthread_exit(NULL);
}