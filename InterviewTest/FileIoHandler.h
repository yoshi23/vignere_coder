#pragma once
#include "IoHandlerBAse.h"
#include <string>
#include <fstream>


class FileIoHandler
	: IoHandlerBase
{
public:
	FileIoHandler();
	~FileIoHandler();

	std::wstring getInputText();
	void writeOutputText(const std::string & iText, const std::string & optText = "");
	char** vigenereTableReader();


private:
	std::wifstream mIfstream;
	std::ofstream mOfstream;
	std::string mInFilePath;
	std::string mOutFilePath;
	std::string mCodeTablePath;
};

