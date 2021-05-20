#ifndef RECORD_LINKEDLIST
#define RECORD_LINKEDLIST

#include <iostream>
#include <string>
#include <fstream>

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
    void add(PlayRecord*&);
    void add(string, int);
    void remove(int);
    void print();
    void clean();
    void save(string);
    void load(string);
};

void ff(PlayRecord *a) {
    if (a) cout<<" -- "<<a->name<<" "<<a->score;
    else cout<<" -- NULL NULL";
    cout<<endl;
}

void RecordLinkedList::add(PlayRecord *&newRecord) {
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
}

void RecordLinkedList::add(string name, int score) {
    PlayRecord *pr = new PlayRecord{score, name, nullptr};
    add(pr);
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

void RecordLinkedList::print() {
    int i;
    PlayRecord *now = head;

    cout<<"length: "<<length<<endl;

    for (i = 0; i < length; i++) {
        cout<<" Name: "<<now->name<<"   Score: "<<now->score<<endl;
        now = now->next;
    }
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
	file.open(filename, ios::out);
	if (!file) {
		cerr << "Record cannot be created!";
	} else {
	    int i;
        PlayRecord *now = head;
	    for (i = 0; i < length; i++) {
            file << now->score <<" "<< now->name<<endl;
            now = now->next;
        }
		file.close();
	}
}

void RecordLinkedList::load(string filename) {
    fstream file;
	file.open(filename, ios::in);
	if (!file) {
		cerr << "Record cannot be loaded!";
	} else {
        clean();
        string a;
        int c;
        string::size_type b;
        while (getline(file, a)) {
            c = stoi(a, &b, 10);
            add(a.substr(b), c);
        }
		file.close();
	}
}

#endif // RECORD_LINKEDLIST
