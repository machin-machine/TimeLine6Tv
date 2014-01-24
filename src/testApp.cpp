#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    //--------------------------OSC------------------------------
    // listen on the given port
    cout << "listening for osc messages on port " << RPORT << "\n";
    receiver.setup(RPORT); //set up receiver
    sender.setup(HOST, SPORT); //set up sender

	ofBackground(255*.15);
	ofSetFrameRate(30);
	ofSetVerticalSync(true);

	ofEnableSmoothing();
	ofEnableAlphaBlending();

//	//on mac lets you use COMMAND+C and COMMAND+V actions
//	ofxtimelineBang::removeCocoaMenusFromGlut("Empty Templates");

	timelineBang.setup();
//	timelineBang.loopType(OF_LOOP_NORMAL);

    timelineBang.setBPM(120.f);
    timelineBang.enableSnapToBPM(true);
    timelineBang.setShowBPMGrid(true);


	timelineBang.setWidth(1100);
	timelineBang.setDurationInSeconds(600);
	timelineBang.addAudioTrack("Audio","bandeSon.wav");
	timelineBang.addBangs("Vid01","Vid01.xml");
	timelineBang.addBangs("Vid02","Vid02.xml");
	timelineBang.addBangs("Vid03","Vid03.xml");
	timelineBang.addBangs("Vid04","Vid04.xml");
	timelineBang.addBangs("Vid05","Vid05.xml");
	timelineBang.addBangs("Vid06","Vid06.xml");
	timelineBang.addFlags("SelVid","SelVid.xml");

	timelineBang.addFlags("SelVidA","SelVidA.xml");
	timelineBang.addFlags("SelVidB","SelVidB.xml");
	timelineBang.addFlags("SelVidC","SelVidC.xml");
	timelineBang.addFlags("SelVidD","SelVidD.xml");
	timelineBang.addFlags("SelVidE","SelVidE.xml");
	timelineBang.addFlags("SelVidF","SelVidF.xml");

	timelineBang.addCurves("Mix_G1","Mix_G1.xml");
	timelineBang.addCurves("TV1","TV1.xml");
	timelineBang.addCurves("Sens","Sens.xml");
	timelineBang.addCurves("In","In.xml");
	timelineBang.addCurves("Out","Out.xml");
	timelineBang.addCurves("TimeF","TimeF.xml");
	timelineBang.addCurves("Rand","Rand.xml");
	timelineBang.addFlags("SendOsc","SendOsc.xml");

	timelineBang.setPageName("Page 1");
//	timelineBang.addPage("Page 2");
//	timelineBang.setCurrentPage(0);

    ofAddListener(timelineBang.events().bangFired, this, &testApp::receivedBang);

    timeline.setup();

//    timeline.setBPM(120.f);
//    timeline.enableSnapToBPM(true);
//    timeline.setShowBPMGrid(true);
    timeline.setWidth(1100);
	timeline.setPageName("Page 2");

//    timeline.addPage("Page 2");
    timeline.addBangs("Vid00000","Vid01.xml");
	timeline.addBangs("Vid02","Vid02.xml");
	timeline.addBangs("Vid03","Vid03.xml");
	timeline.addBangs("Vid04","Vid04.xml");
	timeline.addBangs("Vid05","Vid05.xml");


//--------------------------------------------Midi-------------
	ofSetLogLevel(OF_LOG_VERBOSE);

	midiIn.listPorts(); // via instance
    midiIn.openPort(1);
	midiIn.ignoreTypes(false, false, false);
	midiIn.addListener(this);
	midiIn.setVerbose(true);
	midiOut.listPorts();
//	midiOut.openPort(0);	// by number
	midiOut.openPort(1);


    //--------------------------GUI---------------------------

    setGUI1();
    gui1->setDrawBack(false);
//    ((ofxUISlider*)gui1->getWidget("Lum_A1"))->setValue(127);



}

//--------------------------------------------------------------
void testApp::update(){

//     while(receiver.hasWaitingMessages()){
//		// get the next message
//		ofxOscMessage m;
//		receiver.getNextMessage(&m);
//
//
//        if(m.getAddress() == "/Lum_A1"){
//			Lum_A1 = m.getArgAsFloat(0);
//			cout<<m.getArgAsString(0)<<endl;
//                }

        {

        ofxOscMessage m;
        m.setAddress("/Mix_G1");
        m.addFloatArg(timelineBang.getValue("Mix_G1"));
        sender.sendMessage(m);
            }
            {

        ofxOscMessage m;
        m.setAddress("/TV1");
        m.addFloatArg(timelineBang.getValue("TV1"));
        sender.sendMessage(m);
            }
        {

        ofxOscMessage m;
        m.setAddress("/Sens");
        m.addFloatArg(timelineBang.getValue("Sens"));
        sender.sendMessage(m);
            }
        {
        ofxOscMessage m;
        m.setAddress("/Rand");
        m.addFloatArg(timelineBang.getValue("Rand"));
        sender.sendMessage(m);
            }

        {
        ofxOscMessage m;
        m.setAddress("/Out");
        m.addFloatArg(timelineBang.getValue("Out"));
        sender.sendMessage(m);
                    }
        {
                ofxOscMessage m;
        m.setAddress("/TimeF");
        m.addFloatArg(timelineBang.getValue("TimeF"));
        sender.sendMessage(m);
            }
 {
        ofxOscMessage m;
        m.setAddress("/In");
        m.addFloatArg(timelineBang.getValue("In"));
        sender.sendMessage(m);
            }
//    if(Seq==0){
//    timelineBang.setInPointAtFrame(0);
//    timelineBang.setOutPointAtFrame(2160);
//    }
//    if(Seq==1){
//        timelineBang.setInPointAtFrame(1412);
//    timelineBang.setOutPointAtFrame(2160);
//    }
//    if(Seq==2){
//    timelineBang.setInPointAtFrame(2217);
//    timelineBang.setOutPointAtFrame(3425);
//
//    }
//    if(Seq==3){
//    timelineBang.setInPointAtFrame(3513);
//    timelineBang.setOutPointAtFrame(4166);
//    }
//    if(Seq==4){
//    timelineBang.setInPointAtFrame(4191);
//    timelineBang.setOutPointAtFrame(4443);
//    }
//    if(Seq==5){
//    timelineBang.setInPointAtFrame(4479);
//    timelineBang.setOutPointAtFrame(5134);
//    }
//    if(Seq==6){
////        timelineBang.setInOutRange(ofRange(0.4,0.6));
//    timelineBang.setInPointAtFrame(5274);
//    timelineBang.setOutPointAtFrame(6238);
//    }
//    if(Seq==7){
//       timelineBang.setInPointAtFrame(6220);
//    timelineBang.setOutPointAtFrame(7178);
//    }
//
//    if(Seq==8){
//         timelineBang.setInPointAtFrame(7150);
//    timelineBang.setOutPointAtFrame(7179);
//    }
}
//--------------------------------------------------------------
void testApp::receivedBang(ofxTLBangEventArgs& bang){
	cout << "bang!" <<bang.currentTime<< endl;
//    ofLogNotice("Bang fired from track " + bang->track.getName());
    if(bang.track->getName() == "Vid01"){
        cout << "bangVid1" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(1);
        sender.sendMessage(m);
    }
	if(bang.track->getName() == "Vid02"){
        cout << "bangVid2" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(2);
        sender.sendMessage(m);
	}
	if(bang.track->getName() == "Vid03"){
        cout << "bangVid3" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(3);
        sender.sendMessage(m);
	}
	if(bang.track->getName() == "Vid04"){
        cout << "bangVid4" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(4);
        sender.sendMessage(m);
	}
	if(bang.track->getName() == "Vid05"){
        cout << "bangVid5" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(5);
        sender.sendMessage(m);
	}
	if(bang.track->getName() == "Vid06"){
        cout << "bangVid6" << endl;
        ofxOscMessage m;
        m.setAddress("/Vid");
        m.addFloatArg(6);
        sender.sendMessage(m);
	}
	    if(bang.track->getName() == "SendOsc"){
        cout << "SendOsc" << bang.flag<<endl;
        if(bang.flag    =="1"){
//            cout << "listening for osc messages on port " << RPORT << "\n";
//            receiver.setup(RPORT); //set up receiver
//            sender.setup(HOST, SPORT); //set up sender
        ofxOscMessage m;
        m.setAddress("/SendOsc");
        m.addFloatArg(1);
        sender.sendMessage(m);
            }
        if(bang.flag=="0"){
        ofxOscMessage m;
        m.setAddress("/SendOsc");
        m.addFloatArg(0);
        sender.sendMessage(m);
            }
        }
        if(bang.track->getName() == "SelVid"){
        ofxOscMessage m;
        m.setAddress("/SelVid");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidA"){
        ofxOscMessage m;
        m.setAddress("/SelVidA");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidB"){
        ofxOscMessage m;
        m.setAddress("/SelVidB");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidC"){
        ofxOscMessage m;
        m.setAddress("/SelVidC");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidD"){
        ofxOscMessage m;
        m.setAddress("/SelVidD");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidE"){
        ofxOscMessage m;
        m.setAddress("/SelVidE");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
            if(bang.track->getName() == "SelVidF"){
        ofxOscMessage m;
        m.setAddress("/SelVidF");
        m.addStringArg(bang.flag);
        sender.sendMessage(m);
            }
//
}
//--------------------------------------------------------------
//void testApp::bangFired(ofxTLBangEventArgs& bang){
//
//    //This is our own custom flag protocol to enslave playback
//    //on the sub timelines
//    //a flag that is start 3 or stop 2 will start and stop those timelines
//
//	vector<string> command = ofSplitString(bang.flag, " ");
//    if(command.size() == 2){
//        int trackIndex = ofToInt(command[1]);
//        if(trackIndex >= 0 && trackIndex < sublines.size()){
//            if(command[0] == "start"){
//                sublines[trackIndex]->play();
//            }
//            else if(command[0] == "stop"){
//                sublines[trackIndex]->stop();
//            }
//        }
//    }

//--------------------------------------------------------------

void testApp::draw(){

    ofSetColor(125,125,125,255);
	ofDrawBitmapString("Expand Focused track:_alt+e", 62, 32);
	ofDrawBitmapString("Collapse all tracks:_	alt+c", 62, 52);
	ofDrawBitmapString("Evenly distribute track sizes;_alt+shift+c", 62, 72);


	timelineBang.draw();
	timeline.draw();
	//Gui-------
	 ofFill();
	ofSetColor(255,255,255,255);
    ofRect(1114,70+(Seq*22),16, 16);
}
//------------------------MIDI--------------------------------------

void testApp::newMidiMessage(ofxMidiMessage& msg) {
//	// make a copy of the latest message

            midiMessage = msg;
            cout<<"midi"<<midiMessage.control<<endl;
            Seq = midiMessage.control-1;
            if(midiMessage.control  ==  15){
                ((ofxUICircleSlider*)gui1->getWidget("Sens"))->setValue(midiMessage.value* 2.0);
//                Sens   =    midiMessage.value* 2.0;
                   }

            if(midiMessage.control  ==  1){
                if(midiMessage.value == 0) {
                }
                if(midiMessage.value != 0) {

                }

            }
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
    {
    string name = e.widget->getName();
	int kind = e.widget->getKind();
        if(e.widget->getName()  == "Seq1"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  0;
        }
                if(e.widget->getName()  == "Seq2"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  1;
        }
        if(e.widget->getName()  == "Seq3"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  2;
        }
        if(e.widget->getName()  == "Seq4"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  3;
        }
        if(e.widget->getName()  == "Seq5"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  4;
        }
        if(e.widget->getName()  == "Seq6"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  5;

        }
        if(e.widget->getName()  == "Seq7"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  6;
        }
        if(e.widget->getName()  == "Seq8"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  7;
        }
        if(e.widget->getName()  == "Seq9"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        if(button->getValue()==true)
        Seq =  8;
        }
	if(name == "OpacTV"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
//		OpacTV = slider->getScaledValue();
            }
            else{
        }

        if(Seq==0){
    timelineBang.setInPointAtFrame(0);
    timelineBang.setOutPointAtFrame(2160);
        timelineBang.stop();
    timelineBang.setCurrentFrame(0);
    timelineBang.play();
    }
    if(Seq==1){
        timelineBang.setInPointAtFrame(1412);
    timelineBang.setOutPointAtFrame(2160);
        timelineBang.stop();
    timelineBang.setCurrentFrame(1412);
    timelineBang.play();
    }
    if(Seq==2){
    timelineBang.setInPointAtFrame(2217);
    timelineBang.setOutPointAtFrame(3425);
        timelineBang.stop();
    timelineBang.setCurrentFrame(2217);
    timelineBang.play();

    }
    if(Seq==3){
    timelineBang.setInPointAtFrame(3513);
    timelineBang.setOutPointAtFrame(4166);
        timelineBang.stop();
    timelineBang.setCurrentFrame(3513);
    timelineBang.play();
    }
    if(Seq==4){
    timelineBang.setInPointAtFrame(4191);
    timelineBang.setOutPointAtFrame(4443);
    timelineBang.stop();
    timelineBang.setCurrentFrame(4191);
    timelineBang.play();

    }
    if(Seq==5){
    timelineBang.setInPointAtFrame(4479);
    timelineBang.setOutPointAtFrame(5134);
    timelineBang.stop();
    timelineBang.setCurrentFrame(4479);
    timelineBang.play();
    }
    if(Seq==6){
//        timelineBang.setInOutRange(ofRange(0.4,0.6));
    timelineBang.setInPointAtFrame(5274);
    timelineBang.setOutPointAtFrame(6238);
        timelineBang.stop();
    timelineBang.setCurrentFrame(5274);
    timelineBang.play();;
    }
    if(Seq==7){
       timelineBang.setInPointAtFrame(6220);
    timelineBang.setOutPointAtFrame(6560);
    }

    if(Seq==8){
       timelineBang.setInPointAtFrame(6207);
    timelineBang.setOutPointAtFrame(6500);
    timelineBang.stop();
    timelineBang.setCurrentFrame(6207);
    timelineBang.play();
    }
}
////--------------------------------------------------------------

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//		if(key == 's'){
//			XML.saveFile("mySettings.xml");
//			InOut1 ="settings saved to xml!";
//		}
		if(key == 'b'){
    timelineBang.stop();
    timelineBang.setCurrentFrame(4480);
    timelineBang.play();
		}


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
void testApp::setGUI1()
{

	float dim =8;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 240-xInit;

	gui1 = new ofxUICanvas(1110, 20, 120, 600);


//-------------------------- Player_G1_gui1
    gui1->addWidgetDown(new ofxUILabel("Seq", OFX_UI_FONT_SMALL));


    gui1->addSpacer(1);
//-------------------------- Player_A1_gui1
    gui1->addWidgetDown(new ofxUILabel("In/Out", OFX_UI_FONT_SMALL));

    gui1->addSpacer(1);
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq1"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq2"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq3"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq4"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq5"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq6"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq7"));
    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq8"));
//    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq9"));
//    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq10"));
//    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq11"));
//    gui1->addWidgetDown(new ofxUIButton(dim*2, dim*2,  false, "Seq12"));

	ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
}
