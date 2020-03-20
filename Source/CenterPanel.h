/*
  ==============================================================================

    CenterPanel.h
    Created: 28 Jan 2020 10:45:57pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#pragma once
#include "PanelBase.h"
#include "MenuBarPanel.h"
#include "SpacerPanel.h"

class CenterPanel
:   public PanelBase
{
public:
    
    CenterPanel(EspaciadorAudioProcessor* inProcessor);
    ~CenterPanel();
    
private:
    
    ScopedPointer<MenuBarPanel> mMenuBar;
    ScopedPointer<SpacerPanel> mSpacerPanel;
    
};
