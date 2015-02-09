#include "dictionary.h"
#include <stdlib.h>
#include <locale>

dictionary::dictionary() {
	p = nullptr;
    head = nullptr;
	length = 0;
    prevP = nullptr;
}

dictionary::~dictionary() {
}

void dictionary::Iterate() {
   // word *prevP;
    if (p == NULL) {
        prevP = NULL;
        p = head;
    } else {
        prevP = p;
        p = p->next;
    }
    return;
}

void dictionary::ResetP() {
	p = nullptr;
	return;
}

word dictionary::Read() {
	return *p;
}

bool dictionary::Find (string wordToFind) {
    prevP = NULL;
    p = head;
    while (p != NULL) {
        if (wordToFind == p -> letters)
            return true;
        prevP = p;
        p = p -> next;
    }
    return false;
}

void dictionary::DeleteSorted() {
   // word *prevP = NULL;
    word *q;
    if (prevP == NULL) {
        head = head -> next;
        q = head;
    } else {
        if (p -> next == NULL)
            prevP -> next = NULL;
        else
            prevP -> next = p -> next;
        q = p -> next;
    }
    delete p;
    p = q;
    length --;
    return;
}

void dictionary::InsertSorted(string wordToAdd) {
    word *q = new word;
    prevP = NULL;
    p = head;
    while (p != NULL and wordToAdd >= p -> letters) {
        prevP = p;
        p = p -> next;
    }
    q -> letters = wordToAdd;
        q -> next = p;
    if (prevP == NULL)
        head = q;
    else
        prevP -> next = q;
    p = q;
    length ++;
    return;
}

bool dictionary::IsPSet() {
	if (p == nullptr)
		return false;
	return true;
}

word::word() {
	letters = "";
	count = 1;
}