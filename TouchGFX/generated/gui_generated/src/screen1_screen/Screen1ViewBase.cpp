/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 1024, 600);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(box1);

    background.setXY(0, 0);
    background.setBitmap(touchgfx::Bitmap(BITMAP_FWTQQ4_ID));
    add(background);

    textureMapper1.setXY(436, 448);
    textureMapper1.setBitmap(touchgfx::Bitmap(BITMAP_SANZHOU_ID));
    textureMapper1.setWidth(152);
    textureMapper1.setHeight(152);
    textureMapper1.setBitmapPosition(-81.5f, -81.5f);
    textureMapper1.setScale(1.0f);
    textureMapper1.setCameraDistance(1000.0f);
    textureMapper1.setOrigo(76.0f, 76.0f, 1000.0f);
    textureMapper1.setCamera(76.0f, 76.0f);
    textureMapper1.setAngles(0.0f, 0.0f, 0.0f);
    textureMapper1.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
    add(textureMapper1);

    textspeed.setXY(459, 380);
    textspeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textspeed.setLinespacing(0);
    textspeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZKSF));
    add(textspeed);

    oil.setXY(698, 532);
    oil.setBitmap(touchgfx::Bitmap(BITMAP_OIL_BOX_ID));
    add(oil);

    imageProgress1.setXY(754, 539);
    imageProgress1.setProgressIndicatorPosition(0, 0, 100, 18);
    imageProgress1.setRange(0, 100);
    imageProgress1.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    imageProgress1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_IMAGEPROGRESS_PLAIN_THICK_TINY_ID));
    imageProgress1.setBitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_IMAGEPROGRESS_PLAIN_THICK_TINY_ACTIVE_ID);
    imageProgress1.setValue(60);
    imageProgress1.setAnchorAtZero(true);
    add(imageProgress1);

    containerspeed.setPosition(410, 221, 205, 158);
    speedvalue.setPosition(0, 0, 205, 159);
    speedvalue.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    speedvalue.setLinespacing(0);
    Unicode::snprintf(speedvalueBuffer, SPEEDVALUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0OHJ).getText());
    speedvalue.setWildcard(speedvalueBuffer);
    speedvalue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FHRY));
    containerspeed.add(speedvalue);

    add(containerspeed);

    Image_battery.setBitmap(touchgfx::Bitmap(BITMAP_DIANCI_ID));
    Image_battery.setPosition(131, 528, 47, 40);
    Image_battery.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    add(Image_battery);

    Progress_battery.setXY(193, 524);
    Progress_battery.setProgressIndicatorPosition(3, 3, 150, 35);
    Progress_battery.setRange(0, 99);
    Progress_battery.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    Progress_battery.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_LINEPROGRESS_BACKGROUNDS_IMAGE_STYLED_BATTERIES_BATTERY_LARGE_0_ID));
    Progress_battery.setBitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_IMAGEPROGRESS_PLAIN_THIN_TINY_ACTIVE_ID);
    Progress_battery.setValue(60);
    Progress_battery.setAnchorAtZero(true);
    add(Progress_battery);

    container_can.setPosition(220, 23, 64, 49);
    can_status.setPosition(0, 0, 66, 49);
    can_status.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    can_status.setLinespacing(0);
    can_statusBuffer[0] = 0;
    can_status.setWildcard(can_statusBuffer);
    can_status.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZL3L));
    container_can.add(can_status);

    add(container_can);

    signal_4g.setXY(17, 8);
    signal_4g.setBitmap(touchgfx::Bitmap(BITMAP_SIGNAL_4G2_ID));
    add(signal_4g);

    tp_value.setPosition(848, 12, 56, 60);
    tempdat.setPosition(6, 6, 49, 48);
    tempdat.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tempdat.setLinespacing(0);
    Unicode::snprintf(tempdatBuffer, TEMPDAT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JT4I).getText());
    tempdat.setWildcard(tempdatBuffer);
    tempdat.setTypedText(touchgfx::TypedText(T___SINGLEUSE_E0Q1));
    tp_value.add(tempdat);

    add(tp_value);

    tp_signal.setXY(897, 17);
    tp_signal.setBitmap(touchgfx::Bitmap(BITMAP_SESHIDU_ID));
    add(tp_signal);

    cpuimage.setXY(800, 18);
    cpuimage.setBitmap(touchgfx::Bitmap(BITMAP_CPU_ID));
    add(cpuimage);

    yyimage.setXY(17, 134);
    yyimage.setBitmap(touchgfx::Bitmap(BITMAP_YEYACHUANGAN_ID));
    add(yyimage);

    BHPressure.setPosition(17, 187, 155, 49);
    brakempa.setPosition(-1, 1, 156, 48);
    brakempa.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    brakempa.setLinespacing(0);
    Unicode::snprintf(brakempaBuffer, BRAKEMPA_SIZE, "%s", touchgfx::TypedText(T_BRAKE).getText());
    brakempa.setWildcard(brakempaBuffer);
    brakempa.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W5NF));
    BHPressure.add(brakempa);

    add(BHPressure);

    Mpa.setXY(172, 203);
    Mpa.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Mpa.setLinespacing(0);
    Mpa.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VP8P));
    add(Mpa);

    canrx.setXY(172, 17);
    canrx.setBitmap(touchgfx::Bitmap(BITMAP_CANRX_ID));
    add(canrx);

    timecontainer.setPosition(383, 7, 219, 74);
    digitalClock.setPosition(31, 39, 188, 35);
    digitalClock.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    digitalClock.setTypedText(touchgfx::TypedText(T_TIMER));
    digitalClock.displayLeadingZeroForHourIndicator(true);
    digitalClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR_NO_SECONDS);
    digitalClock.setTime24Hour(14, 9, 57);
    timecontainer.add(digitalClock);

    calendar.setPosition(31, 4, 188, 35);
    calendar.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    calendar.setLinespacing(0);
    Unicode::snprintf(calendarBuffer, CALENDAR_SIZE, "%s", touchgfx::TypedText(T_CALENDAR).getText());
    calendar.setWildcard(calendarBuffer);
    calendar.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1JEG));
    timecontainer.add(calendar);

    add(timecontainer);

    accimage.setXY(16, 253);
    accimage.setBitmap(touchgfx::Bitmap(BITMAP_SXJSD_ID));
    add(accimage);

    Three_acc.setPosition(0, 301, 236, 176);
    ACC_Z.setPosition(5, 94, 227, 54);
    ACC_Z.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ACC_Z.setLinespacing(0);
    Unicode::snprintf(ACC_ZBuffer, ACC_Z_SIZE, "%s", touchgfx::TypedText(T_WIT_AZ).getText());
    ACC_Z.setWildcard(ACC_ZBuffer);
    ACC_Z.setTypedText(touchgfx::TypedText(T_ACC_Z));
    Three_acc.add(ACC_Z);

    ACC_XY.setPosition(0, 0, 236, 103);
    ACC_XY.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ACC_XY.setLinespacing(0);
    touchgfx::Unicode::snprintf(ACC_XYBuffer1, ACC_XYBUFFER1_SIZE, "%s", touchgfx::TypedText(T_WIT_AX).getText());
    ACC_XY.setWildcard1(ACC_XYBuffer1);
    touchgfx::Unicode::snprintf(ACC_XYBuffer2, ACC_XYBUFFER2_SIZE, "%s", touchgfx::TypedText(T_WIT_AY).getText());
    ACC_XY.setWildcard2(ACC_XYBuffer2);
    ACC_XY.setTypedText(touchgfx::TypedText(T_ACC_XY));
    Three_acc.add(ACC_XY);

    add(Three_acc);

    jzqimage.setXY(666, 291);
    jzqimage.setBitmap(touchgfx::Bitmap(BITMAP_JZQ3_ID));
    add(jzqimage);

    tyreimage.setXY(186, 89);
    tyreimage.setBitmap(touchgfx::Bitmap(BITMAP_LUNSHU_ID));
    add(tyreimage);

    lunshu.setPosition(232, 81, 592, 95);
    tyre34.setPosition(0, 44, 580, 51);
    tyre34.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tyre34.setLinespacing(0);
    touchgfx::Unicode::snprintf(tyre34Buffer1, TYRE34BUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_K3RF).getText());
    tyre34.setWildcard1(tyre34Buffer1);
    touchgfx::Unicode::snprintf(tyre34Buffer2, TYRE34BUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Q6O0).getText());
    tyre34.setWildcard2(tyre34Buffer2);
    tyre34.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7JG6));
    lunshu.add(tyre34);

    tyre12.setPosition(0, 0, 580, 44);
    tyre12.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tyre12.setLinespacing(0);
    touchgfx::Unicode::snprintf(tyre12Buffer1, TYRE12BUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_97G1).getText());
    tyre12.setWildcard1(tyre12Buffer1);
    touchgfx::Unicode::snprintf(tyre12Buffer2, TYRE12BUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZXVN).getText());
    tyre12.setWildcard2(tyre12Buffer2);
    tyre12.setTypedText(touchgfx::TypedText(T___SINGLEUSE_P47S));
    lunshu.add(tyre12);

    add(lunshu);

    dynamicGraph1.setPosition(786, 187, 222, 67);
    dynamicGraph1.setScale(1);
    dynamicGraph1.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph1.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph1.setGraphRangeY(0, 230);
    dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph1Line1.setPainter(dynamicGraph1Line1Painter);
    dynamicGraph1Line1.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1Line1);


    dynamicGraph1.addDataPoint(209.0219f);
    dynamicGraph1.addDataPoint(205.10142f);
    dynamicGraph1.addDataPoint(195.40105f);
    dynamicGraph1.addDataPoint(181.39398f);
    dynamicGraph1.addDataPoint(164.94682f);
    dynamicGraph1.addDataPoint(148.10837f);
    dynamicGraph1.addDataPoint(132.87987f);
    dynamicGraph1.addDataPoint(120.992f);
    dynamicGraph1.addDataPoint(113.71349f);
    dynamicGraph1.addDataPoint(111.71209f);
    dynamicGraph1.addDataPoint(114.98345f);
    dynamicGraph1.addDataPoint(122.85559f);
    dynamicGraph1.addDataPoint(134.0684f);
    dynamicGraph1.addDataPoint(146.91939f);
    dynamicGraph1.addDataPoint(159.45935f);
    dynamicGraph1.addDataPoint(169.71646f);
    dynamicGraph1.addDataPoint(175.92388f);
    dynamicGraph1.addDataPoint(176.7255f);
    dynamicGraph1.addDataPoint(171.33726f);
    dynamicGraph1.addDataPoint(159.64574f);
    dynamicGraph1.addDataPoint(142.23326f);
    dynamicGraph1.addDataPoint(120.32621f);
    dynamicGraph1.addDataPoint(95.67236f);
    dynamicGraph1.addDataPoint(70.3602f);
    dynamicGraph1.addDataPoint(46.60017f);
    dynamicGraph1.addDataPoint(26.49148f);
    dynamicGraph1.addDataPoint(11.80028f);
    dynamicGraph1.addDataPoint(3.7731f);
    dynamicGraph1.addDataPoint(3.00621f);
    dynamicGraph1.addDataPoint(9.38514f);
    dynamicGraph1.addDataPoint(22.10074f);
    dynamicGraph1.addDataPoint(39.74021f);
    dynamicGraph1.addDataPoint(60.44282f);
    dynamicGraph1.addDataPoint(82.10333f);
    dynamicGraph1.addDataPoint(102.60067f);
    dynamicGraph1.addDataPoint(120.02675f);
    dynamicGraph1.addDataPoint(132.89032f);
    dynamicGraph1.addDataPoint(140.27359f);
    dynamicGraph1.addDataPoint(141.92437f);
    dynamicGraph1.addDataPoint(138.27393f);
    dynamicGraph1.addDataPoint(130.3786f);
    dynamicGraph1.addDataPoint(119.79192f);
    dynamicGraph1.addDataPoint(108.3814f);
    dynamicGraph1.addDataPoint(98.11049f);
    dynamicGraph1.addDataPoint(90.80994f);
    dynamicGraph1.addDataPoint(87.96375f);
    dynamicGraph1.addDataPoint(90.53375f);
    dynamicGraph1.addDataPoint(98.84223f);
    dynamicGraph1.addDataPoint(112.52568f);
    dynamicGraph1.addDataPoint(130.56507f);
    dynamicGraph1.addDataPoint(151.38933f);
    dynamicGraph1.addDataPoint(173.04095f);
    dynamicGraph1.addDataPoint(193.38559f);
    dynamicGraph1.addDataPoint(210.34251f);
    dynamicGraph1.addDataPoint(222.1109f);
    dynamicGraph1.addDataPoint(227.36693f);
    dynamicGraph1.addDataPoint(225.40994f);
    dynamicGraph1.addDataPoint(216.24183f);
    dynamicGraph1.addDataPoint(200.57054f);
    dynamicGraph1.addDataPoint(179.73756f);
    dynamicGraph1.addDataPoint(155.57699f);
    dynamicGraph1.addDataPoint(130.2218f);
    dynamicGraph1.addDataPoint(105.87842f);
    dynamicGraph1.addDataPoint(84.59417f);
    dynamicGraph1.addDataPoint(68.0431f);
    dynamicGraph1.addDataPoint(57.35363f);
    dynamicGraph1.addDataPoint(52.9966f);
    dynamicGraph1.addDataPoint(54.74598f);
    dynamicGraph1.addDataPoint(61.71628f);
    dynamicGraph1.addDataPoint(72.47231f);
    dynamicGraph1.addDataPoint(85.19907f);
    dynamicGraph1.addDataPoint(97.91274f);
    dynamicGraph1.addDataPoint(108.68937f);
    dynamicGraph1.addDataPoint(115.88607f);
    dynamicGraph1.addDataPoint(118.32992f);
    dynamicGraph1.addDataPoint(115.45384f);
    dynamicGraph1.addDataPoint(107.36436f);
    dynamicGraph1.addDataPoint(94.83358f);
    dynamicGraph1.addDataPoint(79.21628f);
    dynamicGraph1.addDataPoint(62.30122f);
    dynamicGraph1.addDataPoint(46.113f);
    dynamicGraph1.addDataPoint(32.6863f);
    dynamicGraph1.addDataPoint(23.83735f);
    dynamicGraph1.addDataPoint(20.95807f);
    dynamicGraph1.addDataPoint(24.85536f);
    dynamicGraph1.addDataPoint(35.65361f);
    dynamicGraph1.addDataPoint(52.77114f);
    dynamicGraph1.addDataPoint(74.97351f);
    dynamicGraph1.addDataPoint(100.49786f);
    dynamicGraph1.addDataPoint(127.23485f);
    dynamicGraph1.addDataPoint(152.94847f);
    dynamicGraph1.addDataPoint(175.50963f);
    dynamicGraph1.addDataPoint(193.1181f);
    dynamicGraph1.addDataPoint(204.4885f);
    dynamicGraph1.addDataPoint(208.9803f);
    dynamicGraph1.addDataPoint(206.65739f);
    dynamicGraph1.addDataPoint(198.27122f);
    dynamicGraph1.addDataPoint(185.16921f);
    dynamicGraph1.addDataPoint(169.13893f);
    dynamicGraph1.addDataPoint(152.20517f);
    dynamicGraph1.addDataPoint(136.4024f);
    dynamicGraph1.addDataPoint(123.54783f);
    dynamicGraph1.addDataPoint(115.03993f);
    dynamicGraph1.addDataPoint(111.7048f);
    dynamicGraph1.addDataPoint(113.70722f);
    dynamicGraph1.addDataPoint(120.53603f);
    dynamicGraph1.addDataPoint(131.06562f);
    dynamicGraph1.addDataPoint(143.68647f);
    dynamicGraph1.addDataPoint(156.4903f);
    dynamicGraph1.addDataPoint(167.4894f);
    dynamicGraph1.addDataPoint(174.8457f);
    dynamicGraph1.addDataPoint(177.08421f);
    dynamicGraph1.addDataPoint(173.26726f);
    dynamicGraph1.addDataPoint(163.10998f);
    dynamicGraph1.addDataPoint(147.02414f);
    dynamicGraph1.addDataPoint(126.08539f);
    dynamicGraph1.addDataPoint(101.92721f);
    dynamicGraph1.addDataPoint(76.57297f);
    dynamicGraph1.addDataPoint(52.22446f);
    dynamicGraph1.addDataPoint(31.03002f);
    dynamicGraph1.addDataPoint(14.85747f);
    dynamicGraph1.addDataPoint(5.09671f);
    dynamicGraph1.addDataPoint(2.51367f);
    dynamicGraph1.addDataPoint(7.17149f);
    dynamicGraph1.addDataPoint(18.42745f);
    dynamicGraph1.addDataPoint(35.0061f);
    dynamicGraph1.addDataPoint(55.1402f);
    dynamicGraph1.addDataPoint(76.7644f);
    dynamicGraph1.addDataPoint(97.73976f);
    dynamicGraph1.addDataPoint(116.08505f);
    dynamicGraph1.addDataPoint(130.18899f);
    dynamicGraph1.addDataPoint(138.98035f);
    dynamicGraph1.addDataPoint(142.03741f);
    dynamicGraph1.addDataPoint(139.62461f);
    dynamicGraph1.addDataPoint(132.65282f);
    dynamicGraph1.addDataPoint(122.56762f);
    dynamicGraph1.addDataPoint(111.17807f);
    dynamicGraph1.addDataPoint(100.4452f);
    dynamicGraph1.addDataPoint(92.25358f);
    dynamicGraph1.addDataPoint(88.19132f);
    dynamicGraph1.addDataPoint(89.36311f);
    dynamicGraph1.addDataPoint(96.25693f);
    dynamicGraph1.addDataPoint(108.67936f);
    dynamicGraph1.addDataPoint(125.76684f);
    dynamicGraph1.addDataPoint(146.0718f);
    dynamicGraph1.addDataPoint(167.71432f);
    dynamicGraph1.addDataPoint(188.58275f);
    dynamicGraph1.addDataPoint(206.5614f);
    dynamicGraph1.addDataPoint(219.7602f);
    dynamicGraph1.addDataPoint(226.72121f);
    add(dynamicGraph1);

    dynamicGraph2.setPosition(786, 254, 222, 67);
    dynamicGraph2.setScale(1);
    dynamicGraph2.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph2.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph2.setGraphRangeY(0, 230);
    dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph2Line1.setPainter(dynamicGraph2Line1Painter);
    dynamicGraph2Line1.setLineWidth(2);
    dynamicGraph2.addGraphElement(dynamicGraph2Line1);


    dynamicGraph2.addDataPoint(100.01139f);
    dynamicGraph2.addDataPoint(91.97349f);
    dynamicGraph2.addDataPoint(88.1259f);
    dynamicGraph2.addDataPoint(89.5481f);
    dynamicGraph2.addDataPoint(96.69843f);
    dynamicGraph2.addDataPoint(109.3527f);
    dynamicGraph2.addDataPoint(126.61884f);
    dynamicGraph2.addDataPoint(147.02628f);
    dynamicGraph2.addDataPoint(168.68017f);
    dynamicGraph2.addDataPoint(189.4637f);
    dynamicGraph2.addDataPoint(207.26645f);
    dynamicGraph2.addDataPoint(220.21353f);
    dynamicGraph2.addDataPoint(226.87049f);
    dynamicGraph2.addDataPoint(226.40137f);
    dynamicGraph2.addDataPoint(218.66258f);
    dynamicGraph2.addDataPoint(204.22219f);
    dynamicGraph2.addDataPoint(184.30238f);
    dynamicGraph2.addDataPoint(160.65146f);
    dynamicGraph2.addDataPoint(135.35929f);
    dynamicGraph2.addDataPoint(110.63632f);
    dynamicGraph2.addDataPoint(88.58047f);
    dynamicGraph2.addDataPoint(70.95721f);
    dynamicGraph2.addDataPoint(59.01699f);
    dynamicGraph2.addDataPoint(53.36983f);
    dynamicGraph2.addDataPoint(53.93066f);
    dynamicGraph2.addDataPoint(59.94123f);
    dynamicGraph2.addDataPoint(70.06594f);
    dynamicGraph2.addDataPoint(82.55087f);
    dynamicGraph2.addDataPoint(95.42815f);
    dynamicGraph2.addDataPoint(106.7432f);
    dynamicGraph2.addDataPoint(114.77937f);
    dynamicGraph2.addDataPoint(118.25533f);
    dynamicGraph2.addDataPoint(116.47313f);
    dynamicGraph2.addDataPoint(109.40066f);
    dynamicGraph2.addDataPoint(97.67923f);
    dynamicGraph2.addDataPoint(82.55539f);
    dynamicGraph2.addDataPoint(65.7445f);
    dynamicGraph2.addDataPoint(49.241f);
    dynamicGraph2.addDataPoint(35.09628f);
    dynamicGraph2.addDataPoint(25.18869f);
    dynamicGraph2.addDataPoint(21.01107f);
    dynamicGraph2.addDataPoint(23.49927f);
    dynamicGraph2.addDataPoint(32.92065f);
    dynamicGraph2.addDataPoint(48.83508f);
    dynamicGraph2.addDataPoint(70.13276f);
    dynamicGraph2.addDataPoint(95.14501f);
    dynamicGraph2.addDataPoint(121.81596f);
    dynamicGraph2.addDataPoint(147.91651f);
    dynamicGraph2.addDataPoint(171.27716f);
    dynamicGraph2.addDataPoint(190.01433f);
    dynamicGraph2.addDataPoint(202.72553f);
    dynamicGraph2.addDataPoint(208.63203f);
    dynamicGraph2.addDataPoint(207.65354f);
    dynamicGraph2.addDataPoint(200.40699f);
    dynamicGraph2.addDataPoint(188.1295f);
    dynamicGraph2.addDataPoint(172.53447f);
    dynamicGraph2.addDataPoint(155.61648f);
    dynamicGraph2.addDataPoint(139.42679f);
    dynamicGraph2.addDataPoint(125.84421f);
    dynamicGraph2.addDataPoint(116.36651f);
    dynamicGraph2.addDataPoint(111.94551f);
    dynamicGraph2.addDataPoint(112.88393f);
    dynamicGraph2.addDataPoint(118.80533f);
    dynamicGraph2.addDataPoint(128.70038f);
    dynamicGraph2.addDataPoint(141.04433f);
    dynamicGraph2.addDataPoint(153.97261f);
    dynamicGraph2.addDataPoint(165.49505f);
    dynamicGraph2.addDataPoint(173.72504f);
    dynamicGraph2.addDataPoint(177.09817f);
    dynamicGraph2.addDataPoint(174.55621f);
    dynamicGraph2.addDataPoint(165.67569f);
    dynamicGraph2.addDataPoint(150.7271f);
    dynamicGraph2.addDataPoint(130.65761f);
    dynamicGraph2.addDataPoint(106.99924f);
    dynamicGraph2.addDataPoint(81.71218f);
    dynamicGraph2.addDataPoint(56.98046f);
    dynamicGraph2.addDataPoint(34.9822f);
    dynamicGraph2.addDataPoint(17.65942f);
    dynamicGraph2.addDataPoint(6.51284f);
    dynamicGraph2.addDataPoint(2.44384f);
    dynamicGraph2.addDataPoint(5.66103f);
    dynamicGraph2.addDataPoint(15.66151f);
    dynamicGraph2.addDataPoint(31.2889f);
    dynamicGraph2.addDataPoint(50.86163f);
    dynamicGraph2.addDataPoint(72.35734f);
    dynamicGraph2.addDataPoint(93.63316f);
    dynamicGraph2.addDataPoint(112.65771f);
    dynamicGraph2.addDataPoint(127.72912f);
    dynamicGraph2.addDataPoint(137.65548f);
    dynamicGraph2.addDataPoint(141.87771f);
    dynamicGraph2.addDataPoint(140.5217f);
    dynamicGraph2.addDataPoint(134.37388f);
    dynamicGraph2.addDataPoint(124.78342f);
    dynamicGraph2.addDataPoint(113.50168f);
    dynamicGraph2.addDataPoint(102.47717f);
    dynamicGraph2.addDataPoint(93.6284f);
    dynamicGraph2.addDataPoint(88.62021f);
    dynamicGraph2.addDataPoint(88.66827f);
    dynamicGraph2.addDataPoint(94.39339f);
    dynamicGraph2.addDataPoint(105.7421f);
    dynamicGraph2.addDataPoint(121.98231f);
    dynamicGraph2.addDataPoint(141.77469f);
    dynamicGraph2.addDataPoint(163.31216f);
    dynamicGraph2.addDataPoint(184.51224f);
    dynamicGraph2.addDataPoint(203.24117f);
    dynamicGraph2.addDataPoint(217.54526f);
    dynamicGraph2.addDataPoint(225.86401f);
    dynamicGraph2.addDataPoint(227.20172f);
    dynamicGraph2.addDataPoint(221.23846f);
    dynamicGraph2.addDataPoint(208.36838f);
    dynamicGraph2.addDataPoint(189.66095f);
    dynamicGraph2.addDataPoint(166.74945f);
    dynamicGraph2.addDataPoint(141.65867f);
    dynamicGraph2.addDataPoint(116.59087f);
    dynamicGraph2.addDataPoint(93.69328f);
    dynamicGraph2.addDataPoint(74.8326f);
    dynamicGraph2.addDataPoint(61.40106f);
    dynamicGraph2.addDataPoint(54.17538f);
    dynamicGraph2.addDataPoint(53.24365f);
    dynamicGraph2.addDataPoint(58.00824f);
    dynamicGraph2.addDataPoint(67.26399f);
    dynamicGraph2.addDataPoint(79.34297f);
    dynamicGraph2.addDataPoint(92.30963f);
    dynamicGraph2.addDataPoint(104.18461f);
    dynamicGraph2.addDataPoint(113.17247f);
    dynamicGraph2.addDataPoint(117.86795f);
    dynamicGraph2.addDataPoint(117.41814f);
    dynamicGraph2.addDataPoint(111.62223f);
    dynamicGraph2.addDataPoint(100.95817f);
    dynamicGraph2.addDataPoint(86.53281f);
    dynamicGraph2.addDataPoint(69.96129f);
    dynamicGraph2.addDataPoint(53.18872f);
    dynamicGraph2.addDataPoint(38.27396f);
    dynamicGraph2.addDataPoint(27.15913f);
    dynamicGraph2.addDataPoint(21.45053f);
    dynamicGraph2.addDataPoint(22.23501f);
    dynamicGraph2.addDataPoint(29.95214f);
    dynamicGraph2.addDataPoint(44.33654f);
    dynamicGraph2.addDataPoint(64.43671f);
    dynamicGraph2.addDataPoint(88.70853f);
    dynamicGraph2.addDataPoint(115.17341f);
    dynamicGraph2.addDataPoint(141.62377f);
    dynamicGraph2.addDataPoint(165.85356f);
    dynamicGraph2.addDataPoint(185.88857f);
    dynamicGraph2.addDataPoint(200.19147f);
    dynamicGraph2.addDataPoint(207.81916f);
    dynamicGraph2.addDataPoint(208.51541f);
    dynamicGraph2.addDataPoint(202.72873f);
    dynamicGraph2.addDataPoint(191.5536f);
    dynamicGraph2.addDataPoint(176.60194f);
    add(dynamicGraph2);

    dynamicGraph3.setPosition(786, 321, 222, 67);
    dynamicGraph3.setScale(1);
    dynamicGraph3.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph3.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph3.setGraphRangeY(0, 230);
    dynamicGraph3Line1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph3Line1.setPainter(dynamicGraph3Line1Painter);
    dynamicGraph3Line1.setLineWidth(2);
    dynamicGraph3.addGraphElement(dynamicGraph3Line1);


    dynamicGraph3.addDataPoint(96.41294f);
    dynamicGraph3.addDataPoint(81.05758f);
    dynamicGraph3.addDataPoint(64.18937f);
    dynamicGraph3.addDataPoint(47.81749f);
    dynamicGraph3.addDataPoint(33.98699f);
    dynamicGraph3.addDataPoint(24.54928f);
    dynamicGraph3.addDataPoint(20.95257f);
    dynamicGraph3.addDataPoint(24.07509f);
    dynamicGraph3.addDataPoint(34.1199f);
    dynamicGraph3.addDataPoint(50.58282f);
    dynamicGraph3.addDataPoint(72.29725f);
    dynamicGraph3.addDataPoint(97.55112f);
    dynamicGraph3.addDataPoint(124.26335f);
    dynamicGraph3.addDataPoint(150.20052f);
    dynamicGraph3.addDataPoint(173.21018f);
    dynamicGraph3.addDataPoint(191.44536f);
    dynamicGraph3.addDataPoint(203.55567f);
    dynamicGraph3.addDataPoint(208.82434f);
    dynamicGraph3.addDataPoint(207.23615f);
    dynamicGraph3.addDataPoint(199.4691f);
    dynamicGraph3.addDataPoint(186.81083f);
    dynamicGraph3.addDataPoint(171.00919f);
    dynamicGraph3.addDataPoint(154.07355f);
    dynamicGraph3.addDataPoint(138.04879f);
    dynamicGraph3.addDataPoint(124.78699f);
    dynamicGraph3.addDataPoint(115.74197f);
    dynamicGraph3.addDataPoint(111.80937f);
    dynamicGraph3.addDataPoint(113.22981f);
    dynamicGraph3.addDataPoint(119.56585f);
    dynamicGraph3.addDataPoint(129.75508f);
    dynamicGraph3.addDataPoint(142.23361f);
    dynamicGraph3.addDataPoint(155.11603f);
    dynamicGraph3.addDataPoint(166.41211f);
    dynamicGraph3.addDataPoint(174.256f);
    dynamicGraph3.addDataPoint(177.12271f);
    dynamicGraph3.addDataPoint(174.00771f);
    dynamicGraph3.addDataPoint(164.54977f);
    dynamicGraph3.addDataPoint(149.0832f);
    dynamicGraph3.addDataPoint(128.61364f);
    dynamicGraph3.addDataPoint(104.71965f);
    dynamicGraph3.addDataPoint(79.391f);
    dynamicGraph3.addDataPoint(54.82092f);
    dynamicGraph3.addDataPoint(33.17527f);
    dynamicGraph3.addDataPoint(16.36366f);
    dynamicGraph3.addDataPoint(5.83763f);
    dynamicGraph3.addDataPoint(2.43793f);
    dynamicGraph3.addDataPoint(6.30762f);
    dynamicGraph3.addDataPoint(16.88044f);
    dynamicGraph3.addDataPoint(32.94563f);
    dynamicGraph3.addDataPoint(52.78201f);
    dynamicGraph3.addDataPoint(74.34668f);
    dynamicGraph3.addDataPoint(95.49738f);
    dynamicGraph3.addDataPoint(114.2242f);
    dynamicGraph3.addDataPoint(128.86522f);
    dynamicGraph3.addDataPoint(138.28235f);
    dynamicGraph3.addDataPoint(141.97822f);
    dynamicGraph3.addDataPoint(140.14134f);
    dynamicGraph3.addDataPoint(133.61481f);
    dynamicGraph3.addDataPoint(123.79209f);
    dynamicGraph3.addDataPoint(112.45167f);
    dynamicGraph3.addDataPoint(101.54884f);
    dynamicGraph3.addDataPoint(92.98798f);
    dynamicGraph3.addDataPoint(88.40031f);
    dynamicGraph3.addDataPoint(88.95217f);
    dynamicGraph3.addDataPoint(95.20487f);
    dynamicGraph3.addDataPoint(107.0418f);
    dynamicGraph3.addDataPoint(123.67121f);
    dynamicGraph3.addDataPoint(143.7042f);
    dynamicGraph3.addDataPoint(165.29984f);
    dynamicGraph3.addDataPoint(186.36133f);
    dynamicGraph3.addDataPoint(204.76188f);
    dynamicGraph3.addDataPoint(218.57539f);
    dynamicGraph3.addDataPoint(226.28676f);
    dynamicGraph3.addDataPoint(226.95856f);
    dynamicGraph3.addDataPoint(220.3358f);
    dynamicGraph3.addDataPoint(206.87725f);
    dynamicGraph3.addDataPoint(187.70966f);
    dynamicGraph3.addDataPoint(164.5101f);
    dynamicGraph3.addDataPoint(139.32897f);
    dynamicGraph3.addDataPoint(114.37325f);
    dynamicGraph3.addDataPoint(91.77356f);
    dynamicGraph3.addDataPoint(73.36053f);
    dynamicGraph3.addDataPoint(60.475f);
    dynamicGraph3.addDataPoint(53.83255f);
    dynamicGraph3.addDataPoint(53.45719f);
    dynamicGraph3.addDataPoint(58.69133f);
    dynamicGraph3.addDataPoint(68.28051f);
    dynamicGraph3.addDataPoint(80.52359f);
    dynamicGraph3.addDataPoint(93.47144f);
    dynamicGraph3.addDataPoint(105.15223f);
    dynamicGraph3.addDataPoint(113.79818f);
    dynamicGraph3.addDataPoint(118.04869f);
    dynamicGraph3.addDataPoint(117.10743f);
    dynamicGraph3.addDataPoint(110.83584f);
    dynamicGraph3.addDataPoint(99.77261f);
    dynamicGraph3.addDataPoint(85.07716f);
    dynamicGraph3.addDataPoint(68.40297f);
    dynamicGraph3.addDataPoint(51.71498f);
    dynamicGraph3.addDataPoint(37.07093f);
    dynamicGraph3.addDataPoint(26.39096f);
    dynamicGraph3.addDataPoint(21.24072f);
    dynamicGraph3.addDataPoint(22.65213f);
    dynamicGraph3.addDataPoint(31.00148f);
    dynamicGraph3.addDataPoint(45.95864f);
    dynamicGraph3.addDataPoint(66.51286f);
    dynamicGraph3.addDataPoint(91.07281f);
    dynamicGraph3.addDataPoint(117.62985f);
    dynamicGraph3.addDataPoint(143.96676f);
    dynamicGraph3.addDataPoint(167.88934f);
    dynamicGraph3.addDataPoint(187.45544f);
    dynamicGraph3.addDataPoint(201.17645f);
    dynamicGraph3.addDataPoint(208.1694f);
    dynamicGraph3.addDataPoint(208.24302f);
    dynamicGraph3.addDataPoint(201.90851f);
    dynamicGraph3.addDataPoint(190.31406f);
    dynamicGraph3.addDataPoint(175.11046f);
    dynamicGraph3.addDataPoint(158.26266f);
    dynamicGraph3.addDataPoint(141.82838f);
    dynamicGraph3.addDataPoint(127.72792f);
    dynamicGraph3.addDataPoint(117.53079f);
    dynamicGraph3.addDataPoint(112.28264f);
    dynamicGraph3.addDataPoint(112.39153f);
    dynamicGraph3.addDataPoint(117.58596f);
    dynamicGraph3.addDataPoint(126.94944f);
    dynamicGraph3.addDataPoint(139.02744f);
    dynamicGraph3.addDataPoint(151.99508f);
    dynamicGraph3.addDataPoint(163.8668f);
    dynamicGraph3.addDataPoint(172.72481f);
    dynamicGraph3.addDataPoint(176.94113f);
    dynamicGraph3.addDataPoint(175.36833f);
    dynamicGraph3.addDataPoint(167.47802f);
    dynamicGraph3.addDataPoint(153.43145f);
    dynamicGraph3.addDataPoint(134.07431f);
    dynamicGraph3.addDataPoint(110.85608f);
    dynamicGraph3.addDataPoint(85.68257f);
    dynamicGraph3.addDataPoint(60.71764f);
    dynamicGraph3.addDataPoint(38.15577f);
    dynamicGraph3.addDataPoint(19.99032f);
    dynamicGraph3.addDataPoint(7.8028f);
    dynamicGraph3.addDataPoint(2.59617f);
    dynamicGraph3.addDataPoint(4.69046f);
    dynamicGraph3.addDataPoint(13.69203f);
    dynamicGraph3.addDataPoint(28.53978f);
    dynamicGraph3.addDataPoint(47.62325f);
    dynamicGraph3.addDataPoint(68.95943f);
    dynamicGraph3.addDataPoint(90.40901f);
    dynamicGraph3.addDataPoint(109.90815f);
    dynamicGraph3.addDataPoint(125.69041f);
    dynamicGraph3.addDataPoint(136.47445f);
    dynamicGraph3.addDataPoint(141.597f);
    add(dynamicGraph3);

    dynamicGraph4.setPosition(786, 389, 222, 67);
    dynamicGraph4.setScale(1);
    dynamicGraph4.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph4.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph4.setGraphRangeY(0, 230);
    dynamicGraph4Line1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph4Line1.setPainter(dynamicGraph4Line1Painter);
    dynamicGraph4Line1.setLineWidth(2);
    dynamicGraph4.addGraphElement(dynamicGraph4Line1);


    dynamicGraph4.addDataPoint(88.02276f);
    dynamicGraph4.addDataPoint(89.97701f);
    dynamicGraph4.addDataPoint(97.66775f);
    dynamicGraph4.addDataPoint(110.80584f);
    dynamicGraph4.addDataPoint(128.43965f);
    dynamicGraph4.addDataPoint(149.05101f);
    dynamicGraph4.addDataPoint(170.71486f);
    dynamicGraph4.addDataPoint(191.30501f);
    dynamicGraph4.addDataPoint(208.72372f);
    dynamicGraph4.addDataPoint(221.1295f);
    dynamicGraph4.addDataPoint(227.13857f);
    dynamicGraph4.addDataPoint(225.97751f);
    dynamicGraph4.addDataPoint(217.57035f);
    dynamicGraph4.addDataPoint(202.55059f);
    dynamicGraph4.addDataPoint(182.1966f);
    dynamicGraph4.addDataPoint(158.2976f);
    dynamicGraph4.addDataPoint(132.96468f);
    dynamicGraph4.addDataPoint(108.40761f);
    dynamicGraph4.addDataPoint(86.70188f);
    dynamicGraph4.addDataPoint(69.57135f);
    dynamicGraph4.addDataPoint(58.21032f);
    dynamicGraph4.addDataPoint(53.16427f);
    dynamicGraph4.addDataPoint(54.2824f);
    dynamicGraph4.addDataPoint(60.74671f);
    dynamicGraph4.addDataPoint(71.17443f);
    dynamicGraph4.addDataPoint(83.78212f);
    dynamicGraph4.addDataPoint(96.59332f);
    dynamicGraph4.addDataPoint(107.66655f);
    dynamicGraph4.addDataPoint(115.31847f);
    dynamicGraph4.addDataPoint(118.31747f);
    dynamicGraph4.addDataPoint(116.02609f);
    dynamicGraph4.addDataPoint(108.47675f);
    dynamicGraph4.addDataPoint(96.37199f);
    dynamicGraph4.addDataPoint(81.00946f);
    dynamicGraph4.addDataPoint(64.1397f);
    dynamicGraph4.addDataPoint(47.77232f);
    dynamicGraph4.addDataPoint(33.95212f);
    dynamicGraph4.addDataPoint(24.52965f);
    dynamicGraph4.addDataPoint(20.95164f);
    dynamicGraph4.addDataPoint(24.09447f);
    dynamicGraph4.addDataPoint(34.15915f);
    dynamicGraph4.addDataPoint(50.63945f);
    dynamicGraph4.addDataPoint(72.36697f);
    dynamicGraph4.addDataPoint(97.62827f);
    dynamicGraph4.addDataPoint(124.34151f);
    dynamicGraph4.addDataPoint(150.27316f);
    dynamicGraph4.addDataPoint(173.27133f);
    dynamicGraph4.addDataPoint(191.49027f);
    dynamicGraph4.addDataPoint(203.58127f);
    dynamicGraph4.addDataPoint(208.82954f);
    dynamicGraph4.addDataPoint(207.22194f);
    dynamicGraph4.addDataPoint(199.43842f);
    dynamicGraph4.addDataPoint(186.76821f);
    dynamicGraph4.addDataPoint(170.96025f);
    dynamicGraph4.addDataPoint(154.02433f);
    dynamicGraph4.addDataPoint(138.00511f);
    dynamicGraph4.addDataPoint(124.75377f);
    dynamicGraph4.addDataPoint(115.72271f);
    dynamicGraph4.addDataPoint(111.80576f);
    dynamicGraph4.addDataPoint(113.24157f);
    dynamicGraph4.addDataPoint(119.59071f);
    dynamicGraph4.addDataPoint(129.78913f);
    dynamicGraph4.addDataPoint(142.2717f);
    dynamicGraph4.addDataPoint(155.15238f);
    dynamicGraph4.addDataPoint(166.44096f);
    dynamicGraph4.addDataPoint(174.27229f);
    dynamicGraph4.addDataPoint(177.12266f);
    dynamicGraph4.addDataPoint(173.98928f);
    dynamicGraph4.addDataPoint(164.51292f);
    dynamicGraph4.addDataPoint(149.02993f);
    dynamicGraph4.addDataPoint(128.54779f);
    dynamicGraph4.addDataPoint(104.64654f);
    dynamicGraph4.addDataPoint(79.31686f);
    dynamicGraph4.addDataPoint(54.75226f);
    dynamicGraph4.addDataPoint(33.11816f);
    dynamicGraph4.addDataPoint(16.3231f);
    dynamicGraph4.addDataPoint(5.81703f);
    dynamicGraph4.addDataPoint(2.43875f);
    dynamicGraph4.addDataPoint(6.32924f);
    dynamicGraph4.addDataPoint(16.92019f);
    dynamicGraph4.addDataPoint(32.99914f);
    dynamicGraph4.addDataPoint(52.84367f);
    dynamicGraph4.addDataPoint(74.41024f);
    dynamicGraph4.addDataPoint(95.55666f);
    dynamicGraph4.addDataPoint(114.27373f);
    dynamicGraph4.addDataPoint(128.90082f);
    dynamicGraph4.addDataPoint(138.3016f);
    dynamicGraph4.addDataPoint(141.98066f);
    dynamicGraph4.addDataPoint(140.12852f);
    dynamicGraph4.addDataPoint(133.59007f);
    dynamicGraph4.addDataPoint(123.76017f);
    dynamicGraph4.addDataPoint(112.41815f);
    dynamicGraph4.addDataPoint(101.51948f);
    dynamicGraph4.addDataPoint(92.96804f);
    dynamicGraph4.addDataPoint(88.39399f);
    dynamicGraph4.addDataPoint(88.96204f);
    dynamicGraph4.addDataPoint(95.2316f);
    dynamicGraph4.addDataPoint(107.08404f);
    dynamicGraph4.addDataPoint(123.7257f);
    dynamicGraph4.addDataPoint(143.76613f);
    dynamicGraph4.addDataPoint(165.36333f);
    dynamicGraph4.addDataPoint(186.4201f);
    dynamicGraph4.addDataPoint(204.80988f);
    dynamicGraph4.addDataPoint(218.60749f);
    dynamicGraph4.addDataPoint(226.2993f);
    dynamicGraph4.addDataPoint(226.94976f);
    dynamicGraph4.addDataPoint(220.30598f);
    dynamicGraph4.addDataPoint(206.82876f);
    dynamicGraph4.addDataPoint(187.64669f);
    dynamicGraph4.addDataPoint(164.43821f);
    dynamicGraph4.addDataPoint(139.2545f);
    dynamicGraph4.addDataPoint(114.30266f);
    dynamicGraph4.addDataPoint(91.71275f);
    dynamicGraph4.addDataPoint(73.31422f);
    dynamicGraph4.addDataPoint(60.44626f);
    dynamicGraph4.addDataPoint(53.82246f);
    dynamicGraph4.addDataPoint(53.46481f);
    dynamicGraph4.addDataPoint(58.71379f);
    dynamicGraph4.addDataPoint(68.31339f);
    dynamicGraph4.addDataPoint(80.56145f);
    dynamicGraph4.addDataPoint(93.50843f);
    dynamicGraph4.addDataPoint(105.18276f);
    dynamicGraph4.addDataPoint(113.81758f);
    dynamicGraph4.addDataPoint(118.05374f);
    dynamicGraph4.addDataPoint(117.09675f);
    dynamicGraph4.addDataPoint(110.81002f);
    dynamicGraph4.addDataPoint(99.73418f);
    dynamicGraph4.addDataPoint(85.03032f);
    dynamicGraph4.addDataPoint(68.35312f);
    dynamicGraph4.addDataPoint(51.66812f);
    dynamicGraph4.addDataPoint(37.03301f);
    dynamicGraph4.addDataPoint(26.36716f);
    dynamicGraph4.addDataPoint(21.23492f);
    dynamicGraph4.addDataPoint(22.66643f);
    dynamicGraph4.addDataPoint(31.03596f);
    dynamicGraph4.addDataPoint(46.0113f);
    dynamicGraph4.addDataPoint(66.57981f);
    dynamicGraph4.addDataPoint(91.14871f);
    dynamicGraph4.addDataPoint(117.70838f);
    dynamicGraph4.addDataPoint(144.04135f);
    dynamicGraph4.addDataPoint(167.95384f);
    dynamicGraph4.addDataPoint(187.50473f);
    dynamicGraph4.addDataPoint(201.20701f);
    dynamicGraph4.addDataPoint(208.17963f);
    dynamicGraph4.addDataPoint(208.23341f);
    dynamicGraph4.addDataPoint(201.88154f);
    dynamicGraph4.addDataPoint(190.27392f);
    dynamicGraph4.addDataPoint(175.06252f);
    dynamicGraph4.addDataPoint(158.21295f);
    dynamicGraph4.addDataPoint(141.78282f);
    add(dynamicGraph4);

    JZFL.setXY(758, 206);
    JZFL.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    JZFL.setLinespacing(0);
    JZFL.setTypedText(touchgfx::TypedText(T___SINGLEUSE_14NU));
    add(JZFL);

    JZQL.setXY(752, 340);
    JZQL.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    JZQL.setLinespacing(0);
    JZQL.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IYWN));
    add(JZQL);

    JZFR.setXY(755, 272);
    JZFR.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    JZFR.setLinespacing(0);
    JZFR.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B1Y0));
    add(JZFR);

    JZQR.setXY(749, 407);
    JZQR.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    JZQR.setLinespacing(0);
    JZQR.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IX9P));
    add(JZQR);

    textureMapper2.setXY(232, 244);
    textureMapper2.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_ANALOGCLOCK_HANDS_SMALL_HOUR_PLAIN_DARK_ACCENT_ID));
    textureMapper2.setWidth(135);
    textureMapper2.setHeight(126);
    textureMapper2.setBitmapPosition(58.5f, 0.0f);
    textureMapper2.setScale(1.0f);
    textureMapper2.setCameraDistance(1000.0f);
    textureMapper2.setOrigo(67.5f, 63.0f, 1000.0f);
    textureMapper2.setCamera(67.5f, 63.0f);
    textureMapper2.setAngles(0.0f, 0.0f, 4.7f);
    textureMapper2.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);
    add(textureMapper2);

    lscontainer.setPosition(416, 187, 192, 62);
    lsspeed.setPosition(6, 8, 181, 47);
    lsspeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lsspeed.setLinespacing(0);
    Unicode::snprintf(lsspeedBuffer, LSSPEED_SIZE, "%s", touchgfx::TypedText(T_LUNSHU).getText());
    lsspeed.setWildcard(lsspeedBuffer);
    lsspeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9LCQ));
    lscontainer.add(lsspeed);

    add(lscontainer);
}

Screen1ViewBase::~Screen1ViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void Screen1ViewBase::setupScreen()
{

}
