/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string visual[16][16];
int boardA[16][16];
int boardB[16][16];

int len = 15;
int hei = 15;

void initArrays() {
    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            visual[x][y] = " . ";
            
    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            boardA[x][y] = 0;
            
    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            boardB[x][y] = 0;
            
}




struct point2d {
    int x;
    int y;
};

void printer (vector<point2d> v) {  // delete later.
    cout << "Inputted Coordinates:\n";
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i].x << "   " << v[i].y << "\n";
	}
	cout << "\n" << "test";
}

void ui_out() {
    for (int y = hei; y > 0; y--) {
        for (int x = 1; x < len; x++) {
            cout << visual[x][y];
        }
        cout << "\n";
    }
}


//void 

int main()
{
    cout << "Hello World! • " << "\n\n";
    
    initArrays();
    

    vector<point2d> af;
    vector<point2d> ah;
    vector<point2d> bf;
    vector<point2d> bh;
    //bh.push_back({2,2});
    
    //printer(af);
    
    
    ui_out();

    return 0;
}











