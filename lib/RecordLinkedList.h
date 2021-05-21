#ifndef RECORD_LINKEDLIST
#define RECORD_LINKEDLIST

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include "display.h"

using namespace std;

typedef struct PlayRecord {
    int score;
    string name;
    PlayRecord* next;
} PlayRecord;

class RecordLinkedList {
private:
    PlayRecord *head;
    int length;
public:
    RecordLinkedList() {
        head = nullptr;
        length = 0;
    };
    ~RecordLinkedList() {
        clean();
    }
    int add(PlayRecord*&);
    int add(string, int);
    void remove(int);
    void print(int);
    void clean();
    void save(string);
    void load(string);
};

int RecordLinkedList::add(PlayRecord *&newRecord) {
    int i;
    PlayRecord *now = head, *prev = nullptr;

    if (length == 0) {
        newRecord->next = head;
        head = newRecord;
    } else {
        for (i = 0; i < length; i++) {
            if (newRecord->score > now->score) break;
            prev = now;
            now = now->next;
        }
        if (!prev) {
            newRecord->next = now;
            head = newRecord;
        } else {
            prev->next = newRecord;
            newRecord->next = now;
        }
    }
    length++;
    return i;
}

int RecordLinkedList::add(string name, int score) {
    PlayRecord *pr = new PlayRecord{score, name, nullptr};
    return add(pr);
}

void RecordLinkedList::remove(int index) {
    int i;
    PlayRecord *prev, *now;
    now = head;

    if (index >= 0 && index < length) {
        if (length > 0) {
            if (index == 0) {
                head = now->next;
                delete now;
            } else {
                for (i = 0; i < index; i++) {
                    prev = now;
                    now = now->next;
                }
                prev->next = now->next;
                delete now;
            }
            length--;
        }
    } else {
        cerr<<"Out of range"<<endl;
    }
}

void RecordLinkedList::print(int j) {
    int i;
    PlayRecord *now = head;

    //cout<<"length: "<<length<<endl;

    printColor("&90Scoreboard&70", 5, 5);
    printColor("&80Name&70", 5, 8);
    printColor("&80Score&70", 25, 8);

    string c = "";
    if (length == 0) printColor( "--------------------- Empty ---------------------  " , 5, 10);
    else
    for (i = 0; i < length; i++) {

        if (i == j) c = "&20";
        else c = "";

        printColor(c + (now->name), 5, 10+i);
        printColor(c + to_string(now->score), 25, 10+i);
        now = now->next;
    }
    setxy(5, 10+i+2);
}

void RecordLinkedList::clean() {
    int i;
    PlayRecord *now = head, *temp;
    for (i = 0; i < length; i++) {
        temp = now;
        now = now->next;
        delete temp;
    }
    head = nullptr;
    length = 0;
}

void RecordLinkedList::save(string filename) {
    fstream file;
    int i = 0;
    while (i < 2) {
        try {
            file.open(filename, ios::out);
            if (!file) {
                throw 1;
            } else {
                int i;
                PlayRecord *now = head;
                for (i = 0; i < length; i++) {
                    file << now->score <<" "<< now->name<<endl;
                    now = now->next;
                }
                file.close();
                break;
            }
        } catch(int err) {
            cerr<<"Record cannot be created!"<<endl;
            cout<<" ( Press any key to try again )"<<endl; getch();
            i++;
        }
    }
    if (i > 2) exit(1);
}

void RecordLinkedList::load(string filename) {
    fstream file;
	file.open(filename, ios::in);
	int i = 0;
	while (i < 2) {
        try {
            if (!file) {
                throw 1;
            } else {
                clean();
                string a;
                int c;
                string::size_type b;
                while (getline(file, a)) {
                    c = stoi(a, &b, 10);
                    add(a.substr(b+1), c);
                }
                file.close();
            }
        }
        catch(int err) {
            save("data.txt");
            i++;
        }
	}
    if (i > 2) exit(1);
}

#endif // RECORD_LINKEDLIST
