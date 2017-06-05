default: all

all: switchrcsocket libRCSocket.a

switchrcsocket: libRCSocket.a switchrcsocket.c
	g++ -std=c++14 -o switchrcsocket switchrcsocket.c libRCSocket.a -lwiringPi


RCSocketTransmitter.o: RCSocketTransmitter.hpp RCSocketTransmitter.cpp 
	g++ -std=c++14 -o RCSocketTransmitter.o -c RCSocketTransmitter.cpp  	
	
libRCSocket.a: RCSocketTransmitter.o RCSocketTransmitterHelper.o
	ar rcs libRCSocket.a RCSocketTransmitter.o RCSocketTransmitterHelper.o
	
	
RCSocketTransmitterHelper.o: RCSocketTransmitterHelper.hpp RCSocketTransmitterHelper.cpp
	g++ -std=c++14 -o RCSocketTransmitterHelper.o -c RCSocketTransmitterHelper.cpp
	

install: all
	cp switchrcsocket /usr/bin/switchrcsocket
	chmod +s /usr/bin/switchrcsocket

clean:
	rm -f *.o *.exe *.a *.so
	
	
