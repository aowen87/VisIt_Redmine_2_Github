OpenDatabase("~/Development/data/silo_hdf5_test_data/bigsil.silo")
DefineScalarExpression("zid", "zoneid(mesh)")
DefineScalarExpression("radial", "recenter(dist)")
AddPlot("Pseudocolor", "zid")
DrawPlots()

AddOperator("Isosurface")
iso = IsosurfaceAttributes()
iso.contourNLevels = 3
iso.variable = "dist"
SetOperatorOptions(iso)
DrawPlots()

# The bug is after this.
ChangeActivePlotsVar("dist")
SaveWindow() # junky picture

# Make the right picture now.
CloseComputeEngine()
ClearWindow()
DrawPlots()
SaveWindow()
