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

import com.pusher.client.Pusher;
import com.pusher.client.channel.Channel;
import com.pusher.client.channel.SubscriptionEventListener;

import java.io.IOException;

public class MyActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static native void callNativeOne(int x);
    private Intent mServiceIntent;
    public static MyActivity currentActivity;
    public Pusher pusher;

    public static MyActivity getIns()
    {
        Log.w("myApp","getIns~~~~~~~~~~~~~~~~~");
        return currentActivity;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        currentActivity = this;
        Log.w("TAG", "onCreate");

        mServiceIntent = new Intent(this, MyService.class);
        this.startService(mServiceIntent);
    }
}
