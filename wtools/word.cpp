#include "word.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

word::word(string in) {
	w = in;
	size = w.length();
}

int word::indexWhereLetter(char c) {
	for (int cur = 0; cur < size; cur++) {
		bool match =
			w.at(cur) == c;
		if (match) {
			return cur;
		}
	}
	return -1;
}

char word::letterAtIndex(int i) {
	return w.at(i);
}

bool word::matches(word compareTo) {
	bool isMatch = true;
	//cout << "Checking if " << get() << " matches " << compareTo.get() << endl;
	for (int cur = 0; cur < size; cur++) {
		bool curIsMatch = (
			w.at(cur) == compareTo.get().at(cur) ||
			'_' == compareTo.get().at(cur)
		);
		if (!curIsMatch) {
			isMatch = false;
			//cout << "cur is not match" << endl;
		} else {
			//cout << "cur is match" << endl;
		}
	}

	return isMatch;
}

bool word::contains(vector<char> chars, vector<int> indices) {
	bool hasAll = false;
	int matchCount = 0;
	int matchGoal = chars.size();

	for (int testLetterIndex = 0; testLetterIndex < chars.size(); testLetterIndex++) {
		if (letterAtIndex(indices[testLetterIndex]) == chars[testLetterIndex]) {
			return false;
		}
		for (int wordLetterIndex = 0; wordLetterIndex < size; wordLetterIndex++) {
			bool hasThis =
				letterAtIndex(wordLetterIndex) == chars[testLetterIndex];
			if (hasThis) {
				matchCount++;
				break;
			}
		}
	}
	hasAll =
		matchCount == matchGoal;
	return hasAll;
}

bool word::doesntContain(vector<char> chars) {
	bool hasNone = true;
	for (int testLetterIndex = 0; testLetterIndex < chars.size(); testLetterIndex++) {
		for (int wordLetterIndex = 0; wordLetterIndex < size; wordLetterIndex++) {
			bool match =
				chars[testLetterIndex] == w.at(wordLetterIndex);
			if (match) {
				hasNone = false;
				return hasNone;
			}
		}
	}

	return hasNone;
}



string word::get() {
	return w;
}
