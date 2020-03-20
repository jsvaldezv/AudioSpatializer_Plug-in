/*
  ==============================================================================

    MainPanel.cpp
    Created: 28 Jan 2020 10:45:45pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "MainPanel.h"

MainPanel::MainPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = new TopPanel(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
    
    mCenterPanel = new CenterPanel(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel);
    
}

MainPanel::~MainPanel()
{
    
}
