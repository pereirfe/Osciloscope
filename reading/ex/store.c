#include <stdio.h>
#include <stdlib.h>

int main(void){

  int length = 160;
  char* fileName = "mydata.dat";
  float m[100][2];
  int i;
  // Write data to file

  FILE* file = fopen (fileName, "wb");

<<<<<<< HEAD:store.c
  for(int i = 0; i< length; i++){
    m[i][0] = m[i][1] = 1.0;
=======

  for(i = 0; i<100; i++){
    m[i][0] = i;
    m[i][1] = i;
>>>>>>> b85de11bb2f1efc602cfd5fc74036a0fe0fb5608:reading/ex/store.c
  }
  
  fwrite(m, sizeof(float), 100*2, file);
  fclose(file);
}
