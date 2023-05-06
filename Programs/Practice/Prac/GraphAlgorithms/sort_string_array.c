#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a,int b)
{
    if(a>b)
       return b;
     return a;
}
int lexicographic_sort(const char* a, const char* b) {
    int n=strlen(a);
    int m=strlen(b);
    
    for(int i=0;i<min(n,m);i++)
      {
          if(a[i]<b[i])
              return 0;
          if(a[i]>b[i])
              return 1;
      }
    if(n>m)
       return 1;
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  int n=strlen(a);
  int m=strlen(b);
  for(int i=0;i<min(n,m);i++)
   {
       if(a[i]<b[i])
          return 1;
      if(a[i]>b[i])
         return 0;
   }
  if(n<m)
     return 1;
  return 0;
}
int dist(const char *a)
{
    int f[26];
    for(int i=0;i<26;i++)
       f[i]=0;
    for(int i=0;i<strlen(a);i++)
      {
          f[a[i]-'a']++;
      }
      int cnt=0;
    for(int i=0;i<26;i++)
       if(f[i]>0) 
         cnt++;
    return cnt;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int cnta=dist(a);
    int cntb=dist(b);
    if(cnta>cntb)
       return 1;
    if(cntb>cnta)
       return 0;
    return lexicographic_sort(a,b);
      
}

int sort_by_length(const char* a, const char* b) {
  int n=strlen(a);
  int m=strlen(b);;
  if(n<m)
     return 0;
  if(n>m)
    return 1;
   return lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int  flag=0;
    int p=len;
    while (flag==0) 
    {
        flag=1;
        for (int i = 0; i <p-1; i++) {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                flag=0;
            }
        }
        p--;
    }
}


int main() 
{
    
    
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}