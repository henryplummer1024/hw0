#pragma once
#include <fstream>
#include <iostream>>


void closeFile(const char* fileName, std::ifstream* file);
bool openFile(const char* fileName, std::ifstream* file);
void printOutput(const char* fileName, std::string fileContents);
std::string readFile(std::ifstream* file);


int main(int argc, char** argv)
{
	int programSuccess = -1;
	std::ifstream* file = new std::ifstream;

	if (argc != 2)
	{
		std::cout << "Error - incorrect number of command line arguments" << '\n';
		std::cout << "Correct syntax -> hw0 fileToOpen.txt" << std::endl;
		return -2;
	}

	if (openFile(argv[1], file))
	{
		printOutput(argv[1], readFile(file));
		programSuccess = 0;
	}
	else
	{
		programSuccess = -3;
	}

	closeFile(argv[1], file);
	
	delete file;
	
	return programSuccess;
}

void closeFile(const char* fileName, std::ifstream* file)
{
	std::cout << "Closing " << fileName << "..." << std::endl;

	file->close();
}

bool openFile(const char* fileName, std::ifstream* file)
{
	std::cout << "Opening " << fileName << "..." << '\n';

	file->open(fileName, std::ios::in);

	if (!file->is_open())
	{
		std::cout << "Error opening file " << fileName << std::endl;
		return false;
	}
	return true;
}

void printOutput(const char* fileName, std::string fileContents)
{
	std::cout << fileContents << '\n';
	//TODO - BUG
	//appending '\n' changes the output to not match the output file?
	//not appending newline character causes closing file message to 
	//be indented one space
	//possibly caused by differences in unix vs dos file endings
	//code was run in Visual Studio IDE on windows as I am having
	//issues installing the VPN and do not currently have g++ / make
}

std::string readFile(std::ifstream* file)
{
	std::string fileContents;

	while (!file->eof())
	{
		fileContents.push_back(file->get());
	}

	return fileContents;
}