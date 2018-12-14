<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - pjacobi_mpi4py.py - VisIt Bugs</title>
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
				
        <h2>pjacobi_mpi4py.py</h2>

<div class="attachments">
<p>Example simulation - 
   <span class="author">Brad Whitlock, 05/16/2012 01:44 pm</span></p>
<p><a href="/attachments/download/126/pjacobi_mpi4py.py">Download</a>   <span class="size">(14 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre># this code is largely inspired from Brad Whitlock's updateplots.py
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre># this code is similar in nature and algorithm to the F90 code contributed earlier
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre># see tools/DataManualExamples/Simulations/contrib
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre># this is a very first attempt to use some numpy arrays.
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre># A grid of size (M+2)x(M+2) is allocated.
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre># the working buffer is of size MxM
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>import sys, math
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>import numpy as sp
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>sys.path.append('&lt;pathtosimv2&gt;')
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>from simV2 import *
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>from mpi4py import MPI
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>class Simulation:
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>    def __init__(self):
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>        self.done = 0
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>        self.cycle = 0
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>        self.time = 0.
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>        self.runMode = VISIT_SIMMODE_RUNNING
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>        self.par_size = 1
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>        self.par_rank = 0
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>        self.savingFiles = 0
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>        self.saveCounter = 0
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>        self.M = 20 
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>        self.MP = self.M # to be redefined if parallel
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>        self.rmesh_dims = [self.M+2, self.M+2, 1]
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>        self.dx = 1.0/(self.rmesh_dims[0]-1)
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>        self.rmesh_ndims = 2
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>        self.commands = (&quot;halt&quot;, &quot;step&quot;, &quot;run&quot;, &quot;addplot&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>        self.v = sp.zeros([self.rmesh_dims[0],self.rmesh_dims[1]]) # includes 2 ghosts
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>        self.vnew = sp.zeros([self.M, self.M])
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>    def Initialize(self, simname, visitdir):
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>        VisItOpenTraceFile(&quot;trace.%d.txt&quot; % self.par_rank)
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>        VisItSetDirectory(visitdir)
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>        VisItSetupEnvironment()
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>            VisItInitializeSocketAndDumpSimFile(simname, 
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>                &quot;Heat Equation solver in Python&quot;, &quot;&lt;pathwheresimwasstarted&gt;&quot;,
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>                 None, None, None)
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>        self.rmesh_dims = [self.MP+2, self.M+2, 1]
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>        self.v = sp.zeros([self.rmesh_dims[0],self.rmesh_dims[1]]) # includes 2 ghosts
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>        self.vnew = sp.zeros([self.MP, self.M])
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>        self.set_initial_bc()
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>    def set_initial_bc(self):
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>        if self.par_size &gt; 1:
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>          if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>            for j in range(self.rmesh_dims[1]):
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>              self.v[0,j] = math.sin(math.pi*j*self.dx)
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>        else:
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>          #first (bottom) row
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>          for j in range(self.rmesh_dims[1]):
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>            self.v[0,j] = math.sin(math.pi*j*self.dx)
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>          #last (top) row
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>          self.v[-1,:] = self.v[0,:]* math.exp(-math.pi)
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>    def Finalize(self):
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>        VisItCloseTraceFile()
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>    def SimulateOneTimestep(self):
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>        self.cycle = self.cycle + 1
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>        self.time = self.time + 1.
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>        self.vnew = 0.25 * ( self.v[2:, 1:-1]  + # north neighbor
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>                             self.v[0:-2, 1:-1] + # south neighbor
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>                             self.v[1:-1, 2:] + # east neighbor
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>                             self.v[1:-1, :-2]) # west neighbor
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>        self.v[1:-1,1:-1] = self.vnew.copy()
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>        if self.par_size &gt; 1:
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>         
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>            if self.par_rank &lt; self.par_size-1:
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre>                self.comm.Irecv(self.v[-1,], source=self.par_rank+1, tag=11)
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre>            if self.par_rank &gt; 0:
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre>                self.comm.Irecv(self.v[0,], source=self.par_rank-1, tag=22)
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>          
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre>            if self.par_rank &gt; 0:
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>                self.comm.Send(self.v[1,], dest=self.par_rank-1, tag=11)
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>            if self.par_rank &lt; self.par_size-1:
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>                self.comm.Send(self.v[-2,], dest=self.par_rank+1, tag=22)
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>        VisItTimeStepChanged()
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre>        VisItUpdatePlots()
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>        if self.savingFiles:
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>            filename = &quot;Heat%04d.jpg&quot; % self.saveCounter
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre>            if VisItSaveWindow(filename, 800, 800, VISIT_IMAGEFORMAT_JPEG) == VISIT_OKAY:
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre>                self.saveCounter = self.saveCounter + 1
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>                if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre>                    print &quot;Saved&quot;,filename
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>            else:
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>                print &quot;The image could not be saved to&quot;,filename
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>    def ProcessVisItCommand(self):
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>        return (VisItProcessEngineCommand() == VISIT_OKAY)
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre>    def DoPrompt(self):
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>            sys.stdout.write(&quot;command&gt;&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre>            sys.stdout.flush()
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre>    def ProcessConsoleCommand(self):
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre>        cmd = self.GetInputFromConsole()
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre>        if cmd == &quot;quit&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre>            self.done = 1
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre>        elif cmd == &quot;halt&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre>            self.runMode = VISIT_SIMMODE_STOPPED
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre>        elif cmd == &quot;step&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre>            self.SimulateOneTimestep()
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>        elif cmd == &quot;run&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>            self.runMode = VISIT_SIMMODE_RUNNING
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>        elif cmd == &quot;saveon&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>            self.savingFiles = 1
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>        elif cmd == &quot;saveoff&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre>            self.savingFiles = 0
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre>        elif cmd == &quot;addplot&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre>            VisItExecuteCommand('AddPlot(&quot;Pseudocolor&quot;, &quot;temperature&quot;)\n')
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre>            VisItExecuteCommand('DrawPlots()\n')
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre>    def GetInputFromConsole(self):
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre>        return VisItReadConsole()
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre>        
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre>    def GetInputFromVisIt(self, blocking):
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre>        console = -1
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre>        return VisItDetectInputWithTimeout(blocking, 100000, console)
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>    def MainLoop(self):
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>        
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>        while self.done == 0:
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>            blocking = 1
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre>            if self.runMode == VISIT_SIMMODE_RUNNING:
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre>                blocking = 0
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre>            visitstate = self.GetInputFromVisIt(blocking)
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre>            if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre>               print &quot;State: &quot;, visitstate
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre>            if visitstate == 0:
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre>                self.SimulateOneTimestep()
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre>            elif visitstate == 1:
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre>                if VisItAttemptToCompleteConnection() == VISIT_OKAY:
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre>                    print &quot;VisIt connected&quot;
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>                    self.runMode = VISIT_SIMMODE_STOPPED
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>                    self.ConnectCallbacks()
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>                else:
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre>                    print &quot;VisIt did not connect&quot;
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>                    
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>            elif visitstate == 2:
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>                print &quot;ProcessVisIsCommand&quot;
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>                if not self.ProcessVisItCommand():
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>                    print &quot;Disconnect&quot;, self.par_rank
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>                    VisItDisconnect()
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>                    self.runMode = VISIT_SIMMODE_RUNNING
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre>            elif visitstate == 3:
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>                self.ProcessConsoleCommand()
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>            else:
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre>                print &quot;Error: &quot;, visitstate
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre>    def ConnectCallbacks(self):
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre>        VisItSetCommandCallback(self.ControlCommandCallback, 0)
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre>        VisItSetGetMetaData(self.GetMetaData, None)
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre>        VisItSetGetMesh(self.GetMesh, 0)
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre>        VisItSetGetVariable(self.GetVariable, 0)
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre>    def ControlCommandCallback(self, cmd, args, cbdata):
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre>        if cmd == &quot;halt&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L189"><a href="#L189">189</a></th><td class="line-code"><pre>            self.runMode = VISIT_SIMMODE_STOPPED
</pre></td></tr>


<tr><th class="line-num" id="L190"><a href="#L190">190</a></th><td class="line-code"><pre>        elif cmd == &quot;step&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L191"><a href="#L191">191</a></th><td class="line-code"><pre>            self.SimulateOneTimestep()
</pre></td></tr>


<tr><th class="line-num" id="L192"><a href="#L192">192</a></th><td class="line-code"><pre>        elif cmd == &quot;run&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L193"><a href="#L193">193</a></th><td class="line-code"><pre>            self.runMode = VISIT_SIMMODE_RUNNING
</pre></td></tr>


<tr><th class="line-num" id="L194"><a href="#L194">194</a></th><td class="line-code"><pre>        elif cmd == &quot;addplot&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L195"><a href="#L195">195</a></th><td class="line-code"><pre>            VisItExecuteCommand('AddPlot(&quot;Pseudocolor&quot;, &quot;temperature&quot;)\n')
</pre></td></tr>


<tr><th class="line-num" id="L196"><a href="#L196">196</a></th><td class="line-code"><pre>            VisItExecuteCommand('DrawPlots()\n')
</pre></td></tr>


<tr><th class="line-num" id="L197"><a href="#L197">197</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L198"><a href="#L198">198</a></th><td class="line-code"><pre>    def GetMetaData(self, cbdata):
</pre></td></tr>


<tr><th class="line-num" id="L199"><a href="#L199">199</a></th><td class="line-code"><pre>        md = VisIt_SimulationMetaData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L200"><a href="#L200">200</a></th><td class="line-code"><pre>        if md != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L201"><a href="#L201">201</a></th><td class="line-code"><pre>            VisIt_SimulationMetaData_setCycleTime(md, self.cycle, self.time)
</pre></td></tr>


<tr><th class="line-num" id="L202"><a href="#L202">202</a></th><td class="line-code"><pre>            # Add mesh metadata.
</pre></td></tr>


<tr><th class="line-num" id="L203"><a href="#L203">203</a></th><td class="line-code"><pre>            mmd = VisIt_MeshMetaData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L204"><a href="#L204">204</a></th><td class="line-code"><pre>            if mmd != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L205"><a href="#L205">205</a></th><td class="line-code"><pre>                # Set the mesh's properties.
</pre></td></tr>


<tr><th class="line-num" id="L206"><a href="#L206">206</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setName(mmd, &quot;mesh&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L207"><a href="#L207">207</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setMeshType(mmd, VISIT_MESHTYPE_RECTILINEAR)
</pre></td></tr>


<tr><th class="line-num" id="L208"><a href="#L208">208</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setTopologicalDimension(mmd, 2)
</pre></td></tr>


<tr><th class="line-num" id="L209"><a href="#L209">209</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setSpatialDimension(mmd, 2)
</pre></td></tr>


<tr><th class="line-num" id="L210"><a href="#L210">210</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setNumDomains(mmd, self.par_size)
</pre></td></tr>


<tr><th class="line-num" id="L211"><a href="#L211">211</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setDomainTitle(mmd, &quot;Domains&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L212"><a href="#L212">212</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setDomainPieceName(mmd, &quot;domain&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L213"><a href="#L213">213</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setNumGroups(mmd, 0)
</pre></td></tr>


<tr><th class="line-num" id="L214"><a href="#L214">214</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setXUnits(mmd, &quot;cm&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L215"><a href="#L215">215</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setYUnits(mmd, &quot;cm&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L216"><a href="#L216">216</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setXLabel(mmd, &quot;Width&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L217"><a href="#L217">217</a></th><td class="line-code"><pre>                VisIt_MeshMetaData_setYLabel(mmd, &quot;Height&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L218"><a href="#L218">218</a></th><td class="line-code"><pre>                VisIt_SimulationMetaData_addMesh(md, mmd)
</pre></td></tr>


<tr><th class="line-num" id="L219"><a href="#L219">219</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L220"><a href="#L220">220</a></th><td class="line-code"><pre>            # Add a variable.
</pre></td></tr>


<tr><th class="line-num" id="L221"><a href="#L221">221</a></th><td class="line-code"><pre>            vmd = VisIt_VariableMetaData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L222"><a href="#L222">222</a></th><td class="line-code"><pre>            if vmd != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L223"><a href="#L223">223</a></th><td class="line-code"><pre>                VisIt_VariableMetaData_setName(vmd, &quot;temperature&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L224"><a href="#L224">224</a></th><td class="line-code"><pre>                VisIt_VariableMetaData_setMeshName(vmd, &quot;mesh&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L225"><a href="#L225">225</a></th><td class="line-code"><pre>                VisIt_VariableMetaData_setType(vmd, VISIT_VARTYPE_SCALAR)
</pre></td></tr>


<tr><th class="line-num" id="L226"><a href="#L226">226</a></th><td class="line-code"><pre>                VisIt_VariableMetaData_setCentering(vmd, VISIT_VARCENTERING_NODE)
</pre></td></tr>


<tr><th class="line-num" id="L227"><a href="#L227">227</a></th><td class="line-code"><pre>                VisIt_SimulationMetaData_addVariable(md, vmd)
</pre></td></tr>


<tr><th class="line-num" id="L228"><a href="#L228">228</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L229"><a href="#L229">229</a></th><td class="line-code"><pre>            # Add some commands
</pre></td></tr>


<tr><th class="line-num" id="L230"><a href="#L230">230</a></th><td class="line-code"><pre>            for c in self.commands:
</pre></td></tr>


<tr><th class="line-num" id="L231"><a href="#L231">231</a></th><td class="line-code"><pre>                cmd = VisIt_CommandMetaData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L232"><a href="#L232">232</a></th><td class="line-code"><pre>                if cmd != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L233"><a href="#L233">233</a></th><td class="line-code"><pre>                    VisIt_CommandMetaData_setName(cmd, c)
</pre></td></tr>


<tr><th class="line-num" id="L234"><a href="#L234">234</a></th><td class="line-code"><pre>                    VisIt_SimulationMetaData_addGenericCommand(md, cmd)
</pre></td></tr>


<tr><th class="line-num" id="L235"><a href="#L235">235</a></th><td class="line-code"><pre>        return md
</pre></td></tr>


<tr><th class="line-num" id="L236"><a href="#L236">236</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L237"><a href="#L237">237</a></th><td class="line-code"><pre>    def GetMesh(self, domain, name, cbdata):
</pre></td></tr>


<tr><th class="line-num" id="L238"><a href="#L238">238</a></th><td class="line-code"><pre>        h = VISIT_INVALID_HANDLE
</pre></td></tr>


<tr><th class="line-num" id="L239"><a href="#L239">239</a></th><td class="line-code"><pre>        if name == &quot;mesh&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L240"><a href="#L240">240</a></th><td class="line-code"><pre>            h = VisIt_RectilinearMesh_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L241"><a href="#L241">241</a></th><td class="line-code"><pre>            if h != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L242"><a href="#L242">242</a></th><td class="line-code"><pre>                minRealIndex = [0,0,0]
</pre></td></tr>


<tr><th class="line-num" id="L243"><a href="#L243">243</a></th><td class="line-code"><pre>                maxRealIndex = [0,0,0]
</pre></td></tr>


<tr><th class="line-num" id="L244"><a href="#L244">244</a></th><td class="line-code"><pre>                maxRealIndex[0] = self.rmesh_dims[1]-1
</pre></td></tr>


<tr><th class="line-num" id="L245"><a href="#L245">245</a></th><td class="line-code"><pre>                if self.par_rank == (self.par_size-1):
</pre></td></tr>


<tr><th class="line-num" id="L246"><a href="#L246">246</a></th><td class="line-code"><pre>                  maxRealIndex[1] = self.rmesh_dims[0]-1
</pre></td></tr>


<tr><th class="line-num" id="L247"><a href="#L247">247</a></th><td class="line-code"><pre>                else:
</pre></td></tr>


<tr><th class="line-num" id="L248"><a href="#L248">248</a></th><td class="line-code"><pre>                  maxRealIndex[1] = self.rmesh_dims[0]-2
</pre></td></tr>


<tr><th class="line-num" id="L249"><a href="#L249">249</a></th><td class="line-code"><pre>                
</pre></td></tr>


<tr><th class="line-num" id="L250"><a href="#L250">250</a></th><td class="line-code"><pre>                maxRealIndex[2] = self.rmesh_dims[2]-1
</pre></td></tr>


<tr><th class="line-num" id="L251"><a href="#L251">251</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L252"><a href="#L252">252</a></th><td class="line-code"><pre>                rmesh_x = sp.linspace(0.0, 1.0, self.rmesh_dims[1])
</pre></td></tr>


<tr><th class="line-num" id="L253"><a href="#L253">253</a></th><td class="line-code"><pre>                rmesh_y = sp.linspace(self.par_rank*self.MP*self.dx, ((self.par_rank+1)*self.MP+1)*self.dx, self.rmesh_dims[0])
</pre></td></tr>


<tr><th class="line-num" id="L254"><a href="#L254">254</a></th><td class="line-code"><pre>                hx = VisIt_VariableData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L255"><a href="#L255">255</a></th><td class="line-code"><pre>                hy = VisIt_VariableData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L256"><a href="#L256">256</a></th><td class="line-code"><pre>                VisIt_VariableData_setDataD(hx, VISIT_OWNER_SIM, 1,
</pre></td></tr>


<tr><th class="line-num" id="L257"><a href="#L257">257</a></th><td class="line-code"><pre>                                            rmesh_x.size, rmesh_x.tolist())
</pre></td></tr>


<tr><th class="line-num" id="L258"><a href="#L258">258</a></th><td class="line-code"><pre>                VisIt_VariableData_setDataD(hy, VISIT_OWNER_SIM, 1,
</pre></td></tr>


<tr><th class="line-num" id="L259"><a href="#L259">259</a></th><td class="line-code"><pre>                                            rmesh_y.size, rmesh_y.tolist())
</pre></td></tr>


<tr><th class="line-num" id="L260"><a href="#L260">260</a></th><td class="line-code"><pre>                VisIt_RectilinearMesh_setCoordsXY(h, hx, hy)
</pre></td></tr>


<tr><th class="line-num" id="L261"><a href="#L261">261</a></th><td class="line-code"><pre>                VisIt_RectilinearMesh_setRealIndices(h, minRealIndex, maxRealIndex)
</pre></td></tr>


<tr><th class="line-num" id="L262"><a href="#L262">262</a></th><td class="line-code"><pre>        return h
</pre></td></tr>


<tr><th class="line-num" id="L263"><a href="#L263">263</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L264"><a href="#L264">264</a></th><td class="line-code"><pre>    def GetVariable(self, domain, name, cbdata):
</pre></td></tr>


<tr><th class="line-num" id="L265"><a href="#L265">265</a></th><td class="line-code"><pre>        h = VISIT_INVALID_HANDLE
</pre></td></tr>


<tr><th class="line-num" id="L266"><a href="#L266">266</a></th><td class="line-code"><pre>        if name == &quot;temperature&quot;:
</pre></td></tr>


<tr><th class="line-num" id="L267"><a href="#L267">267</a></th><td class="line-code"><pre>            nTuples = self.v.size
</pre></td></tr>


<tr><th class="line-num" id="L268"><a href="#L268">268</a></th><td class="line-code"><pre>            h = VisIt_VariableData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L269"><a href="#L269">269</a></th><td class="line-code"><pre>            VisIt_VariableData_setDataD(h, VISIT_OWNER_SIM, 1,
</pre></td></tr>


<tr><th class="line-num" id="L270"><a href="#L270">270</a></th><td class="line-code"><pre>                nTuples, self.v.flatten().tolist())
</pre></td></tr>


<tr><th class="line-num" id="L271"><a href="#L271">271</a></th><td class="line-code"><pre>        return h
</pre></td></tr>


<tr><th class="line-num" id="L272"><a href="#L272">272</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L273"><a href="#L273">273</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L274"><a href="#L274">274</a></th><td class="line-code"><pre>#*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L275"><a href="#L275">275</a></th><td class="line-code"><pre># Class: ParallelSimulation
</pre></td></tr>


<tr><th class="line-num" id="L276"><a href="#L276">276</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L277"><a href="#L277">277</a></th><td class="line-code"><pre># Purpose:
</pre></td></tr>


<tr><th class="line-num" id="L278"><a href="#L278">278</a></th><td class="line-code"><pre>#   This subclass of Simulation overrides some input handling methods and 
</pre></td></tr>


<tr><th class="line-num" id="L279"><a href="#L279">279</a></th><td class="line-code"><pre>#   provides a few extra callbacks to provide an MPI-parallel simulation.
</pre></td></tr>


<tr><th class="line-num" id="L280"><a href="#L280">280</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L281"><a href="#L281">281</a></th><td class="line-code"><pre># Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L282"><a href="#L282">282</a></th><td class="line-code"><pre># Date:       Fri Mar 18 14:24:17 PDT 2011
</pre></td></tr>


<tr><th class="line-num" id="L283"><a href="#L283">283</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L284"><a href="#L284">284</a></th><td class="line-code"><pre># Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L285"><a href="#L285">285</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L286"><a href="#L286">286</a></th><td class="line-code"><pre>#*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L287"><a href="#L287">287</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L288"><a href="#L288">288</a></th><td class="line-code"><pre>class ParallelSimulation(Simulation):
</pre></td></tr>


<tr><th class="line-num" id="L289"><a href="#L289">289</a></th><td class="line-code"><pre>    def __init__(self):
</pre></td></tr>


<tr><th class="line-num" id="L290"><a href="#L290">290</a></th><td class="line-code"><pre>        Simulation.__init__(self)
</pre></td></tr>


<tr><th class="line-num" id="L291"><a href="#L291">291</a></th><td class="line-code"><pre>        self.VISIT_COMMAND_PROCESS = 0
</pre></td></tr>


<tr><th class="line-num" id="L292"><a href="#L292">292</a></th><td class="line-code"><pre>        self.VISIT_COMMAND_SUCCESS = 1
</pre></td></tr>


<tr><th class="line-num" id="L293"><a href="#L293">293</a></th><td class="line-code"><pre>        self.VISIT_COMMAND_FAILURE = 2
</pre></td></tr>


<tr><th class="line-num" id="L294"><a href="#L294">294</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L295"><a href="#L295">295</a></th><td class="line-code"><pre>    # Override Initialize for parallel
</pre></td></tr>


<tr><th class="line-num" id="L296"><a href="#L296">296</a></th><td class="line-code"><pre>    def Initialize(self, simname, visitdir):
</pre></td></tr>


<tr><th class="line-num" id="L297"><a href="#L297">297</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L298"><a href="#L298">298</a></th><td class="line-code"><pre>        self.comm = MPI.COMM_WORLD
</pre></td></tr>


<tr><th class="line-num" id="L299"><a href="#L299">299</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L300"><a href="#L300">300</a></th><td class="line-code"><pre>        VisItSetBroadcastIntFunction(self.broadcast_int)
</pre></td></tr>


<tr><th class="line-num" id="L301"><a href="#L301">301</a></th><td class="line-code"><pre>        VisItSetBroadcastStringFunction(self.broadcast_string)
</pre></td></tr>


<tr><th class="line-num" id="L302"><a href="#L302">302</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L303"><a href="#L303">303</a></th><td class="line-code"><pre>        self.par_size = self.comm.Get_size()
</pre></td></tr>


<tr><th class="line-num" id="L304"><a href="#L304">304</a></th><td class="line-code"><pre>        self.par_rank = self.comm.Get_rank()
</pre></td></tr>


<tr><th class="line-num" id="L305"><a href="#L305">305</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L306"><a href="#L306">306</a></th><td class="line-code"><pre>        VisItSetParallel(self.par_size  &gt;1)
</pre></td></tr>


<tr><th class="line-num" id="L307"><a href="#L307">307</a></th><td class="line-code"><pre>        VisItSetParallelRank(self.par_rank)
</pre></td></tr>


<tr><th class="line-num" id="L308"><a href="#L308">308</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L309"><a href="#L309">309</a></th><td class="line-code"><pre>        self.par_size = self.comm.Get_size()
</pre></td></tr>


<tr><th class="line-num" id="L310"><a href="#L310">310</a></th><td class="line-code"><pre>        self.par_rank = self.comm.Get_rank()
</pre></td></tr>


<tr><th class="line-num" id="L311"><a href="#L311">311</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L312"><a href="#L312">312</a></th><td class="line-code"><pre>        self.MP = self.M / self.par_size
</pre></td></tr>


<tr><th class="line-num" id="L313"><a href="#L313">313</a></th><td class="line-code"><pre>        Simulation.Initialize(self, simname, visitdir)
</pre></td></tr>


<tr><th class="line-num" id="L314"><a href="#L314">314</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L315"><a href="#L315">315</a></th><td class="line-code"><pre>        
</pre></td></tr>


<tr><th class="line-num" id="L316"><a href="#L316">316</a></th><td class="line-code"><pre>        #print self.par_rank, self.v
</pre></td></tr>


<tr><th class="line-num" id="L317"><a href="#L317">317</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L318"><a href="#L318">318</a></th><td class="line-code"><pre>    def GetInputFromConsole(self):
</pre></td></tr>


<tr><th class="line-num" id="L319"><a href="#L319">319</a></th><td class="line-code"><pre>        cmd = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L320"><a href="#L320">320</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L321"><a href="#L321">321</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L322"><a href="#L322">322</a></th><td class="line-code"><pre>            cmd = VisItReadConsole()
</pre></td></tr>


<tr><th class="line-num" id="L323"><a href="#L323">323</a></th><td class="line-code"><pre>        else: 
</pre></td></tr>


<tr><th class="line-num" id="L324"><a href="#L324">324</a></th><td class="line-code"><pre>            cmd = None
</pre></td></tr>


<tr><th class="line-num" id="L325"><a href="#L325">325</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L326"><a href="#L326">326</a></th><td class="line-code"><pre>        cmd = self.comm.bcast(cmd)
</pre></td></tr>


<tr><th class="line-num" id="L327"><a href="#L327">327</a></th><td class="line-code"><pre>        return cmd
</pre></td></tr>


<tr><th class="line-num" id="L328"><a href="#L328">328</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L329"><a href="#L329">329</a></th><td class="line-code"><pre>    def GetInputFromVisIt(self, blocking):
</pre></td></tr>


<tr><th class="line-num" id="L330"><a href="#L330">330</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L331"><a href="#L331">331</a></th><td class="line-code"><pre>        s = 0
</pre></td></tr>


<tr><th class="line-num" id="L332"><a href="#L332">332</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L333"><a href="#L333">333</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L334"><a href="#L334">334</a></th><td class="line-code"><pre>            #console = sys.stdin.fileno()
</pre></td></tr>


<tr><th class="line-num" id="L335"><a href="#L335">335</a></th><td class="line-code"><pre>            console = -1
</pre></td></tr>


<tr><th class="line-num" id="L336"><a href="#L336">336</a></th><td class="line-code"><pre>            s = VisItDetectInputWithTimeout(blocking, 100000, console) #100000
</pre></td></tr>


<tr><th class="line-num" id="L337"><a href="#L337">337</a></th><td class="line-code"><pre>        else:
</pre></td></tr>


<tr><th class="line-num" id="L338"><a href="#L338">338</a></th><td class="line-code"><pre>            s = None
</pre></td></tr>


<tr><th class="line-num" id="L339"><a href="#L339">339</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L340"><a href="#L340">340</a></th><td class="line-code"><pre>        s = self.comm.bcast(s)
</pre></td></tr>


<tr><th class="line-num" id="L341"><a href="#L341">341</a></th><td class="line-code"><pre>        return s
</pre></td></tr>


<tr><th class="line-num" id="L342"><a href="#L342">342</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L343"><a href="#L343">343</a></th><td class="line-code"><pre>    def Finalize(self):
</pre></td></tr>


<tr><th class="line-num" id="L344"><a href="#L344">344</a></th><td class="line-code"><pre>        Simulation.Finalize(self)
</pre></td></tr>


<tr><th class="line-num" id="L345"><a href="#L345">345</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L346"><a href="#L346">346</a></th><td class="line-code"><pre>    def ConnectCallbacks(self):
</pre></td></tr>


<tr><th class="line-num" id="L347"><a href="#L347">347</a></th><td class="line-code"><pre>        Simulation.ConnectCallbacks(self)
</pre></td></tr>


<tr><th class="line-num" id="L348"><a href="#L348">348</a></th><td class="line-code"><pre>        VisItSetSlaveProcessCallback(self.slave_process_callback)
</pre></td></tr>


<tr><th class="line-num" id="L349"><a href="#L349">349</a></th><td class="line-code"><pre>        VisItSetGetDomainList(self.GetDomainList, 0)
</pre></td></tr>


<tr><th class="line-num" id="L350"><a href="#L350">350</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L351"><a href="#L351">351</a></th><td class="line-code"><pre>    def GetDomainList(self, name, cbdata):
</pre></td></tr>


<tr><th class="line-num" id="L352"><a href="#L352">352</a></th><td class="line-code"><pre>        h = VisIt_DomainList_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L353"><a href="#L353">353</a></th><td class="line-code"><pre>        if h != VISIT_INVALID_HANDLE:
</pre></td></tr>


<tr><th class="line-num" id="L354"><a href="#L354">354</a></th><td class="line-code"><pre>            hdl = VisIt_VariableData_alloc()
</pre></td></tr>


<tr><th class="line-num" id="L355"><a href="#L355">355</a></th><td class="line-code"><pre>            VisIt_VariableData_setDataI(hdl, VISIT_OWNER_VISIT, 1, 1, [self.par_rank])
</pre></td></tr>


<tr><th class="line-num" id="L356"><a href="#L356">356</a></th><td class="line-code"><pre>            VisIt_DomainList_setDomains(h, self.par_size, hdl)
</pre></td></tr>


<tr><th class="line-num" id="L357"><a href="#L357">357</a></th><td class="line-code"><pre>        return h
</pre></td></tr>


<tr><th class="line-num" id="L358"><a href="#L358">358</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L359"><a href="#L359">359</a></th><td class="line-code"><pre>    def broadcast_int(self, ival, sender):
</pre></td></tr>


<tr><th class="line-num" id="L360"><a href="#L360">360</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L361"><a href="#L361">361</a></th><td class="line-code"><pre>            ret = ival
</pre></td></tr>


<tr><th class="line-num" id="L362"><a href="#L362">362</a></th><td class="line-code"><pre>        else:
</pre></td></tr>


<tr><th class="line-num" id="L363"><a href="#L363">363</a></th><td class="line-code"><pre>            ret = None
</pre></td></tr>


<tr><th class="line-num" id="L364"><a href="#L364">364</a></th><td class="line-code"><pre>        
</pre></td></tr>


<tr><th class="line-num" id="L365"><a href="#L365">365</a></th><td class="line-code"><pre>        ret = self.comm.bcast(ret)
</pre></td></tr>


<tr><th class="line-num" id="L366"><a href="#L366">366</a></th><td class="line-code"><pre>        return ret
</pre></td></tr>


<tr><th class="line-num" id="L367"><a href="#L367">367</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L368"><a href="#L368">368</a></th><td class="line-code"><pre>    def broadcast_string(self, sval, slen, sender):
</pre></td></tr>


<tr><th class="line-num" id="L369"><a href="#L369">369</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L370"><a href="#L370">370</a></th><td class="line-code"><pre>            ret = sval
</pre></td></tr>


<tr><th class="line-num" id="L371"><a href="#L371">371</a></th><td class="line-code"><pre>        else:
</pre></td></tr>


<tr><th class="line-num" id="L372"><a href="#L372">372</a></th><td class="line-code"><pre>            ret = None
</pre></td></tr>


<tr><th class="line-num" id="L373"><a href="#L373">373</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L374"><a href="#L374">374</a></th><td class="line-code"><pre>        ret = self.comm.bcast(ret)
</pre></td></tr>


<tr><th class="line-num" id="L375"><a href="#L375">375</a></th><td class="line-code"><pre>        return ret
</pre></td></tr>


<tr><th class="line-num" id="L376"><a href="#L376">376</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L377"><a href="#L377">377</a></th><td class="line-code"><pre>    def slave_process_callback(self):
</pre></td></tr>


<tr><th class="line-num" id="L378"><a href="#L378">378</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L379"><a href="#L379">379</a></th><td class="line-code"><pre>        s = None
</pre></td></tr>


<tr><th class="line-num" id="L380"><a href="#L380">380</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L381"><a href="#L381">381</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L382"><a href="#L382">382</a></th><td class="line-code"><pre>            s = self.VISIT_COMMAND_PROCESS
</pre></td></tr>


<tr><th class="line-num" id="L383"><a href="#L383">383</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L384"><a href="#L384">384</a></th><td class="line-code"><pre>        self.comm.bcast(s)
</pre></td></tr>


<tr><th class="line-num" id="L385"><a href="#L385">385</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L386"><a href="#L386">386</a></th><td class="line-code"><pre>    def ProcessVisItCommand(self):
</pre></td></tr>


<tr><th class="line-num" id="L387"><a href="#L387">387</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L388"><a href="#L388">388</a></th><td class="line-code"><pre>        if self.par_rank == 0:
</pre></td></tr>


<tr><th class="line-num" id="L389"><a href="#L389">389</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L390"><a href="#L390">390</a></th><td class="line-code"><pre>            success = VisItProcessEngineCommand()
</pre></td></tr>


<tr><th class="line-num" id="L391"><a href="#L391">391</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L392"><a href="#L392">392</a></th><td class="line-code"><pre>            if success == VISIT_OKAY:
</pre></td></tr>


<tr><th class="line-num" id="L393"><a href="#L393">393</a></th><td class="line-code"><pre>                self.comm.bcast(self.VISIT_COMMAND_SUCCESS)
</pre></td></tr>


<tr><th class="line-num" id="L394"><a href="#L394">394</a></th><td class="line-code"><pre>                return 1
</pre></td></tr>


<tr><th class="line-num" id="L395"><a href="#L395">395</a></th><td class="line-code"><pre>            else:
</pre></td></tr>


<tr><th class="line-num" id="L396"><a href="#L396">396</a></th><td class="line-code"><pre>                self.comm.bcast(self.VISIT_COMMAND_FAILURE)
</pre></td></tr>


<tr><th class="line-num" id="L397"><a href="#L397">397</a></th><td class="line-code"><pre>                return 0
</pre></td></tr>


<tr><th class="line-num" id="L398"><a href="#L398">398</a></th><td class="line-code"><pre>        else:
</pre></td></tr>


<tr><th class="line-num" id="L399"><a href="#L399">399</a></th><td class="line-code"><pre>            while 1:
</pre></td></tr>


<tr><th class="line-num" id="L400"><a href="#L400">400</a></th><td class="line-code"><pre>                command = self.comm.bcast(None)
</pre></td></tr>


<tr><th class="line-num" id="L401"><a href="#L401">401</a></th><td class="line-code"><pre>                if command == self.VISIT_COMMAND_PROCESS:
</pre></td></tr>


<tr><th class="line-num" id="L402"><a href="#L402">402</a></th><td class="line-code"><pre>                    VisItProcessEngineCommand()
</pre></td></tr>


<tr><th class="line-num" id="L403"><a href="#L403">403</a></th><td class="line-code"><pre>                elif command == self.VISIT_COMMAND_SUCCESS:
</pre></td></tr>


<tr><th class="line-num" id="L404"><a href="#L404">404</a></th><td class="line-code"><pre>                    return 1
</pre></td></tr>


<tr><th class="line-num" id="L405"><a href="#L405">405</a></th><td class="line-code"><pre>                elif command == self.VISIT_COMMAND_FAILURE:
</pre></td></tr>


<tr><th class="line-num" id="L406"><a href="#L406">406</a></th><td class="line-code"><pre>                    return 0
</pre></td></tr>


<tr><th class="line-num" id="L407"><a href="#L407">407</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L408"><a href="#L408">408</a></th><td class="line-code"><pre>def main():
</pre></td></tr>


<tr><th class="line-num" id="L409"><a href="#L409">409</a></th><td class="line-code"><pre>    sim = ParallelSimulation()
</pre></td></tr>


<tr><th class="line-num" id="L410"><a href="#L410">410</a></th><td class="line-code"><pre>    sim.Initialize(&quot;heat_equation&quot;, &quot;&lt;pathotovisit&gt;&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L411"><a href="#L411">411</a></th><td class="line-code"><pre>    sim.MainLoop()
</pre></td></tr>


<tr><th class="line-num" id="L412"><a href="#L412">412</a></th><td class="line-code"><pre>    sim.Finalize()
</pre></td></tr>


<tr><th class="line-num" id="L413"><a href="#L413">413</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L414"><a href="#L414">414</a></th><td class="line-code"><pre>main()
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
