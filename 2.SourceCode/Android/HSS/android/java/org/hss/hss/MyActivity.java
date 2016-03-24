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

import java.io.IOException;

public class MyActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    public static MyActivity currentActivity;

    public static MyActivity getIns()
    {
        return currentActivity;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        currentActivity = this;
    }

    public void showToast(final String text) {
        Log.w("TAG", "onCreate");
        currentActivity.runOnUiThread(new Runnable() {
             public void run() {
                  Toast.makeText(currentActivity, text, Toast.LENGTH_SHORT).show();
             }
        });
    }
}
