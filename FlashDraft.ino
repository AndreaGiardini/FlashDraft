/*
* Author: Andrea Giardini
* Email: contact@andreagiardini.com
* Website: www.andreagiardini.com
*/

/*
* Include the DueFlash library @ https://github.com/Pansenti/DueFlash
*/
#include <efc.h>
#include <DueFlash.h>
#include <flash_efc.h>
#define DATA_LENGTH   ((IFLASH1_PAGE_SIZE/sizeof(uint32_t)) * 5)
#define  FLASH_START  ((uint32_t *)IFLASH1_ADDR + 4)

/*
* Memory representation in char* and uint32_t* format
*/
uint32_t* uintData;
char*     stringData;

DueFlash flash;

void setup() {

  //Serial initialization @ 115200 baud rate
  Serial.begin(115200);

  //Variables allocation
  stringData = (char*) malloc(sizeof(char)*DATA_LENGTH);
  uintData = (uint32_t*) malloc(sizeof(uint32_t)*DATA_LENGTH/4);
}

/*
* Convert char array (input) to uint32_t array (output)
*/
void stringToInt32(char* input, uint32_t* output){
  int index;
  for(index=0; index < DATA_LENGTH/4; index++){
    output[index] = (uint32_t)input[index*4] << 24 |
      (uint32_t)input[index*4+1] << 16 |
      (uint32_t)input[index*4+2] << 8  |
      (uint32_t)input[index*4+3];
  }
}

/*
* Convert uint32_t array (input) to string (output)
*/
void int32ToString(uint32_t* input, char* output){
  int index;
  for(index=0; index < DATA_LENGTH/4; index++){
    output[index*4] = input[index] >> 24;
    output[index*4+1] = input[index] >> 16;
    output[index*4+2] = input[index] >> 8;
    output[index*4+3] = input[index];
  }
}

/*
* It stores the stringData content in the memory
*/
void writeData()
{
  //The char array is converted to a uint32_t array
  stringToInt32(stringData, uintData);
  //The array is copied in the memory
  flash.write(FLASH_START, uintData, DATA_LENGTH);
}

/*
* The memory content is stored in the stringData variable
*/
void readData()
{
  //The Arduino memory is copied inside a uint32_t array
  for (int i = 0; i < DATA_LENGTH; i++) {
    uintData[i]=((uint32_t *)FLASH_START)[i];
  }
  //The uint32_t array is converted to a char array
  int32ToString(uintData, stringData);
}

void loop() {

  /*
  * The variable stringData is used to store the value of the Arduino's flash memory
  *
  * To write the memory:
  *  - write inside the variable stringData the datas that you want to write
  *  - call the writeData() function
  *
  * To read the memory:
  *  - call the readData() function
  *  - take the values from the stringData variable
  */

}

