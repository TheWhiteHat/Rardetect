#include <stdio.h>
int main(int argc, char** argv) {
   int header[7] = {0x52,0x61,0x72,0x21,0x1A,0x07,0x00};
   int current;
   int progress=0;
   FILE* jaypeg;
   if(argc !=2) {
      printf("usage: rardetect filename\n");
      return 2;
   }
   jaypeg = fopen(argv[1],"rb");
   if(jaypeg==NULL) {
      fprintf(stderr,"FILE NOT FOUND\n");
      return 3;
   }
   current = getc(jaypeg);
   while(current != EOF) {
      if(current==header[progress]) {
         progress++;
      }
      else if(current==header[0]) {
         progress=1;
      }
      else {
         progress=0;
      }
      if(progress==7) {
         printf("There is a rar\n");
         return 0;
      }
      current=getc(jaypeg);
   }
   printf("There is no rar\n");
   return 1;
}
