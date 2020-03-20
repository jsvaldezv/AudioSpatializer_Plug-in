/*
  ==============================================================================

    CenterPanel.cpp
    Created: 28 Jan 2020 10:45:57pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "CenterPanel.h"

CenterPanel::CenterPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar = new MenuBarPanel(inProcessor);
    mMenuBar->setTopLeftPosition(0,0);
    addAndMakeVisible(mMenuBar);
    
    mSpacerPanel = new SpacerPanel(inProcessor);
    mSpacerPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mSpacerPanel);
}

CenterPanel::~CenterPanel()
{
    
}
