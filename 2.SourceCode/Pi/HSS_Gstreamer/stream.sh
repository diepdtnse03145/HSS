#!/bin/sh

myip=$(ip add show eth0 | awk '/inet / {print $2}' | cut -d -f 1)
set port=5000
set width=320
set height=240

gst-launch\
  v4l2src !\
  ffmpegcolorspace !\
  video/x-raw-yuv,width=${width},height=${height},framerate=\(fraction\)30/1 !\
  jpegenc !\
  tcpserversink host=${myip} port=${port} sync=false