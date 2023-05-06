#include <stdio.h>
#include <dirent.h>

int main()
{

    DIR *d;
    struct dirent *dir;
    char filechar[1000];

    printf("Enter file directory path: ");
    scanf("%s", filechar);

    d = opendir(filechar);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return 0;
}