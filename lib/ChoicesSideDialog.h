#ifndef CHOICESSIDEDIALOG_H
#define CHOICESSIDEDIALOG_H

#include <iostream>
#include "display.h"
#include "pixelimg.h"
#include "TextImageDialog.h"

using namespace std;

class ChoicesSideDialog : public TextImageDialog {
protected:
    string *choices;
    int choicesN;
public:
    ChoicesSideDialog(string titl, string txt, PixelImg pimg, string *choi, int choiN);
    virtual int display();
};
ChoicesSideDialog::ChoicesSideDialog(string titl, string txt, PixelImg pimg, string *choi, int choiN): TextImageDialog(titl, txt, pimg) {
    choices = choi;
    choicesN = choiN;
}
int ChoicesSideDialog::display() {
    clearScreen(); //Always clear screen first

    int sx = 68, sy = 1; //Box offset
    int w = 50, h = 28; //Box Dimension

    //Display image
    pixelimg.display(4,1);
    //Display box
    outlineBox(title, sx, sy, w, h);
    //Display navigation details
    printColor(NAV_UPDOWN NAV_ENTER, sx, sy+h, w);
    //Display text
    printColor(text, sx+6, sy+3, w-8, 30);

    return selectChoices(choices, choicesN, sx+6, sy+8, w-12);
}

#endif // CHOICESSIDEDIALOG_H
