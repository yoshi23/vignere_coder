// InterviewTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "FileIoHandler.h"
#include "UserIoHandler.h"
#include "TextProcessor.h"
#include "CodingManager.h"

#include <string>


int main()
{
	FileIoHandler wFileIoHandler;
	UserIoHandler wUserIioHandler;

	//Read in the Vignere coding table
	char** wVigenereTable = wFileIoHandler.vigenereTableReader();

	//Obtain the input text from user
	std::wstring wSt = wUserIioHandler.getInputText();
	
	//Process the text (remove accents and spaces, change to capital)
	TextProcessor wTextProcessor(wSt);
	
	//Print processed text
	std::string wCleanText = wTextProcessor.getCleanText();
	wUserIioHandler.writeOutputText(wCleanText, "Converted to English letters and capitalized:\n");

	std::string wKeyword = wUserIioHandler.getKeyWord();

	//Initiate a coding manager class
	CodingManager wCodingManager(wCleanText, wKeyword, wVigenereTable);

	//Extend keyword to the length of the input text
	std::string wExtendedKeyword = wCodingManager.getExtendedKeyword();
	//Perform the coding based on the Vignere table
	std::string wCodedText = wCodingManager.codeText();

	//Print remaining results
	wUserIioHandler.writeOutputText(wExtendedKeyword, "Keyword elongated to fit text:\n");
	wUserIioHandler.writeOutputText(wCodedText, "Coded text:\n");
	wFileIoHandler.writeOutputText(wCodedText);

    return 0;
}

