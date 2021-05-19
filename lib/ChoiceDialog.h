#ifndef CHOICEDIALOG_H
#define CHOICEDIALOG_H
#include<string>
#include"Dialog.h"
 
class ChoiceDialog : public Dialog {
	string* choices;
public:
	ChoiceDialog(const string ctt,string* c, int Size);
	~ChoiceDialog();
	//friend ostream& operator<< (ostream& s, const ChoiceDialog& x);
	void display(int Size) const;
};

#endif
