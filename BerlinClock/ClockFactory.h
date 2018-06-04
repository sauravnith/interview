/*
 * ClockFactory.h
 *
 *  Created on: Apr 7, 2018
 *      Author: sauravsharma
 */

#pragma once
#include "../BerlinClock/BerlinClock.h"

namespace ubs
{
	class ClockFactory
	{
	public:
		static BerlinClock::Ptr createBerlinClock();

	private:
		static ClockHand::Ptr createHourHand();
		static ClockHand::Ptr createMinuteHand();
	};

}

