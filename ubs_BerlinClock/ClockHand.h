/*
 * ClockHand.h
 *
 *  Created on: Apr 7, 2018
 *      Author: sauravsharma
 */

#pragma once
#include<memory>

#include "Lamp.h"

namespace ubs
{
	class ClockHand
	{
	public:
		using Ptr = std::unique_ptr<ClockHand>;

		void addLampRow(Lamp::LampRow&& arLampRow)
		{
			mLampRowVctr.push_back(std::move(arLampRow));
		}

		Secs setTime(Secs arTime)
		{
			for(auto& lLampRow: mLampRowVctr)
			{
				for(auto& lLamp : lLampRow)
				{
					//pass remainder time to other lamps
					arTime = lLamp.setTime(arTime);

					//in case of 0 seconds
					if(arTime ==Secs{0})
					{
						return arTime;
					}
				}
			}

			return arTime;
		}

		void display()
		{
			for(auto& lLampRow: mLampRowVctr)
			{
				for(auto& lLamp : lLampRow)
				{
					std::cout<<lLamp;
				}

				std::cout<<std::endl;
			}
		}
	private:
		std::vector<Lamp::LampRow> mLampRowVctr;
	};

}

