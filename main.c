#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char ch;
  char it[2];
  char chr[256];
  char fl[4];
  if((fp=fopen(argv[1] /*"data.dat"*/,"r"))==NULL) {
    printf("Невозможно открыть файл.\n");
    exit(1);
  }
  while((ch=fgetc(fp)) != EOF) {
      while((ch=fgetc(fp)) != EOF) {
      it[0] = ch;
      int i = 0;
      while(((ch=fgetc(fp)) != EOF) && (i < 1)) {
        it[i+1] = ch;
        i++;
      }
      short resulti = *(short*)&it;
      i = 0;
      while(((ch=fgetc(fp)) != EOF) && (i < 255)) {
        chr[i] = ch;
        i++;
      }
      i = 0;
      while(((ch=fgetc(fp)) != EOF) && (i < 4)) {
        fl[i] = ch;
        i++;
      }
      float resultf = *(float*)&fl;

      printf("%d\t%s\t%f\n", resulti, chr, resultf);
    }
  }
  fclose(fp);
  getchar();
  return 0;
}
