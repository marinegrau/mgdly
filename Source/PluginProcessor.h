/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class TheDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    TheDelayAudioProcessor();
    ~TheDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    
    enum Parameters
    {
        delayLengthParam = 0,
        timeUnitParam = 1,
        addTime
    };
    enum timeUnits{
        samples = 0,
        ms = 1,
        meter = 2,
    };
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    void getDelayLength();
    int getDelayBufferLength();
    void setDelayLength(int unit, float delayTime);
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    double getParameter (int index) override;
    void setParameter (int index, float newValue) override;
    const String getParameterName (int index) override;
    const String getParameterText (int index) override;
    String getTrackName();
    
    // Delay Line
   
    String trackname;
    double sampleRate;
    double delayLength;
    double addTimeToDelay;
    int delayBufferLength;
    timeUnits currentTimeSetting;
    timeUnits getCurrentTimeSetting();
    void setCurrentTimeSetting(timeUnits unit);
    void setDelayTime(double delayTime, timeUnits unit);

private:
    // circular buffer variables
    AudioSampleBuffer delayBuffer;
    int delayReadPosition;
    int delayWritePosition;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TheDelayAudioProcessor)
};
