//
// Created by Julien Le ber on 23/04/2022.
//

#include "function.h"
/*test*/

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
    test(4);
    clear();
    printf("oui");
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
int test(int n){
    clear();
    /* each row should be considered as a binary code from 0 to 15 */
    /*generation of the grid */
    int grid[4][4];
    int compteur = 0;
    int nombre_1 = 0;
    int j =0;
    int array[4];
    for(int a=0;a<4;a++){
        /*Premiere iteration : pas besoin de regarder le nombre de 1 : cette ligne dicte le takuzu */
        if(a==0){
            for(int i=0;i<n;i++){
                if( i >=2){
                    if(grid[0][i-1]==grid[0][i-2]){
                        if(grid[0][i-1] == 1){
                            grid[0][i] = 0;
                        }
                        else{
                            grid[0][i] = 1;
                        }
                    }
                    else{
                        grid[0][i] = rand() %2 ;
                    }
                }
                else{
                    grid[0][i] = rand() %2 ;
                }
            }
            /*on compte le nombre de 1*/
            for(int z=0;z<n;z++){
                if(grid[0][z] == 1){
                    array[z] = 1;
                    nombre_1 +=1;

                }
            }
            if(nombre_1 !=2){
                break;
            }
            printf("\nLe nombre de 1 est %d\n", nombre_1);
        }
        /* Premiere itération passé, on doit mtn regarder le nombre de 1 a mettre*/
        else if(a==1){
            /*On sait que l'on a nombre_1 nombre de 1 : il faut donc qu'on s'assure qu'il y ait autant de 1 que dans
             * la premiere ligne*/
            //int temp = nombre_1;
            int nbr1 =0, nbr2 = 0;
            while(nbr1 == nbr2 ){
                for(int i =0;i<4;i++){
                    grid[1][i] = 0;
                }
                nbr1 = rand() %3;
                nbr2 = rand() %3;
                grid[a][nbr1]=1;
                grid[a][nbr2]=1;
                int compteur = 0;
                for(int z=0;z<n;z++){
                    if(grid[a][z] == grid[a-1][z]){
                        compteur++;
                    }
                }
                if(compteur==4){
                    nbr2 =2;
                    nbr1 = nbr2;
                    compteur= 0;
                }
                printf("nbr1 = %d , nbr2 = %d \n",nbr1,nbr2);
            }

            printf("2");
            print(grid);
        }
        else if(a>=2){
            for(int i =0;i<4;i++){
                grid[a][i] = 2;
                grid[a+1][i] = 2;
            }
            indice(n,grid);
        }
        }
    print(grid);
    if(nombre_1 !=2 ){
        test(4);
    }


    }
int indice(int n ,grid[4][4]) {
    int array[4] = {0, 0, 0, 0};
    print(grid);
    printf("--------------------\n");
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i - 2][j] == grid[i - 1][j]) {
                grid[i][j] = (grid[i - 1][j] + 1) % 2;
            }
        }
    }
    print(grid);
    int cpt = 0;
    for (int i = 0; i < 4; i++) {
        if (grid[2][i] == 1) {
            cpt += 1;
        }
    }
    if (cpt < 2) {
        while (cpt != 2) {
            int nbr1 = rand() % 4;
            if (grid[2][nbr1] == 2) {
                grid[2][nbr1] = 1;
                cpt++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (grid[2][i] == 2) {
            grid[2][i] = 0;
        }
    }
    print(grid);
    int *p = array1(grid);
    for (int i = 0; i < 4; i++) {
        printf("%d", p[i]);
    }
    for (int i = 0; i < 4; i++) {
        if (p[i] == 1) {
            grid[3][i] = 1;
        } else if (p[i] == 2) {
            grid[3][i] = 0;
        }
    }
    if(verification(grid)==0){
        test(4);
    }
    else{
        print(grid);
    }
}
void print(grid[4][4]){
    clear();
    printf("\n--------------PRINT-----------------\n");
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n--------------------------------\n");
}
int* array1(grid[4][4]){
    int array[4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j] == 1){
                array[j] += 1;
            }
        }
    }
    return array;
}
int verification(grid[4][4]) {
    int similarity = 0;
    int *p;
    int nombre[4] = {0,0,0,0};
    /*On recupere chaque ligne de notre grid, l'isole, la transforme en binaire et la stock dans l'array nombre[]
     * puis on compare tout les nombres pour savoir si les lignes sont uniques */
    for(int i=0;i<4;i++){
        int ligne[4] ={0,0,0,0};
        int* a =ligne;
        //pour les lignes :
        recup_ligne(grid,i,a);
        clear();
        printf(" \n----------Apres recup ligne----- \n");
        printf("\n %d %d %d %d",a[0],a[1],a[2],a[3]);
        nombre[i] = conversion_binaire(ligne);
        clear_ligne(a);
    }
    printf("\n---------------Verification qu'aucun nombre sont égaux \n");
    print(grid);
    for(int i=0;i<4;i++){
        printf("%d\n",nombre[i]);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(nombre[i] == nombre[j] && i!=j){
                similarity = 1;
            }
        }
    }
    if(similarity==1){
        return 0;
    }
    else{
        /*On verifie maintenant de la meme maniere si les columns sont toutes uniques*/
        printf("\nON PASSE AU COLUMNS \n");
        /*On clear l'array nombre*/
        for(int i=0;i<4;i++){
            nombre[i]= 0;
        }
        for(int i=0;i<4;i++){
            int ligne[4] ={0,0,0,0};
            int* a =ligne;
            //pour les columns :
            recup_column(grid,i,a);
            clear();
            printf(" \n----------Apres recup column number %d----- \n", i+1);
            printf("\n %d %d %d %d",a[0],a[1],a[2],a[3]);
            nombre[i] = conversion_binaire(ligne);
            printf("\nnombre binaire associé :%d",nombre[i]);
            clear_ligne(a);
        }
        /*On verifie que tout les nombres binaires sont uniques */
        print(grid);
        for(int i=0;i<4;i++){
            printf("%d\n",nombre[i]);
        }
        similarity =0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(nombre[i] == nombre[j] && i!=j){
                    similarity = 1;
                }
            }
        }
        if(similarity==1){
            test(4);
        }
        else{
            printf("\nLETS GOOOOOOO");
            return 1;
        }

    }

}
int conversion_binaire(array[]){
    int nombre=0;
    for(int i=0;i<4;i++){
        if(array[i] == 1){
            nombre += pow(2,(3-i));
        }
    }
    return nombre;
}
void recup_ligne(grid[4][4],int i,int* a){
    for(int n=0;n<4;n++){
        a[n] = grid[i][n];
    }
}
void clear_ligne(int array[4]){
    for(int i=0;i<4;i++){
        array[i] =0;
    }
}
void recup_column(grid[4][4],int i,int* a){
    for(int n=0;n<4;n++){
        a[n] = grid[n][i];
    }
}