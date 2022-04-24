//
// Created by Julien Le ber on 23/04/2022.
//

#include "function.h"

int menu() {
    printf("Welcome to the Takuzu game created by the Aladdi team (Julien Le Ber & Mathieu Roche)"
           "\n Thank you for using this program and we hope you'll like it"
           "\n ©Aladdi-Team 2022\n");
    printf("------------------------");
    sleep(4);
    clear();

}
void clear(){
    printf("\n \n \n \n \n \n \n \n \n");
}
void sleep(int seconds) {
    /* Init. */
    time_t start_time = 0;
    time_t current_time = 0;

    /* Operate. */
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
