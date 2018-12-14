<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - curve-bug.py - VisIt Bugs</title>
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
				
        <h2>curve-bug.py</h2>

<div class="attachments">
<p>Python script for the above bug - 
   <span class="author">Tom Fogal, 05/18/2011 03:19 pm</span></p>
<p><a href="/attachments/download/58/curve-bug.py">Download</a>   <span class="size">(274 Bytes)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre>OpenDatabase(&quot;../data/curve_test_data/curve.visit&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>AddPlot(&quot;Curve&quot;, &quot;parabolic&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>ra = RenderingAttributes()
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>ra.antialiasing = 0
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>ra.scalableActivationMode = ra.Always
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>SetRenderingAttributes(ra)
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>DrawPlots()
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>SetTimeSliderState(99)
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>Test(&quot;curvebug_01&quot;)
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>DeleteAllPlots()
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>Exit()
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
