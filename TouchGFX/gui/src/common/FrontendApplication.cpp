#include <gui/common/FrontendApplication.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>

static LCD16DebugPrinter bp;

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{
	bp.setPosition(960,575,1024,60);
	bp.setScale(4);
	bp.setColor(0xffef);
	setDebugPrinter(&bp);
}
