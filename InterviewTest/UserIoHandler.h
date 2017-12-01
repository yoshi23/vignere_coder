#pragma once
#include "IoHandlerBase.h"
#include <string>
#include <iostream>

class UserIoHandler
	: IoHandlerBase
{

	//TODO: common baseclass with filehandler...stream is the diff
public:
	UserIoHandler();
	~UserIoHandler();

    std::wstring getInputText();
	std::string getKeyWord();
	void writeOutputText(const std::string & iText, const std::string & optText = "");

};

