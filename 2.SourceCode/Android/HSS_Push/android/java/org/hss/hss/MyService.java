package org.hss.hss;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.app.PendingIntent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.support.v4.app.NotificationCompat;
import android.app.NotificationManager;
import android.app.IntentService;
import android.support.v4.app.TaskStackBuilder;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.os.Vibrator;
import android.media.RingtoneManager;
import android.media.Ringtone;
import android.net.Uri;

import com.pusher.client.Pusher;
import com.pusher.client.channel.Channel;
import com.pusher.client.channel.SubscriptionEventListener;

import java.io.IOException;

public class MyService extends IntentService {
    public Pusher pusher;
    private NotificationManager mNotificationManager;
    static int nofId;

    public MyService() {
        super("MyService");
    }

    @Override
    protected void onHandleIntent(Intent workIntent) {
        nofId = 0;
        pusher = new Pusher("0d2838d583ebb263b04c");

        Channel channel = pusher.subscribe("test_channel");

        channel.bind("my_event", new SubscriptionEventListener() {
            @Override
            public void onEvent(String channelName, String eventName, final String data) {
                Log.w("TAG", "Received from >" + eventName + "< with >" + data + "<");
                sendNotification(data);
            }
        });

        pusher.connect();
    }

    private void sendNotification(String msg) {
        mNotificationManager = (NotificationManager)
                this.getSystemService(Context.NOTIFICATION_SERVICE);

        PendingIntent contentIntent = PendingIntent.getActivity(this, 0,
                new Intent(this, MyActivity.class), 0);

        NotificationCompat.Builder mBuilder =
                new NotificationCompat.Builder(this)
                                       .setSmallIcon(R.drawable.icon)
                                       .setContentTitle("My notification")
                                       .setContentText("Hello World!");
        mBuilder.setContentIntent(contentIntent);
        mBuilder.setAutoCancel(true);
        PowerManager pm = (PowerManager) this.getSystemService(Context.POWER_SERVICE);
        WakeLock wl = pm.newWakeLock(PowerManager.FULL_WAKE_LOCK | PowerManager.ACQUIRE_CAUSES_WAKEUP, "TAG");
        wl.acquire(15000);
        Vibrator v = (Vibrator) this.getSystemService(Context.VIBRATOR_SERVICE);
        v.vibrate(2000);
         Uri notification = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
         Ringtone r = RingtoneManager.getRingtone(getApplicationContext(), notification);
         r.play();

        mNotificationManager.notify(nofId, mBuilder.build());
        nofId++;

    }

}
