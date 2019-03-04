#!/usr/bin/python2.6

#from filter_mover import *
import visit
from filter_mover import *

export_images = True

runningSelf = True
if sys.argv[0][-3:] == 'cli' or sys.argv[0] == '-':
  runningSelf = False
#

if runningSelf:
  if export_images:
    visit.AddArgument('-nowin')
  #  
  visit.Launch()
#

print "**\n** filtermovie.py: running VisIt", visit.Version(),"\n**"
visit.OpenDatabase("2d_filter.visit")

visit.AddPlot("Pseudocolor", "filtered_image")
pa = visit.PseudocolorAttributes()
pa.centering = pa.Nodal
pa.minFlag = True
pa.min = -0.7
pa.maxFlag = True
pa.max = 0.7
visit.SetPlotOptions(pa)

visit.AddOperator("Elevate")
ea = visit.ElevateAttributes()
ea.useXYLimits = 1
ea.minFlag = True
ea.min = -0.7
ea.maxFlag = True
ea.max = 0.7
visit.SetOperatorOptions(ea)

## Set global Annotations:
annot_attr = visit.GetAnnotationAttributes()
annot_attr.axes3D.triadFlag = False
annot_attr.axes3D.axesType = annot_attr.axes3D.StaticTriad

annot_attr.axes3D.xAxis.title.userTitle = True
annot_attr.axes3D.xAxis.title.title = "X"
annot_attr.axes3D.xAxis.title.font.scale = 1.5

annot_attr.axes3D.yAxis.title.userTitle = True
annot_attr.axes3D.yAxis.title.title = "Y"
annot_attr.axes3D.yAxis.title.font.scale = 1.5

annot_attr.axes3D.zAxis.title.userTitle = True
annot_attr.axes3D.zAxis.title.title = "image * gauss"
annot_attr.axes3D.zAxis.title.font.scale = 1.5
annot_attr.axes3D.zAxis.tickMarks.visible = False
annot_attr.axes3D.zAxis.label.visible = False

annot_attr.userInfoFlag = False
annot_attr.databaseInfoFlag = False
visit.SetAnnotationAttributes(annot_attr)

## Set plot Annotations:
p = visit.GetAnnotationObjectNames()[0]
psc_ann = visit.GetAnnotationObject(p)
psc_ann.drawTitle = False
psc_ann.managePosition = False
psc_ann.position = (0.05, 0.98)
psc_ann.orientation = psc_ann.HorizontalTop

## SaveWindow attributes
swa = visit.SaveWindowAttributes()
#swa.outputToCurrentDirectory = False
#swa.outputDirectory = "2d_filter_frames"
#swa.format = swa.JPEG
#swa.quality = 100
#visit.SetSaveWindowAttributes(swa)

## Set properties for the animation:
animation_settings = MoverSettings()
animation_settings.save = export_images
animation_settings.ph0_steps = 30
controller = Mover(visit, animation_settings)

# start the plotting:
visit.DrawPlots()

# Perform the animation:
controller.animate()

if not controller.save():
  raw_input("**\n** Press Enter to finish\n**")
