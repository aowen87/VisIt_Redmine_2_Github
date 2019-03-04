SetWindowArea(0,0,800,800)
OpenDatabase("/usr/gapps/visit/data/multi_rect2d.silo")

AddPlot("Pseudocolor", "d", 1, 0)

PA = PseudocolorAttributes()
PA.minFlag = 0
PA.maxFlag = 0
PA.scaling = PA.Linear  # Linear, Log, Skew
PA.min = 0
PA.max = 0
PA.colorTableName = "calewhite"
PA.invertColorTable = 0
SetPlotOptions(PA)


A = AnnotationAttributes()
#print(A)
A.axes2D.visible = 1
A.axes2D.autoSetTicks = 0
A.axes2D.autoSetScaling = 0
A.axes2D.lineWidth = 2
A.axes2D.tickLocation = A.axes2D.Both  # Inside, Outside, Both
A.axes2D.tickAxes = A.axes2D.All  # Off, Bottom, Left, BottomLeft, All
A.axes2D.xAxis.title.visible = 1
A.axes2D.xAxis.title.font.font = A.axes2D.xAxis.title.font.Arial  # Arial, Courier, Times
A.axes2D.xAxis.title.font.scale = 2
A.axes2D.xAxis.title.font.useForegroundColor = 1
A.axes2D.xAxis.title.font.color = (0, 0, 0, 255)
A.axes2D.xAxis.title.font.bold = 1
A.axes2D.xAxis.title.font.italic = 0
A.axes2D.xAxis.title.userTitle = 1
A.axes2D.xAxis.title.userUnits = 1
A.axes2D.xAxis.title.title = "Z"
A.axes2D.xAxis.title.units = "pc"
A.axes2D.xAxis.label.visible = 1
A.axes2D.xAxis.label.font.font = A.axes2D.xAxis.label.font.Arial  # Arial, Courier, Times
A.axes2D.xAxis.label.font.scale = 2
A.axes2D.xAxis.label.font.useForegroundColor = 1
A.axes2D.xAxis.label.font.color = (0, 0, 0, 255)
A.axes2D.xAxis.label.font.bold = 1
A.axes2D.xAxis.label.font.italic = 0
A.axes2D.xAxis.label.scaling = 0
A.axes2D.xAxis.tickMarks.visible = 1
A.axes2D.xAxis.tickMarks.majorMinimum = -20
A.axes2D.xAxis.tickMarks.majorMaximum = 20
A.axes2D.xAxis.tickMarks.minorSpacing = 0.1
A.axes2D.xAxis.tickMarks.majorSpacing = 0.2
A.axes2D.xAxis.grid = 1
A.axes2D.yAxis.title.visible = 0
A.axes2D.yAxis.title.font.font = A.axes2D.yAxis.title.font.Arial  # Arial, Courier, Times
A.axes2D.yAxis.title.font.scale = 2
A.axes2D.yAxis.title.font.useForegroundColor = 1
A.axes2D.yAxis.title.font.color = (0, 0, 0, 255)
A.axes2D.yAxis.title.font.bold = 1
A.axes2D.yAxis.title.font.italic = 0
A.axes2D.yAxis.title.userTitle = 1
A.axes2D.yAxis.title.userUnits = 1
A.axes2D.yAxis.title.title = "R"
A.axes2D.yAxis.title.units = "pc"
A.axes2D.yAxis.label.visible = 1
A.axes2D.yAxis.label.font.font = A.axes2D.yAxis.label.font.Arial  # Arial, Courier, Times
A.axes2D.yAxis.label.font.scale = 2
A.axes2D.yAxis.label.font.useForegroundColor = 1
A.axes2D.yAxis.label.font.color = (0, 0, 0, 255)
A.axes2D.yAxis.label.font.bold = 1
A.axes2D.yAxis.label.font.italic = 0
A.axes2D.yAxis.label.scaling = 0
A.axes2D.yAxis.tickMarks.visible = 1
A.axes2D.yAxis.tickMarks.majorMinimum = -20
A.axes2D.yAxis.tickMarks.majorMaximum = 20
A.axes2D.yAxis.tickMarks.minorSpacing = 0.1
A.axes2D.yAxis.tickMarks.majorSpacing = 0.2
A.axes2D.yAxis.grid = 1
A.userInfoFlag = 0
A.databaseInfoFlag = 0
A.databaseInfoFont.font = A.databaseInfoFont.Arial  # Arial, Courier, Times
A.databaseInfoFont.scale = 1
A.databaseInfoFont.useForegroundColor = 1
A.databaseInfoFont.color = (0, 0, 0, 255)
A.databaseInfoFont.bold = 0
A.databaseInfoFont.italic = 0
A.databaseInfoExpansionMode = A.File  # File, Directory, Full, Smart, SmartDirectory
A.databaseInfoTimeScale = 1.0
A.databaseInfoTimeOffset = 0
A.legendInfoFlag = 1
A.backgroundColor = (255, 255, 255, 255)
A.foregroundColor = (0, 0, 0, 255)
A.backgroundMode = A.Solid  # Solid, Gradient, Image, ImageSphere

SetAnnotationAttributes(A)


#####################################################################
##########  GET THE VIEW AND IMAGE RESOLUTION THAT WE WANT ##########
#####################################################################
DrawPlots()
ResizeWindow(1,1300,800)

sw = SaveWindowAttributes()
sw.fileName = "test"
sw.width = 600
sw.height= 800
sw.outputToCurrentDirectory = 0
sw.outputDirectory = "."
sw.family = 0
sw.format = sw.PNG # BMP, CURVE, JPEG, OBJ, PNG, POSTSCRIPT, POVRAY, PPM, RGB, STL, TIFF, ULTRA, VTK
sw.resConstraint = sw.NoConstraint

View2DAtts = View2DAttributes()
View2DAtts.windowCoords = ( -0.01, 1.01, -0.01, 1.35 )
View2DAtts.viewportCoords = (0.12, 0.98, 0.11, 0.9)
View2DAtts.fullFrameActivationMode = View2DAtts.Off  # On, Off, Auto
View2DAtts.fullFrameAutoThreshold = 100
View2DAtts.xScale = View2DAtts.LINEAR  # LINEAR, LOG
View2DAtts.yScale = View2DAtts.LINEAR  # LINEAR, LOG
SetView2D(View2DAtts)
#####################################################################


#####################################################################
##########  PLAY AROUND WITH LEGENDS TO GET WHAT WE WANT   ##########
#####################################################################
plotName = GetPlotList().GetPlots(0).plotName 
legend = GetAnnotationObject(plotName)
# See if we can scale the legend.
legend.xScale = 3.2
legend.yScale = 0.5
# the bounding box (draw=0 no, =1 yes)
legend.drawBoundingBox = 0
legend.boundingBoxColor = (200,200,200,230)
# Make it horizontal
legend.orientation = legend.HorizontalTop
# moving the legend
legend.managePosition = 0
legend.position = (0.12,0.99)
# text color
#InvertBackgroundColor()
#legend.useForegroundForTextColor = 0
#legend.textColor = (255, 0, 0, 255)
# number format
legend.numberFormat = "%1.1f"
# the font.
legend.fontFamily = legend.Arial
legend.fontBold = 1
legend.fontItalic = 0
legend.fontHeight = 0.07
# turning off the labels.
legend.drawLabels = 1
legend.drawMinMax = 0
legend.numTicks = 5
# turning off the title.
legend.drawTitle = 0



#####################################################################
# Add a time slider in the lower right corner
slider = CreateAnnotationObject("TimeSlider")
slider.height = 0.1
slider.width = 0.4
slider.text = "Time=\$time "
slider.position = (0.5, 0.12)
# Make the slider transparent, so that only the time shows.
slider.startColor = (0, 255, 255, 0)
slider.endColor = (255, 255, 255, 0)
#####################################################################


sw.fileName = "test_2.7.0"
SetSaveWindowAttributes(sw)
SaveWindow()





