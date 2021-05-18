#ifndef DIALOG_H
#define DIALOG_H
#include<string>
class Dialog {
protected:
	string cattalk;
public:
	Dialog(string ctt);
	~Dialog();
	const string& getCtt() const;
	friend ostream& operator<< (ostream& s, const Dialog& dia);
};

#endif
