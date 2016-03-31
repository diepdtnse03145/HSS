package org.hss.hss;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.support.v4.app.NotificationCompat;
import android.app.NotificationManager;
import android.app.IntentService;

import org.linphone.core.LinphoneAddress;
import org.linphone.core.LinphoneCall;
import org.linphone.core.LinphoneCall.State;
import org.linphone.core.LinphoneCallStats;
import org.linphone.core.LinphoneChatMessage;
import org.linphone.core.LinphoneChatRoom;
import org.linphone.core.LinphoneCore;
import org.linphone.core.LinphoneCore.EcCalibratorStatus;
import org.linphone.core.LinphoneCore.GlobalState;
import org.linphone.core.LinphoneCore.RegistrationState;
import org.linphone.core.LinphoneCoreException;
import org.linphone.core.LinphoneCoreFactory;
import org.linphone.core.LinphoneCoreListener;
import org.linphone.core.LinphoneFriend;
import org.linphone.core.LinphoneProxyConfig;
import org.linphone.core.LinphoneEvent;
import org.linphone.core.LinphoneContent;
import org.linphone.core.PublishState;
import org.linphone.core.SubscriptionState;
import org.linphone.core.LinphoneInfoMessage;
import org.linphone.core.LinphoneAuthInfo;


public class LpVoIP implements LinphoneCoreListener, LinphoneChatMessage.StateListener {
	private boolean running;

	public LpVoIP() {
	}

	public void show(LinphoneCore lc) {}
	public void byeReceived(LinphoneCore lc, String from) {}
        public void authInfoRequested(LinphoneCore lc, String realm, String username, String Domain) {}
	public void displayStatus(LinphoneCore lc, String message) {}
	public void displayMessage(LinphoneCore lc, String message) {}
	public void displayWarning(LinphoneCore lc, String message) {}
	public void globalState(LinphoneCore lc, GlobalState state, String message) {}
	public void newSubscriptionRequest(LinphoneCore lc, LinphoneFriend lf,String url) {}
	public void notifyPresenceReceived(LinphoneCore lc, LinphoneFriend lf) {}
	public void callState(LinphoneCore lc, LinphoneCall call, State cstate, String msg){}
	public void callStatsUpdated(LinphoneCore lc, LinphoneCall call, LinphoneCallStats stats) {}
	public void ecCalibrationStatus(LinphoneCore lc, EcCalibratorStatus status,int delay_ms, Object data) {}
	public void callEncryptionChanged(LinphoneCore lc, LinphoneCall call,boolean encrypted, String authenticationToken) {}
	public void notifyReceived(LinphoneCore lc, LinphoneCall call, LinphoneAddress from, byte[] event){}
	public void dtmfReceived(LinphoneCore lc, LinphoneCall call, int dtmf) {}
        public void uploadStateChanged(LinphoneCore lc, LinphoneCore.LogCollectionUploadState state, java.lang.String info) {}
        public void uploadProgressIndication(LinphoneCore lc, int offset, int total) {}
        public void isComposingReceived(LinphoneCore lc, LinphoneChatRoom cr) {}
        public void notifyReceived(LinphoneCore lc, LinphoneEvent ev, java.lang.String eventName, LinphoneContent content) {}
        public void configuringStatus(LinphoneCore lc, LinphoneCore.RemoteProvisioningState state, java.lang.String message) {}
        public int fileTransferSend(LinphoneCore lc, LinphoneChatMessage message, LinphoneContent content, java.nio.ByteBuffer buffer, int size) {
            return 0;
        }
        public void fileTransferRecv(LinphoneCore lc, LinphoneChatMessage message, LinphoneContent content, byte[] buffer, int size) {}
        public void fileTransferProgressIndication(LinphoneCore lc, LinphoneChatMessage message, LinphoneContent content, int progress) {}
        public void publishStateChanged(LinphoneCore lc, LinphoneEvent ev, PublishState state) {}
        public void subscriptionStateChanged(LinphoneCore lc, LinphoneEvent ev, SubscriptionState state) {}
        public void infoReceived(LinphoneCore lc, LinphoneCall call, LinphoneInfoMessage info) {}
        public void transferState(LinphoneCore lc, LinphoneCall call, LinphoneCall.State new_call_state) {}

	public void textReceived(LinphoneCore lc, LinphoneChatRoom cr,LinphoneAddress from, String message) {
        //Deprecated
	}

	public void launch(String destinationSipAddress) throws LinphoneCoreException {

		// First instantiate the core Linphone object given only a listener.
		// The listener will react to events in Linphone core.
                LinphoneCore lc = LinphoneCoreFactory.instance().createLinphoneCore(this, MyActivity.getIns());
                lc.migrateToMultiTransport();

                try {
                    LinphoneCall call = lc.invite(destinationSipAddress);
                    if (call == null) {
                            write("Could not place call to " + destinationSipAddress);
                            write("Aborting");
                            return;
                    }
                    write("Call to " + destinationSipAddress + " is in progress...");



                // Next step is to create a chat room
                LinphoneChatRoom chatRoom = lc.getOrCreateChatRoom(destinationSipAddress);

                // Send message
                LinphoneChatMessage chatMessage = chatRoom.createLinphoneChatMessage("Hello world");
                chatRoom.sendMessage(chatMessage, this);

                // main loop for receiving notifications and doing background linphonecore work
                running = true;
                while (running) {
                        lc.iterate();
                        try{
                                Thread.sleep(50);
                        } catch(InterruptedException ie) {
                                write("Interrupted!\nAborting");
                                return;
                        }
                }

		} finally {
			write("Shutting down...");
			// You need to destroy the LinphoneCore object when no longer used
			lc.destroy();
			write("Exited");
		}
	}


	public void stopMainLoop() {
		running=false;
	}


	private void write(String s) {
            Log.w("myApp", s);
	}

	@Override
	public void messageReceived(LinphoneCore lc, LinphoneChatRoom cr,
			LinphoneChatMessage message) {
                write("Message [" + message.getText() + "] received from [" + message.getFrom().asString() + "]");
	}

	@Override
	public void onLinphoneChatMessageStateChanged(LinphoneChatMessage msg,
			org.linphone.core.LinphoneChatMessage.State state) {
                write("Sent message [" + msg.getText() + "] new state is " + state.toString());
//                stopMainLoop();
	}

        @Override
        public void registrationState(LinphoneCore lc, LinphoneProxyConfig cfg,RegistrationState cstate, String smessage) {
                write("MoeMoe "+ cfg.getIdentity() + " : "+smessage);
        }

}
