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
           "4 : For our way to generate a 8x8 grid\n"
    );
    scanf("%d",&answer);
    while(answer < 1 || answer > 4){
        clear();
        printf("Error you entered a wrong integer\n"
               "Chose the game mode you'll like to play by entering the integer corresponding\n"
               "1 : Solve a grid \n"
               "2 : Solve automatically a grid \n"
               "3 : Generate a Grid\n"
               "4 : For our way to generate a 8x8 grid\n"
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
    else if(answer == 4) {
        struct grille grad1;
        grad1 = real_grid(0);
        printf("\n----------8X8----------\n");
        for (int c = 0; c < 8; c++) {
            for (int e = 0; e < 8; e++) {
                printf("%d ", grad1.grad[c][e]);
            }
            printf("\n");
        }
    }
    else{
        printf("%d",answer);
        struct grille temp;
        temp = generate_grid(0);
        printf("\n----------8X8----------\n");
        for (int c = 0; c < 8; c++) {
            for (int e = 0; e < 8; e++) {
                printf("%d ", temp.grad[c][e]);
            }
            printf("\n");
        }
        clear();
        menu();
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
    int size= chose_size();
    mask = (struct grille*) malloc(size* sizeof(struct grille));
    int result=0;
    if(size==1){
        while(result ==0) {
            size=4;
            grid = generate_grid(4);
            result = generate_mask(grid, mask,size);
        }
    }
    else{
        size=8;
        grid = maxence();
        result = generate_mask2(grid,mask,size);
    }
    int lives =3;
    int* ptr_lives = &lives;
    while(is_mask_completed(grid , *mask) == 0 && lives >0){
        printf("\nYou have %d lives\n", lives);
        print_solve(*mask, size);
        move(grid , mask ,ptr_lives,size);
    }
    if(lives >0){
        print1(*mask);
        printf("Congrats ! you just solve a Takuzu grid !!!");
        printf("\n");
        sleep(5);
        menu();
    }
    else{
        printf("Youu looooseeee , get better by continue playing\n");
        printf("The right grid was :\n");
        print1(grid);
        printf("\n");
        sleep(5);
        menu();
    }
}
void automatic_solve(){
    int verif =0;
    struct grille grid;
    struct grille mask;
    int size = chose_size();
    if(size==1){
        size=4;
        while(verif ==0){
            clear();
            grid = generate_grid(4);
            verif = generate_mask(grid,&mask, size);
            if(verif==1) {


                clear();
                printf("The computer has this mask : \n");
                print1(mask);
                printf("He has to resolve it\n");
                printf("\n");
                sleep(1);
                float temp_exec;
                clock_t t1, t2;
                clear();
                t1 = clock();
                int steps = 0;
                while (clue(&mask, size) == 0) {
                    steps++;
                    clear();
                    printf("Number of steps : %d\n", steps);
                    print1(mask);
                    printf("\n");
                    //sleep(2);
                }
                t2 = clock();
                temp_exec = (float) ((t2 - t1) - (steps * 2)) / CLOCKS_PER_SEC;
                printf("Le programme a résolu la grille en %f seconde \n", temp_exec);
                sleep(3);
                printf(" \n");
                menu();
            }
            else{

            }
        }
    }
    else{
        size =8;
        while(verif ==0) {
            clear();
            grid = real_grid(1);
            verif = generate_mask2(grid, &mask, size);
            clear();
            printf("The computer has this mask : \n");
            print2(mask);
            printf("He has to resolve it\n");
            printf("\n");
            sleep(3);
            float temp_exec;
            clock_t t1,t2;
            clear();
            t1 = clock();
            int steps =0;
            while(clue2(&mask,size) == 0){
                steps ++;
                clear();
                printf("Number of steps : %d\n", steps);
                print2(mask);
                printf("\n");
                //sleep(2);
            }
            t2 = clock();
            temp_exec = (float)((t2-t1)-(steps*2))/CLOCKS_PER_SEC;
            printf("Le programme a résolu la grille en %f seconde \n",temp_exec);
            sleep(3);
            printf(" \n");
            menu();
        }
    }


}
struct grille generate_grid(int ask){
    if (ask == 0) {
        int size= chose_size();
        if (size == 1) {
            int grid[4][4];
            while (test(size, grid) == 0) {
                test(size, grid);
            }
            struct grille test;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    test.grid[i][j] = grid[i][j];
                }
            }
            print(test);
            return test;
        }
        else if (size == 2) {
            struct grille grad1 = real_grid(1);
            //struct grille grid1;
            printf("\n----------8X8----------\n");
            for (int c = 0; c < 8; c++) {
                for (int e = 0; e < 8; e++) {
                    printf("%d ", grad1.grad[c][e]);
                }
                printf("\n");
            }
            sleep(5);
            return grad1;

        }
    }
    else if(ask == 4){
        int grid[4][4];
        while (test(4, grid) == 0) {
            test(4, grid);
        }
        struct grille test;
        convert(grid,&test);
        print(test);
        return test;
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
int test(int n, int grid[4][4]){
    /* each row should be considered as a binary code from 0 to 15 */
    /*generation of the grid */
    int nombre_1 = 0;
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
            struct grille grid1;
            convert(grid,&grid1);
            if(verification(grid1,4)==0){
                test(4,grid);
            }
            else{
                printf("\n");

                return 1;

            }

        }
    }
    //print(grid);
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
    //print(grid);
}
void print(struct grille grid){
    clear();
    printf("\n--------------PRINT-----------------\n");
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d",grid.grid[i][j]);
        }
        printf("\n");
    }
    printf("\n--------------------------------\n");
}
struct grille real_grid(int n){
    int rep = 1;
    int validity = 0;
    int borne1 = 0;
    int borne2 = 8;
    struct grille grad1;
    while (validity != 1) {
        if (n == 0) {
            grad1 = generate_grad();
            borne1 = 2;
            borne2 = 4;
        }
        if (n == 1) {
            grad1 = maxence();
        }
        validity = 1;
        if(n==0) {
            for (int x = 0; x < 8; x++) {
                for (int y = borne1; y < borne2; y++) {
                    if ((grad1.grad[x][y] == grad1.grad[x][y + 1]) && (grad1.grad[x][y] == grad1.grad[x][y + 2]) &&
                        (validity == 1)) {
                        validity = 0;
                    }
                }
            }
        }
        for (int x = borne1;x < borne2;x++) {
            for (int y = 0; y < 8; y++) {
                if ((grad1.grad[x][y] == grad1.grad[x + 1][y]) && (grad1.grad[x][y] == grad1.grad[x + 2][y]) && (validity == 1)) {
                    validity = 0;
                }
            }
        }
        if (n==1) {
            if ((compteur_column(grad1) == 0) && (validity == 1)) {
                //printf("rep %d",rep);
                validity = 0;
            }
        }
        if(n!=1){
            if((verification2(grad1,8) == 0)&&(validity==1) ){
                sleep(1);
                validity=0;
            }
        }
        rep++;
    }
    printf("Le nombre de tour de boucle est de %d",rep);
    return grad1;

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
int verification(struct grille grid, int size) {
    int similarity = 0;
    int *p;
    size=4;
    int* nombre = (int *)malloc(size*(sizeof (int)));
    /*On recupere chaque ligne de notre grid, l'isole, la transforme en binaire et la stock dans l'array nombre[]
     * puis on compare tout les nombres pour savoir si les lignes sont uniques */
    for(int i=0;i<size;i++){
        int* ligne = (int *)malloc(size*(sizeof (int)));
        int* a =ligne;
        //pour les lignes :
        recup_ligne(grid,i,a,size);
        nombre[i] = conversion_binaire(ligne,size);
        clear_ligne(a,size);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
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
        for(int i=0;i<size;i++){
            nombre[i]= 0;
        }
        for(int i=0;i<size;i++){
            int* ligne = (int *)malloc(size*(sizeof (int)));
            int* a =ligne;
            //pour les columns :
            recup_column(grid,i,a,size);
            nombre[i] = conversion_binaire(ligne,size);
            clear_ligne(a,size);
        }
        /*On verifie que tout les nombres binaires sont uniques */
        similarity =0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(nombre[i] == nombre[j] && i!=j){
                    similarity = 1;
                }
            }
        }
        if(similarity==1){
            return 0;
        }
        else{
            return 1;
        }

    }

}
int verification2(struct grille grid, int size) {
    int similarity = 0;
    int *p;
    int* nombre = (int *)malloc(size*(sizeof (int)));
    /*On recupere chaque ligne de notre grid, l'isole, la transforme en binaire et la stock dans l'array nombre[]
     * puis on compare tout les nombres pour savoir si les lignes sont uniques */
    for(int i=0;i<size;i++){
        int* ligne = (int *)malloc(size*(sizeof (int)));
        int* a =ligne;
        //pour les lignes :
        recup_ligne(grid,i,a,size);
        nombre[i] = conversion_binaire(ligne,size);
        clear_ligne(a,size);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if ((nombre[i] == nombre[j]) && (i!=j)){
                similarity =1;
            }
        }
    }
    print2(grid);
    if(similarity==1){
        return 0;
    }
    else{
        /*On verifie maintenant de la meme maniere si les columns sont toutes uniques*/
        /*On clear l'array nombre*/
        for(int i=0;i<size;i++){
            nombre[i]= 0;
        }
        for(int i=0;i<size;i++){
            int* ligne = (int *)malloc(size*(sizeof (int)));
            int* a =ligne;
            //pour les columns :
            recup_column(grid,i,a,size);
            nombre[i] = conversion_binaire(ligne,size);
            clear_ligne(a,size);
        }
        /*On verifie que tout les nombres binaires sont uniques */
        similarity =0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(nombre[i] == nombre[j] && i!=j){
                    similarity = 1;
                }
            }

        }
        if(similarity==1){
            return 0;
        }
        else{
            return 1;
        }

    }

}
int conversion_binaire(int* array , int size){
    int nombre=0;
    int p;
    if(size==8){
        p=7;
    }
    else{
        p=3;
    }
    for(int i=0;i<size;i++){
        if(array[i] == 1){
            nombre += pow(2,((p)-i));
        }
    }
    return nombre;
}
void recup_ligne(struct grille grid,int i,int* a , int size){
    if(size==4){
        for(int n=0;n<size;n++){
            a[n] = grid.grid[i][n];
        }
    }
    else{
        for(int n=0;n<size;n++){
            a[n] = grid.grad[i][n];
        }
    }
}
void clear_ligne(int* array , int size){
    for(int i=0;i<size;i++){
        array[i] =0;
    }
}
void recup_column(struct grille grid,int i,int* a, int size){
    if(size==4){
        for(int n=0;n<size;n++){
            a[n] = grid.grid[n][i];
        }
    }
    else{
        for(int n=0;n<size;n++){
            a[n] = grid.grad[n][i];
        }
    }
}
int generate_mask(struct grille grid, struct grille* mask,int size){
    clear_grid(mask);
    int compteur=0;
    /* On genere un masque avec x indices */
    int x = 6;
    x += (rand()%((size*2)-4));
    while(compteur <=x){
        int index_x = rand() % size;
        int index_y = rand() % size;
        if((mask->grid[index_x][index_y] != 1) && (mask->grid[index_x][index_y] != 0)){
            mask->grid[index_x][index_y] = grid.grid[index_x][index_y];
            compteur +=1;
        }
    }
    /* print du mask */
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
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
    int a =verif_mask(*mask,size);
    printf("on print a :%d", a);
    return a;
}
int generate_mask2(struct grille grid, struct grille* mask,int size){
    clear_grid2(mask);
    size=8;
    int compteur=0;
    /* On genere un masque avec x indices */
    int x = 8;
    x += rand()%((size*2) -4);
    while(compteur <=x){
        int index_x = rand() % size;
        int index_y = rand() % size;
        if((mask->grad[index_x][index_y] != 1) && (mask->grad[index_x][index_y] != 0)){
            mask->grad[index_x][index_y] = grid.grad[index_x][index_y];
            compteur +=1;
        }
    }
    /* print du mask */
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(mask->grad[i][j] == 2){
                printf(" .");
            }
            else{
                printf(" %d",mask->grad[i][j]);
            }
        }
        printf("\n");
    }
    /* verif mask */
    //int a =verif_mask2(*mask,size);
    //printf("on print a :%d", a);
    int a=1;
    return a;
}
struct grille clear_grid(struct grille* grid){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid->grid[i][j] = 2;
        }
    }
}
struct grille clear_grid2(struct grille* grid){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            grid->grad[i][j] = 2;
        }
    }
}
int verif_mask(struct grille grid,int size){
    int result =0,result2= 0;
    struct grille* ptr = (struct grille*)malloc(sizeof (struct grille));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ptr->grid[i][j] = grid.grid[i][j];
        }
    }
    ptr = &grid;
    while (result == 0) {
        print1(*ptr);
        //sleep(1);
        result = clue(ptr,size);
    }
    result2 = compare_grid(grid, ptr);
    return result2;
}
int verif_mask2(struct grille grid,int size){
    int result =0,result2= 0;
    struct grille* ptr;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ptr->grad[i][j] = grid.grad[i][j];
        }
    }
    ptr = &grid;
    while (result == 0) {
        print1(*ptr);
        sleep(1);
        result = clue2(ptr,size);
    }
    result2 = compare_grid2(grid, ptr);
    return result2;
}
int clue(struct grille* grid,int size){
    int cpt_c=0;
    int cpt_c0=0;
    int compteur=0;
    int compteur0=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(grid->grid[i][j] == 1){
                compteur +=1;
            }
            if(grid->grid[i][j] == 0){
                compteur0 +=1;
            }
            if((grid->grid[i][j] == grid->grid[i][j+1]) && (j<2) && (grid->grid[i][j] != 2) && (grid->grid[i][j+2] == 2) ) {
                grid->grid[i][j+2] = (grid->grid[i][j] +1) %2;
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i][j-1]) && (j>2) && (grid->grid[i][j] != 2)&& (grid->grid[i][j-2] == 2) ) {
                grid->grid[i][j-2] = (grid->grid[i][j] +1) %2;
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i+1][j]) && (i<2) && (grid->grid[i][j] != 2) && (grid->grid[i+2][j] == 2)){
                grid->grid[i+2][j] = (grid->grid[i][j] +1)% 2;
                return 0;
            }
            if((grid->grid[i][j] == grid->grid[i-1][j]) && (i>2) && (grid->grid[i][j] != 2)&& (grid->grid[i-2][j] == 2) ){
                grid->grid[i-2][j] = (grid->grid[i][j] +1)% 2;
                return 0;
            }
        }
        if(compteur == (size/2)){
            for(int j=0;j<size;j++){
                if(grid->grid[i][j] == 2){
                    grid->grid[i][j] = 0;
                    return 0;
                }
            }
        }
        if(compteur0 == (size/2)){
            for(int j=0;j<size;j++){
                if(grid->grid[i][j] == 2){
                    grid->grid[i][j] = 1;
                    return 0;
                }
            }
        }
        compteur=0;
        compteur0=0;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(grid->grid[j][i] == 1){
                cpt_c +=1;
            }
            if(grid->grid[j][i] == 0){
                cpt_c0 +=1;
            }
        }
        if(cpt_c == (size/2)){
            for(int j=0;j<size;j++){
                if(grid->grid[j][i] == 2){
                    grid->grid[j][i] = 0;
                    return 0;
                }
            }
        }
        if(cpt_c0 == (size/2)){
            for(int j=0;j<size;j++){
                if(grid->grid[j][i] == 2){
                    grid->grid[j][i] = 1;
                    return 0;
                }
            }
        }
        cpt_c=0;
        cpt_c0=0;
    }
    return 1;
}
int clue2(struct grille* grid,int size){
    int cpt_c=0;
    int cpt_c0=0;
    int compteur=0;
    int compteur0=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(grid->grad[i][j] == 1){
                compteur +=1;
            }
            if(grid->grad[i][j] == 0){
                compteur0 +=1;
            }
            if((grid->grad[i][j] == grid->grad[i][j+1]) && (j<6) && (grid->grad[i][j] != 2) && (grid->grad[i][j+2] == 2) ) {
                grid->grad[i][j+2] = (grid->grad[i][j] +1) %2;
                return 0;
            }
            if((grid->grad[i+1][j] == grid->grad[i-1][j]) && (i<=6)&&(i>=1)  && (grid->grad[i][j] == 2) ) {
                grid->grad[i][j] = (grid->grad[i][j] +1) %2;
                return 0;
            }
            if((grid->grad[i][j+1] == grid->grad[i][j-1]) && (j<=6)&&(j>=1)   && (grid->grad[i][j] == 2) ) {
                grid->grad[i][j] = (grid->grad[i][j] +1) %2;
                return 0;
            }
            if((grid->grad[i][j] == grid->grad[i][j-1]) && (j>2) && (grid->grad[i][j] != 2)&& (grid->grad[i][j-2] == 2) ) {
                grid->grad[i][j-2] = (grid->grad[i][j] +1) %2;
                return 0;
            }
            if((grid->grad[i][j] == grid->grad[i+1][j]) && (i<6) && (grid->grad[i][j] != 2) && (grid->grad[i+2][j] == 2)){
                grid->grad[i+2][j] = (grid->grad[i][j] +1)% 2;
                return 0;
            }
            if((grid->grad[i][j] == grid->grad[i-1][j]) && (i>2) && (grid->grad[i][j] != 2)&& (grid->grad[i-2][j] == 2) ){
                grid->grad[i-2][j] = (grid->grad[i][j] +1)% 2;
                return 0;
            }
        }
        if(compteur == (4)){
            for(int j=0;j<size;j++){
                if(grid->grad[i][j] == 2){
                    grid->grad[i][j] = 0;
                    return 0;
                }
            }
        }
        if(compteur0 == 4){
            for(int j=0;j<size;j++){
                if(grid->grad[i][j] == 2){
                    grid->grad[i][j] = 1;
                    return 0;
                }
            }
        }
        compteur=0;
        compteur0=0;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(grid->grad[j][i] == 1){
                cpt_c +=1;
            }
            if(grid->grad[j][i] == 0){
                cpt_c0 +=1;
            }
        }
        if(cpt_c == 4){
            for(int j=0;j<size;j++){
                if(grid->grad[j][i] == 2){
                    grid->grad[j][i] = 0;
                    return 0;
                }
            }
        }
        if(cpt_c0 == 4){
            for(int j=0;j<size;j++){
                if(grid->grad[j][i] == 2){
                    grid->grad[j][i] = 1;
                    return 0;
                }
            }
        }
        cpt_c=0;
        cpt_c0=0;
    }
    return 1;
}
void print1(struct grille grid){
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
void print2(struct grille grid){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(grid.grad[i][j] == 2){
                printf(" .");
            }
            else{
                printf(" %d", grid.grad[i][j]);
            }
        }
        printf("\n");
    }
}
void print_solve(struct grille grid,int size){
    if (size==4){
        clear();
        printf("Solve this grid\n");
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
    else{
        clear();
        printf("Solve this grid\n");
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(grid.grad[i][j] == 2){
                    printf(" .");
                }
                else{
                    printf(" %d", grid.grad[i][j]);
                }
            }
            printf("\n");
        }
    }
}
int compare_grid(struct grille grid , struct grille* grille){
    print1(grid);
    print1(*grille);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grille->grid[i][j] == 2){

                return 0;
            }
        }
    }
    return 1;
}
int compare_grid2(struct grille grid , struct grille* grille){
    print1(grid);
    print1(*grille);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(grille->grad[i][j] == 2){
                return 0;
            }
        }
    }
    return 1;
}
void move(struct grille grid , struct grille* mask, int* ptr_lives,int size){
    if(size==4) {
        int c = -1;
        printf("Do you want a clue ? (1:Yes, 0:No ");
        do {
            scanf("%d", &c);
        } while (c > 1 || c < 0);
        if (c == 1) {
            clue(mask, size);
        } else {
            int x = -1;
            printf("Enter the x row you want to complete \n x= ");
            do {
                scanf("%d", &x);
            } while (x > 4 || x < 1);
            x--;
            int y = -1;
            printf("Enter the y column you want to complete \n y= ");
            do {
                scanf("%d", &y);
            } while (y > 4 || y < 1);
            y--;
            if (mask->grid[x][y] != 2) {
                printf("This case is already assigned\n value = %d", mask->grid[x][y]);
                sleep(1);
            } else {
                int value = -1;
                printf("Enter the value (0;1) \n value= ");
                do {
                    scanf("%d", &value);
                } while (value > 1 || value < 0);

                printf("Checking if it is the right move\n");
                if (grid.grid[x][y] == value) {
                    printf("It is the right move\n");
                    mask->grid[x][y] = value;
                    sleep(1);
                } else {
                    printf("This is not the correct move\n");
                    (*ptr_lives)--;
                    printf("You have %d lives\n", *ptr_lives);
                    sleep(1);
                }
            }
        }
    }
    else{
        int c = -1;
        printf("Do you want a clue ? (1:Yes, 0:No ");
        do {
            scanf("%d", &c);
        } while (c > 1 || c < 0);
        if (c == 1) {
            clue(mask, size);
        }
        else{


        int x =-1;
        printf("Enter the x row you want to complete \n x= ");
        do {
            scanf("%d" ,&x);
        }
        while(x>8 || x<1);
        x--;
        int y =-1;
        printf("Enter the y column you want to complete \n y= ");
        do {
            scanf("%d",&y);
        }
        while(y>8 || y<1);
        y--;
        if(mask->grad[x][y] != 2){
            printf("This case is already assigned\n value = %d", mask->grad[x][y]);
            sleep(1);
        }
        else {
            int value = -1;
            printf("Enter the value (0;1) \n value= ");
            do {
                scanf("%d", &value);
            } while (value > 1 || value < 0);

            printf("Checking if it is the right move\n");
            if (grid.grad[x][y] == value) {
                printf("It is the right move\n");
                mask->grad[x][y] = value;
                sleep(1);
            } else {
                printf("This is not the correct move\n");
                (*ptr_lives)--;
                printf("You have %d lives\n", *ptr_lives);
                sleep(1);
            }}
        }
    }
}
int is_mask_completed(struct grille grid,struct grille mask){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid.grid[i][j] != mask.grid[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void convert(int grid[4][4], struct grille* grid1){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid1->grid[i][j] = grid[i][j];
        }
    }
}
struct grille generate_grad(){
    struct grille grid1;
    struct grille grid2;
    struct grille grid3;
    struct grille grid4;
    struct grille grad1;
    int validity = 1;
    grid1 = generate_grid(4);
    grid2 = generate_grid(4);
    grid3 = generate_grid(4);
    grid4 = generate_grid(4);
    for (int x = 0;x < 8;x++){
        for (int y = 0;y < 8;y++) {
            if (x >= 0 && x <= 3 && y >= 0 && y <= 3) {
                grad1.grad[x][y] = grid1.grid[x][y];
            }
            else if (x >= 0 && x <= 3 && y >= 4 && y <= 7) {
                grad1.grad[x][y] = grid2.grid[x][y-4];
            }
            else if (x >= 4 && x <= 7 && y >= 0 && y <= 3) {
                grad1.grad[x][y] = grid3.grid[x-4][y];
            }
            else if (x >= 4 && x <= 7 && y >= 4 && y <= 7) {
                grad1.grad[x][y] = grid4.grid[x-4][y-4];
            }
        }



    }
    //-validité
    //-validité

    return grad1;



};
struct grille maxence() {
    struct grille grad1;
    int line[34][8] =
            {{0, 0, 1, 1, 0, 0, 1, 1},
             {0, 1, 1, 0, 1, 1, 0, 0},
             {1, 1, 0, 0, 1, 0, 1, 0},
             {1, 0, 0, 1, 0, 0, 1, 1},
             {0, 0, 1, 1, 0, 1, 0, 1},
             {1, 1, 0, 0, 1, 1, 0, 0},
             {1, 0, 1, 0, 1, 0, 1, 0},
             {0, 1, 0, 1, 0, 0, 1, 1},
             {0, 0, 1, 1, 0, 1, 1, 0},
             {0, 1, 0, 1, 0, 1, 1, 0},
             {1, 0, 0, 1, 1, 0, 0, 1},
             {1, 0, 1, 0, 0, 1, 1, 0},
             {1, 0, 0, 1, 0, 1, 0, 1},
             {0, 1, 1, 0, 1, 0, 1, 0},
             {0, 1, 1, 0, 1, 0, 1, 0},
             {0, 1, 0, 1, 1, 0, 0, 1},
             {0, 1, 1, 0, 1, 0, 0, 1},
             {0, 1, 1, 0, 1, 0, 0, 1},
             {0, 1, 0, 1, 0, 1, 0, 1},
             {1, 0, 0, 1, 0, 1, 1, 0},
             {1, 0, 1, 0, 1, 1, 0, 0},
             {1, 0, 1, 0, 0, 1, 0, 1},
             {1, 0, 1, 1, 0, 1, 0, 0},
             {0, 0, 1, 0, 1, 1, 0, 1},
             {0, 1, 0, 0, 1, 1, 0, 1},
             {1, 1, 0, 1, 0, 0, 1, 0},
             {1, 0, 1, 1, 0, 0, 1, 0},
             {0, 1, 0, 0, 1, 0, 1, 1},
             {1, 1, 0, 1, 0, 1, 0, 0},
             {0, 1, 1, 0, 0, 1, 0, 1},
             {1, 0, 0, 1, 1, 0, 1, 0},
             {1, 0, 1, 0, 1, 0, 0, 1},
             {0, 0, 1, 0, 1, 0, 1, 1},
             {0, 1, 1, 0, 0, 1, 1, 0}
            };
    int random[8];
    int ok = 0;
    while (ok != 1) {
        ok = 1;
        for (int i = 0; i < 8; i++) {
            random[i] = rand() % 33;
        }
        for (int w = 0; w < 8; w++) {
            for (int x = 0; x < 8; x++) {
                if (random[w] == random[x] && (x != w)) {
                    ok = 0;


                }
            }
        }
    }

    for (int c = 0; c < 8; c++) {
        for (int e = 0; e < 8; e++) {
            grad1.grad[c][e] = line[random[c]][e];
        }
    }
    return grad1;
}
int compteur_column(struct grille grid){
    int un = 0;
    int a = 0;
    for (int i = 0;i<8;i++) {
        for (int e = 0; e < 8; e++) {
            un += grid.grad[e][i];
        }
        if (un != 4) {
            a = 1;
            un = 0;
            break;
        }
        else {
            un = 0;
        }
    }

    if (a == 1){
        return 0;
    }
    else {
        return 1;
    }

}