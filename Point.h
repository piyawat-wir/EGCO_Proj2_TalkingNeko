#ifndef POINT_H
#define POINT_H
#include<string>
#include"Dialog.h"
class Point : public Dialog {
	unsigned point;
public:
	Point(const string sen, unsigned poi);
	~Point();
	inline int getP() const {
		return point;
	}
	friend ostream& operator<< (ostream& s, const Point& x);
};

#endif
