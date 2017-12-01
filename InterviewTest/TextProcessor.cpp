#include "stdafx.h"
#include "TextProcessor.h"

TextProcessor::TextProcessor()
{
	//   "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ"
	mUnicodeShifter = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
						//"üéâäůćçłëŐőîŹÄĆÉĹĺôöĽľŚśÖÜŤťŁ×čáíóúĄąŽžĘę¬źČş«»░▒▓│┤ÁÂĚŞ╣║╗╝Żż┐└┴┬├─┼Ăă╚╔╩╦╠═╬¤đĐĎËďŇÍÎě┘┌█▄ŢŮ▀ÓßÔŃńňŠšŔÚŕŰýÝţ´SHY˝˛ˇ˘§÷¸°¨˙űŘř";
	mWindowsEncoding852 = "ueaauccleooizacelioollssoottlxcaiouaazzee_zcs_______aaes____zz_______aa________dddedniie____tu_obonnnssruruyyt_shy__________urr";

}

TextProcessor::TextProcessor(std::wstring iString) :
	mTextToProcess(iString),
	mCleanText("")
{
				 //   "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ"
	mUnicodeShifter = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
	//"üéâäůćçłëŐőîŹÄĆÉĹĺôöĽľŚśÖÜŤťŁ×čáíóúĄąŽžĘę¬źČş«»░▒▓│┤ÁÂĚŞ╣║╗╝Żż┐└┴┬├─┼Ăă╚╔╩╦╠═╬¤đĐĎËďŇÍÎě┘┌█▄ŢŮ▀ÓßÔŃńňŠšŔÚŕŰýÝţ´SHY˝˛ˇ˘§÷¸°¨˙űŘř";
	mWindowsEncoding852 = "ueaauccleooizacelioollssoottlxcaiouaazzee_zcs_______aaes____zz_______aa________dddedniie____tu_obonnnssruruyyt_shy__________urr";
}

TextProcessor::~TextProcessor()
{
}


#include <iostream>
std::string TextProcessor::removeSpecChar()
{
	std::string retString;
	//This code snipet was inspired by the solution found here: https://stackoverflow.com/questions/14094621/change-all-accented-letters-to-normal-letters-in-c
	for (int i = 0; i < mTextToProcess.length(); ++i)
	{
			unsigned char ch = mTextToProcess[i];
			std::cout << "ch: " << ch << "; mtextproc: " << mTextToProcess[i] << std::endl;
			if (ch >= 128) {
				retString.push_back(mWindowsEncoding852[ch-129]);// mUnicodeShifter[ch - 192]);
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