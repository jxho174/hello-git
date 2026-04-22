#include <iostream>
using namespace std;
void drawBox(int w);
void drawFullLine(int w);
void drawEmptyLine(int w);

int main(){
    int width;
    cout << "\n Enter the side of the box (1-16): ";
    cin >> width;
    drawBox(width);
    return 0;
}

void drawBox(int w) {
    drawFullLine(w);
    for (int i = 0; i < w-2; i++) {
        drawEmptyLine(w);
    }
    drawFullLine(w);
}

void drawFullLine(int w) {
    for (int j = 0; j < w; j++) {
        cout << "* ";
    }
    cout << endl;
}

void drawEmptyLine(int w) {
    cout << "* ";
    for (int j = 1; j < w-1; j++) {
        cout << "  ";
    }
    cout << "* " << endl;
}