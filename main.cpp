#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "word.h"

using namespace std;
using namespace words;

struct FileNotFound {
	string message;
	string filename;
};

vector<string> load_words(string filename);

int main()
{
	cout << "Welcome to my Word Analyzer App!\n\n";

	string filename = "";
	cout << "Enter a file name: ";
	cin >> filename;

	vector<string> words;

	try
	{
		words = load_words(filename);
	}
	catch (const FileNotFound e)
	{
		cout << e.message << "\n";
		cout << "You entered: " << e.filename << "!\n"
			<< "Closing program.............\n\n";
		return 0;
	}

	cout << "\n";
	cout << words.size() << " WORDS:\n";
	for (string word : words) {
		cout << word << ' ';
	}

	cout << "\n\n";

	// find longest word in the file
	string longestWord = "";
	for (string word : words)
	{
		if (word.length() > longestWord.length()){
			longestWord = word;
		}
	}

	cout << "Longest Word: " << longestWord << "\n\n";

	//new stuff
	// count each word
	map<string, int> word_count;

	for (string word : words)
	{
    		word_count[word]++;
	}

	// display count per word
	cout << "\nCOUNT PER WORD: ";
	for_each(word_count.begin(), word_count.end(), display);
	cout << "\n\n";

	// count duplicate words
	int duplicates = count_if(word_count.begin(), word_count.end(), over_1);

	cout << "DUPLICATE WORDS: " << duplicates << endl;;

	// ask the user for a word to search for
	string searchWord = "";

	cout << "Enter a word to search for: ";
	cin >> searchWord;

	int count = 0;

	for (string word : words)
	{
		if (word.find(searchWord) != string::npos){
			count++;
		}
	}

	cout << searchWord << " appears " << count << " time(s)\n\n";

	return 0;
}

// load words from the file into a vector
vector<string> load_words(string filename)
{
	vector<string> words;
	ifstream inputfile(filename);

	if (inputfile){
		string word;
		while (inputfile >> word){
			words.push_back(word);
		}
		inputfile.close();
		return words;
	} else
	{
		FileNotFound error;
		error.message = "File not found!!!!!!!";
		error.filename = filename;
		throw error;
	}
}
