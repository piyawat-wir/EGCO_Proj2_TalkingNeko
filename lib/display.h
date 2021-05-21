#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>

#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKAQUA 3
#define DARKRED 4
#define PURPLE 5
#define GOLD 6
#define LIGHTGRAY 7
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define AQUA 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

#define UP 0xE048
#define DOWN 0xE050
#define LEFT 0xE04B
#define RIGHT 0xE04D
#define ENTER 0x0D
#define ESC 0x1B
#define BKSPACE 0x08
#define DEL 0xE053

#define NAV_UPDOWN "[\x1e Up] [\x1f Down] Navigate. "
#define NAV_ENTER "[Enter] Select. "
#define NAV_EXIT "[Esc] Exit. "
#define NAV_BACK "[Esc] Back. "

#define SCREEN_W 120
#define SCREEN_H 30

using namespace std;

// Basic Interface creation functions
BOOL setxy(short x, short y) {
	COORD c = {x,y};
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void resetxy() {
    setxy(0,0);
}
void setColor(int ForgC, int BackC) {
    WORD wColor = ((BackC & 15) << 4) + (ForgC & 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void resetColor() {
    setColor(7,0);
}

int printColor(string str, int x=0, int y=0, int maxwidth=0, int animrate=0) {
    int i, j, Fc, Bc;
    char a[] = "0\0", b[] = "0\0";
    setxy(x,y);
    for (i = 0, j = 0; i < str.length(); i++,j++) {
        if (maxwidth > 0) {
            if (j % maxwidth == maxwidth-1 || str[i] == '\n') {
                y += 1;
                setxy(x,y);
                if (str[i] == '\n') {Sleep(animrate*3); j = 0; i++;}
            }
        }
        if (str[i] == '\\') {
            cout<<'\\';
            i++;
        } else if (str[i] == '&') {
            a[0] = str[i+1]; b[0] = str[i+2];
            Fc = stoi(a, nullptr, 16);
            Bc = stoi(b, nullptr, 16);
            setColor(Fc,Bc);
            i += 2;
        } else {
            cout<<str[i];
        }
        if (animrate > 0) Sleep(animrate);
    }
    resetColor();
    return y;
}

// Interface navigation
int getKeyPress() {
    int key;
    key = getch();
    if (key == 0xE0)
        key = (key << 8)+getch();
    return key;
}
void moveindex(int &p_index, int max, int delta) {
    p_index += delta;
    if (p_index >= max) p_index = max-1;
    if (p_index < 0) p_index = 0;
}
int naviUpDown(int &menu_index, int len) {
    switch(getKeyPress()) {
        case UP: moveindex(menu_index,len,-1); break;
        case DOWN: moveindex(menu_index,len,1); break;
        case ENTER: return 0;
        case ESC:
            menu_index = -1;
            return 0;
    }
    return 1;
}

// Static Interface components
void fillBox(int sx, int sy, int w, int h, int color) {
    int y, x;
    setColor(color,color);
    for (y = 0; y < h; y++) {
        if (sy+y < 0 || sy+y >= SCREEN_H) continue;
        for (x = 0; x < w; x++) {
            if (sx+x < 0 || sx+x >= SCREEN_W) continue;
            setxy(sx+x,sy+y);cout<<" ";
        }
    }
    resetColor();
    resetxy();
}
void outlineBox(string label, int sx, int sy, int w, int h) {
    int x,y,b = 1;
    //Draw box outline
    for (y = 0; y < h; y++) {
        if (sy+y < 0 || sy+y >= SCREEN_H) continue;
        for (x = 0; x < w; x++) {
            if (sx+x < 0 || sx+x >= SCREEN_W) continue;
            if ( x > b*2-1 && x < w-b*2 && y > b-1 && y < h-b) setColor(0,0);
            else if (h-y < x-w*2/3) setColor(8,8);
            else if (h-y < x-w/3+h) setColor(7,7);
            else setColor(15,15);
            setxy(x+sx,y+sy);cout<<" ";
        }
    }
    //Add box label
    if (label.length() > 0 && sy >= 0) {
        x = sx+3, y = sy;
        setColor(7,0);setxy(x,y); cout<<char(186);
        printColor(label, x+1,y); cout<<char(186);
    }
    resetColor();
    resetxy();
}
void displayChoices(string *choices, int choicesN, int select=0, int sx=0, int sy=0, int textwidth=0) {
    int i, x = sx, y = sy;
    for (i = 0; i < choicesN; i++, y++) {
        setxy(x,y);

        // Display selection pointer
        if (i == select) {setColor(0,9); cout<<" > ";}
        else {setColor(7,0); cout<<" . ";}

        // Display choices text
        resetColor();
        if (i == select) {
            setColor(9,0);
            y = printColor(choices[i], x+4, y, textwidth);
        } else {
            y = printColor(choices[i], x+4, y, textwidth);
        }
    }
    resetColor();
    resetxy();
}

// Interactive Interface components
void keyToContinue(int key) {
    int press;
    while(press != key) press = getKeyPress();
}
int selectChoices(string choices[], int choicesN, int sx, int sy, int textwidth) {
    int index = 0, state = 1;
    while(state) {
        displayChoices(choices, choicesN, index, sx, sy, textwidth);
        state = naviUpDown(index, choicesN);
        if (index > 0 && state == 0) break;
    }
    return index;
}
string stringInput(int sx=0, int sy=0, int maxlength=0, int fcolor=7, int bcolor=0) {
    string out;
    setxy(sx,sy);
    cin>>out;
    if (maxlength > 0) out = out.substr(0,maxlength);
    return out;
}

void clearScreen() {
    fillBox(0, 0, SCREEN_W, SCREEN_H, BLACK);
}



#endif // DISPLAY_H
