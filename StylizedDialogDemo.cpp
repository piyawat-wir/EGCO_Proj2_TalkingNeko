#include <iostream>
#include <string>
#include <windows.h>

#include "lib/display.h"
#include "lib/pixelimg.h"

#include "lib/TextImageDialog.h"
#include "lib/InputDialog.h"
#include "lib/ChoicesSideDialog.h"

using namespace std;

void demo1() {
    PixelImg img("img/cattest2.txt");

    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Hello! Nice to meet you! :D  ",
        img
    );

    mydialog.display();
    clearScreen();
    cout<<"You just pressed [Enter] and will be sent to the next dialog."<<endl;
    cout<<" (press any key to continue)"<<endl; getch();
}

void demo2() {
    PixelImg img("img/cattest2.txt");

    InputDialog mydialog(
        " &30Katsuto&70  ",
        "Hello! I'm &30Katsuto&70! What is your name? :D ",
        img
    );

    string a = mydialog.display();
    clearScreen();
    cout<<"Your name is "<<a<<endl;
    cout<<" (press any key to continue)"<<endl; getch();
}

void demo3() {
    PixelImg img("img/cattest2.txt");
    string choices[4] = {
        "Ice cream!!",
        "Pizza.",
        "...",
        "I don wanna eaattttt~"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "What would you like to eat?",
        img,
        choices, 4
    );

    int a = mydialog.display();
    clearScreen();
    cout<<"Selected option: "<<a+1<<endl;
    cout<<" (press any key to continue)"<<endl; getch();
}

int main() {
    demo1();
    demo2();
    demo3();
    return 0;
}



















