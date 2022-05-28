#include "Cashbox.h"

Cashbox::Cashbox(int capacity)
{
	this->_capacity = capacity;
}

Cashbox::Cashbox(int capacity, std::vector<Ticket> tickets) : Cashbox(capacity)
{
	this->_tickets = tickets;
}

Cashbox::~Cashbox()
{
	pthread_mutex_destroy(&this->mutex);
}

Ticket* Cashbox::GetTicket()
{
	/* Obsługujemy pojedynczo klientów */
	pthread_mutex_lock(&this->mutex);
	if(this->_tickets.size() == 0)
	{
		printw("Nie ma już dostepnych biletów.\n");
		refresh();
	}

	printw("Przygotowanie biletu dla klienta\n");
	refresh();
	sleep(1); /* czekamy 1 sek na przygotwanie biletu */

	Ticket* t = &this->_tickets[_ticketPosition];
	this->_ticketPosition++;

	/* Zwalniamy miejsce przy kasie */
	pthread_mutex_unlock(&this->mutex);
	return t;
}

void Cashbox::GenerateTickets()
{
	const char* filmNames[4] = {"Home alone", "Crazy people", "My cat is super", "Independent city"};
	int durations[4] = {2, 3, 5, 1};
	int endTime = 1;
	for(auto i=0;i<this->_capacity / 5;i++) /* bo na każdy film po 5 biletów */
	{
		for(auto j=0;j<5;j++)
		{
			Ticket* t = NULL;
			if(i == 0)
			{
				t = new Ticket(filmNames[i], 1, durations[i] + 1);
			}
			else
			{
				t = new Ticket(filmNames[i], endTime, endTime + durations[i]);
			}
			this->_tickets.push_back(*t);
		}
		_generatedSchedule.push_back(*(new ScheduleElement(filmNames[i], i==0 ? 1 : endTime, i==0 ? durations[i] + 1 : endTime + durations[i])));
		endTime += durations[i];
	}
}

std::vector<ScheduleElement> Cashbox::GetPlannedSchedule()
{
	return this->_generatedSchedule;
}