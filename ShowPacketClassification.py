#!/usr/bin/env python
import argparse
import sys
import struct
import os
import threading

from scapy.all import sniff, sendp, hexdump, get_if_list, get_if_hwaddr
from scapy.all import ShortField, IntField, LongField, BitField, FieldListField, FieldLenField
from scapy.layers.inet import _IPOption_HDR

sparkkmeans=0
iperf = 0
memcached = 0
ping = 0
sparkglm = 0
other = 0
total = 0

def print_Data():
    global total
    total = total+1
    sys.stdout.write("{0}\n".format(" iperf => "+str(iperf)+ "\t memcached => " + str(memcached) + "\t ping => " + str(ping) + "\t sparkglm => " + str(sparkglm) + "\t sparkkmeans => " + str(sparkkmeans)+ "\t other => " + str(other) + "\t total => " + str(total)))
    sys.stdout.flush()

def handle_IOT_pkt(pkt):
    global memcached
    memcached = memcached +1
    print_Data()
    

def handle_sparkkmeans_pkt(pkt):
    global sparkkmeans
    sparkkmeans = sparkkmeans +1
    print_Data()

def handle_Smart_home_devices_pkt(pkt):
    global iperf
    iperf = iperf +1
    print_Data()

def handle_audio_pkt(pkt):
    global ping
    ping = ping +1
    print_Data()

def handle_video_pkt(pkt):
    global sparkglm
    sparkglm = sparkglm +1
    print_Data()

def handle_other_pkt(pkt):
    global other
    other = other +1
    print_Data()


def sniff_IOT_pkt(iface_name_IOT):
	sniff(iface = iface_name_IOT,prn = lambda x: handle_IOT_pkt(x))

def sniff_sparkkmeans_pkt(iface_name_other):
	sniff(iface = iface_name_other,prn = lambda x: handle_sparkkmeans_pkt(x))

def sniff_SmartDevices_pkt(iface_name_smart):
	sniff(iface = iface_name_smart,prn = lambda x: handle_Smart_home_devices_pkt(x))

def sniff_Audio_pkt(iface_name_audio):
	sniff(iface = iface_name_audio,prn = lambda x: handle_audio_pkt(x))

def sniff_Video_pkt(iface_name_video):
	sniff(iface = iface_name_video,prn = lambda x: handle_video_pkt(x))


def sniff_Other_pkt(iface_name_video):
	sniff(iface = iface_name_video,prn = lambda x: handle_other_pkt(x))


def main():
    t1 = threading.Thread(target=sniff_SmartDevices_pkt, args=("vf0_1",))
    t2 = threading.Thread(target=sniff_IOT_pkt, args=("vf0_2",))
    t3 = threading.Thread(target=sniff_Audio_pkt, args=("vf0_3",))
    t4 = threading.Thread(target=sniff_Video_pkt, args=("vf0_4",))
    t5 = threading.Thread(target=sniff_sparkkmeans_pkt, args=("vf0_5",))
    t6 = threading.Thread(target=sniff_Other_pkt, args=("vf0_6",))
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()
    t6.start()

if __name__ == '__main__':
	main()

