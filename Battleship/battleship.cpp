
#include <iostream>
#include <string>
#include <vector>
#include <array>
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
    separateDoubleCoords(5);
    separateDoubleCoords(4);
    separateDoubleCoords(3);
    separateDoubleCoords(2);
    separateDoubleCoords(1);






}

inline string returnShipName(int t) {
    string name;
    switch(t) {
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

inline int shipSizeFromIntType(int t) {
    int shipSize = t;

    if (t<=2) {
        shipSize++;
    }

    return shipSize;
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

void checkIfInputsOverlap(int tempNums[2][2], bool reverseDir, bool horizontal, int shipSize, int type) {

    vector<vector<int>> vArray;



    for (int i = 0; i < shipSize; i++) {

        if (reverseDir) {
            i -= (shipSize-1);
        }

        switch (type) {
            case 5:
                if (horizontal) {
                    ship1A[0][i] = tempNums[0][0];
                    ship1A[1][i] = tempNums[1][0] + i;
                } else {
                    ship1A[0][i] = tempNums[0][0] + i;
                    ship1A[1][i] = tempNums[1][0];
                }
                break;
}

void implementTempToShipCoords(int tempNums[2][2], bool reverseDir, bool horizontal, int shipSize, int type) {

    for (int i = 0; i < shipSize; i++) {

        if (reverseDir) {
            i -= (shipSize-1);
        }

        switch (type) {
            case 5:
                if (horizontal) {
                    ship1A[0][i] = tempNums[0][0];
                    ship1A[1][i] = tempNums[1][0] + i;
                } else {
                    ship1A[0][i] = tempNums[0][0] + i;
                    ship1A[1][i] = tempNums[1][0];
                }
                break;
            case 4:
                if (horizontal) {
                    ship1B[0][i] = tempNums[0][0];
                    ship1B[1][i] = tempNums[1][0] + i;
                } else {
                    ship1B[0][i] = tempNums[0][0] + i;
                    ship1B[1][i] = tempNums[1][0];
                }
                break;
            case 3:
                if (horizontal) {
                    ship1C[0][i] = tempNums[0][0];
                    ship1C[1][i] = tempNums[1][0] + i;
                } else {
                    ship1C[0][i] = tempNums[0][0] + i;
                    ship1C[1][i] = tempNums[1][0];
                }
                break;
            case 2:
                if (horizontal) {
                    ship1D[0][i] = tempNums[0][0];
                    ship1D[1][i] = tempNums[1][0] + i;
                } else {
                    ship1D[0][i] = tempNums[0][0] + i;
                    ship1D[1][i] = tempNums[1][0];
                }
                break;
            case 1:
                if (horizontal) {
                    ship1E[0][i] = tempNums[0][0];
                    ship1E[1][i] = tempNums[1][0] + i;
                } else {
                    ship1E[0][i] = tempNums[0][0] + i;
                    ship1E[1][i] = tempNums[1][0];
                }
                break;
            default:
                cout << "error in implement coords";
        }
    }
}

void separateDoubleCoords(int type) {   // consider inline
    int tempNums[2][2]; // [i, j][point1, point2];

    int shipSize = shipSizeFromIntType(type);

    string input;

    bool inputsValid;
    do {
        cout << "\n\n\tInput beginning and end coordinates of " << returnShipName(type) << "\n\n\t";
        getline(cin, input);
        int inLen = input.length();
        fill(tempNums[0], tempNums[0] + 2 * 2, 0);
        int currentFillMode = 0; // 0, 1, 2, 3.
        for (int i = 0; i < inLen; i++)  // go through each letter.
        {

            bool digitIsTrue = isdigit(input[i]); // maybe leaves room for error when not string?
            cout << "log: digitIsTrue: " << digitIsTrue << endl;

            // below changes fill mode if change type.
            if (((digitIsTrue) && (currentFillMode%2==0)) || ((!digitIsTrue) && (currentFillMode%2==1))) {
                currentFillMode++;
                cout << "log: change fill mode, new: " << currentFillMode << endl;

                if (currentFillMode>=4)
                    i = inLen; // exit for loop? Max inputs received (A1E1).
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
        bool reverseDir = false;
        bool horizontal = false;
        if ((abs(tempNums[0][0] - shipSize) == tempNums[0][1])) {
            check5++;
            if (tempNums[0][0] > tempNums[0][1]) {
                reverseDir = true;
                // horizontal is static, vertical changes.
            }
        }
        if ((abs(tempNums[1][0] - shipSize) == tempNums[1][1])) {
            check5++;
            if (tempNums[1][0] > tempNums[1][1]) {
                reverseDir = true;
                horizontal = true; // vertical is static.
            }
        }
        if (tempNums[0][0] == tempNums[0][1])
            checkSame++;
        if (tempNums[1][0] == tempNums[1][1])
            checkSame++;

        if ((check5!=1) && (checkSame!=1)) {
            inputsValid = false;
        }



        checkIfInputsOverlap();

        if (inputsValid) {
            implementTempToShipCoords(tempNums, reverseDir, horizontal, shipSize, type);
        }


        // check to see if the new inputs are preoccupied by any other ships.
        // scan through every ship's coordinates and compare if any match.
        // if any do match, reset current ship and ask for reinput.


        system("clear");

        if (!inputsValid) {
            cout << "Inputs are invalid (format: a1e1, A1A5, c3h3, e9a9).";
        }

    } while (!inputsValid);
}





/*void initArrays() { // fill() instead?
    visual.fill(" . ");
    user1out.fill(0);
    user2out.fill(0);
}*/





struct point2d {
    int i;
    int j;
};

void printer (vector<point2d> v) {  // delete later.
    cout << "Inputted Coordinates:\n";
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].i << "   " << v[i].j << "\n";
    }
    cout << "\n" << "test";
}

inline void ui_out() {
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
