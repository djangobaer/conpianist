/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PlaybackComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PlaybackComponent::PlaybackComponent (PianoController& pianoController)
    : pianoController(pianoController)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //Desktop::getInstance().setGlobalScaleFactor(1);
    //[/Constructor_pre]

    addAndMakeVisible (songGroup = new GroupComponent ("Song",
                                                       TRANS("Song")));
    songGroup->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (songLabel = new Label ("Song Label",
                                              TRANS("Click here and select a Song")));
    songLabel->setFont (Font (23.70f, Font::plain).withTypefaceStyle ("Regular"));
    songLabel->setJustificationType (Justification::centredLeft);
    songLabel->setEditable (false, false, false);
    songLabel->setColour (TextEditor::textColourId, Colours::black);
    songLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playbackGroup = new GroupComponent ("Playback",
                                                           TRANS("Playback")));
    playbackGroup->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (positionSlider = new Slider ("Song Position slider"));
    positionSlider->setTooltip (TRANS("Song position"));
    positionSlider->setRange (1, 999, 1);
    positionSlider->setSliderStyle (Slider::LinearHorizontal);
    positionSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    positionSlider->addListener (this);

    addAndMakeVisible (positionLabel = new Label ("Song Position Label",
                                                  TRANS("001")));
    positionLabel->setTooltip (TRANS("Current measure"));
    positionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    positionLabel->setJustificationType (Justification::centredLeft);
    positionLabel->setEditable (false, false, false);
    positionLabel->setColour (TextEditor::textColourId, Colours::black);
    positionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    positionLabel->setBounds (8, ((-8) + 70 - 8) + 24, 36, 20);

    addAndMakeVisible (lengthLabel = new Label ("Song Length Label",
                                                TRANS("999")));
    lengthLabel->setTooltip (TRANS("Number of measures"));
    lengthLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lengthLabel->setJustificationType (Justification::centredRight);
    lengthLabel->setEditable (false, false, false);
    lengthLabel->setColour (TextEditor::textColourId, Colours::black);
    lengthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playButton = new ImageButton ("Play Button"));
    playButton->setTooltip (TRANS("Play/pause"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    playButton->setImages (false, true, true,
                           ImageCache::getFromMemory (BinaryData::buttonplay_png, BinaryData::buttonplay_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 0.750f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000));
    playButton->setBounds (59, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (rewindButton = new ImageButton ("Rewind Button"));
    rewindButton->setTooltip (TRANS("Jump to previous measure"));
    rewindButton->setButtonText (TRANS("Rewind"));
    rewindButton->addListener (this);

    rewindButton->setImages (false, true, true,
                             ImageCache::getFromMemory (BinaryData::buttonrewind_png, BinaryData::buttonrewind_pngSize), 1.000f, Colour (0x00000000),
                             Image(), 0.750f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000));
    rewindButton->setBounds (14, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (forwardButton = new ImageButton ("Forward Button"));
    forwardButton->setTooltip (TRANS("Jump to next measure"));
    forwardButton->setButtonText (TRANS("Play"));
    forwardButton->addListener (this);

    forwardButton->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::buttonfastforward_png, BinaryData::buttonfastforward_pngSize), 1.000f, Colour (0x00000000),
                              Image(), 0.750f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));
    forwardButton->setBounds (104, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (chooseSongButton = new ImageButton ("Choose Song Button"));
    chooseSongButton->setButtonText (TRANS("Choose"));
    chooseSongButton->addListener (this);

    chooseSongButton->setImages (false, true, true,
                                 ImageCache::getFromMemory (BinaryData::buttonexpand_png, BinaryData::buttonexpand_pngSize), 1.000f, Colour (0x00000000),
                                 Image(), 0.750f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (backingPartButton = new TextButton ("Backing Part Button"));
    backingPartButton->setButtonText (TRANS("Backing"));
    backingPartButton->addListener (this);

    backingPartButton->setBounds (14, ((-8) + 70 - 8) + 142, 86, 28);

    addAndMakeVisible (partLabel = new Label ("Part Label",
                                              TRANS("Part")));
    partLabel->setTooltip (TRANS("Playback part"));
    partLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    partLabel->setJustificationType (Justification::centredLeft);
    partLabel->setEditable (false, false, false);
    partLabel->setColour (TextEditor::textColourId, Colours::black);
    partLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    partLabel->setBounds (8, ((-8) + 70 - 8) + 110, 136, 24);

    addAndMakeVisible (leftPartButton = new TextButton ("Left Part Button"));
    leftPartButton->setButtonText (TRANS("Left"));
    leftPartButton->addListener (this);

    leftPartButton->setBounds (103, ((-8) + 70 - 8) + 142, 86, 28);

    addAndMakeVisible (rightPartButton = new TextButton ("Right Part Button"));
    rightPartButton->setButtonText (TRANS("Right"));
    rightPartButton->addListener (this);

    rightPartButton->setBounds (0 + 192, ((-8) + 70 - 8) + 142, 86, 28);

    addAndMakeVisible (guideButton = new ImageButton ("Guide Button"));
    guideButton->setTooltip (TRANS("Guide mode (wait for note)"));
    guideButton->setButtonText (TRANS("Guide"));
    guideButton->addListener (this);

    guideButton->setImages (false, true, true,
                            ImageCache::getFromMemory (BinaryData::buttonguide_png, BinaryData::buttonguide_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 0.750f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    guideButton->setBounds (0 + 193, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (loopButton = new ImageButton ("Loop Button"));
    loopButton->setTooltip (TRANS("Repeat selected fragment (click twice to select)"));
    loopButton->setButtonText (TRANS("A->B Loop"));
    loopButton->addListener (this);

    loopButton->setImages (false, true, true,
                           ImageCache::getFromMemory (BinaryData::buttonabloop_png, BinaryData::buttonabloop_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 0.750f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000));
    loopButton->setBounds (148, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (lightsButton = new ImageButton ("Lights Button"));
    lightsButton->setTooltip (TRANS("Stream lights on/off"));
    lightsButton->setButtonText (TRANS("Lights"));
    lightsButton->addListener (this);

    lightsButton->setImages (false, true, true,
                             ImageCache::getFromMemory (BinaryData::buttonlights_png, BinaryData::buttonlights_pngSize), 1.000f, Colour (0x00000000),
                             Image(), 0.750f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000));
    lightsButton->setBounds (0 + 238, ((-8) + 70 - 8) + 60, 40, 28);

    addAndMakeVisible (volumeTitleLabel = new Label ("Volume Label",
                                                     TRANS("Volume")));
    volumeTitleLabel->setTooltip (TRANS("Playback Volume"));
    volumeTitleLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    volumeTitleLabel->setJustificationType (Justification::centredLeft);
    volumeTitleLabel->setEditable (false, false, false);
    volumeTitleLabel->setColour (TextEditor::textColourId, Colours::black);
    volumeTitleLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    volumeTitleLabel->setBounds (8, ((-8) + 70 - 8) + 186, 136, 24);

    addAndMakeVisible (volumeSlider = new Slider ("Volume Slider"));
    volumeSlider->setTooltip (TRANS("Playback Volume"));
    volumeSlider->setRange (0, 127, 1);
    volumeSlider->setSliderStyle (Slider::LinearHorizontal);
    volumeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    volumeSlider->addListener (this);

    addAndMakeVisible (volumeLabel = new Label ("Volume Label",
                                                TRANS("100")));
    volumeLabel->setTooltip (TRANS("Playback Volume"));
    volumeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    volumeLabel->setJustificationType (Justification::centredRight);
    volumeLabel->setEditable (false, false, false);
    volumeLabel->setColour (TextEditor::textColourId, Colours::black);
    volumeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (tempoTitleLabel = new Label ("Tempo Label",
                                                    TRANS("Tempo")));
    tempoTitleLabel->setTooltip (TRANS("Playback Tempo"));
    tempoTitleLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    tempoTitleLabel->setJustificationType (Justification::centredLeft);
    tempoTitleLabel->setEditable (false, false, false);
    tempoTitleLabel->setColour (TextEditor::textColourId, Colours::black);
    tempoTitleLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    tempoTitleLabel->setBounds (8, ((-8) + 70 - 8) + 242, 136, 24);

    addAndMakeVisible (tempoSlider = new Slider ("Tempo Slider"));
    tempoSlider->setTooltip (TRANS("Playback Tempo"));
    tempoSlider->setRange (5, 280, 1);
    tempoSlider->setSliderStyle (Slider::LinearHorizontal);
    tempoSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    tempoSlider->addListener (this);

    addAndMakeVisible (tempoLabel = new Label ("Tempo Label",
                                               TRANS("128")));
    tempoLabel->setTooltip (TRANS("Playback Tempo"));
    tempoLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    tempoLabel->setJustificationType (Justification::centredRight);
    tempoLabel->setEditable (false, false, false);
    tempoLabel->setColour (TextEditor::textColourId, Colours::black);
    tempoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (transposeTitleLabel = new Label ("Transpose Label",
                                                        TRANS("Transpose")));
    transposeTitleLabel->setTooltip (TRANS("Playback Transpose"));
    transposeTitleLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    transposeTitleLabel->setJustificationType (Justification::centredLeft);
    transposeTitleLabel->setEditable (false, false, false);
    transposeTitleLabel->setColour (TextEditor::textColourId, Colours::black);
    transposeTitleLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    transposeTitleLabel->setBounds (8, ((-8) + 70 - 8) + 298, 136, 24);

    addAndMakeVisible (transposeSlider = new Slider ("Transpose Slider"));
    transposeSlider->setTooltip (TRANS("Playback Transpose"));
    transposeSlider->setRange (-12, 12, 1);
    transposeSlider->setSliderStyle (Slider::LinearHorizontal);
    transposeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    transposeSlider->addListener (this);

    addAndMakeVisible (transposeLabel = new Label ("Transpose Label",
                                                   TRANS("0")));
    transposeLabel->setTooltip (TRANS("Playback Transpose"));
    transposeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    transposeLabel->setJustificationType (Justification::centredRight);
    transposeLabel->setEditable (false, false, false);
    transposeLabel->setColour (TextEditor::textColourId, Colours::black);
    transposeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    playbackGroup->setColour(GroupComponent::outlineColourId, Colours::transparentBlack);
    playbackGroup->setText("");
    songGroup->setColour(GroupComponent::outlineColourId, Colours::transparentBlack);
    songGroup->setText("");
    //[/UserPreSize]

    setSize (290, 410);


    //[Constructor] You can add your own custom stuff here..
    updateEnabledControls();
    pianoController.AddListener(this);
    songLabel->addMouseListener(this, false);
    backingPartButton->getProperties().set("toggle", "yes");
    leftPartButton->getProperties().set("toggle", "yes");
    rightPartButton->getProperties().set("toggle", "yes");
    guideButton->getProperties().set("toggle", "yes");
    lightsButton->getProperties().set("toggle", "yes");
    loopButton->getProperties().set("toggle", "yes");
    volumeTitleLabel->addMouseListener(this, false);
    volumeLabel->addMouseListener(this, false);
    volumeSlider->addMouseListener(this, false);
    tempoTitleLabel->addMouseListener(this, false);
    tempoLabel->addMouseListener(this, false);
    tempoSlider->addMouseListener(this, false);
    transposeTitleLabel->addMouseListener(this, false);
    transposeLabel->addMouseListener(this, false);
    transposeSlider->addMouseListener(this, false);
    //[/Constructor]
}

PlaybackComponent::~PlaybackComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    songGroup = nullptr;
    songLabel = nullptr;
    playbackGroup = nullptr;
    positionSlider = nullptr;
    positionLabel = nullptr;
    lengthLabel = nullptr;
    playButton = nullptr;
    rewindButton = nullptr;
    forwardButton = nullptr;
    chooseSongButton = nullptr;
    backingPartButton = nullptr;
    partLabel = nullptr;
    leftPartButton = nullptr;
    rightPartButton = nullptr;
    guideButton = nullptr;
    loopButton = nullptr;
    lightsButton = nullptr;
    volumeTitleLabel = nullptr;
    volumeSlider = nullptr;
    volumeLabel = nullptr;
    tempoTitleLabel = nullptr;
    tempoSlider = nullptr;
    tempoLabel = nullptr;
    transposeTitleLabel = nullptr;
    transposeSlider = nullptr;
    transposeLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PlaybackComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 0, width = getWidth() - 0, height = 58;
        Colour fillColour = Colour (0xff4e5b62);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = -4, y = 156, width = getWidth() - -8, height = 1;
        Colour fillColour = Colour (0xff4e5b62);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = getWidth() - 1, y = 0, width = 1, height = getHeight() - 0;
        Colour fillColour = Colour (0xff4e5b62);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    {
        int x = proportionOfWidth (0.5000f) - (2 / 2), y = transposeSlider->getY() + 4, width = 2, height = 4;
        g.setColour (Colour (0xabf0ffff));
        g.fillRect (x, y, width, height);
    }
    //[/UserPaint]
}

void PlaybackComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    songGroup->setBounds (0, -8, getWidth() - 0, 70);
    songLabel->setBounds (0 + 12, (-8) + 16, (getWidth() - 0) - 59, 70 - 29);
    playbackGroup->setBounds (0, (-8) + 70 - 8, getWidth() - 0, 354);
    positionSlider->setBounds (0 + 48, ((-8) + 70 - 8) + 22, (getWidth() - 0) - 96, 24);
    lengthLabel->setBounds (0 + (getWidth() - 0) - 8 - 36, ((-8) + 70 - 8) + 24, 36, 20);
    chooseSongButton->setBounds (0 + (getWidth() - 0) - 20 - (20 / 2), (-8) + 25, 20, 24);
    volumeSlider->setBounds (0 + 8, ((-8) + 70 - 8) + 210, (getWidth() - 0) - 16, 24);
    volumeLabel->setBounds (getWidth() - 9 - 48, ((-8) + 70 - 8) + 186, 48, 24);
    tempoSlider->setBounds (0 + 8, ((-8) + 70 - 8) + 266, (getWidth() - 0) - 16, 24);
    tempoLabel->setBounds (getWidth() - 9 - 48, ((-8) + 70 - 8) + 242, 48, 24);
    transposeSlider->setBounds (0 + 8, ((-8) + 70 - 8) + 322, (getWidth() - 0) - 16, 24);
    transposeLabel->setBounds (getWidth() - 9 - 48, ((-8) + 70 - 8) + 298, 48, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PlaybackComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == positionSlider)
    {
        //[UserSliderCode_positionSlider] -- add your slider handling code here..
        pianoController.SetPosition({(int)positionSlider->getValue(), 1});
        //[/UserSliderCode_positionSlider]
    }
    else if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        pianoController.SetVolume(volumeSlider->getValue());
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == tempoSlider)
    {
        //[UserSliderCode_tempoSlider] -- add your slider handling code here..
        pianoController.SetTempo(tempoSlider->getValue());
        //[/UserSliderCode_tempoSlider]
    }
    else if (sliderThatWasMoved == transposeSlider)
    {
        //[UserSliderCode_transposeSlider] -- add your slider handling code here..
        pianoController.SetTranspose(transposeSlider->getValue());
        //[/UserSliderCode_transposeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PlaybackComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        pianoController.GetPlaying() ? pianoController.Pause() : pianoController.Play();
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == rewindButton)
    {
        //[UserButtonCode_rewindButton] -- add your button handler code here..
        pianoController.SetPosition({pianoController.GetPosition().measure -
        	(ModifierKeys::getCurrentModifiers().isShiftDown() ? 0 : 1),
        	(ModifierKeys::getCurrentModifiers().isShiftDown() ? pianoController.GetPosition().beat - 1 : 1)});
        //[/UserButtonCode_rewindButton]
    }
    else if (buttonThatWasClicked == forwardButton)
    {
        //[UserButtonCode_forwardButton] -- add your button handler code here..
        pianoController.SetPosition({pianoController.GetPosition().measure +
        	(ModifierKeys::getCurrentModifiers().isShiftDown() ? 0 : 1),
        	(ModifierKeys::getCurrentModifiers().isShiftDown() ? pianoController.GetPosition().beat + 1 : 1)});
        //[/UserButtonCode_forwardButton]
    }
    else if (buttonThatWasClicked == chooseSongButton)
    {
        //[UserButtonCode_chooseSongButton] -- add your button handler code here..
        chooseSong();
        //[/UserButtonCode_chooseSongButton]
    }
    else if (buttonThatWasClicked == backingPartButton)
    {
        //[UserButtonCode_backingPartButton] -- add your button handler code here..
        pianoController.SetBackingPart(!pianoController.GetBackingPart());
        //[/UserButtonCode_backingPartButton]
    }
    else if (buttonThatWasClicked == leftPartButton)
    {
        //[UserButtonCode_leftPartButton] -- add your button handler code here..
        pianoController.SetLeftPart(!pianoController.GetLeftPart());
        //[/UserButtonCode_leftPartButton]
    }
    else if (buttonThatWasClicked == rightPartButton)
    {
        //[UserButtonCode_rightPartButton] -- add your button handler code here..
        pianoController.SetRightPart(!pianoController.GetRightPart());
        //[/UserButtonCode_rightPartButton]
    }
    else if (buttonThatWasClicked == guideButton)
    {
        //[UserButtonCode_guideButton] -- add your button handler code here..
        pianoController.SetGuide(!pianoController.GetGuide());
        //[/UserButtonCode_guideButton]
    }
    else if (buttonThatWasClicked == loopButton)
    {
        //[UserButtonCode_loopButton] -- add your button handler code here..
        loopButtonClicked();
        //[/UserButtonCode_loopButton]
    }
    else if (buttonThatWasClicked == lightsButton)
    {
        //[UserButtonCode_lightsButton] -- add your button handler code here..
        pianoController.SetStreamLights(!pianoController.GetStreamLights());
        //[/UserButtonCode_lightsButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PlaybackComponent::chooseSong()
{
	File initialLocation = File::getSpecialLocation(File::userHomeDirectory);
	initialLocation = initialLocation.getFullPathName() + "/Midi";
	FileChooser chooser ("Please select the song you want to load...", initialLocation, "*.mid");
    if (chooser.browseForFileToOpen())
    {
        File file(chooser.getResult());
		songLabel->setText(TRANS("Loading..."), NotificationType::dontSendNotification);
		MessageManager::callAsync([=] () { loadSong(file); });
    }
}

void PlaybackComponent::loadSong(const File& file)
{
	MidiFile midiFile;
	FileInputStream inp(file);
	if (!midiFile.readFrom(inp))
	{
		songLabel->setText(TRANS("Error reading file"), NotificationType::dontSendNotification);
		return;
	}

	if (!pianoController.UploadSong(file))
	{
		songLabel->setText(TRANS("Error loading midi"), NotificationType::dontSendNotification);
		return;
	}

	songLabel->setText(file.getFileNameWithoutExtension(), NotificationType::dontSendNotification);
	positionLabel->setText("001", NotificationType::dontSendNotification);
	lengthLabel->setText("999", NotificationType::dontSendNotification);
}

void PlaybackComponent::updateSongState()
{
	int songLength = pianoController.GetLength().measure > 0 ? pianoController.GetLength().measure : 999;
	lengthLabel->setText(String::formatted("%03d", songLength), NotificationType::dontSendNotification);

	positionSlider->setRange(1, songLength, 1);
	positionLabel->setText(String::formatted("%03d", pianoController.GetPosition().measure),
		NotificationType::dontSendNotification);
	positionSlider->setValue(pianoController.GetPosition().measure, NotificationType::dontSendNotification);

	playButton->setImages(false, true, true, ImageCache::getFromMemory(
			pianoController.GetPlaying() ? BinaryData::buttonpause_png : BinaryData::buttonplay_png,
			pianoController.GetPlaying() ? BinaryData::buttonpause_pngSize : BinaryData::buttonplay_pngSize),
			1.000f, Colour (0x00000000), Image(), 0.750f, Colour (0x00000000), Image(), 1.000f, Colour (0x00000000));
	playButton->setTooltip(pianoController.GetPlaying() ? "Pause" : "Play");

	volumeLabel->setText(String(pianoController.GetVolume()), NotificationType::dontSendNotification);
	volumeSlider->setValue(pianoController.GetVolume(), NotificationType::dontSendNotification);

	tempoLabel->setText(String(pianoController.GetTempo()), NotificationType::dontSendNotification);
	tempoSlider->setValue(pianoController.GetTempo(), NotificationType::dontSendNotification);

	transposeLabel->setText((pianoController.GetTranspose() > 0 ? "+" : "") +
		String(pianoController.GetTranspose()), NotificationType::dontSendNotification);
	transposeSlider->setValue(pianoController.GetTranspose(), NotificationType::dontSendNotification);

	bool loopSet = pianoController.GetLoop().begin.measure > 0;
	bool loopHalf = loopStart.measure > 0;
	loopButton->setImages(false, true, true, ImageCache::getFromMemory(
		loopHalf ? BinaryData::buttonabloophalf_png : BinaryData::buttonabloop_png,
		loopHalf ? BinaryData::buttonabloophalf_pngSize : BinaryData::buttonabloop_pngSize),
		1.000f, Colour (0x00000000), Image(), 0.750f, Colour (0x00000000), Image(), 1.000f, Colour (0x00000000));
	loopButton->setToggleState(loopSet || loopHalf, NotificationType::dontSendNotification);
}

void PlaybackComponent::updateSettingsState()
{
	guideButton->setToggleState(pianoController.GetGuide() && pianoController.IsConnected(), NotificationType::dontSendNotification);
	lightsButton->setToggleState(pianoController.GetStreamLights() && pianoController.IsConnected(), NotificationType::dontSendNotification);
	//lightsFastButton->setToggleState(pianoController.GetStreamLightsFast() && pianoController.IsConnected(), NotificationType::dontSendNotification);

	backingPartButton->setToggleState(pianoController.GetBackingPart() && pianoController.IsConnected(), NotificationType::dontSendNotification);
	leftPartButton->setToggleState(pianoController.GetLeftPart() && pianoController.IsConnected(), NotificationType::dontSendNotification);
	rightPartButton->setToggleState(pianoController.GetRightPart() && pianoController.IsConnected(), NotificationType::dontSendNotification);

	updateEnabledControls();
}

void PlaybackComponent::updateEnabledControls()
{
	for (Component* co : getChildren())
	{
		co->setEnabled(pianoController.IsConnected());
	}
}

void PlaybackComponent::mouseUp(const MouseEvent& event)
{
	if (event.eventComponent == songLabel)
	{
		chooseSong();
	}
}

void PlaybackComponent::mouseDoubleClick(const MouseEvent& event)
{
	if (event.eventComponent == volumeSlider ||
		event.eventComponent == volumeTitleLabel ||
		event.eventComponent == volumeLabel)
	{
		pianoController.SetVolume(PianoController::DefaultVolume);
	}
	else if (event.eventComponent == tempoSlider ||
		event.eventComponent == tempoTitleLabel ||
		event.eventComponent == tempoLabel)
	{
		pianoController.ResetTempo();
	}
	else if (event.eventComponent == transposeSlider ||
		event.eventComponent == transposeTitleLabel ||
		event.eventComponent == transposeLabel)
	{
		pianoController.SetTranspose(PianoController::DefaultTranspose);
	}
}

void PlaybackComponent::loopButtonClicked()
{
	bool loopSet = pianoController.GetLoop().begin.measure > 0;
	bool loopHalf = loopStart.measure > 0;

	if (loopSet)
	{
		pianoController.ResetLoop();
	}
	else if (loopHalf && loopStart == pianoController.GetPosition())
	{
		loopStart = {0,0};
		updateSongState();
	}
	else if (loopHalf)
	{
		pianoController.SetLoop({loopStart, pianoController.GetPosition()});
		loopStart = {0,0};
	}
	else
	{
		loopStart = pianoController.GetPosition();
		updateSongState();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PlaybackComponent" componentName=""
                 parentClasses="public Component, public PianoController::Listener"
                 constructorParams="PianoController&amp; pianoController" variableInitialisers="pianoController(pianoController)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="290" initialHeight="410">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 0M 58" fill="solid: ff4e5b62" hasStroke="0"/>
    <RECT pos="-4 156 -8M 1" fill="solid: ff4e5b62" hasStroke="0"/>
    <RECT pos="1R 0 1 0M" fill="solid: ff4e5b62" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="Song" id="4e6df4a0ae6e851b" memberName="songGroup" virtualName=""
                  explicitFocusOrder="0" pos="0 -8 0M 70" title="Song" textpos="36"/>
  <LABEL name="Song Label" id="8682794e760bce8" memberName="songLabel"
         virtualName="" explicitFocusOrder="0" pos="12 16 59M 29M" posRelativeX="4e6df4a0ae6e851b"
         posRelativeY="4e6df4a0ae6e851b" posRelativeW="4e6df4a0ae6e851b"
         posRelativeH="4e6df4a0ae6e851b" edTextCol="ff000000" edBkgCol="0"
         labelText="Click here and select a Song" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="23.69999999999999928946" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="Playback" id="c7b94b60aa96c6e2" memberName="playbackGroup"
                  virtualName="" explicitFocusOrder="0" pos="0 8R 0M 354" posRelativeY="4e6df4a0ae6e851b"
                  title="Playback" textpos="36"/>
  <SLIDER name="Song Position slider" id="3f9d3a942dcf1d69" memberName="positionSlider"
          virtualName="" explicitFocusOrder="0" pos="48 22 96M 24" posRelativeX="c7b94b60aa96c6e2"
          posRelativeY="c7b94b60aa96c6e2" posRelativeW="c7b94b60aa96c6e2"
          tooltip="Song position" min="1.00000000000000000000" max="999.00000000000000000000"
          int="1.00000000000000000000" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Song Position Label" id="17ac2967e993dc43" memberName="positionLabel"
         virtualName="" explicitFocusOrder="0" pos="8 24 36 20" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Current measure" edTextCol="ff000000" edBkgCol="0" labelText="001"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Song Length Label" id="537604aa6486f948" memberName="lengthLabel"
         virtualName="" explicitFocusOrder="0" pos="8Rr 24 36 20" posRelativeX="c7b94b60aa96c6e2"
         posRelativeY="c7b94b60aa96c6e2" tooltip="Number of measures"
         edTextCol="ff000000" edBkgCol="0" labelText="999" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="34"/>
  <IMAGEBUTTON name="Play Button" id="e85b378cc3166e44" memberName="playButton"
               virtualName="" explicitFocusOrder="0" pos="59 60 40 28" posRelativeY="c7b94b60aa96c6e2"
               tooltip="Play/pause" buttonText="Play" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::buttonplay_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="Rewind Button" id="e7074d9d71bdc0e6" memberName="rewindButton"
               virtualName="" explicitFocusOrder="0" pos="14 60 40 28" posRelativeY="c7b94b60aa96c6e2"
               tooltip="Jump to previous measure" buttonText="Rewind" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::buttonrewind_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="Forward Button" id="80a800a526f191f0" memberName="forwardButton"
               virtualName="" explicitFocusOrder="0" pos="104 60 40 28" posRelativeY="c7b94b60aa96c6e2"
               tooltip="Jump to next measure" buttonText="Play" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::buttonfastforward_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="Choose Song Button" id="290d61a1138635c0" memberName="chooseSongButton"
               virtualName="" explicitFocusOrder="0" pos="20Rc 25 20 24" posRelativeX="4e6df4a0ae6e851b"
               posRelativeY="4e6df4a0ae6e851b" buttonText="Choose" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="BinaryData::buttonexpand_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <TEXTBUTTON name="Backing Part Button" id="c44e73ef2ac29304" memberName="backingPartButton"
              virtualName="" explicitFocusOrder="0" pos="14 142 86 28" posRelativeY="c7b94b60aa96c6e2"
              buttonText="Backing" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Part Label" id="35efabd1f34f8989" memberName="partLabel"
         virtualName="" explicitFocusOrder="0" pos="8 110 136 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback part" edTextCol="ff000000" edBkgCol="0" labelText="Part"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Left Part Button" id="e9e1457f74b6fe2f" memberName="leftPartButton"
              virtualName="" explicitFocusOrder="0" pos="103 142 86 28" posRelativeY="c7b94b60aa96c6e2"
              buttonText="Left" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Right Part Button" id="7413d6f9d0d8d631" memberName="rightPartButton"
              virtualName="" explicitFocusOrder="0" pos="192 142 86 28" posRelativeX="c7b94b60aa96c6e2"
              posRelativeY="c7b94b60aa96c6e2" buttonText="Right" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <IMAGEBUTTON name="Guide Button" id="21ab7b81d08c0a5a" memberName="guideButton"
               virtualName="" explicitFocusOrder="0" pos="193 60 40 28" posRelativeX="c7b94b60aa96c6e2"
               posRelativeY="c7b94b60aa96c6e2" tooltip="Guide mode (wait for note)"
               buttonText="Guide" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="BinaryData::buttonguide_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="Loop Button" id="f6f613d6939aee17" memberName="loopButton"
               virtualName="" explicitFocusOrder="0" pos="148 60 40 28" posRelativeY="c7b94b60aa96c6e2"
               tooltip="Repeat selected fragment (click twice to select)" buttonText="A-&gt;B Loop"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="BinaryData::buttonabloop_png" opacityNormal="1.00000000000000000000"
               colourNormal="0" resourceOver="" opacityOver="0.75000000000000000000"
               colourOver="0" resourceDown="" opacityDown="1.00000000000000000000"
               colourDown="0"/>
  <IMAGEBUTTON name="Lights Button" id="ca510a4be11fdde2" memberName="lightsButton"
               virtualName="" explicitFocusOrder="0" pos="238 60 40 28" posRelativeX="c7b94b60aa96c6e2"
               posRelativeY="c7b94b60aa96c6e2" tooltip="Stream lights on/off"
               buttonText="Lights" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="BinaryData::buttonlights_png"
               opacityNormal="1.00000000000000000000" colourNormal="0" resourceOver=""
               opacityOver="0.75000000000000000000" colourOver="0" resourceDown=""
               opacityDown="1.00000000000000000000" colourDown="0"/>
  <LABEL name="Volume Label" id="e9b9fa2403da7aeb" memberName="volumeTitleLabel"
         virtualName="" explicitFocusOrder="0" pos="8 186 136 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Volume" edTextCol="ff000000" edBkgCol="0" labelText="Volume"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Volume Slider" id="1d5558a1e15fd965" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="8 210 16M 24" posRelativeX="c7b94b60aa96c6e2"
          posRelativeY="c7b94b60aa96c6e2" posRelativeW="c7b94b60aa96c6e2"
          tooltip="Playback Volume" min="0.00000000000000000000" max="127.00000000000000000000"
          int="1.00000000000000000000" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Volume Label" id="e81fccf91e43f02a" memberName="volumeLabel"
         virtualName="" explicitFocusOrder="0" pos="9Rr 186 48 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Volume" edTextCol="ff000000" edBkgCol="0" labelText="100"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="34"/>
  <LABEL name="Tempo Label" id="41de6fa00dd29466" memberName="tempoTitleLabel"
         virtualName="" explicitFocusOrder="0" pos="8 242 136 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Tempo" edTextCol="ff000000" edBkgCol="0" labelText="Tempo"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Tempo Slider" id="be0f7ca0a1c6df9a" memberName="tempoSlider"
          virtualName="" explicitFocusOrder="0" pos="8 266 16M 24" posRelativeX="c7b94b60aa96c6e2"
          posRelativeY="c7b94b60aa96c6e2" posRelativeW="c7b94b60aa96c6e2"
          tooltip="Playback Tempo" min="5.00000000000000000000" max="280.00000000000000000000"
          int="1.00000000000000000000" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Tempo Label" id="cc3c03127fcd4516" memberName="tempoLabel"
         virtualName="" explicitFocusOrder="0" pos="9Rr 242 48 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Tempo" edTextCol="ff000000" edBkgCol="0" labelText="128"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="34"/>
  <LABEL name="Transpose Label" id="f18234a2e2a92be" memberName="transposeTitleLabel"
         virtualName="" explicitFocusOrder="0" pos="8 298 136 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Transpose" edTextCol="ff000000" edBkgCol="0"
         labelText="Transpose" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <SLIDER name="Transpose Slider" id="b5af11eac08beef4" memberName="transposeSlider"
          virtualName="" explicitFocusOrder="0" pos="8 322 16M 24" posRelativeX="c7b94b60aa96c6e2"
          posRelativeY="c7b94b60aa96c6e2" posRelativeW="c7b94b60aa96c6e2"
          tooltip="Playback Transpose" min="-12.00000000000000000000" max="12.00000000000000000000"
          int="1.00000000000000000000" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Transpose Label" id="de60858318a22ee1" memberName="transposeLabel"
         virtualName="" explicitFocusOrder="0" pos="9Rr 298 48 24" posRelativeY="c7b94b60aa96c6e2"
         tooltip="Playback Transpose" edTextCol="ff000000" edBkgCol="0"
         labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
