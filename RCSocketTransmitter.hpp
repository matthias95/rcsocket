/**
@author Matthias Bernard
@date 2016
*/

#pragma once 

#include "RCSocketTransmitterHelper.hpp"

namespace RCSocket {
	class RCSocketTransmitter{	
		public:
		RCSocketTransmitter(const int timing, const int pin, const int systemCode);
		
		/** 
		* set 5 bit width system code 
		* @param systemCode for examble 0b10101
		*/
		void setSystemCode(const int systemCode);
		
		/** 
		* switch selected socket on
		* @param socketID socket to switch on
		*/
		void switchOn(const int socketID);
		
		/** 
		* switch selected socket off
		* @param socketID socket to switch off
		*/
		void switchOff(const int socketID);
		
		private:
		const int timing;
		const int pin;
		const int inverted;
		BitType dataFrame[13];
		
		/** 
		* select socket to operate on
		* @param socketID
		*/
		void selectSocket(const int socketID);
	};
}
