// InterviewTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileIoHandler.h"
#include <string>

int main()
{
	FileIoHandler wFileIoHandler("C:\\Users\\yoshi23\\source\\repos\\InterviewTest\\InterviewTest\\Release\\input.txt",
		"C:\\Users\\yoshi23\\source\\repos\\InterviewTest\\InterviewTest\\Release\\output.txt");

	std::string wSt;
	wSt = wFileIoHandler.readFromFile();
	wFileIoHandler.writeToFile(wSt);



    return 0;
}

