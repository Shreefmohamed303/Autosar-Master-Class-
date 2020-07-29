/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/29/2020 04:29 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


#define MULTI_STATE_BTN_MINUS			
#define MULTI_STATE_BTN_PLUS			

			
#define MOTOR_STEP_MINUS			
#define MOTOR_STEP_PLUS		

#define SENSOR_POSITION_STEP_0
#define SENSOR_POSITION_STEP_1
#define SENSOR_POSITION_STEP_2
#define SENSOR_POSITION_STEP_3



static boolean IsMotorAdjustNeeded (SensorPositionType Position, SensorWeightType Weight, StepMotorStepType *Step)
{
	boolean adjustMotor = FALSE;
	
	switch(Position)
	{
		case SENSOR_POSITION_STEP_0 : 
			if(Weight > 60)
			{
				Step = MOTOR_STEP_PLUS; 
				adjustMotor = TRUE;
			}
			else 
			{
				/* Position is OK --> (Weight <= 60) */
			}
			break; 
		case SENSOR_POSITION_STEP_1 : 
			if(Weight > 80)
			{
				Step = MOTOR_STEP_PLUS; 
				adjustMotor = TRUE;
			}
			else if (Weight <= 80 && Weight >= 60)
			{
				/* Position is OK --> (Weight 80:60)*/
			}
			else
			{
				/* Weight < 60 */ 
				Step = MOTOR_STEP_MINUS; 
				adjustMotor = TRUE;
			}
			break; 
		case SENSOR_POSITION_STEP_2 : 
			if(Weight > 100)
			{
				Step = MOTOR_STEP_PLUS; 
				adjustMotor = TRUE;
			}
			else if (Weight <= 100 && Weight >= 80)
			{
				/* Position is OK --> (Weight 100:80) */
			}
			else
			{
				/* Weight < 80 */ 
				Step = MOTOR_STEP_MINUS; 
				adjustMotor = TRUE;
			}
			break;
		case SENSOR_POSITION_STEP_3 : 
			if(Weight < 100)
			{
				Step = MOTOR_STEP_MINUS; 
				adjustMotor = TRUE;
			}
			else 
			{
				/* Position is OK --> (Weight > 100) */
			}
			break; 			
	}
	
	return adjustMotor;
}

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType Step;
	boolean adjustMotor;
	
	/* Server Call Points */
	(void)Rte_Call_rpHeightSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	
	if(adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType Step;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_GetPosition(&Position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	
	if(adjustMotor)
	{
		(void)Rte_Call_rpInclineMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType Step;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&Position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	
	if(adjustMotor)
	{
		(void)Rte_Call_rpSlideMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		/* Server Call Points */
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
}

