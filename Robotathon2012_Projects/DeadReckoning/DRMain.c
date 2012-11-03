#include "inc/hw_types.h"		// tBoolean
#include "RASDemo.h"
#include "utils/uartstdio.h"	// input/output over UART
#include "driverlib/uart.h"		// input/output over UART
#include "RASLib/init.h"
#include "RASLib/motor.h"

void balanceMotors(signed int l, signed int r);

int main(void)
{		  	 
	signed int l=126, r=126;
	LockoutProtection();
	InitializeMCU();
	initUART();		   
	InitializeMotors(true, false);
	InitializeEncoders(false,false);
	//setmotorpowers													
	//move forward 4 feet
	//brake
	//turn
	//brake
	while(1)
	{
		UARTprintf("go forward");
		goForward();
		wait(1000);
		brake();
		UARTprintf("turn left");
		turnLeft();
		wait(1000);
		brake();
		goForward();
		wait(1000);
		brake();
		UARTprintf("Done");
	}
//	while(1)
//	{			
//																			   
//		//SetMotorPowers(-40,126);
//		balanceMotors(l,r);	
//		UARTprintf("%d\n%d\n",l,r);
//	}																	
}
  	