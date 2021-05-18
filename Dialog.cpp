#include<iostream>
using namespace std;
#include "Dialog.h"
Dialog::Dialog(string ctt) {
	cattalk = ctt;
}
Dialog::~Dialog() {
}
const string& Dialog::getCtt() const {
	return cattalk;
}
ostream& operator<< (ostream& s, const Dialog& x) {
	s << x.cattalk << "?" << endl;
	return s;
}
