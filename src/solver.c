#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "problems.h"
bool check_riga(unsigned char (*problem)[9][9], int riga, int num, int colonna){
    //Controlla la riga
    for (riga=0; riga<9; riga=riga+1){
            if ((*problem)[riga][colonna]==num){
                return 1;
            }
    }
    return 0;
}

bool check_colonna(unsigned char (*problem)[9][9], int colonna, int num, int riga){
    //Controlla la colonna
    for (colonna=0; colonna<9; colonna=colonna+1){
            if ((*problem)[riga][colonna]==num){
                return 1;
            }
    }
    return 0;
}

bool check_box(unsigned char (*problem)[9][9], int colonna, int num, int riga){
    //Controllo il box 3x3
    int rigaBox=riga-riga%3;
    int colonnaBox=colonna-colonna%3;
    for (num=1; num<=9; num=num+1){
        for (int i=0; i<3; i=i+1){
            for (int j=0; j<3; j=j+1){
                if ((*problem)[i+rigaBox][j+colonnaBox]==num){
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool numero_vuoto(unsigned char (*problem)[9][9],int *riga, int *colonna){
    int i;
    int j;
    for (i=0; i<9; i=i+1){
        for (j=0; j<9; j=j+1){
            if ((*problem)[i][j]==0){
                *riga=i;
                *colonna=j;
                return 1;
            }
        }
    }
    return 0;
}

int risoluzione(unsigned char (*problem)[9][9]){
        int riga;
        int colonna;
        if(!numero_vuoto(&(*problem), &riga, &colonna)){
            int num; 
            for (num=1;num<=9;num=num+1){
                if (check_riga(&(*problem),riga, num, colonna) && check_colonna(problem,colonna,num, riga) && check_box(problem,colonna,num,riga)){
                    (*problem)[riga][colonna]=num;
                    if (risoluzione(&(*problem))){
                        return 1;
                    }
                    (*problem)[riga][colonna]=0;
                }
            }
        }
        return 0;

        }

void solve(unsigned char (*problem)[9][9]){
    risoluzione(&(*problem));
}
