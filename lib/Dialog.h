#ifndef DIALOG_H
#define DIALOG_H

#include<iostream>
#include <string>

using namespace std;

class Dialog {
protected:
	string text;
public:
	Dialog(string ctt);
	~Dialog();
	const string& getText() const;
	friend ostream& operator<< (ostream& s, const Dialog& dia);
};

Dialog::Dialog(string ctt) {
	text = ctt;
}
Dialog::~Dialog() {
}
const string& Dialog::getText() const {
	return text;
}
ostream& operator<< (ostream& s, const Dialog& x) {
	s << x.text << "?" << endl;
	return s;
}

#endif
