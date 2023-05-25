#include <SoftwareSerial.h> // include header file for initializing serial pins
SoftwareSerial bluetooth(10, 11); // RX and TX pins for serial communication
int in1=3; // Pin number for motor control
int in2=4; // Pin number for motor control
int in3=5; // Pin number for motor control
int in4=6; // Pin number for motor control
void setup() {
	Serial.begin(9600); //initialize baud rate of 9600 for hardware
	bluetooth.begin(9600); //initialize baud rate of 9600 for Bluetooth
	pinMode(in1, OUTPUT); //Set in1 pin as OUTPUT
	pinMode(in2, OUTPUT); //Set in2 pin as OUTPUT
	pinMode(in3, OUTPUT); //Set in3 pin as OUTPUT
	pinMode(in4, OUTPUT); //Set in4 pin as OUTPUT
	}
void loop() {
	if(bluetooth.available()>0) //Check if any BT data available
	{
		char data = bluetooth.read(); //read and store BT data in char
		Serial.println(data); // print on Serial monitor
		if(data=='f') // check if data is ‘f’
		{
		Serial.println("forward");
		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
		digitalWrite(in3,LOW);
		digitalWrite(in4,HIGH); //both motor moves forward
		delay(100); 
		}
		else if(data == 'b') // check if data if ‘b’
		{
		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, HIGH);
		digitalWrite(in4,LOW); //both motor moves backward
		delay(100);
		}
		else if (data == 'l')
		{
		digitalWrite (in1,HIGH);
		digitalWrite (in2,LOW); //motor1 moves backward
		digitalWrite (in3,HIGH);
		digitalWrite (in4,LOW); // motor2 moves forward
		delay(100);
		}
		else if ( data == 'r')
		{
		digitalWrite (in1, LOW);
		digitalWrite (in2, HIGH); //motor1 moves forward
		digitalWrite (in3, LOW);
		digitalWrite (in4, HIGH); //motor2 moves backward
		delay (100);
		}
		else if (data == 's')
		{
		digitalWrite (in1, LOW);
		digitalWrite (in2, LOW);
		digitalWrite (in3, LOW);
		digitalWrite (in4, LOW); //both motors stops
		delay (100);
		}
	}
	Else
	{
	digitalWrite (in1, LOW);
	digitalWrite (in2, LOW);
	digitalWrite (in3, LOW);
	digitalWrite (in4, LOW); // both the motors stops moving
	}
}
