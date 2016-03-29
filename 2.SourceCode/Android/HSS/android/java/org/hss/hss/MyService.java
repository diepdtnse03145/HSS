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

import com.pusher.client.Pusher;
import com.pusher.client.channel.Channel;
import com.pusher.client.channel.SubscriptionEventListener;

import java.io.IOException;

public class MyService extends IntentService {
    public Pusher pusher;
    private NotificationManager mNotificationManager;

    public MyService() {
        super("MyService");
    }

    @Override
    protected void onHandleIntent(Intent workIntent) {
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
                                       .setContentTitle(msg)
                                       .setContentText("Touch to view detail.");
        mBuilder.setContentIntent(contentIntent);
        mBuilder.setAutoCancel(true);
        mNotificationManager.notify(1, mBuilder.build());
    }

}
