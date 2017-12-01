#include "stdafx.h"
#include "TextProcessor.h"
#include "config.h"

TextProcessor::TextProcessor(const std::wstring & iString) :
	mTextToProcess(iString),
	mCleanText("")
{
	//Windows 10 console default character encoding (OEM - LATIN II) can be found here: https://en.wikipedia.org/wiki/Code_page_852
	//We use this array to look up the special characters by their code and search the corresponding english non-accented character.
	//This works for the default Windows 10 console setting, with code page 852.
	//For more platform independent unicode shifting, use this array and check for an 
	//accented letter threshold of 192: https://stackoverflow.com/questions/14094621/change-all-accented-letters-to-normal-letters-in-c
							
							//"ÇüéâäůćçłëŐőîŹÄĆÉĹĺôöĽľŚśÖÜŤťŁ×čáíóúĄąŽžĘę¬źČş«»░▒▓│┤ÁÂĚŞ╣║╗╝Żż┐└┴┬├─┼Ăă╚╔╩╦╠═╬¤đĐĎËďŇÍÎě┘┌█▄ŢŮ▀ÓßÔŃńňŠšŔÚŕŰýÝţ´SHY˝˛ˇ˘§÷¸°¨˙űŘř";
	mWindowsEncodingShifter = "cueaauccleooizacelioollssoottlxcaiouaazzee_zcs_______aaes____zz_______aa________dddedniie____tu_obonnnssruruyyt_s__________urr";
}

TextProcessor::~TextProcessor()
{
}


std::string TextProcessor::removeSpecChar()
{
	std::string retString;
	for (int i = 0; i < mTextToProcess.length(); ++i)
	{
			unsigned char ch = mTextToProcess[i];
			if (ch >= ACCENTED_LETTER_THRESHOLD) {
				retString.push_back(mWindowsEncodingShifter[ch- ACCENTED_LETTER_THRESHOLD]); // mUnicodeShifter[ch - 192]);
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

	wTempString = removeSpecChar();
	mCleanText = removeSpacesAndToUpper(wTempString);

	return mCleanText;
}