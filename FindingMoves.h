#ifndef FINDINGMOVES_H
#define FINDINGMOVES_H

#include <iostream>
#include <queue>
#include <cmath>
#include <QString>

#include"RightMoves.h"

using namespace std;
//using namespace System;

class FindingMoves {
public:

    int nx, ny, mx, my;
    int dx[8] = { -2, -2, -1, -1,  1,  1,  2,  2 };
    int dy[8] = { -1,  1, -2,  2, -2,  2, -1,  1 };

    bool overlap(int mx, int my, int nx, int ny) {
        if (mx < 0 || mx > 7) return false;
        if (my < 0 || my > 7) return false;
        if (nx < 0 || nx > 7) return false;
        if (ny < 0 || ny > 7) return false;
        return mx == nx && my == ny;
    }


    int knight(QString pos1, QString pos2, int* arrXoriginal, int* arrYoriginal) {

        RightMoves rightMoves;
        rightMoves.PointerArray(arrXoriginal, arrYoriginal);

        queue<int> runX;
        queue<int> runY;

        nx = pos1[0].unicode() - 97;
        ny = pos1[1].unicode() - 49;
        mx = pos2[0].unicode() - 97;
        my = pos2[1].unicode() - 49;

        runX.push(nx);
        runY.push(ny);


        for (int i = 0; i < 8; i++) {

            runX.push(runX.front() + dx[i]);
            runY.push(runY.front() + dy[i]);
            if (overlap(runX.back(), runY.back(), mx, my)) {
                rightMoves.Way_ok(dx, dy, runX);

                if (rightMoves.IsOk(nx, ny)) {
                    break;
                }
            }
            if (i == 7) {
                runX.pop();
                runY.pop();
                rightMoves.deletedElements++;
                if (pow(8, rightMoves.numberMoves) <= runX.size()) { ++rightMoves.numberMoves; }
                i = -1;
            }
        }

        return  rightMoves.numberMoves;
    }
};

#endif // FINDINGMOVES_H


