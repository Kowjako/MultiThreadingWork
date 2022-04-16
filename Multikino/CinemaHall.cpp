#include "CinemaHall.h"

CinemaHall::CinemaHall(int actualTime)
{
	this->_actualTime = actualTime;
	sem_init(&this->_semaphore, 0, 5); /*inicjalizacja semaforu, 5 klientów jednocześnie */
}

CinemaHall::CinemaHall(int actualTime, std::vector<std::string> schedule) : CinemaHall(actualTime)
{
	this->_schedule = schedule;
}

CinemaHall::~CinemaHall()
{
	sem_destroy(&this->_semaphore); /* usuwamy semafor podczas usunięcia obiektu */
}

void CinemaHall::StartFilm()
{
	SetUpStartFilm();
	printw("Rozpoczety film: %s\n",this->_actualFilmInfo.data());
	for(auto i =0;i<this->_clients.size();i++)
	{
		this->_clients[i].WatchMovie(this->_actualFilmInfo); /* film trwa od 5 do 15 sekund */
		refresh();
	}
	sleep(6);
	ClearHall();
}

void CinemaHall::SetSchedule(std::vector<std::string> schedule)
{
	this->_schedule = schedule;
}

void CinemaHall::AddClient(Client client)
{
	sem_wait(&this->_semaphore);
	_clients.push_back(client); /* uzupełniamy naszych klientów */
	if(_clients.size() == 5)
	{
		StartFilm();
	}
}

void CinemaHall::ClearHall()
{
	printw("Koniec prezentacji filmu.\n");
	for(auto i = 0;i< this->_clients.size(); i++)
	{
		printw("Klient: %s opuscil sale\n", this->_clients[i].GetNameAndSurname().data());
		sem_post(&this->_semaphore); /* zwalniamy miejsca na naszej sali */
	}
	this->_clients.clear();
}

void CinemaHall::PrintCinemaHallInfo()
{
	start_color(); /* uruchamiamy RGB */
	attron(COLOR_PAIR(1));
	printw("Aktualny plan filmów dla sali:\n");
	for(auto i = 0;i < this->_schedule.size(); i++)
	{
		printw("%s\n",this->_schedule[i].data());
	}
	attroff(COLOR_PAIR(1));
}

void CinemaHall::SetUpStartFilm()
{
	_actualFilmInfo = this->_schedule[_actualTime];
}