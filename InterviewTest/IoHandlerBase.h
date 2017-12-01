#pragma once
#include <string>

//Common base class for handling input 
//and output from user / file.
class IoHandlerBase
{
public:
	IoHandlerBase();
	~IoHandlerBase();

	virtual std::wstring getInputText() = 0;
	virtual void writeOutputText(const std::string & iText, const std::string & optText = "") = 0;

};

