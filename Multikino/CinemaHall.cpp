#include <CinemaHall.h>

CinemaHall::CinemaHall(int actualTime)
{
	this->_actualTime = actualTime;
}

CinemaHall::CinemaHall(int actualTime, std::vector<std::string> schedule) : CinemaHall(actualTime)
{
	this->_schedule = schedule;
	SetUpTimeAndSchedule();
}

void CinemaHall::StartFilm()
{
	std::cout<<"Rozpoczęty film: "<<this->_actualFilmInfo<<endl;
}

void CinemaHall::PrintCinemaHallInfo()
{
	std::cout<<"Aktualny plan filmów dla sali:"<<std::endl;
	for(auto i = 0;i < this->_schedule.size(); i++)
	{
		std::cout<<this->_schedule[i]<<std::endl;
	}
}

void CinemaHall::SetUpTimeAndSchedule()
{
	
}