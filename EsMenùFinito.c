#include <stdio.h>
#include <limits.h>

void Stampa(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("Il numero inserito è: %d \n", array[i]);
}

int Inserisci_in_coda(int array[], int *n, int numero)
{

    array[*n] = numero;
    (*n)++;

    return *n;
}

int Modifica(int array[], int posizione, int valore)
{

    array[posizione] = valore;
    return posizione;
}

int Elimina(int array[], int *n, int posizione)
{

    for (int i = posizione; i < *n; i++)
    {
        array[i] = array[i + 1];
    }
    (*n)--;
    return posizione;
}

int Ricerca(int array[], int n, int valore)
{

    for (int i = 0; i < n; i++)
    {
        if (array[i] == valore)
        {
            return i;
        }
    }

    return -1;
}

int Inserisci_in_posizione(int array[], int *n, int posizione, int valore)
{
    for (int i = *n; i > posizione; i--)
    {
        array[i] = array[i - 1];
    }
    array[posizione] = valore;
    (*n)++;
    return posizione;
}

void Stampa_inversa(int array[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        printf("I numeri inseriti al contrario sono: %d\n", i, array[i]);
}

int Max(int array[], int n)
{
    int massimo = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > massimo)
            massimo = array[i];

    return massimo;
}

void Operazioni(int scelta, int numeri[], int *n)
{

    if (scelta == 1)
    {
        Stampa(numeri, *n);
    }

    if (scelta == 2)
    {
        int numero, posizione;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        posizione = Inserisci_in_coda(numeri, n, numero);
        printf("Numero inserito in posizione: %d", posizione);
    }

    if (scelta == 3)
    {
        int valore, posizione;
        printf("Inserisci il numero da sostituire: ");
        scanf("%d", &valore);
        posizione = Ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            printf("Inserisci il nuovo numero: ");
            scanf("%d", &valore);
            Modifica(numeri, posizione, valore);
        }
        else
        {
            printf("Numero non valido");
        }
    }

    if (scelta == 4)
    {
        int valore, posizione;
        printf("Inserisci il numero da eliminare: ");
        scanf("%d", &valore);
        posizione = Ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            Elimina(numeri, n, posizione);
        }
        else
        {
            printf("Numero non valido");
        }
    }

    if (scelta == 5)
    {
        int posizione, valore;
        printf("Inserisci il valore da cercare: ");
        scanf("%d", &valore);
        posizione = Ricerca(numeri, *n, valore);

        if (posizione > -1)
        {
            printf("Numero trovato in posizione %d", posizione);
        }
        else
        {
            printf("Numero non valido");
        }
    }

    if (scelta == 6)
    {
        int valore, posizione;
        printf("Inserisci il numero da aggiungere: ");
        scanf("%d", &valore);
        printf("Inserisci la posizione: ");
        scanf("%d", &posizione);

        if (posizione < *n)
        {
            Inserisci_in_posizione(numeri, n, posizione, valore);
        }
        else
        {
            printf("Valore non esistente");
        }
    }

    if (scelta == 7)
    {
        Stampa_inversa(numeri, *n);
    }

    if (scelta == 8)
    {
        int max = Max(numeri, *n);
        printf("Il massimo dei numeri inseriti nell'array è: %d", max);
    }
}
int Inserimento(int numeri[])
{
    int num = 0, n = 0;
    while (1)
    {
        printf("Inserisci un numero.Premi -1 per terminare l'inserimento \n");
        scanf("%d", &num);
        if (num == -1)
        {
            return n;
        }

        numeri[n] = num;
        n++;
    }
}
int Menù()
{

    int scelta;

    printf("Premere 1 per mostrare il contenuto dell'array\n");
    printf("Premere 2 per inserire un elemento in coda\n");
    printf("Premere 3 per modificare un elemento\n");
    printf("Premere 4 per eliminare un elemento\n");
    printf("Premere 5 per ricercare un elemento\n");
    printf("Premere 6 per inserire un elemento in una certa posizione\n");
    printf("Premere 7 per mostrare il contenuto dell'array all'inverso\n");
    printf("Premere 8 per mostrare il valore massimo dell'array\n");
    printf("Premere 0 per terminare il programma\n");

    scanf("%d", &scelta);

    return scelta;
}

int main(int argc, char *argv[])
{

    int sceltaMenù, numMax[SHRT_MAX], n = Inserimento(numMax);

    do
    {
        sceltaMenù = Menù();

        if (sceltaMenù == 0)
        {
            printf("Programma terminato\n");
            return 0;
        }
        Operazioni(sceltaMenù, numMax, &n);
    } while (sceltaMenù != 0);
}