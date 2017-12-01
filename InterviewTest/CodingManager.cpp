#include "stdafx.h"
#include "CodingManager.h"
#include "config.h"

CodingManager::CodingManager()
{
}

CodingManager::~CodingManager()
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


std::string CodingManager::getExtendedKeyword()
{
	return mExtendedKeyword;
}


std::string CodingManager::codeText()
{//English capital letters follow each other consecutively in the used
	//character encoding, so we just have shift the character codes down
	//so that they start from 0, because in the Vignere table
	//they also nicely follow each other, A being at 0.
	//We just lookup the corresponding indices of the matrix and we have the coding.
	mCodedText.resize(mTextToCode.length());
	unsigned int wCharText, wCharKeyword;

	for (int i = 0; i < mTextToCode.length(); ++i)
	{
		wCharText = mTextToCode[i];
			wCharKeyword = mExtendedKeyword[i];
			int t = mTextToCode[i];
			int c = mExtendedKeyword[i];
			mCodedText[i] = mCodeTable[wCharText - ANSI_TO_VIGNERE_SHIFT][wCharKeyword - ANSI_TO_VIGNERE_SHIFT];
	}
	return mCodedText;
}

