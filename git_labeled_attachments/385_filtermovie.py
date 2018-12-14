<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - filtermovie.py - VisIt Bugs</title>
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
				
        <h2>filtermovie.py</h2>

<div class="attachments">
<p>The main script to control the animation - 
   <span class="author">Jakob van Bethlehem, 11/10/2010 09:28 am</span></p>
<p><a href="/attachments/download/24/filtermovie.py">Download</a>   <span class="size">(2.3 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre>#!/usr/bin/python2.6
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>#from filter_mover import *
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>import visit
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>from filter_mover import *
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>export_images = True
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>runningSelf = True
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>if sys.argv[0][-3:] == 'cli' or sys.argv[0] == '-':
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>  runningSelf = False
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>if runningSelf:
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>  if export_images:
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>    visit.AddArgument('-nowin')
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>  #  
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>  visit.Launch()
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>#
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>print &quot;**\n** filtermovie.py: running VisIt&quot;, visit.Version(),&quot;\n**&quot;
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>visit.OpenDatabase(&quot;2d_filter.visit&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>visit.AddPlot(&quot;Pseudocolor&quot;, &quot;filtered_image&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>pa = visit.PseudocolorAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>pa.centering = pa.Nodal
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>pa.minFlag = True
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>pa.min = -0.7
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>pa.maxFlag = True
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>pa.max = 0.7
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>visit.SetPlotOptions(pa)
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>visit.AddOperator(&quot;Elevate&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>ea = visit.ElevateAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>ea.useXYLimits = 1
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>ea.minFlag = True
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>ea.min = -0.7
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>ea.maxFlag = True
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>ea.max = 0.7
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>visit.SetOperatorOptions(ea)
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>## Set global Annotations:
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>annot_attr = visit.GetAnnotationAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>annot_attr.axes3D.triadFlag = False
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>annot_attr.axes3D.axesType = annot_attr.axes3D.StaticTriad
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>annot_attr.axes3D.xAxis.title.userTitle = True
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>annot_attr.axes3D.xAxis.title.title = &quot;X&quot;
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>annot_attr.axes3D.xAxis.title.font.scale = 1.5
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>annot_attr.axes3D.yAxis.title.userTitle = True
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>annot_attr.axes3D.yAxis.title.title = &quot;Y&quot;
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>annot_attr.axes3D.yAxis.title.font.scale = 1.5
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>annot_attr.axes3D.zAxis.title.userTitle = True
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>annot_attr.axes3D.zAxis.title.title = &quot;image * gauss&quot;
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>annot_attr.axes3D.zAxis.title.font.scale = 1.5
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>annot_attr.axes3D.zAxis.tickMarks.visible = False
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>annot_attr.axes3D.zAxis.label.visible = False
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>annot_attr.userInfoFlag = False
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>annot_attr.databaseInfoFlag = False
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>visit.SetAnnotationAttributes(annot_attr)
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>## Set plot Annotations:
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>p = visit.GetAnnotationObjectNames()[0]
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>psc_ann = visit.GetAnnotationObject(p)
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre>psc_ann.drawTitle = False
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>psc_ann.managePosition = False
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>psc_ann.position = (0.05, 0.98)
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>psc_ann.orientation = psc_ann.HorizontalTop
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>## SaveWindow attributes
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>swa = visit.SaveWindowAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>#swa.outputToCurrentDirectory = False
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>#swa.outputDirectory = &quot;2d_filter_frames&quot;
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>#swa.format = swa.JPEG
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>#swa.quality = 100
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>#visit.SetSaveWindowAttributes(swa)
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>## Set properties for the animation:
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>animation_settings = MoverSettings()
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>animation_settings.save = export_images
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>animation_settings.ph0_steps = 30
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre>controller = Mover(visit, animation_settings)
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre># start the plotting:
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre>visit.DrawPlots()
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre># Perform the animation:
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>controller.animate()
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>if not controller.save():
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>  raw_input(&quot;**\n** Press Enter to finish\n**&quot;)
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
