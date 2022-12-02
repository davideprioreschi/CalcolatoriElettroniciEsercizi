#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "problems.h"
bool check(unsigned char (*problem)[9][9]){
    //Controllo la riga
    int riga, colonna, num;
    for (num=1; num<=9; num=num+1){
        for (riga=0; riga<9; riga=riga+1){
            for (int x=0; x<9; x=x+1){
                if ((*problem)[riga][x]==num){
                    return 0;
                }
            }
        }
    }
    //Controllo la colonna
    for (num=1; num<=9; num=num+1){
        for (colonna=0; colonna<9; colonna=colonna+1){
            for (int y=0; y<9; y=y+1){
                if ((*problem)[y][colonna]==num){
                    return 0;
                }
            }
        }
    }
    //Controllo il box 3x3
    int rigaBox=riga-riga%3, colonnaBox=colonna-colonna%3;
    for (num=1; num<=9; num=num+1){
        for (riga=0; riga<3; riga=riga+1){
            for (colonna=0; colonna<3; colonna=colonna+1){
                if ((*problem)[riga+rigaBox][colonna+colonnaBox]==num){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void solve(unsigned char (*problem)[9][9])
{
    int riga, colonna, num;
    if (check==true){
        printf("OK");
    }
    else{
        printf("KO");
    }
    //ciaooo
}
