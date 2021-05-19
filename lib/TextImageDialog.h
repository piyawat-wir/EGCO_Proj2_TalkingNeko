#ifndef TEXTIMAGEDIALOG_H
#define TEXTIMAGEDIALOG_H

#include <iostream>
#include "dialog.h"
#include "display.h"
#include "pixelimg.h"

using namespace std;

class TextImageDialog : public Dialog {
protected:
    PixelImg pixelimg;
    string title;
public:
    TextImageDialog(string titl, string txt, PixelImg pimg);
    int display();
};

TextImageDialog::TextImageDialog(string titl, string txt, PixelImg pimg): Dialog(txt) {
    title = titl;
    pixelimg = pimg;
}
int TextImageDialog::display() {
    clearScreen(); //Always clear screen first

    int w = SCREEN_W-4, h = (float)SCREEN_H/3; //Box Dimension
    int sx = 2, sy = SCREEN_H-h-1; //Box offset

    //Display image
    pixelimg.display((SCREEN_W-2*pixelimg.getWidth())/2, (SCREEN_H-pixelimg.getHeight())/2 - 5);
    //Display box
    outlineBox(title, sx, sy, w, h);
    //Display navigation details
    printColor("[Enter] Next", sx, sy+h, w);
    //Display text
    printColor(text, sx+6, sy+2, w-10, 30);

    keyToContinue(ENTER);
    return 1;
}

#endif // TEXTIMAGEDIALOG_H
