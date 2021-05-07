#!/bin/bash -x

sudo ifconfig vf0_0 down
sudo ifconfig vf0_1 down
sudo ifconfig vf0_2 down
sudo ifconfig vf0_3 down
sudo ifconfig vf0_4 down
sudo ifconfig vf0_5 down
sudo ifconfig vf0_6 down
ifconfig vf0_1 hw ether 00:00:00:00:00:02
ifconfig vf0_2 hw ether 00:00:00:00:00:03
ifconfig vf0_3 hw ether 00:00:00:00:00:04
ifconfig vf0_4 hw ether 00:00:00:00:00:05
ifconfig vf0_5 hw ether 00:00:00:00:00:06
ifconfig vf0_6 hw ether 00:00:00:00:00:07

#sudo ifconfig vf0_0 192.168.2.2/24 up
sudo ifconfig vf0_1 192.168.2.3/24 up
sudo ifconfig vf0_2 192.168.2.4/24 up
sudo ifconfig vf0_3 192.168.2.5/24 up
sudo ifconfig vf0_4 192.168.2.6/24 up
sudo ifconfig vf0_5 192.168.2.7/24 up
sudo ifconfig vf0_6 192.168.2.8/24 up

# move vf0_0 into its own namespace
sudo ip netns exec ns_server ip link set vf0_0 netns 1
sudo ip netns delete ns_server
#sudo ifconfig vf0_0 down
sudo ip netns add ns_server

sudo ip link set vf0_0 netns ns_server
sudo ip netns exec ns_server ip addr add dev vf0_0 192.168.2.2/24
sudo ip netns exec ns_server ifconfig vf0_0 hw ether 00:00:00:00:00:01
sudo ip netns exec ns_server ip link set dev vf0_0 up
#sudo ip link set vf0_0 up

sudo ip netns exec ns_server arp -s 192.168.2.2 00:00:00:00:00:01 -i vf0_0
#sudo ip netns exec ns_server arp -s 192.168.2.4 00:33:33:33:33:33 -i vf0_0

#sudo arp -s 192.168.2.2 00:11:11:11:11:11 -i vf0_1
#sudo arp -s 192.168.2.4 00:33:33:33:33:33 -i vf0_1
