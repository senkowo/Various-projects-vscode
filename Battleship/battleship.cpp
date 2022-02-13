/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


string visual[16][16];  // outputs the state of boardA as a UI. (adjust size of arr?)

int ship1A[5][2];
int ship1B[4][2];
int ship1C[3][2];
int ship1D[3][2];
int ship1E[2][2];
int user1out[16][16];   // player attacks - hits and misses.

int ship2A[5][2];
int ship2B[4][2];
int ship2C[3][2];
int ship2D[3][2];
int ship2E[2][2];
int user2out[16][16];   // enemy attacks and hits and misses.

// perhaps for all of these arrays, I could use a far more data-oriented approach,
// and have only a few of them be a 16x16 array.

int len = 16, hei = 16; // 0-15, (1-15).


void introduction()
{
    string input;
    cout << "\n\n\tBattleship 1.0\n\n\n\tPress enter to begin";
    cin.get();
    system("clear");
    cout << "Enter beggining and end coordinates for 'Battleship'\n";
    while(true) {
        getline(cin, input);
        bool ok = true;
        /*if (!strchr("ABCDEFGHIJKLMNO", toupper(input[0]))) {
            ok = false;
        }
        if (isdigit(input[1])&&isdigit(input[2])) {
            if (!strch)
        } else {

        }*/
        // split string instead! into list.
        cout << ok;
    }
}

void initArrays() {
    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            visual[x][y] = " . ";

    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            user1out[x][y] = 0;

    for (int y = 1; y < hei; y++)
        for (int x = 1; x < len; x++)
            user2out[x][y] = 0;

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

int main()
{
    introduction();

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


