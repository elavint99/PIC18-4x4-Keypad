// Microcontrollers Laboratory
// Practice 6
// Esteban Lavín Treviño

// Libraries and Headers
#include "Config_header.h" // Include the config header file

// Directives
#define _XTAL_FREQ 10000000 // frequency


// Constants
        
        
// Global Variables - Function Prototypes
void Ports_configuration(void);                     // Ports configuration.
void release(void);                                 // Release function
void __interrupt (high_priority) high_isr(void);    // High priority Interrupt Service Request.
void __interrupt (low_priority) low_isr(void);      // Low priority Interrupt Service Request.


// Main Function
void main(void){
    Ports_configuration(); // ports configuration function
    while (1) {                         // infinite loop   
        LATC = 0x70;                    // LATC value = 0x70
        switch(LATC | PORTB){           // switch; or condition LATC OR PORTB
            case 0x77:                  // key 1
               LATD = (LATD<<4) | 0x01; // shift 4 bits last value OR with 0x01
               release();               // release function
               break;                   // break   
            case 0x7B:                  // key 4
               LATD = (LATD<<4) | 0x04; // shift 4 bits last value OR with 0x04
               release();               // release function
               break;                   // break
            case 0x7D:                  // key 7
               LATD = (LATD<<4) | 0x07; // shift 4 bits last value OR with 0x07
               release();               // release function
               break;                   // break
            case 0x7E:                  // key * = F
               LATD = (LATD<<4) | 0x0F; // shift 4 bits last value OR with 0x0F
               release();               // release function
               break;                   // break
        }
 
        LATC = 0xB0;                    // LATC value = 0xB0
        switch(LATC | PORTB){           // switch; or condition LATC OR PORTB
            case 0xB7:                  // key 2
               LATD = (LATD<<4) | 0x02; // shift 4 bits last value OR with 0x02
               release();               // release function
               break;                   // break
            case 0xBB:                  // key 5
               LATD = (LATD<<4) | 0x05; // shift 4 bits last value OR with 0x05
               release();               // release function
               break;                   // break
            case 0xBD:                  // key 8
               LATD = (LATD<<4) | 0x08; // shift 4 bits last value OR with 0x08
               release();               // release function
               break;                   // break
            case 0xBE:                  // key 0
               LATD = (LATD<<4) | 0x00; // shift 4 bits last value OR with 0x00
               release();               // release function
               break;                   // break
        }

        LATC = 0xD0;                    // LATC value = 0xD0
        switch(LATC | PORTB){           // switch; or condition LATC OR PORTB
            case 0xD7:                  // key 3
               LATD = (LATD<<4) | 0x03; // shift 4 bits last value OR with 0x03
               release();               // release function
               break;                    // break 
            case 0xDB:                  // key 6
               LATD = (LATD<<4) | 0x06; // shift 4 bits last value OR with 0x06
               release();               // release function
               break;                   // break
            case 0xDD:                  // key 9
               LATD = (LATD<<4) | 0x09; // shift 4 bits last value OR with 0x09
               release();               // release function
               break;                   // break
            case 0xDE:                  // key # = E
               LATD = (LATD<<4) | 0x0E; // shift 4 bits last value OR with 0x0E
               release();               // release function
               break;                   // break
        }

        LATC = 0xE0;                    // LATC value = 0xE0
        switch(LATC | PORTB){           // switch; or condition LATC OR PORTB
            case 0xE7:                  // key A
               LATD = (LATD<<4) | 0x0A; // shift 4 bits last value OR with 0x0A
               release();               // release function
               break;                   // break
            case 0xEB:                  // key B
               LATD = (LATD<<4) | 0x0B; // shift 4 bits last value OR with 0x0B
               release();               // release function
               break;                   // break
            case 0xED:                  // key C
               LATD = (LATD<<4) | 0x0C; // shift 4 bits last value OR with 0x0C
               release();               // release function
               break;                   // break
            case 0xEE:                  // key D
               LATD = (LATD<<4) | 0x0D; // shift 4 bits last value OR with 0x0D
               release();               // release function
               break;                   // break
        }
    }              
}     
 

// Function Definitions
void Ports_configuration(void){//            Ports configuration.
    // PORTB
    ANSELB = 0x00;    // Digital
    TRISB = 0x0F;    // Input
    WPUB = 0x0F;     // Pull up resistors available
    INTCON2 = INTCON2 & 0x7F; // Activate the pull up resistors
    
    // PORTD
    LATD = 0x00; // starting value 0x00
    ANSELD = 0x00; // Digital
    TRISD = 0x00; // Output
    
    // PORTC
    LATC = 0x00;  // starting value 0x00
    ANSELC = 0x00; // digital
    TRISC = 0x00; // 0 = output / 1 = input
}

void release(void){                      // Release function
    __delay_ms(50);                      // delay
    while(1){                            // infinite loop until returned
        if((PORTB & 0x0F) == 0x0F) {    // if button is released
            LATC = 0xFF;                // LATC = 0xFF
            __delay_ms(100);            // delay
            return;                     // break loop
        }
    }
    __delay_ms(50);                     // delay
}

void __interrupt (high_priority) high_isr(void){//  High priority Interrupt Service Request.
    Nop();
}
void __interrupt (low_priority)  low_isr(void){//   Low priority Interrupt Service Request.
    Nop();
}
