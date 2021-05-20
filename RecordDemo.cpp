#include <iostream>
#include "lib/RecordLinkedList.h"

using namespace std;

int main() {

    //Create test data.
    RecordLinkedList rll;
    rll.add("1john", 7);
    rll.add("2james", 3);
    rll.add("3jack", 1);
    rll.add("4jane", 5);

    rll.print(); //display data
    rll.save("data.txt"); //save data

    rll.clean(); //clear data
    rll.print(); //display and check if it's cleared

    rll.load("data.txt"); //load back saved data
    rll.print(); //display and check if data is loaded
}
