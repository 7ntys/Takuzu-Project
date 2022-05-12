//
// Created by Julien Le ber on 23/04/2022.
//

#ifndef TAKUZU_PROJECT_FUNCTION_H
#define TAKUZU_PROJECT_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <math.h>

#endif //TAKUZU_PROJECT_FUNCTION_H
struct grille{
    int grid[4][4];
};



void intro();
void clear();
int menu();
void sleep();
void solve_grid();
void automatic_solve();
struct grille generate_grid();
int chose_size();
int check_grid(int n);
int test(int n, int grid[4][4] );
int generate_row();
int indice(int n,grid[n][n]);
void print(grid[4][4]);
int* array1(int grid[4][4],int* pointeur);
int verification(int grid[4][4]);
int conversion_binaire(int array[4]);
void recup_ligne(int grid[4][4] , int i, int* a);
void clear_ligne(int array[4]);
void recup_column(int grid[4][4],int i ,int* a);
struct grille generate_mask();