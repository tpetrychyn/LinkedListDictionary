#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#include "dictionary.h"

using namespace std;

int main() {
	ifstream inData;
	inData.open("textFile.txt");
	if (!inData.is_open()) {
		cout << "Indata not found. Terminating." << endl;
		return 0;
	}
	dictionary dict;
	word aWord;
    
    dict.ResetP();
    dict.Iterate();
	while (inData >> aWord.letters) {
		size_t found = aWord.letters.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
        if (found == string::npos)
		{
            if (dict.Find(aWord.letters.substr(0, found))) {
                word *temp = dict.GetP();
                temp->count++;
            } else {
                dict.InsertSorted(aWord.letters.substr(0, found));
            }
		}
	}
	inData.close();

	//First print, sorted with duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		cout << "(" << dict.Read().letters << "," << dict.Read().count << ") ";
		dict.Iterate();
	}
	cout << endl << endl << endl;

    //Remove duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		if (dict.Read().count > 1) {
			dict.DeleteSorted();
		} else
            dict.Iterate();
	}

	//Second print, sorted no duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		cout << "(" << dict.Read().letters << "," << dict.Read().count << ") ";
		dict.Iterate();
	}
	cout << endl;

	return 0;
}
