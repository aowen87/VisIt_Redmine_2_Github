<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - bug.py - VisIt Bugs</title>
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
				
        <h2>bug.py</h2>

<div class="attachments">
<p>
   <span class="author">Brad Whitlock, 06/11/2014 04:56 pm</span></p>
<p><a href="/attachments/download/270/bug.py">Download</a>   <span class="size">(518 Bytes)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre>OpenDatabase(&quot;~/Development/data/silo_hdf5_test_data/bigsil.silo&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>DefineScalarExpression(&quot;zid&quot;, &quot;zoneid(mesh)&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>DefineScalarExpression(&quot;radial&quot;, &quot;recenter(dist)&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>AddPlot(&quot;Pseudocolor&quot;, &quot;zid&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>DrawPlots()
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>AddOperator(&quot;Isosurface&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>iso = IsosurfaceAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>iso.contourNLevels = 3
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>iso.variable = &quot;dist&quot;
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>SetOperatorOptions(iso)
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>DrawPlots()
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre># The bug is after this.
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>ChangeActivePlotsVar(&quot;dist&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>SaveWindow() # junky picture
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre># Make the right picture now.
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>CloseComputeEngine()
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>ClearWindow()
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>DrawPlots()
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>SaveWindow()
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
