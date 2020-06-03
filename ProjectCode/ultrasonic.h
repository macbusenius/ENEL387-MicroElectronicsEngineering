/******************************************************************************
 * Name:    		Ultrasonic.h
 * Description: Header File
 * Version: 		Version 1.00
 * Authors: 		Gunjeet Dhaliwal | Mckenzie Busenius
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *          
 *****************************************************************************/

#include <stdint.h>

// Functions for public use
uint32_t start_ultra(void);
int delay1(int);
void high(void);
void low(void);
