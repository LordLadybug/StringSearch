// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <stdexcept>

bool CompareForSubstrings(std::string string1, std::string string2);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		throw std::invalid_argument("Accepts an argument of two strings only.\n");
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

bool CompareForSubstrings(std::string string1, std::string string2) 
{
	//place implementation for checking if second string is a substring of the first
	bool SubstringFlag; //return value for function; used to keep track of if string 2 is in fact a substring
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
