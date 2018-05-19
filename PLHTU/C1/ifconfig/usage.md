- Usage of `ifconfig`

- shutdown a network interface

```sudo ifconfig wlan0 down```

- up a network interface

```
sudo ifconfig wlan0 up
```

- change network interface MTU

```
sudo ifconfig wlan0 mtu 1000
```

- disable arp and enable arp

```
sudo ifconfig wlan0 -arp
arp  # show nothing
sudo ifconfig wlan0 arp
arp # get the arp table again

# Address                  HWtype  HWaddress           Flags Mask            Iface
# ACA80101.ipt.aol.com     ether   F0:A7:D0:0b:cb:4a   C                     wlan0
```

- enable and disable `promisc` mode of a network interface

```
sudo ifconfig wlan0 promisc
ifconfig
# wlan0: flags=4419<UP,BROADCAST,RUNNING,PROMISC,MULTICAST>  mtu 1000
sudo ifconfig wlan0 -promisc
ifconfig
# wlan0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1000
```




