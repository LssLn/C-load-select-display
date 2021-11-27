//inserire Cognome, Nome e Numero di matricola

/* Questo esercizio prevede l’uso di codice esistente da integrare e completare in modo da risolvere il problema proposto.
Lo studente deve utilizzare il codice proposto intervenendo solo nelle parti richieste ed integrandolo se necessario.
Perché l’esercizio sia sufficiente è necessario che il codice compili senza errori, il programma esegua senza errori run-time, e fornisca il risultato previsto. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

void Carica(int* v, int n) {
    // la funzione deve consentire di leggere un vettore di n interi positivi e pari. 
    // I valori che non soddisfano il requisito vanno scartati   
    int i;

    for (i = 0; i < n; i++) {
        //n=dim1
        printf("\nInserisci il valore %d : ", i);
        scanf("%d", &(v[i]));
        if (v[i] < 0 || v[i] % 2 != 0) { //cioè non sono vere le condizioni pari e positivo
            --i; //torno indietro
        }
    }
}

int* Select(int* v, int dim1, int* dim2) { //filtro che scorre v e riempie v2
    // A partire dal vettore v di dimensione dim1, restituisce un nuovo vettore 
    // contenente tutti gli elementi del vettore v che sono multipli di 5.  (modulo = 0  se /5   if(valore%5==0) )
    // La dimensione del nuovo vettore deve essere calcolata e restituita dalla funzione Select 
    // come parametro dim2  (in ingresso ha valore trascurabile, in uscita significativo!)
    //1.    scorro v1 e selezioni gli elementi multipli di 5
    //l'operatore modulo = operatore binario: prende 2 ingressi e da 1 uscita ))) % :intxint->int
    //2.    allocare il v2 di contatore caselle (col numero di multipli di 5, cioè faccio i++ per ogni %!=0)
    //3.    copiare gli elementi multipli di 5 in v2 (v2 ha indice diverso da quello di v, cioè j il contatore del modulo)
    
    int* v_uscita = NULL; //int v_uscita[23] sarebbe cancellata alla fine della chiamata, col puntatore passo i risultati.
    //nella chiamata a select questo avrebbe causato errore a run time di violazione d'accesso
    int dim_uscita = 0;
    int j=0;
    //1.
    for (int i = 0; i < dim1; i++) {
        if (v[i] % 5 == 0)
            ++dim_uscita;
    }
    //2.
    v_uscita = (int*)malloc(dim_uscita * sizeof(int));
    //3.
    for (int i = 0; i < dim1; i++) { //++i
        if (v[i] % 5 == 0) {
            v_uscita[j] = v[i];
            ++j;
        }
     
    }
    if (j != dim_uscita) {
        printf("errore strano\n");
        exit(0);
    }
    *dim2 = dim_uscita;
    return v_uscita;

    return v_uscita;
}

void Display(int* v, int n) {
    // Visualizza tutti gli elementi di un array v passato come parametro avente dimensione n
    int i;
    printf("\nVettore 2: ");
    for (i = 0; i < n; i++) {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int* v1, * v2; //allocazione dinamica a run time
    int dim1, dim2 = 0;
    int i;
    printf("Inserisci la dimensione del vettore v1: ");
    do {
        scanf("%d", &dim1);     // scrivere il codice necessario ad assicurarsi che la dimensione dim1 
    } while (dim1 <= 0);         // sia un numero positivo, se non lo è ripetere l’inserimento (while)
        
    printf("\ndimensione del vettore inserita :%d\n", dim1);

    v1 = (int*)malloc(dim1 * sizeof(int));               // Alloca un array di dim1 elementi int (malloc)
    Carica(v1,dim1);            // Call a Carica per acquisisce gli elementi in v1
    printf("\nvettore 1 : ");
    for (i = 0; i < dim1; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\n\n");
    
    v2 = Select(v1,dim1,&dim2);       // chiama la funzione Select per creare il vettore v2
    
    
    Display(v2,dim2);           // Visualizza il vettore v2  
    
    free(v1);                    // Disalloca v1
    free(v2);                    // Disalloca v2

    

    return 0;
}
