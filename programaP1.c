#include <stdio.h>

void init_cboard (char *brd[8][8]);
void print_cboard (char *brd[8][8]);
void A_mov (int x, int y, char* brd[8][8]);
void Qnt1 (int x, int y, char* brd[8][8]);
void Qnt2 (int x, int y, char* brd[8][8]);
void Qnt3 (int x, int y, char* brd[8][8]);
void Qnt4 (int x, int y, char* brd[8][8]);
void T_mov (int x, int y, char* brd[8][8]);
void left (int x, int y, char* brd[8][8]);
void right (int x, int y, char* brd[8][8]);
void up (int x, int y, char* brd[8][8]);
void down (int x, int y, char* brd[8][8]);


int main(){
    int p = 0, x, y;
    char *brd[8][8];
    
    init_cboard(brd);
    print_cboard(brd);
    
    printf("\n1 Alfil \n2 Torre \n3 Salir \n ");
    scanf("%d", &p);

    switch(p){
        case 1:
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);
        

            //Imprime el tablero con la pieza escogida
            A_mov(x, y, brd);
            brd[x][y] = "|A|";
            print_cboard(brd);
            
            break;
            
        case 2:
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);
            
            //Posición designada por el usuario
            brd[x][y] = "|T|";
            //Imprime el tablero con la pieza escogida
            T_mov(x, y, brd);
            print_cboard(brd);
            
            break;
            
        case 3:
            return -1;
            
        default:
            fprintf(stderr,"Opción no válida");
    }
    return 0;
}

void init_cboard (char *brd[8][8]){
    for (size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
           brd[i][j] = "|-|";
        }
    }
}

void print_cboard (char *brd[8][8]){
    for (size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
           printf(" %s ",brd[i][j]);
        }
        printf("\n");
    }
}
//Movimientos del Alfil Inicio
void A_mov (int x, int y, char* brd[8][8]){
    Qnt1(x, y, brd);
    Qnt2(x, y, brd);
    Qnt3(x, y, brd);
    Qnt4(x, y, brd);
}

void Qnt1 (int x, int y, char* brd[8][8]){
    int rowQ1 = x-1;
    int colQ1 = y-1;
    while(rowQ1 >= 0 && colQ1 >= 0){
        brd[rowQ1][colQ1] = "|x|";
        rowQ1--;
        colQ1--;
    }
}

void Qnt2 (int x, int y, char* brd[8][8]){//
    int rowQ2 = x+1;
    int colQ2 = y-1;

    while(rowQ2 >= 0 && colQ2 <= 7){
        brd[rowQ2][colQ2] = "|x|";
        rowQ2--;
        colQ2++;
    }
}

void Qnt3 (int x, int y, char* brd[8][8]){
    int rowQ3 = x+1;
    int colQ3 = y-1;

    while(rowQ3 <= 7 && colQ3 >= 0){
        brd[rowQ3][colQ3] = "|x|";
        rowQ3++;
        colQ3--;
    }
}

void Qnt4 (int x, int y, char* brd[8][8]){
    int rowQ4 = x+1;
    int colQ4 = y+1;

    while(rowQ4 <= 7 && colQ4 <= 7){
        brd[rowQ4][colQ4] = "|x|";
        rowQ4++;
        colQ4++;
    }
}
//Fin

//Movimientos de la torre
void T_mov(int x, int y, char* brd[8][8]){
    left(x, y, brd);
    right(x, y, brd);
    up(x, y, brd);
    down(x, y, brd);
}

void left (int x, int y, char* brd[8][8]){
    int left_col = y-1;

    while(left_col >= 0){
        brd[x][left_col] = "|x|";
        left_col --;
    }
}

void right (int x, int y, char* brd[8][8]){
    int right_col = y+1;

    while(right_col <= 7){
        brd[x][right_col] = "|x|";
        right_col ++;
    }
}

void up (int x, int y, char* brd[8][8]){
    int up_row = x-1;

    while(up_row >= 0){
        brd[up_row][y] = "|x|";
        up_row --;
    }
}

void down (int x, int y, char* brd[8][8]){
    int down_row = x+1;

    while(down_row <= 7){
        brd[down_row][y] = "|x|";
        down_row ++;
    }
}

//Fin
