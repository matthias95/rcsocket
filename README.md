# rcsocket

Library and sample application for controlling 433MHz remote controled sockets using raspberry pi. The transmitter is controled via bit banging depending on WiringPi for GPIO acces. The project might be easily ported to arduino because of the similarity between WiringPi and arduino interface for GPIO acces.  \

__***Every application build with this lib requeires super user permissions in order to acces GPIO ports***__

# Dependencies
- [WiringPi](http://wiringpi.com/download-and-install/)
- make
- gcc

# Build
Build everything: \
`make`

Build sample application: \
`make switchrcsocket`

Build lib only: \
`make libRCSocket.a`

Install sample application (must be executed as root): \
`make install` copies the executable to `/usr/bin` and sets the [suid bit](https://en.wikipedia.org/wiki/Setuid). This might be a security risk due to possible flaws in my [sample applction](switchrcsocket.c)

# Usage:

__***Every application build with this lib requeires super user permissions in order to acces GPIO ports***__

For usage of the library see sample application [switchrcsocket.c](switchrcsocket.c). \
\
Use of sample application:
Switch socket with system code 0 and socket id 0 on: \
`./switchrcsocket 00000 0 1` \
Switch socket with system code 0 and socket id 0 off: \
`./switchrcsocket 00000 0 0`




