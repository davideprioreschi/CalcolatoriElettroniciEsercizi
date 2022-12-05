#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
void solve(unsigned char (*problem)[9][9]);
bool risoluzione(unsigned char (*problem)[9][9]);
bool check_riga(unsigned char (*problem)[9][9], int num, int riga);
bool check_colonna(unsigned char (*problem)[9][9], int num, int colonna);
bool check_box(unsigned char (*problem)[9][9], int num, int colonna, int riga);
bool numero_vuoto(unsigned char (*problem)[9][9],int *riga, int *colonna);

bool check_riga(unsigned char (*problem)[9][9], int num, int riga){
    //Controlla la riga
    for (int colonna=0; colonna<9; colonna=colonna+1){
            if ((*problem)[riga][colonna]==num){
                return 1;
            }
    }
    return 0;
}

bool check_colonna(unsigned char (*problem)[9][9], int num,int colonna){
    //Controlla la colonna
    for (int riga=0; riga<9; riga=riga+1){
            if ((*problem)[riga][colonna]==num){
                return 1;
            }
    }
    return 0;
}

bool check_box(unsigned char (*problem)[9][9], int num, int colonna, int riga){
    //Controllo il box 3x3
    int rigaBox=riga-riga%3;
    int colonnaBox=colonna-colonna%3;
    for (int i=0; i<3; i=i+1){
            for (int j=0; j<3; j=j+1){
                if ((*problem)[i+rigaBox][j+colonnaBox]==num){
                    return 1;
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

bool risoluzione(unsigned char (*problem)[9][9]){
        int riga;
        int colonna;
        
        if(numero_vuoto(&(*problem), &riga, &colonna)){
            for(int num=1;num<=9;num=num+1){
                if (!check_riga(&(*problem),num, riga) && !check_colonna(&(*problem),num, colonna) && !check_box(&(*problem), num, colonna,riga)){
                    //printf("%d,%d \n", riga, colonna);
                    (*problem)[riga][colonna]=num;
                    //printf("%d \n",(*problem)[riga][colonna]=num);
                    if (risoluzione(&(*problem))){
                        return 1;
                    }else{
                        (*problem)[riga][colonna]=0;
                        //printf("%d \n",(*problem)[riga][colonna]=num);
                    }
                }
            }
        }
        return 0;

}
