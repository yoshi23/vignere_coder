#include "stdafx.h"
#include "CodingManager.h"
#include "config.h"

CodingManager::CodingManager()
{
}

CodingManager::CodingManager(std::string iTextToCode, std::string iKeyword, char ** iCodeTable) :
	mTextToCode(iTextToCode),
	mKeyword(iKeyword),
	mCodeTable(iCodeTable)
{
	int wTextLen = mTextToCode.length();
	int wKeyWordLen = mKeyword.length();
	int wholeDividor = wTextLen / wKeyWordLen;
	int remainder = wTextLen % wKeyWordLen;

	mExtendedKeyword.resize(wTextLen);

	for (int i = 0; i < wTextLen; ++i)
	{
		mExtendedKeyword[i] = mKeyword[i%wKeyWordLen];
	}
}


CodingManager::~CodingManager()
{
}

std::string CodingManager::getExtendedKeyword()
{
	return mExtendedKeyword;
}



std::string CodingManager::codeText()
{
	/*
				unsigned char ch = mTextToProcess[i];
			if (ch >= 192) {
				retString.push_back(mUnicodeShifter[ch - 192]);
			}
			*/
	mCodedText.resize(mTextToCode.length());
	unsigned int wCharText, wCharKeyword;

	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			std::cout << mCodeTable[i][j];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < mTextToCode.length(); ++i)
	{
		wCharText = mTextToCode[i];
			wCharKeyword = mExtendedKeyword[i];
			int t = mTextToCode[i];
			int c = mExtendedKeyword[i];
			std::cout << std::endl<<wCharText << " || " << wCharKeyword <<" VS "<<t<<" || "<<c <<std::endl;
			mCodedText[i] = mCodeTable[wCharText - UNICODE_SHIFT_VAL][wCharKeyword - UNICODE_SHIFT_VAL];
	}


	return mCodedText;
}

