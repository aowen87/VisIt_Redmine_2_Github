OpenDatabase("../data/curve_test_data/curve.visit")
AddPlot("Curve", "parabolic")
ra = RenderingAttributes()
ra.antialiasing = 0
ra.scalableActivationMode = ra.Always
SetRenderingAttributes(ra)
DrawPlots()
SetTimeSliderState(99)
Test("curvebug_01")

DeleteAllPlots()
Exit()
