#include<stdio.h>

void abrirSala(int[][16]);
void exibirSala(int[][16]);
int ocuparPoltrona(char, int, int[][16]);
int desocuparPoltrona(char, int, int[][16]);

int main() {
    // Sala de cinema
    int sala[8][16];
    int disponivel = 128;

    // Opções
    int opcao;
    char fileira;
    int poltrona;

    abrirSala(sala);

    while(1) {
        printf("Poltronas disponíveis: %i\n\n", disponivel);
        printf("1 - Exibir sala\n");
        printf("2 - Ocupar poltrona\n");
        printf("3 - Desocupar poltrona\n");
        printf("4 - Reabrir sala\n");
        printf("5 - Encerrar o sistema\n\n");
        printf("Digite a opção: ");
        scanf("%i", &opcao);

        if(opcao == 1) {
            exibirSala(sala);
        } else if(opcao == 2) {
            exibirSala(sala);

            printf("Digite a fileira: ");
            scanf(" %c", &fileira);
            printf("Digite a poltrona: ");
            scanf("%i", &poltrona);

            if(ocuparPoltrona(fileira, poltrona, sala) == 0) {
                printf("Poltrona ocupada com sucesso!\n");
                disponivel--;
            } else {
                printf("Não foi possível ocupar a poltrona, pois esta já se encontra ocupada.\n");
            }
        } else if(opcao == 3) {
            exibirSala(sala);

            printf("Digite a fileira: ");
            scanf(" %c", &fileira);
            printf("Digite a poltrona: ");
            scanf("%i", &poltrona);

            if(desocuparPoltrona(fileira, poltrona, sala) == 0) {
                printf("Poltrona desocupada com sucesso!\n");
                disponivel++;
            } else {
                printf("Não foi possível desocupar a poltrona, pois esta já se encontra desocupada.\n");
            }
        } else if(opcao == 4) {
            abrirSala(sala);
            disponivel = 128;
        } else {
            break;
        }
    }

    return 0;
}

void abrirSala(int p[][16]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 16; j++) {
            p[i][j] = 0;
        }
    }
}

void exibirSala(int p[][16]) {
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
            printf("  %i", p[i][j]);
        }

        printf("\n");
    }

    printf("\n   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16\n");
}

int ocuparPoltrona(char l, int c, int p[][16]) {
    int i, j;

    switch(l) {
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

    j = c - 1;

    if(p[i][j] == 0) {
        p[i][j] = 1;
        return 0;
    } else {
        return 1;
    }
}

int desocuparPoltrona(char l, int c, int p[][16]) {
    int i, j;

    switch(l) {
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

    j = c - 1;

    if(p[i][j] == 1) {
        p[i][j] = 0;
        return 0;
    } else {
        return 1;
    }
}
