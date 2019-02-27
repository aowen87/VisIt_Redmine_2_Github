#!/usr/bin/python2.6
# This module provides a set of functions that will move the plot
# in filtermovie.py around.

import pdb
from math import cos, sin, pi

class MoverSettings:
  """MoverSettings

   Defines some settings that can be changed for the animation produced
   by Mover. See for details about the animation the documentation
   of Mover
      pause:
        If non-zero, the amount of time in seconds to pause the program
        between each successive animation step
        Default: 0
      save:
        If non-zero, each successive frame is exported using the currently
        stored SaveAttributes. If non-zero, it will override any
        non-zero value of 'pause'
        Default: 0
      xstart,ystart:
        The orientation of the plane when the animation starts:
          xstart = (+|-)1  x-axis is aligned vertically
          ystart = (+|-)1  y-axis is aligned vertically
        Only one of these can be non-zero and the only accepted
        values are plus and minus one.
        Default: xstart=0, ystart=1
      ph0_rotations:
        The number of quarter circle sections that the plane will rotate
        Default: 2 (which corresponds to turning it upside down once)
      ph0_steps:
        The number of animation steps to utilize to rotate
        the plane during phase 0.
        Default: 100
      ph0_direction:
        Rotation direction for phase 0. Either plus one (counter-clockwise)
        or minus one (clockwise)
        Default: +1
      angle:
        The angle in degrees with the XY-plane during the rotation
        Default: 20
      ph1_steps:
        The number of steps to take to perform phase 1 of the animation
        Default: 100
      ph2_rotations:
        Number of quarter segments to rotate during phase 2
        Default: 4
      ph2_steps:
        TOTAL number of animation steps to use for phase 2. An animation
        with ph2_rotations=2 and ph2_steps=300 will rotate twice as fast as
        one with ph2_rotations=1 and equal number of steps.
        Default: 300
      ph2_direction:
        Rotation direction for phase 2. Either plus one (counter-clockwise)
        or minus one (clockwise)
        Default: +1
      ph3_rotations:
        The number of quarter segments to rotate during phase 3
        Default: 8
      ph3_steps:
        TOTAL number of animation steps to use for phase 3. Note that
        if ph3_steps<noTimeSteps, some of the timesteps in the database
        will be skipped. When ph3_steps>noTimeSteps, the animation will
        play several rotation steps for one timestep from the database.
        In all cases, it will make sure that the timeslider and the rotation
        part end at the same time.
      ph3_direction:
        See ph2_direction
        Default: +1
        """
  def __init__(self, pause=0, save=0, xstart=0, ystart=1,
               ph0_rotations=2,ph0_steps=100, ph0_direction=1,
               angle=20, ph1_steps=100,
               ph2_rotations=4, ph2_steps=300, ph2_direction=1,
               ph3_rotations=8, ph3_steps=600, ph3_direction=1):

    self.pause = pause
    self.save = save
    self.xstart = xstart
    self.ystart = ystart
    self.ph0_rotations = ph0_rotations
    self.ph0_steps = ph0_steps
    self.ph0_direction = ph0_direction
    
    self.angle = angle
    self.ph1_steps = ph1_steps

    self.ph2_rotations = ph2_rotations
    self.ph2_steps = ph2_steps
    self.ph2_direction = ph2_direction
    
    self.ph3_rotations = ph3_rotations
    self.ph3_steps = ph3_steps
    self.ph3_direction = ph3_direction

  #
#

# pass the full VisIt module to the constructor, to prevent having
# to relaunch a fully equipped engine.
class Mover:
  """ This class performs an animation of some elevated 2D dataset in three phases:

    phase 0: start with a look along the z-axis, watching the dataset as a picture.
             Then rotate this picture in 2D over a given number of quarter circle
             sections
    phase 1: Rotate the picture into a 3D view by moving the camera towards the bottom side of the
             bounding box
    phase 2: rotate the 3D view MoverSettings.ph2_rotations times around the z-axis in
             MoverSettings.ph2_direction direction
             """
  from time import sleep

  def __init__(self, visitmod, settings):
    """__init__(self, visitmodule mod, MoverSettings settings)

     Set up an object by passing along the full visit module
     (preventing having to do a separate visit.Launch() in
     this sourcefile) and a MoverSettings instance with the
     values to be used to execute the animation. """
    self.vmod = visitmod
    self.c0 = self.first_cpoint(settings)
    self.settings = settings
  #

  def phase0(self):
    """phase0(self)

    Display the image data and rotate it a view quarter
    circle sections. Settings:
      xstart, ystart, pause, ph0_rotations, ph0_steps, ph0_direction"""
    # start with the zero view
    self.vmod.SetView3D(self.c0)
    if self.settings.save:
        self.vmod.SaveWindow()
      #

    # copy the start position
    c1 = self.copy_cpoint(self.c0)

    # step angle
    dangle = (pi / 2) * self.settings.ph0_rotations / self.settings.ph0_steps

    for s in xrange(1, self.settings.ph0_steps+1):
      self.rotate(self.c0, c1, self.settings.ph0_direction*s*dangle)
      if self.settings.pause and not self.settings.save:
        self.sleep(self.settings.pause)
      #

      self.vmod.SetView3D(c1)

      if self.settings.save:
        self.vmod.SaveWindow()
      #
    #for
  #phase0

  def phase1(self):
    """phase1(self)

    Rotate the data into a 3D view and set the perspective switch on.
    Settings used to control the animation:
      angle, xstart, ystart, pause, ph1_steps"""
    # obtain end position of previous phase:
    c1 = self.vmod.GetView3D()
    # obtain a View3DAnnotation object from c0 and set the perspective flag
    c2 = self.copy_cpoint(c1)

    # step in angle in radian
    delta_angle = (pi / 180) * (90 - self.settings.angle) / self.settings.ph1_steps
    # final angle in radian
    final_angle = pi * self.settings.angle / 180

    # do the loop:
    for s in xrange(self.settings.ph1_steps - 1, -1, -1):
      sina = sin(final_angle + s * delta_angle)
      cosa = cos(final_angle + s * delta_angle)
      
      c2.viewUp = (sina * c1.viewUp[0], sina * c1.viewUp[1], cosa)
      c2.viewNormal = (-cosa*c1.viewUp[0], -cosa*c1.viewUp[1], sina)

      if self.settings.pause and not self.settings.save:
        self.sleep(self.settings.pause)
      #
      self.vmod.SetView3D(c2)

      if self.settings.save:
        self.vmod.SaveWindow()
      #
    #
  #phase1

  def phase2(self):
    """phase2(self)

    Rotate the 3D view around the z-axis.
    Settings used to control the animation:
      angle, pause, ph2_rotations, ph2_steps, ph2_direction"""
    if not (self.settings.ph2_direction==1 or self.settings.ph2_direction==-1):
      raise SystemExit("ph2_direction must be either +1 or -1")
    
    # store the current view
    c1 = self.vmod.GetView3D()
    # create a new object to store the new settings
    c2 = self.copy_cpoint(c1)

    # calculate the stepsize:
    delta_angle = (pi / 2) * self.settings.ph2_rotations / self.settings.ph2_steps
    for s in xrange(1, self.settings.ph2_steps+1):
      self.rotate(c1, c2, self.settings.ph2_direction * s * delta_angle)

      if self.settings.pause and not self.settings.save:
        self.sleep(self.settings.pause)
      #
      self.vmod.SetView3D(c2)

      if self.settings.save:
        self.vmod.SaveWindow()
      #
    #
  #phase2
  
  def phase3(self):
    """phase3(self)

    Add a timeslider and move through the
    timelist, while keeping rotating.
    Settings used to control this part:
     angle, pause, ph3_rotations, ph3_steps, ph3_direction"""
    if not (self.settings.ph3_direction==1 or self.settings.ph3_direction==-1):
      raise SystemExit("ph3_direction must be either +1 or -1")
    
    # add the timeslider:
    self.time_slider = self.vmod.CreateAnnotationObject("TimeSlider")
    self.time_slider.text = "sigma=$time"

    # remember the current view:
    c1 = self.vmod.GetView3D()
    # create a new object to store new settings:
    c2 = self.copy_cpoint(c1)
    
    # number of timeslides:
    maxTimeSlide = self.vmod.TimeSliderGetNStates()-1
    steps_per_timeslide = float(self.settings.ph3_steps) / maxTimeSlide

    # angle stepsize:
    delta_angle = (pi / 2) * self.settings.ph3_rotations / self.settings.ph3_steps
    # current time slide:
    current_timeslide = 0
    for s in xrange(1, self.settings.ph3_steps+1):
      self.rotate(c1, c2, s*delta_angle)

      if float(s) / steps_per_timeslide > (current_timeslide+1):
        current_timeslide = int(float(s) / steps_per_timeslide)
        self.vmod.TimeSliderSetState(current_timeslide)
      #

      if self.settings.pause and not self.settings.save:
        self.sleep(self.settings.pause)
      #

      self.vmod.SetView3D(c2)

      if self.settings.save:
        self.vmod.SaveWindow()
      #
    #for
  #phase3
    
  def animate(self):
    """animate(self):

     Call the separate animation phases one by one:
       phase1()
       phase2()
       phase3()"""
    self.phase0()
    #self.phase1()
    #self.phase2()
    #self.phase3()

  #

  def save(self):
    """bool save(self)

    Return the current value for the MoverSettings.save option"""
    return self.settings.save
  #
  
  ## Private interface ##
  def rotate(self, cp_from, cp_to, angle):
    """rotate(self, cpoint cp0, cpoint cp1, float angle)

     Rotate the 3D View Attributes in 'cp0' and rotate
     it along the z-axis over an angle of 'angle' radians.
     Store the new settings in 'cp1'"""
    cp_to.viewNormal = self.rot(cp_from.viewNormal, angle)
    cp_to.viewUp = self.rot(cp_from.viewUp, angle)
  #

  def rot(self, tup_from, angle):
    """tupel rot(self, tupel c0, angle)

     Rotate the coordinate stored in 'c0' over 'angle'
     radians and return the result in a new tupel"""
    return (tup_from[0] * cos(angle) + tup_from[1] * sin(angle),
            -tup_from[0] * sin(angle) + tup_from[1] * cos(angle),
            tup_from[2])
  #
  
  def copy_cpoint(self, cpoint):
    """cpoint copy_cpoint(self, cpoint)

     Return a View3DAttributes() object with
     the same values as 'cpoint'"""
    new = self.vmod.View3DAttributes()
    new.viewNormal = cpoint.viewNormal
    new.focus = cpoint.focus
    new.viewUp = cpoint.viewUp
    new.viewAngle = cpoint.viewAngle
    new.parallelScale = cpoint.parallelScale
    new.nearPlane = cpoint.nearPlane
    new.farPlane = cpoint.farPlane
    new.imagePan = cpoint.imagePan
    new.imageZoom = cpoint.imageZoom
    new.perspective = cpoint.perspective
    new.eyeAngle = cpoint.eyeAngle
    new.centerOfRotationSet = cpoint.centerOfRotationSet
    new.centerOfRotation = cpoint.centerOfRotation
    return new
  #
  
  def first_cpoint(self, settings):
    """first_cpoint(self, MoverSettings settings)

     Do some basic tests on the sanity of the passed
     settings and return the first controlpoint"""
    # Do some simple tests on the sanity of the passed settings:
    if (settings.xstart and settings.ystart):
      raise SystemExit("xstart and ystart can't be both nonzero")
    #
    if not (settings.xstart or settings.ystart):
      raise SystemExit("either xstart or ystart must be nonzero (plus one or minus one)")
    #
    if settings.angle < -90 or settings.angle >= 90:
      raise SystemExit("the angle must be in the range [-90,90)")
    #
    c0 = self.vmod.View3DAttributes()
    c0.focus = (156, 156, 156)
    c0.viewNormal = (0, 0, 1)
    if settings.xstart:
      if settings.xstart==1 or settings.xstart==-1:
        c0.SetViewUp(settings.xstart, 0, 0)
      else:
        raise SystemExit("xstart must be either plus one or minus one")
    else:
      if settings.ystart==1 or settings.ystart==-1:
        c0.SetViewUp(0, settings.ystart, 0)
      else:
        raise SystemExit("ystart must be either plus one or minus one")
    #
    c0.viewAngle = 30
    c0.parallelScale = 270.2
    c0.nearPlane = -540.4
    c0.farPlane = 540.4
    c0.imagePan = (0, 0)
    c0.perspective = True
    c0.eyeAngle = 2
    c0.centerOfRotationSet = False
    return c0
  #
  
#
  
if __name__ == "__main__":
  print MoverSettings.__doc__

#
