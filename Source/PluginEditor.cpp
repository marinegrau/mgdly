/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TestPluginAudioProcessorEditor::TestPluginAudioProcessorEditor (TestPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (250, 330);
    
    labelTextColour = Colour(0, 0, 0);                   //black
    labelTextColourMouseOver = Colour(255, 255, 255);    //white
    labelBGselected = Colour(120,120,120);               //mittelgrau
    labelBGdeselected = Colour(80,80,80);                //dunkelgrau
    // ================================ INCDELAYMIN BUTTON =======
    incDelayMin.setName("incmin");
    incDelayMin.setBounds(160, 185, 60, 40);
    incDelayMin.setButtonText("+");
    
    incDelayMin.addListener(this);
    
    // ================================ DECDELAYMIN BUTTON =======
    decDelayMin.setName("decmin");
    decDelayMin.setBounds(160, 235, 60, 40);
    decDelayMin.setButtonText("-");
    
    decDelayMin.addListener(this);
    
    // ================================ INCDELAYMID BUTTON =======
    incDelayMid.setName("incmid");
    incDelayMid.setBounds(90, 185, 60, 40);
    incDelayMid.setButtonText("+");
    
    incDelayMid.addListener(this);
    // ================================ DECDELAYMID BUTTON =======
    decDelayMid.setName("decmid");
    decDelayMid.setBounds(90, 235, 60, 40);
    decDelayMid.setButtonText("-");
    
    decDelayMid.addListener(this);
    
    // ================================ INCDELAYMAX BUTTON =======
    incDelayMax.setName("incmax");
    incDelayMax.setBounds(20, 185, 60, 40);
    incDelayMax.setButtonText("+");
    
    incDelayMax.addListener(this);
    
    // ================================ DECDELAYMAX BUTTON =======
    decDelayMax.setName("decmax");
    decDelayMax.setBounds(20, 235, 60, 40);
        decDelayMax.setButtonText("-");
    
    decDelayMax.addListener(this);
    
    // =============================== ADD DELAY BUTTON =========
    addDelay.setName("addDelay");
    addDelay.setBounds(90, 285, 60, 40 );
    addDelay.setButtonText("add");
    
    addDelay.addListener(this);
    
    // ============================== ADD DELAY EDITOR =========
    addDelayEditor.setBounds(90, 285, 60, 40);
    addDelayEditor.addListener(this);
    // addDelayEditor.setVisible(false); This has to be done after addAndMakeVisible
    
    
    // ==================  LABELS =================
//    trackNameLabel.setName("trackNameLabel");
//    trackNameLabel.setBounds(20, 10, 300, 40);
//    trackNameLabel.setText("This is the trackname", dontSendNotification);
//    trackNameLabel.setEditable(false, false);
//    trackNameLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    
    samplesTextLabel.setText("samples", dontSendNotification);
    samplesTextLabel.setBounds(125, 40, 100, 40);
    samplesTextLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    
    msTextLabel.setText("milliseconds", dontSendNotification);
    msTextLabel.setBounds(125, 90, 100, 40);
    msTextLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    
    meterTextLabel.setText("meter", dontSendNotification);
    meterTextLabel.setBounds(125, 140, 100, 40);
    meterTextLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    
    samplesLabel.setName("samplesLabel");
    samplesLabel.setBounds(20, 40, 100, 40);
    samplesLabel.setEditable(false, true);  // Not editable on a single click. But editable on a double click
    samplesLabel.addListener(this);
    samplesLabel.addMouseListener(this, false);
    samplesLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    samplesLabel.setJustificationType(juce::Justification::centredRight);
    
    msLabel.setName("msLabel");
    msLabel.setBounds(20, 90, 100, 40);
    msLabel.setEditable(false, true);       // Not editable on a single click. But editable on a double click
    msLabel.addListener(this);
    msLabel.addMouseListener(this, false);
    msLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    msLabel.setJustificationType(juce::Justification::centredRight);


    meterLabel.setName("meterLabel");
    meterLabel.setBounds(20, 140, 100, 40);
    meterLabel.setEditable(false, true);       // Not editable on a single click. But editable on a double click
    meterLabel.addListener(this);
    meterLabel.addMouseListener(this, false);
    meterLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);
    meterLabel.setJustificationType(juce::Justification::centredRight);

    //Filling the Labels with Text and setting colour
    updateLabels();
    updateTimeLabelColours();
    
    //adding components to the editor
    addAndMakeVisible(incDelayMin);
    addAndMakeVisible(decDelayMin);
    addAndMakeVisible(incDelayMid);
    addAndMakeVisible(decDelayMid);
    addAndMakeVisible(incDelayMax);
    addAndMakeVisible(decDelayMax);
    addAndMakeVisible(addDelay);
    addAndMakeVisible(addDelayEditor);
    addDelayEditor.setVisible(false);       // Hide it
    
    
    addAndMakeVisible(trackNameLabel);
    addAndMakeVisible(msLabel);
    addAndMakeVisible(samplesLabel);
    addAndMakeVisible(meterLabel);
    addAndMakeVisible(samplesTextLabel);
    addAndMakeVisible(msTextLabel);
    addAndMakeVisible(meterTextLabel);
}

TestPluginAudioProcessorEditor::~TestPluginAudioProcessorEditor()
{
}


void TestPluginAudioProcessorEditor::paint (Graphics& g)
{

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("NavyGrey TheDelay", 0, 0, getWidth(), 30, Justification::centred, 1);

}

void TestPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //sets the position and size of the slider with arguments (x,y,width,height)
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void TestPluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
}


bool TestPluginAudioProcessorEditor::isFloat(String text){
    text = text.replaceCharacter(',', '.');
    // Check if there aren't any non number characters and there is not more than 1 dot
    bool isFloat = ((text.toStdString().find_first_not_of( "0123456789." ) == std::string::npos) &&
                    (countCharOccurencesInString(text, '.') <= 1));
                    
    return isFloat;
}


int TestPluginAudioProcessorEditor::countCharOccurencesInString(String str, char a)
{
    char checkCharacter = a;
    int count = 0;
    for (int i = 0; i < str.toStdString().size(); i++)
    {
        if (str[i] ==  checkCharacter)
        {
            ++ count;
        }
    }
    return count;
}



void TestPluginAudioProcessorEditor::labelTextChanged(Label* label)
{
    int sampleRate = getAudioProcessor()->getSampleRate();
    if(label == &msLabel){
        float delayTime = 0.0;
        String text = msLabel.getText();
        bool isFloat = TestPluginAudioProcessorEditor::isFloat(text);
        
        if (isFloat) {  // IF TEXT IS A VALID ENTRY
            delayTime = std::stof(text.toStdString()); // set Delaytime to the entered number
            setDelayTime(delayTime * sampleRate / 1000);
            //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, delayTime * sampleRate / 1000);
        }
        updateLabels();

    }

    if(label == &samplesLabel){
        float delayTime = 0.0;
        String text = samplesLabel.getText();
        bool isFloat = (text.toStdString().find_first_not_of( "0123456789" ) == std::string::npos);
        // IF ENTERED TEXT IS VALID
        if (isFloat) {
            delayTime = std::stof(text.toStdString());
            setDelayTime(delayTime);
            //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, delayTime);
        }
        updateLabels();
        
    }

    if(label == &meterLabel){
        float delayTime = 0.0;
        String text = meterLabel.getText();
        bool isFloat = TestPluginAudioProcessorEditor::isFloat(text);
        // IF ENTERED TEXT IS VALID
        if (isFloat)
        {
            delayTime = std::stof(text.toStdString());
            setDelayTime(delayTime * sampleRate / 1000 * (100/343));
            //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, delayTime * sampleRate / 1000 * (100/343));
        }
        updateLabels();
        
    }

    
}
void TestPluginAudioProcessorEditor::updateLabels(){
    int sampleRate = getAudioProcessor()->getSampleRate();
    float delayInSamples = round(getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::delayLengthParam));
    float delayInMs = delayInSamples * 1000 / sampleRate;
    delayInMs = round(delayInMs * 10)/10; // round to 0.1
    float delayInMeters = delayInMs * 0.343;
    delayInMeters = round(delayInMeters * 10) /10;
    samplesLabel.setText((String)delayInSamples, dontSendNotification);
    msLabel.setText((String) delayInMs, dontSendNotification);
    meterLabel.setText((String) delayInMeters, dontSendNotification);
}





void TestPluginAudioProcessorEditor::buttonClicked(Button* button)
{
//switch on button
    
    if (button == &incDelayMin) {
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    
    if (button == &decDelayMin){
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();

    }

    if (button == &incDelayMid) {
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor * 10);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    if (button == &decDelayMid) {
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor * 10);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();
    }
    if (button == &incDelayMax) {
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor * 100);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    if (button == &decDelayMax) {
        int unit = getCurrentTimeUnit();
        float factor = getFactor(unit, min);
        float addDelayInSamples = convertToSamples(unit, factor * 100);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();
    }
    
    if (button == &addDelay) {
        addDelayEditor.setVisible(true);
        addDelayEditor.grabKeyboardFocus();
    }
}


void TestPluginAudioProcessorEditor::updateTimeLabelColours(){
    int param = getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::timeUnitParam);
    switch (param) {
        case TestPluginAudioProcessor::timeUnits::samples:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            break;
        case TestPluginAudioProcessor::timeUnits::ms:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            break;
        case TestPluginAudioProcessor::timeUnits::meter:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            break;
        default:
            break;
    }
    
}
// =========================== BEHAVIOUR FOR LABEL BUTTONS
void TestPluginAudioProcessorEditor::mouseDown(const MouseEvent& e){
    // Setting the timeUnit corresponding to the selected Label
    if (e.eventComponent->getName() == samplesLabel.getName()){
        getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::timeUnitParam, TestPluginAudioProcessor::timeUnits::samples);
    }
    if (e.eventComponent->getName() == msLabel.getName()){
        getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::timeUnitParam, TestPluginAudioProcessor::timeUnits::ms);
    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::timeUnitParam, TestPluginAudioProcessor::timeUnits::meter);
    }
    
    // Set Colours
    updateTimeLabelColours();

}
void TestPluginAudioProcessorEditor::mouseEnter(const MouseEvent& e){
    if (e.eventComponent->getName() == samplesLabel.getName()){
        samplesLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColourMouseOver);
        
    }
    if (e.eventComponent->getName() == msLabel.getName()){
        msLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColourMouseOver);

    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        meterLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColourMouseOver);

    }
}
void TestPluginAudioProcessorEditor::mouseExit(const MouseEvent& e){
    if (e.eventComponent->getName() == samplesLabel.getName()){
        samplesLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);

    }
    if (e.eventComponent->getName() == msLabel.getName()){
        msLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);

    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        meterLabel.setColour(juce::Label::ColourIds::textColourId, TestPluginAudioProcessorEditor::labelTextColour);

    }
}

void TestPluginAudioProcessorEditor::textEditorReturnKeyPressed(TextEditor &t){
    float addTime;
    float oldDelay = getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::delayLengthParam);
    //float addTime = getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::addTime);
    String text;
    text = addDelayEditor.getText();
    bool isFloat = TestPluginAudioProcessorEditor::isFloat(text);
    if (isFloat)
        addTime = std::stof(text.toStdString());
        
    else
    {
        addTime = 0;
        addDelayEditor.setText("");
        addDelayEditor.setVisible(false);
    }
    
    
    
    //=======
    int unit = getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::timeUnitParam);
    int addDelayInSamples;
    double sampleRate = getAudioProcessor()->getSampleRate();
    switch (unit) {
        case TestPluginAudioProcessor::timeUnits::samples:
            addDelayInSamples = addTime;
            break;
        case TestPluginAudioProcessor::timeUnits::ms:
            addDelayInSamples = round(addTime * sampleRate / 1000);
            break;
        case TestPluginAudioProcessor::timeUnits::meter:
            addDelayInSamples = round(addTime * sampleRate / 1000 * 0.2915451895 * 10);
            break;
            //default:
            //  break;
    };
    //=======
    
    
    int newDelayInsamples = oldDelay + addDelayInSamples;
    setDelayTime(newDelayInsamples);
    //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, newDelayInsamples);
    addDelayEditor.setVisible(false);
    updateLabels();
}

void TestPluginAudioProcessorEditor::textEditorEscapeKeyPressed(TextEditor &t){
    //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::addTime, 0.0);
    addDelayEditor.setVisible(false);
    addDelayEditor.setText("");

}

void TestPluginAudioProcessorEditor::textEditorFocusLost(TextEditor &t){
    //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::addTime, 0.0);
    addDelayEditor.setVisible(false);
    addDelayEditor.setText("");
}


void TestPluginAudioProcessorEditor::incDecDelay(float samples, int incDec) {
    int factor;
    float currentDelay;
    float newDelay;
    // Determining whether the delay should be increased or decreased
    switch (incDec) {
        case plusMinus::inc:
            factor = 1;
            break;
        case plusMinus::dec:
            factor = -1;
            break;
        default:
            factor = 0;
            break;
    }
    
    currentDelay = getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::delayLengthParam);
    newDelay = currentDelay + samples * factor;
    setDelayTime(newDelay);
    //getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, newDelay);
}

// ===================== HELPER == FUNCTIONS =======================
/// converts from samples, ms and meters to samples
float TestPluginAudioProcessorEditor::convertToSamples(int unit, float value)
{
    float delayInSamples;
    float sampleRate = (float) getAudioProcessor()->getSampleRate();
    switch (unit) {
        case TestPluginAudioProcessor::timeUnits::samples:
            delayInSamples = roundf(value);
            break;
        case TestPluginAudioProcessor::timeUnits::ms:
            delayInSamples = value * sampleRate / 1000;
            break;
        case TestPluginAudioProcessor::timeUnits::meter:
            delayInSamples = value * sampleRate / 343;
            break;
        default:
            abort();            // If unit is not defined CRASH
    }
    return delayInSamples;
}

int TestPluginAudioProcessorEditor::getCurrentTimeUnit()
{
    return getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::timeUnitParam);
}

float TestPluginAudioProcessorEditor::getDelayLength()
{
    return getAudioProcessor()->getParameter(TestPluginAudioProcessor::Parameters::delayLengthParam);
}

void TestPluginAudioProcessorEditor::setDelayTime(int samples){
    getAudioProcessor()->setParameter(TestPluginAudioProcessor::Parameters::delayLengthParam, samples);
}


float TestPluginAudioProcessorEditor::getFactor(int unit, int strength){
    switch (unit) {
        case TestPluginAudioProcessor::timeUnits::samples:
            switch (strength) {
                case strengthEnum::min:
                    return 1;
                case strengthEnum::mid:
                    return 10;
                case strengthEnum::max:
                    return 100;
                default:
                    return 0;
            }
        case TestPluginAudioProcessor::timeUnits::ms:
            switch (strength) {
                case strengthEnum::min:
                    return 0.1;
                case strengthEnum::mid:
                    return 1;
                case strengthEnum::max:
                    return 10;
                default:
                    return 0;
            }
        case TestPluginAudioProcessor::timeUnits::meter:
            switch (strength) {
                case strengthEnum::min:
                    return 0.1;
                case strengthEnum::mid:
                    return 1;
                case strengthEnum::max:
                    return 10;
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

