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


string visual[10][10];  // outputs the state of boardA as a UI. (adjust size of arr?)

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
string returnShipName(int);

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

inline void separateDoubleCoords(int shipSize) {   // consider inline
    int cacheNums[2];
    char cacheChars[2];

    string input;

    bool inputsValid;
    do {
        cout << "Input beginning and end coordinates of " << returnShipName(shipSize) << endl;
        getline(cin, input);
        int ln = input.length();
        cacheChars.fill('a');
        cacheNums.fill(0);
        for (int i = 0; i < ln; i++) {  // go through each letter.

            int currentFillMode = 0;    // 0, 1, 2, 3.

            bool digitIsTrue = checkTypeCurrent(input[i]);
            if (((digitIsTrue) && (input[i]%2==0)) || ((!digitIsTrue) && (input[i]%2==1))) {
                currentFillMode++;      //^ change fill mode if change type.

                if (currentFillMode>=4)
                    i = ln; // exit for loop? Max inputs received (A1E1).
            }

            switch(currentFillMode) {
                case 0:
                    cacheChars[0] += toupper(input[i]);
                    break;
                case 1:
                    cacheNums[0] += stoi(input[i]);   // append instead? supposed to work...
                    break;
                case 2:
                    cacheChars[1] += toupper(input[i]);
                    break;
                case 3:
                    cacheNums[1] += stoi(input[i]);
                    break;
                default:
                    cout << "error. Or maybe right. Exit input filling.";
            }
        }

        // Now check if inputs fit and if format valid.
        inputsValid = true;

        for (int i = 0; i < 2; i++) {
            if ((!strchr("ABCDEFGHI", cacheChars[i])) || (cacheChars[i].length!=1)) {
                inputsValid = false;
            }
            if (cacheNums[i+1] >= len) { //fix
                inputsValid = false;
            }
            // perhaps have letters correspond to number coordinates, letters only for input and visual output.
        }






    } while (!inputsValid);
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
}

inline bool checkTypeCurrent (char iChar) {
    bool digitIsTrue;
    if (isdigit(iChar)) { // is there a more efficient method? One-liner?
        digitIsTrue = true;
    } else if (isalpha(iChar)) {
        digitIsTrue = false;
    } else {
        cout << "error.";
    }
    return digitIsTrue;
}



void initArrays() { // fill() instead?
    visual.fill(" . ");
    user1out.fill(0);
    user2out.fill(0);
}

inline int lettertoCoord(char let) {
    char [allLet] = "ABCDEFGHIJKLMNO";

    int ycoord;
    switch(let) {
        case 'A':
            ycoord()


    }
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
