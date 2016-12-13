#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define LCD_DATA PORTK
#define LCD_CTRL PORTK
#define RS 0x01
#define EN 0x02

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
//#define melodyPin 3

//Mario main theme melody
unsigned int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
unsigned int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
unsigned int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
unsigned int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

unsigned int underworld_melody1[] = {
  NOTE_C5, NOTE_C6, NOTE_A4, NOTE_A5, 
  NOTE_AS4, NOTE_AS5, 0,
  0,
  NOTE_C5, NOTE_C6, NOTE_A4, NOTE_A5, 
  NOTE_AS4, NOTE_AS5, 0,
  0,
  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, 0,
  0,
  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, 0,
  0, NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_C5, NOTE_DS5, 
  NOTE_DS5, NOTE_GS4,
  NOTE_G4, NOTE_CS5,
  NOTE_C5, NOTE_FS5,NOTE_F5, NOTE_E4, NOTE_AS5, NOTE_A5,
  NOTE_GS5, NOTE_DS5, NOTE_B4,
  NOTE_AS4, NOTE_A4, NOTE_GS4,
  0, 0, 0
};

unsigned int harmony1[] = {
  NOTE_FS6, NOTE_FS6,0,NOTE_FS6, 
  0, NOTE_FS6, NOTE_FS6,0,
  NOTE_B6,0,0,0,
  NOTE_G6,0,0,0,

  NOTE_E6, 0, 0,NOTE_C6, 
  0, 0,NOTE_G5,0,
  0, NOTE_C6, 0, NOTE_D6, 
  0, NOTE_CS6, NOTE_C6, 0,

  NOTE_C6, NOTE_G6, NOTE_B6, 
  NOTE_C7, 0, NOTE_A6, NOTE_B6, 
  0, NOTE_A6, 0,NOTE_E6, 
  NOTE_F6, NOTE_D6, 0,0,

  NOTE_E6, 0, 0,NOTE_C6, 
  0, 0,NOTE_G5,0,
  0, NOTE_C6, 0, NOTE_D6, 
  0, NOTE_CS6, NOTE_C6, 0, 

  NOTE_C6, NOTE_G6, NOTE_B6, 
  NOTE_C7, 0, NOTE_A6, NOTE_B6, 
  0, NOTE_A6, 0,NOTE_E6, 
  NOTE_F6, NOTE_D6, 0,0,
};

const unsigned char keypad[4][4] =
{
'0','1','2','3',
'4','5','6','7',
'8','9','A','B',
'C','D','E','F'
};

unsigned char column,row;

void COMWRT4(unsigned char);
void DATWRT4(unsigned char);
void MSDelay(unsigned int);
void buzz(unsigned int frequency, unsigned int length);
//millisecond delay for XTAL=8MHz, PLL=48MHz
//The HCS12 Serial Monitor is used to download and  the program.
//Serial Monitor uses PLL=48MHz
void MSDelayBuzz(unsigned int itime);
void sing(unsigned int song);
void DisplayStr(char*);
void CleanScr();
void DisplayInt(unsigned int);
void Int2Char();

unsigned int freLevel = 0;
char showFre[9];

void main(void) 
{
    showFre[0] = 'L';
    showFre[1] = 'E';
    showFre[2] = 'V';
    showFre[3] = 'E';
    showFre[4] = 'L';
    showFre[5] = ':';
    showFre[8] = '\0';

    //init
    DDRK = 0xFF;   
    COMWRT4(0x33);   //reset sequence provided by data sheet
    MSDelay(1);
    COMWRT4(0x32);   //reset sequence provided by data sheet
    MSDelay(1);
    COMWRT4(0x28);   //Function set to four bit data length
                                     //2 line, 5 x 7 dot format
    MSDelay(1);
    COMWRT4(0x06);  //entry mode set, increment, no shift
    MSDelay(1);
    COMWRT4(0x0E);  //Display set, disp on, cursor on, blink off
    MSDelay(1);
    COMWRT4(0x01);  //Clear display
    MSDelay(1);
    COMWRT4(0x80);  //set start posistion, home position
    MSDelay(1);
    
    //for(;;);       //stay here 
  
    //init buzz
    DDRT = DDRT | 0b00100000;    // PTT5 as output
    
    DDRB = DDRB | 0xFF;    // PTB as output
    DDRJ = DDRJ | 0xFF;    // PTJ as output
    PTJ = PTJ & 0;
    
    DDRB = 0xFF;                           //MAKE PORTB OUTPUT
   DDRJ |=0x02; 
   PTJ &=~0x02;                            //ACTIVATE LED ARRAY ON PORT B
   DDRP |=0x0F;                           //
   PTP |=0x0F;                            //TURN OFF 7SEG LED
   DDRA = 0x0F;                           //MAKE ROWS INPUT AND COLUMNS OUTPUT
   
   Int2Char();
   DisplayStr(showFre);
   
   while(1){                              //OPEN WHILE(1)
      do{                                 //OPEN do1
         PORTA = PORTA | 0x0F;            //COLUMNS SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
      }while(row == 0x00);                //WAIT UNTIL KEY PRESSED //CLOSE do1



      do{                                 //OPEN do2
         do{                              //OPEN do3
            MSDelay(1);                   //WAIT
            row = PORTA & 0xF0;           //READ ROWS
         }while(row == 0x00);             //CHECK FOR KEY PRESS //CLOSE do3
         
         MSDelay(15);                     //WAIT FOR DEBOUNCE
         row = PORTA & 0xF0;
      }while(row == 0x00);                //FALSE KEY PRESS //CLOSE do2

      while(1){                           //OPEN while(1)
         PORTA &= 0xF0;                   //CLEAR COLUMN
         PORTA |= 0x01;                   //COLUMN 0 SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
         if(row != 0x00){                 //KEY IS IN COLUMN 0
            column = 0;
            break;                        //BREAK OUT OF while(1)
         }
         PORTA &= 0xF0;                   //CLEAR COLUMN
         PORTA |= 0x02;                   //COLUMN 1 SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
         if(row != 0x00){                 //KEY IS IN COLUMN 1
            column = 1;
            break;                        //BREAK OUT OF while(1)
         }

         PORTA &= 0xF0;                   //CLEAR COLUMN
         PORTA |= 0x04;                   //COLUMN 2 SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
         if(row != 0x00){                 //KEY IS IN COLUMN 2
            column = 2;
            break;                        //BREAK OUT OF while(1)
         }
         PORTA &= 0xF0;                   //CLEAR COLUMN
         PORTA |= 0x08;                   //COLUMN 3 SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
         if(row != 0x00){                 //KEY IS IN COLUMN 3
            column = 3;
            break;                        //BREAK OUT OF while(1)
         }
         row = 0;                         //KEY NOT FOUND
      break;                              //step out of while(1) loop to not get stuck
      }                                   //end while(1)

      if(row == 0x10){
         PORTB=keypad[0][column];         //OUTPUT TO PORTB LED
         
         //fre up
         if(column == 0) {
         
            freLevel++;
         }
         
         //fre down
         else if(column == 1) {
         
            if(freLevel != 0)
               freLevel--;
         }
         
         //play
         else if(column == 2) {
            sing(1);
            sing(2);          
         }
         
         Int2Char();
         DisplayStr(showFre);
 
      }
      else if(row == 0x20){
         PORTB=keypad[1][column];
 
      }
      else if(row == 0x40){
         PORTB=keypad[2][column];
 
      }
      else if(row == 0x80){
         PORTB=keypad[3][column];
 
      }

      do{
         MSDelay(15);
         PORTA = PORTA | 0x0F;            //COLUMNS SET HIGH
         row = PORTA & 0xF0;              //READ ROWS
      }while(row != 0x00);                //MAKE SURE BUTTON IS NOT STILL HELD
   }                                      //CLOSE WHILE(1)
	
}

void COMWRT4(unsigned char command)
  {
        unsigned char x;
        
        x = (command & 0xF0) >> 2;         //shift high nibble to center of byte for Pk5-Pk2
      LCD_DATA =LCD_DATA & ~0x3C;          //clear bits Pk5-Pk2
        LCD_DATA = LCD_DATA | x;          //sends high nibble to PORTK
        MSDelay(1);
        LCD_CTRL = LCD_CTRL & ~RS;         //set RS to command (RS=0)
        MSDelay(1);
        LCD_CTRL = LCD_CTRL | EN;          //rais enable
        MSDelay(5);
        LCD_CTRL = LCD_CTRL & ~EN;         //Drop enable to capture command
        MSDelay(15);                       //wait
        x = (command & 0x0F)<< 2;          // shift low nibble to center of byte for Pk5-Pk2
        LCD_DATA =LCD_DATA & ~0x3C;         //clear bits Pk5-Pk2
        LCD_DATA =LCD_DATA | x;             //send low nibble to PORTK
        LCD_CTRL = LCD_CTRL | EN;          //rais enable
        MSDelay(5);
        LCD_CTRL = LCD_CTRL & ~EN;         //drop enable to capture command
        MSDelay(15);
  }

void DATWRT4(unsigned char data)
  {
  unsigned char x;
       
        
        
        x = (data & 0xF0) >> 2;
        LCD_DATA =LCD_DATA & ~0x3C;                     
        LCD_DATA = LCD_DATA | x;
        MSDelay(1);
        LCD_CTRL = LCD_CTRL | RS;
        MSDelay(1);
        LCD_CTRL = LCD_CTRL | EN;
        MSDelay(1);
        LCD_CTRL = LCD_CTRL & ~EN;
        MSDelay(5);
       
        x = (data & 0x0F)<< 2;
        LCD_DATA =LCD_DATA & ~0x3C;                     
        LCD_DATA = LCD_DATA | x;
        LCD_CTRL = LCD_CTRL | EN;
        MSDelay(1);
        LCD_CTRL = LCD_CTRL & ~EN;
        MSDelay(15);
  }


 void MSDelay(unsigned int itime)
  {
    unsigned int i; unsigned int j;
    for(i=0;i<itime;i++)
      for(j=0;j<4000;j++);
 }
 
void sing(unsigned int song) {
   
  unsigned int thisNote;
  unsigned int pauseBetweenNotes;
  unsigned int size;
  unsigned int noteDuration;
   
  if(song == 1) {
    
    size = sizeof(melody) / sizeof(int);
    for (thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      noteDuration = 110 / tempo[thisNote];

      buzz(melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      pauseBetweenNotes = noteDuration*13/10;
      MSDelayBuzz(pauseBetweenNotes); 
      
      // stop the tone playing:
      //buzz(0, noteDuration);
      
    }
    
  }else{
    size = sizeof(underworld_melody) / sizeof(int);
    for (thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      
     noteDuration = 130 / underworld_tempo[thisNote];
      
      buzz(underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      pauseBetweenNotes = noteDuration*13/10;
      MSDelayBuzz(pauseBetweenNotes); 
      
      // stop the tone playing:
      //buzz(0, noteDuration);
      
    }
  }
    
}

void buzz(unsigned int frequency, unsigned int length) {

  unsigned int delayValue;
  long numCycles;
  int gap;
  long i;
  
  frequency = frequency + freLevel*200;
  
  if(frequency == 0) {
  
      //pause  
      delayValue = 0;
      numCycles = length*10000;
      
  } else {
  
      delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
      //// 1 second's worth of 1000000 microseconds, divided by the frequency, then split in half since
      //// there are two phases to each cycle
      numCycles = frequency * length/ 100; // calculate the number of cycles for proper timing
      //// multiply frequency, which is really cycles per second, by the number of seconds to
      //// get the total number of cycles to produce
  }
  
  //DisplayInt(frequency);
  gap = frequency/625;
  switch(gap) {
    case 0:
      PORTB = 0x01;
      break;
    case 1:
      PORTB = 0x02;
      break;
    case 2:
      PORTB = 0x04;
      break;
    case 3:
      PORTB = 0x08;
      break;
    case 4:
      PORTB = 0x10;
      break;
    case 5:
      PORTB = 0x20;
      break;
    case 6:
      PORTB = 0x40;
      break;
    default:
      PORTB = 0x80;
      break;
  }
  
  for (i = 0; i < numCycles; i++) { // for the calculated length of time...
    PTT = PTT | 0x20;      //make PT5=1 write the buzzer pin high to push out the diaphram
    MSDelayBuzz(delayValue); // wait for the calculated delay value
    PTT = PTT & 0xDF;      //Make PT5=0 write the buzzer pin low to pull back the diaphram   
    MSDelayBuzz(delayValue); // wait again or the calculated delay value
  }
  
}

//1 microsecond 4 loops
//millisecond delay(4000 loops) for XTAL=8MHz, PLL=48MHz
//Serial Monitor uses PLL=48MHz
 void MSDelayBuzz(unsigned int itime)
  {
    unsigned int i;
    unsigned int j;
    
    for(i=0;i<itime;i++)
      for(j=0;j<4;j++);
  }
  
void Int2Char() {

    showFre[6] = freLevel/10+48;
    showFre[7] = freLevel%10+48;
}
  
void DisplayInt(unsigned int num) {

    char showNum[5];
    
    showNum[0] = num/1000+48;
    showNum[1] = num/100%10+48;
    showNum[2] = num/10%10+48;
    showNum[3] = num%10+48;
    showNum[4] = '\0';
    
    DisplayStr(showNum);
}

void DisplayStr(char* str) {
  
  int i;
  CleanScr();
  
  for(i=0; str[i]!='\0' ;++i) {
    DATWRT4(str[i]);
    MSDelay(1);  
  }
}

void CleanScr() {
  COMWRT4(0x01);  //Clear display
  MSDelay(1);
  COMWRT4(0x80);  //set start posistion, home position
  MSDelay(1);  
}

