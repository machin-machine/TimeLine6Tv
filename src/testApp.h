#pragma once

#include "ofMain.h"

#include "ofxUI.h"
#include "ofxMidi.h"


#include "ofxTimeline.h"
#define MAX_N_PTS         1500
#include "ofxOsc.h"
#define RPORT 12349 //incoming
#define SPORT 12347 //outgoing
#define NUM_MSG_STRINGS 100
#define HOST "localhost"
class testApp : public ofBaseApp, public ofxMidiListener{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    void receivedBang(ofxTLBangEventArgs& bang);


	ofxTimeline timelineBang;
    ofxTimeline timeline;


	 //OSC-------
        ofxOscReceiver receiver;
		ofxOscSender    sender;
		string getOscMsgAsString(ofxOscMessage m);

		int current_msg_string;
		string msg_strings[NUM_MSG_STRINGS];
		float timers[NUM_MSG_STRINGS];

        string movieAdress;
        float   SendOsc;


    //MIDI---------------
    void newMidiMessage(ofxMidiMessage& eventArgs);
    stringstream text;

	ofxMidiIn midiIn;
    ofxMidiOut midiOut;
	ofxMidiMessage midiMessage;

    //GUI---------
	void setGUI1();
    ofxUICanvas *gui1;
    void guiEvent(ofxUIEventArgs &e);
    float Seq;



};
