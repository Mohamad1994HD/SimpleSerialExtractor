#ifndef SERIAL_H
#define SERIAL_H


/*
20 February 2016
Simple Serial extractor for extracting numbers sent to serial port in a sentence
ex. 2:3# where : is the delimeter and # is the end indicator
Use:
  int a[10]={0};
  int siz = 0;
  
  ser.TryReadSerial();
  
    if (ser.SERIAL_RESULT == SUCCESS){
      ser.extractInfo(a, siz);
      for (int i=0;i<siz; i++)
      {
        Serial.println(a[i]);
      }
     
    }
	
CAUTION: Displaying Error via DisplayError has a problem unknown till now
*/
#include "Arduino.h"
enum MsgState {SUCCESS, ERROR_MSG_NOT_TERMINATED, WAITING, ERROR_IN_DELIMETER};

class SerialExtractor{
  private:
	//char delimeter;
	char endIndicator;
	char const*  delimeter;
    char cmd[100];
    int siz;

  public :
	SerialExtractor(char end='#', char const* deli=":");
    MsgState SERIAL_RESULT;
 
    void TryReadSerial();
    void resetCommand();  
    void extractInfo(int *,int &);
	void DisplayError();
	
	void SetEndIndicator(char );
	char GetEndIndicator();
	void SetDelimeter(char const* );
	char const* GetDelimeter();
	
	//SerialExtractor(char end='#', char deli=':');
	// void extractInfo();
	// void extractInfo(int*, int *);
	//char GetDelimeter();
   	//void SetDelimeter(char );
	
	//void Run();
};
  
#endif
