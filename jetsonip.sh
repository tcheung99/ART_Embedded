#!/bin/bash 

usbid=`ls /dev/serial/by-id/ | grep Arduino`
usbid="/dev/serial/by-id/$usbid"
baud_rate=9600;
stty -F $usbid cs8 $baud_rate ignbrk -brkint -icrnl \
  -imaxbel -opost -onlcr -isig -icanon -iexten -echo \
  -echoe -echok -echoctl -echoke noflsh -ixon -crtscts;
tail -f $usbid & bg;
while :
do
IP=`hostname -i | awk '{print $1}'`
IP_b = `hostname -i | awk '{print $2}'`
printf $IP > $usbid
printf $IP_b > $usbid
sleep 1;
done


