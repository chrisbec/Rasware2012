#include "inc/hw_types.h"		// tBoolean
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "utils/uartstdio.h"	// input/output over UART
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

#include "RASLib/motor.h"
#include "RASLib/encoder.h"

#include "RASDemo.h"

int is_timeout;


void balanceMotors(signed int l, signed int r);

void initMotors(tBoolean a, tBoolean b) {
	InitializeMotors(a,b);
	
		//initialize timer
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
	TimerConfigure(TIMER2_BASE, TIMER_CFG_32_BIT_OS);

	IntEnable(INT_TIMER2A);
	TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

	IntMasterEnable();
}

void timerHandler() {
	TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
	is_timeout = true;
}

void balanceMotors(signed int l, signed int r)
{
	signed long encoder0, encoder1;
	encoder0 = GetEncoderCount(ENCODER_0);	 
	encoder1 = GetEncoderCount(ENCODER_1);
	GetEncoderCounts(&encoder0, &encoder1);
	
	  // starts timer
	is_timeout = false;
	TimerLoadSet(TIMER2_BASE, TIMER_A, 1000);
  TimerEnable(TIMER2_BASE, TIMER_A);
	
	while(!is_timeout)//encoder0!=encoder1)
	{
		if(encoder0<encoder1)
		{
			if(l<0)
			{
				SetMotorPowers(++l,r);
			}
			else
			{
				SetMotorPowers(--l,r);
			}
		}
		else 
		{
			if(l<0)
			{
				SetMotorPowers(l,++r);
			}
			else
			{
				SetMotorPowers(l,--r);
			}
		}
		encoder0 = GetEncoderCount(ENCODER_0);	 
		encoder1 = GetEncoderCount(ENCODER_1);
	}
}
		   
void brake(void)
{
	SetMotorPowers(0,0);
}

void turnLeft(void)
{
	SetMotorPowers(-50,50);
}

void turnRight(void)
{
	SetMotorPowers(50,-50);
}

void goForward(void)
{
	SetMotorPowers(126,126);
	balanceMotors(126,126);	
}

void goBackward(void)
{
	SetMotorPowers(-126,-126);
	balanceMotors(-126,-126);
}

void wait(signed int i)
{
	signed int c = 0;
	while(c<i)
	{
		c++;
	}
}

//void motorDemo(void) 
//{
//	{
//		// values should range between -128 and 127?
//		while(1) 
//		{
//			left = maxSpeed;
//			right = -maxSpeed;
//			SetMotorPowers(left, right);
//		}
//	}
//}
