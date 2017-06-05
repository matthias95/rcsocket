/**
@author Matthias Bernard
@date 2016
*/

#include "RCSocketTransmitter.hpp"
#include "RCSocketTransmitterHelper.hpp"

namespace RCSocket {
	RCSocketTransmitter::RCSocketTransmitter(const int timing, const int pin, const int systemCode) : timing(timing), pin(pin), inverted(0), dataFrame{ZERO, ZERO, ZERO, ZERO, ZERO, FLOAT, FLOAT, FLOAT, FLOAT, FLOAT, ZERO, ZERO, SYNC} {
		initTransmitter(pin);
		setSystemCode(systemCode);
	}

	/** 
	* set 5 bit width system code 
	* @param systemCode for examble 0b10101
	*/
	void RCSocketTransmitter::setSystemCode(const int systemCode){
		for(int i = 0; i < 5; i++){
			dataFrame[i] = (systemCode&(1<<i)) ? ZERO : FLOAT;
		}
	}

	/** 
	* select socket to operate on
	* @param socketID
	*/
	void RCSocketTransmitter::selectSocket(const int socketID){
		if(socketID >= 5 || socketID < 0 ) 
			return;
		dataFrame[5 + socketID] = ZERO;
	}
	
	/** 
	* switch selected socket on
	* @param socketID socket to switch on
	*/
	void RCSocketTransmitter::switchOn(const int socketID){
		selectSocket(socketID);
		dataFrame[10] = ZERO;
		dataFrame[11] = FLOAT;
		transmit(dataFrame, pin, timing); 
	}
	
	/** 
	* switch selected socket off
	* @param socketID socket to switch off
	*/
	void RCSocketTransmitter::switchOff(const int socketID){
		selectSocket(socketID);
		dataFrame[10] = FLOAT;
		dataFrame[11] = ZERO;
		transmit(dataFrame, pin, timing); 
	}
}
