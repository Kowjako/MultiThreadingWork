#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include "Client.h"
#include <vector>
#include <semaphore.h>
#include <ncurses.h>
#include <algorithm>

class CinemaHall
{
	public:
		virtual ~CinemaHall();
		CinemaHall(int actualTime);
		CinemaHall(int actualTime, std::vector<ScheduleElement> _schedule);

		void AddClient(Client* client);
		void StartFilm();
		void PrintCinemaHallInfo();
		void SetSchedule(std::vector<ScheduleElement> films);

	private:
		sem_t _semaphore;
		int _actualTime;
		ScheduleElement _actualFilmInfo;
		std::vector<ScheduleElement> _schedule;
		std::vector<Client*> _clients;

		void SetUpStartFilm();
		void ClearHall();
};

#endif