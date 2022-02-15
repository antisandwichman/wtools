#pragma once
#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>
using std::string;
using std::vector;

class word {
	public:
		int indexWhereLetter(char c);
		char letterAtIndex(int i);
		word(string in);
		bool matches(word compareTo);
		bool contains(vector<char> chars, vector<int> indices);
		bool doesntContain(vector<char> chars);
		string get();
	private:
		string w;
		int size;
		
};

#endif
