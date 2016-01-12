//
//  Creato da Cesare de Cal
//  Esercizio in C sulle matrici: vettori multi-dimensionali
//

#include <stdio.h>

int acquisisciNumeroCompresoTraValori(int inserimentoMinimoConsentito, int inserimentoMassimoConsentito) {
    int inserimento;
    scanf("%d", &inserimento);
    while ((inserimento < inserimentoMinimoConsentito) || (inserimento > inserimentoMassimoConsentito)) {
        printf("'%d' non e' un inserimento valido. Inserisci un valore compreso tra %d e %d: ", inserimento, inserimentoMinimoConsentito, inserimentoMassimoConsentito);
        scanf("%d", &inserimento);
    }
    return inserimento;
}

void azzeramentoElementiMatrice(int matrice[][100], int numeroColonne, int numeroRighe) {
    int a, z;
    for (a = 0; a < numeroRighe; a++) {
        for (z = 0; z < numeroColonne; z++) {
            matrice[a][z] = 0;
        }
    }
    puts("Gli elementi della matrice sono stati azzerati.");
}

void inserimentoDaTastieraElementiMatrice(int matrice[][100], int numeroColonne, int numeroRighe) {
    int a, z;
    for (a = 0; a < numeroRighe; a++) {
        for (z = 0; z < numeroColonne; z++) {
            printf("Inserisci un numero da assegnare alla posizione (%d, %d): ", a, z);
            scanf("%d", &matrice[a][z]);
        }
    }
}

void visualizzaValoriElementiMatrice(int matrice[][100], int numeroColonne, int numeroRighe) {
    int a, z;
    for (a = 0; a < numeroRighe; a++) {
        for (z = 0; z < numeroColonne; z++) {
            printf("%d ", matrice[a][z]);
        }
        printf("\n");
    }
}

void inserimentoDiUnSoloDatoDataRigaColonnaMatrice(int matrice[][100], int numeroColonne, int numeroRighe) {
    printf("Inserisci il numero della colonna dell'elemento da sostituire: ");
    int numeroColonnaElemento = acquisisciNumeroCompresoTraValori(0, numeroColonne);
    printf("Inserisci il numero della riga dell'elemento da sostituire: ");
    int numeroRigaElemento = acquisisciNumeroCompresoTraValori(0, numeroRighe);
    printf("Nelle coordinate (%d, %d) si trova l'elemento %d. Inserisci il numero con cui vuoi sostituirlo: ", numeroColonnaElemento, numeroRigaElemento, matrice[numeroColonnaElemento][numeroRigaElemento]);
    int elementoDaSostituire;
    scanf("%d", &elementoDaSostituire);
    matrice[numeroColonnaElemento][numeroRigaElemento] = elementoDaSostituire;
    printf("Ho inserito %d alla posizione (%d, %d).\n", matrice[numeroColonnaElemento][numeroRigaElemento], numeroColonnaElemento, numeroRigaElemento);
}

void bubbleSort(int vettore[], int numeroRiga, int numeroColonne) {
    int tmp, i = 0;
    for (i = 0; i < numeroColonne-1; i++) {
        if (vettore[i] > vettore[i+1]) {
            tmp = vettore[i];
            vettore[i] = vettore[i+1];
            vettore[i+1] = tmp;
        }
    }
}

void ordinamentoElementiRigaMatriceDatoIndice(int matrice[][100], int numeroColonne, int numeroRighe) {
    printf("Inserisci l'indice della riga di cui vuoi ordinare gli elementi: ");
    int numeroRiga = acquisisciNumeroCompresoTraValori(0, numeroRighe);
    bubbleSort(matrice[numeroRiga], numeroRiga, numeroColonne);
    printf("Ho ordinato gli elementi della %da riga.\n", numeroRiga+1);
}


void invertiRigheColonneMatrice(int ***numeroColonne, int ***numeroRighe) {
    int temp = ***numeroColonne;
    ***numeroColonne = ***numeroRighe;
    ***numeroRighe = temp;
}

void traspostaElementiMatrice(int matrice[][100], int **numeroColonne, int **numeroRighe) {
    int matriceTrasposta[100][100], r, c;
    
    for (r = 0; r < **numeroRighe; r++) {
        for (c = 0; c < **numeroColonne; c++) {
            matriceTrasposta[c][r] = matrice[r][c];
        }
    }
    invertiRigheColonneMatrice(&numeroColonne, &numeroRighe);
    
    for (r = 0; r < **numeroRighe; r++) {
        for (c = 0; c < **numeroColonne; c++) {
            matrice[r][c] = matriceTrasposta[r][c];
        }
    }
    puts("Ho trasposto la matrice.");
}

void controllaSeMatriceSimmetrica(int matrice[][100], int numeroColonne, int numeroRighe) {
    int matriceTrasposta[100][100], r, c;
    for (r = 0; r < numeroRighe; r++) {
        for (c = 0; c < numeroColonne; c++) {
            matriceTrasposta[c][r] = matrice[r][c];
        }
    }
    
    if (numeroColonne == numeroRighe) {
        for (c = 0; c < numeroColonne; c++ ) {
            for (r = 0 ; r < numeroRighe; r++) {
                if (matrice[c][r] != matriceTrasposta[c][r]) {
                    break;
                }
            }
            if (r != numeroColonne) {
                break;
            }
        }
        if (c == numeroRighe) {
            puts("La matrice e' simmetrica.");
        }
    }
    else {
        puts("La matrice non e' simmetrica.");
    }
}

void mostraMenu(int matrice[][100], int *numeroColonne, int *numeroRighe) {
    char listaOpzioni[][80] = {
        "Azzeramento di tutti gli elementi contenuti nella matrice",
        "Inserimento di tutti gli elementi contenuti nella matrice",
        "Visualizzazione di tutti gli elementi contenuti nella matrice",
        "Inserimento di un solo elemento nella matrice data riga e colonna",
        "Ordinamento di una riga inserito l'indice",
        "Trasposta elementi della matrice",
        "Controlla se la matrice e' simmetrica"
    };
    
    int i, numeroOpzioni = 7;
    
    puts("----------------------------------------------------------------------");
    for (i = 0; i < numeroOpzioni; i++) {
        printf("| %d. %s\n", i+1, listaOpzioni[i]);
    }
    puts("----------------------------------------------------------------------");
    
    printf("Seleziona un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 7);
    
    switch (scelta) {
        case 1:
            azzeramentoElementiMatrice(matrice, *numeroColonne, *numeroRighe);
            break;
        case 2:
            inserimentoDaTastieraElementiMatrice(matrice, *numeroColonne, *numeroRighe);
            break;
        case 3:
            visualizzaValoriElementiMatrice(matrice, *numeroColonne, *numeroRighe);
            break;
        case 4:
            inserimentoDiUnSoloDatoDataRigaColonnaMatrice(matrice, *numeroColonne, *numeroRighe);
            break;
        case 5:
            ordinamentoElementiRigaMatriceDatoIndice(matrice, *numeroColonne, *numeroRighe);
            break;
        case 6:
            traspostaElementiMatrice(matrice, &numeroColonne, &numeroRighe);
            break;
        case 7:
            controllaSeMatriceSimmetrica(matrice, *numeroColonne, *numeroRighe);
            break;
        default:
            break;
    }
}

void determinaNumeroRigheColonneMatrice(int *numeroColonne, int *numeroRighe) {
    printf("Inserisci il numero delle colonne della matrice: ");
    *numeroColonne = acquisisciNumeroCompresoTraValori(1, 100);
    printf("Inserisci il numero delle righe della matrice: ");
    *numeroRighe = acquisisciNumeroCompresoTraValori(1, 100);
}

int main() {
    int numeroColonne, numeroRighe;
    determinaNumeroRigheColonneMatrice(&numeroColonne, &numeroRighe);
    int matrice[100][100];
    
    while (1) {
        mostraMenu(matrice, &numeroColonne, &numeroRighe);
    }
}