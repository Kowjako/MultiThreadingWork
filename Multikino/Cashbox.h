#ifndef CASHBOX_H
#define CASHBOX_H

#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h> 
#include <ncurses.h>

struct ScheduleElement
{
	std::string _filmName;
	int _startTime, _endTime;
	ScheduleElement() {}
	ScheduleElement(std::string _name, int _startTime, int _endTime)
	{
		_filmName = _name;
		this->_startTime  = _startTime;
		this->_endTime = _endTime;
	}

	std::string GetInfo()
	{
		return "Nazwa filmu: " + this->_filmName + 
			   " Termin: " + std::to_string(this->_startTime) + " - " + std::to_string(this->_endTime) + "\n";
	}
};

struct Ticket
{
	std::string filmName;
	short startTime;
	short endTime;

	Ticket(std::string filmName, short start, short end)
	{
		this->filmName = filmName;
		startTime = start;
		endTime = end;
	}

	std::string TicketInfo()
	{
		return "Nazwa filmu: " + this->filmName + 
			   " Termin: " + std::to_string(this->startTime) + " - " + std::to_string(this->endTime) + "\n";
	}
};

class Cashbox
{
	public:
		Cashbox(int capacity);
		Cashbox(int capacity, std::vector<Ticket> tickets);

		void GenerateTickets();
		Ticket* GetTicket();
		std::vector<ScheduleElement> GetPlannedSchedule();

	private:
		int _ticketPosition=0;
		pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
		int _capacity;
		std::vector<Ticket> _tickets;
		std::vector<ScheduleElement> _generatedSchedule;
};

#endif 