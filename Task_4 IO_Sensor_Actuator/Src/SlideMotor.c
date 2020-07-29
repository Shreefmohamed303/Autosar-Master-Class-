/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/29/2020 06:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;
	
	if(Step == MOTOR_STEP_PLUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		(void)Rte_Call_rpIOSetSlide_IOSetReverse();
	}
	else
	{
		/* Do Nothing */
	}	
}

