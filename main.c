#include<stdio.h>

void openRoom(int[][16]);
void showRoom(int[][16]);
int occupySeat(char, int, int[][16]);
int vacateSeat(char, int, int[][16]);

int main() {
    // Room
    int room[8][16];
    int availableSeats = 128;

    // Options
    int option;
    char row;
    int seat;

    openRoom(room);

    while(1) {
        printf("Available seats: %i\n\n", availableSeats);
        printf("1 - Show room\n");
        printf("2 - Occupy seat\n");
        printf("3 - Vacate seat\n");
        printf("4 - Reopen room\n");
        printf("5 - Quit system\n\n");
        printf("Type an option: ");
        scanf("%i", &option);

        if(option == 1) {
            showRoom(room);
        } else if(option == 2) {
            showRoom(room);

            printf("Tyoe the row: ");
            scanf(" %c", &row);
            printf("Type the seat: ");
            scanf("%i", &seat);

            if(occupySeat(row, seat, room) == 0) {
                printf("Seat occupied successfully!\n");
                availableSeats--;
            } else {
                printf("It was not possible to occupy the seat, as it is already occupied.\n");
            }
        } else if(option == 3) {
            showRoom(room);

            printf("Type the row: ");
            scanf(" %c", &row);
            printf("Type the seat: ");
            scanf("%i", &seat);

            if(vacateSeat(row, seat, room) == 0) {
                printf("Seat vacated succesfully!\n");
                availableSeats++;
            } else {
                printf("It was not possible to vacate the seat, as it is already vacated.\n");
            }
        } else if(option == 4) {
            openRoom(room);
            availableSeats = 128;
        } else {
            break;
        }
    }

    return 0;
}

void openRoom(int p[][16]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 16; j++) {
            p[i][j] = 0;
        }
    }
}

void showRoom(int r[][16]) {
    for(int i = 0; i < 8; i++) {
        if(i == 0) {
            printf("A");
        } else if(i == 1) {
            printf("B");
        } else if(i == 2) {
            printf("C");
        } else if(i == 3) {
            printf("D");
        } else if(i == 4) {
            printf("E");
        } else if(i == 5) {
            printf("F");
        } else if(i == 6) {
            printf("G");
        } else {
            printf("H");
        }

        for(int j = 0; j < 16; j++) {
            printf("  %i", r[i][j]);
        }

        printf("\n");
    }

    printf("\n   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16\n\n");
}

int occupySeat(char r, int s, int p[][16]) {
    int i, j;

    switch(r) {
        case 'A':
            i = 0;
            break;
        case 'B':
            i = 1;
            break;
        case 'C':
            i = 2;
            break;
        case 'D':
            i = 3;
            break;
        case 'E':
            i = 4;
            break;
        case 'F':
            i = 5;
            break;
        case 'G':
            i = 6;
            break;
        default:
            i = 7;
    }

    j = s - 1;

    if(p[i][j] == 0) {
        p[i][j] = 1;
        return 0;
    } else {
        return 1;
    }
}

int vacateSeat(char r, int s, int p[][16]) {
    int i, j;

    switch(r) {
        case 'A':
            i = 0;
            break;
        case 'B':
            i = 1;
            break;
        case 'C':
            i = 2;
            break;
        case 'D':
            i = 3;
            break;
        case 'E':
            i = 4;
            break;
        case 'F':
            i = 5;
            break;
        case 'G':
            i = 6;
            break;
        default:
            i = 7;
    }

    j = s - 1;

    if(p[i][j] == 1) {
        p[i][j] = 0;
        return 0;
    } else {
        return 1;
    }
}
