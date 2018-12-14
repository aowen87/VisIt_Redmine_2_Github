<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - LaunchService_socket-bridge-host.C - VisIt Bugs</title>
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
				
        <h2>LaunchService_socket-bridge-host.C</h2>

<div class="attachments">
<p>
   <span class="author">Jens Henrik Goebbert, 10/26/2015 06:03 am</span></p>
<p><a href="/attachments/download/357/LaunchService_socket-bridge-host.C">Download</a>   <span class="size">(15.6 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre><span class="c">/*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>* Copyright (c) 2000 - 2015, Lawrence Livermore National Security, LLC
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>* Produced at the Lawrence Livermore National Laboratory
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>* LLNL-CODE-442911
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>* All rights reserved.
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>* full copyright notice is contained in the file COPYRIGHT located at the root
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>* modification, are permitted provided that the following conditions are met:
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>*  - Redistributions of  source code must  retain the above  copyright notice,
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>*    this list of conditions and the disclaimer below.
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>*  - Redistributions in binary form must reproduce the above copyright notice,
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>*    documentation and/or other materials provided with the distribution.
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>*    be used to endorse or promote products derived from this software without
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>*    specific prior written permission.
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS &quot;AS IS&quot;
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>* DAMAGE.
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>*****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;LaunchService.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;cstdio&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;cstdlib&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;cstring&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;ctime&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre><span class="pp">#if</span> defined(_WIN32)
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;process.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;winsock2.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;windows.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre><span class="pp">#else</span>
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;unistd.h&gt; // alarm</span>
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;signal.h&gt; </span>
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;sys/types.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;sys/wait.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;DebugStream.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;FileFunctions.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;ParentProcess.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;VisItException.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;SocketBridge.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;SocketConnection.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre><span class="c">// Capture child output on UNIX &amp; Mac. </span>
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre><span class="pp">#if</span> !defined(_WIN32)
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre><span class="pp">#define</span> CAPTURE_CHILD_OUTPUT
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre><span class="c">// Static member variables.</span>
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>std::map&lt;<span class="pt">int</span>, <span class="pt">bool</span>&gt; LaunchService::childDied;
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre><span class="c">// Pass this information to the thread to set up the bridge.</span>
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre><span class="r">struct</span> BridgeInfo
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>    <span class="pt">int</span>  newlocalport;
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>    <span class="pt">int</span>  oldlocalport;
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>    <span class="pt">int</span>  bufferSize;
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>    <span class="pt">bool</span> logging;
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>};
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre><span class="c">//  Function:  CreateSocketBridge</span>
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre><span class="c">//  Purpose:</span>
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre><span class="c">//    Initiate the socket bridge.</span>
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre><span class="c">//  Arguments:</span>
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre><span class="c">//    ports      (really an int[2]):</span>
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre><span class="c">//                 ports[0]=new local port</span>
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre><span class="c">//                 ports[1]=old local port</span>
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre><span class="c">//  Programmer:  Jeremy Meredith</span>
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre><span class="c">//  Creation:    June  5, 2007</span>
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre><span class="c">//  Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre><span class="c">//    Thomas R. Treadway, Mon Oct  8 13:27:42 PDT 2007</span>
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre><span class="c">//    Backing out SSH tunneling on Panther (MacOS X 10.3)</span>
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre><span class="c">//    Brad Whitlock, Tue Oct 14 17:12:46 PDT 2014</span>
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre><span class="c">//    Pass the bridge set up information in a struct. Set the buffer size.</span>
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre><span class="r">static</span> <span class="pt">void</span> CreateSocketBridge(<span class="pt">void</span> *ptr)
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>    BridgeInfo *info = (BridgeInfo *)ptr;
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>    SocketBridge bridge(info-&gt;newlocalport, info-&gt;oldlocalport);
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>    bridge.SetLogging(info-&gt;logging);
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>    <span class="r">if</span>(info-&gt;bufferSize &gt; <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>        bridge.SetBufferSize(info-&gt;bufferSize);
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre>    bridge.Bridge();
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre><span class="c">// Method: LaunchService::LaunchService</span>
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre><span class="c">// Purpose: </span>
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre><span class="c">//   Constructor.</span>
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre><span class="c">// Programmer: Brad Whitlock</span>
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre><span class="c">// Creation:   Mon Nov 28 17:11:19 PST 2011</span>
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre><span class="c">// Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre><span class="c">//   </span>
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>LaunchService::LaunchService()
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre><span class="c">// Method: LaunchService::~LaunchService</span>
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre><span class="c">// Purpose: </span>
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre><span class="c">//   Destructor.</span>
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre><span class="c">// Programmer: Brad Whitlock</span>
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre><span class="c">// Creation:   Mon Nov 28 17:11:19 PST 2011</span>
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre><span class="c">// Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre><span class="c">//   </span>
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>LaunchService::~LaunchService()
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre><span class="c">// Method: LaunchService::DeadChildHandler</span>
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre><span class="c">// Purpose: </span>
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre><span class="c">//    Signal handler for a SIGCHLD even while waiting for remote connections.</span>
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre><span class="c">//    Catch a child that died and mark it's success or failure in the</span>
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre><span class="c">//    childDied array.</span>
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre><span class="c">// Programmer: Brad Whitlock</span>
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre><span class="c">// Creation:   Mon May 5 11:18:55 PDT 2003</span>
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre><span class="c">// Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre><span class="c">//   </span>
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre><span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>LaunchService::DeadChildHandler(<span class="pt">int</span>)
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre><span class="pp">#if</span> !defined(_WIN32)
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>    <span class="pt">int</span> status;
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>    <span class="pt">int</span> pid;
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>    pid = wait(&amp;status);
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>    childDied[pid] = (status == <span class="i">0</span> ? <span class="pc">false</span> : <span class="pc">true</span>);
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>    signal(SIGCHLD, DeadChildHandler);
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre><span class="c">//  Method:  LaunchService::SetupGatewaySocketBridgeIfNeeded</span>
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre><span class="c">//  Purpose:</span>
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre><span class="c">//    If SSH tunneling is enabled and we're about to launch a parallel</span>
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre><span class="c">//    engine, we need to set up a local port from any incoming host</span>
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre><span class="c">//    that gets forwarded through the appropriate SSH tunnel.  We cannot</span>
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre><span class="c">//    access SSH tunnels at the login node for a cluster from the</span>
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre><span class="c">//    compute nodes, because by default SSH only listens for connections</span>
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre><span class="c">//    from localhost.</span>
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre><span class="c">//    The launch arguments containing the login node forward (&quot;localhost&quot;:port)</span>
</pre></td></tr>


<tr><th class="line-num" id="L189"><a href="#L189">189</a></th><td class="line-code"><pre><span class="c">//    are also converted to the new bridge (loginnode:newport);</span>
</pre></td></tr>


<tr><th class="line-num" id="L190"><a href="#L190">190</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L191"><a href="#L191">191</a></th><td class="line-code"><pre><span class="c">//  Arguments:</span>
</pre></td></tr>


<tr><th class="line-num" id="L192"><a href="#L192">192</a></th><td class="line-code"><pre><span class="c">//    launchArgs    the launch arguments (these will be modified in-place!)</span>
</pre></td></tr>


<tr><th class="line-num" id="L193"><a href="#L193">193</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L194"><a href="#L194">194</a></th><td class="line-code"><pre><span class="c">//  Programmer:  Jeremy Meredith</span>
</pre></td></tr>


<tr><th class="line-num" id="L195"><a href="#L195">195</a></th><td class="line-code"><pre><span class="c">//  Creation:    May 24, 2007</span>
</pre></td></tr>


<tr><th class="line-num" id="L196"><a href="#L196">196</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L197"><a href="#L197">197</a></th><td class="line-code"><pre><span class="c">//  Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L198"><a href="#L198">198</a></th><td class="line-code"><pre><span class="c">//    Thomas R. Treadway, Mon Oct  8 13:27:42 PDT 2007</span>
</pre></td></tr>


<tr><th class="line-num" id="L199"><a href="#L199">199</a></th><td class="line-code"><pre><span class="c">//    Backing out SSH tunneling on Panther (MacOS X 10.3)</span>
</pre></td></tr>


<tr><th class="line-num" id="L200"><a href="#L200">200</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L201"><a href="#L201">201</a></th><td class="line-code"><pre><span class="c">//    Brad Whitlock, Mon Apr 27 16:31:23 PST 2009</span>
</pre></td></tr>


<tr><th class="line-num" id="L202"><a href="#L202">202</a></th><td class="line-code"><pre><span class="c">//    I changed the routine so the check for setting up the bridge is passed</span>
</pre></td></tr>


<tr><th class="line-num" id="L203"><a href="#L203">203</a></th><td class="line-code"><pre><span class="c">//    in rather than calculated in here from launch arguments.</span>
</pre></td></tr>


<tr><th class="line-num" id="L204"><a href="#L204">204</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L205"><a href="#L205">205</a></th><td class="line-code"><pre><span class="c">//    Brad Whitlock, Tue Oct 14 17:16:31 PDT 2014</span>
</pre></td></tr>


<tr><th class="line-num" id="L206"><a href="#L206">206</a></th><td class="line-code"><pre><span class="c">//    Allow the buffer size to be passed in to the thread that makes the bridge.</span>
</pre></td></tr>


<tr><th class="line-num" id="L207"><a href="#L207">207</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L208"><a href="#L208">208</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L209"><a href="#L209">209</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L210"><a href="#L210">210</a></th><td class="line-code"><pre><span class="pt">bool</span>
</pre></td></tr>


<tr><th class="line-num" id="L211"><a href="#L211">211</a></th><td class="line-code"><pre>LaunchService::SetupGatewaySocketBridgeIfNeeded(stringVector &amp;launchArgs)
</pre></td></tr>


<tr><th class="line-num" id="L212"><a href="#L212">212</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L213"><a href="#L213">213</a></th><td class="line-code"><pre>    <span class="r">const</span> <span class="pt">char</span> *mName=<span class="s"><span class="dl">&quot;</span><span class="k">LaunchService::SetupGatewaySocketBridgeIfNeeded: </span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L214"><a href="#L214">214</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L215"><a href="#L215">215</a></th><td class="line-code"><pre>    <span class="c">// Get the port and host.</span>
</pre></td></tr>


<tr><th class="line-num" id="L216"><a href="#L216">216</a></th><td class="line-code"><pre>    <span class="pt">int</span>  oldlocalport       = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L217"><a href="#L217">217</a></th><td class="line-code"><pre>    <span class="pt">int</span>  portargument       = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L218"><a href="#L218">218</a></th><td class="line-code"><pre>    <span class="pt">int</span>  hostargument       = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L219"><a href="#L219">219</a></th><td class="line-code"><pre>    <span class="pt">int</span>  bufferSize         = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L220"><a href="#L220">220</a></th><td class="line-code"><pre>    std::string sbHost;
</pre></td></tr>


<tr><th class="line-num" id="L221"><a href="#L221">221</a></th><td class="line-code"><pre>    <span class="r">for</span> (size_t i=<span class="i">0</span>; i&lt;launchArgs.size(); i++)
</pre></td></tr>


<tr><th class="line-num" id="L222"><a href="#L222">222</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L223"><a href="#L223">223</a></th><td class="line-code"><pre>        <span class="r">if</span> (i&lt;launchArgs.size()-<span class="i">1</span> &amp;&amp; launchArgs[i] == <span class="s"><span class="dl">&quot;</span><span class="k">-port</span><span class="dl">&quot;</span></span>)
</pre></td></tr>


<tr><th class="line-num" id="L224"><a href="#L224">224</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L225"><a href="#L225">225</a></th><td class="line-code"><pre>            oldlocalport = atoi(launchArgs[i+<span class="i">1</span>].c_str());
</pre></td></tr>


<tr><th class="line-num" id="L226"><a href="#L226">226</a></th><td class="line-code"><pre>            portargument = i+<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L227"><a href="#L227">227</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L228"><a href="#L228">228</a></th><td class="line-code"><pre>        <span class="r">else</span> <span class="r">if</span> (i&lt;launchArgs.size()-<span class="i">1</span> &amp;&amp; launchArgs[i] == <span class="s"><span class="dl">&quot;</span><span class="k">-host</span><span class="dl">&quot;</span></span>)
</pre></td></tr>


<tr><th class="line-num" id="L229"><a href="#L229">229</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L230"><a href="#L230">230</a></th><td class="line-code"><pre>            hostargument = i+<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L231"><a href="#L231">231</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L232"><a href="#L232">232</a></th><td class="line-code"><pre>        <span class="r">else</span> <span class="r">if</span> (launchArgs[i] == <span class="s"><span class="dl">&quot;</span><span class="k">-fixed-buffer-sockets</span><span class="dl">&quot;</span></span>)
</pre></td></tr>


<tr><th class="line-num" id="L233"><a href="#L233">233</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L234"><a href="#L234">234</a></th><td class="line-code"><pre>            bufferSize = SocketConnection::FIXED_BUFFER_SIZE;
</pre></td></tr>


<tr><th class="line-num" id="L235"><a href="#L235">235</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L236"><a href="#L236">236</a></th><td class="line-code"><pre>        <span class="r">else</span> <span class="r">if</span>((i+<span class="i">1</span>)&lt;launchArgs.size() &amp;&amp; launchArgs[i] == <span class="s"><span class="dl">&quot;</span><span class="k">-socket-bridge-host</span><span class="dl">&quot;</span></span>)
</pre></td></tr>


<tr><th class="line-num" id="L237"><a href="#L237">237</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L238"><a href="#L238">238</a></th><td class="line-code"><pre>            sbHost = launchArgs[i+<span class="i">1</span>];
</pre></td></tr>


<tr><th class="line-num" id="L239"><a href="#L239">239</a></th><td class="line-code"><pre>        }        
</pre></td></tr>


<tr><th class="line-num" id="L240"><a href="#L240">240</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L241"><a href="#L241">241</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L242"><a href="#L242">242</a></th><td class="line-code"><pre>    <span class="pt">bool</span> setupBridge = (portargument != -<span class="i">1</span> &amp;&amp; hostargument != -<span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L243"><a href="#L243">243</a></th><td class="line-code"><pre>    <span class="r">if</span>(setupBridge)
</pre></td></tr>


<tr><th class="line-num" id="L244"><a href="#L244">244</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L245"><a href="#L245">245</a></th><td class="line-code"><pre>        debug5 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">Setting up gateway port bridge.</span><span class="ch">\n</span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L246"><a href="#L246">246</a></th><td class="line-code"><pre>        <span class="c">// find a new local port</span>
</pre></td></tr>


<tr><th class="line-num" id="L247"><a href="#L247">247</a></th><td class="line-code"><pre>        <span class="pt">int</span> lowerRemotePort = <span class="i">10000</span>;
</pre></td></tr>


<tr><th class="line-num" id="L248"><a href="#L248">248</a></th><td class="line-code"><pre>        <span class="pt">int</span> upperRemotePort = <span class="i">40000</span>;
</pre></td></tr>


<tr><th class="line-num" id="L249"><a href="#L249">249</a></th><td class="line-code"><pre>        <span class="pt">int</span> remotePortRange = <span class="i">1</span>+upperRemotePort-lowerRemotePort;
</pre></td></tr>


<tr><th class="line-num" id="L250"><a href="#L250">250</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L251"><a href="#L251">251</a></th><td class="line-code"><pre><span class="pp">#if</span> defined(_WIN32)
</pre></td></tr>


<tr><th class="line-num" id="L252"><a href="#L252">252</a></th><td class="line-code"><pre>        srand((<span class="pt">unsigned</span>)time(<span class="i">0</span>));
</pre></td></tr>


<tr><th class="line-num" id="L253"><a href="#L253">253</a></th><td class="line-code"><pre>        <span class="pt">int</span> newlocalport = lowerRemotePort+(rand()%remotePortRange);
</pre></td></tr>


<tr><th class="line-num" id="L254"><a href="#L254">254</a></th><td class="line-code"><pre><span class="pp">#else</span>
</pre></td></tr>


<tr><th class="line-num" id="L255"><a href="#L255">255</a></th><td class="line-code"><pre>        srand48(<span class="pt">long</span>(time(<span class="i">0</span>)));
</pre></td></tr>


<tr><th class="line-num" id="L256"><a href="#L256">256</a></th><td class="line-code"><pre>        <span class="pt">int</span> newlocalport = lowerRemotePort+(lrand48()%remotePortRange);
</pre></td></tr>


<tr><th class="line-num" id="L257"><a href="#L257">257</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L258"><a href="#L258">258</a></th><td class="line-code"><pre>        debug5 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">Bridging new port INADDR_ANY/</span><span class="dl">&quot;</span></span> &lt;&lt; newlocalport
</pre></td></tr>


<tr><th class="line-num" id="L259"><a href="#L259">259</a></th><td class="line-code"><pre>               &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k"> to tunneled port localhost/</span><span class="dl">&quot;</span></span> &lt;&lt; oldlocalport &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L260"><a href="#L260">260</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L261"><a href="#L261">261</a></th><td class="line-code"><pre>        <span class="c">// replace the host with my host name</span>
</pre></td></tr>


<tr><th class="line-num" id="L262"><a href="#L262">262</a></th><td class="line-code"><pre>        <span class="r">if</span>(sbHost.empty()) {
</pre></td></tr>


<tr><th class="line-num" id="L263"><a href="#L263">263</a></th><td class="line-code"><pre>            <span class="pt">char</span> hostname[<span class="i">1024</span>];
</pre></td></tr>


<tr><th class="line-num" id="L264"><a href="#L264">264</a></th><td class="line-code"><pre>            gethostname(hostname,<span class="i">1024</span>);
</pre></td></tr>


<tr><th class="line-num" id="L265"><a href="#L265">265</a></th><td class="line-code"><pre>            launchArgs[hostargument] = hostname;
</pre></td></tr>


<tr><th class="line-num" id="L266"><a href="#L266">266</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L267"><a href="#L267">267</a></th><td class="line-code"><pre>        <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L268"><a href="#L268">268</a></th><td class="line-code"><pre>            launchArgs[hostargument] = sbHost;
</pre></td></tr>


<tr><th class="line-num" id="L269"><a href="#L269">269</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L270"><a href="#L270">270</a></th><td class="line-code"><pre>        <span class="c">// replace the launch argument port number</span>
</pre></td></tr>


<tr><th class="line-num" id="L271"><a href="#L271">271</a></th><td class="line-code"><pre>        <span class="pt">char</span> newportstr[<span class="i">10</span>];
</pre></td></tr>


<tr><th class="line-num" id="L272"><a href="#L272">272</a></th><td class="line-code"><pre>        sprintf(newportstr,<span class="s"><span class="dl">&quot;</span><span class="k">%d</span><span class="dl">&quot;</span></span>,newlocalport);
</pre></td></tr>


<tr><th class="line-num" id="L273"><a href="#L273">273</a></th><td class="line-code"><pre>        launchArgs[portargument] = newportstr;
</pre></td></tr>


<tr><th class="line-num" id="L274"><a href="#L274">274</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L275"><a href="#L275">275</a></th><td class="line-code"><pre>        <span class="c">// fork and start the socket bridge</span>
</pre></td></tr>


<tr><th class="line-num" id="L276"><a href="#L276">276</a></th><td class="line-code"><pre>        BridgeInfo *info = new BridgeInfo;
</pre></td></tr>


<tr><th class="line-num" id="L277"><a href="#L277">277</a></th><td class="line-code"><pre>        info-&gt;newlocalport = newlocalport;
</pre></td></tr>


<tr><th class="line-num" id="L278"><a href="#L278">278</a></th><td class="line-code"><pre>        info-&gt;oldlocalport = oldlocalport;
</pre></td></tr>


<tr><th class="line-num" id="L279"><a href="#L279">279</a></th><td class="line-code"><pre>        info-&gt;bufferSize   = bufferSize;
</pre></td></tr>


<tr><th class="line-num" id="L280"><a href="#L280">280</a></th><td class="line-code"><pre>        info-&gt;logging      = DebugStream::Level1();
</pre></td></tr>


<tr><th class="line-num" id="L281"><a href="#L281">281</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> _WIN32
</pre></td></tr>


<tr><th class="line-num" id="L282"><a href="#L282">282</a></th><td class="line-code"><pre>        _beginthread(CreateSocketBridge, <span class="i">0</span>, (<span class="pt">void</span>*)info);
</pre></td></tr>


<tr><th class="line-num" id="L283"><a href="#L283">283</a></th><td class="line-code"><pre><span class="pp">#else</span>
</pre></td></tr>


<tr><th class="line-num" id="L284"><a href="#L284">284</a></th><td class="line-code"><pre>        <span class="r">switch</span> (fork())
</pre></td></tr>


<tr><th class="line-num" id="L285"><a href="#L285">285</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L286"><a href="#L286">286</a></th><td class="line-code"><pre>          <span class="r">case</span> -<span class="i">1</span>:
</pre></td></tr>


<tr><th class="line-num" id="L287"><a href="#L287">287</a></th><td class="line-code"><pre>            <span class="c">// Could not fork.</span>
</pre></td></tr>


<tr><th class="line-num" id="L288"><a href="#L288">288</a></th><td class="line-code"><pre>            exit(-<span class="i">1</span>); <span class="c">// HOOKS_IGNORE</span>
</pre></td></tr>


<tr><th class="line-num" id="L289"><a href="#L289">289</a></th><td class="line-code"><pre>            <span class="r">break</span>;
</pre></td></tr>


<tr><th class="line-num" id="L290"><a href="#L290">290</a></th><td class="line-code"><pre>          <span class="r">case</span> <span class="i">0</span>:
</pre></td></tr>


<tr><th class="line-num" id="L291"><a href="#L291">291</a></th><td class="line-code"><pre>              {
</pre></td></tr>


<tr><th class="line-num" id="L292"><a href="#L292">292</a></th><td class="line-code"><pre>                  <span class="c">// The child process will start the bridge</span>
</pre></td></tr>


<tr><th class="line-num" id="L293"><a href="#L293">293</a></th><td class="line-code"><pre>                  <span class="c">// Close stdin and any other file descriptors.</span>
</pre></td></tr>


<tr><th class="line-num" id="L294"><a href="#L294">294</a></th><td class="line-code"><pre>                  fclose(stdin);
</pre></td></tr>


<tr><th class="line-num" id="L295"><a href="#L295">295</a></th><td class="line-code"><pre>                  <span class="r">for</span> (<span class="pt">int</span> k = <span class="i">3</span> ; k &lt; <span class="i">32</span> ; ++k)
</pre></td></tr>


<tr><th class="line-num" id="L296"><a href="#L296">296</a></th><td class="line-code"><pre>                  {
</pre></td></tr>


<tr><th class="line-num" id="L297"><a href="#L297">297</a></th><td class="line-code"><pre>                      close(k);
</pre></td></tr>


<tr><th class="line-num" id="L298"><a href="#L298">298</a></th><td class="line-code"><pre>                  }
</pre></td></tr>


<tr><th class="line-num" id="L299"><a href="#L299">299</a></th><td class="line-code"><pre>                  CreateSocketBridge((<span class="pt">void</span>*)info);
</pre></td></tr>


<tr><th class="line-num" id="L300"><a href="#L300">300</a></th><td class="line-code"><pre>                  exit(<span class="i">0</span>); <span class="c">// HOOKS_IGNORE</span>
</pre></td></tr>


<tr><th class="line-num" id="L301"><a href="#L301">301</a></th><td class="line-code"><pre>                  <span class="r">break</span>;
</pre></td></tr>


<tr><th class="line-num" id="L302"><a href="#L302">302</a></th><td class="line-code"><pre>              }
</pre></td></tr>


<tr><th class="line-num" id="L303"><a href="#L303">303</a></th><td class="line-code"><pre>          <span class="r">default</span>:
</pre></td></tr>


<tr><th class="line-num" id="L304"><a href="#L304">304</a></th><td class="line-code"><pre>            <span class="c">// Parent process continues on as normal</span>
</pre></td></tr>


<tr><th class="line-num" id="L305"><a href="#L305">305</a></th><td class="line-code"><pre>            <span class="c">// Caution: there is a slight race condition here, though</span>
</pre></td></tr>


<tr><th class="line-num" id="L306"><a href="#L306">306</a></th><td class="line-code"><pre>            <span class="c">// it would require the engine to launch and try to connect</span>
</pre></td></tr>


<tr><th class="line-num" id="L307"><a href="#L307">307</a></th><td class="line-code"><pre>            <span class="c">// back before the child process got the bridge set up.</span>
</pre></td></tr>


<tr><th class="line-num" id="L308"><a href="#L308">308</a></th><td class="line-code"><pre>            <span class="c">// The odds of this happening are low, but it should be fixed.</span>
</pre></td></tr>


<tr><th class="line-num" id="L309"><a href="#L309">309</a></th><td class="line-code"><pre>            <span class="r">break</span>;
</pre></td></tr>


<tr><th class="line-num" id="L310"><a href="#L310">310</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L311"><a href="#L311">311</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L312"><a href="#L312">312</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L313"><a href="#L313">313</a></th><td class="line-code"><pre>    <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L314"><a href="#L314">314</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L315"><a href="#L315">315</a></th><td class="line-code"><pre>        debug5 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">Required -host or -port argument not found</span><span class="dl">&quot;</span></span> &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L316"><a href="#L316">316</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L317"><a href="#L317">317</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L318"><a href="#L318">318</a></th><td class="line-code"><pre>    <span class="r">return</span> setupBridge;
</pre></td></tr>


<tr><th class="line-num" id="L319"><a href="#L319">319</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L320"><a href="#L320">320</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L321"><a href="#L321">321</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L322"><a href="#L322">322</a></th><td class="line-code"><pre><span class="c">// Method: LaunchService::LaunchProcess</span>
</pre></td></tr>


<tr><th class="line-num" id="L323"><a href="#L323">323</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L324"><a href="#L324">324</a></th><td class="line-code"><pre><span class="c">// Purpose: </span>
</pre></td></tr>


<tr><th class="line-num" id="L325"><a href="#L325">325</a></th><td class="line-code"><pre><span class="c">//   Launch a process, optionally reading its output.</span>
</pre></td></tr>


<tr><th class="line-num" id="L326"><a href="#L326">326</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L327"><a href="#L327">327</a></th><td class="line-code"><pre><span class="c">// Arguments:</span>
</pre></td></tr>


<tr><th class="line-num" id="L328"><a href="#L328">328</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L329"><a href="#L329">329</a></th><td class="line-code"><pre><span class="c">// Returns:    </span>
</pre></td></tr>


<tr><th class="line-num" id="L330"><a href="#L330">330</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L331"><a href="#L331">331</a></th><td class="line-code"><pre><span class="c">// Note:       </span>
</pre></td></tr>


<tr><th class="line-num" id="L332"><a href="#L332">332</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L333"><a href="#L333">333</a></th><td class="line-code"><pre><span class="c">// Programmer: Brad Whitlock</span>
</pre></td></tr>


<tr><th class="line-num" id="L334"><a href="#L334">334</a></th><td class="line-code"><pre><span class="c">// Creation:   Mon Nov 28 17:07:30 PST 2011</span>
</pre></td></tr>


<tr><th class="line-num" id="L335"><a href="#L335">335</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L336"><a href="#L336">336</a></th><td class="line-code"><pre><span class="c">// Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L337"><a href="#L337">337</a></th><td class="line-code"><pre><span class="c">//   </span>
</pre></td></tr>


<tr><th class="line-num" id="L338"><a href="#L338">338</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L339"><a href="#L339">339</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L340"><a href="#L340">340</a></th><td class="line-code"><pre><span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L341"><a href="#L341">341</a></th><td class="line-code"><pre>LaunchService::Launch(<span class="r">const</span> stringVector &amp;origLaunchArgs, <span class="pt">bool</span> doBridge, 
</pre></td></tr>


<tr><th class="line-num" id="L342"><a href="#L342">342</a></th><td class="line-code"><pre>    SocketConnection **conn)
</pre></td></tr>


<tr><th class="line-num" id="L343"><a href="#L343">343</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L344"><a href="#L344">344</a></th><td class="line-code"><pre>    <span class="r">const</span> <span class="pt">char</span> *mName = <span class="s"><span class="dl">&quot;</span><span class="k">LaunchService::LaunchProcess: </span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L345"><a href="#L345">345</a></th><td class="line-code"><pre>    debug1 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">start</span><span class="dl">&quot;</span></span> &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L346"><a href="#L346">346</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L347"><a href="#L347">347</a></th><td class="line-code"><pre>    stringVector launchArgs(origLaunchArgs);
</pre></td></tr>


<tr><th class="line-num" id="L348"><a href="#L348">348</a></th><td class="line-code"><pre>    <span class="pt">bool</span> readOutput = conn != <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L349"><a href="#L349">349</a></th><td class="line-code"><pre>    <span class="r">if</span>(readOutput)
</pre></td></tr>


<tr><th class="line-num" id="L350"><a href="#L350">350</a></th><td class="line-code"><pre>        *conn = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L351"><a href="#L351">351</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L352"><a href="#L352">352</a></th><td class="line-code"><pre>    <span class="r">if</span>(launchArgs.empty())
</pre></td></tr>


<tr><th class="line-num" id="L353"><a href="#L353">353</a></th><td class="line-code"><pre>        <span class="r">return</span>;
</pre></td></tr>


<tr><th class="line-num" id="L354"><a href="#L354">354</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L355"><a href="#L355">355</a></th><td class="line-code"><pre>    <span class="c">// Set up a socket bridge if we need one.</span>
</pre></td></tr>


<tr><th class="line-num" id="L356"><a href="#L356">356</a></th><td class="line-code"><pre>    <span class="r">if</span>(doBridge)
</pre></td></tr>


<tr><th class="line-num" id="L357"><a href="#L357">357</a></th><td class="line-code"><pre>        SetupGatewaySocketBridgeIfNeeded(launchArgs);
</pre></td></tr>


<tr><th class="line-num" id="L358"><a href="#L358">358</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L359"><a href="#L359">359</a></th><td class="line-code"><pre>    std::string remoteProgram(launchArgs[<span class="i">0</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L360"><a href="#L360">360</a></th><td class="line-code"><pre>    debug1 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">LaunchRPC command = </span><span class="dl">&quot;</span></span> &lt;&lt; remoteProgram.c_str() &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">, args=(</span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L361"><a href="#L361">361</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L362"><a href="#L362">362</a></th><td class="line-code"><pre>    <span class="c">// Make a command line array for the exec functions.</span>
</pre></td></tr>


<tr><th class="line-num" id="L363"><a href="#L363">363</a></th><td class="line-code"><pre>    <span class="pt">char</span> **args = new <span class="pt">char</span> *[launchArgs.size() + <span class="i">1</span>];
</pre></td></tr>


<tr><th class="line-num" id="L364"><a href="#L364">364</a></th><td class="line-code"><pre>    memset(args, <span class="i">0</span>, (launchArgs.size() + <span class="i">1</span>) * <span class="r">sizeof</span>(<span class="pt">char</span> *));
</pre></td></tr>


<tr><th class="line-num" id="L365"><a href="#L365">365</a></th><td class="line-code"><pre>    <span class="r">for</span>(size_t i = <span class="i">0</span>; i &lt; launchArgs.size(); ++i)
</pre></td></tr>


<tr><th class="line-num" id="L366"><a href="#L366">366</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L367"><a href="#L367">367</a></th><td class="line-code"><pre>        args[i] = new <span class="pt">char</span>[launchArgs[i].size() + <span class="i">1</span>];
</pre></td></tr>


<tr><th class="line-num" id="L368"><a href="#L368">368</a></th><td class="line-code"><pre>        strcpy(args[i], launchArgs[i].c_str());
</pre></td></tr>


<tr><th class="line-num" id="L369"><a href="#L369">369</a></th><td class="line-code"><pre>        <span class="r">if</span>(i &gt; <span class="i">0</span>) {
</pre></td></tr>


<tr><th class="line-num" id="L370"><a href="#L370">370</a></th><td class="line-code"><pre>            debug1 &lt;&lt; launchArgs[i].c_str() &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k"> </span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L371"><a href="#L371">371</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L372"><a href="#L372">372</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L373"><a href="#L373">373</a></th><td class="line-code"><pre>    debug1 &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">)</span><span class="dl">&quot;</span></span> &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L374"><a href="#L374">374</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L375"><a href="#L375">375</a></th><td class="line-code"><pre>    <span class="c">// We have command line arguments for a command to launch.</span>
</pre></td></tr>


<tr><th class="line-num" id="L376"><a href="#L376">376</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L377"><a href="#L377">377</a></th><td class="line-code"><pre>    <span class="pt">int</span> remoteProgramPid = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L378"><a href="#L378">378</a></th><td class="line-code"><pre><span class="pp">#if</span> defined(_WIN32)
</pre></td></tr>


<tr><th class="line-num" id="L379"><a href="#L379">379</a></th><td class="line-code"><pre>    <span class="c">// Do it the WIN32 way where we use the _spawnvp system call.</span>
</pre></td></tr>


<tr><th class="line-num" id="L380"><a href="#L380">380</a></th><td class="line-code"><pre>    remoteProgramPid = _spawnvp(_P_NOWAIT, remoteProgram.c_str(), args);
</pre></td></tr>


<tr><th class="line-num" id="L381"><a href="#L381">381</a></th><td class="line-code"><pre><span class="pp">#else</span>
</pre></td></tr>


<tr><th class="line-num" id="L382"><a href="#L382">382</a></th><td class="line-code"><pre>    <span class="c">// Watch for a process who died</span>
</pre></td></tr>


<tr><th class="line-num" id="L383"><a href="#L383">383</a></th><td class="line-code"><pre>    childDied[remoteProgramPid] = <span class="pc">false</span>;
</pre></td></tr>


<tr><th class="line-num" id="L384"><a href="#L384">384</a></th><td class="line-code"><pre>    signal(SIGCHLD, DeadChildHandler);
</pre></td></tr>


<tr><th class="line-num" id="L385"><a href="#L385">385</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L386"><a href="#L386">386</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> CAPTURE_CHILD_OUTPUT
</pre></td></tr>


<tr><th class="line-num" id="L387"><a href="#L387">387</a></th><td class="line-code"><pre>    <span class="c">// Create a pipe.</span>
</pre></td></tr>


<tr><th class="line-num" id="L388"><a href="#L388">388</a></th><td class="line-code"><pre>    <span class="pt">int</span> f_des[<span class="i">2</span>];
</pre></td></tr>


<tr><th class="line-num" id="L389"><a href="#L389">389</a></th><td class="line-code"><pre>    <span class="r">if</span>(pipe(f_des) == -<span class="i">1</span>)
</pre></td></tr>


<tr><th class="line-num" id="L390"><a href="#L390">390</a></th><td class="line-code"><pre>        readOutput = <span class="pc">false</span>;
</pre></td></tr>


<tr><th class="line-num" id="L391"><a href="#L391">391</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L392"><a href="#L392">392</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L393"><a href="#L393">393</a></th><td class="line-code"><pre>    <span class="r">switch</span> (remoteProgramPid = fork())
</pre></td></tr>


<tr><th class="line-num" id="L394"><a href="#L394">394</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L395"><a href="#L395">395</a></th><td class="line-code"><pre>    <span class="r">case</span> -<span class="i">1</span>:
</pre></td></tr>


<tr><th class="line-num" id="L396"><a href="#L396">396</a></th><td class="line-code"><pre>        <span class="c">// Could not fork.</span>
</pre></td></tr>


<tr><th class="line-num" id="L397"><a href="#L397">397</a></th><td class="line-code"><pre>        exit(-<span class="i">1</span>); <span class="c">// HOOKS_IGNORE</span>
</pre></td></tr>


<tr><th class="line-num" id="L398"><a href="#L398">398</a></th><td class="line-code"><pre>        <span class="r">break</span>;
</pre></td></tr>


<tr><th class="line-num" id="L399"><a href="#L399">399</a></th><td class="line-code"><pre>    <span class="r">case</span> <span class="i">0</span>:
</pre></td></tr>


<tr><th class="line-num" id="L400"><a href="#L400">400</a></th><td class="line-code"><pre>        <span class="c">// Close stdin and any other file descriptors.</span>
</pre></td></tr>


<tr><th class="line-num" id="L401"><a href="#L401">401</a></th><td class="line-code"><pre>        fclose(stdin);
</pre></td></tr>


<tr><th class="line-num" id="L402"><a href="#L402">402</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> CAPTURE_CHILD_OUTPUT
</pre></td></tr>


<tr><th class="line-num" id="L403"><a href="#L403">403</a></th><td class="line-code"><pre>        <span class="c">// Send the process' stdout/stderr to our pipe.</span>
</pre></td></tr>


<tr><th class="line-num" id="L404"><a href="#L404">404</a></th><td class="line-code"><pre>        <span class="r">if</span>(readOutput)
</pre></td></tr>


<tr><th class="line-num" id="L405"><a href="#L405">405</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L406"><a href="#L406">406</a></th><td class="line-code"><pre>            dup2(f_des[<span class="i">1</span>], fileno(stdout));
</pre></td></tr>


<tr><th class="line-num" id="L407"><a href="#L407">407</a></th><td class="line-code"><pre>            dup2(f_des[<span class="i">1</span>], fileno(stderr));
</pre></td></tr>


<tr><th class="line-num" id="L408"><a href="#L408">408</a></th><td class="line-code"><pre>            close(f_des[<span class="i">0</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L409"><a href="#L409">409</a></th><td class="line-code"><pre>            close(f_des[<span class="i">1</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L410"><a href="#L410">410</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L411"><a href="#L411">411</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L412"><a href="#L412">412</a></th><td class="line-code"><pre>        <span class="r">for</span> (<span class="pt">int</span> k = <span class="i">3</span> ; k &lt; <span class="i">32</span> ; ++k)
</pre></td></tr>


<tr><th class="line-num" id="L413"><a href="#L413">413</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L414"><a href="#L414">414</a></th><td class="line-code"><pre>            close(k);
</pre></td></tr>


<tr><th class="line-num" id="L415"><a href="#L415">415</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L416"><a href="#L416">416</a></th><td class="line-code"><pre>        <span class="c">// Execute the process on the local machine.</span>
</pre></td></tr>


<tr><th class="line-num" id="L417"><a href="#L417">417</a></th><td class="line-code"><pre>        remoteProgram = FileFunctions::ExpandPath(remoteProgram);
</pre></td></tr>


<tr><th class="line-num" id="L418"><a href="#L418">418</a></th><td class="line-code"><pre>        execvp(remoteProgram.c_str(), args);
</pre></td></tr>


<tr><th class="line-num" id="L419"><a href="#L419">419</a></th><td class="line-code"><pre>        exit(-<span class="i">1</span>); <span class="c">// HOOKS_IGNORE</span>
</pre></td></tr>


<tr><th class="line-num" id="L420"><a href="#L420">420</a></th><td class="line-code"><pre>        <span class="r">break</span>;   <span class="c">// OCD</span>
</pre></td></tr>


<tr><th class="line-num" id="L421"><a href="#L421">421</a></th><td class="line-code"><pre>    <span class="r">default</span>:
</pre></td></tr>


<tr><th class="line-num" id="L422"><a href="#L422">422</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> CAPTURE_CHILD_OUTPUT
</pre></td></tr>


<tr><th class="line-num" id="L423"><a href="#L423">423</a></th><td class="line-code"><pre>        <span class="r">if</span>(readOutput)
</pre></td></tr>


<tr><th class="line-num" id="L424"><a href="#L424">424</a></th><td class="line-code"><pre>            close(f_des[<span class="i">1</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L425"><a href="#L425">425</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L426"><a href="#L426">426</a></th><td class="line-code"><pre>        <span class="r">break</span>;
</pre></td></tr>


<tr><th class="line-num" id="L427"><a href="#L427">427</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L428"><a href="#L428">428</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L429"><a href="#L429">429</a></th><td class="line-code"><pre>    <span class="c">// Stop watching for dead children</span>
</pre></td></tr>


<tr><th class="line-num" id="L430"><a href="#L430">430</a></th><td class="line-code"><pre>    signal(SIGCHLD, SIG_DFL);
</pre></td></tr>


<tr><th class="line-num" id="L431"><a href="#L431">431</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L432"><a href="#L432">432</a></th><td class="line-code"><pre>    <span class="c">// If we had a dead child, try and connect back to the client that</span>
</pre></td></tr>


<tr><th class="line-num" id="L433"><a href="#L433">433</a></th><td class="line-code"><pre>    <span class="c">// wanted to connect to the dead child.</span>
</pre></td></tr>


<tr><th class="line-num" id="L434"><a href="#L434">434</a></th><td class="line-code"><pre>    <span class="r">if</span>(childDied[remoteProgramPid])
</pre></td></tr>


<tr><th class="line-num" id="L435"><a href="#L435">435</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L436"><a href="#L436">436</a></th><td class="line-code"><pre>        <span class="c">// Create a temp array of pointers to the strings that we</span>
</pre></td></tr>


<tr><th class="line-num" id="L437"><a href="#L437">437</a></th><td class="line-code"><pre>        <span class="c">// created and pass the temp array to the TerminateConnectionRequest</span>
</pre></td></tr>


<tr><th class="line-num" id="L438"><a href="#L438">438</a></th><td class="line-code"><pre>        <span class="c">// method because it creates a ParentProcess object that will</span>
</pre></td></tr>


<tr><th class="line-num" id="L439"><a href="#L439">439</a></th><td class="line-code"><pre>        <span class="c">// rearrange the pointers in the array.</span>
</pre></td></tr>


<tr><th class="line-num" id="L440"><a href="#L440">440</a></th><td class="line-code"><pre>        <span class="pt">char</span> **args2 = new <span class="pt">char</span> *[launchArgs.size() + <span class="i">1</span>];
</pre></td></tr>


<tr><th class="line-num" id="L441"><a href="#L441">441</a></th><td class="line-code"><pre>        <span class="r">for</span>(size_t i = <span class="i">0</span>; i &lt; launchArgs.size(); ++i)
</pre></td></tr>


<tr><th class="line-num" id="L442"><a href="#L442">442</a></th><td class="line-code"><pre>            args2[i] = args[i];
</pre></td></tr>


<tr><th class="line-num" id="L443"><a href="#L443">443</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L444"><a href="#L444">444</a></th><td class="line-code"><pre>        <span class="c">// Tell the client that we could not connect.</span>
</pre></td></tr>


<tr><th class="line-num" id="L445"><a href="#L445">445</a></th><td class="line-code"><pre>        TerminateConnectionRequest(launchArgs.size(), args2);
</pre></td></tr>


<tr><th class="line-num" id="L446"><a href="#L446">446</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L447"><a href="#L447">447</a></th><td class="line-code"><pre>        delete [] args2;
</pre></td></tr>


<tr><th class="line-num" id="L448"><a href="#L448">448</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L449"><a href="#L449">449</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> CAPTURE_CHILD_OUTPUT
</pre></td></tr>


<tr><th class="line-num" id="L450"><a href="#L450">450</a></th><td class="line-code"><pre>    <span class="r">else</span> <span class="r">if</span>(readOutput)
</pre></td></tr>


<tr><th class="line-num" id="L451"><a href="#L451">451</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L452"><a href="#L452">452</a></th><td class="line-code"><pre>        <span class="c">// Add the child's output pipe to the list of descriptors that</span>
</pre></td></tr>


<tr><th class="line-num" id="L453"><a href="#L453">453</a></th><td class="line-code"><pre>        <span class="c">// we will check. We add the pipe file descriptor as a </span>
</pre></td></tr>


<tr><th class="line-num" id="L454"><a href="#L454">454</a></th><td class="line-code"><pre>        <span class="c">// SocketConnection object.</span>
</pre></td></tr>


<tr><th class="line-num" id="L455"><a href="#L455">455</a></th><td class="line-code"><pre>        *conn = new SocketConnection(f_des[<span class="i">0</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L456"><a href="#L456">456</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L457"><a href="#L457">457</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L458"><a href="#L458">458</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L459"><a href="#L459">459</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L460"><a href="#L460">460</a></th><td class="line-code"><pre>    <span class="c">// Free the command line storage.</span>
</pre></td></tr>


<tr><th class="line-num" id="L461"><a href="#L461">461</a></th><td class="line-code"><pre>    <span class="r">for</span>(size_t i = <span class="i">0</span>; i &lt; launchArgs.size(); ++i)
</pre></td></tr>


<tr><th class="line-num" id="L462"><a href="#L462">462</a></th><td class="line-code"><pre>        delete [] args[i];
</pre></td></tr>


<tr><th class="line-num" id="L463"><a href="#L463">463</a></th><td class="line-code"><pre>    delete [] args;
</pre></td></tr>


<tr><th class="line-num" id="L464"><a href="#L464">464</a></th><td class="line-code"><pre>    debug1 &lt;&lt; mName &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">end</span><span class="dl">&quot;</span></span> &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L465"><a href="#L465">465</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L466"><a href="#L466">466</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L467"><a href="#L467">467</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L468"><a href="#L468">468</a></th><td class="line-code"><pre><span class="c">// Method: LaunchService::TerminateConnectionRequest</span>
</pre></td></tr>


<tr><th class="line-num" id="L469"><a href="#L469">469</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L470"><a href="#L470">470</a></th><td class="line-code"><pre><span class="c">// Purpose: </span>
</pre></td></tr>


<tr><th class="line-num" id="L471"><a href="#L471">471</a></th><td class="line-code"><pre><span class="c">//   Tells the client that we could not launch the desired process. This</span>
</pre></td></tr>


<tr><th class="line-num" id="L472"><a href="#L472">472</a></th><td class="line-code"><pre><span class="c">//   lets the client fail gracefully instead of hang.</span>
</pre></td></tr>


<tr><th class="line-num" id="L473"><a href="#L473">473</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L474"><a href="#L474">474</a></th><td class="line-code"><pre><span class="c">// Arguments:</span>
</pre></td></tr>


<tr><th class="line-num" id="L475"><a href="#L475">475</a></th><td class="line-code"><pre><span class="c">//   argc : The number of arguments in argv.</span>
</pre></td></tr>


<tr><th class="line-num" id="L476"><a href="#L476">476</a></th><td class="line-code"><pre><span class="c">//   argv : The argument array used to connect back to the client.</span>
</pre></td></tr>


<tr><th class="line-num" id="L477"><a href="#L477">477</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L478"><a href="#L478">478</a></th><td class="line-code"><pre><span class="c">// Programmer: Brad Whitlock</span>
</pre></td></tr>


<tr><th class="line-num" id="L479"><a href="#L479">479</a></th><td class="line-code"><pre><span class="c">// Creation:   Mon May 5 11:46:35 PDT 2003</span>
</pre></td></tr>


<tr><th class="line-num" id="L480"><a href="#L480">480</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L481"><a href="#L481">481</a></th><td class="line-code"><pre><span class="c">// Modifications:</span>
</pre></td></tr>


<tr><th class="line-num" id="L482"><a href="#L482">482</a></th><td class="line-code"><pre><span class="c">//   Brad Whitlock, Tue Jul 29 11:39:03 PDT 2003</span>
</pre></td></tr>


<tr><th class="line-num" id="L483"><a href="#L483">483</a></th><td class="line-code"><pre><span class="c">//   Changed interface to ParentProcess::Connect.</span>
</pre></td></tr>


<tr><th class="line-num" id="L484"><a href="#L484">484</a></th><td class="line-code"><pre><span class="c">//</span>
</pre></td></tr>


<tr><th class="line-num" id="L485"><a href="#L485">485</a></th><td class="line-code"><pre><span class="c">//   Mark C. Miller, Wed Jun 17 14:27:08 PDT 2009</span>
</pre></td></tr>


<tr><th class="line-num" id="L486"><a href="#L486">486</a></th><td class="line-code"><pre><span class="c">//   Replaced CATCHALL(...) with CATCHALL.</span>
</pre></td></tr>


<tr><th class="line-num" id="L487"><a href="#L487">487</a></th><td class="line-code"><pre><span class="c">// ****************************************************************************</span>
</pre></td></tr>


<tr><th class="line-num" id="L488"><a href="#L488">488</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L489"><a href="#L489">489</a></th><td class="line-code"><pre><span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L490"><a href="#L490">490</a></th><td class="line-code"><pre>LaunchService::TerminateConnectionRequest(<span class="pt">int</span> argc, <span class="pt">char</span> *argv[])
</pre></td></tr>


<tr><th class="line-num" id="L491"><a href="#L491">491</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L492"><a href="#L492">492</a></th><td class="line-code"><pre>    <span class="c">// Try and connect back to the process that initiated the request and</span>
</pre></td></tr>


<tr><th class="line-num" id="L493"><a href="#L493">493</a></th><td class="line-code"><pre>    <span class="c">// send it a non-zero fail code so it will terminate the connection.</span>
</pre></td></tr>


<tr><th class="line-num" id="L494"><a href="#L494">494</a></th><td class="line-code"><pre>    TRY
</pre></td></tr>


<tr><th class="line-num" id="L495"><a href="#L495">495</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L496"><a href="#L496">496</a></th><td class="line-code"><pre>        debug1 &lt;&lt; <span class="s"><span class="dl">&quot;</span><span class="k">Terminating connection request to the client.</span><span class="dl">&quot;</span></span> &lt;&lt; endl;
</pre></td></tr>


<tr><th class="line-num" id="L497"><a href="#L497">497</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L498"><a href="#L498">498</a></th><td class="line-code"><pre>        ParentProcess killer;
</pre></td></tr>


<tr><th class="line-num" id="L499"><a href="#L499">499</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L500"><a href="#L500">500</a></th><td class="line-code"><pre>        <span class="c">// Connect back to the process and say that we could not connect.</span>
</pre></td></tr>


<tr><th class="line-num" id="L501"><a href="#L501">501</a></th><td class="line-code"><pre>        killer.Connect(<span class="i">1</span>, <span class="i">1</span>, &amp;argc, &amp;argv, <span class="pc">true</span>, <span class="i">3</span>);
</pre></td></tr>


<tr><th class="line-num" id="L502"><a href="#L502">502</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L503"><a href="#L503">503</a></th><td class="line-code"><pre>    CATCHALL
</pre></td></tr>


<tr><th class="line-num" id="L504"><a href="#L504">504</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L505"><a href="#L505">505</a></th><td class="line-code"><pre>        <span class="c">// We know that we're going to get here, but no action is required.</span>
</pre></td></tr>


<tr><th class="line-num" id="L506"><a href="#L506">506</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L507"><a href="#L507">507</a></th><td class="line-code"><pre>    ENDTRY
</pre></td></tr>


<tr><th class="line-num" id="L508"><a href="#L508">508</a></th><td class="line-code"><pre>}
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
