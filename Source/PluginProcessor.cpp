#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AudioHelpers.h"

EspaciadorAudioProcessor::EspaciadorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       /*.withInput  ("Mono In 1",   AudioChannelSet::mono(), true)
                       .withInput  ("Mono In 2",   AudioChannelSet::mono(), true)
                       .withInput  ("Mono In 3",   AudioChannelSet::mono(), true)
                       .withInput  ("Mono In 4",   AudioChannelSet::mono(), true)*/
                       .withInput  ("Input",   AudioChannelSet::mono(),true)
                       
                      #endif
                       /*.withOutput  ("Mono Out 1",   AudioChannelSet::mono(), true)
                       .withOutput  ("Mono Out 2",   AudioChannelSet::mono(), true)
                       .withOutput  ("Mono Out 3",   AudioChannelSet::mono(), true)
                       .withOutput  ("Mono Out 4",   AudioChannelSet::mono(), true)*/
                       .withOutput ("Output", AudioChannelSet::octagonal(),true)
                     #endif
                       ), highPassFilter(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20000.f, 0.09f)),
                          lowPassFilter(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000.f, 0.09f))

#endif
{
   // initializeDSP();
    //INPUT
    addParameter(mInputGain = new AudioParameterFloat("mInputGain","Input", 0.f, 1.f, 0.5f));
    //THETA
    addParameter(mParameterTheta = new AudioParameterFloat("mParameterTheta", "Theta", 0.0f, (M_PI/2) * 1.0f, (M_PI/4)));
    //X
    addParameter(mParameterX = new AudioParameterFloat("mParameterX", "GainX", 0.0f, (M_PI/2) * 1.0f, 0));
    //Y
    addParameter(mParameterY = new AudioParameterFloat("mParameterY", "GainY", 0.0f, (M_PI/2) * 1.0f, 0));
    //COMBOBOX
    addParameter(mChoiceChannels = new AudioParameterInt("mChoiceChannels", "Channels", 1, 3, 1));
    //CUTOFF HIGH
    addParameter(mParameterCutOffHigh = new AudioParameterFloat("mParameterCutOffHigh","CutOffHigh", 20.f, 20000.f, 20.f));
    //CUTOFF LOW
     addParameter(mParameterCutOffLow = new AudioParameterFloat("mParameterCutOffLow","CutOffLow", 20.f, 20000.f, 20000.f));
    //RESONANCE HIGH
    addParameter(mParameterResHigh = new AudioParameterFloat("mParameterResHigh","ResonanceHigh", 1.f, 7.f, 1.f));
    //RESONANCE LOW
    addParameter(mParameterResLow = new AudioParameterFloat("mParameterResLow","ResonanceLow", 1.f, 7.f, 1.f));
    //OUTPUT
    addParameter(mOutputGain = new AudioParameterFloat("mOutputGain","Output", 0.f, 1.f, 0.5f));
}
EspaciadorAudioProcessor::~EspaciadorAudioProcessor()
{
}

const String EspaciadorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EspaciadorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EspaciadorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool EspaciadorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double EspaciadorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EspaciadorAudioProcessor::getNumPrograms()
{
    return 1;
}

int EspaciadorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EspaciadorAudioProcessor::setCurrentProgram (int index)
{
}

const String EspaciadorAudioProcessor::getProgramName (int index)
{
    return {};
}

void EspaciadorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void EspaciadorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;

    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    highPassFilter.prepare(spec);
    highPassFilter.reset();

    lowPassFilter.prepare(spec);
    lowPassFilter.reset();
}

void EspaciadorAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EspaciadorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  /*#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif*/
    
    return ((! layouts.getMainInputChannelSet() .isDiscreteLayout())
        && (! layouts.getMainOutputChannelSet().isDiscreteLayout())
        && (layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet())
        && (! layouts.getMainInputChannelSet().isDisabled()));
}
#endif

void EspaciadorAudioProcessor::updateFilter()
{
    float CutHigh = *mParameterCutOffHigh;
    float CutLow = *mParameterCutOffLow;
    float ResHigh = *mParameterResHigh;
    float ResLow = *mParameterResLow;
    
    *highPassFilter.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, CutHigh, ResHigh);
    *lowPassFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, CutLow, ResLow);
}

void EspaciadorAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
//***************************************************************************************************
    
    auto* channeldata1 = buffer.getWritePointer(0);
    auto* channeldata2 = buffer.getWritePointer(1);
    auto* channeldata3 = buffer.getWritePointer(2);
    auto* channeldata4 = buffer.getWritePointer(3);
    auto* channeldata5 = buffer.getWritePointer(4);
    auto* channeldata6 = buffer.getWritePointer(5);
    auto* channeldata7 = buffer.getWritePointer(6);
    auto* channeldata8 = buffer.getWritePointer(7);
    
    float input = *mInputGain;
    float theta = *mParameterTheta;
    float sX = *mParameterX;
    float sY = *mParameterY;
    int choice = *mChoiceChannels;
    float output = *mOutputGain;
    double g1, g2, g3, g4, g5, g6, g7, g8, gR, gL;
    float gVolIn, gVolOut;
    
    gVolIn = jmap(input, 0.0f, 1.0f, -24.0f, 24.0f);
    gVolIn = Decibels::decibelsToGain(gVolIn, -24.0f);
    
    gVolOut = jmap(output, 0.0f, 1.0f, -24.0f, 24.0f);
    gVolOut = Decibels::decibelsToGain(gVolOut, -24.0f);
    
    gR = (sqrt(theta*(2/MPI)*sin(theta)));
    gL = (sqrt((MPI2-theta)*(2/MPI)*cos(theta)));
    
    /*g1 = cos(pX) * cos(pY);
    g2 = sin(pX) * cos(pY);
    g3 = sin(pX) * sin(pY);
    g4 = cos(pX) * sin(pY);*/
    
    g1 = pow(cos(sX), 2) * pow(cos(sY), 2);
    g2 = pow(sin(sX), 2) * pow(cos(sY), 2);
    g3 = pow(sin(sX), 2) * pow(sin(sY), 2);
    g4 = pow(cos(sX), 2) * pow(sin(sY), 2);
    g5 = pow(sin(sX + M_PI_4), 10) * cos(sY);
    g6 = pow(sin(sX + M_PI_4), 10) * sin(sY);
    g7 = pow(cos(sY + ((3*M_PI)/4)), 10) * sin(sX);
    g8 = pow(sin(sY - ((3*M_PI)/4)), 10) * sin(sX + M_PI_2);
    
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        //VARIABLES PARA CANALES
        //MODIFICAMOS LA GANANCIA DE LOS CANALES
        //REGRESA VALORES AL ARREGLO DEL BUFFER CON LOS VALORES YA MODIFICADOS
        if (choice == 1)
        {
            channeldata1[i] *= gL * gVolIn * gVolOut;
            channeldata2[i] *= gR * gVolIn * gVolOut;
        }
        
        if (choice == 2)
        {
            channeldata1[i] *= g1 * gVolOut;
            channeldata2[i] *= g2 * gVolOut;
            channeldata3[i] *= g3 * gVolOut;
            channeldata4[i] *= g4 * gVolOut;
        }
        
        if (choice == 3)
        {
            channeldata1[i] *= g1 * gVolOut;
            channeldata2[i] *= g2 * gVolOut;
            channeldata3[i] *= g3 * gVolOut;
            channeldata4[i] *= g4 * gVolOut;
            channeldata5[i] *= g5 * gVolOut;
            channeldata6[i] *= g6 * gVolOut;
            channeldata7[i] *= g7 * gVolOut;
            channeldata8[i] *= g8 * gVolOut;
        }
    }

    dsp::AudioBlock<float> block (buffer);
    //updateFilter();
    //highPassFilter.process(dsp::ProcessContextReplacing<float> (block));
    //lowPassFilter.process(dsp::ProcessContextReplacing<float> (block));
}

bool EspaciadorAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* EspaciadorAudioProcessor::createEditor()
{
    return new EspaciadorAudioProcessorEditor (*this);
}

void EspaciadorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void EspaciadorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//******************************************************************************************
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EspaciadorAudioProcessor();
}


