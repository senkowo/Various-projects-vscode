#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>
using namespace std;

/*
 *  For snake, make 3d array with 2 pairs to store coordinates, make into an 
 *  arraylist(?) or long simple list, find length of 3d array and paste in 
 *  block for all those coordinates. 
 *  
 *  sleep(1);
 *
 *
 */


void constMove();
void keyReaction(char in);
void arrayDeclare();
void shiftSnake();
void addingSnakeToArray();
void arrayPrint();
void appleSpawn();
void checkForInteraction();

char in;

bool programRunning = true;

int currentDirH = 1;
int currentDirV = 0;
char currentChar = 'd';

int totalPoints = 0;    // same as length of snake and snakeCoords [z];

int length = 22;
int height = 22;
string matrix[22][22];  // [x][y]; couldn't just plug in height and length because not declared at run time(?)
string matrixOrig[42][42];
int snakeCoords[2][161] = {{10},{10}};   // [x,y][z];
int appleX;
int appleY;

int main()
{
    // below was stolen from "https://replit.com/talk/share/Terminal-Snake-Game-made-with-just-C/52115"
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    // basically allows for the scanning of input without pressing enter.
    
    srand(time(0));
    appleSpawn();
    
    arrayDeclare();
    copy(&matrix[0][0], &matrix[0][0]+length*height, &matrixOrig[0][0]);
    
    thread th1(constMove);
    
    while (programRunning) {    // receives input for keypresses. 
        in = getchar();
        keyReaction(in);
    }
    th1.join();
    return 0;
}


void constMove() 
{
    while (programRunning) {
        keyReaction(currentChar);
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}


// reacts to keypresses. 
// the current direction is set by changing currentDirH (horizontal) and currentDirV (vertical).
// matrix[][] gets a copy of matrixOrig[][], so the previous snake image won't remain when pasting the new one.
// shiftSnake() shifts the snake body in whichever direction that is defined by currentDirH and currentDirV.
// arrayPrint() prints the full array.
void keyReaction(char in) {
    switch (in) {
        case 'w':
            currentDirH = 0;
            currentDirV = 1;
            currentChar = 'w';
            copy(&matrixOrig[0][0], &matrixOrig[0][0]+length*height, &matrix[0][0]);
            shiftSnake();
            checkForInteraction();
            arrayPrint();
            break;
        case 'a':
            currentDirH = -1;
            currentDirV = 0;
            currentChar = 'a';
            copy(&matrixOrig[0][0], &matrixOrig[0][0]+length*height, &matrix[0][0]);
            shiftSnake();
            checkForInteraction();
            arrayPrint();
            break;
        case 's':
            currentDirH = 0;
            currentDirV = -1;
            currentChar = 's';
            copy(&matrixOrig[0][0], &matrixOrig[0][0]+length*height, &matrix[0][0]);
            shiftSnake();
            checkForInteraction();
            arrayPrint();
            break;
        case 'd':
            currentDirH = 1;
            currentDirV = 0;
            currentChar = 'd';
            copy(&matrixOrig[0][0], &matrixOrig[0][0]+length*height, &matrix[0][0]);
            shiftSnake();
            checkForInteraction();
            arrayPrint();
            break;
        default:
            cout << "incorrect input";
    }
}

// initializes the matrix.
void arrayDeclare() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < length; x++) {
            matrix[x][y] = " . ";
        }
        cout << "\n";
    }
}

// shifts the snake one unit forward by setting all coordinates to its next upper part
// (except the very front). The very front coordinates are changed according to 
// currentDirH and currentDirV, which bascially states the current direction. 
// If the snake is moving left, currentDirH (horizontal) is set to -1, and currentDirV 
// (vertical) is set to 0. 
void shiftSnake() {
    for (int z = totalPoints+1; z >= 1; z--) {
        snakeCoords[0][z] = snakeCoords[0][z-1];
        snakeCoords[1][z] = snakeCoords[1][z-1];
    }
    snakeCoords[0][0] = snakeCoords[0][0] + currentDirH;
    snakeCoords[1][0] = snakeCoords[1][0] + currentDirV;
}

// If eat apple, adds a new coordinate to the end of the snakeCoords list based on totalPoints. 
void addBlockToSnake() {
    snakeCoords[0][totalPoints+1] = snakeCoords[0][totalPoints] - currentDirH;
    snakeCoords[1][totalPoints+1] = snakeCoords[1][totalPoints] - currentDirV;
    totalPoints++;
}

// prints " O " on all coordinates found in snakeCoords onto matrix, so basically pastes the
// snake onto the playing field.
void printSnakeOnArray() {
    int x;
    int y;
    for (int z = 0; z < totalPoints; z++) {
        x = snakeCoords[0][z];
        y = snakeCoords[1][z];
        matrix[x][y] = " O ";
    }
    matrix[appleX][appleY] = " A ";
}

// prints the full matrix. 
// this function also includes the call for "printSnakeOnArray()", which pastes the snake body
    // onto the matrix before printing. 
void arrayPrint() {
    
    printSnakeOnArray();    // integrate with this function? Might be better not to if I'm adding 
                        // block to the front of snake. On a similar note, make addBlockToSnake
                        // attached to a thread, so separate and instantaneous? 
    system("clear");
    for (int y = height-1; y > 0; y--) {
        for (int x = 1; x < length; x++) {
            cout << matrix[x][y];
        }
        cout << "\n";
    }
    //sleep(1);
    // below is for debugging:
    //cout << "snakeCoords: " << snakeCoords[0][0] << " " << snakeCoords[1][0] << "\n";
    //cout << "appleCoords: " << appleX << " " << appleY;
}

// set random spawn location for apple and increase totalPoints.
void appleSpawn() {
    appleX = (1+rand() % (length-2)) + 1;
    appleY = (1+rand() % (length-2)) + 1;
    totalPoints++;
}

void checkForInteraction() {
    // if snake head touch edge, end game.
    if (snakeCoords[0][0]==0 || snakeCoords[0][0]==length || snakeCoords[1][0]==0 || snakeCoords[1][0]==height) {
        programRunning = false;
    }
    // if snake head touch itself, end game.
    for (int z = 1; z < totalPoints; z++) {
        if ((snakeCoords[0][0]==snakeCoords[0][z]) && (snakeCoords[1][0]==snakeCoords[1][z])) {
            programRunning = false;
        }
    }
    
    // if snake head touch apple, run "appleSpawn()";
    if ((snakeCoords[0][0]==appleX) && (snakeCoords[1][0]==appleY)) {
        appleSpawn();
    }
    
}



















