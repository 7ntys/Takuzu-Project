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
    int grad[8][8];
};



struct grille generate_grad();
void intro();
void clear();
int menu();
void sleep();
void solve_grid();
void automatic_solve();
struct grille generate_grid(int ask);
int chose_size();
int check_grid(int n);
int test(int n, int grid[4][4] );
int generate_row();
int indice(int n,int grid[4][4]);
void print(grid[4][4]);
int* array1(int grid[4][4],int* pointeur);
int verification(struct grille grid, int size);
int conversion_binaire(int* array, int size);
void recup_ligne(struct grille grid , int i, int* a, int size);
void clear_ligne(int* array, int size);
void recup_column(struct grille grid,int i ,int* a,int size);
int generate_mask(struct grille grid, struct grille* mask);
struct grille clear_grid(struct grille* grid);
int verif_mask(struct grille grid);
int clue(struct grille* grid);
void print1(struct grille grid);
int compare_grid(struct grille grid , struct grille* grille);
void print_solve(struct grille grid);
void move(struct grille grid, struct grille* mask, int* ptr_lives);
int is_mask_completed(struct grille grid,struct grille mask);
void convert(int grid[4][4], struct grille* grid1);