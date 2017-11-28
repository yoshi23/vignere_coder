#include "stdafx.h"
#include "FileIoHandler.h"

#include <fstream>

FileIoHandler::FileIoHandler()
{
}

FileIoHandler::FileIoHandler(std::string iFilePath, std::string oFilePath) :
	mInFile(iFilePath),
	mOutFile(oFilePath)
{}


FileIoHandler::~FileIoHandler()
{
}

std::string FileIoHandler::readFromFile()
{
	std::ifstream iFile(mInFile);
	std::string lineToCode;
	getline(iFile, lineToCode);
	iFile.close();
	return lineToCode;
}

void FileIoHandler::writeToFile(std::string iText)
{
	std::ofstream oFile(mOutFile);
	for (int i = 0; i < iText.size(); ++i) //we exploit that fact that we have single line texts as input
	{
		oFile << iText[i];
	}
	oFile.close();
}
