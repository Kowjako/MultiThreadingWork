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
	std::cout<<"Rozpoczęty film: "<<this->_actualFilmInfo<<std::endl;
	for(auto i =0;i<this->_clients.size();i++)
	{
		this->_clients[i].WatchMovie(this->_actualFilmInfo, rand() % 10 + 5); /* film trwa od 5 do 15 sekund */
	}
}

void CinemaHall::AddClient(Client client)
{
	sem_wait(&this->_semaphore);
	_clients.push_back(client); /* uzupełniamy naszych klientów */
}

void CinemaHall::ClearHall()
{
	std::cout<<"Koniec prezentacji filmu."<<std::endl;
	for(auto i = 0;i< this->_clients.size(); i++)
	{
		std::cout<<"Klient: ";
		this->_clients[i].DisplayInfo();
		std::cout<<" opuscił salę."<<std::endl;
		sem_post(&this->_semaphore); /* zwalniamy miejsca na naszej sali */
	}
	this->_clients.clear();
}

void CinemaHall::PrintCinemaHallInfo()
{
	std::cout<<"Aktualny plan filmów dla sali:"<<std::endl;
	for(auto i = 0;i < this->_schedule.size(); i++)
	{
		std::cout<<this->_schedule[i]<<std::endl;
	}
}

void CinemaHall::SetUpStartFilm()
{
	_actualFilmInfo = this->_schedule[_actualTime];
}