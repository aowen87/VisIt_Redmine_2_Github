DeleteAllPlots()
OpenDatabase("/project/projectdirs/visit/data/MIR_ThreeSlice_Problem/phi_2lev.3d.hdf5")
AddPlot("Pseudocolor", "phi")

DrawPlots()
SaveWindow()
# Works

silr = SILRestriction()
mats = silr.SetsInCategory('materials')
silr.TurnOffAll()
silr.TurnOnSet(mats[0])
SetPlotSILRestriction(silr)
SaveWindow()
# Works

silr.TurnOffAll()
silr.TurnOnSet(mats[1])
SetPlotSILRestriction(silr)
SaveWindow()
# Works

AddOperator("ThreeSlice")
ThreeSliceAtts = ThreeSliceAttributes()
ThreeSliceAtts.x = 32
ThreeSliceAtts.y = 32
ThreeSliceAtts.z = 32
SetOperatorOptions(ThreeSliceAtts)
silr.TurnOnAll()
SetPlotSILRestriction(silr)
DrawPlots()
SaveWindow()
# Works

silr = SILRestriction()
mats = silr.SetsInCategory('materials')
silr.TurnOffAll()
silr.TurnOnSet(mats[0])
SetPlotSILRestriction(silr)
SaveWindow()
# Fails with:
#  VisIt: Error - Pseudocolor:  ()
#  viewer: No input was defined for this filter.

silr.TurnOffAll()
silr.TurnOnSet(mats[1])
SetPlotSILRestriction(silr)
DrawPlots()
SaveWindow()
# Fails with:
#  VisIt: Error - Pseudocolor:  ()
#  viewer: No input was defined for this filter.
