#pragma once

#include <string>
class FileIoHandler
{
public:
	FileIoHandler();
	FileIoHandler(std::string iFilePath, std::string oFilePath);
	~FileIoHandler();

	std::string readFromFile();
	void writeToFile(std::string iText);
private:
	std::string mInFile;
	std::string mOutFile;
};

