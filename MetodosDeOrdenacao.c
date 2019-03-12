#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void shellSortKnuth( int *v, int n);
void shellSort2kmais1( int *v, int n);
void shellSort2kmenos1( int *v, int n);
void inserction( int *v, int n);
void bubble(int *v, int n);
void selection(int *v, int n);
void merge(int *v, int n, int *comp, int *mov);
void submerge(int *v, int esq, int dir, int *comp, int *mov);
void merge_intercala(int *v, int esq, int meio, int dir, int *comp, int *mov);
void quick(int *v, int n, int *comp, int *mov);
void subquick(int *v, int esq , int dir, int *comp, int *mov);
void quick_intercala(int *v, int esq, int dir, int *i, int *j, int *comp, int *mov);
void heapRefaz(int *v, int esq, int dir);
void heapConstroi(int *v, int n);
void heapSort(int *v, int n);

int cmp=0;
int mv=0;


int main()
{
    int *v=NULL, *aux=NULL;
    int i,j,n,tam;
    int comp, mov;
    scanf("%d", &n); // numero lido na entrada representado o total de vetores
    for(j=0; j<n; j++)
    {
        scanf("%d", &tam);  // tamanho do vetor j
        printf("Vetor %d:\n", j+1);
        printf("- Comparacoes | Movimentacoes | Tempo:\n"); // foi considerado segundos para o tempo pois para vetores muito grandes, seria um numero muito grande em milisegundos para se visualizar
        v = (int*) malloc(sizeof(int)*tam);
        aux = (int*) malloc(sizeof(int)*tam);
        for(i=0; i<tam; i++)
        {
            scanf("%d", &v[i]);  // escaneando valores  de entrada
            aux[i] = v[i];          // fazendo copia dos valores
        }
        bubble(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        selection(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        inserction(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        merge(v,tam, &comp, &mov);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        quick(v,tam, &comp, &mov);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        shellSortKnuth(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        shellSort2kmais1(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        shellSort2kmenos1(v,tam);
        for(i=0; i<tam; i++)
            v[i] = aux[i]; // voltando com o vetor para os valores iniciais para proxima ordenação
        heapSort(v,tam);
        free(v);
        free(aux);
        printf("\n");
    }
    return 0;
}
void shellSortKnuth( int *v, int n)
{
    int i, j, h;
    int comp=0, mov=0;
    int aux ;
    double tempo;
    clock_t start_time;
    start_time = clock();
    for (h = 1; h < n; h = 3 * h + 1); /* h inicial . */
    do
    {
        h = (h - 1) / 3; /* atualiza h. */
        for (i = h ; i < n ; i ++)
        {
            aux = v[i];
            mov++;
            j = i;
            /* Comparações entre elementos com distância h: */
            while (v[j - h] > aux )
            {
                comp++;
                v[j] = v[j - h];
                mov++;
                j -= h;
                if (j < h)
                {
                    comp++;
                    break ;
                }
            }
            v[j] = aux ;
            mov++;
        }
    } while (h != 1);
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Shell 01..: %3d | %3d | %.3lf\n",comp,mov,tempo);
    // metodo de knuth
}
void shellSort2kmais1( int *v, int n)
{
    int i, j, h;
    int aux ;
    int comp=0, mov=0;
    double tempo;
    clock_t start_time;
    start_time = clock();
        //sequencia dada por 2^n + 1
    h = pow(2.0,n) + 1;
    do
    {
        h = ((h-1)/2)+1; /* atualiza h. */
        for (i = h ; i < n ; i ++)
        {
            aux = v[i];
            mov++;
            j = i;
            /* Comparações entre elementos com distância h: */
            while (v[j - h] > aux )
            {
                comp++;
                v[j] = v[j - h];
                mov++;
                j -= h;
                if (j < h)
                {
                    comp++;
                    break ;
                }
            }
            v[j] = aux ;
            mov++;
        }
    } while (h != 1);
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Shell 02..: %3d | %3d | %.3lf\n",comp,mov,tempo);
}
void shellSort2kmenos1( int *v, int n)
{
    int i, j, h;
    int comp=0, mov=0;
    int aux ;
    double tempo;
    clock_t start_time;
    start_time = clock();
    //sequencia dada por 2^n + 1
    h = pow(2.0,n)-1;
    do
    {
        h = ((h-1)/2); /* atualiza h. */
        for (i = h ; i < n ; i ++)
        {
            aux = v[i];
            mov++;
            j = i;
            /* Comparações entre elementos com distância h: */
            while (v[j - h] > aux )
            {
                comp++;
                v[j] = v[j - h];
                mov++;
                j -= h;
                if (j < h)
                {
                    comp++;
                    break ;
                }

            }
            v[j] = aux ;
            mov++;
        }
    } while (h != 1);
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Shell 03..: %3d | %3d | %.3lf\n",comp,mov,tempo);
}

void inserction( int *v, int n)
{
    int i, j;
    int comp=0, mov=0;
    int aux ;
    double tempo;
    clock_t start_time;
    start_time = clock();
    for (i = 1; i < n; i ++)
    {
        aux = v[i];
        mov++;
        j = i - 1;
        while (j >= 0 && v[j]> aux)
        {
            comp++;
            comp++;
            v[j + 1] = v[j];
            mov++;
            j --;
        }
        comp++;
        v[j + 1] = aux ;
        mov++;
    }
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Insertion.: %3d | %3d | %.3lf\n",comp,mov,tempo);
 }

void bubble(int *v, int n)
{
    int i, j;
    int comp=0, mov=0;
    int aux ,troca;
    double tempo;
    clock_t start_time;
    start_time = clock();
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(v[j]>v[j+1])
            {
                comp++;
                troca=1;
                aux = v[j];
                mov++;
                v[j] = v[j+1];
                mov++;
                v[j+1] = aux;
                mov++;
            }
            comp++;
        }
        if(troca==0)
        {
            comp++;
            break;
        }
        comp++;
        troca=0;
    }
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Bubble....: %3d | %3d | %.3lf\n",comp,mov,tempo);
}
void selection(int *v, int n)
{
    int i, j;
    int comp=0, mov=0;
    int aux,troca ;
    double tempo;
    clock_t start_time;
    start_time = clock();
     for(i=0; i<n; i++)
    { // 7 2 8 3 55 77 88 = 2 7 8 9 1 99 10
        for(j=i; j<n-1; j++)
        {
            if(v[i]>v[j+1])
            {
                comp++;
                troca=1;
                aux = v[j+1];
                mov++;
                v[j+1] = v[i];
                mov++;
                v[i] = aux;
                mov++;
            }
            comp++;
        }
        if(troca==0)
        {
            comp++;
            break;
        }
        comp++;
        troca=0;
    }
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Selection.: %3d | %3d | %.3lf\n",comp,mov,tempo);
}
void merge(int *v, int n, int *comp, int *mov)
{
    (*comp)=0;
    (*mov)=0;
    double tempo;
    clock_t start_time;
    start_time = clock();
    submerge(v, 0, n-1, comp, mov);
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Merge.....: %3d | %3d | %.3lf\n",*comp,*mov,tempo);
}
void submerge(int *v, int esq, int dir, int *comp, int *mov)
{
    if(esq>=dir)
    {
        (*comp)++;
        return;
    }
    int meio = (esq+dir)/2;
    submerge(v, esq,meio, comp, mov);
    submerge(v, meio+1,dir, comp, mov);
    merge_intercala(v,esq,meio,dir, comp, mov);
}
void merge_intercala(int *v, int esq, int meio, int dir, int *comp, int *mov)
{
    int i,j,k;
    int tamA = meio-esq+1;
    int tamB = dir-meio;

    int *a = (int*) malloc(sizeof(int)*tamA);
    int *b = (int*) malloc(sizeof(int)*tamB);

    for(i=0; i<tamA; i++)
    {
        (*mov)++;
        (*comp)++;
        a[i] = v[i+esq];
    }

    for(i=0; i<tamB; i++)
    {
        (*mov)++;
        (*comp)++;
        b[i] = v[i+meio+1];
    }


    for(i=0,j=0,k=esq; k<=dir; k++)
    {
        if(i==tamA)
        {
            (*mov)++;
            (*comp)++;
            v[k] = b[j++];
        }
        else if(j==tamB)
        {
            (*mov)++;
            (*comp)++;
            v[k] = a[i++];
        }
        else if(a[i]>b[j])
        {
            (*mov)++;
            (*comp)++;
            v[k] = b[j++];
        }
        else
        {
            (*mov)++;
            (*comp)++;
            v[k] = b[j++];
        }
    }
    free(a);
    free(b);
}
void quick(int *v, int n, int *comp, int *mov)
{
    (*comp)=0;
    (*mov)=0;
    double tempo;
    clock_t start_time;
    start_time = clock();
    subquick(v, 0, n-1, comp, mov);
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Quick.....: %3d | %3d | %.3lf\n",*comp,*mov,tempo);
}
void subquick(int *v, int esq , int dir, int *comp, int *mov)
{
    int i, j;
    quick_intercala(v, esq , dir , &i, &j, comp,mov);
    if (esq < j)
    {
        (*comp)++;
        subquick(v, esq , j, comp, mov);
    }
    if (i < dir)
    {
        (*comp)++;
        subquick (v, i, dir, comp, mov);
    }
}
void quick_intercala(int *v, int esq, int dir, int *i, int *j, int *comp, int *mov)
{

    int pivo, aux;
    *i = esq;
    *j = dir;
    pivo = v[(*i + *j)/2];
    do
    {
        while(!(pivo <= v[*i]))
        {
            (*comp)++;
            (*i)++;
        }

        while((pivo < v[*j]))
        {
            (*comp)++;
            (*j)--;
        }
        if(*i <= *j)
        {
            (*comp)++;
            aux = v[*i];
            (*mov)++;
            v[*i] = v[*j];
            (*mov)++;
            v[*j] = aux;
            (*mov)++;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
    (*comp)++;
}


void heapRefaz(int *v, int esq, int dir)
{
    int i = esq;
    int j = i*2 + 1; // j = primeiro filho de i
    int aux = v[i]; // aux = no i (pai de j)
    while (j <= dir)
    {
        cmp++;
        if (j < dir && v[j] < v[j+1])
        {
            j++; // j recebe o outro filho de i
            cmp++;
            cmp++;
        }
        if (aux>= v[j])
        {
            cmp++;
            break; // heap foi refeito corretamente
        }
        v[i] = v[j];
        mv++;
        i = j;
        j = i*2 + 1; // j = primeiro filho de i
    }
    v[i] = aux;
    mv++;
}

void heapConstroi(int *v, int n)
{
    int esq;
    esq = (n / 2) - 1; // esq = nó anterior ao primeiro nó folha do heap
    while (esq >= 0)
    {
        cmp++;
        heapRefaz(v, esq, n-1);
        esq--;
    }
}
void heapSort(int *v, int n)
{
    int aux;
    double tempo;
    clock_t start_time;
    start_time = clock();
    heapConstroi(v, n);
    while (n > 1)
    {
        cmp++;
        aux = v[n-1];
        mv++;
        v[n-1] = v[0];
        mv++;
        v[0] = aux;
        mv++;
        n--;
        heapRefaz(v, 0, n-1); // refaz o heap
    }
    tempo = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("- - Heap......: %3d | %3d | %.3lf\n",cmp,mv,tempo);
}

