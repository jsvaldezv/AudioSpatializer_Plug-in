#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Background.h"
#include "InterfaceDefines.h"

EspaciadorAudioProcessorEditor::EspaciadorAudioProcessorEditor (EspaciadorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = new MainPanel(&processor);
    addAndMakeVisible(mMainPanel);
    
    initializeGUI();
    setLookAndFeel(&jsvLookAndFeel);
    
    mBackgroundImage = ImageCache::getFromMemory(BinaryData::fondo_png, BinaryData::fondo_pngSize);
}

EspaciadorAudioProcessorEditor::~EspaciadorAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

void EspaciadorAudioProcessorEditor::paint (Graphics& g)
{    
    g.drawImage(mBackgroundImage, getLocalBounds().toFloat());
}

void EspaciadorAudioProcessorEditor::resized()
{
}

void EspaciadorAudioProcessorEditor::initializeGUI()
{
    auto& params = processor.getParameters();
    
    const int slider_size = 45;
    
//************************************************************************************************
    //Parametro de Input
    AudioParameterFloat* parameterInput = (AudioParameterFloat*)params.getUnchecked(0);
    sliderInput.setBounds(30, (getHeight() * 0.5) - (slider_size * 0.5), slider_size, slider_size);
    sliderInput.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderInput.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderInput.setRange(parameterInput->range.start, parameterInput->range.end);
    sliderInput.setValue(*parameterInput);
    addAndMakeVisible(sliderInput);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderInput.onValueChange = [this, parameterInput] { *parameterInput = sliderInput.getValue(); };
    sliderInput.onDragStart = [parameterInput] { parameterInput->beginChangeGesture(); };
    sliderInput.onDragEnd = [parameterInput] { parameterInput->endChangeGesture(); };
    
    //ETIQUETA DE INPUT
    addAndMakeVisible (labelInput);
    labelInput.setText ("Input", dontSendNotification);
    labelInput.setJustificationType(Justification::centred);
    labelInput.attachToComponent (&sliderInput, true);
    labelInput.setCentrePosition(37, (getHeight() * 0.5) + (slider_size * 0.5) + 20);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de Theta
    AudioParameterFloat* parameterTheta = (AudioParameterFloat*)params.getUnchecked(1);
    sliderTheta.setBounds((550 / 5) - (slider_size * 0.5) + 100, (getHeight() * 0.5) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderTheta.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderTheta.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderTheta.setRange(parameterTheta->range.start, parameterTheta->range.end);
    sliderTheta.setValue(*parameterTheta);
    addAndMakeVisible(sliderTheta);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderTheta.onValueChange = [this, parameterTheta] { *parameterTheta = sliderTheta.getValue(); };
    sliderTheta.onDragStart = [parameterTheta] { parameterTheta->beginChangeGesture(); };
    sliderTheta.onDragEnd = [parameterTheta] { parameterTheta->endChangeGesture(); };
    
    //ETIQUETA DE THETA
    addAndMakeVisible (labelTheta);
    labelTheta.setText ("Pan", dontSendNotification);
    labelTheta.setJustificationType(Justification::centred);
    labelTheta.attachToComponent (&sliderTheta, true);
    labelTheta.setCentrePosition(210, 215);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de X
    AudioParameterFloat* parameterAxisX = (AudioParameterFloat*)params.getUnchecked(2);
    sliderAxisX.setBounds(((550 / 5) * 2) - (slider_size * 0.5) + 100, (getHeight() / 3) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderAxisX.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderAxisX.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderAxisX.setRange(parameterAxisX->range.start, parameterAxisX->range.end);
    sliderAxisX.setValue(*parameterAxisX);
    addAndMakeVisible(sliderAxisX);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderAxisX.onValueChange = [this, parameterAxisX] { *parameterAxisX = sliderAxisX.getValue(); };
    sliderAxisX.onDragStart = [parameterAxisX] { parameterAxisX->beginChangeGesture(); };
    sliderAxisX.onDragEnd = [parameterAxisX] { parameterAxisX->endChangeGesture(); };
    
    //ETIQUETA DE X
    addAndMakeVisible (labelAxisX);
    labelAxisX.setText ("Axis X", dontSendNotification);
    labelAxisX.setJustificationType(Justification::centred);
    labelAxisX.attachToComponent (&sliderAxisX, true);
    labelAxisX.setCentrePosition(320, 163);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de Y
    AudioParameterFloat* parameterAxisY = (AudioParameterFloat*)params.getUnchecked(3);
    sliderAxisY.setBounds(((550 / 5) * 2) - (slider_size * 0.5) + 100, ((getHeight() / 3) * 2) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderAxisY.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderAxisY.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderAxisY.setRange(parameterAxisY->range.start, parameterAxisY->range.end);
    sliderAxisY.setValue(*parameterAxisY);
    addAndMakeVisible(sliderAxisY);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderAxisY.onValueChange = [this, parameterAxisY] { *parameterAxisY = sliderAxisY.getValue(); };
    sliderAxisY.onDragStart = [parameterAxisY] { parameterAxisY->beginChangeGesture(); };
    sliderAxisY.onDragEnd = [parameterAxisY] { parameterAxisY->endChangeGesture(); };
    
    //ETIQUETA DE Y
    addAndMakeVisible (labelAxisY);
    labelAxisY.setText ("Axis Y", dontSendNotification);
    labelAxisY.setJustificationType(Justification::centred);
    labelAxisY.attachToComponent (&sliderAxisY, true);
    labelAxisY.setCentrePosition(320, 263);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //COMBOBOX Channels
    AudioParameterFloat* parameterChoiceChannels = (AudioParameterFloat*)params.getUnchecked(4);
    
    boxChoiceChannels.setBounds(530, 18, 200, 30);
    boxChoiceChannels.setColour(ComboBox::backgroundColourId, Colours::black);
    boxChoiceChannels.setColour(ComboBox::outlineColourId, Colours::ghostwhite);
    boxChoiceChannels.setColour(ComboBox::arrowColourId, Colours::ghostwhite);
    boxChoiceChannels.setColour(ComboBox::textColourId, Colours::ghostwhite);
    boxChoiceChannels.addItem ("Two Channels", 1);
    boxChoiceChannels.addItem ("Four Channels", 2);
    boxChoiceChannels.addItem ("Eight Channels", 3);
    addAndMakeVisible (boxChoiceChannels);
    
    boxChoiceChannels.onChange = [this, parameterChoiceChannels] { *parameterChoiceChannels = boxChoiceChannels.getSelectedId(); };
    boxChoiceChannels.setSelectedId (1);

//************************************************************************************************
    //Parametro de cutoff high
    AudioParameterFloat* parameterCutOffHigh = (AudioParameterFloat*)params.getUnchecked(5);
    sliderCutOffHigh.setBounds(((550 / 5) * 3) - (slider_size * 0.5) + 100, ((getHeight() / 3)) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderCutOffHigh.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderCutOffHigh.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderCutOffHigh.setRange(parameterCutOffHigh->range.start, parameterCutOffHigh->range.end);
    sliderCutOffHigh.setValue(*parameterCutOffHigh);
    addAndMakeVisible(sliderCutOffHigh);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderCutOffHigh.onValueChange = [this, parameterCutOffHigh] { *parameterCutOffHigh = sliderCutOffHigh.getValue(); };
    sliderCutOffHigh.onDragStart = [parameterCutOffHigh] { parameterCutOffHigh->beginChangeGesture(); };
    sliderCutOffHigh.onDragEnd = [parameterCutOffHigh] { parameterCutOffHigh->endChangeGesture(); };
    
    //ETIQUETA DE CUTOFF HIGH
    addAndMakeVisible (labelCutOffHigh);
    labelCutOffHigh.setText ("High Pass", dontSendNotification);
    labelCutOffHigh.setJustificationType(Justification::centred);
    labelCutOffHigh.attachToComponent (&sliderCutOffHigh, true);
    labelCutOffHigh.setCentrePosition(430, 163);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de cutoff low
    AudioParameterFloat* parameterCutOffLow = (AudioParameterFloat*)params.getUnchecked(6);
    sliderCutOffLow.setBounds(((550 / 5) * 3) - (slider_size * 0.5) + 100, ((getHeight() / 3) * 2) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderCutOffLow.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderCutOffLow.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderCutOffLow.setRange(parameterCutOffLow->range.start, parameterCutOffLow->range.end);
    sliderCutOffLow.setValue(*parameterCutOffLow);
    addAndMakeVisible(sliderCutOffLow);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderCutOffLow.onValueChange = [this, parameterCutOffLow] { *parameterCutOffLow = sliderCutOffLow.getValue(); };
    sliderCutOffLow.onDragStart = [parameterCutOffLow] { parameterCutOffLow->beginChangeGesture(); };
    sliderCutOffLow.onDragEnd = [parameterCutOffLow] { parameterCutOffLow->endChangeGesture(); };
    
    //ETIQUETA DE CUTOFF LOW
    addAndMakeVisible (labelCutOffLow);
    labelCutOffLow.setText ("Low Pass", dontSendNotification);
    labelCutOffLow.setJustificationType(Justification::centred);
    labelCutOffLow.attachToComponent (&sliderCutOffLow, true);
    labelCutOffLow.setCentrePosition(430, 263);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de Res High
    AudioParameterFloat* parameterResHigh = (AudioParameterFloat*)params.getUnchecked(7);
    sliderResHigh.setBounds(((550 / 5) * 4) - (slider_size * 0.5) + 100, ((getHeight() / 3)) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderResHigh.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderResHigh.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderResHigh.setRange(parameterResHigh->range.start, parameterResHigh->range.end);
    sliderResHigh.setValue(*parameterResHigh);
    addAndMakeVisible(sliderResHigh);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderResHigh.onValueChange = [this, parameterResHigh] { *parameterResHigh = sliderResHigh.getValue(); };
    sliderResHigh.onDragStart = [parameterResHigh] { parameterResHigh->beginChangeGesture(); };
    sliderResHigh.onDragEnd = [parameterResHigh] { parameterResHigh->endChangeGesture(); };
    
    //ETIQUETA DE RES HIGH
    addAndMakeVisible (labelResHigh);
    labelResHigh.setText ("High Resonance", dontSendNotification);
    labelResHigh.setJustificationType(Justification::centred);
    labelResHigh.attachToComponent (&sliderResHigh, true);
    labelResHigh.setCentrePosition(540, 163);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de Res Low
    AudioParameterFloat* parameterResLow = (AudioParameterFloat*)params.getUnchecked(8);
    sliderResLow.setBounds(((550 / 5) * 4) - (slider_size * 0.5) + 100, ((getHeight() / 3) * 2) - (slider_size * 0.5) + 35, slider_size, slider_size);
    sliderResLow.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderResLow.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderResLow.setRange(parameterResLow->range.start, parameterResLow->range.end);
    sliderResLow.setValue(*parameterResLow);
    addAndMakeVisible(sliderResLow);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderResLow.onValueChange = [this, parameterResLow] { *parameterResLow = sliderResLow.getValue(); };
    sliderResLow.onDragStart = [parameterResLow] { parameterResLow->beginChangeGesture(); };
    sliderResLow.onDragEnd = [parameterResLow] { parameterResLow->endChangeGesture(); };
    
    //ETIQUETA DE RES LOW
    addAndMakeVisible (labelResLow);
    labelResLow.setText ("Low Resonance", dontSendNotification);
    labelResLow.setJustificationType(Justification::centred);
    labelResLow.attachToComponent (&sliderResLow, true);
    labelResLow.setCentrePosition(540, 263);
    labelInput.setSize(60, 20);

//************************************************************************************************
    //Parametro de Output
    AudioParameterFloat* parameterOutput = (AudioParameterFloat*)params.getUnchecked(9);
    sliderOutput.setBounds(680, (getHeight() * 0.5) - (slider_size * 0.5), slider_size, slider_size);
    sliderOutput.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    sliderOutput.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderOutput.setRange(parameterOutput->range.start, parameterOutput->range.end);
    sliderOutput.setValue(*parameterOutput);
    addAndMakeVisible(sliderOutput);
    
    // Funciones Lambda para conectar el Slider gráfico con el Procesor
    sliderOutput.onValueChange = [this, parameterOutput] { *parameterOutput = sliderOutput.getValue(); };
    sliderOutput.onDragStart = [parameterOutput] { parameterOutput->beginChangeGesture(); };
    sliderOutput.onDragEnd = [parameterOutput] { parameterOutput->endChangeGesture(); };
    
    //ETIQUETA DE OUTPUT
    addAndMakeVisible (labelOutput);
    labelOutput.setText ("Output", dontSendNotification);
    labelOutput.setJustificationType(Justification::centred);
    labelOutput.attachToComponent (&sliderOutput, true);
    labelOutput.setCentrePosition(700, (getHeight() * 0.5) + (slider_size * 0.5) + 20);
    labelInput.setSize(60, 20);
}
