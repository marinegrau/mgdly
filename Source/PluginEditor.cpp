/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TheDelayAudioProcessorEditor::TheDelayAudioProcessorEditor (TheDelayAudioProcessor& p)
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
//    trackNameLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    
    samplesTextLabel.setText("samples", dontSendNotification);
    samplesTextLabel.setBounds(125, 40, 100, 40);
    samplesTextLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    
    msTextLabel.setText("milliseconds", dontSendNotification);
    msTextLabel.setBounds(125, 90, 100, 40);
    msTextLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    
    meterTextLabel.setText("meter", dontSendNotification);
    meterTextLabel.setBounds(125, 140, 100, 40);
    meterTextLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    
    samplesLabel.setName("samplesLabel");
    samplesLabel.setBounds(20, 40, 100, 40);
    samplesLabel.setEditable(false, true);  // Not editable on a single click. But editable on a double click
    samplesLabel.addListener(this);
    samplesLabel.addMouseListener(this, false);
    samplesLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    samplesLabel.setJustificationType(juce::Justification::centredRight);
    
    msLabel.setName("msLabel");
    msLabel.setBounds(20, 90, 100, 40);
    msLabel.setEditable(false, true);       // Not editable on a single click. But editable on a double click
    msLabel.addListener(this);
    msLabel.addMouseListener(this, false);
    msLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
    msLabel.setJustificationType(juce::Justification::centredRight);


    meterLabel.setName("meterLabel");
    meterLabel.setBounds(20, 140, 100, 40);
    meterLabel.setEditable(false, true);       // Not editable on a single click. But editable on a double click
    meterLabel.addListener(this);
    meterLabel.addMouseListener(this, false);
    meterLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);
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

TheDelayAudioProcessorEditor::~TheDelayAudioProcessorEditor()
{
}


void TheDelayAudioProcessorEditor::paint (Graphics& g)
{

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("NavyGrey TheDelay", 0, 0, getWidth(), 30, Justification::centred, 1);

}

void TheDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //sets the position and size of the slider with arguments (x,y,width,height)
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void TheDelayAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
}


bool TheDelayAudioProcessorEditor::isDouble(String text){
    text = text.replaceCharacter(',', '.');
    // Check if there aren't any non number characters and there is not more than 1 dot
    bool isDouble = ((text.toStdString().find_first_not_of( "0123456789." ) == std::string::npos) &&
                    (countCharOccurencesInString(text, '.') <= 1));
                    
    return isDouble;
}


int TheDelayAudioProcessorEditor::countCharOccurencesInString(String str, char a)
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



void TheDelayAudioProcessorEditor::labelTextChanged(Label* label)
{
    int sampleRate = getAudioProcessor()->getSampleRate();
    if(label == &msLabel){
        double delayTime = 0.0;
        String text = msLabel.getText();
        bool isDouble = TheDelayAudioProcessorEditor::isDouble(text);
        text = text.replaceCharacter(',', '.');
        if (isDouble) {  // IF TEXT IS A VALID ENTRY
            delayTime = std::stof(text.toStdString()); // set Delaytime to the entered number
            int delayInSamples = round(delayTime * sampleRate / 1000);
            setDelayTime(delayInSamples);
            //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, delayTime * sampleRate / 1000);
        }
        updateLabels();

    }

    if(label == &samplesLabel){
        double delayTime = 0.0;
        String text = samplesLabel.getText();
        //bool isDouble = (text.toStdString().find_first_not_of( "0123456789" ) == std::string::npos);
        bool isDouble = TheDelayAudioProcessorEditor::isDouble(text);
        text = text.replaceCharacter(',', '.');
        // IF ENTERED TEXT IS VALID
        if (isDouble) {
            delayTime = std::stof(text.toStdString());
            delayTime = round(delayTime);
            setDelayTime(delayTime);
            //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, delayTime);
        }
        updateLabels();
        
    }

    if(label == &meterLabel){
        double delayTime = 0.0;
        String text = meterLabel.getText();
        bool isDouble = TheDelayAudioProcessorEditor::isDouble(text);
        text = text.replaceCharacter(',', '.');
        // IF ENTERED TEXT IS VALID
        if (isDouble)
        {
            delayTime = std::stof(text.toStdString());
            int delayInSamples = round(delayTime * sampleRate / 1000 * (100/343));
            setDelayTime(delayInSamples);
            
            //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, delayTime * sampleRate / 1000 * (100/343));
        }
        updateLabels();
        
    }

    
}
void TheDelayAudioProcessorEditor::updateLabels(){
    int sampleRate = getAudioProcessor()->getSampleRate();
    double delayInSamples = round(getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::delayLengthParam));
    double delayInMs = delayInSamples * 1000 / sampleRate;
    delayInMs = round(delayInMs * 10)/10; // round to 0.1
    double delayInMeters = delayInMs * 0.343;
    delayInMeters = round(delayInMeters * 10) /10;
    samplesLabel.setText((String)delayInSamples, dontSendNotification);
    msLabel.setText((String) delayInMs, dontSendNotification);
    meterLabel.setText((String) delayInMeters, dontSendNotification);
}





void TheDelayAudioProcessorEditor::buttonClicked(Button* button)
{
//switch on button
    
    if (button == &incDelayMin) {
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    
    if (button == &decDelayMin){
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();

    }

    if (button == &incDelayMid) {
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor * 10);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    if (button == &decDelayMid) {
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor * 10);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();
    }
    if (button == &incDelayMax) {
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor * 100);
        incDecDelay(addDelayInSamples, plusMinus::inc);
        updateLabels();
    }
    if (button == &decDelayMax) {
        int unit = getCurrentTimeUnit();
        double factor = getFactor(unit, min);
        double addDelayInSamples = convertToSamples(unit, factor * 100);
        incDecDelay(addDelayInSamples, plusMinus::dec);
        updateLabels();
    }
    
    if (button == &addDelay) {
        addDelayEditor.setVisible(true);
        addDelayEditor.grabKeyboardFocus();
    }
}


void TheDelayAudioProcessorEditor::updateTimeLabelColours(){
    int param = getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::timeUnitParam);
    switch (param) {
        case TheDelayAudioProcessor::timeUnits::samples:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            break;
        case TheDelayAudioProcessor::timeUnits::ms:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            break;
        case TheDelayAudioProcessor::timeUnits::meter:
            samplesLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            msLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGdeselected);
            meterLabel.setColour(juce::Label::ColourIds::backgroundColourId, labelBGselected);
            break;
        default:
            break;
    }
    
}
// =========================== BEHAVIOUR FOR LABEL BUTTONS
void TheDelayAudioProcessorEditor::mouseDown(const MouseEvent& e){
    // Setting the timeUnit corresponding to the selected Label
    if (e.eventComponent->getName() == samplesLabel.getName()){
        getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::timeUnitParam, TheDelayAudioProcessor::timeUnits::samples);
    }
    if (e.eventComponent->getName() == msLabel.getName()){
        getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::timeUnitParam, TheDelayAudioProcessor::timeUnits::ms);
    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::timeUnitParam, TheDelayAudioProcessor::timeUnits::meter);
    }
    
    // Set Colours
    updateTimeLabelColours();

}
void TheDelayAudioProcessorEditor::mouseEnter(const MouseEvent& e){
    if (e.eventComponent->getName() == samplesLabel.getName()){
        samplesLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColourMouseOver);
        
    }
    if (e.eventComponent->getName() == msLabel.getName()){
        msLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColourMouseOver);

    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        meterLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColourMouseOver);

    }
}
void TheDelayAudioProcessorEditor::mouseExit(const MouseEvent& e){
    if (e.eventComponent->getName() == samplesLabel.getName()){
        samplesLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);

    }
    if (e.eventComponent->getName() == msLabel.getName()){
        msLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);

    }
    if (e.eventComponent->getName() == meterLabel.getName()){
        meterLabel.setColour(juce::Label::ColourIds::textColourId, TheDelayAudioProcessorEditor::labelTextColour);

    }
}

void TheDelayAudioProcessorEditor::textEditorReturnKeyPressed(TextEditor &t){
    double addTime;
    double oldDelay = getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::delayLengthParam);
    //double addTime = getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::addTime);
    String text;
    text = addDelayEditor.getText();
    bool isDouble = TheDelayAudioProcessorEditor::isDouble(text);
    if (isDouble)
        addTime = std::stof(text.toStdString());
        
    else
    {
        addTime = 0;
        addDelayEditor.setText("");
        addDelayEditor.setVisible(false);
    }
    
    
    
    //=======
    int unit = getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::timeUnitParam);
    int addDelayInSamples;
    double sampleRate = getAudioProcessor()->getSampleRate();
    switch (unit) {
        case TheDelayAudioProcessor::timeUnits::samples:
            addDelayInSamples = addTime;
            break;
        case TheDelayAudioProcessor::timeUnits::ms:
            addDelayInSamples = round(addTime * sampleRate / 1000);
            break;
        case TheDelayAudioProcessor::timeUnits::meter:
            addDelayInSamples = round(addTime * sampleRate / 1000 * 0.2915451895 * 10);
            break;
            //default:
            //  break;
    };
    //=======
    
    
    int newDelayInsamples = oldDelay + addDelayInSamples;
    setDelayTime(newDelayInsamples);
    //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, newDelayInsamples);
    addDelayEditor.setVisible(false);
    updateLabels();
}

void TheDelayAudioProcessorEditor::textEditorEscapeKeyPressed(TextEditor &t){
    //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::addTime, 0.0);
    addDelayEditor.setVisible(false);
    addDelayEditor.setText("");

}

void TheDelayAudioProcessorEditor::textEditorFocusLost(TextEditor &t){
    //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::addTime, 0.0);
    addDelayEditor.setVisible(false);
    addDelayEditor.setText("");
}


void TheDelayAudioProcessorEditor::incDecDelay(double samples, int incDec) {
    int factor = 0;                 // shouldn't matter if not initialized
    double currentDelay = 0;        // shouldn't matter if not initialized
    double newDelay = 0;            // shouldn't matter if not initialized
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
    
    currentDelay = getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::delayLengthParam);
    newDelay = currentDelay + samples * factor;
    newDelay = round(newDelay);                 // fixed the "Samples on ms up down" issue
    setDelayTime(newDelay);
    //getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, newDelay);
}

// ===================== HELPER == FUNCTIONS =======================
/// converts from samples, ms and meters to samples
double TheDelayAudioProcessorEditor::convertToSamples(int unit, double value)
{
    double delayInSamples;
    double sampleRate = getAudioProcessor()->getSampleRate();
    switch (unit) {
        case TheDelayAudioProcessor::timeUnits::samples:
            delayInSamples = roundf(value);
            break;
        case TheDelayAudioProcessor::timeUnits::ms:
            delayInSamples = value * sampleRate / 1000;
            break;
        case TheDelayAudioProcessor::timeUnits::meter:
            delayInSamples = value * sampleRate / 343;
            break;
        default:
            abort();            // If unit is not defined CRASH
    }
    return delayInSamples;
}

int TheDelayAudioProcessorEditor::getCurrentTimeUnit()
{
    return getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::timeUnitParam);
}

double TheDelayAudioProcessorEditor::getDelayLength()
{
    return getAudioProcessor()->getParameter(TheDelayAudioProcessor::Parameters::delayLengthParam);
}

void TheDelayAudioProcessorEditor::setDelayTime(int samples){
    getAudioProcessor()->setParameter(TheDelayAudioProcessor::Parameters::delayLengthParam, samples);
}


double TheDelayAudioProcessorEditor::getFactor(int unit, int strength){
    switch (unit) {
        case TheDelayAudioProcessor::timeUnits::samples:
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
        case TheDelayAudioProcessor::timeUnits::ms:
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
        case TheDelayAudioProcessor::timeUnits::meter:
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

