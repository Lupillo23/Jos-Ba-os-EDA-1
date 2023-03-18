//programaP3.c
#include <stdio.h>

void init_cboard (char *brd[8][8]);
void print_cboard (char *brd[8][8]);
void A_mov(int x, int y, char *brd[8][8]);
void T_mov(int x, int y, char *brd[8][8]);
void Q_mov(int x, int y, char *brd[8][8]);
void R_mov(int x, int y, char *brd[8][8]);
void K_mov(int x, int y, char *brd[8][8]);
void Qnt1 (int x, int y, char* brd[8][8]);
void Qnt2 (int x, int y, char* brd[8][8]);
void Qnt3 (int x, int y, char* brd[8][8]);
void Qnt4 (int x, int y, char* brd[8][8]);
void left (int x, int y, char* brd[8][8]);
void right (int x, int y, char* brd[8][8]);
void up (int x, int y, char* brd[8][8]);
void down (int x, int y, char* brd[8][8]);


int main(){
    int p = 0, x, y;
    char *brd[8][8];
    
    //Inicializa el tablero
    init_cboard(brd);
    //Imprime el tablero
    print_cboard(brd);
    
    //Menú de Opciones
    printf("\n1 Caballo \n2 Alfil \n3 Torre \n4 Reina \n5 Rey \n6 Salir \n ");
    scanf("%d", &p);

    switch(p){
        case 1://Caballo
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);
        

            //Imprime el tablero con la pieza escogida
            K_mov(x, y, brd);
            //Coordenada escogida por el usuario
            brd[x][y] = "|C|";
            //Imprime nuevamente el tablero
            print_cboard(brd);
            
            break;
            
        case 2://Alfil
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);
            
            //Posición designada por el usuario
            brd[x][y] = "|A|";
            //Imprime el tablero con la pieza escogida
            A_mov(x, y, brd);
            //Vuelve a imprimir el tablero 
            print_cboard(brd);

            break;
        case 3://Torre
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);

            //Posición designada por el usuario
            brd[x][y] = "|T|";
            //Imprime el tablero con la pieza escogida
            T_mov(x, y, brd);
            //Vuelve a imprimir el tablero 
            print_cboard(brd);

            break;
        case 4://Reina
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);

            //Imprime el tablero con la pieza escogida
            Q_mov(x, y, brd);
            //Coordenada escogida por el usuario
            brd[x][y] = "|Q|";
            //Imprime nuevamente el tablero
            print_cboard(brd);

            break;
        case 5://Rey
            printf("Coordenadas: \n");
            printf("Y: \t");
            scanf("%d",&x);
            printf("X: \t");
            scanf("%d",&y);

            //Coordenada escogida por el usuario
            brd[x][y] = "|R|";
            //Imprime el tablero con la pieza escogida
            R_mov(x, y, brd);
            //Imprime nuevamente el tablero
            print_cboard(brd);

            break;
        case 6://salir
            return 0;
            break;

        default:
            fprintf(stderr,"Opción no válida");
            break;
    }
    return 0;
}

void init_cboard (char *brd[8][8]){
    for (size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
           brd[i][j] = "| |";
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
//Movimientos del caballo
void K_mov (int x, int y, char* brd[8][8]){
    int i, j;
    int movimientos[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}; // Matriz con los posibles movimientos del caballo
    
    for (i = 0; i < 8; i++) {
        int nueva_fila = x + movimientos[i][0];
        int nueva_columna = y + movimientos[i][1];

        // Comprobar si la casilla a la que se quiere mover el caballo está dentro del tablero
        if (nueva_fila >= 0 && nueva_fila < 8 && nueva_columna >= 0 && nueva_columna < 8) {
            brd[nueva_fila][nueva_columna] = "|x|";
        }
    }
}


//Movimientos de la Reina "Q"
void Q_mov (int x, int y, char* brd[8][8]){
    Qnt1(x, y, brd);
    Qnt2(x, y, brd);
    Qnt3(x, y, brd);
    Qnt4(x, y, brd);
    left(x, y, brd);
    right(x, y, brd);
    up(x, y, brd);
    down(x, y, brd);
}

//Movimientos del Rey
void R_mov(int x, int y, char* brd[8][8]){
    //almacenan las direcciones de variable del x, y
    int *row = &x;
    int *col = &y;
    //variables de tipo apuntador que nos dan los valores de x, y
    int *a = row;
    int *b = col;
    //Variables auxiliares
    int i = x, m = x;
    int j = y, n = y;
    //Marca una casilla hacia arriba si está dentro del tablero
    if(x>0){
        brd[--i][y] = "|x|";
    }
    if(y<=7){
        //marca una casilla hacia la izquierda si está dentro del tablero
        brd[x][--j] = "|x|";
        //marca una casilla en diagonal hacia arriba y hacia la izquierda
        brd[i][j] = "|x|";
        i++;
        j++;
        brd[--m][++n] = "|x|";
    }
    if(y>0){
        brd[++i][y] = "|x|";
    }
    if(x<=7){
        brd[x][++j] = "|x|";
        brd[i][j] = "|x|";
        brd[++*a][--*b] = "|x|";
    }
}

//Movimientos del Alfil 
void A_mov (int x, int y, char* brd[8][8]){
    Qnt1(x, y, brd);
    Qnt2(x, y, brd);
    Qnt3(x, y, brd);
    Qnt4(x, y, brd);
}

//Movimientos de la torre
void T_mov(int x, int y, char* brd[8][8]){
    left(x, y, brd);
    right(x, y, brd);
    up(x, y, brd);
    down(x, y, brd);
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
    int rowQ2 = x-1;
    int colQ2 = y+1;

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

