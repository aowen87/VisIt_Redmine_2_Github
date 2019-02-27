import subprocess, string

def SampleTop(pid):
    p = subprocess.Popen(["top", "-l", "1", "-pid", str(pid)], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    ret = p.communicate()[0]
    ret = string.split(ret, "\n")
    values = string.split(ret[-2], " ")
    ret = []
    for v in values:
        if v != "":
            ret = ret + [v]
    return ret

def Sample2Number(num):
    value = 0
    if num[-1] == "-" or num[-1] == "+":
        if num[-2] == "M":
           value = float(num[:-2])
    return value

def setupplots():
    OpenDatabase("~/data/wave/wave.visit")
    AddPlot("Pseudocolor", "pressure")
    AddOperator("Reflect")
    AddOperator("Reflect")
    AddOperator("Reflect")
    DrawPlots()

def main(pid, nloops):
    filename = "viewer" + str(pid) + ".curve"
    # Iterate over time and make a plot of VSIZE.
    f = open(filename, "wt")
    iteration = 0
    for i in range(nloops):
        for j in range(TimeSliderGetNStates()):
            SetTimeSliderState(j)
            samples = SampleTop(pid)
            f.write("%g %g\n" % (iteration, Sample2Number(samples[12])))
            f.flush()
            iteration = iteration + 1
    f.close()

setupplots()
#main(26065, 10)
