#include "inc/hw_types.h"		// tBoolean
#include "inc/hw_memmap.h"
#include "utils/uartstdio.h"	// input/output over UART
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "RASLib/encoder.h"

#include "RASDemo.h"

void initEncoders(void) {
	InitializeEncoders(false, false);
}


void encoderDemo(void) 
{
	signed long encoder0, encoder1, counter = 0;
	PresetEncoderCounts(0, 0);
	while(1) 
	{	  
		
		counter++;
	}
}
