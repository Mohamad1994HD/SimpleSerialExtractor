 #include "SerialExtractor.h"


SerialExtractor::SerialExtractor(char end,char const* deli):endIndicator(end), delimeter(deli)
{
  resetCommand();
  
  this->SERIAL_RESULT = WAITING;
}

void SerialExtractor::TryReadSerial()
{
  char serialInByte;
  bool isData = false;
  if (Serial.available())
  {
	isData = true;
    do
    {
      serialInByte = Serial.read();
      //this->command += serialInByte;
      
      this->cmd[siz] = serialInByte;
      siz++;
      
     // Serial.println(this->cmd);
    } while ((serialInByte != endIndicator) && Serial.available());
  }
 this->cmd[this->siz] = '\0';
 
 if(isData)
 {
	  if (serialInByte == endIndicator)
	  {
		this->SERIAL_RESULT = SUCCESS;
	  }
	  else
	  {
		this->SERIAL_RESULT = ERROR_MSG_NOT_TERMINATED;
		//Serial.println("ERROR MSG NOT TERMINATED WITH : "+this->endIndicator);
	  }
 }
 else
 {
	this->SERIAL_RESULT = WAITING;
 }
 Serial.flush();
}
/*
void SerialExtractor::Run()
{
  TryReadSerial();
  if (this->SERIAL_RESULT == SUCCESS)
  {
   // extractInfo();
    resetCommand();
  }
  else if (this->SERIAL_RESULT == ERROR_MSG_NOT_TERMINATED)
  {
    // Raise Error Indicator  
    Serial.println("ERROR IN READING DATA");
  }
}

*/
void SerialExtractor::resetCommand()
{
  //this->command = "";
  for (int i=0;i<siz;i++)
  {
	  this->cmd[i]='\0';
  }
   this->siz = 0;
}


void SerialExtractor::extractInfo(int a[], int &size)
{
	//const  char *  d = new char(delimeter);
//	Serial.println(atoi(token));
	char* token = strtok(cmd, delimeter);
	
	if(token)
	{
		while(token)
		{
			a[size] = atoi(token);
			size++;
			token = strtok(NULL, delimeter);
			if(!token)
			{
				SERIAL_RESULT = ERROR_IN_DELIMETER;
				break;
			}
			//Serial.print(a[size]); Serial.print(" "); Serial.println(size);
		}
	}
	else
	{
		SERIAL_RESULT = ERROR_IN_DELIMETER;
	}
	
	if (SERIAL_RESULT == ERROR_IN_DELIMETER)
	{
		Serial.print("ERROR VALID DELIMETER NOT USED: ");
		Serial.println(this->delimeter);
	}
	
	resetCommand();
}

void SerialExtractor::DisplayError()
{
	if(SERIAL_RESULT == ERROR_MSG_NOT_TERMINATED)
	{
	  Serial.print("ERROR MSG NOT TERMINATED WITH ");
      Serial.println(GetEndIndicator());
	}
}

void SerialExtractor::SetEndIndicator(char c)
{
	this->endIndicator = c;
}

void SerialExtractor::SetDelimeter(char const* c)
{
	this->delimeter = c;
}

char SerialExtractor::GetEndIndicator()
{
	return this->endIndicator;
}
char const* SerialExtractor::GetDelimeter()
{
	return this->delimeter;
}