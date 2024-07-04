.PHONY: compile
compile:
	arduino-cli compile -b arduino:avr:nano --board-options cpu=atmega328old .

.PHONY: upload
upload:
	arduino-cli compile -b arduino:avr:nano --board-options cpu=atmega328old -u -p /dev/ttyUSB0 .
