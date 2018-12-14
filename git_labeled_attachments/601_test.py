OpenDatabase("localhost:/usr/gapps/visit/data/curv3d.silo", 0)
AddPlot("Pseudocolor", "u", 1, 1)
DrawPlots()
OpenDatabase("localhost:/usr/gapps/visit/data/noise.silo", 0)
AddPlot("Pseudocolor", "PointVar", 1, 1)
DrawPlots()
PseudocolorAtts = PseudocolorAttributes()
PseudocolorAtts.pointType = PseudocolorAtts.Sphere
PseudocolorAtts.pointSizePixels = 20
SetPlotOptions(PseudocolorAtts)
View3DAtts = View3DAttributes()
View3DAtts.viewNormal = (0.639859, 0.671989, 0.372842)
View3DAtts.focus = (-0.0242615, -0.170417, 10.0743)
View3DAtts.viewUp = (-0.405118, 0.707224, -0.579408)
View3DAtts.viewAngle = 30
View3DAtts.parallelScale = 24.1266
View3DAtts.nearPlane = -48.2531
View3DAtts.farPlane = 48.2531
View3DAtts.imagePan = (0, 0)
View3DAtts.imageZoom = 1
View3DAtts.perspective = 1
View3DAtts.eyeAngle = 2
View3DAtts.centerOfRotationSet = 0
View3DAtts.centerOfRotation = (-0.0242615, -0.170417, 10.0743)
View3DAtts.axis3DScaleFlag = 0
View3DAtts.axis3DScales = (1, 1, 1)
View3DAtts.shear = (0, 0, 1)
SetView3D(View3DAtts)
AnnotationAtts = AnnotationAttributes()
AnnotationAtts.axes3D.visible = 0
AnnotationAtts.axes3D.bboxFlag = 1
AnnotationAtts.userInfoFlag = 0
AnnotationAtts.databaseInfoFlag = 1
AnnotationAtts.legendInfoFlag = 1
AnnotationAtts.backgroundColor = (0, 0, 0, 255)
AnnotationAtts.foregroundColor = (255, 255, 255, 255)
AnnotationAtts.backgroundMode = AnnotationAtts.Solid
SetAnnotationAttributes(AnnotationAtts)
RenderingAtts = RenderingAttributes()
RenderingAtts.specularFlag = 1
SetRenderingAttributes(RenderingAtts)
SaveWindow()
