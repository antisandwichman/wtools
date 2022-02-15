#include "wordList.h"
#include "word.h"
#include <vector>
#include <iostream>
using namespace std;

wordList wordList::getMatches(word testFor) {
	wordList listOfMatches;
	for (int cur = 0; cur < listOfWords.size(); cur++) {
		bool match =
			listOfWords[cur].matches(testFor);
		if (match) {
			listOfMatches.add(listOfWords[cur]);
		}
	}
	return listOfMatches;
}

void wordList::printMatches(word testFor) {
	wordList listOfMatches = getMatches(testFor);
	for (int cur = 0; cur < listOfMatches.getSize(); cur++) {
		cout << listOfMatches.wordAt(cur).get() << endl;
	}

}

void wordList::add(word in) {
	listOfWords.push_back(in);
}

wordList wordList::getWordsThatContain(vector<char> chars, vector<int> indices) {
	
	wordList listContaining;

	for (int cur = 0; cur < listOfWords.size(); cur++) {
		bool wordContains =
			listOfWords[cur].contains(chars, indices);
		if (wordContains) {
			listContaining.add(listOfWords[cur]);
		}
	}

	return listContaining;

}

wordList wordList::getWordsThatDontContain(vector<char> excl) {
	wordList listNotContaining;

	for (int cur = 0; cur < listOfWords.size(); cur++) {
		if (listOfWords[cur].doesntContain(excl)) {
			listNotContaining.add(listOfWords[cur]);
		}
	}
	
	/*
	for (int cur = 0; cur < listNotContaining.getSize(); cur++) {
		cout << listNotContaining.wordAt(cur).get() << endl;
	}
	*/
	return listNotContaining;
}

int wordList::getSize() {
	return listOfWords.size();
}

word wordList::wordAt(int index) {
	return listOfWords[index];
}

void wordList::printWordsThatContain(vector<char> chars, vector<int> indices) {
	wordList toBePrinted = getWordsThatContain(chars, indices);
	for (int cur = 0; cur < toBePrinted.getSize(); cur++) {
		cout << toBePrinted.wordAt(cur).get() << endl;
	}
}

wordList wordList::search(word testFor, vector<char> chars, vector<char> excl, vector<int> indices) {
	wordList containsList = getWordsThatContain(chars, indices);
	wordList matchList = getMatches(testFor);
	wordList doesntContainList = getWordsThatDontContain(excl);
	wordList intersectionMC;
	wordList intersectionID;
	
	
	for (int c = 0; c < containsList.getSize(); c++) {
		for (int m = 0; m < matchList.getSize(); m++) {
			bool match =
				containsList.wordAt(c).get() == matchList.wordAt(m).get();

			if (match) {
				intersectionMC.add(containsList.wordAt(c).get());
			}
		}
	}

	for (int i = 0; i < intersectionMC.getSize(); i++) {
		for (int d = 0; d < doesntContainList.getSize(); d++) {
			bool match =
				intersectionMC.wordAt(i).get() == doesntContainList.wordAt(d).get();

			if (match) {
				intersectionID.add(intersectionMC.wordAt(i).get());
			}
		}
	}

	return intersectionID;

}

void wordList::printSearch(word testFor, vector<char> chars, vector<char> excl, vector<int> indices) {
	wordList intersection = search(testFor, chars, excl, indices);
	for (int cur = 0; cur < intersection.getSize(); cur++) {
		cout << intersection.wordAt(cur).get() << endl;
	}
}