#include<iostream>
using namespace std;
#include"Point.h"
Point::Point(const string sen, unsigned poi) : Dialog(sen) {
	point = poi;
}
Point::~Point() {
	cout << "Point class destructor." << endl;
}
ostream& operator<< (ostream& s, const Point& x) {
	s << static_cast<Dialog>(x) << endl;
	s << "Point =" << x.point;
	return s;
}
