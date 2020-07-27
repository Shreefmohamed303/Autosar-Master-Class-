/**
 *
 * \file SeatManger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/22/2020 03:24 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManger.h"

			
#define MULTI_STATE_BTN_MINUS			
#define MULTI_STATE_BTN_PLUS			

			
#define MOTOR_STEP_MINUS			
#define MOTOR_STEP_PLUS			


/**
 *
 * Runnable SeatManger_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtn_DE_HeightBtnState
 *
 */

void SeatManger_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtn_DE_HeightBtnState(&DE_HeightBtnState);
	
	if(DE_HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		 Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		 Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
}


/**
 *
 * Runnable SeatManger_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtn_DE_InclinceBtnState
 *
 */

void SeatManger_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_InclinceBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtn_DE_InclinceBtnState(&DE_InclinceBtnState);
	
	if(DE_InclinceBtnState == MULTI_STATE_BTN_MINUS)
	{
		 Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		 Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}
}


/**
 *
 * Runnable SeatManger_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtn_DE_SlideBtnState
 *
 */

void SeatManger_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtn_DE_SlideBtnState(&DE_SlideBtnState);
	
	if(DE_SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		 Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		 Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
}

