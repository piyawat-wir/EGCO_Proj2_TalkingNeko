#include<iostream>
using namespace std;
#include"ChoiceDialog.h"
ChoiceDialog::ChoiceDialog(const string ctt, const string choi1, const string choi2, const string choi3, const string choi4) : Dialog(ctt){
	choices = new string[SIZE];
	choices[0] = choi1;
	choices[1] = choi2;
	choices[2] = choi3;
	choices[3] = choi4;
}
ChoiceDialog::~ChoiceDialog() {
	delete[] choices;
}
ostream& operator<< (ostream& s, const ChoiceDialog& x) {
	s << static_cast<Dialog>(x) << endl;
	s << "1. " << x.choices[0] << endl;
	s << "2. " << x.choices[1] << endl;
	s << "3. " << x.choices[2] << endl;
	s << "4. " << x.choices[3] << endl;
	return s;
}
