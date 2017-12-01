#pragma once
#include <string>
class TextProcessor
{
public:
	TextProcessor();
	TextProcessor(std::wstring iString);
	~TextProcessor();

	std::string getCleanText();

private:
	std::string removeSpecChar();
	std::string removeSpacesAndToUpper(const std::string & iText);


	std::wstring mTextToProcess;
	std::string mCleanText;
	const char*	mUnicodeShifter;
	const char* mWindowsEncoding852;
};

