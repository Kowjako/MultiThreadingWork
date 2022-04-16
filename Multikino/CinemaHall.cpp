#include "CinemaHall.h"

CinemaHall::CinemaHall(int actualTime)
{
	this->_actualTime = actualTime;
}

CinemaHall::CinemaHall(int actualTime, std::vector<std::string> schedule) : CinemaHall(actualTime)
{
	this->_schedule = schedule;
}

void CinemaHall::StartFilm()
{
	SetUpStartFilm();
	std::cout<<"Rozpoczęty film: "<<this->_actualFilmInfo<<std::endl;
}

void CinemaHall::AddClient(Client client)
{
	if(this->_clients.size() != 10)
	{
		_clients.push_back(client);
	}
}

void CinemaHall::ClearHall()
{
	for(auto i = 0;i< this->_clients.size(); i++)
	{
		std::cout<<"Klient: ";
		this->_clients[i].DisplayInfo();
		std::cout<<" opuscił salę."<<std::endl;
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