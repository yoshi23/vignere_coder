#include "stdafx.h"

#include "config.h"

#include "FileIoHandler.h"
#include <iostream>


FileIoHandler::FileIoHandler() :
 mInFilePath("input.txt"),
 mOutFilePath("kodolt.dat"),
 mCodeTablePath("vtabla_c++.dat")
{
#ifdef DEVELOPMENT_PROCESS
	mIfstream.open("input.txt");
#endif // DEVELOPMENT_PROCESS

	mOfstream.open("kodolt.dat");
}

FileIoHandler::~FileIoHandler()
{
#ifdef DEVELOPMENT_PROCESS
	if(mIfstream.is_open()) mIfstream.close();
#endif // DEVELOPMENT_PROCESS

	if(mOfstream.is_open())mOfstream.close();

}

std::string FileIoHandler::getInputText()
{
	std::string lineToCode;
	if (!mIfstream.is_open()) mIfstream.open(mInFilePath);
	getline(mIfstream, lineToCode);
	mIfstream.close();
	return lineToCode;
}

void FileIoHandler::writeOutputText(const std::string & iText)
{
	if (!mOfstream.is_open()) mOfstream.open(mOutFilePath);




	



	for (int i = 0; i < iText.size(); ++i) //we exploit that fact that we have single line texts as input
	{
		mOfstream << iText[i];
	}
	mOfstream.close();
}

char** FileIoHandler::vigenereTableReader()
{
	std::ifstream  wCodeTableFile(mCodeTablePath);
	char** wCodeMatrix;
		wCodeMatrix = new char*[ALPHABET_SIZE];
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		wCodeMatrix[i] = new char[ALPHABET_SIZE]; 
		//The matrix is symmetric so it might be useful to store only upper/lowertriangle. 
		//TODO: consider if making sure that i<j indexing is fast enough or easier to store the whole matrix.
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

	if (i < ALPHABET_SIZE-1) std::cout << "The provided code table was not full.\nLess letters than in set alphabet\n";

	return wCodeMatrix;
}
