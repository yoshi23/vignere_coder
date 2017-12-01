#pragma once
#include <string>

class CodingManager
{
public:
	CodingManager();
	CodingManager(std::string iTextToCode, std::string iKeyword, char** iCodeTable);
	~CodingManager();

	std::string getExtendedKeyword();

	std::string codeText();

private:
	std::string mTextToCode;
	std::string mCodedText;
	std::string mKeyword;
	std::string mExtendedKeyword;
	char** mCodeTable;

};

