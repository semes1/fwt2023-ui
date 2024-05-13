#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>


class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		virtual void handleTickEvent();
		void runAnimcar();
		void Screen1speed();
		void Screen1temperNum(uint8_t &tpnum);
		void Screen1gpsNum(double &gpsnum);
		void Screen1witNum(float *witnum1,float *witnum2);
		void Screen1canNum(uint8_t &can_link);
		void Screen1Adc1Num(uint8_t *adc_dat);
		void Screen1Adc2Num(uint8_t *adc_dat);
		void Screen1TyreNum(uint8_t *tyre_dat);
		void Screen1RtcNum(uint8_t &rtcyear,uint8_t &rtcmonth,uint8_t &rtcdate,uint8_t &rtchour,uint8_t &rtcminute);
		void Screen1updat();
protected:
		float xAngle,yAngle,zAngle,bra_num,oxj_value;
		uint8_t sp_num,tp_num,can_flag;
    uint8_t xj_value1,xj_value2,xj_value3,xj_value4,xj_memory1,xj_memory2,xj_memory3,xj_memory4,xj_flag;
		uint8_t rtc_year,rtc_month,rtc_day,rtc_hour,rtc_minute,rtc_second;
		int gps_num,gps_memory,gpsc;
		float *witdat1,*witdat2;
		float xAcc,yAcc,zAcc;
    uint16_t tyrenum[4];
		uint16_t tmcount;
};

#endif // SCREEN1VIEW_HPP
