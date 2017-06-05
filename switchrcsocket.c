#include <wiringPi.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "RCSocketTransmitter.hpp"

/**
timing used in the tranmitter protocoll, may depend on the brand of the sockets, for mine 380 microseconds works well
*/
constexpr int timing = 380;

/**
gpio pin the transmitter is attache to  
*/
constexpr int pin = 0; 

int main(int argc, char **args){
	if(argc < 4) {
		std::cout << "args: <systemcode> <socket number> <state>" << std::endl;
		std::cout << "Example: " << args[0] << "00000 0 1" << std::endl;
		exit(-1);
	}
	const int code = std::stoi (args[1], nullptr, 2);
	const int socketId = std::stoi (args[2], nullptr, 10);
	const int state = std::stoi (args[3], nullptr, 10);
	RCSocket::RCSocketTransmitter socket(timing, pin, code);
	
	/**
	repeat transmission 16 times to make it work more reliable
	*/
	for(int i = 0; i < 15; i++){
		if(state)
			socket.switchOn(socketId);
		else
			socket.switchOff(socketId);
		if(i % 5 == 0){
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	return 0;
}
