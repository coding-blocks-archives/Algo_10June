// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

class Pen {
public:
    char name[10];
    char color[10];
    Pen(const char n[], const char c[]) {
        strcpy(name, n);    // name = n;
        strcpy(color, c);   // color = c;
    }
    void write(char words[]) {
        cout << name << " is writing " << words << " with " << color << endl;
    }
};


int main() {
    // char p1_name[] = "parker";
    // char p1_color[] = "red";
    // char words[] = "Apple is green but I like red.";
    // write(p1_name, p1_color, words);

    // char car_name[] = "rolls royce";
    // write(car_name, p1_color, words);

    Pen P("parker", "black");
    char words[] = "Apple is green but I like red.";
    P.write(words);

    // char car_name[] = "rolls royce";
    // write(car_name, p1_color, words);



}