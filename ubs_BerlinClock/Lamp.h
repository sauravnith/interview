/*
 * Lamp.h
 *
 *  Created on: Apr 7, 2018
 *      Author: sauravsharma
 */

#pragma once
#include<iostream>
#include <vector>
#include <string_view>
#include <string>
#include "Types.h"

namespace ubs
{
	class Lamp
	{
	public:
		using LampRow = std::vector<Lamp>;

		enum class LampColor: std::int8_t
		{
			RED =0,
			YELLOW
		};

		enum class LampState : std::int8_t
		{
			ON,
			OFF
		};

		Lamp(LampColor arColor, Secs arTimeInSecs)
			:mLampColor{arColor}
			 ,mLampState{LampState::OFF}
			 ,mTimeInSecs{arTimeInSecs}
		{

		}

		void turnOn()
		{
			mLampState=LampState::ON;
		}

		void turnOff()
		{
			mLampState=LampState::OFF;
		}

		Secs setTime(Secs arTimeInterval)
		{
			if(arTimeInterval == Secs{0} || arTimeInterval < mTimeInSecs )
			{
				return arTimeInterval;
			}

			turnOn();

			return arTimeInterval - mTimeInSecs ;
		}

		friend std::ostream& operator<<(std::ostream& arStream, const Lamp& arLamp);

		std::string_view getLampColor()const
		{
			switch(mLampColor)
			{
			case LampColor::RED:
				return "R";
			case LampColor::YELLOW:
				return "Y";
			default:
				throw std::runtime_error("Lamp: Unknown Lamp color");
			}
		}

	private:
		LampColor mLampColor;
		LampState mLampState;
		Secs mTimeInSecs;
	};

	inline std::ostream& operator<<(std::ostream& arStream, const Lamp& arLamp)
	{
		switch(arLamp.mLampState)
		{
		case Lamp::LampState::ON:
			arStream<<arLamp.getLampColor();
			break;
		case Lamp::LampState::OFF:
			arStream<<"O";
			break;
		default:
			break;
		}

		return arStream;
	}
}

