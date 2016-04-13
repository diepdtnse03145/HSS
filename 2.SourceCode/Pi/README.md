
================ TAKE PHOTO FROM WEBCAM ================

1. Install Apache
sudo apt-get install apache2 -y

2. Install fswebcam
sudo apt-get install fswebcam

3. TAKE PHOTO FROM USB WEBCAM
sudo fswebcam -r 640x480 --no-banner /var/www/html/door.jpg -S 2