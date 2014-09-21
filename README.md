QT_ELM327_Simulator
===================

Simulates an ELM327 OBD2 Adapter over Serial Port (COMx)..

#Info:
- http://en.wikipedia.org/wiki/ELM327
- http://elmelectronics.com/DSheets/ELM327DS.pdf
- http://elmelectronics.com/ELM327/AT_Commands.pdf

#Current Features:

- select port from GUI
- AT Command console
- Response for simple AT Commands needed for connection
- 01 Modes: speed, rpm, throttle, cooler temp
- real car data from LifeForSpeed over UDP (OutGauge)

#TODO:
- Implement more AT Commands
- Implement echo, linefeed, header on/off Switching
- Implement error code reading
- Implement more Mode 1 codes

#Bugs:
?
