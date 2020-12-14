#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string GetTheShortestWords(string& s)
{
	string tmpWord = "";
	string minWord = "";

	for (int i = 0; i < s.length(); i++) {
		/// If founded space, rewrite word
		if (s[i] != ' ') {
			tmpWord += s[i];
		}
		else {
			if (minWord.length() == 0)//this only happens once
				minWord = tmpWord;//for the first word,you need to assign minWord so you have something to compare to
			if (tmpWord.length() < minWord.length())//move this block here
				minWord = tmpWord;
			tmpWord = "";
		}
	}
	//cout << "Shortest Word: " << minWord << endl;
	//cout << "Word Length: " << minWord.length() << endl;

	return minWord;
}

int GetCountWords(string& s)
{
	bool isWord = false;
	int countWords = 0;
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] != ' ' && !isWord)
		{
			isWord = true;
			countWords++;
		}
		else if (s[i] == ' ')
			isWord = false;
		i++;
	}

	return countWords;
}

void Process(const string src_fname, const string dst_fname)
{
	string s; // прочитаний рядок
	int count = 0;

	ifstream fin(src_fname); // відкрили файл для зчитування
	ofstream fout(dst_fname); // відкрили файл для запису
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		count += GetCountWords(s);
		fout << GetTheShortestWords(s) << endl;
	}
	fout << count << endl;
	fout.close();
	fin.close();
}

void PrepareAndSaveTXTFile(const string fname) // створення файлу з введених рядків
{
	string s;

	ofstream fout(fname);
	s = "Create a text file";
	fout << s << endl;
	s = "Find the shortest word";
	fout << s << endl;
	s = "Write down the shortest word and number of words";
	fout << s << endl;
	fout.close();
}

void PrintFromTXTFile(const string fname) // виведення файлу на екран
{
	string s; // прочитаний рядок

	ifstream fin(fname); // відкрили файл для зчитування
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}

void Menu()
{
	int menuItem;
	string src_fname = "source.txt"; // ім'я першого файлу
	string dst_fname = "result.txt"; // ім'я другого файлу

	do {
		cout << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - Prepare and save TXTFile" << endl;
		cout << " [2] - Print from sourceFile" << endl;
		cout << " [3] - Process (find the shortest word in each string and number of words)" << endl;
		cout << " [4] - Print from resultFile" << endl;
		cout << " [0] - exit" << endl << endl;
		cout << "Enter a number: "; cin >> menuItem;
		cout << endl << endl;

		switch (menuItem)
		{
		case 1:
			PrepareAndSaveTXTFile(src_fname);
			break;
		case 2:
			cout << "Content of " << src_fname << " : " << endl;
			PrintFromTXTFile(src_fname);
			break;
		case 3:
			Process(src_fname, dst_fname);
			break;
		case 4:
			cout << "Content of " << dst_fname << " : " << endl;
			PrintFromTXTFile(dst_fname);
			break;
		case 0:
			break;
		default:
			cout << "You have entered an incorrect value! "
				"You must enter the number - the number of the selected menu item" << endl;
		}

	} while (menuItem != 0);
}

int main()
{
	Menu();

	return 0;
}
