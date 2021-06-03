/* Spell Corrector Program using C++.
this program checks the spelling of the entered word is right or wrong. */
#include <iostream>
// fstream is used to read and write from/to the file.
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <conio.h>

using namespace std;

//lower case alphabets.
char lower_alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


// function to check if there is extra character present in a word or not.
int extrachar_check(string input)
{
	int found = 0;
	string str;
	ifstream spell;   //creating object of ifstream with name 'spell.' to access the file
	spell.open("smpl.txt");   
	while (getline(spell, str))
	{
		int str_len = str.length();
		int inp_lenght = input.length();
		if (str_len + 1 == inp_lenght)
		{
			for (int i = 0; i < inp_lenght; ++i)
			{
				string temp_input = input;
				temp_input.erase(temp_input.begin() + i);
				// cout<<temp_input;
				if (temp_input == str)
				{
					 found = 1;
					cout << str << endl;
				}
			}
		}
		else
		{
			continue;
		}
	}
	spell.close();
	return found;
}

// function to check the missing character in a word .
int missedchar_check(string input)
{
	string str;
	int found = 0;
	string temp_input, temp_str;
	ifstream spell;   //creating object of ifstream with name 'spell.' to access the file
	spell.open("smpl.txt");
	while (getline(spell, str))
	{

		for (int i = 0; i < 26; i++)
		{
			int str_len = str.size();
			int inp_lenght = input.size();
			temp_input = input;
			temp_str = str;
			temp_input.resize(inp_lenght + 1, 'a');
			temp_input[inp_lenght] = lower_alpha[i];
			inp_lenght = temp_input.size();

			string input1, str1;
			if (inp_lenght == str_len)
			{
				for (int j = 1; j <= inp_lenght; j++)
					input1.push_back(temp_input[j]);

				for (int j = 1; j <= str_len; j++)
					str1.push_back(temp_str[j]);
				// cout<<temp_str<<" ";
				temp_input.resize(1);				//the given statement make the size of input_1 to 1..
				temp_str.resize(1);					//the given statement make the size of str_1 to 1..
				sort(input1.begin(), input1.end()); //sorting the charcter of the string
				sort(str1.begin(), str1.end());		//sorting the charcter of the string
				//now adding the first character and sorted string for the 'input'	and 'str'.

				string add_input = temp_input + input1;
				string add_str = temp_str + str1;

				if (add_input == add_str)
				{
					found = 1;
					cout << str << endl;
					break;
				}
			}
			if (found == 1)
				break;
		}
		if (found == 1)
			break;
	}
	spell.close();
	return found;
}


// function to check if there is exchange of characters in a given word i.e. 
//right character is missing and wrong one is present in the word.ex (rigst-right)
int exchangechar_check(string input)
{
	string str;
	int found = 0;
	ifstream spell;			//creating object of ifstream with name 'spell.' to access the file
	spell.open("smpl.txt"); //opening the file sample.txt.

	while (getline(spell, str)) //loop to acces all the element inside file.
	{
		int inp_lenght = input.length();
		int str_len = str.length();
		if (inp_lenght == str_len) //if the length of input string and current str of file is same then we are going to perform operations.
		{
			for (int i = inp_lenght; i >= 0; i--) //outer loop for putting each charcter at each position of the string.
			{
				string temp_input = input;
				temp_input[i] = lower_alpha[0];

				for (int j = 0; j < 26; ++j) //inner loop for putting each charater in place of i for matching correct spelling within the file.
				{
					if (temp_input == str) //if the temp_input matched with the word inside file then this may be the right spelling
					{
						found = 1;
						cout << temp_input << endl;
						break;
					}
					temp_input[i] = lower_alpha[j]; //putting next charcter from lower_alpha in place of i.
				}
				if (found == 1)
					break;
			}
		}
	}
	spell.close();

	return found;
}

// function to check if there is incorrect arrangement of characters inside a word or not.( desret-desert)
int incorrectArrangement_check(string input)
{
	int found = 0;
	string str;
	ifstream spell;   //creating object of ifstream with name 'spell.' to access the file
	spell.open("smpl.txt");
	while (getline(spell, str))
	{
		int inp_lenght = input.length();
		int str_len = str.length();
		string temp_input;
		string temp_str;
		string input_1 = input;
		string str_1 = str;

		if (inp_lenght == str_len)
		{
			for (int i = 1; i < inp_lenght; ++i)
			{
				temp_input.push_back(input[i]);
				temp_str.push_back(str[i]);
			}
			input_1.resize(1);							//the given statement make the size of input_1 to 1..
			str_1.resize(1);							//the given statement make the size of str_1 to 1..
			sort(temp_input.begin(), temp_input.end()); //sorting the charcter of the string
			sort(temp_str.begin(), temp_str.end());		//sorting the charcter of the string
			//now adding the first character and sorted string for the 'input'	and 'str'.

			string add_input = input_1 + temp_input;
			string add_str = str_1 + temp_str;

			if (add_input == add_str)
			{
				found = 1;
				cout << str << endl;
				break;
			}
		}
	}
	spell.close();
	return found;
}
// this function is used to check combination of missing character and extra charcter.ex(tommorow-'tomorrow')
int missPlusExtra_check(string input)
{
	string str, temp_input, temp_str;
	int found = 0;
	ifstream spell;   //creating object of ifstream with name 'spell.' to access the file
	spell.open("smpl.txt");
	while (getline(spell, str))
	{
		int inp_lenght = input.length();
		int str_len = str.length();
		if (inp_lenght == str_len)
		{
			for (int i = 1; i < inp_lenght; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					temp_input = input;
					temp_str = str;
					temp_input.erase(temp_input.begin() + i);
					temp_input.resize(inp_lenght, 'a');
					temp_input[inp_lenght - 1] = lower_alpha[j];
					sort(temp_input.begin() + 1, temp_input.end());
					sort(temp_str.begin() + 1, temp_str.end());
					if (temp_input == temp_str)
					{
						found = 1;
						cout << str << endl;
						break;
					}
				}
				if (found == 1)
					break;
			}
			if (found == 1)
				break;
		}
	}
	spell.close();
	return found;
}

int main()
{
	while (1)
	{
		string input;
		string str;
		int correct;
		cout << "enter the spelling" << endl;
		cin >> input;
		// getline(cin,input);
		int inp_lenght = input.length();
		// cout<<inp_lenght;
		for (int i = 0; i < inp_lenght; ++i)
		{
			input[i] = tolower(input[i]);
		}

		ifstream spell;
		spell.open("smpl.txt");

		while (getline(spell, str))
		{
			// cout<<str<<endl;
			if (input == str)
			{
				correct=1;
				break;
			}
			else
			{
				correct = 0;
			}
		}
		spell.close();

		if (correct==1)
            {
                cout<<endl<<"Spelling is correct"<<endl;
            }
		if (correct == 0)
		{
			int extrachar = 0, missedchar = 0, exchangechar = 0, incorrectArrangement = 0, missPlusExtra = 0;
			cout << "spelling is worng. Correct spelling may be --> " << endl;
			extrachar = extrachar_check(input);
			missedchar = missedchar_check(input);
			exchangechar = exchangechar_check(input);
			incorrectArrangement = incorrectArrangement_check(input);
			missPlusExtra = missPlusExtra_check(input);
			

			if (extrachar ==0 && missedchar ==0 && exchangechar ==0 && incorrectArrangement ==0 && missPlusExtra ==0)
			{
				cout << endl<< "No such  word exist in file" << endl;
			}
		}
		cout << endl
			 << "Press any key to continue..." << endl;
			 
		_getch();
	}
	return 0;
}
