#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define DATA_L 10000

uint8_t get_byte();

int main(void){

  char* fileName = "mydata.dat";
  float m[DATA_L][2];
  int i;
  float data;
  // Write data to file

  for(i = 0; i<DATA_L; i++){
    m[i][0] = i;
  }
  // preenchendo tabela com valores recuperados do ADC (futuro)

  while(1){
    //TODO CS-LOW	
    for(i = 0; i<DATA_L; i++){
      m[i][1] = (((float)(get_byte()<<2 + get_byte()))/102.4) - 5.0; // Agregacao 10bits + interpolacao (y=10k/1024 -5)  
    }
    //TODO CS-HIGH

    FILE* file = fopen (fileName, "wb");
    fwrite(m, sizeof(float), DATA_L*2, file);
    fclose(file);
  }
}


uint8_t get_byte(){
  return 1<<7;
}
