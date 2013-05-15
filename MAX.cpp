#include "MAX.h"

int dataIn = 2;
int load = 3;
int clock = 4;

 
int maxInUse = 4;    //change this variable to set how many MAX7219's you'll use
 

 
                     // define max7219 registers
byte max7219_reg_noop        = 0x00;
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;
 
void MAX::putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite( clock, LOW);   // tick
    if (data & mask){            // choose bit
      digitalWrite(dataIn, HIGH);// send 1
    }else{
      digitalWrite(dataIn, LOW); // send 0
    }
    digitalWrite(clock, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}

void MAX::maxAll (byte reg, byte col) {    // initialize  all  MAX7219's in the system
  int c = 0;
  digitalWrite(load, LOW);  // begin    
  for ( c =1; c<= maxInUse; c++) {
  putByte(reg);  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
    }
  digitalWrite(load, LOW);
  digitalWrite(load,HIGH);
}

MAX::MAX(){
 
  int e = 0;           // just a varialble
  
  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(load,   OUTPUT);
 
  //beginSerial(9600);
  digitalWrite(13, HIGH);  
 
//initiation of the max 7219
  maxAll(max7219_reg_scanLimit, 0x07);      
  maxAll(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  maxAll(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  maxAll(max7219_reg_displayTest, 0x00); // no display test
   for (e=1; e<=8; e++) {    // empty registers, turn all LEDs off
    maxAll(e,0);
  }
  maxAll(max7219_reg_intensity, 0x0f & 0x0f);    // the first 0x0f is the value you can set
                                                  // range: 0x00 to 0x0f
}

MAX::~MAX(){		}

void MAX::maxSingle( byte reg, byte col) {    
 
  digitalWrite(load, LOW);       // begin    
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data  
  digitalWrite(load, LOW);       // and load da shit
  digitalWrite(load,HIGH);
}

void MAX::test(int time)
{
   maxSingle(1,255);
   maxSingle(2,255);   
   maxSingle(3,255);        
   maxSingle(4,255);          
   maxSingle(5,255);        
   maxSingle(6,255);          
   maxSingle(7,255);      
   maxSingle(8,255);         
        
  delay(time);
}

void MAX::a(int time)
{
   maxSingle(1,0);
   maxSingle(2,124);   
   maxSingle(3,126);        
   maxSingle(4,11);          
   maxSingle(5,11);        
   maxSingle(6,126);          
   maxSingle(7,124);      
   maxSingle(8,0);         
        
  delay(time);
}

void MAX::b(int time)
{
   maxSingle(1,0);
   maxSingle(2,127);   
   maxSingle(3,127);        
   maxSingle(4,73);          
   maxSingle(5,73);        
   maxSingle(6,127);          
   maxSingle(7,54);      
   maxSingle(8,0);         
        
  delay(time);
}

void MAX::c(int time)
{
   maxSingle(1,0);
   maxSingle(2,62);   
   maxSingle(3,127);        
   maxSingle(4,65);          
   maxSingle(5,65);        
   maxSingle(6,99);          
   maxSingle(7,34);      
   maxSingle(8,0);         
        
  delay(time);
}

void MAX::d(int time)
{
   maxSingle(1,0);
   maxSingle(2,127);   
   maxSingle(3,127);        
   maxSingle(4,65);          
   maxSingle(5,99);        
   maxSingle(6,62);          
   maxSingle(7,28);      
   maxSingle(8,0);         
        
  delay(time);
}

void MAX::e(int time)
{
   maxSingle(1,0);
   maxSingle(2,127);   
   maxSingle(3,127);        
   maxSingle(4,73);          
   maxSingle(5,73);        
   maxSingle(6,65);          
   maxSingle(7,65);      
   maxSingle(8,0);  

   delay(time);	
}

void MAX::f(int time)
{
   maxSingle(1,0);
   maxSingle(2,127);   
   maxSingle(3,127);        
   maxSingle(4,9);          
   maxSingle(5,9);        
   maxSingle(6,1);          
   maxSingle(7,1);      
   maxSingle(8,0);  

   delay(time);	
}

void MAX::g(int time)
{
   maxSingle(1,0);
   maxSingle(2,62);   
   maxSingle(3,123);        
   maxSingle(4,65);          
   maxSingle(5,73);        
   maxSingle(6,123);          
   maxSingle(7,58);      
   maxSingle(8,0);         
        
  delay(time);
}

void MAX::scrllD(int num, int time)
{
int bill[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	for ( int n = 1; n <= (num*8); n++) 
	{
		//Just some variables
		
		int dill[8];
		int b;
		
		b = bill[1];
		maxSingle(b,0);
		b = bill[2];
		maxSingle(b,127);
		b = bill[3];
		maxSingle(b,127);
		b = bill[4];
		maxSingle(b,65);  
		b = bill[5];
		maxSingle(b,99);
		b = bill[6];
		maxSingle(b,62);
		b = bill[7];
		maxSingle(b,28);
		b = bill[8];
		maxSingle(b,0);         
        
		dill[1] = bill[1];
		dill[2] = bill[2];
		dill[3] = bill[3];
		dill[4] = bill[4];
		dill[5] = bill[5];
		dill[6] = bill[6];
		dill[7] = bill[7];
		dill[8] = bill[8];
		
		bill[1] = dill[8];
		bill[2] = dill[1];
		bill[3] = dill[2];
		bill[4] = dill[3];
		bill[5] = dill[4];
		bill[6] = dill[5];
		bill[7] = dill[6];
		bill[8] = dill[7];
	
		delay(time);
	}
}
