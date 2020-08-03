/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/29/2020 06:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/* For reading from position sensor */
#include "Adc.h"

/* For reading from Weight sensor */
#include "Spi.h"

/* For Driving Motor (Height, Slide, Incline) */
#include "Dio.h"

/* Global Array to Save Sensors Readings coming from Adc */ 
static Adc_ValueGroupType IoHwAbs_PositionSensorsReadings[ADC_GR0_NUM_CHANNELS] = 
{
	/* Height */ 
	0,
	/* Slide */ 
	0,
	/* Incline */ 
	0
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionSensorsGrp, IoHwAbs_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[0]; 
	}
	else
	{
		/* should be updated to return failure Error */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionSensorsGrp, IoHwAbs_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[2]; 
	}
	else
	{
		/* should be updated to return failure Error */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionSensorsGrp, IoHwAbs_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[1]; 
	}
	else
	{
		/* should be updated to return failure Error */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType SpiData ;
	
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &SpiData);
	
	if(status == E_OK)
	{
		weight =  (IoWeightSensorReadingType) SpiData;
	}
	else
	{
		/* should be updated to return failure Error */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	Std_ReturnType status;
	/* Write High to move Forward */ 
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH)
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	Std_ReturnType status;
	/* Write High to move Forward */ 
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH)
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	Std_ReturnType status;
	/* Write High to move Forward */ 
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH)
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Std_ReturnType status;
		/* Write low to move reverse */ 
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW)
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Std_ReturnType status;
	/* Write low to move reverse */ 
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW)
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Std_ReturnType status;
	/* Write low to move reverse */ 
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW)
}

