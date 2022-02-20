
#include <iostream>
#include <string>
#include <vector>
//#include <cstring>
#include <array>
//#include <math.h>
#include <cmath>
using namespace std;


string visual[9][9];  // outputs the state of boardA as a UI. (adjust size of arr?)

int ship1A[2][5];
int ship1B[2][4];
int ship1C[2][3];
int ship1D[2][2];
int ship1E[2][1];
int user1out[10][10];   // player attacks - hits and misses.

int ship2A[2][5];
int ship2B[2][4];
int ship2C[2][3];
int ship2D[2][2];
int ship2E[2][1];
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
    for (int i = 5; i > 0; i--) {
        separateDoubleCoords(i);
    }




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
    int tempNums[2][2] =  {{0,0}, {0,0}}; // [i, j][point1, point2];

    string input;

    bool inputsValid;
    do {
        cout << "\n\n\tInput beginning and end coordinates of " << returnShipName(shipSize) << "\n\n\t";
        getline(cin, input);
        int inLn = input.length();
        fill(tempNums[0], tempNums[0] + 2 * 2, 0);
        int currentFillMode = 0; // 0, 1, 2, 3.
        string errorMess = "";
        for (int i = 0; i < inLn; i++) {  // go through each letter.

            bool digitIsTrue = isdigit(input[i]); // maybe leaves room for error when not string?
            cout << "log: digitIsTrue: " << digitIsTrue << endl;

            // below changes fill mode if change type.
            if (((digitIsTrue) && (currentFillMode%2==0)) || ((!digitIsTrue) && (currentFillMode%2==1))) {
                currentFillMode++;
                cout << "log: change fill mode, new: " << currentFillMode << endl;

                if (currentFillMode>=4)
                    i = inLn; // exit for loop? Max inputs received (A1E1).
            }

            // convert letters into nums first and store in tempNums:

            switch(currentFillMode) {
                case 0:
                    if (tempNums[0][0] != 0) {
                        tempNums[0][0] = 0;
                        errorMess = "\n\tToo many letters in first letter input.";
                    } else {
                        tempNums[0][0] = letterToCoord(toupper(input[i]));
                    }
                    break;
                case 1:
                    if (tempNums[1][0] != 0) {
                        tempNums[1][0] = 0;
                        errorMess = "\n\tInapplicable first number.";
                    } else {
                        tempNums[1][0] = (input[i] - '0');
                    }
                    break;
                case 2:
                    if (tempNums[0][1] != 0) {
                        tempNums[0][1] = 0;
                        errorMess = "\n\tToo many letters in second letter input.";
                    } else {
                        tempNums[0][1] = letterToCoord(toupper(input[i]));
                    }
                    break;
                case 3:
                    if (tempNums[1][1] != 0) {
                        tempNums[1][1] = 0;
                        errorMess = "\n\tInnaplicable second number.";
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
        bool reverseDir = false;
        bool horizontalChange = false;
        if ((abs(tempNums[0][0] - shipSize) == tempNums[0][1])) {
            check5++;
            if (tempNums[0][0] > tempNums[0][1]) {
                reverseDir = true;
            }
        }
        if ((abs(tempNums[1][0] - shipSize) == tempNums[1][1])) {
            check5++;
            if (tempNums[1][0] > tempNums[1][1]) {
                reverseDir = true;
                horizontalChange = true;
            }
        }
        if (tempNums[0][0] == tempNums[0][1])
            checkSame++;
        if (tempNums[1][0] == tempNums[1][1])
            checkSame++;

        if ((check5!=1) && (checkSame!=1)) {
            inputsValid = false;
            errorMess = "\n\tInvalid coordinates";
        }



        if (inputsValid)
        {
            if (!reverseDir)
            {
                for (int i = 0; i < shipSize; i++)
                {
                    if (horizontalChange) {    // what about all the other ships?
                        ship1A[0][i] = tempNums[0][0];  // use a matrix or array of functions?
                        ship1A[1][i] = tempNums[1][0] + i;  // externally, storing all?
                    } else {
                        ship1A[0][i] = tempNums[0][0] + i;
                        ship1A[1][i] = tempNums[1][0];
                    }
                }
            } else
            {
                for (int i = shipSize-1 ; i >= 0; i--)
                {
                    if (horizontalChange) {
                        ship1A[0][i] = tempNums[0][0];
                        ship1A[1][i] = tempNums[1][0] - i;
                    } else {
                        ship1A[0][i] = tempNums[0][0] - i;
                        ship1A[1][i] = tempNums[1][0];
                    }

                }
            }
        }


        // check to see if the new inputs are preoccupied by any other ships.
        // scan through every ship's coordinates and compare if any match.
        // if any do match, reset current ship and ask for reinput.


        system("clear");

        if (!inputsValid) {
            cout << "Inputs are invalid: " << errorMess << endl;
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


// /usr/bin/clang++ -g /Users/kaiarntz/vsCodeAll_/vsCode-proj/Battleship/battleship.cpp -o /Users/kaiarntz/vsCodeAll_/vsCode-proj/Battleship/battleship
