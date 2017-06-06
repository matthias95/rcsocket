/**
@author Matthias Bernard
@date 2016
*/

#pragma once
namespace RCSocket {
	enum BitType{
		ZERO,
		ONE,
		FLOAT,
		SYNC
	};
	
	/** 
	* setup gpio to control the transmitter
	* @param pin raspberry pi GPIO pin connected to transmitter, pinout according to wiringPi
	*/
	void initTransmitter(const unsigned short pin);
	
	/** 
	* transmit data frame 
	* @param frame 13 data bit data frame to be transmittet
	* @param pin raspberry pi GPIO pin connected to transmitter
	* @param timing timing in microseconds used to transmitt data bits
	* @param inverted true if the input of the transmitter is inverted 
	*/
	void transmit(BitType *frame , const int pin, const int timing = 300, const int inverted = 0);
}
