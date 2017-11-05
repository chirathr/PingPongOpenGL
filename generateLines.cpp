#include <iostream>
using namespace std;

int main() {
    for (int i = -410; i < 400 + 10; i+= 40) {
        cout << "glBegin(GL_QUADS);" << endl;
        cout << "glColor3f(1.0, 1.0, 1.0);" << endl;
        cout << "glVertex2f(-2 , " << i << ");" << endl;
        cout << "glVertex2f(2 , " << i << ");" << endl;
        cout << "glVertex2f(2 , " <<  i+20 << ");" << endl;
        cout << "glVertex2f(-2 , " << i + 20 << ");" << endl;
        cout << "glEnd();" << endl << endl;
    }
    return 0;
}
