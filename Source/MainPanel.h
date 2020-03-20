/*
  ==============================================================================

    MainPanel.h
    Created: 28 Jan 2020 10:45:45pm
    Author:  Jesús Valdez Vázquez 

  ==============================================================================
*/

#pragma once
#include "PanelBase.h"
#include "TopPanel.h"
#include "GainPanel.h"
#include "CenterPanel.h"


class MainPanel
:   public PanelBase
{
public:
    
    MainPanel(EspaciadorAudioProcessor* inProcessor);
    ~MainPanel();
    
private:
    
    ScopedPointer<TopPanel> mTopPanel;
    ScopedPointer<GainPanel> mInputGainPanel;
    ScopedPointer<GainPanel> mOutputGainPanel;
    ScopedPointer<CenterPanel> mCenterPanel;
    
};
