#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include "Client.h"
#include <vector>
#include <semaphore.h>
#include <ncurses.h>

class CinemaHall
{
	public:
		virtual ~CinemaHall();
		CinemaHall(int actualTime);
		CinemaHall(int actualTime, std::vector<std::string> _schedule);

		void AddClient(Client client);
		void StartFilm();
		void PrintCinemaHallInfo();
		void SetSchedule(std::vector<std::string> films);

	private:
		sem_t _semaphore;
		int _actualTime;
		std::string _actualFilmInfo;
		std::vector<std::string> _schedule;
		std::vector<Client> _clients;

		void SetUpStartFilm();
		void ClearHall();
};

#endif