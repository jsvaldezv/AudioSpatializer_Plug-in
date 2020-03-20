#include "Spacer.h"
#include "math.h"
#include "AudioHelpers.h"

Spacer::Spacer()
{
    
}

Spacer::~Spacer()
{
    
}

//CHANNEL 1
void Spacer::processSpacer1(float* inAudioSpacer, float pTheta, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c1;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c1 = (sqrt((MPI2-pTheta)*(2/MPI)*cos(pTheta)));
        outAudioSpacer[i] = inAudioSpacer[i] * c1;
    }
}

//CHANNEL 2
void Spacer::processSpacer2(float* inAudioSpacer, float pTheta, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c2;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c2 = (sqrt(pTheta*(2/MPI)*sin(pTheta)));
        outAudioSpacer[i] = inAudioSpacer[i] * c2;
    }
}

//CHANNEL 3
void Spacer::processSpacer3(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c3;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c3 = pow(sin(pX), 2) * pow(sin(pY), 2);
        outAudioSpacer[i] = inAudioSpacer[i] * c3;
    }
}

//CHANNEL 4
void Spacer::processSpacer4(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c4;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c4 = pow(cos(pX), 2) * pow(sin(pY), 2);
        outAudioSpacer[i] = inAudioSpacer[i] * c4;
    }
}

//CHANNEL 5
void Spacer::processSpacer5(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c5;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c5 = pow(sin(pX + MPI4), 10) * cos(pY);
        outAudioSpacer[i] = inAudioSpacer[i] * c5;
    }
}

//CHANNEL 6
void Spacer::processSpacer6(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c6;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c6 = pow(sin(pX + MPI4), 10) * sin(pY);
        outAudioSpacer[i] = inAudioSpacer[i] * c6;
    }
}

//CHANNEL 7
void Spacer::processSpacer7(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c7;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c7 = pow(cos(pY + ((3*MPI)/4)), 10) * sin(pX);
        outAudioSpacer[i] = inAudioSpacer[i] * c7;
    }
}

//CHANNEL 8
void Spacer::processSpacer8(float* inAudioSpacer, float pX, float pY, float* outAudioSpacer, int inNumSamplesToRender)
{
    float c8;
    
    for(int i=0; i < inNumSamplesToRender; i++)
    {
        c8 = pow(sin(pY - ((3*MPI)/4)), 10) * sin(pX + MPI2);
        outAudioSpacer[i] = inAudioSpacer[i] * c8;
    }
}
