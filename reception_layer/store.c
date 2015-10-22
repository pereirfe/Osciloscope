#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bcm2835.h>

#define DATA_L 100000

int main(void){

  char* fileName = "mydata.dat";
  float m[DATA_L][2];
  uint8_t rec_buf[2*DATA_L], snd_buf[2*DATA_L]; 
  int i;
  int k;
  float data;
  // Write data to file


  if (!bcm2835_init()) return 1;
  bcm2835_spi_begin();
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8);// The default
  bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default

  for(i = 0; i<DATA_L; i++){
    m[i][0] = i; // TODO: preencher com o tempo da freq de update (testar.. 15M?)
    snd_buf[2*i] = i%0x100;
    snd_buf[2*i+1] = 0;
  }
  // preenchendo tabela com valores recuperados do ADC (futuro)

  while(1){

    puts("connectando ADC...");
    // Recebe dados do ADC
    bcm2835_spi_transfernb((char*)snd_buf, (char*)rec_buf, 2*DATA_L); // Funcao ja cuida do CS

    puts("Recebidos! Iniciando processamento");
    // Processa dados
    for(i = 0; i<DATA_L; i++){
      k = rec_buf[2*i]; 
      k = k<<6 + rec_buf[2*i+1];
      m[i][1] = ((float)k)/102.3 - 5.0;
//      m[i][1] = (((float)(rec_buf[2*i]<<2 +(rec_buf[2*i+1])>>6))/102.3) - 5.0; // Agregacao 10bits + interpolacao (y=10k/1023 -5)  
//      printf("(rcv:snd): (%d:%d) - (%d:%d)\n", (rec_buf[2*i]), snd_buf[2*i], (rec_buf[2*i+1]), snd_buf[2*i+1]);
    }

    puts("Salvando arquivo...");

    FILE* file = fopen (fileName, "wb");
    fwrite(m, sizeof(float), DATA_L*2, file);
    fclose(file);
    puts("Completed!.");
    break; // TODO: Tirar
  }
  return 0;
}
