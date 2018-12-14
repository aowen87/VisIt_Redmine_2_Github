#!/usr/bin/python -i
# -*- coding: utf-8 -*-

from visit import *
Launch()
OpenGUI()

def active_plots(ids, flag):
  print "SetActivePlotsRPC catched :",ids
#

RegisterCallback('SetActivePlotsRPC', active_plots)
