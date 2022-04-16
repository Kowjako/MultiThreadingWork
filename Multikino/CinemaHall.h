#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include "Client.h"
#include <vector>
#include <semaphore.h>

class CinemaHall
{
	public:
		virtual ~CinemaHall();
		CinemaHall(int actualTime);
		CinemaHall(int actualTime, std::vector<std::string> _schedule);

		void AddClient(Client client);
		void ClearHall();
		void StartFilm();
		void PrintCinemaHallInfo();

	private:
		sem_t _semaphore;
		int _actualTime;
		std::string _actualFilmInfo;
		std::vector<std::string> _schedule;
		std::vector<Client> _clients;

		void SetUpStartFilm();
};

#endif