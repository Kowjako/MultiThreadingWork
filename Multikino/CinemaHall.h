#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include <Client.h>

class CinemaHall
{
	public:
		CinemaHall(int actualTime);
		CinemaHall(int actualTime, std::vector<std::string> _schedule);

		void AddClient(Client client);
		void ClearHall();
		void StartFilm();
		void PrintCinemaHallInfo();

	private:
		int _actualTime;
		std::string _actualFilmInfo;
		std::vector<string> _schedule;
		std::vector<Client> _clients;

		void SetUpTimeAndSchedule();
};

#endif