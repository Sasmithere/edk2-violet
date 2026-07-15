Name (PCFG, Buffer (){
"<?xml version='1.0' encoding='utf-8'?>
<PanelName>NOVATEK_NT36672A_VIOLET</PanelName>
<PanelDescription>Novatek nt36672a Notch Single DSI Video Mode Panel (1080x2340 24bpp)</PanelDescription>
<Group id='Active Timing'>
<HorizontalActive>1080</HorizontalActive>
<HorizontalFrontPorch>90</HorizontalFrontPorch>
<HorizontalBackPorch>120</HorizontalBackPorch>
<HorizontalSyncPulse>2</HorizontalSyncPulse>
<HorizontalSyncSkew>0</HorizontalSyncSkew>
<HorizontalLeftBorder>0</HorizontalLeftBorder>
<HorizontalRightBorder>0</HorizontalRightBorder>
<VerticalActive>2340</VerticalActive>
<VerticalFrontPorch>13</VerticalFrontPorch>
<VerticalBackPorch>8</VerticalBackPorch>
<VerticalSyncPulse>3</VerticalSyncPulse>
<VerticalSyncSkew>0</VerticalSyncSkew>
<VerticalTopBorder>0</VerticalTopBorder>
<VerticalBottomBorder>0</VerticalBottomBorder>
<InvertDataPolarity>False</InvertDataPolarity>
<InvertVsyncPolairty>False</InvertVsyncPolairty>
<InvertHsyncPolarity>False</InvertHsyncPolarity>
<BorderColor>0x0</BorderColor>
</Group>
<Group id='EDID Configuration'>
 <ManufactureID>0x104D</ManufactureID>
 <ProductCode>7180</ProductCode>
 <SerialNumber>0x00001</SerialNumber>
 <WeekofManufacture>0x01</WeekofManufacture>
 <YearofManufacture>0x1B</YearofManufacture>
 <EDIDVersion>1</EDIDVersion>
 <EDIDRevision>3</EDIDRevision>
 <VideoInputDefinition>0x80</VideoInputDefinition>
 <HorizontalScreenSize>0x07</HorizontalScreenSize>
 <VerticalScreenSize>0x0E</VerticalScreenSize>
 <DisplayTransferCharacteristics>0x78</DisplayTransferCharacteristics>
 <FeatureSupport>0x2</FeatureSupport>
 <Red.GreenBits>0xA5</Red.GreenBits>
 <Blue.WhiteBits>0x58</Blue.WhiteBits>
 <RedX>0xA6</RedX>
 <RedY>0x54</RedY>
 <GreenX>0x33</GreenX>
 <GreenY>0xB3</GreenY>
 <BlueX>0x26</BlueX>
 <BlueY>0x12</BlueY>
 <WhiteX>0x4F</WhiteX>
 <WhiteY>0x54</WhiteY>
 <EstablishedTimingsI>0x0</EstablishedTimingsI>
 <EstablishedTimingsII>0x0</EstablishedTimingsII>
 <ManufacturesTiming>0x0</ManufacturesTiming>
 <StandardTimings1/>
 <StandardTimings2/>
 <StandardTimings3/>
 <StandardTimings4/>
 <StandardTimings5/>
 <StandardTimings6/>
 <StandardTimings7/>
 <SignalTimingInterface/>
</Group>
<Group id='Detailed Timing'>
 <HorizontalScreenSizeMM>0x43</HorizontalScreenSizeMM>
 <VerticalScreenSizeMM>0x91</VerticalScreenSizeMM>
 <HorizontalVerticalScreenSizeMM>0x00</HorizontalVerticalScreenSizeMM>
</Group>
<Group id='Display Interface'>
<InterfaceType>9</InterfaceType>
<InterfaceColorFormat>3</InterfaceColorFormat>
</Group>
<Group id='DSI Interface'>
<DSIChannelId>1</DSIChannelId>
<DSIVirtualId>0</DSIVirtualId>
<DSIColorFormat>36</DSIColorFormat>
<DSITrafficMode>1</DSITrafficMode>
<DSILanes>4</DSILanes>
<DSIRefreshRate>0x3C0000</DSIRefreshRate>
<DSICmdSwapInterface>False</DSICmdSwapInterface>
<DSICmdUsingTrigger>False</DSICmdUsingTrigger>
<DSIEnableAutoRefresh>True</DSIEnableAutoRefresh>
<DSIAutoRefreshFrameNumDiv>1</DSIAutoRefreshFrameNumDiv>
<DSIControllerMapping>00</DSIControllerMapping>
<DSITECheckEnable>True</DSITECheckEnable>
<DSITEUsingDedicatedTEPin>True</DSITEUsingDedicatedTEPin>
<DSITimingCLKPrepareOverride>True</DSITimingCLKPrepareOverride>
<DSITEvSyncStartPos>2340</DSITEvSyncStartPos>
<DSITEvSyncInitVal>2340</DSITEvSyncInitVal>
<DSITimingCLKPrepareValue>7</DSITimingCLKPrepareValue>
<DSITimingHSPrepareOverride>True</DSITimingHSPrepareOverride>
<DSITimingHSPrepareValue>7</DSITimingHSPrepareValue>
<DSIEnterULPSPowerDown>True</DSIEnterULPSPowerDown>
<DSILowPowerModeInBLLPEOF>True</DSILowPowerModeInBLLPEOF>
<DSILowPowerModeInBLLP>True</DSILowPowerModeInBLLP>
</Group>
<DSIInitSequence>
15 FF 23
15 FB 01
15 07 20
15 08 04
15 09 00
15 FF 25
15 FB 01
15 18 96
15 05 04
15 FF 27
15 FB 01
15 D9 10
15 FF 24
15 FB 01
15 82 13
15 84 31
15 88 13
15 8A 31
15 8E E4
15 8F 01
15 90 80
15 9D B0
15 FF 26
15 FB 01
15 A9 12
15 AA 10
15 AE 8A
15 1C FA
15 FF 10
15 B0 01
15 51 B8
39 68 06 04
15 53 2C
15 55 00
05 29 00
05 11 00
</DSIInitSequence>
<DSITermSequence>
15 ff 10
05 28
FF 14
05 10
FF 78
</DSITermSequence>
<Group id='Backlight Configuration'>
<BacklightType>3</BacklightType>
<BacklightPmicControlType>2</BacklightPmicControlType>
<DisplayResetInfo>0 10 10000 10000 0</DisplayResetInfo>
<BacklightSteps>1</BacklightSteps>
<BrightnessMaxLuminance>430000</BrightnessMaxLuminance>
<BrightnessMinLuminance>323</BrightnessMinLuminance>
<BrightnessRangeLevel0>100 400000 1 0</BrightnessRangeLevel0>
</Group>"})
