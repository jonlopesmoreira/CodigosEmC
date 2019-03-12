void merge(int *v, int tam)
{
    merge_ordena(v, 0, tam-1);
}
void merge_ordena(int *v, int esq, int dir)
{
    if(esq>=dir)
        return;
    int meio = (esq+dir)/2;
    merge_ordena(v, esq, meio);
    merge_ordena(v, meio+1, dir);
    mergeSort_intercala(int *v, int esq, int meio, int dir);
    return;
}
void mergeSort_intercala ( int *v, int esq , int meio , int dir )
{
    int i, j, k;
    int a_tam = meio - esq +1;
    int b_tam = dir - meio ;
    int *a = (int*) malloc ( sizeof (int) * a_tam );
    int *b = (int*) malloc ( sizeof (int) * b_tam );

    for (i = 0; i < a_tam ; i ++)
        a[i] = v[i+ esq ];

    for (i = 0; i < b_tam ; i ++)
        b[i] = v[i+ meio +1];

    for (i = 0, j = 0, k = esq; k <= dir; k ++)
    {
        if (i == a_tam )
            v[k] = b[j ++];
        else if (j == b_tam )
            v[k] = a[i ++];
        else if (a[i] < b[j])
            v[k] = a[i ++];
        else
            v[k] = b[j ++];
    }
    free (a);
    free (b);
}