#include "stdafx.h"
#include "TextProcessor.h"

TextProcessor::TextProcessor()
{
	//   "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ"
	mUnicodeShifter = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
}

TextProcessor::TextProcessor(std::string iString) :
	mTextToProcess(iString),
	mCleanText("")
{
				 //   "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ"
	mUnicodeShifter = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
}

TextProcessor::~TextProcessor()
{
}



std::string TextProcessor::removeSpecChar(std::string iText)
{
	std::string retString;
	//This code snipet was inspired by the solution found here: https://stackoverflow.com/questions/14094621/change-all-accented-letters-to-normal-letters-in-c
	for (int i = 0; i < mTextToProcess.length(); ++i)
	{
			unsigned char ch = mTextToProcess[i];
			if (ch >= 192) {
				retString.push_back(mUnicodeShifter[ch - 192]);
			}
			else
			{
				retString.push_back(mTextToProcess[i]);
			}
	}
	return retString;
}

std::string TextProcessor::removeSpacesAndToUpper(const std::string & iText)
{
	std::string retString;
	for (int i = 0; i < iText.length(); ++i)
	{
		if (isalnum(iText[i]))
		{
			retString.push_back(toupper(iText[i]));
		}
	}
	return retString;
}

std::string TextProcessor::getCleanText()
{
	std::string wTempString;

	wTempString = removeSpecChar(mTextToProcess);
	mCleanText = removeSpacesAndToUpper(wTempString);

	return mCleanText;
}