#include <iostream>
#include <ubs_BerlinClock/ClockFactory.h>


int main()
{
	ubs::BerlinClock::Ptr lBerlinClock = ubs::ClockFactory::createBerlinClock();

	lBerlinClock->showTime(ubs::Secs{16*3600 +  58 * 60 + 1});
	//TODO add test cases google test
}




