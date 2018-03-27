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
class TheDelayAudioProcessorEditor  : public AudioProcessorEditor,
                                        private Slider::Listener,
                                        private Button::Listener,
                                        private Label::Listener,
                                        private TextEditor::Listener
{
public:
    TheDelayAudioProcessorEditor (TheDelayAudioProcessor&);
    ~TheDelayAudioProcessorEditor();

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
    TheDelayAudioProcessor& processor;
    
    TextButton incDelayMin;     // increase delay by minimum value
    TextButton decDelayMin;     // decrease delay by minimum value
    TextButton incDelayMid;
    TextButton decDelayMid;
    TextButton incDelayMax;
    TextButton decDelayMax;
    TextButton addDelay;
    TextEditor addDelayEditor;
    double timeToAddToDelay;
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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TheDelayAudioProcessorEditor);
    
    
    
    // Helper Methods
    void incDecDelay(double samples, int incDec);
    double convertToSamples(int unit, double value);
    int getCurrentTimeUnit();
    double getDelayLength();
    double getFactor(int unit, int strength);
    bool isDouble(String text);
    int countCharOccurencesInString(String string, char a);
    void setDelayTime(int samples);
    void updateTimeLabelColours();

};
