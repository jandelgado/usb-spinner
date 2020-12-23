# use this makefile to build with platformio 
#
.PHONY: all clean upload monitor lint ci

all:
	pio run

ci:
	platformio ci -c platformio.ini src/spinner.ino --board=sparkfun_promicro16

lint:
	cpplint --extensions=cpp,h,ino src/spinner.ino

clean:
	pio run --target clean

upload:
	pio run --target upload 

monitor:
	pio device monitor

