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
    sleep(1);
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
    struct grille grid ;
    struct grille* mask ;
    mask = (struct grille*) malloc(sizeof(struct grille));
    int result=0;
    do{
        grid = generate_grid();
        clear();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%d",grid.grid[i][j]);
            }
            printf("\n");
        }
        result =generate_mask(grid , mask);
    }
    while(result ==0);

}
void automatic_solve(){
    clear();
}
struct grille generate_grid(){
    int size = chose_size();
    int grid[4][4];
    while(test(size,grid) == 0){
        test(size,grid);
    }
    struct grille test;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            test.grid[i][j] = grid[i][j];
        }
    }
    printf("oui");
    return test;
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
int test(int n, int grid[4][4]){
    /* each row should be considered as a binary code from 0 to 15 */
    /*generation of the grid */
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
            }
        }
        else if(a>=2){
            for(int i =0;i<4;i++){
                grid[a][i] = 2;
                grid[a+1][i] = 2;
            }
            indice(n,grid);
            if(verification(grid)==0){
                return 0;
            }
            else{
                printf("\nLa grille est valide ");
                return 1;

            }

        }
        }
    print(grid);
    if(nombre_1 !=2 ){
        test(4 , grid);
    }


    }
int indice(int n ,int grid[4][4]) {
    int array[4] = {0, 0, 0, 0};
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i - 2][j] == grid[i - 1][j]) {
                grid[i][j] = (grid[i - 1][j] + 1) % 2;
            }
        }
    }
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
    int* vertical;
    int array_empty[4] = {0,0,0,0};
    vertical = array_empty;
    vertical = array1(grid,vertical);
    for(int i = 0;i<4;i++){
        if(vertical[i] == 1){
            grid[3][i] = 1;
        }
        else if(vertical[i]== 2 && grid[3][1] !=1){
            grid[3][i] = 0;
        }
    }
    for(int x=0;x<4;x++){
        if( grid[3][x] == 2){
            grid[3][x] =0;
        }
    }
    print(grid);
}
void print(int grid[4][4]){
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
int* array1(int grid[4][4],int* pointeur){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j] == 1) {
                pointeur[j] += 1;
            }
            else{
                pointeur[j] += 0;
            }

        }
    }

    return pointeur;
}
int verification(int grid[4][4]) {
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
        nombre[i] = conversion_binaire(ligne);
        clear_ligne(a);
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
        /*On clear l'array nombre*/
        for(int i=0;i<4;i++){
            nombre[i]= 0;
        }
        for(int i=0;i<4;i++){
            int ligne[4] ={0,0,0,0};
            int* a =ligne;
            //pour les columns :
            recup_column(grid,i,a);
            nombre[i] = conversion_binaire(ligne);
            clear_ligne(a);
        }
        /*On verifie que tout les nombres binaires sont uniques */
        similarity =0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(nombre[i] == nombre[j] && i!=j){
                    similarity = 1;
                }
            }
        }
        if(similarity==1){
            test(4,grid);
        }
        else{
            return 1;
        }

    }

}
int conversion_binaire(int array[]){
    int nombre=0;
    for(int i=0;i<4;i++){
        if(array[i] == 1){
            nombre += pow(2,(3-i));
        }
    }
    return nombre;
}
void recup_ligne(int grid[4][4],int i,int* a){
    for(int n=0;n<4;n++){
        a[n] = grid[i][n];
    }
}
void clear_ligne(int array[4]){
    for(int i=0;i<4;i++){
        array[i] =0;
    }
}
void recup_column(int grid[4][4],int i,int* a){
    for(int n=0;n<4;n++){
        a[n] = grid[n][i];
    }
}
int generate_mask(struct grille grid, struct grille* mask){
    printf("\nca rentre\n");
    clear_grid(mask);
    printf("ici");
    int compteur=0;
    /* On genere un masque avec 8 indices */
    while(compteur <=7){
        int index_x = rand() % 4;
        int index_y = rand() % 4;
        if((mask->grid[index_x][index_y] != 1) && (mask->grid[index_x][index_y] != 0)){
            mask->grid[index_x][index_y] = grid.grid[index_x][index_y];
            compteur +=1;
        }
    }
    /* print du mask */
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mask->grid[i][j] == 2){
                printf(" .");
            }
            else{
                printf(" %d",mask->grid[i][j]);
            }
        }
        printf("\n");
    }
    /* verif mask */
    int a =verif_mask(*mask);
    printf("apres");
    return a;
    }
struct grille clear_grid(struct grille* grid){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid->grid[i][j] = 2;
        }
    }
}
int verif_mask(struct grille grid){
    int result =0,result2= 0;
    struct grille* ptr;
    ptr = &grid;
    printf("\n%d\n", ptr->grid[0][0]);
    while (result == 0) {
        print1(*ptr);
        sleep(1);
        result = clue(ptr);
    }
    printf("\n---------\n");
    result2 = compare_grid(grid, ptr);
    return result2;
}
int clue(struct grille* grid){
    int cpt_c=0;
    int cpt_c0=0;
    int compteur=0;
    int compteur0=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid->grid[i][j] == 1){
                compteur +=1;
            }
            if(grid->grid[i][j] == 0){
                compteur0 +=1;
            }
            if((grid->grid[i][j] == grid->grid[i][j+1]) && (j<2) && (grid->grid[i][j] != 2) && (grid->grid[i][j+2] == 2) ) {
                grid->grid[i][j+2] = (grid->grid[i][j] +1) %2;
                printf("11");
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i][j-1]) && (j>2) && (grid->grid[i][j] != 2)&& (grid->grid[i][j-2] == 2) ) {
                grid->grid[i][j-2] = (grid->grid[i][j] +1) %2;
                printf("12");
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i+1][j]) && (i<2) && (grid->grid[i][j] != 2) && (grid->grid[i+2][j] == 2)){
                grid->grid[i+2][j] = (grid->grid[i][j] +1)% 2;
                printf("13");
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i-1][j]) && (i>2) && (grid->grid[i][j] != 2)&& (grid->grid[i-2][j] == 2) ){
                grid->grid[i-2][j] = (grid->grid[i][j] +1)% 2;
                printf("14");
                return 0;
            }
        }
        if(compteur == 2){
            for(int j=0;j<4;j++){
                if(grid->grid[i][j] == 2){
                    grid->grid[i][j] = 0;
                    return 0;
                }
            }
        }
        if(compteur0 == 2){
            for(int j=0;j<4;j++){
                if(grid->grid[i][j] == 2){
                    grid->grid[i][j] = 1;
                    return 0;
                }
            }
        }
        compteur=0;
        compteur0=0;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid->grid[j][i] == 1){
                cpt_c +=1;
            }
            if(grid->grid[j][i] == 0){
                cpt_c0 +=1;
            }
        }
        if(cpt_c == 2){
            for(int j=0;j<4;j++){
                if(grid->grid[j][i] == 2){
                    grid->grid[j][i] = 0;
                    return 0;
                }
            }
        }
        if(cpt_c0 == 2){
            for(int j=0;j<4;j++){
                if(grid->grid[j][i] == 2){
                    grid->grid[j][i] = 1;
                    return 0;
                }
            }
        }
        cpt_c=0;
        cpt_c0=0;
    }
    printf("j'ai fini");
    return 1;
}
void print1(struct grille grid){
    clear();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid.grid[i][j] == 2){
                printf(" .");
            }
            else{
                printf(" %d", grid.grid[i][j]);
            }
        }
        printf("\n");
    }
}
int compare_grid(struct grille grid , struct grille* grille){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid.grid[i][j] != grille->grid[i][j]){
                return 0;
            }
        }
    }
    return 1;

}