#pragma once
#include <string>
class TextProcessor
{
public:
	TextProcessor();
	TextProcessor(std::string iString);
	~TextProcessor();

	std::string getCleanText();

private:
	std::string removeSpecChar(std::string iText);
	std::string removeSpacesAndToUpper(const std::string & iText);


	std::string mTextToProcess;
	std::string mCleanText;
	const char*	mUnicodeShifter;
};

