// Including Libraries and Headers                      


#include <avr/io.h>
#include <util/delay.h>


//***********************************************************************************************
// Change constant here to change port used by 7-segment


#define F_CPU 16000000L
#define PORT_7_SEGMENT PORTD
#define DDR_7_SEGMENT DDRD 
#define PI 3.14
#define segg 6
#define segf 5
#define sege 4
#define segd 3
#define segc 2
#define segb 1
#define sega 0


//*************************************************************************************************
// This function shows value of count on display 


void SevenSegment(uint8_t count)
{

      switch (count)
      {
         case 0: //Showing0
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (1<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);


         break;

         case 1: //Showing1
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (1<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (1<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (1<<sega);
         break;

         case 2: //Showing2
     
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (1<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;

         case 3: //Showing3
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
    PORT_7_SEGMENT |= (0<<sega);

         break;

         case 4: //Showing4
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (1<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
    PORT_7_SEGMENT |= (1<<sega);

         break;

         case 5: //Showing5
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (1<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;

         case 6: //Showing6
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (1<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;

         case 7: //Showing7
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (1<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (1<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;

         case 8: //Showing8
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;

         case 9: //Showing9
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (1<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);
         break;
     case 10: //ShowingA
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (1<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (0<<sega);
     break;
     case 11: //ShowingB
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (1<<segb);
      PORT_7_SEGMENT |= (1<<sega);
     break;
     case 12: //ShowingC
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (1<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (1<<segc);
      PORT_7_SEGMENT |= (1<<segb);
      PORT_7_SEGMENT |= (0<<sega);
     break;
     case 13: //ShowingE
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (1<<sega);
     break;
     case 14: //Showing#
      PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (0<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (1<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (0<<segb);
      PORT_7_SEGMENT |= (1<<sega);
     break;
     case 15: //Showing*
       PORT_7_SEGMENT = 0b00000000;
      PORT_7_SEGMENT |= (0<<segg); 
      PORT_7_SEGMENT |= (1<<segf);
      PORT_7_SEGMENT |= (0<<sege);
      PORT_7_SEGMENT |= (0<<segd);
      PORT_7_SEGMENT |= (0<<segc);
      PORT_7_SEGMENT |= (1<<segb);
      PORT_7_SEGMENT |= (1<<sega);
     break;
      }
}


//****************************************************************************************************************
//Goertzel Functions Here


#define SAMPLING_FREQUENCY 8000
float TARGET_FREQUENCY;
#define N 204
float coeff,Q1,Q2,Q0,k,w;
int input_data[205];


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


//This function fills the array needed to be passed to goertzel


void sample()
{
  for(int i =0;i<N;i++)     
  {
  // initialize counter
   
  
      ADCSRA |= (1<<ADSC);
      while((ADCSRA & (1<<ADIF))==0);
      input_data[i]=ADC;  
      ADCSRA |= (1<<ADIF);
    _delay_us(21) ; 
 
  }

} 


//This function returns the magnitude of signal for every series of samples


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


//***********************************************************************************************************


float row[]={697.00,770.00,852.00,941.00};
float col[]={1209.00,1336.00,1477.00,1633.00};
float maxRow,maxCol,magnitudeRow,magnitudeCol,checkCol,checkRow,maxcheckCol,maxcheckRow;

int _col,_row,_colcheck,_rowcheck;


//main function


int main()
{
   //Setup
   magnitudeRow = 0;
   magnitudeCol = 0;
   checkCol = 0 ; 
   checkRow = 0;
   maxCol = 0 ; 
   maxRow = 0 ; 
   maxcheckCol = 0 ; 
   maxcheckRow = 0 ; 
   DDR_7_SEGMENT=0xFF;    //All output
   PORT_7_SEGMENT=0xFF; //All segments off
   uint8_t inputSignal=0;
   ADMUX |= (1<<REFS0);
   //set prescaller to 128 and enable ADC 
   ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
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


      if(_col==0 )
    {

            if(_row==0 )
      {
      inputSignal = 1;
      }
      else if(_row==1 )
      {
      inputSignal = 4;
      }
      else if(_row==2 )
      {
      inputSignal = 7;
      }
      else if(_row==3 )
      {
      inputSignal = 15;
      }
    }
    else if(_col==1 )
      {
      if(_row==0 )
      {
      inputSignal = 2;
      }
      else if(_row==1 )
      {
      inputSignal = 5;
      }
      else if(_row==2 )
      {
      inputSignal = 8;
      }
      else if(_row==3 )
      {
      inputSignal = 0;
      }
    }
    else if(_col==2 )
    {
      if(_row==0)
      {
      inputSignal = 3;
      }
      else if(_row==1 )
      {
      inputSignal = 6;
      }
      else if(_row==2 )
      {
      inputSignal = 9;
      }
      else if(_row==3 )
      {
      inputSignal = 14;
      }
      
     }
    else if(_col==3 ) 
    {
      if(_row==0 )
      {
      inputSignal = 10;
      }
      else if(_row==1 )
      {
      inputSignal = 11;
      }
      else if(_row==2 )
      {
      inputSignal = 12;
      }
      else if(_row==3)
      {
      inputSignal = 13;
      }
    }
     if(maxCol>=200)
   {
    if(maxRow>200)
      SevenSegment(inputSignal);  
  }
  

  }
}
