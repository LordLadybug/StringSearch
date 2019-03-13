// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iterator>
#include <tuple>

std::tuple<std::string::iterator, std::string::iterator> FirstCharFinder(std::string string1, std::string string2);
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
		//check for substrings here first using own algorithm
		CompareForSubstrings(string1, string2);
		//then use substr library function for same two strings to verify algorithm works correctly
	}
}

std::tuple<std::string::iterator, std::string::iterator> FirstCharFinder(std::string string1, std::string string2)	//after an astericks, finds first matching character in two strings
{
	std::string::iterator String2Grabber = string2.begin();
	char& firstCharacter = string2.front();
	if (firstCharacter == '*')
	{
		firstCharacter = String2Grabber._Getpnext(); //if string2 begins with wildcard, grab the second character in string2 instead
	}
	std::string::iterator String1Searcher = string1.begin(); //initialize to start of string 1
	do
	{
		if (&String1Searcher == firstCharacter)
		{
			//Set to next character in each string, then continue with search outside of this while loop
			String2Grabber++;
			String1Searcher++;
		}
	} while (&String1Searcher != firstCharacter && String1Searcher != string1.begin());//Stops either upon finding a matching character to firstCharacter or the end of string1, whichever comes first
}

bool CompareForSubstrings(std::string string1, std::string string2) 
{
	//place implementation for checking if second string is a substring of the first
	bool SubstringFlag = false; //return value for function; used to keep track of if string 2 is in fact a substring
	
	//grab first character of string2, then search string1 for same character
	std::string::iterator String2Grabber = string2.begin();
	char& firstCharacter = string2.front();
	std::string::iterator String1Searcher = string1.begin(); //initialize to start of string 1
	<String1Searcher, String2Grabber> = FirstCharFinder(std::string string1, std::string string2);
	
	//Proceed to search through next characters
	while (&String1Searcher == &String2Grabber && String2Grabber != string2.end())
	{
		String2Grabber++;
		String1Searcher++;
		if (&String2Grabber == '*')
		{
			String1Searcher++;
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
