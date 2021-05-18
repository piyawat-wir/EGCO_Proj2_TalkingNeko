#include <iostream>
using namespace std;
#include"ChoiceDialog.h"

int main(){
	string str[] = { "a","b", "c", "d", "e"};
	ChoiceDialog a("How are you",str,5);
	a.display(5);

	return 0;
}
