/******************************************************************************
 * Name:    		TempSensor.h
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

//Functions available for public use
uint32_t ADCreadT(void);
void reg_out(uint32_t);
