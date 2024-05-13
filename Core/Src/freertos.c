/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticSemaphore_t osStaticSemaphoreDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define XJWY_StdId							0x01
#define GPS_StdId								0x02
#define DTU_StdId								0x04       //0x03,0x04     csq
#define CLK_StdId								0x03       //0x03,0x04     clk
#define Tyre_StdId              0x08
#define CLK_StdId2						  0x13       //0x03,0x04     clk
#define OADC_StdId              0x05       
#define Wit_StdId   						0x51      //0x51,0x52,0x53   angle acc

#define XJWY_DLC								7
#define GPS_DLC									4
#define CLK_DLC									6
#define Wit_DLC									8
#define Tyre_DLC								8
#define Oadc_DLC								2


#define CAN_EVENTBIT_0	(1<<0)				//
#define CAN_EVENTBIT_1	(1<<1)				//
#define CAN_EVENTBIT_2	(1<<2)				
#define CAN_EVENTBIT_3	(1<<3)				
#define CAN_EVENTBIT_4	(1<<4)
#define CAN_EVENTBIT_5	(1<<5)

#define CANTX_EVENTBIT_0	(1<<0)
#define CANTX_EVENTBIT_1	(1<<1)				
#define CANTX_EVENTBIT_2	(1<<2)				
#define CANTX_EVENTBIT_3	(1<<3)				
#define CANTX_EVENTBIT_4	(1<<4)


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
extern IWDG_HandleTypeDef hiwdg;
extern ADC_HandleTypeDef hadc1;
extern CAN_HandleTypeDef hcan1;
extern __IO uint8_t temADC1_Flag;
extern uint32_t adc_value[10]; 
extern RTC_HandleTypeDef hrtc;
CAN_RxHeaderTypeDef RxMessage;
CAN_TxHeaderTypeDef TxMessage;
uint8_t canrx_dat[8] = {0};

uint8_t CpuTpQueue_prio = 5;


typedef union 
{
	float value;
	uint8_t data[4];
}speed_float;


typedef union
{
	float value;
	uint8_t data[4];
}Anglefloat;

typedef union
{
	float value;
	uint8_t data[4];
}Accfloat;

typedef struct{
	uint8_t dtu_flag;
	uint8_t xjwy_data[XJWY_DLC];
	uint8_t tyre_data[Tyre_DLC];
	uint8_t dtu_tdata[CLK_DLC];
	uint8_t dtu_cdata;
	uint8_t oadc_dat[Oadc_DLC];
	Anglefloat Ag_data[3];
	Accfloat   Acc_data[3];
	speed_float gps_data;
}can_rxdata;

uint8_t rtc_sure = 0;

can_rxdata Can_rxdata1 = {0,{0},0,{0},0,{0},{0}};
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

void TpNum(uint8_t tpdat);
void GpsNum(double gpsdat);
void WitNum(float *witdat1,float *witdat2);
void CanNum(uint8_t canflag);
void ADC1_Num(uint8_t *adc1dat);
void ADC2_Num(uint8_t *adc2dat);
void RtcNum(uint8_t rtcyear,uint8_t rtcmonth,uint8_t rtcdate,uint8_t rtchour,uint8_t rtcminute);
void DTU_C_Num(uint8_t csqdat);
void Can_Send_Msg(uint32_t ucStdId, uint8_t* msg, uint32_t len);
void Tyre_Num(uint8_t *tyre_dat);
void Updattim(void);

/* USER CODE END Variables */
/* Definitions for touchGFX */
osThreadId_t touchGFXHandle;
const osThreadAttr_t touchGFX_attributes = {
  .name = "touchGFX",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Can_Rx_Task */
osThreadId_t Can_Rx_TaskHandle;
uint32_t Can_Rx_TaskBuffer[ 256 ];
osStaticThreadDef_t Can_Rx_TaskControlBlock;
const osThreadAttr_t Can_Rx_Task_attributes = {
  .name = "Can_Rx_Task",
  .cb_mem = &Can_Rx_TaskControlBlock,
  .cb_size = sizeof(Can_Rx_TaskControlBlock),
  .stack_mem = &Can_Rx_TaskBuffer[0],
  .stack_size = sizeof(Can_Rx_TaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Atemperature */
osThreadId_t AtemperatureHandle;
const osThreadAttr_t Atemperature_attributes = {
  .name = "Atemperature",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for IWDG_Task */
osThreadId_t IWDG_TaskHandle;
const osThreadAttr_t IWDG_Task_attributes = {
  .name = "IWDG_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Speed_Task */
osThreadId_t Speed_TaskHandle;
const osThreadAttr_t Speed_Task_attributes = {
  .name = "Speed_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow2,
};
/* Definitions for Wit_task */
osThreadId_t Wit_taskHandle;
const osThreadAttr_t Wit_task_attributes = {
  .name = "Wit_task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for ADC1_Task */
osThreadId_t ADC1_TaskHandle;
const osThreadAttr_t ADC1_Task_attributes = {
  .name = "ADC1_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow5,
};
/* Definitions for ADC2_Task */
osThreadId_t ADC2_TaskHandle;
const osThreadAttr_t ADC2_Task_attributes = {
  .name = "ADC2_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for RTC_Task */
osThreadId_t RTC_TaskHandle;
const osThreadAttr_t RTC_Task_attributes = {
  .name = "RTC_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for DTU_Task */
osThreadId_t DTU_TaskHandle;
const osThreadAttr_t DTU_Task_attributes = {
  .name = "DTU_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Cantx_Task */
osThreadId_t Cantx_TaskHandle;
const osThreadAttr_t Cantx_Task_attributes = {
  .name = "Cantx_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for TyrespTask */
osThreadId_t TyrespTaskHandle;
const osThreadAttr_t TyrespTask_attributes = {
  .name = "TyrespTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow4,
};
/* Definitions for BspInitTask */
osThreadId_t BspInitTaskHandle;
const osThreadAttr_t BspInitTask_attributes = {
  .name = "BspInitTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for CanBinarySem */
osSemaphoreId_t CanBinarySemHandle;
osStaticSemaphoreDef_t CanBinarySemControlBlock;
const osSemaphoreAttr_t CanBinarySem_attributes = {
  .name = "CanBinarySem",
  .cb_mem = &CanBinarySemControlBlock,
  .cb_size = sizeof(CanBinarySemControlBlock),
};
/* Definitions for CAN_DatEvent */
osEventFlagsId_t CAN_DatEventHandle;
const osEventFlagsAttr_t CAN_DatEvent_attributes = {
  .name = "CAN_DatEvent"
};
/* Definitions for Can_TxEvent */
osEventFlagsId_t Can_TxEventHandle;
const osEventFlagsAttr_t Can_TxEvent_attributes = {
  .name = "Can_TxEvent"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void TouchGFX_Task(void *argument);
void Can_Rx_Handle(void *argument);
void temAdc_Handle(void *argument);
void IWDG_Handle(void *argument);
void Speed_Handle(void *argument);
void Wit_DatHandle(void *argument);
void ADC1_Handle(void *argument);
void ADC2_Handle(void *argument);
void RTC_Handle(void *argument);
void Dtu_datHandle(void *argument);
void CanTX_Handle(void *argument);
void Tyresp_Handle(void *argument);
void BspInit_Handle(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of CanBinarySem */
  CanBinarySemHandle = osSemaphoreNew(1, 1, &CanBinarySem_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of touchGFX */
  touchGFXHandle = osThreadNew(TouchGFX_Task, NULL, &touchGFX_attributes);

  /* creation of Can_Rx_Task */
  Can_Rx_TaskHandle = osThreadNew(Can_Rx_Handle, NULL, &Can_Rx_Task_attributes);

  /* creation of Atemperature */
  AtemperatureHandle = osThreadNew(temAdc_Handle, NULL, &Atemperature_attributes);

  /* creation of IWDG_Task */
  IWDG_TaskHandle = osThreadNew(IWDG_Handle, NULL, &IWDG_Task_attributes);

  /* creation of Speed_Task */
  Speed_TaskHandle = osThreadNew(Speed_Handle, NULL, &Speed_Task_attributes);

  /* creation of Wit_task */
  Wit_taskHandle = osThreadNew(Wit_DatHandle, NULL, &Wit_task_attributes);

  /* creation of ADC1_Task */
  ADC1_TaskHandle = osThreadNew(ADC1_Handle, NULL, &ADC1_Task_attributes);

  /* creation of ADC2_Task */
  ADC2_TaskHandle = osThreadNew(ADC2_Handle, NULL, &ADC2_Task_attributes);

  /* creation of RTC_Task */
  RTC_TaskHandle = osThreadNew(RTC_Handle, NULL, &RTC_Task_attributes);

  /* creation of DTU_Task */
  DTU_TaskHandle = osThreadNew(Dtu_datHandle, NULL, &DTU_Task_attributes);

  /* creation of Cantx_Task */
  Cantx_TaskHandle = osThreadNew(CanTX_Handle, NULL, &Cantx_Task_attributes);

  /* creation of TyrespTask */
  TyrespTaskHandle = osThreadNew(Tyresp_Handle, NULL, &TyrespTask_attributes);

  /* creation of BspInitTask */
  BspInitTaskHandle = osThreadNew(BspInit_Handle, NULL, &BspInitTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the event(s) */
  /* creation of CAN_DatEvent */
  CAN_DatEventHandle = osEventFlagsNew(&CAN_DatEvent_attributes);

  /* creation of Can_TxEvent */
  Can_TxEventHandle = osEventFlagsNew(&Can_TxEvent_attributes);

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_TouchGFX_Task */
/**
  * @brief  Function implementing the touchGFX thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_TouchGFX_Task */
__weak void TouchGFX_Task(void *argument)
{
  /* USER CODE BEGIN TouchGFX_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(100);
  }
  /* USER CODE END TouchGFX_Task */
}

/* USER CODE BEGIN Header_Can_Rx_Handle */
/**
* @brief Function implementing the Can_Rx_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Can_Rx_Handle */
void Can_Rx_Handle(void *argument)
{
  /* USER CODE BEGIN Can_Rx_Handle */
  /* Infinite loop */
	static uint32_t can_tick = 0;
	static uint8_t can_error = 0;
  for(;;)
  {
		osSemaphoreAcquire(CanBinarySemHandle,1600);
		if( uwTick-can_tick > 1500){
			can_error = 0;
		}else{
			can_error = 1;
		}
		CanNum(can_error);
		can_tick = uwTick;
    osDelay(1);
  }
  /* USER CODE END Can_Rx_Handle */
}

/* USER CODE BEGIN Header_temAdc_Handle */
/**
* @brief Function implementing the Atemperature thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_temAdc_Handle */
void temAdc_Handle(void *argument)
{
  /* USER CODE BEGIN temAdc_Handle */
  /* Infinite loop */
	uint8_t i = 0;
	double temadc_dat = 0;
	uint8_t temperature = 0;
	
  for(;;)
  {
		if(temADC1_Flag == 1)
		{
			for( i = 1; i<10 ; i++){
				adc_value[0]+=adc_value[i];
			}
			temadc_dat = (double)(adc_value[0]*3.3/40960);
//			printf("ADC : %.2f v\r\n",temadc_dat);
			temperature = (uint8_t)((temadc_dat-0.76)/0.0025)+25;
//			printf("MCU Temperature : %d\r\n",temperature);
			TpNum(temperature);
			temADC1_Flag = 0;
			HAL_ADC_Start_DMA(&hadc1,adc_value,sizeof(adc_value)/4);
		}
    osDelay(1000);
  }
  /* USER CODE END temAdc_Handle */
}

/* USER CODE BEGIN Header_IWDG_Handle */
/**
* @brief Function implementing the IWDG_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_IWDG_Handle */
void IWDG_Handle(void *argument)
{
  /* USER CODE BEGIN IWDG_Handle */
  /* Infinite loop */
  for(;;)
  {		
		__HAL_IWDG_RELOAD_COUNTER(&hiwdg);
    osDelay(100);
  }
  /* USER CODE END IWDG_Handle */
}

/* USER CODE BEGIN Header_Speed_Handle */
/**
* @brief Function implementing the Speed_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Speed_Handle */
void Speed_Handle(void *argument)
{
  /* USER CODE BEGIN Speed_Handle */
  /* Infinite loop */
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_1,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_1){
			GpsNum(Can_rxdata1.gps_data.value);
		}
  }
  /* USER CODE END Speed_Handle */
}

/* USER CODE BEGIN Header_Wit_DatHandle */
/**
* @brief Function implementing the Wit_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Wit_DatHandle */
void Wit_DatHandle(void *argument)
{
  /* USER CODE BEGIN Wit_DatHandle */
  /* Infinite loop */
  float ag_xyz[3] = {0},acc_xyz[3] = {0};
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_3,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_3){
			ag_xyz[0] = Can_rxdata1.Ag_data[0].value;
			ag_xyz[1] = Can_rxdata1.Ag_data[1].value;
			ag_xyz[2] = Can_rxdata1.Ag_data[2].value;
//			printf("angle:%.3f %.3f %.3f\r\n", ag_xyz[0], ag_xyz[1], ag_xyz[2]);
			acc_xyz[0] = Can_rxdata1.Acc_data[0].value;
			acc_xyz[1] = Can_rxdata1.Acc_data[1].value;
			acc_xyz[2] = Can_rxdata1.Acc_data[2].value;
//			printf("acc:%.3f %.3f %.3f\r\n", acc_xyz[0], acc_xyz[1], acc_xyz[2]);
			WitNum(ag_xyz,acc_xyz);
		}
  }
  /* USER CODE END Wit_DatHandle */
}

/* USER CODE BEGIN Header_ADC1_Handle */
/**
* @brief Function implementing the ADC1_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ADC1_Handle */
void ADC1_Handle(void *argument)
{
  /* USER CODE BEGIN ADC1_Handle */
  /* Infinite loop */
	uint8_t xjwydat[XJWY_DLC] = {0};
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_0,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_0){
			for(uint8_t i = 0;i<XJWY_DLC;i++)
			{
				xjwydat[i] = Can_rxdata1.xjwy_data[i];
			}
			ADC1_Num(xjwydat);
		}
    osDelay(10);
  }
  /* USER CODE END ADC1_Handle */
}

/* USER CODE BEGIN Header_ADC2_Handle */
/**
* @brief Function implementing the ADC2_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ADC2_Handle */
void ADC2_Handle(void *argument)
{
  /* USER CODE BEGIN ADC2_Handle */
  /* Infinite loop */
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_4,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_4){
		ADC2_Num(Can_rxdata1.oadc_dat);
		}
    osDelay(100);
  }
  /* USER CODE END ADC2_Handle */
}

/* USER CODE BEGIN Header_RTC_Handle */
/**
* @brief Function implementing the RTC_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_RTC_Handle */
void RTC_Handle(void *argument)
{
  /* USER CODE BEGIN RTC_Handle */
  /* Infinite loop */
	RTC_TimeTypeDef rtcTime;
  RTC_DateTypeDef GetData;   //获取日期结构	
  for(;;)
  {
		HAL_RTC_GetTime(&hrtc,&rtcTime,RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc,&GetData,RTC_FORMAT_BIN);
		RtcNum(GetData.Year,GetData.Month,GetData.Date,rtcTime.Hours,rtcTime.Minutes);
//		printf("      %02d-%02d-%02d\r\n",rtcTime.Hours,rtcTime.Minutes,rtcTime.Seconds);
    osDelay(500);
  }
  /* USER CODE END RTC_Handle */
}

/* USER CODE BEGIN Header_Dtu_datHandle */
/**
* @brief Function implementing the DTU_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Dtu_datHandle */
void Dtu_datHandle(void *argument)
{
  /* USER CODE BEGIN Dtu_datHandle */
  /* Infinite loop */
	RTC_TimeTypeDef SetTime;
	RTC_DateTypeDef SetData;
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_2,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_2){
			if(Can_rxdata1.dtu_flag == 1){
				Can_rxdata1.dtu_flag = 2;
				SetData.Year = Can_rxdata1.dtu_tdata[0];
				SetData.Month = Can_rxdata1.dtu_tdata[1];
				SetData.Date = Can_rxdata1.dtu_tdata[2];
				SetTime.Hours = Can_rxdata1.dtu_tdata[3];
				SetTime.Minutes = Can_rxdata1.dtu_tdata[4];
				SetTime.Seconds = Can_rxdata1.dtu_tdata[5];
				HAL_RTC_SetDate(&hrtc,&SetData,RTC_FORMAT_BIN);
				HAL_RTC_SetTime(&hrtc,&SetTime,RTC_FORMAT_BIN);
				HAL_RTC_DST_Add1Hour(&hrtc);
				rtc_sure = 1;
				osEventFlagsSet(Can_TxEventHandle,CANTX_EVENTBIT_0);
				Updattim();
			}else if(Can_rxdata1.dtu_flag == 2){
				DTU_C_Num(Can_rxdata1.dtu_cdata);
			}
		}
  }
  /* USER CODE END Dtu_datHandle */
}

/* USER CODE BEGIN Header_CanTX_Handle */
/**
* @brief Function implementing the Cantx_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CanTX_Handle */
void CanTX_Handle(void *argument)
{
  /* USER CODE BEGIN CanTX_Handle */
  /* Infinite loop */
	
	uint32_t can_tx_mailbox;
	TxMessage.ExtId=0;
	TxMessage.IDE=CAN_ID_STD;
	TxMessage.RTR=CAN_RTR_DATA;
	TxMessage.TransmitGlobalTime=DISABLE;
	uint8_t canovertime = 0;
  for(;;)
  {
		if(osEventFlagsWait (Can_TxEventHandle,CANTX_EVENTBIT_0,osFlagsWaitAny, NULL)&CANTX_EVENTBIT_0){
			canovertime = 0;
			TxMessage.StdId=CLK_StdId2;
			TxMessage.DLC=sizeof(rtc_sure);
			while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) < 1){
				if(canovertime++ >= 5){
					break;
				}
				else{
					osDelay(1);	
				}
			}
			if(HAL_CAN_AddTxMessage(&hcan1,&TxMessage,&rtc_sure,&can_tx_mailbox) != HAL_OK)
			{
				printf ("数据发送失败！\r\n");
			}
			osDelay(1);			
		}
		osDelay(1);
  }
  /* USER CODE END CanTX_Handle */
}

/* USER CODE BEGIN Header_Tyresp_Handle */
/**
* @brief Function implementing the TyrespTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Tyresp_Handle */
void Tyresp_Handle(void *argument)
{
  /* USER CODE BEGIN Tyresp_Handle */
  /* Infinite loop */
	uint8_t tyre_dat[8] = {0};
  for(;;)
  {
		if(osEventFlagsWait (CAN_DatEventHandle, CAN_EVENTBIT_5,osFlagsWaitAny, osWaitForever)&CAN_EVENTBIT_5){
			for(uint8_t i = 0;i<Tyre_DLC;i++)
			{
				tyre_dat[i] = Can_rxdata1.tyre_data[i];
			}
			Tyre_Num(tyre_dat);
		}
    osDelay(10);
  }
  /* USER CODE END Tyresp_Handle */
}

/* USER CODE BEGIN Header_BspInit_Handle */
/**
* @brief Function implementing the BspInitTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BspInit_Handle */
void BspInit_Handle(void *argument)
{
  /* USER CODE BEGIN BspInit_Handle */
  /* Infinite loop */
  for(;;)
  {
		HAL_ADC_Start_DMA(&hadc1,adc_value,sizeof(adc_value)/4);
		HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING|CAN_IT_TX_MAILBOX_EMPTY);
		HAL_CAN_Start(&hcan1);
		vTaskDelete(BspInitTaskHandle);
  }
  /* USER CODE END BspInit_Handle */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	uint8_t i = 0;
	if(hcan->Instance == CAN1)
	{
		RxMessage.StdId=0x00;
		RxMessage.ExtId=0x00;
		RxMessage.IDE=0;
		RxMessage.DLC=0;
		RxMessage.RTR=0;
		RxMessage.Timestamp=0;
		RxMessage.FilterMatchIndex = 0;
//		printf("can_receive!\r\n");
		for(i = 0; i < 8; i++)
		{
			canrx_dat[i]=0x00;
		}
		HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0,&RxMessage,canrx_dat);
		switch(RxMessage.StdId)
		{
			case(XJWY_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==XJWY_DLC)){
					for(i = 0;i<XJWY_DLC;i++){
						Can_rxdata1.xjwy_data[i] = canrx_dat[i];
					}
//					printf("XJWY!\r\n");
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_0);
				}
				break;
			}
			case(GPS_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==GPS_DLC)){
					for(i = 0;i<GPS_DLC;i++){
						Can_rxdata1.gps_data.data[i] = canrx_dat[i];
					}
//					printf("GPSspeed = %f!\r\n",Can_rxdata1.gps_data.value);
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_1);
				}
				break;
			}
			case(CLK_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==CLK_DLC)){
					for(i = 0;i<CLK_DLC;i++){
						Can_rxdata1.dtu_tdata[i] = canrx_dat[i];
//						printf("%d\r\n",Can_rxdata1.dtu_tdata[i]);
					}
					Can_rxdata1.dtu_flag = 1;
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_2);
				}
				break;
			}
			case(DTU_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==1)){
					Can_rxdata1.dtu_cdata = canrx_dat[0];
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_2);
//					printf("DTU2!\r\n");
				}
				break;
			}
			case(Wit_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==Wit_DLC)){
					for(i = 0;i<Wit_DLC;i++){
						if(i<4){
							Can_rxdata1.Ag_data[0].data[i] = canrx_dat[i];
						}else{
							Can_rxdata1.Ag_data[1].data[i-4] = canrx_dat[i];
						}
					}
//					printf("Wit1!\r\n");
				}
				break;
			}
			case(Wit_StdId+1):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==Wit_DLC)){
					for(i = 0;i<Wit_DLC;i++){
						if(i<4){
							Can_rxdata1.Ag_data[2].data[i] = canrx_dat[i];
						}else{
							Can_rxdata1.Acc_data[0].data[i-4] = canrx_dat[i];
						}
					}	
//					printf("Wit2!\r\n");
				}
				break;
			}
			case(Wit_StdId+2):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==Wit_DLC)){
					for(i = 0;i<Wit_DLC;i++){
						if(i<4){
							Can_rxdata1.Acc_data[1].data[i] = canrx_dat[i];
						}else{
							Can_rxdata1.Acc_data[2].data[i-4] = canrx_dat[i];
						}
					}
//					printf("Wit3!\r\n");
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_3);
				}
				break;
			}
			case(OADC_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==Oadc_DLC)){
					for(i = 0;i<Oadc_DLC;i++){
						Can_rxdata1.oadc_dat[i] = canrx_dat[i];
					}
//					printf("OADC!\r\n");
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_4);
				}
				break;
			}		
			case(Tyre_StdId):{
				if((RxMessage.IDE==CAN_ID_STD) && (RxMessage.DLC==Tyre_StdId)){
					for(i = 0;i<Tyre_DLC;i++){
						Can_rxdata1.tyre_data[i] = canrx_dat[i];
					}
//				printf("TYRE!\r\n");
					osEventFlagsSet ( CAN_DatEventHandle, CAN_EVENTBIT_5);
				}
				break;
			}				
			default:
				break;
		}
		osSemaphoreRelease(CanBinarySemHandle);
	}
}

/* USER CODE END Application */

