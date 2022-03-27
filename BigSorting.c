#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char **temp;
void sort(char **ar, int left , int right);
void merge(char **ar, int left , int mid , int right);
int main()
{
    int n;
    printf("Enter the size of string \n");
    scanf("%d\n", &n);
    char **str =(char **)malloc(n*sizeof(char*));
    char **temp =(char **)malloc(n*sizeof(char*));

    for(int i=0; i<n; i++)
    {
      scanf("%s\n",str+i);
    }

       sort(str, 0 , n-1);
       printf("Printing string \n");
      for(int i=0; i<n; i++)
      puts(str[i]);


    return 0;

}

void sort(char **ar, int left , int right)
{
    int mid=0;
    if(left<right)
    {
        mid=(left+right)/2;

        sort(ar,left, mid);
        sort(ar, mid+1, right);

        merge(ar, left, mid, right);
    }
}

void merge(char **ar, int left , int mid , int right)
{
    int i=left ;
    int j=mid;
    int k=left;

    while((i<=mid-1) && (j<=right))
    {
        int len1= strlen(ar[i]);
        int len2= strlen(ar[j]);

        if((len1<len2) ||((len1==len2) && strcmp(ar[i],ar[j])<0))
        {
               temp[k++]=ar[i++];
        }
        else 
        {
            temp[k++]=ar[j++];
        }
    }

    while(i<=mid-1)
      temp[k++]=ar[i++];


    while(j<=right)
       temp[k++]=ar[i++];

    for(int i=left; i<=right ; i++)
    {
        ar[i]=temp[k]; 
    }

    
}