#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100], gen[100], code[50];
int dataLen, genLen;

void doXor(int i) {
  // do XOR with needed data and code
  if (code[i] == gen[i])
    code[i] = '0';
  else
    code[i] = '1';
}

void crc() {
  int i, j;

  // for the first division
  for (i = 0; i < genLen; i++) {
    code[i] = data[i];
  }
    
  // polynomial divison
  do { 
    if (code[0] == '1') {
      for (j = 1; j < genLen; j++) {
        doXor(j);
      }
    }

    // copy remainder 
    for (j = 0; j < genLen - 1; j++)
      code[j] = code[j + 1];

    // adding next bit from top
    code[j] = data[i++];
  } while (i <= dataLen + genLen - 1);
}

void clean() {
  // to clear the code array
  int i;
  for (i = 0; i < 50; i++) {
    code[i] = '0';
  }
}

void sender() {
  int i;
  printf("SENDER\n\n");
  printf("Enter the polynomial: ");
  scanf("%s", data);
    
  printf("Enter the generator polynomial: ");
  scanf("%s", gen);
    
  // find lengths
  dataLen = strlen(data);
  genLen = strlen(gen);
    
  //appending genLen-1(L-1) 0's
  for(i = dataLen; i < dataLen + genLen - 1; i++)
    data[i] = '0';
    
  //perform datanomial division
  crc();
    
  //Senders coded datanomial
  for(i = dataLen; i < dataLen + genLen - 1; i++)
    data[i] = code[i - dataLen];
        
  printf("\nCRC computed: %s\n", code);
  printf("Coded polynomial: %s\n\n", data);
}

int receiver() {
  int i;
  printf("\nRECEIVER\n\n");
  printf("Enter the data received: ");
  scanf("%s", data);
  dataLen = strlen(data);
  int flag = 0;
  crc();

  // printf("\nCRC computed: %s\n", code);
  // printf("Coded polynomial: %s\n\n", data);

  // check for error, if 1 is present in the code
  for(i = 0; i < strlen(code); i++) {
    if(code[i]=='1')
      flag = 1;
  }

  return flag;
}

void main() {
  // make the coded polynomial at the sender
  sender();
    
  // send coded polynomial to receiver
  int flag = receiver();

  printf(flag == 1 ? "\nThere seems to be an error in the data\n" : "\nNo error has been detected\n");
}
