#ifndef PIXELIMG_H
#define PIXELIMG_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PixelImg {
private:
    int *imagedata;
    int width, height;
public:
    PixelImg(string);
    void display(int, int);
    int getWidth() {return width;};
    int getHeight() {return height;};
};

PixelImg::PixelImg(string filename = "") {
    fstream file;
    file.open(filename, ios::in);

    if (!file) {
        imagedata = NULL;
        width = 0;
        height = 0;
    } else {
        string temp;
        char ch[] = "0\0";
        getline(file, temp); width = stoi(temp);
        getline(file, temp); height = stoi(temp);

        int i, size = width*height;
        imagedata = new int[size];

        for (i = 0; i < size; i++) {
            file >> ch[0];
            imagedata[i] = stoi(ch, nullptr, 16);
        }
    }
}
void PixelImg::display(int sx=0, int sy=0) {
    int x,y;
    for (y = 0; y < height; y++) {
        if (sy+y < 0 || sy+y >= SCREEN_H) continue;
        setxy(sx,sy+y);
        for (x = 0; x < width; x++) {
            if (sx+x < 0 || sx+x >= SCREEN_W) continue;
            setColor(8, imagedata[y*width+x]);
            cout<<"  ";
        }
    }
    //setxy(0,0);
}

#endif // PIXELIMG_H
