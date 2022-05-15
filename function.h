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

struct combo{
    int grid[19][8];
};

int compteur_column(struct grille grid);
struct grille generate_grad();
struct grille clear_grid2(struct grille* grid);
int verif_mask2(struct grille grid,int size);
int clue2(struct grille* grid,int size);
int compare_grid2(struct grille grid , struct grille* grille);
void print2(struct grille grid);
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
void print(struct grille grid);
int* array1(int grid[4][4],int* pointeur);
int verification(struct grille grid, int size);
int conversion_binaire(int* array, int size);
void recup_ligne(struct grille grid , int i, int* a, int size);
void clear_ligne(int* array, int size);
void recup_column(struct grille grid,int i ,int* a,int size);
int generate_mask(struct grille grid, struct grille* mask,int size);
int generate_mask2(struct grille grid, struct grille* mask,int size);
struct grille clear_grid(struct grille* grid);
int verif_mask(struct grille grid,int size);
int clue(struct grille* grid,int size);
void print1(struct grille grid);
int compare_grid(struct grille grid , struct grille* grille);
void print_solve(struct grille grid,int size);
void move(struct grille grid, struct grille* mask, int* ptr_lives,int size);
int is_mask_completed(struct grille grid,struct grille mask);
void convert(int grid[4][4], struct grille* grid1);
int verification2(struct grille grid, int size);
struct grille real_grid(int n);
struct grille maxence();