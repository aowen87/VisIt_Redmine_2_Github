# We want on-screen rendering so we can contrast with explicit SR mode.
#./visit -cli -np 4 -s transparent_mesh.py 

import sys

def setup():
    # Create plot 1
    AddPlot("Mesh", "mesh1")
    atts = MeshAttributes(1)
    atts.opacity = 0.109804
    SetPlotOptions(atts)

    # Create plot 2
    AddPlot("FilledBoundary", "mat1")
    fb = FilledBoundaryAttributes(1)
    fb.SetMultiColor(0, (255, 0, 0, 255))
    fb.SetMultiColor(1, (0, 255, 0, 67))
    fb.SetMultiColor(2, (0, 0, 255, 255))
    SetPlotOptions(fb)

    # Set the view
    view = View3DAttributes()
    view.viewNormal = (-0.650079, 0.303104, 0.696796)
    view.focus = (0.5, 0.5, 0.5)
    view.viewUp = (0.140041, 0.949081, -0.282195)
    view.viewAngle = 30
    view.parallelScale = 0.866025
    view.nearPlane = -1.73205
    view.farPlane = 1.73205
    view.imagePan = (0.0298507, 0.0545635)
    view.imageZoom = 1
    view.perspective = 1
    view.eyeAngle = 2
    view.centerOfRotationSet = 0
    view.centerOfRotation = (0.5, 0.5, 0.5)
    view.axis3DScaleFlag = 0
    view.axis3DScales = (1, 1, 1)
    view.shear = (0, 0, 1)
    SetView3D(view)

    # Set the annotation attributes
    annot = AnnotationAttributes()
    annot.axes3D.visible = 0
    annot.userInfoFlag = 0
    annot.databaseInfoFlag = 1
    annot.timeInfoFlag = 1
    annot.legendInfoFlag = 1
    annot.backgroundColor = (255, 255, 255, 255)
    annot.foregroundColor = (0, 0, 0, 255)
    annot.gradientBackgroundStyle = annot.TopToBottom  # TopToBottom, BottomToTop, LeftToRight, RightToLeft, Radial
    annot.gradientColor1 = (0, 51, 102, 255)
    annot.gradientColor2 = (0, 0, 0, 255)
    annot.backgroundMode = annot.Solid  # Solid, Gradient, Image, ImageSphere
    annot.backgroundImage = ""
    annot.imageRepeatX = 1
    annot.imageRepeatY = 1
    SetAnnotationAttributes(annot)

    DrawPlots()

def saveImage(filename):
    swa = GetSaveWindowAttributes()
    swa.outputDirectory = "."
    swa.fileName = filename
    swa.family = 0
    swa.format =  swa.PNG
    swa.screenCapture = 1
    SetSaveWindowAttributes(swa)
    SaveWindow()

def main():
    db = "localhost:/Users/bjw/Development/data/multi_rect3d.silo"
    OpenDatabase(db)
    setup()
    saveImage("withoutSR.png")
    ClearWindow()
    
    # Switch to SR mode.
    ra = RenderingAttributes()
    ra.scalableActivationMode = ra.Always  # Never, Always, Auto
    ra.scalableAutoThreshold = 2000000
    SetRenderingAttributes(ra)
    DrawPlots()
    
    saveImage("withSR.png")

main()
sys.exit(0)
