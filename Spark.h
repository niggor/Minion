#ifndef SPARK_H
#define SPARK_H

#include "SerialPort.h"
#include "stdint.h"

class Spark : public Serial
{
private:
	#define WIFIon 'W';
	#define WIFIoff 'w';
	#define CLOUDon 'C';
	#define CLOUDoff 'c';
	#define WIFIparam 'p';
	#define StopByte 0x00;
	#define SlefieDown 's'
	#define SlefieUp 'S'
	#define ACB 0xFF

public:

	Spark(int NumberOfAccums);
	Spark(const char* port, int baudrate);
	void WiFiOn();
	void WiFiOff();
	void CloudOn();
	void CloudOff();	
	void WiFiParams(const char* SSID, const char* password);
	void SelfieGetReady();
	void SelfieRelease();
	bool getResponse();
	void getBatteries();
	int percent(int index);

	int acb;
	float cell[2][5];
	float voltage[2];
	bool plugged[2];
	bool StickIsDown;

};

#endif
