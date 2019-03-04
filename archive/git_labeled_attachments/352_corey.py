#
# Implement this for handling a pick event caused by the user.
#
def handle_pick(atts, userdata):
    print "We received a real user-caused pick event", atts, userdata

#
# This class lets get pick attributes routed to handle_pick so that
# changes to pickAtts not caused by the user picking are ignored.
#
class pickAttsResponder:
    def __init__(self, cb, cbdata):
        self.count = 0
        self.cb = cb
        self.cbdata = cbdata
    def reset(self, c):
        self.count = c
    def respond(self, atts):
        if self.count == 0:
            self.count = 0
            self.cb(atts, self.cbdata)
        else:
            self.count = self.count - 1

def When_PickAtts(atts, obj):
    obj.respond(atts)
def When_TimeSliderNextState(obj):
    obj.reset(2)
def When_TimeSliderPreviousState(obj):
    obj.reset(2)
def When_SetTimeSliderState(ts, obj):
    obj.reset(2)

paResponder = pickAttsResponder(handle_pick, 0)
RegisterCallback("PickAttributes",         When_PickAtts, paResponder)
RegisterCallback("TimeSliderNextStateRPC", When_TimeSliderNextState, paResponder)
RegisterCallback("TimeSliderPreviousStateRPC", When_TimeSliderPreviousState, paResponder)
RegisterCallback("SetTimeSliderStateRPC",  When_SetTimeSliderState, paResponder)

OpenDatabase("~/data/wave/wave.visit")
AddPlot("Pseudocolor","v")
DrawPlots()
#OpenGUI()
