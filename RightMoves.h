#ifndef RIGHTMOVES_H
#define RIGHTMOVES_H

#include<iostream>
#include<queue>

using namespace std;

class RightMoves {
public:
    int arrX[6] = { 0,0,0,0,0,0 };
    int arrY[6] = { 0,0,0,0,0,0 };
    int* arrXoriginal;
    int* arrYoriginal;
    int numberMoves = 1;
    int deletedElements = 0;

    void PointerArray(int* arrXoriginal, int* arrYoriginal) {
        this->arrXoriginal = arrXoriginal;
        this->arrYoriginal = arrYoriginal;
    }

    int SizeMultipleOf8(queue<int>& runX) {
        return runX.size() + deletedElements - 1;
    }

    void Way_ok(int dx[], int dy[], queue<int>& runX) {

        int V = SizeMultipleOf8(runX);

        for (int i = 0; i < numberMoves; i++) {
            if (V % 8 == 0) {
                arrX[numberMoves - 1 - i] = dx[7];
                arrY[numberMoves - 1 - i] = dy[7];
                V = (V - 8) / 8;
            }
            else {
                arrX[numberMoves - 1 - i] = dx[(V % 8) - 1];
                arrY[numberMoves - 1 - i] = dy[(V % 8) - 1];
                V = (V - (V % 8)) / 8;
            }

        }

        for (int i = 0; i < 6; i++) {
            cout << arrX[i] << " " << arrY[i] << endl;
        }
        cout << endl;

    }

    bool IsOk(int nx, int ny) {
        for (int i = 0; i < numberMoves; i++) {
            nx += arrX[i];
            ny += arrY[i];
            if (nx < 0 || nx > 7) return false;
            if (ny < 0 || ny > 7) return false;
        }
        for (int i = 0; i < 6; i++) {
            arrXoriginal[i] = arrX[i];
            arrYoriginal[i] = arrY[i];
        }


        return true;
    }



};
#endif // RIGHTMOVES_H
