/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
//#include <cstring>
#include <array>
//#include <math.h>
#include <cmath>
using namespace std;


string visual[9][9];  // outputs the state of boardA as a UI. (adjust size of arr?)

int ship1A[5][2];
int ship1B[4][2];
int ship1C[3][2];
int ship1D[3][2];
int ship1E[2][2];
int user1out[10][10];   // player attacks - hits and misses.

int ship2A[5][2];
int ship2B[4][2];
int ship2C[3][2];
int ship2D[3][2];
int ship2E[2][2];
int user2out[10][10];   // enemy attacks and hits and misses.

// perhaps for all of these arrays, I could use a far more data-oriented approach,
// and have only a few of them be a 9*9 array.

int len = 9, hei = 9; //

void separateDoubleCoords(int);

void introduction()
{
    string input;
    cout << "\n\n\tBattleship 1.0\n\n\n\tPress enter to begin";
    cin.get();
    system("clear");
    separateDoubleCoords(5);
    /*if (!strchr("ABCDEFGHIJKLMNO", toupper(input[0]))) {
        ok = false;
    }
    if (isdigit(input[1]&&isdigit(input[2]))) {
        if (!strchr)
    }*/
    // https://stackoverflow.com/questions/26502432/how-can-i-separate-numbers-and-letters-in-a-c-string
}

inline string returnShipName(int s) {
    string name;
    switch(s) {
        case 5:
            name = "Aircraft Carrier";
            break;
        case 4:
            name = "Battleship";
            break;
        case 3:
            name = "Submarine";
            break;
        case 2:
            name = "Destroyer";
            break;
        case 1:
            name = "Smallboat";
            break;
        default:
            cout << "error";
    }
    return name;
}

inline int letterToCoord(char let) {
    string posit = "IHGFEDCBA";

    int ret = 0;

    for (int a = 0; a < 9; a++) {
        if (posit[a] == let) {
            ret = a+1;
            break;
        }
    }
    cout << "log: letterToCoord: " << ret << endl;
    return ret;
}

inline void separateDoubleCoords(int shipSize) {   // consider inline
    int tempNums[2][2] =  {{0,0}, {0,0}}; // [x, y][point1, point2];

    string input;

    bool inputsValid;
    do {
        cout << "\n\n\tInput beginning and end coordinates of " << returnShipName(shipSize) << "\n\n\t";
        getline(cin, input);
        int ln = input.length();
        fill(tempNums[0], tempNums[0] + 2 * 2, 0);
        int currentFillMode = 0; // 0, 1, 2, 3.
        for (int i = 0; i < ln; i++) {  // go through each letter.


            bool digitIsTrue = isdigit(input[i]); // maybe leaves room for error when not string?
            cout << "log: digitIsTrue: " << digitIsTrue << endl;

            // below changes fill mode if change type.
            if (((digitIsTrue) && (currentFillMode%2==0)) || ((!digitIsTrue) && (currentFillMode%2==1))) {
                currentFillMode++;
                cout << "log: change fill mode, new: " << currentFillMode << endl;

                if (currentFillMode>=4)
                    i = ln; // exit for loop? Max inputs received (A1E1).
            }

            // convert letters into nums first and store in tempNums:

            switch(currentFillMode) {
                case 0:
                    if (tempNums[0][0] != 0) {
                        tempNums[0][0] = 0;
                    } else {
                        tempNums[0][0] = letterToCoord(toupper(input[i]));
                    }
                    break;
                case 1:
                    if (tempNums[1][0] != 0) {
                        tempNums[1][0] = 0;
                    } else {
                        tempNums[1][0] = (input[i] - '0');
                    }
                    break;
                case 2:
                    if (tempNums[0][1] != 0) {
                        tempNums[0][1] = 0;
                    } else {
                        tempNums[0][1] = letterToCoord(toupper(input[i]));
                    }
                    break;
                case 3:
                    if (tempNums[1][1] != 0) {
                        tempNums[1][1] = 0;
                    } else {
                        tempNums[1][1] = (input[i] - '0');
                    }
                    break;
                default:
                    cout << "error. Or maybe right. Exit input filling.\n";
            }
        }

        cout << "log: " << tempNums[0][0] << " " << tempNums[1][0] <<  " " << tempNums[0][1] << " " << tempNums[1][1] << endl;


        // Done with looping every char, Now check if inputs fit and if format valid.
        inputsValid = true;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if ((tempNums[i][j] > 9) || (tempNums[i][j] == 0)) {
                    inputsValid = false;
                }
            }
        }

        int check5 = 0;
        int checkSame = 0;
        if ((abs(tempNums[0][0] - 5) == tempNums[0][1]))
            check5++;
        if ((abs(tempNums[1][0] - 5) == tempNums[1][1]))
            check5++;
        if (tempNums[0][0] == tempNums[0][1])
            checkSame++;
        if (tempNums[1][0] == tempNums[1][1])
            checkSame++;

        if ((check5!=1) && (checkSame!=1))
            inputsValid = false;



        if (!inputsValid) {
            cout << "inputs are invalid.\n";
        }

    } while (!inputsValid);
}





/*void initArrays() { // fill() instead?
    visual.fill(" . ");
    user1out.fill(0);
    user2out.fill(0);
}*/





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

    //initArrays


    vector<point2d> af;
    vector<point2d> ah;
    vector<point2d> bf;
    vector<point2d> bh;
    //bh.push_back({2,2});

    //printer(af);


    ui_out();

    return 0;
}
