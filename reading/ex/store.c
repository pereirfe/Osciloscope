#include <stdio.h>
#include <stdlib.h>

int main(void){

  int length = 160;
  char* fileName = "mydata.dat";
  float m[100][2];
  int i;
  // Write data to file

  FILE* file = fopen (fileName, "wb");


  for(i = 0; i<100; i++){
    m[i][0] = i;
    m[i][1] = i;
  }
  
  fwrite(m, sizeof(float), 100*2, file);
  fclose(file);

}
