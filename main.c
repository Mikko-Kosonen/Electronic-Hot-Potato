/* 
 * File:   main.c
 * Author: Mikko
 *
 * Created on August 3, 2021, 4:12 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 4000000

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

void alustus(void) {
    TRISA = 0;
    PORTA = 0;
}

void odotus(int r);

void main(void) {
    alustus();

    // Arvo satunnaisluku ja odota sen perusteella tietty aika
    // T‰m‰n j‰lkeen kytke k‰rp‰sl‰tk‰ p‰‰lle 200 millisekunniksi
    // Toista ikuisesti
    while (1) {
        int r = ((rand()%(30-100+1)+15) * 100);
            odotus(r);
        
        PORTAbits.RA0 = 1;
        __delay_ms(200);
        PORTAbits.RA0 = 0;
    }
}

// Odota satunnaisluvun m‰‰‰r‰‰m‰ aika
void odotus(int r) {
    for (int i = 0; i < r; i++) {
        __delay_ms(1);
    }
}
