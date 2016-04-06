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
import android.widget.Toast;

import com.pusher.client.Pusher;
import com.pusher.client.channel.Channel;
import com.pusher.client.channel.SubscriptionEventListener;

import java.io.IOException;
import org.hss.hss.LpVoIP;

public class MyActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static native void toLoginScr();
    public static MyActivity currentActivity;
    private Intent mServiceIntent;
    public Pusher pusher;

    public static MyActivity getIns()
    {
        return currentActivity;
    }

    private boolean m_isCalling;

    public boolean isCalling()
    {
        return m_isCalling;
    }

    public void setIsCalling(boolean vl)
    {
        m_isCalling = vl;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        currentActivity = this;

        mServiceIntent = new Intent(this, MyService.class);
        this.startService(mServiceIntent);
    }

    public void showToast(final String text) {
        currentActivity.runOnUiThread(new Runnable() {
             public void run() {
                  Toast.makeText(currentActivity, text, Toast.LENGTH_SHORT).show();
             }
        });
    }

    public void toHome() {
        Intent startMain = new Intent(Intent.ACTION_MAIN);
        startMain.addCategory(Intent.CATEGORY_HOME);
        startMain.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(startMain);
    }

    public void call(final String des) {
        Log.w("myApp","Moe~~~~~~~~~~~~~~~~~");

        setIsCalling(true);
        Thread thread = new Thread() {
            @Override
            public void run() {
                Log.w("myApp","Moe~~~~~~~~~~~~~~~~~");
                LpVoIP t = new LpVoIP();
                try {
                        t.launch(des);
                } catch (Exception e) {
                        e.printStackTrace();
                }
            }
        };

        thread.start();
    }

    public void endCall()
    {
        setIsCalling(false);
    }
}
