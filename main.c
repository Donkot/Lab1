#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char ch[256];
  int num;
  float f;
  if((fp=fopen(argv[1] /*"data.dat"*/,"r"))==NULL) {
    printf("Невозможно открыть файл.\n");
    exit(1);
}
        while(!feof(fp)){
            fread(&num, sizeof(int), 1, fp);
            for( int i = 0; i < 256; i++){
                fread(ch + i, 1, 1, fp);
            }
            fread(&f, sizeof(f), 1, fp);
            printf("%2d | %s | %f\n", num, ch, f);
        }
    fclose(fp);
    getchar();
return 0;
}