<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - visit_movie_script.sh - VisIt Bugs</title>
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
				
        <h2>visit_movie_script.sh</h2>

<div class="attachments">
<p>Allens' parallel movie making script - 
   <span class="author">Mark Miller, 10/22/2014 03:23 pm</span></p>
<p><a href="/attachments/download/288/visit_movie_script.sh">Download</a>   <span class="size">(11.9 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre>#!/bin/csh
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>if ($#argv &lt; 5) then
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>    echo &quot;Missing movie name and/or number of frames to generate ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>    echo &quot;Usage: $0 &lt;movie name&gt; &lt;start frame&gt; &lt;end frame&gt; &lt;frames per batch&gt; &lt;session file&gt;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>    echo &quot;       [-concurrent] or [-shotgun (to be deparcated)]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>    echo &quot;       [-v version of VisIt to execute]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>    echo &quot;       [-l launchMethod] [-queue &lt;queue&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>    echo &quot;       [-geometry &lt;width&gt;x&lt;height&gt;] [-format &lt;image format&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>    echo &quot;       [-nn &lt;Number of nodes&gt;] [-npn &lt;Number of processors per node&gt;] [-time &lt;Maximum job run time&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>    echo &quot;       [-bank &lt;Bank from which to draw resources&gt;] [-partition &lt;Partition to utilize&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>    exit
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>set movieName = $1
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>set startFrame = $2
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>set endFrame = $3
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>set framesPerBatch = $4
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>set sessionFile = $5
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre># Check for the session file to exist
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>if (! -e $sessionFile) then
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>    echo &quot;The session file, $sessionFile does not exist ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>    exit
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre># Check for the movie directory to exist
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>set movieRoot = $movieName:h
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>if ($movieRoot != $movieName) then
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>    if (! -e $movieRoot) then
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>        echo &quot;The directory $movieRoot does not exist ... creating $movieRoot&quot;
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>        mkdir -p $movieRoot
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>        if (! -e $movieRoot) then
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>            echo &quot;The directory $movieRoot could not be created ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>            exit
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>        endif
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre># Check for visit to exist
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>set visit = `which visit`
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>if (&quot;$visit:t&quot; != &quot;visit&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>    if (${?VISITHOME}) then
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>        set visit = $VISITHOME/bin/visit
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>	if (! -e $visit) then
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>	    echo &quot;Found the VISITHOME environment variable but can not find the visit executable ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>	    exit
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>        endif
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>        if (${?UUFSCELL}) then
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>	    set visit = &quot;/uufs/$UUFSCELL/sys/pkg/VisIt/Install/gcc/bin/visit&quot;
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>	    if (! -e $visit) then
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>		echo &quot;Can not find the visit executable ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>		exit
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>	    endif
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>	else
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>            echo &quot;Can not find VISITHOME or the visit executable ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>	    exit
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>        endif
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre># Process the the optional arguments to find whether running
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre># sequientially or concurrently.
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>set concurrent = &quot;false&quot;
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>set i = 6
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>set j = 7
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>while ($i &lt;= $#argv)
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>    if (X${argv[$i]} =~ X-c* || X${argv[$i]} =~ X-s*) then
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>       set concurrent = true
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>       break
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>    @ i = $i + 1
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>    @ j = $j + 1
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>end
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre># Parse the session file and locate the Machine Profiles. If they exist
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre># parse the format, height, and width.
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre>set hostmane = `/bin/hostname | sed -e 's/[1-9]*//g'`
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre>#sed -e '1,/&quot;hostNickname&quot; type=&quot;string&quot;&gt;ash/d' pal_session | sed -n '/\&lt;LaunchProfile\&gt;/,/\&lt;\&lt;parallel\&gt;/{/\&lt;LaunchProfile\&gt;/{h;d};H;/\&lt;\&lt;parallel\&gt;/{x;p}}'
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>set version = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>if ($concurrent == false) then
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre>    set queue = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>    set launchMethod = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre>    set launchArgs = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>    set nNodes = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>    set nProcsPerNode = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>    set time = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre>    set bank = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre>    set partition = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>else
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre>    set launchMethodSet = `grep '&quot;launchMethodSetSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>    if (&quot;$launchMethodSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>	set launchMethod = `grep '&quot;launchMethod&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>	set launchMethod = qsub/mpirun
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre>    set queue = $launchMethod:h
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>    set launchMethod = $launchMethod:t
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre>    set launchArgsSet = `grep '&quot;launchArgsSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre>    if (&quot;$launchArgsSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre>	set launchArgs = `grep '&quot;launchArgs&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//' -e 's/&quot;//g'`
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre>	set launchArgs = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre>    set nNodesSet = `grep '&quot;numNodesSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre>    if (&quot;$nNodesSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre>	set nNodes = `grep '&quot;numNodes&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre>	set nNodes = 8
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>    set nProcs = `grep '&quot;numProcessors&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>    if (&quot;$nProcs&quot; != &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre>	@ nProcsPerNode = $nProcs / $nNodes
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre>	set nProcsPerNode = 12
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre>    set timeLimitSet = `grep '&quot;timeLimitSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre>    if (&quot;$timeLimitSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre>	set time = `grep '&quot;timeLimit&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre>	set time = &quot;4:00:00&quot;
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>    set bankSet = `grep '&quot;bankSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>    if (&quot;$bankSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>	set bank = `grep '&quot;bank&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>	set bank = &quot;smithp-ash&quot;
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre>    set partitionSet = `grep '&quot;partitionSet&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre>    if (&quot;$partitionSet&quot; == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre>	set partition = `grep '&quot;partition&quot;' $sessionFile | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre>	set partition = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre># Parse the session file and locate the Save Window Attributes. If they exist
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre># parse the format, height, and width.
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre>set format = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre>set height = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>set width  = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>set windowAttsSet = `grep '&quot;SaveWindowAttributes&quot;' $sessionFile`
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>if (&quot;$windowAttsSet&quot; != &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre>    set format = `sed -e '1,/SaveWindowAttributes&quot;/d' -e '/&lt;Object/,$d' $sessionFile | grep '&quot;format&quot;' | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//' -e 's/\(.*\)/\L\1/'`
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>    set height = `sed -e '1,/&quot;SaveWindowAttributes&quot;/d' -e '/&lt;Object/,$d' $sessionFile | grep '&quot;height&quot;' | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>    set width  = `sed -e '1,/&quot;SaveWindowAttributes&quot;/d' -e '/&lt;Object/,$d' $sessionFile | grep '&quot;width&quot;'  | sed -e 's/&lt;[^&gt;]*&gt;//g' -e 's/^[ \t]*//'`
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>else
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>    echo &quot;Can not find SaveWindowAttributes, using internal defaults.&quot;
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre># Rather than use the VisIt defaults use the following values.
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>if (&quot;$format&quot; == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>    set format = &quot;tiff&quot;
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre>if (&quot;$height&quot; == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre>    set height = 512
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre>if (&quot;$width&quot; == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre>    set width  = 1024
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre>set geometry = &quot;${width}x${height}&quot;
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L189"><a href="#L189">189</a></th><td class="line-code"><pre># Process the rest of the optional arguments.
</pre></td></tr>


<tr><th class="line-num" id="L190"><a href="#L190">190</a></th><td class="line-code"><pre>set i = 6
</pre></td></tr>


<tr><th class="line-num" id="L191"><a href="#L191">191</a></th><td class="line-code"><pre>set j = 7
</pre></td></tr>


<tr><th class="line-num" id="L192"><a href="#L192">192</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L193"><a href="#L193">193</a></th><td class="line-code"><pre>while ($i &lt;= $#argv)
</pre></td></tr>


<tr><th class="line-num" id="L194"><a href="#L194">194</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L195"><a href="#L195">195</a></th><td class="line-code"><pre>    if (X${argv[$i]} =~ X-c* || X${argv[$i]} =~ X-s*) then
</pre></td></tr>


<tr><th class="line-num" id="L196"><a href="#L196">196</a></th><td class="line-code"><pre>       set concurrent = true
</pre></td></tr>


<tr><th class="line-num" id="L197"><a href="#L197">197</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L198"><a href="#L198">198</a></th><td class="line-code"><pre>    else if (X${argv[$i]} =~ X-*) then
</pre></td></tr>


<tr><th class="line-num" id="L199"><a href="#L199">199</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L200"><a href="#L200">200</a></th><td class="line-code"><pre>        if (X${argv[$i]} =~ X-v) then              # version
</pre></td></tr>


<tr><th class="line-num" id="L201"><a href="#L201">201</a></th><td class="line-code"><pre>	    set version = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L202"><a href="#L202">202</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-l) then         # launch method
</pre></td></tr>


<tr><th class="line-num" id="L203"><a href="#L203">203</a></th><td class="line-code"><pre>	    set launchMethod = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L204"><a href="#L204">204</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-q) then         # queue
</pre></td></tr>


<tr><th class="line-num" id="L205"><a href="#L205">205</a></th><td class="line-code"><pre>	    set queue = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L206"><a href="#L206">206</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-nn) then        # number of nodes
</pre></td></tr>


<tr><th class="line-num" id="L207"><a href="#L207">207</a></th><td class="line-code"><pre>	    set nNodes = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L208"><a href="#L208">208</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-npn) then       # number of processors/nodes
</pre></td></tr>


<tr><th class="line-num" id="L209"><a href="#L209">209</a></th><td class="line-code"><pre>	    set nProcsPerNode = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L210"><a href="#L210">210</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-t*) then        # time
</pre></td></tr>


<tr><th class="line-num" id="L211"><a href="#L211">211</a></th><td class="line-code"><pre>	    set time = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L212"><a href="#L212">212</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-b*) then        # bank
</pre></td></tr>


<tr><th class="line-num" id="L213"><a href="#L213">213</a></th><td class="line-code"><pre>	    set bank = ${argv[$j]}
</pre></td></tr>


<tr><th class="line-num" id="L214"><a href="#L214">214</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-p*) then        # partition
</pre></td></tr>


<tr><th class="line-num" id="L215"><a href="#L215">215</a></th><td class="line-code"><pre>	    set partition = &quot;${argv[$j]}&quot;
</pre></td></tr>


<tr><th class="line-num" id="L216"><a href="#L216">216</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-g*) then        # geometry
</pre></td></tr>


<tr><th class="line-num" id="L217"><a href="#L217">217</a></th><td class="line-code"><pre>	    set geometry = &quot;${argv[$j]}&quot;
</pre></td></tr>


<tr><th class="line-num" id="L218"><a href="#L218">218</a></th><td class="line-code"><pre>        else if (X${argv[$i]} =~ X-g*) then        # format
</pre></td></tr>


<tr><th class="line-num" id="L219"><a href="#L219">219</a></th><td class="line-code"><pre>	    set format = &quot;${argv[$j]}&quot;
</pre></td></tr>


<tr><th class="line-num" id="L220"><a href="#L220">220</a></th><td class="line-code"><pre>	else
</pre></td></tr>


<tr><th class="line-num" id="L221"><a href="#L221">221</a></th><td class="line-code"><pre>	  echo &quot;Unknown option ${argv[$i]} ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L222"><a href="#L222">222</a></th><td class="line-code"><pre>          echo &quot;Usage: $0 &lt;movie name&gt; &lt;start frame&gt; &lt;end frame&gt; &lt;frames per batch&gt; &lt;session file&gt;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L223"><a href="#L223">223</a></th><td class="line-code"><pre>          echo &quot;       [-concurrent] or [-shotgun (to be deparcated)]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L224"><a href="#L224">224</a></th><td class="line-code"><pre>          echo &quot;       [-v version of VisIt to execute]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L225"><a href="#L225">225</a></th><td class="line-code"><pre>          echo &quot;       [-l launchMethod] [-queue &lt;queue&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L226"><a href="#L226">226</a></th><td class="line-code"><pre>          echo &quot;       [-geometry &lt;width&gt;x&lt;height&gt;] [-format &lt;image format&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L227"><a href="#L227">227</a></th><td class="line-code"><pre>          echo &quot;       [-nn &lt;Number of nodes&gt;] [-npn &lt;Number of processors per node&gt;] [-time &lt;Maximum job run time&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L228"><a href="#L228">228</a></th><td class="line-code"><pre>          echo &quot;       [-bank &lt;Bank from which to draw resources&gt;] [-partition &lt;Partition to utilize&gt;]&quot;
</pre></td></tr>


<tr><th class="line-num" id="L229"><a href="#L229">229</a></th><td class="line-code"><pre>	  exit
</pre></td></tr>


<tr><th class="line-num" id="L230"><a href="#L230">230</a></th><td class="line-code"><pre>	endif
</pre></td></tr>


<tr><th class="line-num" id="L231"><a href="#L231">231</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L232"><a href="#L232">232</a></th><td class="line-code"><pre>        @ i = $i + 1
</pre></td></tr>


<tr><th class="line-num" id="L233"><a href="#L233">233</a></th><td class="line-code"><pre>        @ j = $j + 1
</pre></td></tr>


<tr><th class="line-num" id="L234"><a href="#L234">234</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L235"><a href="#L235">235</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L236"><a href="#L236">236</a></th><td class="line-code"><pre>    @ i = $i + 1
</pre></td></tr>


<tr><th class="line-num" id="L237"><a href="#L237">237</a></th><td class="line-code"><pre>    @ j = $j + 1
</pre></td></tr>


<tr><th class="line-num" id="L238"><a href="#L238">238</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L239"><a href="#L239">239</a></th><td class="line-code"><pre>end
</pre></td></tr>


<tr><th class="line-num" id="L240"><a href="#L240">240</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L241"><a href="#L241">241</a></th><td class="line-code"><pre># If needed calculate the number of nodes, processors per node, etc.
</pre></td></tr>


<tr><th class="line-num" id="L242"><a href="#L242">242</a></th><td class="line-code"><pre>if ($concurrent == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L243"><a href="#L243">243</a></th><td class="line-code"><pre>    @ nProcs = $nNodes * $nProcsPerNode
</pre></td></tr>


<tr><th class="line-num" id="L244"><a href="#L244">244</a></th><td class="line-code"><pre>else
</pre></td></tr>


<tr><th class="line-num" id="L245"><a href="#L245">245</a></th><td class="line-code"><pre>    if( $nNodes == &quot;&quot; &amp;&amp; $nProcsPerNode == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L246"><a href="#L246">246</a></th><td class="line-code"><pre>	set nProcs = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L247"><a href="#L247">247</a></th><td class="line-code"><pre>    else if ($nNodes == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L248"><a href="#L248">248</a></th><td class="line-code"><pre>	set nNodes = 8
</pre></td></tr>


<tr><th class="line-num" id="L249"><a href="#L249">249</a></th><td class="line-code"><pre>	@ nProcs = $nNodes * $nProcsPerNode
</pre></td></tr>


<tr><th class="line-num" id="L250"><a href="#L250">250</a></th><td class="line-code"><pre>    else if (&quot;$nProcsPerNode&quot; == &quot;&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L251"><a href="#L251">251</a></th><td class="line-code"><pre>	set nProcsPerNode = 12
</pre></td></tr>


<tr><th class="line-num" id="L252"><a href="#L252">252</a></th><td class="line-code"><pre>	@ nProcs = $nNodes * $nProcsPerNode
</pre></td></tr>


<tr><th class="line-num" id="L253"><a href="#L253">253</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L254"><a href="#L254">254</a></th><td class="line-code"><pre>        @ nProcs = $nNodes * $nProcsPerNode
</pre></td></tr>


<tr><th class="line-num" id="L255"><a href="#L255">255</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L256"><a href="#L256">256</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L257"><a href="#L257">257</a></th><td class="line-code"><pre>    if (&quot;$queue&quot; != &quot;&quot; &amp;&amp; $queue != $launchMethod) then
</pre></td></tr>


<tr><th class="line-num" id="L258"><a href="#L258">258</a></th><td class="line-code"><pre>	set launchMethod = $queue/$launchMethod
</pre></td></tr>


<tr><th class="line-num" id="L259"><a href="#L259">259</a></th><td class="line-code"><pre>        set queue = &quot;&quot;
</pre></td></tr>


<tr><th class="line-num" id="L260"><a href="#L260">260</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L261"><a href="#L261">261</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L262"><a href="#L262">262</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L263"><a href="#L263">263</a></th><td class="line-code"><pre>if ($concurrent == &quot;true&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L264"><a href="#L264">264</a></th><td class="line-code"><pre>    if (X&quot;${launchArgs}&quot; =~ X*-l*) then
</pre></td></tr>


<tr><th class="line-num" id="L265"><a href="#L265">265</a></th><td class="line-code"><pre>      echo &quot;The session file contains launch args ($launchArgs) that will conflict with $launchMethod. Edit the session file and set launchArgsSet to false.&quot;
</pre></td></tr>


<tr><th class="line-num" id="L266"><a href="#L266">266</a></th><td class="line-code"><pre>      exit
</pre></td></tr>


<tr><th class="line-num" id="L267"><a href="#L267">267</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L268"><a href="#L268">268</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L269"><a href="#L269">269</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L270"><a href="#L270">270</a></th><td class="line-code"><pre># Set some required default command line arguments
</pre></td></tr>


<tr><th class="line-num" id="L271"><a href="#L271">271</a></th><td class="line-code"><pre>set sessionFile = &quot;-sessionfile $sessionFile&quot;
</pre></td></tr>


<tr><th class="line-num" id="L272"><a href="#L272">272</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L273"><a href="#L273">273</a></th><td class="line-code"><pre>echo &quot;Successfully parsed the session file and command line. The following parameters were found:&quot;
</pre></td></tr>


<tr><th class="line-num" id="L274"><a href="#L274">274</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L275"><a href="#L275">275</a></th><td class="line-code"><pre>if ($version != &quot;&quot;)        echo &quot;  VisIt version = $version&quot;
</pre></td></tr>


<tr><th class="line-num" id="L276"><a href="#L276">276</a></th><td class="line-code"><pre>if ($concurrent == &quot;true&quot;) echo &quot;  Queue = $queue&quot;
</pre></td></tr>


<tr><th class="line-num" id="L277"><a href="#L277">277</a></th><td class="line-code"><pre>if ($launchMethod != &quot;&quot;)   echo &quot;  Launch method = $launchMethod&quot;
</pre></td></tr>


<tr><th class="line-num" id="L278"><a href="#L278">278</a></th><td class="line-code"><pre>if ($launchArgs != &quot;&quot;)     echo &quot;  Launch method = $launchArgs&quot;
</pre></td></tr>


<tr><th class="line-num" id="L279"><a href="#L279">279</a></th><td class="line-code"><pre>if ($nNodes != &quot;&quot;)         echo &quot;  Number of nodes = $nNodes&quot;
</pre></td></tr>


<tr><th class="line-num" id="L280"><a href="#L280">280</a></th><td class="line-code"><pre>if ($nProcs != &quot;&quot;)         echo &quot;  Number of processors = $nProcs&quot;
</pre></td></tr>


<tr><th class="line-num" id="L281"><a href="#L281">281</a></th><td class="line-code"><pre>if ($nProcsPerNode != &quot;&quot;)  echo &quot;  Number of processors per node = $nProcsPerNode&quot;
</pre></td></tr>


<tr><th class="line-num" id="L282"><a href="#L282">282</a></th><td class="line-code"><pre>if ($bank != &quot;&quot;)           echo &quot;  Bank = $bank&quot;
</pre></td></tr>


<tr><th class="line-num" id="L283"><a href="#L283">283</a></th><td class="line-code"><pre>if ($time != &quot;&quot;)           echo &quot;  Time = $time&quot;
</pre></td></tr>


<tr><th class="line-num" id="L284"><a href="#L284">284</a></th><td class="line-code"><pre>if ($partition != &quot;&quot;)      echo &quot;  Partition = $partition&quot;
</pre></td></tr>


<tr><th class="line-num" id="L285"><a href="#L285">285</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L286"><a href="#L286">286</a></th><td class="line-code"><pre>if ($format != &quot;&quot;)         echo &quot;  Format = $format&quot;
</pre></td></tr>


<tr><th class="line-num" id="L287"><a href="#L287">287</a></th><td class="line-code"><pre>if ($geometry != &quot;&quot;)       echo &quot;  Image size = $geometry&quot;
</pre></td></tr>


<tr><th class="line-num" id="L288"><a href="#L288">288</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L289"><a href="#L289">289</a></th><td class="line-code"><pre>if ($version != &quot;&quot;) set version = &quot;-v $version&quot;
</pre></td></tr>


<tr><th class="line-num" id="L290"><a href="#L290">290</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L291"><a href="#L291">291</a></th><td class="line-code"><pre>if ($concurrent == &quot;false&quot;) then
</pre></td></tr>


<tr><th class="line-num" id="L292"><a href="#L292">292</a></th><td class="line-code"><pre>    if ($launchMethod != &quot;&quot;) set launchMethod = &quot;-l $launchMethod&quot;
</pre></td></tr>


<tr><th class="line-num" id="L293"><a href="#L293">293</a></th><td class="line-code"><pre>    if ($nNodes != &quot;&quot;) set nNodes = &quot;-nn $nNodes&quot;
</pre></td></tr>


<tr><th class="line-num" id="L294"><a href="#L294">294</a></th><td class="line-code"><pre>    if ($nProcs != &quot;&quot;) set nProcs = &quot;-np $nProcs&quot;
</pre></td></tr>


<tr><th class="line-num" id="L295"><a href="#L295">295</a></th><td class="line-code"><pre>    if ($bank != &quot;&quot;) set bank = &quot;-b $bank&quot;
</pre></td></tr>


<tr><th class="line-num" id="L296"><a href="#L296">296</a></th><td class="line-code"><pre>    if ($time != &quot;&quot;) set time = &quot;-t $time&quot;
</pre></td></tr>


<tr><th class="line-num" id="L297"><a href="#L297">297</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L298"><a href="#L298">298</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L299"><a href="#L299">299</a></th><td class="line-code"><pre>if ($partition != &quot;&quot;) set partition = &quot;-p $partition&quot;
</pre></td></tr>


<tr><th class="line-num" id="L300"><a href="#L300">300</a></th><td class="line-code"><pre>if ($format != &quot;&quot;)    set format = &quot;-format $format&quot;
</pre></td></tr>


<tr><th class="line-num" id="L301"><a href="#L301">301</a></th><td class="line-code"><pre>if ($geometry != &quot;&quot;)  set geometry = &quot;-geometry $geometry&quot;
</pre></td></tr>


<tr><th class="line-num" id="L302"><a href="#L302">302</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L303"><a href="#L303">303</a></th><td class="line-code"><pre># Calculate the number frames and batches to generate.
</pre></td></tr>


<tr><th class="line-num" id="L304"><a href="#L304">304</a></th><td class="line-code"><pre>@ nFrames = $endFrame - $startFrame + 1
</pre></td></tr>


<tr><th class="line-num" id="L305"><a href="#L305">305</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L306"><a href="#L306">306</a></th><td class="line-code"><pre>if ($nFrames &lt;= 0) then
</pre></td></tr>


<tr><th class="line-num" id="L307"><a href="#L307">307</a></th><td class="line-code"><pre>    echo &quot;The number of frames is zero or negative ... exiting&quot;
</pre></td></tr>


<tr><th class="line-num" id="L308"><a href="#L308">308</a></th><td class="line-code"><pre>    exit
</pre></td></tr>


<tr><th class="line-num" id="L309"><a href="#L309">309</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L310"><a href="#L310">310</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L311"><a href="#L311">311</a></th><td class="line-code"><pre>@ nBatches = $nFrames / $framesPerBatch
</pre></td></tr>


<tr><th class="line-num" id="L312"><a href="#L312">312</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L313"><a href="#L313">313</a></th><td class="line-code"><pre>if ($nBatches * $framesPerBatch != $nFrames) then
</pre></td></tr>


<tr><th class="line-num" id="L314"><a href="#L314">314</a></th><td class="line-code"><pre>    @ nBatches = $nBatches + 1
</pre></td></tr>


<tr><th class="line-num" id="L315"><a href="#L315">315</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L316"><a href="#L316">316</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L317"><a href="#L317">317</a></th><td class="line-code"><pre># Loop through and generate the jobs either sequientially or in parallel.
</pre></td></tr>


<tr><th class="line-num" id="L318"><a href="#L318">318</a></th><td class="line-code"><pre>if( $concurrent == &quot;true&quot; ) then
</pre></td></tr>


<tr><th class="line-num" id="L319"><a href="#L319">319</a></th><td class="line-code"><pre>    echo &quot;Creating $nBatches concurrent jobs.&quot;
</pre></td></tr>


<tr><th class="line-num" id="L320"><a href="#L320">320</a></th><td class="line-code"><pre>else
</pre></td></tr>


<tr><th class="line-num" id="L321"><a href="#L321">321</a></th><td class="line-code"><pre>    echo &quot;Creating $nBatches sequential jobs.&quot;
</pre></td></tr>


<tr><th class="line-num" id="L322"><a href="#L322">322</a></th><td class="line-code"><pre>endif
</pre></td></tr>


<tr><th class="line-num" id="L323"><a href="#L323">323</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L324"><a href="#L324">324</a></th><td class="line-code"><pre>set batch = 0
</pre></td></tr>


<tr><th class="line-num" id="L325"><a href="#L325">325</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L326"><a href="#L326">326</a></th><td class="line-code"><pre>while ($batch &lt; $nBatches)
</pre></td></tr>


<tr><th class="line-num" id="L327"><a href="#L327">327</a></th><td class="line-code"><pre>    @ start = $startFrame + $batch * $framesPerBatch
</pre></td></tr>


<tr><th class="line-num" id="L328"><a href="#L328">328</a></th><td class="line-code"><pre>    @ end   = $start + $framesPerBatch - 1
</pre></td></tr>


<tr><th class="line-num" id="L329"><a href="#L329">329</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L330"><a href="#L330">330</a></th><td class="line-code"><pre>    if( $end &gt; $endFrame ) set end = $endFrame
</pre></td></tr>


<tr><th class="line-num" id="L331"><a href="#L331">331</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L332"><a href="#L332">332</a></th><td class="line-code"><pre>    set fullMovieName = &quot;-output $movieName&quot;
</pre></td></tr>


<tr><th class="line-num" id="L333"><a href="#L333">333</a></th><td class="line-code"><pre>    set jobName = $movieName:t_job_$batch
</pre></td></tr>


<tr><th class="line-num" id="L334"><a href="#L334">334</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L335"><a href="#L335">335</a></th><td class="line-code"><pre>    echo &quot;Creating frames $start through $end using job name $jobName&quot;
</pre></td></tr>


<tr><th class="line-num" id="L336"><a href="#L336">336</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L337"><a href="#L337">337</a></th><td class="line-code"><pre>    # Concurrent
</pre></td></tr>


<tr><th class="line-num" id="L338"><a href="#L338">338</a></th><td class="line-code"><pre>    if( $concurrent == &quot;true&quot; ) then
</pre></td></tr>


<tr><th class="line-num" id="L339"><a href="#L339">339</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L340"><a href="#L340">340</a></th><td class="line-code"><pre># No indentation because white spaces are passed to qsub and
</pre></td></tr>


<tr><th class="line-num" id="L341"><a href="#L341">341</a></th><td class="line-code"><pre># will screw up the EOF sentinal. 
</pre></td></tr>


<tr><th class="line-num" id="L342"><a href="#L342">342</a></th><td class="line-code"><pre>     $queue -l nodes=${nNodes}:ppn=$nProcsPerNode,walltime=$time $launchArgs -A $bank -N $jobName &lt;&lt; EOF
</pre></td></tr>


<tr><th class="line-num" id="L343"><a href="#L343">343</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L344"><a href="#L344">344</a></th><td class="line-code"><pre>cd $cwd
</pre></td></tr>


<tr><th class="line-num" id="L345"><a href="#L345">345</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L346"><a href="#L346">346</a></th><td class="line-code"><pre>$visit $version -l $launchMethod -nn $nNodes -np $nProcs -machinefile \${PBS_NODEFILE} -bank $bank $partition -movie -start $start -end $end $geometry -frame $start $format $fullMovieName $sessionFile
</pre></td></tr>


<tr><th class="line-num" id="L347"><a href="#L347">347</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L348"><a href="#L348">348</a></th><td class="line-code"><pre>EOF
</pre></td></tr>


<tr><th class="line-num" id="L349"><a href="#L349">349</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L350"><a href="#L350">350</a></th><td class="line-code"><pre>    # Sequential
</pre></td></tr>


<tr><th class="line-num" id="L351"><a href="#L351">351</a></th><td class="line-code"><pre>    else
</pre></td></tr>


<tr><th class="line-num" id="L352"><a href="#L352">352</a></th><td class="line-code"><pre>        echo &quot;$visit $version $launchMethod $nNodes $nProcs $time $bank $partition -movie -start $start -end $end -frame $start $geometry $format $fullMovieName $sessionFile&quot;
</pre></td></tr>


<tr><th class="line-num" id="L353"><a href="#L353">353</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L354"><a href="#L354">354</a></th><td class="line-code"><pre>        $visit $version $launchMethod $nNodes $nProcs $time $bank $partition -movie -start $start -end $end -frame $start $geometry $format $fullMovieName $sessionFile &gt;&gt;&amp;! $movieName$batch.script_log
</pre></td></tr>


<tr><th class="line-num" id="L355"><a href="#L355">355</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L356"><a href="#L356">356</a></th><td class="line-code"><pre>    endif
</pre></td></tr>


<tr><th class="line-num" id="L357"><a href="#L357">357</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L358"><a href="#L358">358</a></th><td class="line-code"><pre>    @ batch = $batch + 1
</pre></td></tr>


<tr><th class="line-num" id="L359"><a href="#L359">359</a></th><td class="line-code"><pre>end
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
