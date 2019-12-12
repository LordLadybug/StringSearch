// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdexcept>

struct IndexPair
{
	int Index1 = 0;
	int Index2 = 0;
};
IndexPair FirstCharFinder(std::string string1, std::string string2);
bool CompareForSubstrings(std::string string1, std::string string2);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		//Should tell user that they need to input two strings, then terminate.
		try
		{
			throw std::invalid_argument("Accepts an argument of two strings only.\n");
			//std::cout << std::exception::what();
			return -1;
		}
		catch (const std::exception&)
		{
			return -1;
		}
	}
	else
	{
		//execute the rest of the program here
		std::string string1 = argv[1];
		std::string string2 = argv[2];
		//check for substrings here using functions below
		CompareForSubstrings(string1, string2);
	}
}

IndexPair FirstCharFinder(std::string string1, std::string string2)
{
	char& firstCharacter = string2[0];
	int String2Grabber = 0;
	int String1Searcher = 0;
	if (firstCharacter == '*')
	{
		String2Grabber++;//if string2 begins with wildcard, grab the second character in string2 instead
		firstCharacter = string2[String2Grabber];
	}
	do
	{
		if (string1[String1Searcher] != firstCharacter)
		{
			//Skip to next character in String1
			String1Searcher++;
		}
	} while (string1[String1Searcher] != firstCharacter && string1[String1Searcher] != '\0');//Stops either upon finding a matching character to firstCharacter or the end of string1, whichever comes first
	IndexPair firstChar;
	firstChar.Index1= String1Searcher;
	firstChar.Index2= String2Grabber;
}

bool CompareForSubstrings(std::string string1, std::string string2)
{
	//place implementation for checking if second string is a substring of the first
	bool SubstringFlag = false; //return value for function; used to keep track of if string 2 is in fact a substring
	
	//start by running the first character finder
	IndexPair FirstChar = FirstCharFinder(string1, string2);
	int String1Searcher = FirstChar.Index1;
	int String2Grabber = FirstChar.Index2;
	//Proceed to search through next characters
	while (string1[String1Searcher] == string2[String2Grabber] && string1[String1Searcher] != '\0')
	{
		//iterates through rest of characters until string2 encounters an astericks or end of string
		String1Searcher++;
		String2Grabber++;
		if (string2[String2Grabber] == '*')
		{
			FirstChar = FirstCharFinder(string1Clipped, string2Clipped);
			//after finding the first index that occurs after the wild card, should be able to keep going until end of string2
		}
		if (string2[String2Grabber] == '\0') {
			bool SubstringFlag = true;
			return SubstringFlag;
		}
	}
	return SubstringFlag;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
