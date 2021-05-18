#include<iostream>
using namespace std;
#include "Dialog.h"
Dialog::Dialog(string sen) {
	sentence = sen;
}
Dialog::~Dialog() {
	cout << "Dialog class destructor." << endl; 
}
const string& Dialog::getSen() const {
	return sentence;
}
ostream& operator<< (ostream& s, const Dialog& dia) {
	s << dia.sentence;
	return s;
}
