#pragma once
#include <string>

//Common base class for handling inpute and output from user / file.
class IoHandlerBase
{
public:
	IoHandlerBase();
	~IoHandlerBase();

	virtual std::wstring getInputText() = 0;
	virtual void writeOutputText(const std::string & iText) = 0;

};

