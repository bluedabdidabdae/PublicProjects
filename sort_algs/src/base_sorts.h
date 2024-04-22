int SelectionSort(data arr[]);                            // done
int DoubleSelectionSort(data arr[]);                      // done
int OddEvenSort(data arr[]);                              // done
int CocktailShakerSort(data arr[]);                       // done
int RadixSortLsd(data arr[]);                             // done
int RadixCountSort(data arr[], int exp, data aux_arr[]);  // done
int RecursiveMergeSort(data arr[], int l, int r);         // done
int MergeArrays(data arr[], int l, int m, int r);         // done
int RecursiveMergeSortCaller(data arr[]);                 // done
void Swap(data *ele1, data *ele2);                        // done
int GetMax(data arr[]);                                   // done

int RecursiveMergeSortCaller(data arr[])
{
    return RecursiveMergeSort(arr, 0, arrLen);
}

int RecursiveMergeSort(data arr[], int l = 0, int r = arrLen)
{
    comps++; //comparazione dell'if
    if (l < r) {
        int m = l + (r - l) / 2;
 
        if(RecursiveMergeSort(arr, l, m) == 1)
            return 1;
        if(RecursiveMergeSort(arr, m + 1, r) == 1)
            return 1;
        if(MergeArrays(arr, l, m, r) == 1)
            return 1;
    }
    return 0;
}

int RadixSortLsd(data arr[])
{
    int m = GetMax(arr);
    data outputarr[arrLen+1];
    
    for(int tmp=0; tmp<arrLen; tmp++)
    {
        outputarr[tmp].value=arr[tmp].value;
        outputarr[tmp].color=arr[tmp].color;
    }

    if(WindowShouldClose())
        return 1;
    if(!benchmark)
        HandleGraphic(outputarr);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        fcycles++; // ciclo for
        if(RadixCountSort(arr, exp, outputarr) == 1)
            return 1;
    }
    return 0;
}

int RadixCountSort(data arr[], int exp, data aux_arr[])
{
    int count[10];
    int i;

    for(i=0;i<10;i++)
    {
        secarr++; //accesso all'array secondario
        fcycles++; // ciclo for
        count[i]=0;
    }

    for (i = 0; i < arrLen; i++)
    {
        secarr++; //accesso all'array secondario
        fcycles++; // ciclo for
        count[(arr[i].value / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        secarr++; //accesso all'array secondario
        fcycles++; // ciclo for
        count[i] += count[i - 1];
    }

    for (i = arrLen - 1; i >= 0; i--) {
        fcycles++; // ciclo for
        marr++; // accesso al main array
        secarr++; //accesso all'array secondario
        aux_arr[count[(arr[i].value / exp) % 10] - 1].value = arr[i].value;
        count[(arr[i].value / exp) % 10]--;
    }

    for (i = 0; i < arrLen; i++)
    {
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
        {
            arr[i].color=visualIndicatorColor;
            HandleGraphic(arr);
            arr[i].color=sortColor;
        }
        fcycles++; // ciclo for
        marr++; // accesso al main array
        secarr++; //accesso all'array secondario
        arr[i].value = aux_arr[i].value;
    }
    return 0;
}

int OddEvenSort(data arr[])
{
    bool sorted=false;
    while(!sorted)
    {
        sorted=true;
        for(int c=1; c<arrLen-1; c+=2)
        {
            marr+=2; // doppio accesso al main array
            comps++; //comparazione dell'if
            if(arr[c].value>arr[c+1].value)
            {
                marr+=2; // doppio accesso al main array
                swaps++; //swap elementi
                Swap(&arr[c], &arr[c+1]);
                if(WindowShouldClose())
                    return 1;
                sorted=false;
            }
            fcycles++; // ciclo for
            
        }
        
        if(!benchmark)
            HandleGraphic(arr);
        
        for(int c=0; c<arrLen-1; c+=2)
        {
            marr+=2; // doppio accesso al main array
            comps++; //comparazione dell'if
            if(arr[c].value>arr[c+1].value)
            {
                marr+=2; // doppio accesso al main array
                swaps++; //swap elementi
                Swap(&arr[c], &arr[c+1]);
                if(WindowShouldClose())
                    return 1;
                sorted=false;
            }
            fcycles++; // ciclo for
        }
        
        if(!benchmark)
            HandleGraphic(arr);
    }
    return 0;
}

int CocktailShakerSort(data arr[])
{
    int c;
    bool sorted=false;
    for(int i=arrLen; i>arrLen/2&&!sorted; i--)
    {
        sorted=true;
        for(c=arrLen-i; c<i; c++)
        {
            marr+=2; // doppio accesso al main array
            comps++; // comparazione dell'if
            if(arr[c].value>arr[c+1].value)
            {
                marr+=2; // doppio accesso al main array
                swaps++; // swap elementi
                Swap(&arr[c], &arr[c+1]);
                sorted=false;
            }
            if(WindowShouldClose())
                return 1;
            fcycles++; // ciclo for
        }
        if(!benchmark)
            HandleGraphic(arr);
        for(c=c; c>=arrLen-i; c--)
        {
            marr+=2; // doppio accesso al main array
            comps++; // comparazione dell'if
            if(arr[c].value>arr[c+1].value)
            {
                marr+=2; // doppio accesso al main array
                swaps++; // swap elementi
                Swap(&arr[c], &arr[c+1]);
                sorted=false;
            }
            if(WindowShouldClose())
                return 1;
            fcycles++; // ciclo for
        }
        if(!benchmark)
            HandleGraphic(arr);
        fcycles++; // ciclo for
    }
    return 0;
}

int DoubleSelectionSort(data arr[])
{
    int max, min;
    for(int c=arrLen; c>arrLen/2; c--){
        min=c-1;
        max=0;
        for(int i=arrLen-c; i<c; i++)
        {
            marr+=2; // doppio accesso al main array
            comps++; // comparazione dell'if
            if(arr[i].value>arr[max].value)
                max=i;
            fcycles++; // ciclo for
        }
        
        marr+=2; // doppio accesso al main array
        swaps++; // swap elementi
        Swap(&arr[max], &arr[c-1]);
        
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
        {
            arr[max].color=visualIndicatorColor;
            arr[c-1].color=visualIndicatorColor;
            HandleGraphic(arr);
            arr[max].color=sortColor;
            arr[c-1].color=sortColor;
        }
        
        for(int i=arrLen-c; i<c; i++)
        {
            marr+=2; // doppio accesso al main array
            comps++; // comparazione dell'if
            if(arr[i].value<arr[min].value)
                min=i;
            fcycles++; // ciclo for
        }
        
        marr+=2; // doppio accesso al main array
        swaps++; // swap elementi
        Swap(&arr[min], &arr[arrLen-c]);
        
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
        {
            arr[min].color=visualIndicatorColor;
            arr[arrLen-c].color=visualIndicatorColor;
            HandleGraphic(arr);
            arr[min].color=sortColor;
            arr[arrLen-c].color=sortColor;
        }   
        fcycles++; // ciclo for
    }
    return 0;
}

int SelectionSort(data arr[])
{
    int max;
    for(int c=arrLen; c>0; c--){
        max=0;
        for(int i=1; i<c; i++)
        {
            marr+=2; // doppio accesso al main array
            comps++; // comparazione dell'if
            if(arr[i].value>arr[max].value)
                max=i;
            fcycles++; // ciclo for
        }
        
        marr+=2; // doppio accesso al main array
        swaps++; // swap elementi
        Swap(&arr[max], &arr[c-1]);
        
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
        {
            arr[max].color=visualIndicatorColor;
            HandleGraphic(arr);
            arr[max].color=sortColor;
        }
        fcycles++; // ciclo for
    }
    return 0;
}

int MergeArrays(data arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    data L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
    {
        fcycles++; // ciclo for
        secarr++; //accesso all'array secondario
        marr++; // accesso al main array
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        fcycles++; // ciclo for
        secarr++; //accesso all'array secondario
        marr++; // accesso al main array
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        fcycles++; // ciclo for
        secarr++; //accesso all'array secondario
        marr++; // accesso al main array
        comps++; //comparazione dell'if
        if (L[i].value <= R[j].value) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
        {
            arr[k].color=visualIndicatorColor;
            HandleGraphic(arr);
            arr[k].color=sortColor;
        }
        k++;
    }
 
    while (i < n1) {
        fcycles++; // ciclo for
        secarr++; //accesso all'array secondario
        marr++; // accesso al main array
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        fcycles++; // ciclo for
        secarr++; //accesso all'array secondario
        marr++; // accesso al main array
        arr[k] = R[j];
        j++;
        k++;
    }
    return 0;
}

void Swap(data *ele1, data *ele2)
{
    data tmp = *ele1;
    *ele1=*ele2;
    *ele2=tmp;
}

int GetMax(data arr[])
{
    int max = arr[0].value;
    for (int i = 1; i < arrLen; i++)
        if (arr[i].value > max)
            max = arr[i].value;
    return max;
}