#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>

#define ICONFONT_1  0xe61c
#define ICONFONT_2  0xe65e

extern "C" {
	void TpNum(uint8_t tpdat);
	void GpsNum(double gpsdat);
	void WitNum(float *witdat1,float *witdat2);
	void CanNum(uint8_t canflag);
	void ADC1_Num(uint8_t *adc1dat);
	void ADC2_Num(uint8_t *adc2dat);
	void RtcNum(uint8_t rtcyear,uint8_t rtcmonth,uint8_t rtcdate,uint8_t rtchour,uint8_t rtcminute);
	void DTU_C_Num(uint8_t csqdat);
	void Tyre_Num(uint8_t *tyre_dat);
	void Updattim(void);
}

DebugPrinter * dp2;
Screen1View  * screen1 = NULL;

Screen1View::Screen1View() : sp_num(0),tp_num(0),can_flag(0),xj_value1(0),\
														 xj_value2(0),xj_value3(0),xj_value4(0),rtc_year(0),\
														 rtc_month(0),rtc_day(0),rtc_hour(0),rtc_minute(0),\
														 rtc_second(0),gps_num(0),gps_memory(0)
{
	witdat1 = NULL;
	witdat2 = NULL;
	bra_num = 10.000;
	tmcount = 2500;
	xj_memory1 = 0;xj_memory2 = 0;xj_memory3 = 0;xj_memory4 = 0;xj_flag = 0;
	xAngle = 0;yAngle = 0;zAngle = 0;
	oxj_value = 4.7;
	xAcc = 0;yAcc = 0;zAcc = 0;
	gpsc = 0;
	for(uint8_t i = 0; i<4; i++){
		tyrenum[i] = 0;
	}
}

void Screen1View::setupScreen()
{
  Screen1ViewBase::setupScreen();
	screen1 = this;
		//显示图标
	can_statusBuffer[0] = ICONFONT_2;
	container_can.invalidate();
	Unicode::snprintf(speedvalueBuffer,SPEEDVALUE_SIZE,"%d",0);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
		screen1 = NULL;
}

void Screen1View::runAnimcar()
{
	static uint8_t acc_count = 0;
	acc_count++;
//	xAngle = witdat1[0]*PI/180;
//	yAngle = witdat1[1]*PI/180;
//	zAngle = witdat1[2]*PI/180;
	if(acc_count > 10){
		acc_count = 0;
		xAcc = witdat2[0];
		yAcc = witdat2[1];
		zAcc = witdat2[2];
		Unicode::snprintfFloat(ACC_XYBuffer1,ACC_XYBUFFER1_SIZE,"%2.3f",xAcc);
		Unicode::snprintfFloat(ACC_XYBuffer2,ACC_XYBUFFER2_SIZE,"%2.3f",yAcc);
		Unicode::snprintfFloat(ACC_ZBuffer,ACC_Z_SIZE,"%2.3f",zAcc);
		Three_acc.invalidate();
	}
//	textureMapper1.updateAngles(xAngle,yAngle,zAngle);
	textureMapper2.updateAngles(0,0,oxj_value);
}

void Screen1View::handleTickEvent()
{
	static uint16_t count = 0,gpscount = 0;
	uint8_t m = 0;
	
	runAnimcar();
	count++;
	tmcount++;
	gpscount++;
	if (count >= 50)
	{
		count = 0;
		Unicode::snprintf(tempdatBuffer,TEMPDAT_SIZE,"%d",tp_num);
		tp_value.invalidate();
		Unicode::snprintf(tyre12Buffer1, TYRE12BUFFER1_SIZE,"%d",tyrenum[0]);
		Unicode::snprintf(tyre12Buffer2, TYRE12BUFFER2_SIZE,"%d",tyrenum[1]);
		Unicode::snprintf(tyre34Buffer1, TYRE34BUFFER1_SIZE,"%d",tyrenum[2]);
		Unicode::snprintf(tyre34Buffer2, TYRE34BUFFER2_SIZE,"%d",tyrenum[3]);
		lunshu.invalidate();
		for(uint8_t i = 0;i<4;i++){
			if(tyrenum[i] == 0){
				m++;
			}
		}
		Unicode::snprintf(lsspeedBuffer, LSSPEED_SIZE,"%d",(tyrenum[0]+tyrenum[1]+tyrenum[2]+tyrenum[3])*3/(m*50));
		lscontainer.invalidate();
		m = 0;
		Unicode::snprintfFloat(brakempaBuffer,BRAKEMPA_SIZE,"%2.3f",bra_num);
		BHPressure.invalidate();
		if(can_flag){
			can_statusBuffer[0] = ICONFONT_1;
		}else{
			can_statusBuffer[0] = ICONFONT_2;
		}
		container_can.invalidate();
	}
	if(gpscount >= 45/gpsc)
	{
		gpscount = 0;
		Screen1speed();
	}
	if(tmcount >= 2500)
	{
		tmcount = 0;
		Unicode::snprintf(calendarBuffer,CALENDAR_SIZE,"%d.%d.%d",rtc_year+2000,rtc_month,rtc_day);
		digitalClock.setTime24Hour(rtc_hour,rtc_minute,rtc_second);
		//		if(rtc_hour >= 13)
		//		{
		//			digitalClock.setTime12Hour(rtc_hour,rtc_minute,rtc_second,0);
		//		}else{
		//			digitalClock.setTime12Hour(rtc_hour-12,rtc_minute,rtc_second,1);
		//		}
		timecontainer.invalidate();
	}
	dynamicGraph1.addDataPoint(xj_value1);
	dynamicGraph2.addDataPoint(xj_value2);
	dynamicGraph3.addDataPoint(xj_value3);
	dynamicGraph4.addDataPoint(xj_value4);
//	while(1){
//		if(xj_memory1 > xj_value1){
//			xj_memory1--;
//			dynamicGraph1.addDataPoint(xj_memory1);
//		}else if(xj_memory1 < xj_value1){
//			xj_memory1++;
//		}else{
//			xj_flag++;
//		}
//		if(xj_memory2 > xj_value2){
//			dynamicGraph2.addDataPoint(xj_memory2);
//		}else if(xj_memory2 < xj_value2){
//			xj_memory2++;
//		}else{
//			xj_flag++;
//		}
//		if(xj_memory3 > xj_value3){
//			dynamicGraph3.addDataPoint(xj_memory3);
//		}else if(xj_memory3 < xj_value3){
//			xj_memory3++;
//		}else{
//			xj_flag++;
//		}
//		if(xj_memory4 > xj_value4){
//			dynamicGraph4.addDataPoint(xj_memory4);				
//		}else if(xj_memory4 < xj_value4){
//			xj_memory4++;
//		}else{
//			xj_flag++;
//		}
//		if(xj_flag > 4){
//			xj_flag = 0;
//			break;
//		}
//	}
}


void Screen1View::Screen1updat()
{
	tmcount = 2300;
}

void Screen1View::Screen1speed()
{
	if(gps_num > gps_memory){
			gps_memory++;
			Unicode::snprintf(speedvalueBuffer,SPEEDVALUE_SIZE,"%d",gps_memory);
			containerspeed.invalidate();
	}else if(gps_num < gps_memory){
			gps_memory--;
			Unicode::snprintf(speedvalueBuffer,SPEEDVALUE_SIZE,"%d",gps_memory);
			containerspeed.invalidate();
	}
}

void Screen1View::Screen1temperNum(uint8_t &tpnum)
{
	tp_num = tpnum;
}
void Screen1View::Screen1gpsNum(double &gpsnum)
{
	gps_memory = gps_num;
	gps_num = (int)(gpsnum-(gpsnum*0.08));           //国家规定码表必须比实际车速快5~10%        
	if(gps_memory - gps_num > 0){
		gpsc = gps_memory - gps_num;
	}else if(gps_memory - gps_num < 0){
		gpsc = gps_memory - gps_num;
		gpsc = ~(gpsc-1);
	}
}
void Screen1View::Screen1witNum(float *witnum1,float *witnum2)
{
	witdat1 = witnum1;
	witdat2 = witnum2;
}
void Screen1View::Screen1canNum(uint8_t &can_link)
{
	can_flag = can_link;
}
void Screen1View::Screen1Adc1Num(uint8_t *adc_dat)
{
	xj_memory1 = xj_value1;
	xj_memory2 = xj_value2;
	xj_memory3 = xj_value3;
	xj_memory4 = xj_value4;
	xj_value1 = adc_dat[0];
	xj_value2 = adc_dat[1];
	xj_value3 = adc_dat[2];
	xj_value4 = adc_dat[3];
	xj_flag = 0;
	oxj_value = (4.7+adc_dat[4]*(3.2/50));
	bra_num = (adc_dat[5]*100+adc_dat[6])*1.0/1000;
}
void Screen1View::Screen1Adc2Num(uint8_t *adc_dat)
{

}

void Screen1View::Screen1RtcNum(uint8_t &rtcyear,uint8_t &rtcmonth,uint8_t &rtcdate,uint8_t &rtchour,uint8_t &rtcminute)
{
	rtc_year = rtcyear;
	rtc_month = rtcmonth;
	rtc_day = rtcdate;
	rtc_hour = rtchour;
	rtc_minute = rtcminute;
}

void Screen1View::Screen1TyreNum(uint8_t *tyre_dat)
{
	tyrenum[0] = tyre_dat[0]<<8|tyre_dat[1];
	tyrenum[1] = tyre_dat[2]<<8|tyre_dat[3];
	tyrenum[2] = tyre_dat[4]<<8|tyre_dat[5];
	tyrenum[3] = tyre_dat[6]<<8|tyre_dat[7];
}

void TpNum(uint8_t tpdat)
{
	if(screen1){
		screen1->Screen1temperNum(tpdat);
	}
}

void GpsNum(double gpsdat)
{
	if(screen1){
		screen1->Screen1gpsNum(gpsdat);
	}
}

void WitNum(float *witdat1,float *witdat2)
{
	if(screen1){
		screen1->Screen1witNum(witdat1,witdat2);
	}
}

void CanNum(uint8_t canflag)
{
	if(screen1){
		screen1->Screen1canNum(canflag);
	}
}

void ADC1_Num(uint8_t *adc1dat)
{
	if(screen1){
		screen1->Screen1Adc1Num(adc1dat);
	}
}
void ADC2_Num(uint8_t *adc2dat)
{
	if(screen1){
		screen1->Screen1Adc2Num(adc2dat);
	}
}

void RtcNum(uint8_t rtcyear,uint8_t rtcmonth,uint8_t rtcdate,uint8_t rtchour,uint8_t rtcminute)
{
	if(screen1){
		screen1->Screen1RtcNum(rtcyear,rtcmonth,rtcdate,rtchour,rtcminute);
	}	
}

void DTU_C_Num(uint8_t csqdat)
{
	if(screen1){
		
	}		
}
void Tyre_Num(uint8_t *tyre_dat)
{
	if(screen1){
		screen1->Screen1TyreNum(tyre_dat);
	}
}

void Updattim()
{
	if(screen1){
		screen1->Screen1updat();
	}
}
