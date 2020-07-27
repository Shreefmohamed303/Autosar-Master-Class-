/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/22/2020 03:24 AM
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
	MultiStateBtnType DE_HeightBtnState;
	MultiStateBtnType DE_InclinceBtnState;
	MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Height;
	uint8 DE_Incline;
	uint8 DE_Slide;
	bool isUpdated; 
	
	/* Operating on Height Data Element */ 
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_DE_Height();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		DE_HeightBtnState = HMI_updateBtnState(DE_Height);
		(void)Rte_Write_ppSeatCtrlBtn_DE_HeightBtnState(DE_HeightBtnState);
	}
	else
	{
		DE_Height = 0;
		DE_HeightBtnState = HMI_updateBtnState(DE_Height);
		(void)Rte_Write_ppSeatCtrlBtn_DE_HeightBtnState(DE_HeightBtnState);
	}

	/* Operating on Incline Data Element */ 
	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_DE_Incline();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		DE_InclinceBtnState = HMI_updateBtnState(DE_Incline);
		(void)Rte_Write_ppSeatCtrlBtn_DE_InclinceBtnState(DE_InclinceBtnState);
	}
	else
	{
		DE_Incline = 0;
		DE_InclinceBtnState = HMI_updateBtnState(DE_Incline);
		(void)Rte_Write_ppSeatCtrlBtn_DE_InclinceBtnState(DE_InclinceBtnState);
	}

	/* Operating on Slide Data Element */ 
	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	isUpdated = Rte_isUpdated_rpSeatCtrlData_DE_Slide();
	if(status == RTE_E_OK && isUpdated == TRUE)
	{
		DE_SlideBtnState = HMI_updateBtnState(DE_Slide);
		(void)Rte_Write_ppSeatCtrlBtn_DE_SlideBtnState(DE_SlideBtnState);
	}
	else
	{
		DE_Slide = 0;
		DE_SlideBtnState = HMI_updateBtnState(DE_Slide);
		(void)Rte_Write_ppSeatCtrlBtn_DE_SlideBtnState(DE_SlideBtnState);
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
