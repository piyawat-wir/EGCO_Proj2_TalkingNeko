#ifndef CHOICEDIALOG_H
#define CHOICEDIALOG_H
#include<string>
#include"Dialog.h"
#define SIZE 5 
 
class ChoiceDialog : private Dialog {
	string* choices;
public:
	ChoiceDialog(const string ctt, const string choi1, const string choi2, const string choi3, const string choi4);
	~ChoiceDialog();
	friend ostream& operator<< (ostream& s, const ChoiceDialog& x);
};

#endif
