#!/bin/bash
rfkill unblock all
ip link set wlx00c0caa89ffc down
iw dev wlx00c0caa89ffc set type monitor
ip link set wlx00c0caa89ffc up
