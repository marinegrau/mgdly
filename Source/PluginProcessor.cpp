/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TestPluginAudioProcessor::TestPluginAudioProcessor()


#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor(BusesProperties()
    #if ! JucePlugin_IsMidiEffect
      #if ! JucePlugin_IsSynth
                 .withInput("Input", AudioChannelSet::stereo(), true)
                 #endif
                 .withOutput("Output", AudioChannelSet::stereo(), true)
                 #endif
                 )
#endif
, delayBuffer(2,1)
{
    //set default values
    delayLength = 0;
    delayBufferLength = 1;
    delayReadPosition = 0;
    delayWritePosition = 0;
    currentTimeSetting = timeUnits::samples;
}

//==============================================================================

/*TestPluginAudioProcessor::TestPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
 //set default values
 delayLength = 10000;
 delayBufferLength = 10000;
 delayReadPosition = 0;
 delayWritePosition = 0;
}
*/


TestPluginAudioProcessor::~TestPluginAudioProcessor()
{
}

//==============================================================================

float TestPluginAudioProcessor::getParameter(int index)
{
    switch(index) {
        case delayLengthParam:
            return delayLength;
        case timeUnitParam:
            return currentTimeSetting;
        case addTime:
            return addTimeToDelay;
        default:
            return 0.0f;
            
    }
}
void TestPluginAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {

        case delayLengthParam:
                                                    // Ensure boundaries of delayLength
            if(newValue<0)
                delayLength = 0;
            else if(newValue>delayBufferLength)
                delayLength = delayBufferLength;
            else
                delayLength = newValue;
            
            delayReadPosition = (int) (delayWritePosition - (delayLength) + delayBufferLength) % delayBufferLength;
            break;
        case addTime:
            addTimeToDelay = newValue;
        case timeUnitParam:
            int index2 = (int) newValue;
            switch (index2) {
                case TestPluginAudioProcessor::timeUnits::samples:
                    currentTimeSetting = timeUnits::samples;
                    break;
                case TestPluginAudioProcessor::timeUnits::ms:
                    currentTimeSetting = timeUnits::ms;
                    break;
                case TestPluginAudioProcessor::timeUnits::meter:
                    currentTimeSetting= timeUnits::meter;
                    break;
                default:
                    break;
            };
        
    }
}

String TestPluginAudioProcessor::getTrackName()
{
    //String name = &TestPluginAudioProcessor::TrackProperties::name; conversion error -.- TODO
    return "name";

}

void TestPluginAudioProcessor::setCurrentTimeSetting(TestPluginAudioProcessor::timeUnits unit)
{
    currentTimeSetting = unit;
}

TestPluginAudioProcessor::timeUnits TestPluginAudioProcessor::getCurrentTimeSetting(){
    return currentTimeSetting;
}

const String TestPluginAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case delayLengthParam:
            return "delay";
        case timeUnitParam:
            return "timeUnit";
        default:
            return String::empty;
    }
}

int TestPluginAudioProcessor::getDelayBufferLength()
{
    return TestPluginAudioProcessor::delayBufferLength;
}



const String TestPluginAudioProcessor::getParameterText (int index)
{
    return String();
}

const String TestPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TestPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TestPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TestPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TestPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TestPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TestPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TestPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String TestPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void TestPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TestPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    TestPluginAudioProcessor::sampleRate = sampleRate;
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    delayBufferLength  = (int) 2.0 * sampleRate;        // 2 seconds delay Buffer
    if (delayBufferLength < 1)
        delayBufferLength = 1;
    
    delayBuffer.setSize(2, delayBufferLength);
    delayBuffer.clear();
    
    delayReadPosition = (int) (delayWritePosition - (delayLength) + delayBufferLength) % delayBufferLength;     // TODO -1 seems to solve it. test.
}

void TestPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TestPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TestPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
     // This code block deals with the Audio buffer, which is not needed for this project.
     
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();
    
    int dpr, dpw;
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        float* delayData = delayBuffer.getWritePointer(jmin(channel, delayBuffer.getNumChannels() - 1));
        
        dpr = delayReadPosition;
        dpw = delayWritePosition;
        
        // ..do something to the data...
        for(int i = 0; i < numSamples; ++i)
        {
            const float in = channelData[i];
            float out = 0.0;
            
            if (delayLength==0)
                out = in;
            else
                out = delayData[dpr];
            
            delayData[dpw] = in;
            
            if(++dpr >= delayBufferLength)
                dpr = 0;
            if(++dpw >= delayBufferLength)
                dpw = 0;
            
            channelData[i] = out;
        }
    }
    
    delayReadPosition = dpr;
    delayWritePosition = dpw;
  
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
}

    


//==============================================================================
bool TestPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TestPluginAudioProcessor::createEditor()
{
    return new TestPluginAudioProcessorEditor (*this);
}

//==============================================================================
void TestPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TestPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TestPluginAudioProcessor();
}
