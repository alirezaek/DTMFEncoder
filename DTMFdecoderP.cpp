// Including Libraries and Headers                      

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>



//**************
// Change constant here to change port used by 7-segment

#define PORT_7_SEGMENT PORTD
#define DDR_7_SEGMENT DDRD 
#define PI 3.143


//****************
// This function shows value of count on display 


void SevenSegment(uint8_t count)
{

      switch (count)
      {
         case 0:
      PORT_7_SEGMENT=
            0b10001000; //0
         break;

         case 1:
      PORT_7_SEGMENT=
            0b10111110;  //1
         break;

         case 2:
      PORT_7_SEGMENT= 
            0b00011001; //2
         break;

         case 3:
      PORT_7_SEGMENT=
            0b00011100; //3
         break;

         case 4:
      PORT_7_SEGMENT=  
            0b00101110; //4
         break;

         case 5:
      PORT_7_SEGMENT=
            0b01001100; //5
         break;

         case 6:
      PORT_7_SEGMENT=
            0b01001000; //6
         break;

         case 7:
      PORT_7_SEGMENT= 
            0b10111100; //7
         break;

         case 8:
      PORT_7_SEGMENT= 
            0b00001000; //8
         break;

         case 9:
      PORT_7_SEGMENT=
            0b00001100; //9
         break;
     case 10:
      PORT_7_SEGMENT= 
        0b00101000;  //A
     break;
     case 11:
       PORT_7_SEGMENT= 
        0b01001010;  //b
     break;
     case 12:
       PORT_7_SEGMENT=
        0b11001001;  //C
     break;
     case 13:
       PORT_7_SEGMENT=  
         0b00011010;  //d
     break;
     case 14:
       PORT_7_SEGMENT= 
        0b00101010;  //#
     break;
     case 15:
       PORT_7_SEGMENT=
        0b01011010;  //*
     break;
      }
}

//*******************
//Goertzel Functions Here


#define SAMPLING_FREQUENCY 9000.00
float TARGET_FREQUENCY;
#define N 599
float coeff,Q1,Q2,Q0,k,w;
int input_data[600];


//This function initializes Goertzel algorithm constants for every target frequency


void Goertzel(float TARGET_FREQUENCY)
{
 
    k = (int) (0.5 + N*TARGET_FREQUENCY/SAMPLING_FREQUENCY) ;
    w = (2*PI/N)*k ;
    //cosine = cos w ;
    //sine = sin w ;
    coeff =(float)2 * (float)cos(w)  ; 
    ResetGoertzel();
}


//This functions resets Goertzel's Q1 and Q2


void ResetGoertzel(void)
{
    Q2 = 0;
    Q1 = 0;
 }


//This function evaluates Q0 for every sample. Q0 for last sample would be our answer


void ProcessSample(int sample)
{
    Q0 = coeff * Q1 - Q2 + sample ;
    Q2 = Q1 ;
    Q1 = Q0 ; 
}


//This function returns the magnitude of signal for every series of samples
void sample()
{
  for(int i =0;i<N;i++)      // 90Hz goertzel resoloution
  {
  // initialize counter
    /*
    TCCR1A |= 0;
    OCR1A = 1759;  // sample per 110us 
    TCNT1 = 0;
    // not required since WGM11:0, both are zero (0)
    TCCR1B |= (1 « CS10); // timer mode no prescale
      while((TIFR1 & (1«OCF1A)));  
    */
      ADCSRA |= (1«ADSC);
      while((ADCSRA & (1«ADIF))==0);
    input_data[i]=ADC;  
      ADCSRA |= (1«ADIF);
    //TIFR1 |= (1 « OCF1A);
    //TCNT1 = 0;   
  }//  sample[90] per 10 ms

}
float detect()
{

    float magnitude;
    for (int i=0; i<N; i++) 
    {
      ProcessSample(input_data[i]);
    }
    magnitude = (float)sqrtf(Q1*Q1 + Q2*Q2 - coeff*Q1*Q2);
    return magnitude;
}


//*************************************

float row[]={697.00,770.00,852.00,941.00};
float col[]={1209.00,1336.00,1477.00,1633.00};
float maxRow,maxCol,magnitudeRow,magnitudeCol;
float magnitude_threshhold=30;
int _col,_row;
float inputinputsignal ; 
int main()
{
   //Setup
   magnitudeRow = 0;
   magnitudeCol = 0;
   DDR_7_SEGMENT=0xFF;    //All output
   PORT_7_SEGMENT=0xFF; //All segments off
   uint8_t inputSignal=0;
  ADMUX |= (1«REFS0);
  //set prescaller to 128 and enable ADC 
  ADCSRA |= (1«ADPS2)|(1«ADPS1)|(1«ADPS0)|(1«ADEN);
  ADMUX = (ADMUX & 0xF0) | (0 & 0x0F);
   while(1)  //loop forever
   {
    maxRow = 0.00;
    maxCol = 0.00;  
    magnitudeRow =0.00;
    magnitudeCol = 0.00;
      sample();
    for(int i = 0;i<4;i++)
    {
      Goertzel(col[i]);
        magnitudeCol = detect();
    ResetGoertzel();

        if(magnitudeCol>maxCol)
        {
            maxCol = magnitudeCol;
            _col=i ;
        }

     }


      for(int i = 0;i<4;i++)
      {
      Goertzel(row[i]);

      magnitudeRow = detect();
    ResetGoertzel();
      if(magnitudeRow>maxRow)
      {
        maxRow = magnitudeRow;
        _row = i ; 
      }
    }


      if(_col==0)
    {

            if(_row==0)
      {
      inputSignal = 1;
      }
      else if(_row==1)
      {
      inputSignal = 4;
      }
      else if(_row==2)
      {
      inputSignal = 7;
      }
      else if(_row==3)
      {
      inputSignal = 15;
      }
    }
    else if(_col==1)
      {
      if(_row==0)
      {
      inputSignal = 2;
      }
      else if(_row==1)
      {
      inputSignal = 5;
      }
      else if(_row==2)
      {
      inputSignal = 8;
      }
      else if(_row==3)
      {
      inputSignal = 0;
      }
    }
    else if(_col==2)
    {
      if(_row==0)
      {
      inputSignal = 3;
      }
      else if(_row==1)
      {
      inputSignal = 6;
      }
      else if(_row==2)
      {
      inputSignal = 9;
      }
      else if(_row==3)
      {
      inputSignal = 14;
      }
      
     }
    else if(_col==3)
    {
      if(_row==0)
      {
      inputSignal = 10;
      }
      else if(_row==1)
      {
      inputSignal = 11;
      }
      else if(_row==2)
      {
      inputSignal = 12;
      }
      else if(_row==3)
      {
      inputSignal = 13;
      }
    }
     if(maxCol>=40)
   {
    if(maxRow>40)
      SevenSegment(inputSignal);  
  }

  }
}
