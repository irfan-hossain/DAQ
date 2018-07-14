# DAQ: Data Acquisition System
This project uses a Raspberry Pi and Arduino Uno to create a high speed data acquisition system. The project is based on the OpenLabTools guide provided by the Univeristy of Cambridge, provided [here](http://openlabtools.eng.cam.ac.uk/Resources/Datalog/RPi_Arduino/). There are a few modifications from the original guide and implementation differences.   

# Hardware
   * Raspberry Pi 2
   * Arduino Uno
   * OLED Display
   * Light Sensor    
   * Adafruit T-Cobbler Plus
   * Serial Cable


# Code Guide

### ADMXUX

| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |   
|---|---|---|---|---|---|---|---|
|REFS1|REFS0|ADLAR|--|MUX3|MUX2|MUX1|MUX0|
|0|0|1|--|0|0|0|0|

**[7:6]** Sets the reference voltage. Making the bits zero sets the reference voltage to the internal reference voltage.

**[ 5 ]** Left shifts the 10 bit conversion result so the ADCH register contains an 8-bit result from the ADC. Example:
* ADLAR = 0, ADCH = ---- --11, ADCL = 1011 0101
* ADLAR = 1, ADCH = 1110 1101, ADCL = 01-- ---

**[3:0]** Selects the analog pin being used for ADC, in this case it's pin A0.

### ADSCRA


### ADCSRB
