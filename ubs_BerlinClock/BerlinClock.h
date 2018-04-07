/*
 * BerlinClock.h
 *
 *  Created on: Apr 7, 2018
 *      Author: sauravsharma
 */

#pragma once
#include "ClockHand.h"
#include <assert.h>

namespace ubs
{
	class BerlinClock
	{
	public:
		using Ptr = std::unique_ptr<BerlinClock>;

		BerlinClock(ClockHand::Ptr arHourHand,ClockHand::Ptr arMinHand)
		:mHourHandPtr(std::move(arHourHand))
		,mMinHandPtr(std::move(arMinHand))
		,mSecondsLamp(Lamp::LampColor::YELLOW, Secs{0})
		{}

		void showTime(Secs arTime)
		{
			arTime = mHourHandPtr->setTime(arTime);

			arTime = mMinHandPtr->setTime(arTime);

			assert(arTime >= Secs{0} && arTime <= Secs{60});

			//even seconds : lamp is turned on and odd means lamp turned off
			arTime.count() % 2 ==0 ? mSecondsLamp.turnOn() : mSecondsLamp.turnOff();

			display();
		}

	private:
		ClockHand::Ptr mHourHandPtr;
		ClockHand::Ptr mMinHandPtr;
		Lamp mSecondsLamp;

		void display()
		{
			std::cout<<mSecondsLamp<<std::endl;

			mHourHandPtr->display();
			mMinHandPtr->display();
		}
	};

}

