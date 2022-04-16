#ifndef CASHBOX_H
#define CASHBOX_H

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
		return "Nazwa filmu: " + this->filmName + " Termin: " + this->startTime + " - " + this->endTime;
	}
};

class Cashbox
{
	public:
		Cashbox(int capacity);
		Cashbox(int capacity, std::vector<Ticket> tickets);

		void AddTicket(Ticket ticket);
		void GetTicket();

	private:
		int _capacity;
		std::vector<Ticket> _tickets;
};

#endif 