#include <iostream>
#include <string>
#include <windows.h>

#include "lib/display.h"
#include "lib/pixelimg.h"

#include "lib/TextImageDialog.h"
#include "lib/InputDialog.h"
#include "lib/ChoicesSideDialog.h"
#include "lib/RecordLinkedList.h"

#include "lib/predefine.h"
#include "lib/scene.h"

using namespace std;

int main() {
    int a,b;

    rll.load("data.txt");

    Start();
    AskName();
    ResponseName();
    a = scene1_How();
    switch(a){
        case 0: scene1_1_How(); break;
        case 1: scene1_2_How(); break;
        case 2: scene1_3_How(); break;
        case 3: scene1_4_How(); break;
        case 4: scene1_5_How(); break;
    }

    a = scene3_SeAc();
    while(a != 0){
        if(a == 1) { Meme1_1(); Meme1_2(); Meme1_3(); Meme1_4(); Meme1_5(); Meme1_6();}
        if(a == 2) ShowRecord();
        if(a == 3) WebCo();
        a = scene3_SeAc();
    }

    b = scene4_Nice();
    switch(b){
        case 0: scene5_Hav(); break;
        case 1: if(scene6_Ito()==0){ scene6_1_Ito(); break; }
                else { scene6_2_Ito(); break; }
        case 2: scene7_Why(); break;
    }

    do{
        b = scene8_Bytheway();
        switch(b){
            case 0: scene8_1_Bytheway(); break;
            case 1: scene8_2_Bytheway(); break;
            case 2: scene8_3_Bytheway(); break;
            case 3: scene8_4_Bytheway(); break;
            case 4: scene8_5_Bytheway(); break;
        }
    }while(b != 1);

    b = scene9_Youknow();
    if(b == 1) scene9_2_Youknow();
    if(b == 2) scene9_3_Youknow();

    b = scene10_Even();
    if(b == 0) scene10_1_Even();
    if(b == 1) scene10_2_Even();

    if(scene11_Its() == 3) scene11_4_Its();

    do{
        b = scene12_Change();
        if(b == 1) { scene12_2_Change(); scene12_2_1_Change(); }
        if(b == 2) { scene12_3_Change(); scene12_2_1_Change(); }

    }while(b != 0);

    b = scene12_1_Change();
    if(b == 0) scene12_1_1_Change();
    if(b == 1) scene12_1_2_Change();
    if(b == 2) scene12_1_3_Change();

    b = scene13_Does();
    if(b == 0 || b == 1) scene13_1_Does();
    if(b == 2) scene13_3_Does();
    if(b == 3){
            int c = scene13_4_Does();
            if(c == 0 || c == 2) scene13_3_Does();
    }
    b = scene14_Imafraid();
    if(b == 1 || b == 3) scene14_2_Imafraid();
    if(b == 2) scene14_3_Imafraid();
    scene15bye();
    ShowRecord(Rec());
    clearScreen();

    return 0;
}



















