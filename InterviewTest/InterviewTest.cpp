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

	char** wVigenereTable = wFileIoHandler.vigenereTableReader();

	std::wstring wSt = wUserIioHandler.getInputText();
	
	TextProcessor wTextProcessor(wSt);
	
	std::string wCleanText = wTextProcessor.getCleanText();
	wUserIioHandler.writeOutputText(wCleanText, "Converted to English letters and capitalized:\n");

	std::string wKeyword = wUserIioHandler.getKeyWord();

	CodingManager wCodingManager(wCleanText, wKeyword, wVigenereTable);

	std::string wExtendedKeyword = wCodingManager.getExtendedKeyword();
	std::string wCodedText = wCodingManager.codeText();

	wUserIioHandler.writeOutputText(wExtendedKeyword, "Keyword elongated to fit text:\n");
	wUserIioHandler.writeOutputText(wCodedText, "Coded text:\n");
	wFileIoHandler.writeOutputText(wCodedText);

    return 0;
}

