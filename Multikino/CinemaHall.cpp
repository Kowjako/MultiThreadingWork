#include "CinemaHall.h"

CinemaHall::CinemaHall(int actualTime)
{
	this->_actualTime = actualTime;
	sem_init(&this->_semaphore, 0, 5); /*inicjalizacja semaforu, 5 klientów jednocześnie */
}

CinemaHall::CinemaHall(int actualTime, std::vector<ScheduleElement> schedule) : CinemaHall(actualTime)
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
	start_color(); /* uruchamiamy RGB */
	attron(COLOR_PAIR(2));
	printw("Rozpoczety film: %s\n",this->_actualFilmInfo._filmName.data());
	attroff(COLOR_PAIR(2));
	for(auto i =0;i<this->_clients.size();i++)
	{
		this->_clients[i]->WatchMovie(this->_actualFilmInfo._filmName); /* film trwa od 5 do 15 sekund */
		refresh();
	}

	sleep(6);

	_actualTime += (_actualFilmInfo._endTime - _actualFilmInfo._startTime);

	std::for_each(this->_clients.begin(), this->_clients.end(), [](Client* t)
	{
		t->SetClientState(AfterMovie);
	});

	ClearHall();
}

void CinemaHall::SetSchedule(std::vector<ScheduleElement> schedule)
{
	this->_schedule = schedule;
}

void CinemaHall::AddClient(Client* client)
{
	/* Wpuszczamy klientów co mają bilet na określoną godzinę */
	if(client->GetTicket()->startTime == _actualTime)
	{
		client->SetClientState(WaitingForMovie);
		sem_wait(&this->_semaphore);
		_clients.push_back(client); /* uzupełniamy naszych klientów */
		
		if(_clients.size() == 5)
		{
			StartFilm();	
		}
	}
}

void CinemaHall::ClearHall()
{
	printw("Koniec prezentacji filmu.\n");
	for(auto i = 0;i< this->_clients.size(); i++)
	{
		printw("Klient: %s opuscil sale\n", this->_clients[i]->GetNameAndSurname().data());
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
		printw("%s",this->_schedule[i].GetInfo().data());
	}
	attroff(COLOR_PAIR(1));
}

void CinemaHall::SetUpStartFilm()
{
	for(auto i = 0; i<this->_schedule.size();i++)
	{
		if(this->_schedule[i]._startTime == _actualTime)
		{
			_actualFilmInfo = this->_schedule[i];
			break;
		}
	}
}