/*
  ==============================================================================

    MenuBarPanel.cpp
    Created: 28 Jan 2020 10:47:03pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#include "MenuBarPanel.h"

MenuBarPanel::MenuBarPanel(EspaciadorAudioProcessor* inProcessor)
:   PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}

MenuBarPanel::~MenuBarPanel()
{
    
}
