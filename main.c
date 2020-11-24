#include <stdio.h>
#include <stdlib.h>
//Definizione struct
typedef struct {

float n;
struct numero *next;

}numero;

//Crea un elemento di tipo numero
numero *crea_elemento(float num);
//Aggiunge elemento in testa alla lista e ritorna il puntatore alla nuova lista
numero *aggiungi_elemento_testa(numero *lista, numero *el);
//Aggiunge elemento in coda alla lista e ritorna il puntatore alla nuova lista
numero *aggiungi_elemento_coda(numero *lista, numero *el);
//Aggiunge elemento in posizione generica della lista e ritorna il puntatore alla nuova lista
numero *aggiungi_elemento_indice(numero *lista, numero *el, int pos);
//Rimuove l'elementp dalla testa della lista e ritorna un puntatore all'elemento
numero *rimuovi_elemento_testa(numero **lista);
//Rimuove l'elementp in posizione generica nella lista e ritorna un puntatore all'elemento
numero *rimuovi_elemento_indice(numero **lista, int pos);
//Rimuove l'elementp che contiene uno specifico numero e ritorna un puntatore all'elemento
numero *rimuovi_elemento_numero(numero **lista, float _n);
//Inverte due elementi generici della lista e ritorna la nuova lista
int inverti_elementi(numero **lista, int ind1, int ind2);
//
void stampa_lista(numero *lista);


int main()
{
    //Dichiaro la testata della lista
    numero *testa=NULL;

    stampa_lista(testa);

    int decisione=-1;
    float n;
    int ind;

    while(decisione){

        puts("\nBenvenuto nel modulo di controllo zugu zugu per lo studio di una lista contenente un numero reale :)");
        puts("Decidi che istruzione fare:");
        puts(" 1)Aggiungere un elemento in testa alla lista");
        puts(" 2)Aggiungere un elemento in coda alla lista");
        puts(" 3)Aggiungere un elemento in posizione generica nella lista");
        puts(" 4)Rimuovere un elemento dalla testa della lista");
        puts(" 5)Rimuovere un elemento in posizione generica nella lista");
        puts(" 6)Rimuovere un elemento dalla lista in base al numero che contiene");
        puts(" 7)Inverti due elementi nella lista");

        puts(" 8)Visualizzare tutto il contenuto della lista");
        puts(" 0)Termina il programma");
        scanf("%d",&decisione);

        switch(decisione){

        case 1:
            printf("\nInserisci il numero da inserire nella testa della lista: ");
            scanf("%f", &n);
            testa=aggiungi_elemento_testa(testa, crea_elemento(n));
            if(testa==NULL) puts("\nNon è stato possibile inserire l'elemento in testa alla funzione.\nPer favore riprovare :)");
            break;

        case 2:
            printf("\nInserisci il numero da inserire nella coda della lista: ");
            scanf("%f", &n);
            testa=aggiungi_elemento_coda(tprec_el2->next=el1;esta, crea_elemento(n));
            if(testa==NULL) puts("Controlla la tua lista che mi sa che c'e' stato un problema nell'aggiunta :/");
            break;

        case 3:
            printf("\nInserisci un indice : ");
            scanf("%d",&ind);
            printf("\nInserisci il numero da inserire nella lista: ");
            scanf("%f", &n);
            testa=aggiungi_elemento_indice(testa, crea_elemento(n), ind);
            if(testa==NULL) puts("Controlla la tua lista che mi sa che c'e' stato un problema nell'aggiunta :/");
            break;

        case 4: ;
            numero *rimosso_testa=rimuovi_elemento_testa(&testa);
            if(rimosso_testa == NULL) puts("\nControlla che la lista non sia vuota :)\n");
            else{
                printf("\nIl numero era %.2f, ora lo lascero' libero :)\n",rimosso_testa->n);
                free(rimosso_testa);
            }
            break;

        case 5:
            printf("\nInserisci un indice : ");
            scanf("%d",&ind);
            numero *rimosso_indice=rimuovi_elemento_indice(&testa,ind);
            if(rimosso_indice == NULL) puts("\nControlla che la lista non sia vuota o che tu abbia inserito un indice valido :)\n");
            else{
                printf("\nIl numero era %.2f, ora lo lascero' libero :)\n",rimosso_indice->n);
                free(rimosso_indice);
            }
            break;

        case 6:
            printf("\nInserisci un numero: ");
            float f;
            scanf("%f",&f);
            numero *rimosso_numero=rimuovi_elemento_numero(&testa,f);
            if(rimosso_numero == NULL) puts("\nControlla che la lista non sia vuota o che tu abbia inserito un numero valido :)\n");
            else{
                printf("\nIl numero era %.2f, ora lo lascero' libero :)\n",rimosso_numero->n);
                free(rimosso_numero);
            }
            break;

        case 7: ;
            //Per convenzione si tiene il primo indice come il più piccolo
            int ind1=-1,ind2=-1;
            while(ind1<0){
                printf("\nInserisci il primo indice (partendo da zero): ");
                scanf("%d",&ind1);
            }
            while(ind2<=ind1){
                printf("\nInserisci il secondo indice (piu' grande di %d): ",ind1);
                scanf("%d",&ind2);
            }
            if(inverti_elementi(&testa, ind1, ind2))
                puts("Elementi invertiti correttamente :)");
            else
                puts("Ci sono stati errori con l'inversione");
            break;

        case 8:
            stampa_lista(testa);
            break;

        case 0:
            puts("\nAddio :(");
            break;

        default:
            puts("\nNumero inserito non valido :(");
            break;
        }
    }

    return 0;
}

numero *crea_elemento(float num){

    //Preparo l'elemento
    numero *el;
    //alloco memoria
    el=malloc(sizeof(numero));
    //Controllo fallimento della malloc
    if(el == NULL) return NULL;
    //Metto il numero nell'elemento
    el->n=num;
    //Prossimo elemento NULL
    el->next=NULL;
    //Ritorno elemento
    return el;

}

numero *aggiungi_elemento_testa(numero *lista, numero *el){

    //Se l'elemento non esiste ritorna la lista stessa
    if(el == NULL) return lista;
    //Se la lista è vuota ritorna il puntatore all'elemento
    if(lista == NULL) return el;

    //il primo elemento diventa il secondo
    el->next=lista;
    //l'elemento è inserito in testa
    lista=el;

    return lista;

}

numero *rimuovi_elemento_testa(numero **lista){

    //Se la lista è vuota
    if(*lista == NULL) return NULL;

    //Prendo il primo elemento
    numero *primo=*lista;
    //la testa della lista ora punta al prossimo elemento
   *lista=primo->next;

    return primo;

}

void stampa_lista(numero *lista){

    printf("\nLista: ");
    //Se lista vuota
    if(lista==NULL){ puts("<vuota>");return; }

    int indice=0;
    while(lista!=NULL){
        //Stampo l'elemento
        printf("\n Numero in posizione %d: %.2f",indice++,lista->n);
        //Passo al prossimo
        lista=lista->next;
    }
    puts("");
}

numero *rimuovi_elemento_indice(numero **lista, int pos){

    //Se lista è vuota ritorna NULL
    if(*lista==NULL) return NULL;
    //Se chiede la posizione 0 richiama la funzione che rimuove in testa
    if(!pos) return (rimuovi_elemento_testa(lista));
    //Prendo in considerazione il primo elemento della lista
    numero *prev=*lista;
    //Prendo anche il secondo della lista (se c'è)
    numero *current=prev->next;
    //Tengo traccia della posizione
    int index=1;
    //Fino a quando non è la posizione corretta muovo i puntatori
    while(index<pos && current!=NULL){
        //Il precedente diventa il corrente
        prev=current;
        //Il corrente diventa il prossimo
        current=current->next;
        index++;
    }
    //Se la lista è finita ritorna NULL
    if(current==NULL)return NULL;
    //Altrimenti stacco l'elemento della lista
    prev->next=current->next;
    //E ritorno l'elemento corrente
    return current;
}

numero *rimuovi_elemento_numero(numero **lista, float _n){

    //Se la lista è vuota
    if(*lista==NULL) return NULL;
    //Prendo in considerazione il primo elemento della lista
    numero *prev=*lista;
    //Prendo anche il secondo della lista (se c'è)
    numero *current=prev->next;
    //Ciclo fino a quando non trovo l'elemento cercato o fino a quando non arrivo all'ultimo
    while(current!=NULL && current->n!=_n){
        //Il precedente diventa il corrente
        prev=current;
        //Il corrente diventa il prossimo
        current=current->next;
    }
    //Se non ha trovato il numero oppure è il primo elemento
    if(current==NULL){
        //Controllo se per caso è nel primo elemento e ritorno la rimozione del primo elemento
        if((*lista)->n==_n) return rimuovi_elemento_testa(lista);
        //Altrimenti ritorna null
        return NULL;
    }
    //Altrimenti stacco l'elemento della lista
    prev->next=current->next;
    //E ritorno l'elemento corrente
    return current;
}

numero *aggiungi_elemento_coda(numero *lista, numero *el){

    //Se l'elemento non esiste ritorna la testa della lista
    if(el==NULL) return lista;
    //Se la lista è vuota ritorno l'elemento
    if(lista==NULL) return el;
    //Tengo conto di dove sono arrivato con la lista
    numero *current=lista;
    //Fino a che non arrivo all'ultimo elemento mi muovo nella lista
    while(current->next!=NULL){
        current=current->next;
    }
    //Aggiungo in coda alla lista
    current->next=el;
    //Ritorna la lista modificata
    return lista;
}

/*
DA FIXARE
*/
numero *aggiungi_elemento_indice(numero *lista, numero *el, int pos){

    //Se l'elemento non esiste ritorna la testa della lista
    if(el==NULL) return lista;
    //Se la lista è vuota ritorno l'elemento
    if(lista==NULL) return el;
    //Se chiede la posizione 0 inserisci in testa
    if(pos==0) return aggiungi_elemento_testa(lista, el);
    //Tengo conto della posizione
    int indice=1;
    //Tengo conto dell'elemento corrente
    numero *current=lista->next;
    //Fino a quando non arrivo all'ultimo elemento oppure all'indice selezionato continuo ad incrementare la posizione
    while(current!=NULL && indice<pos){
        current=current->next;
        indice++;
    }
    //Se è arrivato all'indice inserisco in quella posizione, altrimenti l'inserimento sarà in coda
    el->next=current;
    current=el;
    //Ritorno la lista modificata
    return lista;
}

int inverti_elementi(numero **lista, int ind1, int ind2){
    //Se la lista è vuota non fa niente
    if(*lista==NULL) return 0;
    //Se contiene un solo elemento non può essere effettuato lo scambio
    if((*lista)->next==NULL) return 0;
    //Tengo in considerazione i due ellementi e i rispettiivi precedenti per effettuare lo scambio
    numero *el1=*lista, *prec_el1=NULL, *el2=NULL, *prec_el2=NULL;

    int i=0;

    //Fino a che non arrivo all'ultimo elemento oppure l'indice è quello cercato
    while(el1->next!=NULL && i!=ind1){
        //Passo al prossimo
        prec_el1=el1;
        el1=el1->next;
        i++;
    }
    //Se è arrivato in fondo non si può effettuare lo scambio
    if(el1->next==NULL) return 0;

    //Nuovo punto di partenza
    el2=el1;
    prec_el2=prec_el1;
    //Fino a che non punto a NULL oppure l'indice è quello cercato
    while(el2!=NULL && i!=ind2){
        //Passo al prossimo
        prec_el2=el2;
        el2=el2->next;
        i++;
    }
    //Se non ha trovato il secondo elemento non si può effettuare lo scambio
    if(el2==NULL) return 0;

    //Ora ho entrambi gli elementi da scambiare

    //Se è il primo elemento devo operare con la testa della lista
    if(prec_el1==NULL){
        //Semplice algoritmo di scambio
        numero *temp=el1->next;
        *lista=el2;
        el1->next=el2->next;
        el2->next=temp;
        prec_el2->next=el1;
    }
    //Altrimenti devo ragionare con il prec_el1
    else{
        numero *temp=el1->next;
        prec_el1->next=el2;
        el1->next=el2->next;
        el2->next=temp;
        prec_el2->next=el1;
    }

    //E' andato tutto bene
    return 1;
}
