#!/bin/sh

ifconfig -a | grep ether | cut -c15- | cut -c1-17
