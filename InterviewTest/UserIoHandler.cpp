#include "stdafx.h"
#include "UserIoHandler.h"

#include<iostream>

UserIoHandler::UserIoHandler()
{
}


UserIoHandler::~UserIoHandler()
{
}

std::wstring UserIoHandler::getInputText()
{
	std::wstring retString;
	std::cout << "Please type in the text to code!\nInput: ";
	getline(std::wcin, retString);
	return retString;
}

bool keywordToUpperAndValidity(std::string & iString)
{
	bool onlyChars = true;
	for (int i = 0; i < iString.length(); ++i)
	{
		if (!isalnum(iString[i]) || isdigit(iString[i])) onlyChars = false;
		else iString[i] = toupper(iString[i]);
	}
	return onlyChars;
}

std::string UserIoHandler::getKeyWord()
{
	std::string retString;
	std::cout << "\nWhat keyword would you like to use for coding?\nInput: ";
	std::cin >> retString;
	bool onlyChars = keywordToUpperAndValidity(retString);

	while (retString.length() < 1 || retString.length() > 5 ||!onlyChars)
	{
		std::cout << "Keyword has to be non-empty and no longer than 5 characters,\nand it may only contain English characters.\nPlease provide a new one:\n";
		std::cin >> retString;
		onlyChars = keywordToUpperAndValidity(retString);
	}
	return retString;
}


void UserIoHandler::writeOutputText(const std::string & iText, const std::string & optText)
{
	std::cout << "\n" << optText << iText << "\n";
}
