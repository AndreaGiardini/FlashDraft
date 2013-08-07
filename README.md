FlashDraft
=========

Simple draft for projects that need to use the Arduino Due memory to store values.
Remember to include the DueFlash library @ https://github.com/Pansenti/DueFlash
In this project draft there are a couple of functions that may help you to store 
and read values from the Arduino due memory:

  The variable stringData is used to store the value of the Arduino's flash memory
  
  To write the memory:
   - write inside the variable stringData the datas that you want to write
   - call the writeData() function
  
  To read the memory:
   - call the readData() function
   - take the values from the stringData variable

In this way the datas that you store will be written in the non-volatile memory and 
will remain inside the Arduino Due also after reboots.

