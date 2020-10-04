#include <stdio.h>
#define ll long long int 
#define ld long double 
ll N, C;
ll arr[2000007];
void merge(ll  l, ll  m, ll  r) 
{ 
    ll  i, j, k; 
    ll  n1 = m - l + 1; 
    ll  n2 =  r - m; 
  
    
    ll  L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(ll  l, ll  r) 
{ 
    if (l < r) 
    { 
        
         
        ll  m = l+(r-l)/2; 
  
         
        mergeSort( l, m); 
        mergeSort(m+1, r); 
  
        merge( l, m, r); 
    } 
} 
ll tof(ll dis)
{
    ll cow, pos;
    cow = 1;
    pos = arr[0];
    for(ll i=0;i<N;i++)
    {
        if(arr[i]-pos>=dis)
        {
            pos = arr[i];
            cow++;
            if(cow==C)
            return 1;
        }
    }
    return 0;
}

ll binsearch()
{
    ll l = 0, r = arr[N-1];
    ll temp = -7;
    for(ll i = 0; i < r; i++)
    {
        ll mid = (l+r)/2;
        if(tof(mid)==1)
        {
            if(mid>temp)
            temp = mid;
            l = (mid+1);
        }
        else 
        r = mid;
    }
    return temp;
}
int main(void)
{
    ll t;
    scanf("%lld", &t);
    for(ll i = 0; i<t; i++)
    {
        scanf("%lld %lld", &N, &C);
        for(ll j=0;j<N;j++)
        {
            scanf("%lld", &arr[j]);
        }
        mergeSort(0, N-1);
        ll ans = binsearch(arr);
        printf("%lld\n", ans);
    }

    return 0;
}
