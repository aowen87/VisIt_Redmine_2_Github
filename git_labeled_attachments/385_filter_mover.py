<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - filter_mover.py - VisIt Bugs</title>
<meta name="description" content="Redmine" />
<meta name="keywords" content="issue,bug,tracker" />
<link href="/stylesheets/application.css?1267352889" media="all" rel="stylesheet" type="text/css" />
<script src="/javascripts/prototype.js?1267352889" type="text/javascript"></script>
<script src="/javascripts/effects.js?1267352889" type="text/javascript"></script>
<script src="/javascripts/dragdrop.js?1267352889" type="text/javascript"></script>
<script src="/javascripts/controls.js?1267352889" type="text/javascript"></script>
<script src="/javascripts/application.js?1267352889" type="text/javascript"></script>
<link href="/stylesheets/jstoolbar.css?1267352889" media="screen" rel="stylesheet" type="text/css" />
<!--[if IE]>
    <style type="text/css">
      * html body{ width: expression( document.documentElement.clientWidth < 900 ? '900px' : '100%' ); }
      body {behavior: url(/stylesheets/csshover.htc?1267352889);}
    </style>
<![endif]-->

<!-- page specific tags -->
    <link href="/stylesheets/scm.css?1267352889" media="screen" rel="stylesheet" type="text/css" /></head>
<body>
<div id="wrapper">
<div id="top-menu">
    <div id="account">
        <ul><li><a href="/login" class="login">Sign in</a></li>
<li><a href="/account/register" class="register">Register</a></li></ul>    </div>
    
    <ul><li><a href="/" class="home">Home</a></li>
<li><a href="/projects" class="projects">Projects</a></li>
<li><a href="http://www.redmine.org/guide" class="help">Help</a></li></ul></div>
      
<div id="header">
    <div id="quick-search">
        <form action="/search/index/visit" method="get">
        
        <a href="/search/index/visit" accesskey="4">Search</a>:
        <input accesskey="f" class="small" id="q" name="q" size="20" type="text" />
        </form>
        
    </div>
    
    <h1>VisIt</h1>
    
    <div id="main-menu">
        <ul><li><a href="/projects/visit" class="overview">Overview</a></li>
<li><a href="/projects/visit/activity" class="activity">Activity</a></li>
<li><a href="/projects/visit/roadmap" class="roadmap">Roadmap</a></li>
<li><a href="/projects/visit/issues" class="issues">Issues</a></li></ul>
    </div>
</div>

<div class="nosidebar" id="main">
    <div id="sidebar">        
        
        
    </div>
    
    <div id="content">
				
        <h2>filter_mover.py</h2>

<div class="attachments">
<p>This module defines the Mover class, which performs the actual animation - 
   <span class="author">Jakob van Bethlehem, 11/10/2010 09:28 am</span></p>
<p><a href="/attachments/download/25/filter_mover.py">Download</a>   <span class="size">(12.1 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre>#!/usr/bin/python2.6
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre># This module provides a set of functions that will move the plot
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre># in filtermovie.py around.
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>import pdb
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>from math import cos, sin, pi
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>class MoverSettings:
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>  &quot;&quot;&quot;MoverSettings
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>   Defines some settings that can be changed for the animation produced
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>   by Mover. See for details about the animation the documentation
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>   of Mover
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>      pause:
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>        If non-zero, the amount of time in seconds to pause the program
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>        between each successive animation step
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>        Default: 0
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>      save:
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>        If non-zero, each successive frame is exported using the currently
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>        stored SaveAttributes. If non-zero, it will override any
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>        non-zero value of 'pause'
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>        Default: 0
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>      xstart,ystart:
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>        The orientation of the plane when the animation starts:
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>          xstart = (+|-)1  x-axis is aligned vertically
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>          ystart = (+|-)1  y-axis is aligned vertically
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>        Only one of these can be non-zero and the only accepted
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>        values are plus and minus one.
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>        Default: xstart=0, ystart=1
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>      ph0_rotations:
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>        The number of quarter circle sections that the plane will rotate
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>        Default: 2 (which corresponds to turning it upside down once)
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>      ph0_steps:
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>        The number of animation steps to utilize to rotate
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>        the plane during phase 0.
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>        Default: 100
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>      ph0_direction:
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>        Rotation direction for phase 0. Either plus one (counter-clockwise)
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>        or minus one (clockwise)
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>        Default: +1
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>      angle:
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>        The angle in degrees with the XY-plane during the rotation
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>        Default: 20
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>      ph1_steps:
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>        The number of steps to take to perform phase 1 of the animation
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>        Default: 100
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>      ph2_rotations:
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>        Number of quarter segments to rotate during phase 2
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>        Default: 4
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>      ph2_steps:
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>        TOTAL number of animation steps to use for phase 2. An animation
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>        with ph2_rotations=2 and ph2_steps=300 will rotate twice as fast as
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>        one with ph2_rotations=1 and equal number of steps.
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>        Default: 300
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>      ph2_direction:
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>        Rotation direction for phase 2. Either plus one (counter-clockwise)
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>        or minus one (clockwise)
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>        Default: +1
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>      ph3_rotations:
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>        The number of quarter segments to rotate during phase 3
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>        Default: 8
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>      ph3_steps:
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>        TOTAL number of animation steps to use for phase 3. Note that
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>        if ph3_steps&lt;noTimeSteps, some of the timesteps in the database
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>        will be skipped. When ph3_steps&gt;noTimeSteps, the animation will
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>        play several rotation steps for one timestep from the database.
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>        In all cases, it will make sure that the timeslider and the rotation
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre>        part end at the same time.
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>      ph3_direction:
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>        See ph2_direction
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>        Default: +1
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>        &quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>  def __init__(self, pause=0, save=0, xstart=0, ystart=1,
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>               ph0_rotations=2,ph0_steps=100, ph0_direction=1,
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>               angle=20, ph1_steps=100,
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>               ph2_rotations=4, ph2_steps=300, ph2_direction=1,
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>               ph3_rotations=8, ph3_steps=600, ph3_direction=1):
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>    self.pause = pause
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>    self.save = save
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>    self.xstart = xstart
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>    self.ystart = ystart
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>    self.ph0_rotations = ph0_rotations
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>    self.ph0_steps = ph0_steps
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre>    self.ph0_direction = ph0_direction
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre>    self.angle = angle
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre>    self.ph1_steps = ph1_steps
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre>    self.ph2_rotations = ph2_rotations
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>    self.ph2_steps = ph2_steps
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>    self.ph2_direction = ph2_direction
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>    self.ph3_rotations = ph3_rotations
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre>    self.ph3_steps = ph3_steps
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>    self.ph3_direction = ph3_direction
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre># pass the full VisIt module to the constructor, to prevent having
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre># to relaunch a fully equipped engine.
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>class Mover:
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre>  &quot;&quot;&quot; This class performs an animation of some elevated 2D dataset in three phases:
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>    phase 0: start with a look along the z-axis, watching the dataset as a picture.
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>             Then rotate this picture in 2D over a given number of quarter circle
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>             sections
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>    phase 1: Rotate the picture into a 3D view by moving the camera towards the bottom side of the
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>             bounding box
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre>    phase 2: rotate the 3D view MoverSettings.ph2_rotations times around the z-axis in
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>             MoverSettings.ph2_direction direction
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>             &quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre>  from time import sleep
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre>  def __init__(self, visitmod, settings):
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre>    &quot;&quot;&quot;__init__(self, visitmodule mod, MoverSettings settings)
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre>     Set up an object by passing along the full visit module
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre>     (preventing having to do a separate visit.Launch() in
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre>     this sourcefile) and a MoverSettings instance with the
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre>     values to be used to execute the animation. &quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre>    self.vmod = visitmod
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre>    self.c0 = self.first_cpoint(settings)
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre>    self.settings = settings
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>  def phase0(self):
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>    &quot;&quot;&quot;phase0(self)
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre>    Display the image data and rotate it a view quarter
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre>    circle sections. Settings:
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre>      xstart, ystart, pause, ph0_rotations, ph0_steps, ph0_direction&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre>    # start with the zero view
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre>    self.vmod.SetView3D(self.c0)
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre>    if self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre>        self.vmod.SaveWindow()
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre>    # copy the start position
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre>    c1 = self.copy_cpoint(self.c0)
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>    # step angle
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>    dangle = (pi / 2) * self.settings.ph0_rotations / self.settings.ph0_steps
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>    for s in xrange(1, self.settings.ph0_steps+1):
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>      self.rotate(self.c0, c1, self.settings.ph0_direction*s*dangle)
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre>      if self.settings.pause and not self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre>        self.sleep(self.settings.pause)
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre>      self.vmod.SetView3D(c1)
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre>      if self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre>        self.vmod.SaveWindow()
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre>    #for
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre>  #phase0
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre>  def phase1(self):
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre>    &quot;&quot;&quot;phase1(self)
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre>    Rotate the data into a 3D view and set the perspective switch on.
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>    Settings used to control the animation:
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>      angle, xstart, ystart, pause, ph1_steps&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre>    # obtain end position of previous phase:
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>    c1 = self.vmod.GetView3D()
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>    # obtain a View3DAnnotation object from c0 and set the perspective flag
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>    c2 = self.copy_cpoint(c1)
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>    # step in angle in radian
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>    delta_angle = (pi / 180) * (90 - self.settings.angle) / self.settings.ph1_steps
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>    # final angle in radian
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre>    final_angle = pi * self.settings.angle / 180
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>    # do the loop:
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre>    for s in xrange(self.settings.ph1_steps - 1, -1, -1):
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre>      sina = sin(final_angle + s * delta_angle)
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre>      cosa = cos(final_angle + s * delta_angle)
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre>      
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre>      c2.viewUp = (sina * c1.viewUp[0], sina * c1.viewUp[1], cosa)
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre>      c2.viewNormal = (-cosa*c1.viewUp[0], -cosa*c1.viewUp[1], sina)
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre>      if self.settings.pause and not self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre>        self.sleep(self.settings.pause)
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre>      self.vmod.SetView3D(c2)
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L189"><a href="#L189">189</a></th><td class="line-code"><pre>      if self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L190"><a href="#L190">190</a></th><td class="line-code"><pre>        self.vmod.SaveWindow()
</pre></td></tr>


<tr><th class="line-num" id="L191"><a href="#L191">191</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L192"><a href="#L192">192</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L193"><a href="#L193">193</a></th><td class="line-code"><pre>  #phase1
</pre></td></tr>


<tr><th class="line-num" id="L194"><a href="#L194">194</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L195"><a href="#L195">195</a></th><td class="line-code"><pre>  def phase2(self):
</pre></td></tr>


<tr><th class="line-num" id="L196"><a href="#L196">196</a></th><td class="line-code"><pre>    &quot;&quot;&quot;phase2(self)
</pre></td></tr>


<tr><th class="line-num" id="L197"><a href="#L197">197</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L198"><a href="#L198">198</a></th><td class="line-code"><pre>    Rotate the 3D view around the z-axis.
</pre></td></tr>


<tr><th class="line-num" id="L199"><a href="#L199">199</a></th><td class="line-code"><pre>    Settings used to control the animation:
</pre></td></tr>


<tr><th class="line-num" id="L200"><a href="#L200">200</a></th><td class="line-code"><pre>      angle, pause, ph2_rotations, ph2_steps, ph2_direction&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L201"><a href="#L201">201</a></th><td class="line-code"><pre>    if not (self.settings.ph2_direction==1 or self.settings.ph2_direction==-1):
</pre></td></tr>


<tr><th class="line-num" id="L202"><a href="#L202">202</a></th><td class="line-code"><pre>      raise SystemExit(&quot;ph2_direction must be either +1 or -1&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L203"><a href="#L203">203</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L204"><a href="#L204">204</a></th><td class="line-code"><pre>    # store the current view
</pre></td></tr>


<tr><th class="line-num" id="L205"><a href="#L205">205</a></th><td class="line-code"><pre>    c1 = self.vmod.GetView3D()
</pre></td></tr>


<tr><th class="line-num" id="L206"><a href="#L206">206</a></th><td class="line-code"><pre>    # create a new object to store the new settings
</pre></td></tr>


<tr><th class="line-num" id="L207"><a href="#L207">207</a></th><td class="line-code"><pre>    c2 = self.copy_cpoint(c1)
</pre></td></tr>


<tr><th class="line-num" id="L208"><a href="#L208">208</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L209"><a href="#L209">209</a></th><td class="line-code"><pre>    # calculate the stepsize:
</pre></td></tr>


<tr><th class="line-num" id="L210"><a href="#L210">210</a></th><td class="line-code"><pre>    delta_angle = (pi / 2) * self.settings.ph2_rotations / self.settings.ph2_steps
</pre></td></tr>


<tr><th class="line-num" id="L211"><a href="#L211">211</a></th><td class="line-code"><pre>    for s in xrange(1, self.settings.ph2_steps+1):
</pre></td></tr>


<tr><th class="line-num" id="L212"><a href="#L212">212</a></th><td class="line-code"><pre>      self.rotate(c1, c2, self.settings.ph2_direction * s * delta_angle)
</pre></td></tr>


<tr><th class="line-num" id="L213"><a href="#L213">213</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L214"><a href="#L214">214</a></th><td class="line-code"><pre>      if self.settings.pause and not self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L215"><a href="#L215">215</a></th><td class="line-code"><pre>        self.sleep(self.settings.pause)
</pre></td></tr>


<tr><th class="line-num" id="L216"><a href="#L216">216</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L217"><a href="#L217">217</a></th><td class="line-code"><pre>      self.vmod.SetView3D(c2)
</pre></td></tr>


<tr><th class="line-num" id="L218"><a href="#L218">218</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L219"><a href="#L219">219</a></th><td class="line-code"><pre>      if self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L220"><a href="#L220">220</a></th><td class="line-code"><pre>        self.vmod.SaveWindow()
</pre></td></tr>


<tr><th class="line-num" id="L221"><a href="#L221">221</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L222"><a href="#L222">222</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L223"><a href="#L223">223</a></th><td class="line-code"><pre>  #phase2
</pre></td></tr>


<tr><th class="line-num" id="L224"><a href="#L224">224</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L225"><a href="#L225">225</a></th><td class="line-code"><pre>  def phase3(self):
</pre></td></tr>


<tr><th class="line-num" id="L226"><a href="#L226">226</a></th><td class="line-code"><pre>    &quot;&quot;&quot;phase3(self)
</pre></td></tr>


<tr><th class="line-num" id="L227"><a href="#L227">227</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L228"><a href="#L228">228</a></th><td class="line-code"><pre>    Add a timeslider and move through the
</pre></td></tr>


<tr><th class="line-num" id="L229"><a href="#L229">229</a></th><td class="line-code"><pre>    timelist, while keeping rotating.
</pre></td></tr>


<tr><th class="line-num" id="L230"><a href="#L230">230</a></th><td class="line-code"><pre>    Settings used to control this part:
</pre></td></tr>


<tr><th class="line-num" id="L231"><a href="#L231">231</a></th><td class="line-code"><pre>     angle, pause, ph3_rotations, ph3_steps, ph3_direction&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L232"><a href="#L232">232</a></th><td class="line-code"><pre>    if not (self.settings.ph3_direction==1 or self.settings.ph3_direction==-1):
</pre></td></tr>


<tr><th class="line-num" id="L233"><a href="#L233">233</a></th><td class="line-code"><pre>      raise SystemExit(&quot;ph3_direction must be either +1 or -1&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L234"><a href="#L234">234</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L235"><a href="#L235">235</a></th><td class="line-code"><pre>    # add the timeslider:
</pre></td></tr>


<tr><th class="line-num" id="L236"><a href="#L236">236</a></th><td class="line-code"><pre>    self.time_slider = self.vmod.CreateAnnotationObject(&quot;TimeSlider&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L237"><a href="#L237">237</a></th><td class="line-code"><pre>    self.time_slider.text = &quot;sigma=$time&quot;
</pre></td></tr>


<tr><th class="line-num" id="L238"><a href="#L238">238</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L239"><a href="#L239">239</a></th><td class="line-code"><pre>    # remember the current view:
</pre></td></tr>


<tr><th class="line-num" id="L240"><a href="#L240">240</a></th><td class="line-code"><pre>    c1 = self.vmod.GetView3D()
</pre></td></tr>


<tr><th class="line-num" id="L241"><a href="#L241">241</a></th><td class="line-code"><pre>    # create a new object to store new settings:
</pre></td></tr>


<tr><th class="line-num" id="L242"><a href="#L242">242</a></th><td class="line-code"><pre>    c2 = self.copy_cpoint(c1)
</pre></td></tr>


<tr><th class="line-num" id="L243"><a href="#L243">243</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L244"><a href="#L244">244</a></th><td class="line-code"><pre>    # number of timeslides:
</pre></td></tr>


<tr><th class="line-num" id="L245"><a href="#L245">245</a></th><td class="line-code"><pre>    maxTimeSlide = self.vmod.TimeSliderGetNStates()-1
</pre></td></tr>


<tr><th class="line-num" id="L246"><a href="#L246">246</a></th><td class="line-code"><pre>    steps_per_timeslide = float(self.settings.ph3_steps) / maxTimeSlide
</pre></td></tr>


<tr><th class="line-num" id="L247"><a href="#L247">247</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L248"><a href="#L248">248</a></th><td class="line-code"><pre>    # angle stepsize:
</pre></td></tr>


<tr><th class="line-num" id="L249"><a href="#L249">249</a></th><td class="line-code"><pre>    delta_angle = (pi / 2) * self.settings.ph3_rotations / self.settings.ph3_steps
</pre></td></tr>


<tr><th class="line-num" id="L250"><a href="#L250">250</a></th><td class="line-code"><pre>    # current time slide:
</pre></td></tr>


<tr><th class="line-num" id="L251"><a href="#L251">251</a></th><td class="line-code"><pre>    current_timeslide = 0
</pre></td></tr>


<tr><th class="line-num" id="L252"><a href="#L252">252</a></th><td class="line-code"><pre>    for s in xrange(1, self.settings.ph3_steps+1):
</pre></td></tr>


<tr><th class="line-num" id="L253"><a href="#L253">253</a></th><td class="line-code"><pre>      self.rotate(c1, c2, s*delta_angle)
</pre></td></tr>


<tr><th class="line-num" id="L254"><a href="#L254">254</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L255"><a href="#L255">255</a></th><td class="line-code"><pre>      if float(s) / steps_per_timeslide &gt; (current_timeslide+1):
</pre></td></tr>


<tr><th class="line-num" id="L256"><a href="#L256">256</a></th><td class="line-code"><pre>        current_timeslide = int(float(s) / steps_per_timeslide)
</pre></td></tr>


<tr><th class="line-num" id="L257"><a href="#L257">257</a></th><td class="line-code"><pre>        self.vmod.TimeSliderSetState(current_timeslide)
</pre></td></tr>


<tr><th class="line-num" id="L258"><a href="#L258">258</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L259"><a href="#L259">259</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L260"><a href="#L260">260</a></th><td class="line-code"><pre>      if self.settings.pause and not self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L261"><a href="#L261">261</a></th><td class="line-code"><pre>        self.sleep(self.settings.pause)
</pre></td></tr>


<tr><th class="line-num" id="L262"><a href="#L262">262</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L263"><a href="#L263">263</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L264"><a href="#L264">264</a></th><td class="line-code"><pre>      self.vmod.SetView3D(c2)
</pre></td></tr>


<tr><th class="line-num" id="L265"><a href="#L265">265</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L266"><a href="#L266">266</a></th><td class="line-code"><pre>      if self.settings.save:
</pre></td></tr>


<tr><th class="line-num" id="L267"><a href="#L267">267</a></th><td class="line-code"><pre>        self.vmod.SaveWindow()
</pre></td></tr>


<tr><th class="line-num" id="L268"><a href="#L268">268</a></th><td class="line-code"><pre>      #
</pre></td></tr>


<tr><th class="line-num" id="L269"><a href="#L269">269</a></th><td class="line-code"><pre>    #for
</pre></td></tr>


<tr><th class="line-num" id="L270"><a href="#L270">270</a></th><td class="line-code"><pre>  #phase3
</pre></td></tr>


<tr><th class="line-num" id="L271"><a href="#L271">271</a></th><td class="line-code"><pre>    
</pre></td></tr>


<tr><th class="line-num" id="L272"><a href="#L272">272</a></th><td class="line-code"><pre>  def animate(self):
</pre></td></tr>


<tr><th class="line-num" id="L273"><a href="#L273">273</a></th><td class="line-code"><pre>    &quot;&quot;&quot;animate(self):
</pre></td></tr>


<tr><th class="line-num" id="L274"><a href="#L274">274</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L275"><a href="#L275">275</a></th><td class="line-code"><pre>     Call the separate animation phases one by one:
</pre></td></tr>


<tr><th class="line-num" id="L276"><a href="#L276">276</a></th><td class="line-code"><pre>       phase1()
</pre></td></tr>


<tr><th class="line-num" id="L277"><a href="#L277">277</a></th><td class="line-code"><pre>       phase2()
</pre></td></tr>


<tr><th class="line-num" id="L278"><a href="#L278">278</a></th><td class="line-code"><pre>       phase3()&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L279"><a href="#L279">279</a></th><td class="line-code"><pre>    self.phase0()
</pre></td></tr>


<tr><th class="line-num" id="L280"><a href="#L280">280</a></th><td class="line-code"><pre>    #self.phase1()
</pre></td></tr>


<tr><th class="line-num" id="L281"><a href="#L281">281</a></th><td class="line-code"><pre>    #self.phase2()
</pre></td></tr>


<tr><th class="line-num" id="L282"><a href="#L282">282</a></th><td class="line-code"><pre>    #self.phase3()
</pre></td></tr>


<tr><th class="line-num" id="L283"><a href="#L283">283</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L284"><a href="#L284">284</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L285"><a href="#L285">285</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L286"><a href="#L286">286</a></th><td class="line-code"><pre>  def save(self):
</pre></td></tr>


<tr><th class="line-num" id="L287"><a href="#L287">287</a></th><td class="line-code"><pre>    &quot;&quot;&quot;bool save(self)
</pre></td></tr>


<tr><th class="line-num" id="L288"><a href="#L288">288</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L289"><a href="#L289">289</a></th><td class="line-code"><pre>    Return the current value for the MoverSettings.save option&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L290"><a href="#L290">290</a></th><td class="line-code"><pre>    return self.settings.save
</pre></td></tr>


<tr><th class="line-num" id="L291"><a href="#L291">291</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L292"><a href="#L292">292</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L293"><a href="#L293">293</a></th><td class="line-code"><pre>  ## Private interface ##
</pre></td></tr>


<tr><th class="line-num" id="L294"><a href="#L294">294</a></th><td class="line-code"><pre>  def rotate(self, cp_from, cp_to, angle):
</pre></td></tr>


<tr><th class="line-num" id="L295"><a href="#L295">295</a></th><td class="line-code"><pre>    &quot;&quot;&quot;rotate(self, cpoint cp0, cpoint cp1, float angle)
</pre></td></tr>


<tr><th class="line-num" id="L296"><a href="#L296">296</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L297"><a href="#L297">297</a></th><td class="line-code"><pre>     Rotate the 3D View Attributes in 'cp0' and rotate
</pre></td></tr>


<tr><th class="line-num" id="L298"><a href="#L298">298</a></th><td class="line-code"><pre>     it along the z-axis over an angle of 'angle' radians.
</pre></td></tr>


<tr><th class="line-num" id="L299"><a href="#L299">299</a></th><td class="line-code"><pre>     Store the new settings in 'cp1'&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L300"><a href="#L300">300</a></th><td class="line-code"><pre>    cp_to.viewNormal = self.rot(cp_from.viewNormal, angle)
</pre></td></tr>


<tr><th class="line-num" id="L301"><a href="#L301">301</a></th><td class="line-code"><pre>    cp_to.viewUp = self.rot(cp_from.viewUp, angle)
</pre></td></tr>


<tr><th class="line-num" id="L302"><a href="#L302">302</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L303"><a href="#L303">303</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L304"><a href="#L304">304</a></th><td class="line-code"><pre>  def rot(self, tup_from, angle):
</pre></td></tr>


<tr><th class="line-num" id="L305"><a href="#L305">305</a></th><td class="line-code"><pre>    &quot;&quot;&quot;tupel rot(self, tupel c0, angle)
</pre></td></tr>


<tr><th class="line-num" id="L306"><a href="#L306">306</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L307"><a href="#L307">307</a></th><td class="line-code"><pre>     Rotate the coordinate stored in 'c0' over 'angle'
</pre></td></tr>


<tr><th class="line-num" id="L308"><a href="#L308">308</a></th><td class="line-code"><pre>     radians and return the result in a new tupel&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L309"><a href="#L309">309</a></th><td class="line-code"><pre>    return (tup_from[0] * cos(angle) + tup_from[1] * sin(angle),
</pre></td></tr>


<tr><th class="line-num" id="L310"><a href="#L310">310</a></th><td class="line-code"><pre>            -tup_from[0] * sin(angle) + tup_from[1] * cos(angle),
</pre></td></tr>


<tr><th class="line-num" id="L311"><a href="#L311">311</a></th><td class="line-code"><pre>            tup_from[2])
</pre></td></tr>


<tr><th class="line-num" id="L312"><a href="#L312">312</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L313"><a href="#L313">313</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L314"><a href="#L314">314</a></th><td class="line-code"><pre>  def copy_cpoint(self, cpoint):
</pre></td></tr>


<tr><th class="line-num" id="L315"><a href="#L315">315</a></th><td class="line-code"><pre>    &quot;&quot;&quot;cpoint copy_cpoint(self, cpoint)
</pre></td></tr>


<tr><th class="line-num" id="L316"><a href="#L316">316</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L317"><a href="#L317">317</a></th><td class="line-code"><pre>     Return a View3DAttributes() object with
</pre></td></tr>


<tr><th class="line-num" id="L318"><a href="#L318">318</a></th><td class="line-code"><pre>     the same values as 'cpoint'&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L319"><a href="#L319">319</a></th><td class="line-code"><pre>    new = self.vmod.View3DAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L320"><a href="#L320">320</a></th><td class="line-code"><pre>    new.viewNormal = cpoint.viewNormal
</pre></td></tr>


<tr><th class="line-num" id="L321"><a href="#L321">321</a></th><td class="line-code"><pre>    new.focus = cpoint.focus
</pre></td></tr>


<tr><th class="line-num" id="L322"><a href="#L322">322</a></th><td class="line-code"><pre>    new.viewUp = cpoint.viewUp
</pre></td></tr>


<tr><th class="line-num" id="L323"><a href="#L323">323</a></th><td class="line-code"><pre>    new.viewAngle = cpoint.viewAngle
</pre></td></tr>


<tr><th class="line-num" id="L324"><a href="#L324">324</a></th><td class="line-code"><pre>    new.parallelScale = cpoint.parallelScale
</pre></td></tr>


<tr><th class="line-num" id="L325"><a href="#L325">325</a></th><td class="line-code"><pre>    new.nearPlane = cpoint.nearPlane
</pre></td></tr>


<tr><th class="line-num" id="L326"><a href="#L326">326</a></th><td class="line-code"><pre>    new.farPlane = cpoint.farPlane
</pre></td></tr>


<tr><th class="line-num" id="L327"><a href="#L327">327</a></th><td class="line-code"><pre>    new.imagePan = cpoint.imagePan
</pre></td></tr>


<tr><th class="line-num" id="L328"><a href="#L328">328</a></th><td class="line-code"><pre>    new.imageZoom = cpoint.imageZoom
</pre></td></tr>


<tr><th class="line-num" id="L329"><a href="#L329">329</a></th><td class="line-code"><pre>    new.perspective = cpoint.perspective
</pre></td></tr>


<tr><th class="line-num" id="L330"><a href="#L330">330</a></th><td class="line-code"><pre>    new.eyeAngle = cpoint.eyeAngle
</pre></td></tr>


<tr><th class="line-num" id="L331"><a href="#L331">331</a></th><td class="line-code"><pre>    new.centerOfRotationSet = cpoint.centerOfRotationSet
</pre></td></tr>


<tr><th class="line-num" id="L332"><a href="#L332">332</a></th><td class="line-code"><pre>    new.centerOfRotation = cpoint.centerOfRotation
</pre></td></tr>


<tr><th class="line-num" id="L333"><a href="#L333">333</a></th><td class="line-code"><pre>    return new
</pre></td></tr>


<tr><th class="line-num" id="L334"><a href="#L334">334</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L335"><a href="#L335">335</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L336"><a href="#L336">336</a></th><td class="line-code"><pre>  def first_cpoint(self, settings):
</pre></td></tr>


<tr><th class="line-num" id="L337"><a href="#L337">337</a></th><td class="line-code"><pre>    &quot;&quot;&quot;first_cpoint(self, MoverSettings settings)
</pre></td></tr>


<tr><th class="line-num" id="L338"><a href="#L338">338</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L339"><a href="#L339">339</a></th><td class="line-code"><pre>     Do some basic tests on the sanity of the passed
</pre></td></tr>


<tr><th class="line-num" id="L340"><a href="#L340">340</a></th><td class="line-code"><pre>     settings and return the first controlpoint&quot;&quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L341"><a href="#L341">341</a></th><td class="line-code"><pre>    # Do some simple tests on the sanity of the passed settings:
</pre></td></tr>


<tr><th class="line-num" id="L342"><a href="#L342">342</a></th><td class="line-code"><pre>    if (settings.xstart and settings.ystart):
</pre></td></tr>


<tr><th class="line-num" id="L343"><a href="#L343">343</a></th><td class="line-code"><pre>      raise SystemExit(&quot;xstart and ystart can't be both nonzero&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L344"><a href="#L344">344</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L345"><a href="#L345">345</a></th><td class="line-code"><pre>    if not (settings.xstart or settings.ystart):
</pre></td></tr>


<tr><th class="line-num" id="L346"><a href="#L346">346</a></th><td class="line-code"><pre>      raise SystemExit(&quot;either xstart or ystart must be nonzero (plus one or minus one)&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L347"><a href="#L347">347</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L348"><a href="#L348">348</a></th><td class="line-code"><pre>    if settings.angle &lt; -90 or settings.angle &gt;= 90:
</pre></td></tr>


<tr><th class="line-num" id="L349"><a href="#L349">349</a></th><td class="line-code"><pre>      raise SystemExit(&quot;the angle must be in the range [-90,90)&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L350"><a href="#L350">350</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L351"><a href="#L351">351</a></th><td class="line-code"><pre>    c0 = self.vmod.View3DAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L352"><a href="#L352">352</a></th><td class="line-code"><pre>    c0.focus = (156, 156, 156)
</pre></td></tr>


<tr><th class="line-num" id="L353"><a href="#L353">353</a></th><td class="line-code"><pre>    c0.viewNormal = (0, 0, 1)
</pre></td></tr>


<tr><th class="line-num" id="L354"><a href="#L354">354</a></th><td class="line-code"><pre>    if settings.xstart:
</pre></td></tr>


<tr><th class="line-num" id="L355"><a href="#L355">355</a></th><td class="line-code"><pre>      if settings.xstart==1 or settings.xstart==-1:
</pre></td></tr>


<tr><th class="line-num" id="L356"><a href="#L356">356</a></th><td class="line-code"><pre>        c0.SetViewUp(settings.xstart, 0, 0)
</pre></td></tr>


<tr><th class="line-num" id="L357"><a href="#L357">357</a></th><td class="line-code"><pre>      else:
</pre></td></tr>


<tr><th class="line-num" id="L358"><a href="#L358">358</a></th><td class="line-code"><pre>        raise SystemExit(&quot;xstart must be either plus one or minus one&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L359"><a href="#L359">359</a></th><td class="line-code"><pre>    else:
</pre></td></tr>


<tr><th class="line-num" id="L360"><a href="#L360">360</a></th><td class="line-code"><pre>      if settings.ystart==1 or settings.ystart==-1:
</pre></td></tr>


<tr><th class="line-num" id="L361"><a href="#L361">361</a></th><td class="line-code"><pre>        c0.SetViewUp(0, settings.ystart, 0)
</pre></td></tr>


<tr><th class="line-num" id="L362"><a href="#L362">362</a></th><td class="line-code"><pre>      else:
</pre></td></tr>


<tr><th class="line-num" id="L363"><a href="#L363">363</a></th><td class="line-code"><pre>        raise SystemExit(&quot;ystart must be either plus one or minus one&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L364"><a href="#L364">364</a></th><td class="line-code"><pre>    #
</pre></td></tr>


<tr><th class="line-num" id="L365"><a href="#L365">365</a></th><td class="line-code"><pre>    c0.viewAngle = 30
</pre></td></tr>


<tr><th class="line-num" id="L366"><a href="#L366">366</a></th><td class="line-code"><pre>    c0.parallelScale = 270.2
</pre></td></tr>


<tr><th class="line-num" id="L367"><a href="#L367">367</a></th><td class="line-code"><pre>    c0.nearPlane = -540.4
</pre></td></tr>


<tr><th class="line-num" id="L368"><a href="#L368">368</a></th><td class="line-code"><pre>    c0.farPlane = 540.4
</pre></td></tr>


<tr><th class="line-num" id="L369"><a href="#L369">369</a></th><td class="line-code"><pre>    c0.imagePan = (0, 0)
</pre></td></tr>


<tr><th class="line-num" id="L370"><a href="#L370">370</a></th><td class="line-code"><pre>    c0.perspective = True
</pre></td></tr>


<tr><th class="line-num" id="L371"><a href="#L371">371</a></th><td class="line-code"><pre>    c0.eyeAngle = 2
</pre></td></tr>


<tr><th class="line-num" id="L372"><a href="#L372">372</a></th><td class="line-code"><pre>    c0.centerOfRotationSet = False
</pre></td></tr>


<tr><th class="line-num" id="L373"><a href="#L373">373</a></th><td class="line-code"><pre>    return c0
</pre></td></tr>


<tr><th class="line-num" id="L374"><a href="#L374">374</a></th><td class="line-code"><pre>  #
</pre></td></tr>


<tr><th class="line-num" id="L375"><a href="#L375">375</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L376"><a href="#L376">376</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L377"><a href="#L377">377</a></th><td class="line-code"><pre>  
</pre></td></tr>


<tr><th class="line-num" id="L378"><a href="#L378">378</a></th><td class="line-code"><pre>if __name__ == &quot;__main__&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L379"><a href="#L379">379</a></th><td class="line-code"><pre>  print MoverSettings.__doc__
</pre></td></tr>


<tr><th class="line-num" id="L380"><a href="#L380">380</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L381"><a href="#L381">381</a></th><td class="line-code"><pre>#
</pre></td></tr>


</tbody>
</table>
</div>





        
				<div style="clear:both;"></div>
    </div>
</div>

<div id="ajax-indicator" style="display:none;"><span>Loading...</span></div>
	
<div id="footer">
    Powered by <a href="http://www.redmine.org/">Redmine</a> &copy; 2006-2010 Jean-Philippe Lang
</div>
</div>

</body>
</html>
