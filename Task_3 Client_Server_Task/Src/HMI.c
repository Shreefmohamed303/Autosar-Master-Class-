/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/27/2020 09:32 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"



#define MULTI_STATE_BTN_INIT			
#define MULTI_STATE_BTN_MINUS			
#define MULTI_STATE_BTN_PLUS			

static MultiStateBtnType HMI_updateBtnState(uint8 BtnData);

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	boolean isUpdated;
	
	/* Operating on Height Data Element */ 
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_Height();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		HeightBtnState = HMI_updateBtnState(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}
	else
	{
		Height = 0;
		HeightBtnState = HMI_updateBtnState(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}
	
	/* Operating on Slide Data Element */ 
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_Slide();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		SlideBtnState = HMI_updateBtnState(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}
	else
	{
		Slide = 0;
		SlideBtnState = HMI_updateBtnState(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}

	/* Operating on Incline Data Element */ 
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_Incline();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		InclinceBtnState = HMI_updateBtnState(Incline);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}
	else
	{
		Incline = 0;
		InclinceBtnState = HMI_updateBtnState(Incline);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}
}



static MultiStateBtnType HMI_updateBtnState(uint8 BtnData)
{
	MultiStateBtnType BtnState;
	if(BtnData==0)
	{
		BtnState = MULTI_STATE_BTN_INIT; 
	}
	else if (BtnData==1)
	{
		BtnState = MULTI_STATE_BTN_MINUS; 
	}
	else if(BtnData==2)
	{
		BtnState = MULTI_STATE_BTN_PLUS; 
	}
	else
	{
		BtnState = MULTI_STATE_BTN_INIT; 
	}
	
	return BtnState;
}

