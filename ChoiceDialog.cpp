#include<iostream>
#include<string>
using namespace std;
#include"ChoiceDialog.h"

ChoiceDialog::ChoiceDialog(const string ctt, string* c,int Size) : Dialog(ctt){
	choices = new string[Size];
	for (int i = 0; i < Size; i++)
		choices[i] = c[i];
}
ChoiceDialog::~ChoiceDialog() {
	delete[] choices;
}
void ChoiceDialog::display(int Size) const {
	cout << static_cast<Dialog>(*this) << endl;
	for (int i = 0; i < Size; i++)
		cout << (i + 1) << "." << choices[i] << endl;
}
/*ostream& operator<< (ostream& s, const ChoiceDialog& x) {
	s << static_cast<Dialog>(x) << endl;
	int Size = sizeof(x.choices) / sizeof(x.choices[0]);
	for (int i = 0; i < Size; i++) {
		cout << (i + 1) << "." << x.choices[i];
	}
	return s;
}*/
