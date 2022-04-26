//
// Created by Julien Le ber on 23/04/2022.
//

#include "function.h"

void intro() {
    clear();
    printf("Welcome to the Takuzu game created by the Aladdi team (Julien Le Ber & Mathieu Roche)"
           "\n Thank you for using this program and we hope you'll like it"
           "\n                 ©Aladdi-Team 2022\n");
    printf("-------------------------------------------------------------------------------------");
    sleep(4);
    clear();
}
int menu(){
    int answer;
    printf("Chose the game mode you'll like to play by entering the integer corresponding\n"
           "1 : Solve a grid \n"
           "2 : Solve automatically a grid \n"
           "3 : Generate a Grid\n"
            );
    scanf("%d",&answer);
    while(answer < 1 || answer > 3){
        clear();
        printf("Error you entered a wrong integer\n"
               "Chose the game mode you'll like to play by entering the integer corresponding\n"
               "1 : Solve a grid \n"
               "2 : Solve automatically a grid \n"
               "3 : Generate a Grid\n"
        );
        scanf("%d",&answer);
    }


    if(answer==1){
        printf("%d",answer);
        solve_grid();
    }
    else if(answer==2){
        printf("%d",answer);
        automatic_solve();
    }
    else{
        printf("%d",answer);
        generate_grid();
    }


}
void clear(){
    printf("\n \n \n \n \n \n \n \n \n");
}
void sleep(int seconds) {
    /* Initialize */
    time_t start_time = 0;
    time_t current_time = 0;

    /* Pause the program for x seconds */
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
void solve_grid(){
    clear();
}
void automatic_solve(){
    clear();
}
void generate_grid(){
    int size = chose_size();
    printf("%d",rand() % 2);
    if(size==1){
        clear();
        /* each row should be considered as a binary code from 0 to 15 */
        /*generation of the grid */
        int grid[4][4];
        int compteur = 0;
        int j =0;
        int somme;
        do {
            for(int i=0;i<4;i++){


                if (j==1){
                    for(int a = 0; a < 4;a++){
                        somme += grid[j][a];
                        int temp = somme;
                        while (temp != 0){
                            if( i >=2){
                                if(grid[j][i-1]==grid[j][i-2]){
                                    if(grid[j][i-1] == 1){
                                        grid[j][i] = 0;
                                    }
                                    else{
                                        grid[j][i] = 1;
                                        temp--;
                                    }
                                }
                            }
                            else{
                                grid[j][i] = rand() %2 ;
                                if (grid[j][i] == 1){
                                    temp--;

                                }
                            }

                            printf("%d " , grid[j][i]);
                            printf("%d",temp);

                        }

                    }

                }
                if( i >=2){
                    if(grid[j][i-1]==grid[j][i-2]){
                        if(grid[j][i-1] == 1){
                            grid[j][i] = 0;
                        }
                        else{
                            grid[j][i] = 1;
                        }
                    }
                }
                else{
                    grid[j][i] = rand() %2 ;
                }

                printf("%d " , grid[j][i]);


            }
            printf("\n");
            compteur +=1;

            j++;


        }
        while(compteur != 10);


    }
    else{
        printf("8x8 grid");
    }
}
int chose_size(){
    int answer;
    clear();
    printf("Enter the size of the takuzu grid you want \n"
           "1 : 4x4 grid \n"
           "2 : 8x8 grid \n");
    scanf("%d",&answer);
    while(answer<1 || answer >2){
        clear();
        printf("Error the integer doesn't correspond to a choice\n "
               "Enter the size of the takuzu grid you want \n"
               "1 : 4x4 grid \n"
               "2 : 8x8 grid \n");
        scanf("%d",&answer);
    }
    return answer;
}
