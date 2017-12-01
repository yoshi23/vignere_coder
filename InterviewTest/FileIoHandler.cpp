#include "stdafx.h"
#include "FileIoHandler.h"

#include <iostream>


FileIoHandler::FileIoHandler() :
 mInFilePath(INPUT_FILE), //paths are defined in config.h
 mOutFilePath(OUTPUT_FILE),
 mCodeTablePath(VIGNERETABLE_FILE)
{
}

FileIoHandler::~FileIoHandler()
{
}

//This method was used during development, to make
//testing faster.
std::wstring FileIoHandler::getInputText()
{
	std::wifstream mIfstream(mInFilePath);
	if (!mIfstream.is_open()) std::cout << "Warning: problems with opening input file.\n";

	std::wstring lineToCode;
	getline(mIfstream, lineToCode);
	mIfstream.close();
	return lineToCode;
}

void FileIoHandler::writeOutputText(const std::string & iText, const std::string & optText)
{
	std::ofstream mOfstream(mOutFilePath);
	if (!mOfstream.is_open()) std::cout << "Warning: problems with opening output file.\n";

	for (int i = 0; i < iText.size(); ++i) //we exploit that fact that we have single line texts as input
	{
		mOfstream << iText[i];
	}
	mOfstream.close();
}

char** FileIoHandler::vigenereTableReader()
{
	//The matrix is symmetric, but we read in the complete matrix.
	//Thus, we are wasting a little memory space here.
	//But this way, asking for values form the Vigenere table is more comfortable,
	//than in the case if we only create a lower / upper triangle matrix to save memory.
	std::ifstream  wCodeTableFile(mCodeTablePath);

	char** wCodeMatrix;
	wCodeMatrix = new char*[ALPHABET_SIZE];

	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		wCodeMatrix[i] = new char[ALPHABET_SIZE]; 
	}

	std::string line;
	int i = 0;

	while (getline(wCodeTableFile, line))
	{
		for (int j = 0; j < line.size(); ++j)
		{
			wCodeMatrix[i][j] = line[j];
		}
		++i;
	}

	if (i < ALPHABET_SIZE-1) std::cout << "The provided code table was not full.\nLess letters than expected in set alphabet\n";

	return wCodeMatrix;
}
