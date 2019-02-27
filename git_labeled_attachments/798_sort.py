OpenDatabase("saved-sort.vtk")

AddPlot("Pseudocolor", "Normals_magnitude")
pc = PseudocolorAttributes()
pc.opacityType = pc.Explicit
pc.opacity = 0.9
SetPlotOptions(pc)

#AddPlot("Mesh", "mesh")

#InvertBackgroundColor()

View3DAtts = View3DAttributes()
View3DAtts.viewNormal = (-0.140771, 0.640697, 0.754779)
View3DAtts.focus = (436672, 3.68192e+06, 133.6)
View3DAtts.viewUp = (0.0617961, 0.76657, -0.639181)
View3DAtts.viewAngle = 30
View3DAtts.parallelScale = 222.628
View3DAtts.nearPlane = -445.256
View3DAtts.farPlane = 445.256
View3DAtts.imagePan = (0, 0)
View3DAtts.imageZoom = 1
View3DAtts.perspective = 1
View3DAtts.eyeAngle = 2
View3DAtts.centerOfRotationSet = 0
View3DAtts.centerOfRotation = (436672, 3.68192e+06, 133.6)
View3DAtts.axis3DScaleFlag = 0
View3DAtts.axis3DScales = (1, 1, 1)
View3DAtts.shear = (0, 0, 1)
SetView3D(View3DAtts)

DrawPlots()
