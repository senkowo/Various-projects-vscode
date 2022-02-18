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
#include <array>
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
    cout << "\n\nEnter beggining and end coordinates for 'Battleship'\n";
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
    char all[] = "IHGFEDCBA";

    int a;
    for (a = 1; a <= all.length(); a++) {
        if (all[a] == let) {
            break;
        }
    }
    return a;
}

inline void separateDoubleCoords(int shipSize) {   // consider inline
    int tempNums[2][2] =  {{0,0}, {0,0}}; // [x, y][point1, point2];

    string input;

    bool inputsValid;
    do {
        cout << "Input beginning and end coordinates of " << returnShipName(shipSize) << endl;
        getline(cin, input);
        int ln = input.length();
        //memset(tempNums,0,sizeof(tempNums));
        fill(tempNums[0], tempNums[0] + 2 * 2, 0);
        for (int i = 0; i < ln; i++) {  // go through each letter.

            int currentFillMode = 0;    // 0, 1, 2, 3.

            bool digitIsTrue = isdigit(input[i]); //checkTypeCurrent(input[i]);
            // ^^^ maybe leaves room for error when not string?
            cout << "log: digitIsTrue" << digitIsTrue << endl;

            if (((digitIsTrue) && (currentFillMode%2==0)) || ((!digitIsTrue) && (currentFillMode%2==1))) {
                currentFillMode++;      //^ change fill mode if change type.

                if (currentFillMode>=4)
                    i = ln; // exit for loop? Max inputs received (A1E1).
            }

            // convert letters into nums first and store in tempNums:

            switch(currentFillMode) {
                case 0:
                    tempNums[0][0] += letterToCoord(toupper(input[i]));
                    break;
                case 1:
                    tempNums[1][0] += stoi(input[i]);   // append instead? supposed to work...
                    break;
                case 2:
                    tempNums[0][1] += letterToCoord(toupper(input[i]));
                    break;
                case 3:
                    tempNums[1][1] += stoi(input[i]);   // [y, x] instead? since reversed y and then x?
                    break;
                default:
                    cout << "error. Or maybe right. Exit input filling.";
            }
        }

        // Done with looping every char, Now check if inputs fit and if format valid.
        inputsValid = true;

        for (int i = 0; i < 2; i++) {
            if ((!strchr("ABCDEFGHI", cacheChars[i])) || (cacheChars[i].length!=1)) {
                inputsValid = false;
            }
            if (cacheNums[i+1] > len) { //fix
                inputsValid = false;
            }

            int numLet[2];  // wont work.
            numLet[i] = letterToChord(cacheChars[i]);
            // instead, convert letter to number up top, for simplicity?
            // will I need to write on a new doc? too extreme maybe?


            // perhaps have letters correspond to number coordinates, letters only for input and visual output.
        }






    } while (!inputsValid);
}





void initArrays() { // fill() instead?
    visual.fill(" . ");
    user1out.fill(0);
    user2out.fill(0);
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
