#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "HashTable.h"


//Helper function declarations
string eraseOneLetter(string x, int index);

void swap(string& x, int i, int j);

bool InVector(vector<string> result, string x);

void putSpace(string& x, string& new_word, int index);

int find_space_index(string x);

void letteratindex(string& x, string& new_word, int index, int charIndex);

void Insertat_Zero(string& x, string& new_word, int charIndex);

void putLetter(string& new_word, int index, int charIndex);


//Functions


//extraLetter – if word is not in dict returns all strings in dict that can be made by deleting a single letter from word
vector<string> extraLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if ( dict.find(word) == false)
	{
		for (int i = 0; i < (int)word.size(); i++)
		{
			string erased = eraseOneLetter(word, i);

			if ( dict.find(erased) && InVector(result, erased) == false)
			{
				result.push_back(erased);
			}
		}

		if (!result.empty())
		{
			sort(result.begin(), result.end());
		}
	}
	else
	{
		result.push_back(word);
	}
	return result;
}


//transposition – input : atr, output : {tar, art} – not rat as that requires swapping more than two adjacent letters
vector<string> transposition(const HashTable& dict, string word)
{
	vector<string> result;

	if (dict.find(word) == false)
	{
		for (int i = 0; i < (int)word.size(); i++)
		{
			string word_copy = word;
			for (int j = 0; j < (int)word.size(); j++)
			{
				if (i != j)
				{
					swap(word_copy, i, j);

					if ( dict.find(word_copy) && InVector(result, word_copy) == false)
					{
						result.push_back(word_copy);
					}
					word_copy = word;

				}
			}
		}

		if (!result.empty())
		{
			sort(result.begin(), result.end());
		}
	}
	else
	{
		result.push_back(word);
	}
	return result;
}

//missingSpace – input : rateat, output : {rat eat, rate at}
vector<string> missingSpace(const HashTable& dict, string word)
{
	vector<string> result;

	if (dict.find(word) == false)
	{
		string x1 = "";
		string x2 = "";
		string word_with_Space = "";

		for (int i = 0; i <= (int)word.size() - 2; i++)
		{
			putSpace(word, word_with_Space, i);
			int space_index = find_space_index(word_with_Space);


			for (int j = 0; j < (int)word_with_Space.size(); j++)
			{
				if (j < space_index)
				{
					x1 += word_with_Space[j];
				}
				else if (j > space_index)
				{
					x2 += word_with_Space[j];
				}
			}

			if (dict.find(x1) && dict.find(x2))
			{
				result.push_back(word_with_Space);
			}

			word_with_Space = "";
			x1 = "";
			x2 = "";
		}

		if (!result.empty())
		{
			sort(result.begin(), result.end());
		}
	}
	else
	{
		result.push_back(word);
	}
	return result;
}

//missingLetter – if word is not in dict returns all strings in dict that can be made by inserting any single letter of the alphabet at any position in word
vector<string> missingLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if( dict.find(word) == false)
	{
		string new_word = "";

		for (int j = 0; j < 26; j++)
		{
			Insertat_Zero(word, new_word, j);
			if (dict.find(new_word) && InVector(result, new_word) == false)
			{
				result.push_back(new_word);
			}
			new_word = "";
		}

		for (int i = 0; i < (int)word.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				letteratindex(word, new_word, i, j);
				if (dict.find(new_word) && InVector(result, new_word) == false)
				{
					result.push_back(new_word);
				}
				new_word = "";
			}
		}

		if (!result.empty())
		{
			sort(result.begin(), result.end());
		}
	}
	else
	{
		result.push_back(word);
	}
	return result;
}

//incorrectLetter – input : thed, output : {shed, thee, them, they, thud, toed} – not shad or thus as they have two incorrect letters
vector<string> incorrectLetter(const HashTable& dict, string word)
{
	vector<string> result;
	if (dict.find(word) == false)
	{
		string new_word = word;

		for (int i = 0; i < (int)word.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				putLetter(new_word, i, j);
				if (dict.find(new_word) && InVector(result, new_word) == false)
				{
					result.push_back(new_word);
				}
				new_word = word;
			}
		}

		if (!result.empty())
		{
			sort(result.begin(), result.end());
		}
	}
	else
	{
		result.push_back(word);
	}
	return result;
}


///////////////////////////////////////////////////////////////////////
///////////////////HELPER FUNCTIONS///////////////////////////////////

//helper function to erase a single letter in a string
string eraseOneLetter(string x, int index)
{
	string ans;
	for (int i = 0; i < (int)x.size(); i++)
	{
		if (i != index)
		{
			ans += x[i];
		}
	}
	return ans;
}

//helper function for transposition to swap two letters in string x
void swap(string& x, int i, int j)
{
	char temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

//helper function to prevent dupliucate words from being put into the result vector
bool InVector(vector<string> result, string x)
{
	if (result.empty())
	{
		return false;
	}

	for (int i = 0; i < (int)result.size(); i++)
	{
		if (result[i] == x)
		{
			return true;
		}
	}
	return false;
}

//helper function to put a space inside a string
void putSpace(string& x, string& new_word, int index)
{
	for (int i = 0; i <= index; i++)
	{
		new_word += x[i];
	}
	new_word += " ";

	for (int i = index + 1; i < (int)x.size(); i++)
	{
		new_word += x[i];
	}
}

//helper function to find the index of a space inside a string
int find_space_index(string x)
{
	string sp = " ";
	for (int i = 0; i < (int)x.size(); i++)
	{
		if (x[i] == sp[0])
		{
			return i;
		}
	}
}

//helper function to insert new letters in the string x
void letteratindex(string& x, string& new_word, int index, int charIndex)
{
	string characters = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i <= index; i++)
	{
		new_word += x[i];
	}
	new_word += characters[charIndex];

	for (int i = index + 1; i < (int)x.size(); i++)
	{
		new_word += x[i];
	}
}

//helper function to insert letters at the begininng of the string x
void Insertat_Zero(string& x, string& new_word, int charIndex)
{
	string characters = "abcdefghijklmnopqrstuvwxyz";
	new_word += characters[charIndex];

	for (int i = 0; i < (int)x.size(); i++)
	{
		new_word += x[i];
	}
}

//helper function to replace letters in string new_word
void putLetter(string& new_word, int index, int charIndex)
{
	string characters = "abcdefghijklmnopqrstuvwxyz";
	new_word[index] = characters[charIndex];
}
