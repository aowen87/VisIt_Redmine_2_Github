import sys

Source("base.py")

W = 1024
H = 1024
samp = 1000

#VolumeRender
AddPlot("Volume", "node_sMD", 1, 0)
va = VolumeAttributes()
va.legendFlag = 1
va.lightingFlag = 0
va.opacityAttenuation = .57
va.useColorVarMin = 1
va.colorVarMin = 10
va.useColorVarMax = 1
va.colorVarMax = 15

va.samplesPerRay = samp
va.rendererType = va.RayCasting  # Splatting, Texture3D, RayCasting, RayCastingIntegration, SLIVR, Tuvok


#Color table. hot_desaturated
va.GetColorControlPoints().ClearControlPoints()
clr = ColorControlPoint()
clr.colors = (71, 71, 219, 255)
clr.position = 0
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (0, 0, 91, 255)
clr.position = 0.143
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (0, 255, 255, 255)
clr.position = 0.285
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (0, 127, 0, 255)
clr.position = 0.429
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (255, 255, 0, 255)
clr.position = 0.571
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (255, 96, 0, 255)
clr.position = 0.714
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (107, 0, 0, 255)
clr.position = 0.857
va.GetColorControlPoints().AddControlPoints(clr)

clr.colors = (224, 76, 76, 255)
clr.position = 1
va.GetColorControlPoints().AddControlPoints(clr)
va.colorControlPoints.smoothingFlag = 1
va.colorControlPoints.equalSpacingFlag = 0
va.colorControlPoints.discreteFlag = 0
va.colorControlPoints.externalFlag = 0

#
#Transfer funciton
va.opacityMode = va.GaussianMode  # FreeformMode, GaussianMode, ColorTableMode
va.opacityControlPoints.ClearControlPoints()

c = GaussianControlPoint()

c.x = 0.564612
c.height = 0.276316
c.width = 0.161034
c.xBias = 0
c.yBias = 0
va.GetOpacityControlPoints().AddControlPoints(c)

c.x = 0.349901
c.height = 0.144737
c.width = 0.109344
c.xBias = 0
c.yBias = 0
va.GetOpacityControlPoints().AddControlPoints(c)

c.x = 0.765408
c.height = 0.881579
c.width = 0.137177
c.xBias = 0
c.yBias = 0
va.GetOpacityControlPoints().AddControlPoints(c)

c.x = 0.210736
c.height = 0.0921053
c.width = 0.0994036
c.xBias = 0
c.yBias = 0
va.GetOpacityControlPoints().AddControlPoints(c)


#Set view
view = View3DAttributes()
view.viewNormal = (-0.857227, -0.34997, 0.377734)
view.viewUp = (-0.477029, 0.815957, -0.326584)
view.nearPlane = -1.04837e+08
view.farPlane = 1.04837e+08
view.imagePan = (0.00645685, -0.00928373)
view.imageZoom = 2.14359
SetView3D(view)

#Annotations
a = GetAnnotationAttributes()
a.backgroundColor=(0,0,0,255)
a.foregroundColor=(255,255,255,255)
a.axes3D.bboxFlag = 0
a.axes3D.xAxis.tickMarks.visible = 0
a.userInfoFlag = 0
SetAnnotationAttributes(a)

#Save window attrs
sa = SaveWindowAttributes()
sa.fileName = "snVolRend"
sa.format = sa.PNG
sa.width = W
sa.height = H
sa.resConstraint = sa.NoConstraint
SetSaveWindowAttributes(sa)


## Do the work!
SetPlotOptions(va)

AddOperator("Isovolume")
iso = IsovolumeAttributes()
iso.lbound = 12.5
SetOperatorOptions(iso)

DrawPlots()


SaveWindow()
sys.exit()
