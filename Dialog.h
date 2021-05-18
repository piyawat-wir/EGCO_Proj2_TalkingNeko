#ifndef DIALOG_H
#define DIALOG_H
#include<string>
class Dialog {
	string sentence;
public:
	Dialog(string sen);
	~Dialog();
	const string& getSen() const;
	friend ostream& operator<< (ostream& s, const Dialog& dia);
};

#endif
