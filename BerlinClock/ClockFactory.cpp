/*
 * ClockFactory.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: sauravsharma
 */
#include "../BerlinClock/ClockFactory.h"

using namespace ubs;

BerlinClock::Ptr ClockFactory::createBerlinClock()
{
	return std::make_unique<BerlinClock>(createHourHand(), createMinuteHand());
}

ClockHand::Ptr ClockFactory::createHourHand()
{
	ClockHand::Ptr lHourHand(std::make_unique<ClockHand>());

	//First Row : 4 red lamps and each represent 5 hours
	Lamp::LampRow lHourFirstRow;
	lHourFirstRow.reserve(4);

	for(size_t lIdx =0 ; lIdx<4 ; ++lIdx)
	{
	  lHourFirstRow.emplace_back(Lamp{Lamp::LampColor::RED, Secs{5 * 3600} });
	}
	lHourHand->addLampRow(std::move(lHourFirstRow));

	//Second Row: 4 red lamps and each represent 5 hours
	Lamp::LampRow lHourSecondRow;
	lHourSecondRow.reserve(4);

	for(size_t lIdx =0 ; lIdx<4 ; ++lIdx)
	{
		lHourSecondRow.emplace_back(Lamp{Lamp::LampColor::RED, Secs{3600} });
	}
	lHourHand->addLampRow(std::move(lHourSecondRow));

	return lHourHand;
}

ClockHand::Ptr ClockFactory::createMinuteHand()
{
	ClockHand::Ptr lMinuteHand(std::make_unique<ClockHand>());

	//First row: 11 yellow lamps and each represent 5 minutes
	Lamp::LampRow lMinFirstRow;
	lMinFirstRow.reserve(11);

	for(size_t lIdx =0 ; lIdx < 11 ; ++lIdx)
	{
		//3rd,6th and 9th represent  first quarter, half and last quarter of an hour
		if( (lIdx +1) % 3 == 0 )
		{
			lMinFirstRow.emplace_back(Lamp{Lamp::LampColor::RED, Secs{5 * 60} });
		}
		else
		{
			lMinFirstRow.emplace_back(Lamp{Lamp::LampColor::YELLOW, Secs{5 * 60} });
		}

	}
	lMinuteHand->addLampRow(std::move(lMinFirstRow));

	//Second row: 4 yellow lamps and each represent 5 minutes
	Lamp::LampRow lMinSecondRow;
	lMinSecondRow.reserve(4);

	for(size_t lIdx =0 ; lIdx < 4 ; ++lIdx)
	{
		lMinSecondRow.emplace_back(Lamp{Lamp::LampColor::YELLOW, Secs{60} });
	}
	lMinuteHand->addLampRow(std::move(lMinSecondRow));

	return lMinuteHand;
}


