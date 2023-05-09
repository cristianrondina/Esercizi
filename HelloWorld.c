#include <stdio.h>
void main()
{
    int numeri, somma = 0, media = 0; // dichiaro le variabili
    int count = 0, maggiori = 0;
    int mediaPari = 0;
    int mediaDispari = 0;

    do // ciclo do while con controllo in coda perchè l'utente deve entrare nel ciclo almeno una volta
    {
        printf("Inserisci dei numeri interi: \n");
        scanf("%d", &numeri);
        somma = somma + numeri; // calcolo somma
        count++;                // per contare quanti numeri sono stati inseriti
        maggiori = numeri > 7;
        maggiori++;

    } while (somma < 20);
    printf("La somma dei numeri inseriti è: %d", somma); // output
    media = somma / count;                               // calcolo media
    printf("\n");
    printf("La media dei numeri inseriti è: %d", media);
    printf("\n");
    printf("Numeri maggiori di 7: %d", maggiori);
    mediaPari = (numeri % 2) + somma / count;
    printf("\n");
    printf("La media dei numeri pari inseriti è: %d", mediaPari);
    printf("\n");
    mediaPari = (numeri % 2) + somma / count;
    printf("La media dei numeri dispari inseriti è: %d", mediaDispari);
}