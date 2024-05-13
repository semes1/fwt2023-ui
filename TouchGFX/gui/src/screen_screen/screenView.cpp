#include <gui/screen_screen/screenView.hpp>
#include <gui_generated/screen_screen/screenViewBase.hpp>

DebugPrinter * dp1;


screenView::screenView()
{
	zAngle = 0;
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
		dp1 = Application::getDebugPrinter();
		dp1->setString("v1.0");
		Application::invalidateDebugRegion();
}

void screenView::tearDownScreen()
{
  screenViewBase::tearDownScreen();

}


void screenView::handleTickEvent()
{
	static uint16_t count = 200;
	  if (count > 0)
    {
				runAnimDemo();
        count--;
        if (count == 0)
        {
            application().gotoScreen1ScreenSlideTransitionSouth();
        }
    }
}

void screenView::runAnimDemo()
{
	zAngle += (1.6f*PI/180);   //1.6¡£
	textureMapper1.updateAngles(0,0,zAngle);
}
