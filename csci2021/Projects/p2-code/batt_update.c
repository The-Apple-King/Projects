#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batt.h"
#include <stdint.h>

int batt_update()
{
    batt_t batt;
    batt.mlvolts = 0;
    batt.mode = 0;
    batt.percent = 0;
    if (set_batt_from_ports(&batt) != 1)
    {
        set_display_from_batt(batt, &BATT_DISPLAY_PORT);
        return 0; // succeed
    }
    return 1; // fail
}
// Called to update the battery meter display.  Makes use of
// set_batt_from_ports() and set_display_from_batt() to access battery
// voltage sensor then set the display. Checks these functions and if
// they indicate an error, does NOT change the display.  If functions
// succeed, modifies BATT_DISPLAY_PORT to show current battery level.
//
// CONSTRAINT: Does not allocate any heap memory as malloc() is NOT
// available on the target microcontroller.  Uses stack and global
// memory only.

int set_batt_from_ports(batt_t *batt)
{
    if (BATT_VOLTAGE_PORT >= 0)
    {
        batt->mlvolts = BATT_VOLTAGE_PORT >> 1;
        if (batt->mlvolts < 3000)
        {
            batt->percent = 0;
        }
        else
        {
            batt->percent = (batt->mlvolts - 3000) >> 3;
        }
        if(batt->percent > 100){
            batt->percent = 100;
        }
        batt->mode = (BATT_STATUS_PORT & 0b00010000) ? 1 : 2;
        return 0;
    }
    return 1; // voltage is negative
}
// Uses the two global variables (ports) BATT_VOLTAGE_PORT and
// BATT_STATUS_PORT to set the fields of the parameter 'batt'.  If
// BATT_VOLTAGE_PORT is negative, then battery has been wired wrong;
// no fields of 'batt' are changed and 1 is returned to indicate an
// error.  Otherwise, sets fields of batt based on reading the voltage
// value and converting to precent using the provided formula. Returns
// 0 on a successful execution with no errors. This function DOES NOT
// modify any global variables but may access global variables.
//
// CONSTRAINT: Avoids the use of the division operation as much as
// possible. Makes use of shift operations in place of division where
// possible.
//
// CONSTRAINT: Uses only integer operations. No floating point
// operations are used as the target machine does not have a FPU.
//
// CONSTRAINT: Limit the complexity of code as much as possible. Do
// not use deeply nested conditional structures. Seek to make the code
// as short, and simple as possible. Code longer than 40 lines may be
// penalized for complexity.

int set_display_from_batt(batt_t batt, int *display)
{
    int nums[10] = {0b0111111, 0b0000011, 0b1011011, 1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b01111111, 0b1101111}; // bit vals for each digit

    if (batt.percent >= 90)
    {
        *display = 0b11111;
    }
    else if (batt.percent >= 70)
    {
        *display = 0b01111;
    }
    else if (batt.percent >= 50)
    {
        *display = 0b00111;
    }
    else if (batt.percent >= 30)
    {
        *display = 0b00011;
    }
    else if (batt.percent >= 5)
    {
        *display = 0b00001;
    }
    else
    {
        *display = 0b00000;
    }
    *display <<= 24;

    if (batt.mode == 1)
    { // volts
        int voltage = (batt.mlvolts * 3) / 60;
        int count = 100;
        for (int i = 14; i >= 0; i -= 7)
        {
            *display |= nums[voltage % count] << (i + 3);
            voltage -= (voltage % count) * count;
            count /= 10;
        }
        *display |= 0b001;
    }
    else
    { // percent
        int percent = (batt.percent * 100);
        int count = 100;
        int nonzero = 0;
        *display |= nums[0] << 3;
        for (int i = 14; i >= 0; i -= 7)
        {
            *display |= nums[percent % count] << (i + 3);
            percent -= (percent % count) * count;
            count /= 10;
            nonzero = 1;
        }
        
        *display |= 0b110;
    }
    return 0;
}
// Alters the bits of integer pointed to by 'display' to reflect the
// data in struct param 'batt'.  Does not assume any specific bit
// pattern stored at 'display' and completely resets all bits in it on
// successfully completing.  Selects either to show Volts (mode=1) or
// Percent (mode=2). If Volts are displayed, only displays 3 digits
// rounding the lowest digit up or down appropriate to the last digit.
// Calculates each digit to display changes bits at 'display' to show
// the volts/percent according to the pattern for each digit. Modifies
// additional bits to show a decimal place for volts and a 'V' or '%'
// indicator appropriate to the mode. In both modes, places bars in
// the level display as indicated by percentage cutoffs in provided
// diagrams. This function DOES NOT modify any global variables but
// may access global variables. Always returns 0.
//
// CONSTRAINT: Limit the complexity of code as much as possible. Do
// not use deeply nested conditional structures. Seek to make the code
// as short, and simple as possible. Code longer than 65 lines may be
// penalized for complexity.