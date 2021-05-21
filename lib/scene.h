void Start() {
    img_start.display();
    setxy(0,0);

    printColor("&8e ( Press any key to start ) ", 45, 27, 0, 30); getch();
    clearScreen();
}
void AskName() {
    InputDialog mydialog(
        " &30Katsuto&70  ",
        "Hello! I'm &30Katsuto&70! What is your name? :D ",
        img_cheer
    );

    Name = mydialog.display();
    clearScreen();
}
void ResponseName() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        Name + " is a very good name! :D",
        img_cheer
    );

    mydialog.display();
    clearScreen();
}
void ShowRecord(int i = -1) {
    rll.print(i);
    cout<<"   ( Press any key to continue )"<<endl; getch();
}
int Rec(){
    int i = rll.add(Name, PlayScore);
    rll.save("data.txt");
    clearScreen();
    return i;
}
int scene1_How() {
    string choices[5] = {
        "I'm pretty good!",
        "I'm fine",
        "So so...",
        "Not very well...",
        "Really bad."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "How are you doing?",
        img_normal,
        choices, 5
    );
    int x = mydialog.display();
    int ChoiceScore[5] = {2,1,0,-1,-2};
    PlayScore += ChoiceScore[x];
    clearScreen();
    return x;
}
void scene1_1_How() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "I'm glad to hear that! :D  ",
        img_bigsmile
    );

    mydialog.display();
    clearScreen();
}
void scene1_2_How() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "That's wonderful.",
        img_bigsmile
    );

    mydialog.display();
    clearScreen();
}
void scene1_3_How() {
    PixelImg img("img/cattest2.txt");
    string choices[1] = {
        "I'm not Takeshi."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Fight on! Takeshi !",
        img_cheer,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene1_4_How() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "I hope you get better soon.",
        img_normal
    );

    mydialog.display();
    clearScreen();
}
void scene1_5_How() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "I'm always here for you",
        img_confused
    );

    mydialog.display();
    clearScreen();
}
int scene3_SeAc() {
    string choices[4] = {
        "Talk to cat.",
        "Ask a meme.",
        "Game Record.",
        "Websites for COVID-19"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Select an activity",
        img_readbook,
        choices, 4
    );
    int a = mydialog.display();
    clearScreen();
    return a;
}
int scene4_Nice() {
    string choices[3] = {
        "Nice to meet you too.",
        "I took a shine to you at first sight.",
        "I don't want to see you."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Nice to meet you.",
        img_bigsmile,
        choices, 3
    );
    int i = mydialog.display();
    int ChoiceScore[3] = {1,2,-1};
    PlayScore += ChoiceScore[i];
    clearScreen();
    return i;
}
void WebCo() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "https://ddc.moph.go.th/viralpneumonia/index.php \nhttps://www.cdc.gov/coronavirus/2019-ncov/index.html\nhttps://covid19.who.int \nhttps://covid-19.kapook.com",
        img_bigsmile
    );

    mydialog.display();
    clearScreen();
}
void scene5_Hav() {
    string choices[3] = {
        "Of course.",
        "I never met a cute cat like you before",
        "No."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Have you ever met a cute cat like me?",
        img_shy,
        choices, 3
    );
    int i = mydialog.display();
    int ChoiceScore[3] = {1,3,2};
    PlayScore += ChoiceScore[i];
    clearScreen();
}
int scene6_Ito() {
    string choices[2] = {
        "Wait! I just kidding.",
        "Let's get married. "
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "I took a shine to you at first sight too.",
        img_shy,
        choices, 2
    );
    int i = mydialog.display();
    int ChoiceScore[2] = {1,3};
    PlayScore += ChoiceScore[i];
    clearScreen();
    return i;
}
void scene6_1_Ito() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "You're really getting on my nerves right now.",
        img_angry
    );

    mydialog.display();
    clearScreen();
}
void scene6_2_Ito() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "I'm always here for you.",
        img_shy
    );

    mydialog.display();
    clearScreen();
}
void scene7_Why() {
    string choices[3] = {
        "Because I have a crush on you \nand I'm embarrassed to meet you.",
        "I don't know.",
        "I don't like cats."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Why you said like that?",
        img_confused,
        choices, 3
    );
    int i = mydialog.display();
    int ChoiceScore[3] = {3,2,1};
    PlayScore += ChoiceScore[i];
    clearScreen();
}
int scene8_Bytheway() {
    string choices[5] = {
        "I have no idea.",
        "Thailand",
        "Africa",
        "Pluto",
        "Let me go ask my dad first."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "By the way, Let me ask. Guess which\ncountry do I live in right now? ",
        img_readbook,
        choices, 5
    );
    int i = mydialog.display();
    clearScreen();
    return i;
}
void scene8_1_Bytheway() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Hang in there. Don't give up.",
        img_cheer
    );

    mydialog.display();
    clearScreen();
}
void scene8_2_Bytheway() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Ping Pong! Correctly.",
        img_bigsmile
    );

    mydialog.display();
    clearScreen();
}
void scene8_3_Bytheway() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Keep going. You're getting closer.",
        img_cheer
    );

    mydialog.display();
    clearScreen();
}
void scene8_4_Bytheway() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Unlucky! But... Wait! Pluto is not a country.",
        img_angry
    );

    mydialog.display();
    clearScreen();
}
void scene8_5_Bytheway() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Hope your father knows.",
        img_bigsmile
    );

    mydialog.display();
    clearScreen();
}
int scene9_Youknow() {
    string choices[3] = {
        "I knew.",
        "I don't know.",
        "I don't care."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "You know, my country has a lot\nof people infected with the coronavirus.",
        img_confused,
        choices, 3
    );
    int i = mydialog.display();
    int ChoiceScore[3] = {3,2,1};
    PlayScore += ChoiceScore[i];
    clearScreen();
    return i;
}
void scene9_2_Youknow() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "You never know anything.",
        img_angry
    );

    mydialog.display();
    clearScreen();
}
void scene9_3_Youknow() {
    string choices[3] = {
        "Thanks",
        "Nope",
        "OK"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "The COVID 19 is so frightening, you have\nto pay attention and take care of\nyourself.",
        img_normal,
        choices, 3
    );
    int i = mydialog.display();
    int ChoiceScore[3] = {1,0,1};
    PlayScore += ChoiceScore[i];
    clearScreen();
}
int scene10_Even() {
    string choices[4] = {
        "Really?",
        "Are you sure?",
        "Very very good.",
        "Unbelievable"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Even though my country has a lot of\ninfected people But the government takes\ngood care of the people.",
        img_bigsmile,
        choices, 4
    );
    int i = mydialog.display();
    int ChoiceScore[4] = {1,1,2,0};
    PlayScore += ChoiceScore[i];
    clearScreen();
    return i;
}
void scene10_1_Even() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "YES!!!",
        img_readbook
    );

    mydialog.display();
    clearScreen();
}
void scene10_2_Even() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Of course!!!",
        img_readbook
    );

    mydialog.display();
    clearScreen();
}
int scene11_Its() {
    PixelImg img("img/cattest2.txt");
    string choices[4] = {
        "Cheer up!",
        "Look on the bright side.",
        "Don't be close to me,\nI'll be infected!",
        "May the force be with you."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "It's could happen to anyone.\nMaybe I am already infected.",
        img_confused,
        choices, 4
    );
    int i = mydialog.display();
    int ChoiceScore[4] = {2,3,1,0};
    PlayScore += ChoiceScore[i];
    clearScreen();
    return i;
}
void scene11_4_Its() {
    TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "Thank you very much but I'm not Goku.",
        img_drunk
    );

    mydialog.display();
    clearScreen();
}
int scene12_Change() {
    string choices[3] = {
        "( Change the topic of discussion )",
        "( Singing Doraemon song )",
        "( Laughing )"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "(......)",
        img_sad,
        choices, 3
    );
    int i = mydialog.display();
    clearScreen();
    return i;
}
int scene12_1_Change() {
    string choices[3] = {
        "Snakes with scales or not.",
        "Eels with scales or not",
        "Lizards with scales or not"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "(......)",
        img_sad,
        choices, 3
    );
    int i = mydialog.display();
    clearScreen();
    return i;
}
void scene12_1_1_Change() {
    string choices[1] = {
        "(...)"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Snake without scales. Stupid question.",
        img_angry,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene12_1_2_Change() {
    string choices[1] = {
        "(...)"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Eels must have scales. stupid question.",
        img_angry,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene12_1_3_Change() {
    string choices[1] = {
        "(...)"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Lizards must have scales. stupid question. ",
        img_angry,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene12_2_Change() {
    string choices[1] = {
        "Konna Koto Iina Dekitara Iina\nAnna Yume Konna Yume\nIppai Aru Kedo"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "(......)",
        img_sad,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene12_2_1_Change() {
    string choices[1] = {
        "5555"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "You encourage me or make teasing of me.",
        img_confused,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene12_3_Change() {
    string choices[1] = {
        "5555555555555555555555555555555555555555555555555555555555555555555"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "(......)",
        img_sad,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
int scene13_Does() {
    string choices[4] = {
        "You make my heart warm and happy.",
        "I'm lucky to have you in my life.",
        "Nope.",
        "A little bit."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Does talking to me make you feel better?",
        img_bigsmile,
        choices, 4
    );
    int i = mydialog.display();
    clearScreen();
    int ChoiceScore[4] = {2,2,0,1};
    PlayScore += ChoiceScore[i];
    return i;
}
void scene13_1_Does() {
    string choices[2] = {
        "Thank you.",
        "You make me feel like I was \n14 years old"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "-/////- I'm glad to hear that.",
        img_shy,
        choices, 2
    );
    mydialog.display();
    clearScreen();
}
void scene13_3_Does() {
    string choices[1] = {
        "( How does she know my secret? )"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Because of this you are still single.",
        img_normal,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
int scene13_4_Does() {
    string choices[3] = {
        "Your cuteness is 0.",
        "Your cuteness is maximum.",
        "Less cute than me."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Maybe my cuteness is not enough.",
        img_normal,
        choices, 3
    );
    int i = mydialog.display();
    clearScreen();
    int ChoiceScore[3] = {0,1,-1};
    PlayScore += ChoiceScore[i];
    return i;
}
int scene14_Imafraid() {
    string choices[4] = {
        "Say what.",
        "So say hello.",
        "I won't either.",
        "Good bye."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "I'm afraid I have to go now.\nBut I won't say goodbye. ",
        img_sad,
        choices, 4
    );
    int i = mydialog.display();
    clearScreen();
    int ChoiceScore[4] = {2,1,2,1};
    PlayScore += ChoiceScore[i];
    return i;
}
void scene14_2_Imafraid() {
    string choices[3] = {
        "Haha sorry","No","OK"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Quit freaking bugging me!",
        img_angry,
        choices, 3
    );
    mydialog.display();
    clearScreen();
}
void scene14_3_Imafraid() {
    string choices[1] = {
        "(......)"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "When there is an encounter, there must\nbe a goodbye.",
        img_normal,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void scene15bye() {
    string choices[1] = {
        "Bye bye."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Catch you on the flip side.",
        img_cheer,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void Meme1_1() {
    string choices[4] = {
        "Catfish.",
        "Whale.",
        "Shark.",
        "Mackerel."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "What is the biggest fish?",
        img_readbook,
        choices, 4
    );
    mydialog.display();
    clearScreen();
}
void Meme1_2() {
    string choices[2] = {
        "What is the correct answer?",
        "Unbelievable."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Not correct !!!",
        img_bigsmile,
        choices, 2
    );
    mydialog.display();
    clearScreen();
}
void Meme1_3() {
    string choices[1] = {
        "is......"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "The correct answer is ....",
        img_bigsmile,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void Meme1_4() {
    string choices[1] = {
        "is......"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "is .......",
        img_bigsmile,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void Meme1_5() {
    string choices[1] = {
        "(......)"
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "The correct answer is ParYu",
        img_cheer,
        choices, 1
    );
    mydialog.display();
    clearScreen();
}
void Meme1_6() {
    string choices[2] = {
        "Yes.",
        "No."
    };

    ChoicesSideDialog mydialog(
        " &30Katsuto&70  ",
        "Do you like it? Is the question fun? ",
        img_bigsmile,
        choices, 2
    );
    int i = mydialog.display();
    clearScreen();
    if(i == 0){
        TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "So happy.......",
        img_cheer
    );
    mydialog.display();
    clearScreen();
    }
    if(i == 1){
        TextImageDialog mydialog(
        " &30Katsuto&70  ",
        "So sad.......",
        img_cry
    );
    mydialog.display();
    clearScreen();
    }
}
