

----- SYNC DATE AND TIME -----
########## Require Internet connection before syncing

sudo cp /usr/share/zoneinfo/Asia/Ho_Chi_Minh /etc/localtime
sudo /etc/init.d/ntp restart
sudo ntpd -gq

