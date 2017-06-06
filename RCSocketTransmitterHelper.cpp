/**
@author Matthias Bernard
@date 2016
*/

#include "RCSocketTransmitterHelper.hpp"
#include <wiringPi.h>

namespace RCSocket {
	static inline constexpr decltype(HIGH) PINHIGH(const int inverted) {
		return inverted?LOW:HIGH;
	}

	static inline constexpr decltype(LOW) PINLOW(const int inverted) {
		return inverted?HIGH:LOW;
	}

	/** 
	* setup gpio to control the transmitter
	* @param pin raspberry pi GPIO pin connected to transmitter, pinout according to wiringPi
	*/
	void initTransmitter(const unsigned short pin){
		wiringPiSetup();
		pinMode(pin,OUTPUT);
	}

	static inline void bit(const int on, const int off, const int pin, const int inverted){
		digitalWrite(pin, PINHIGH(inverted));
		delayMicroseconds(on);
		digitalWrite(pin, PINLOW(inverted));
		delayMicroseconds(off);
	}
	static inline void zeroBit(const int pin, const int timing, const int inverted){
		bit(timing * 1, timing * 3, pin, inverted);
		bit(timing * 1, timing * 3, pin, inverted);
	}
	static inline void oneBit(const int pin, const int timing, const int inverted){
		bit(timing * 3, timing * 1, pin, inverted);
		bit(timing * 3, timing * 1, pin, inverted);
	}
	static inline void floatBit(const int pin, const int timing, const int inverted){
		bit(timing * 1, timing * 3, pin, inverted);
		bit(timing * 3, timing * 1, pin, inverted);
	}
	static inline void syncBit(const int pin, const int timing, const int inverted){
		bit(timing * 1, timing * 31, pin, inverted);
	}


	/** 
	* transmit data frame 
	* @param frame 13 data bit data frame to be transmittet
	* @param pin raspberry pi GPIO pin connected to transmitter, pinout according to wiringPi
	* @param timing timing in microseconds used to transmitt data bits
	* @param inverted true if the input of the transmitter is inverted 
	*/
	void transmit(BitType *frame , const int pin, const int timing, const int inverted){
		for(BitType* b = frame; b < frame+13; ++b){
			switch(*b) {
				case ZERO:
					zeroBit(pin, timing, inverted);
					break;
				case ONE:
					oneBit(pin, timing, inverted);
					break;
				case FLOAT:
					floatBit(pin, timing, inverted);
					break;
				case SYNC:
					syncBit(pin, timing, inverted);
					break;
			}
		}
	}
}
