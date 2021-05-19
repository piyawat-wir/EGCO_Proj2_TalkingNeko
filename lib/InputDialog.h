#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <iostream>
#include "display.h"
#include "pixelimg.h"
#include "TextImageDialog.h"

using namespace std;

class InputDialog : public TextImageDialog {
public:
    InputDialog(string titl, string txt, PixelImg pimg);
    virtual string display();
};

InputDialog::InputDialog(string titl, string txt, PixelImg pimg): TextImageDialog(titl, txt, pimg) {
}
string InputDialog::display() {
    clearScreen(); //Always clear screen first

    int w = SCREEN_W-4, h = (float)SCREEN_H/3; //Box Dimension
    int sx = 2, sy = SCREEN_H-h-1; //Box offset

    //Display image
    pixelimg.display((SCREEN_W-2*pixelimg.getWidth())/2, (SCREEN_H-pixelimg.getHeight())/2 - 5);
    //Display box
    outlineBox(title, sx, sy, w, h);
    //Display navigation details
    printColor("[Enter] Submit", sx, sy+h, w);
    //Display text
    printColor(text, sx+6, sy+2, w-10, 30);

    //Get user input
    printColor("&80>", sx+6, sy+6);
    string output = stringInput(sx+7, sy+6, 20);
    return output;
}

#endif // INPUTDIALOG_H
