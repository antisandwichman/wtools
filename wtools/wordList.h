#pragma once
#ifndef WORDLIST_H
#define WORDLIST_H
#include "word.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class wordList {
	public:
		wordList getMatches(word testFor);
		void printMatches(word testFor);
		void add(word in);
		wordList getWordsThatContain(vector<char> chars, vector<int> indices);
		void printWordsThatContain(vector<char> chars, vector<int> indices);
		int getSize();
		word wordAt(int index);
		wordList search(word testFor, vector<char> chars, vector<char> excl, vector<int> indices);
		void printSearch(word testFor, vector<char> chars, vector<char> excl, vector<int> indices);
		wordList getWordsThatDontContain(vector<char> excl);
	private:
		vector<word> listOfWords;
		




};

#endif

