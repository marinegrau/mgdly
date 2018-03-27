/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TestPluginAudioProcessorEditor  : public AudioProcessorEditor,
                                        private Slider::Listener,
                                        private Button::Listener,
                                        private Label::Listener,
                                        private TextEditor::Listener
{
public:
    TestPluginAudioProcessorEditor (TestPluginAudioProcessor&);
    ~TestPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //void setDelayLength(int unit, float delayTime);
    void updateLabels();
    enum strengthEnum{          //in ermangelung eines besseren Namens
        min = 0,
        mid = 1,
        max = 2
    };
    enum plusMinus {
        inc = 0,
        dec = 1
    };
    
private:
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* button) override;
    void labelTextChanged (Label* labelThatHasChanged) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TestPluginAudioProcessor& processor;
    
    TextButton incDelayMin;     // increase delay by minimum value
    TextButton decDelayMin;     // decrease delay by minimum value
    TextButton incDelayMid;
    TextButton decDelayMid;
    TextButton incDelayMax;
    TextButton decDelayMax;
    TextButton addDelay;
    TextEditor addDelayEditor;
    float timeToAddToDelay;
    /*
    TextButton msButton;
    TextButton samplesButton;
    TextButton meterButton;
    */
    
    Slider midiVolume;
    Label samplesLabel;
    Label msLabel;
    Label meterLabel;
    Label trackNameLabel;
    Label samplesTextLabel;
    Label msTextLabel;
    Label meterTextLabel;
    
    
    
    Colour labelTextColour;
    Colour labelTextColourMouseOver;
    Colour labelBGselected;
    Colour labelBGdeselected;
    
    void mouseDown(const MouseEvent& e) override;
    void mouseEnter(const MouseEvent& e) override;
    void mouseExit(const MouseEvent& e) override;
    
    //void textEditorTextChanged(TextEditor &t) override;
    void textEditorReturnKeyPressed(TextEditor &t) override;
    void textEditorEscapeKeyPressed(TextEditor &t) override;
    void textEditorFocusLost (TextEditor &t) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestPluginAudioProcessorEditor);
    
    
    
    // Helper Methods
    void incDecDelay(float samples, int incDec);
    float convertToSamples(int unit, float value);
    int getCurrentTimeUnit();
    float getDelayLength();
    float getFactor(int unit, int strength);
    bool isFloat(String text);
    int countCharOccurencesInString(String string, char a);
    void setDelayTime(int samples);
    void updateTimeLabelColours();

};
