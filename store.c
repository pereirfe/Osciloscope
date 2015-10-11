#include <stdio.h>
#include <stdlib.h>

int main(void){

  int length = 160;
  char* fileName = "testFile.dat";
  float m[10000][2];

  // Write data to file

  FILE* file = fopen (fileName, "wb");

  for(int i = 0; i< length; i++){
    m[i][0] = m[i][1] = i;
  }
  
  fwrite(m, sizeof(float), 10000*2, file);
  fclose(file);

}
