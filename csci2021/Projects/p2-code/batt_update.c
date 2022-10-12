#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batt.h"
#include <stdint.h>

/**
 * @brief creates a batt to update using the helper functions
 *
 * @return int returns 0 success, 1 failure
 */
int batt_update()
{
    // instantiate the battery
    batt_t batt; // battery to store info
    batt.mlvolts = 0;
    batt.mode = 0;
    batt.percent = 0;

    // update the battery and set display if wired correctly
    if (set_batt_from_ports(&batt) != 1)
    {
        set_display_from_batt(batt, &BATT_DISPLAY_PORT);
        return 0; // succeed
    }
    return 1; // fail
}

/**
 * @brief Set the batt from the global variable that takes info from the ports
 *
 * @param batt the battery to set
 * @return int returns 0 if correct, returns 1 if theres an error
 */
int set_batt_from_ports(batt_t *batt)
{
    if (BATT_VOLTAGE_PORT >= 0) // if voltage is positive
    {
        // set voltage
        batt->mlvolts = BATT_VOLTAGE_PORT >> 1;
        // set percent
        if (batt->mlvolts < 3000) // if less than 0%
        {
            batt->percent = 0;
        }
        else // if more than 0 less than 100
        {
            batt->percent = (batt->mlvolts - 3000) >> 3;
        }
        if (batt->percent > 100) // if greater thatn 100 then set to 100
        {
            batt->percent = 100;
        }
        batt->mode = (BATT_STATUS_PORT & 0b00010000) ? 1 : 2; // sets the mode of battery based on the 4th bit
        return 0;
    }
    return 1; // voltage is negative
}

/**
 * @brief Set the display from batt object
 *
 * @param batt the battery to get info from
 * @param display the 28 digit variable used to change the display
 * @return int always returns 0
 */
int set_display_from_batt(batt_t batt, int *display)
{
    int count = 100;              // used to know which amount to modulo by
    *display = 0;                                                                                                                   // initializes value
    int nums[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b01111111, 0b1101111}; // bit vals for each digit
    int battlevel[5] = {5, 30, 50, 70, 90};                                                                                         // levels of battery to check against

    // set the battery icon by checking all sections
    for (int i = 0; i < 5 && batt.percent >= battlevel[i]; i++)
    {
        *display |= 1 << (i + 24);
    }

    // set the number display
    if (batt.mode == 2) // volts
    {
        int voltage = batt.mlvolts; // used to modulo and find each digit

        // rounds up
        if (voltage % 10 >= 5)
        {
            voltage += 10;
        }
        voltage /= 10;

        for (int i = 14; i >= 0; i -= 7)
        {
            *display |= nums[voltage / count] << (i + 3);
            voltage %= count;
            count /= 10;
        }
        // set the units
        *display |= 0b110;
    }
    else // percent
    {
        int percent = (batt.percent); // used for modulo to find each digit
        int nonzero = 0;              // flag used to know when there is no longer a leading 0
        for (int i = 14; i >= 0; i -= 7)
        {
            if (count > 0 && (percent / count != 0 || nonzero == 1))
            {
                *display |= nums[percent / count] << (i + 3);
                percent %= count;
                nonzero = 1;
            }
            count /= 10;
        }
        if (!nonzero) // if percent is 0
        {
            *display |= nums[0] << 3;
        }
        // set the units
        *display |= 0b001;
    }
    return 0;
}