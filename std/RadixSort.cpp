\begin{lstlisting}
#define base (1<<16)
int n,a[maxn],t[maxn],bucket[base+2];

void RadixSort(int n,int a[],int t[],int bucket[])
{
    int k,i,j;
    for(j=0;j<base;j++) bucket[j]=0;    
    for(k=base-1,i=0; i<2; i++,k<<=16){
        for(j=0;j<n;j++)     bucket[a[j]&k]++;
        for(j=1;j<base;j++)  bucket[j]+=bucket[j-1];
        for(j=n-1;j>=0;j--)  t[--bucket[a[j]&k]]=a[j];
        for(j=0;j<n;j++)     a[j]=t[j];
    }
}
\end{lstlisting}
