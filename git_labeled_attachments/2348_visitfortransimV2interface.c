<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - visitfortransimV2interface.c - VisIt Bugs</title>
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
				
        <h2>visitfortransimV2interface.c</h2>

<div class="attachments">
<p>
   <span class="author">Jens Henrik Goebbert, 11/02/2015 11:06 am</span></p>
<p><a href="/attachments/download/361/visitfortransimV2interface.c">Download</a>   <span class="size">(65.5 KB)</span></p>

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


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;stdio.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;stdlib.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;string.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;VisItControlInterface_V2.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &quot;VisItFortran.h&quot;</span>
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre><span class="c">/* Data Access function prototypes. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre><span class="pt">int</span> VisItActivateTimestep(<span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>visit_handle VisItGetMetaData(<span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>visit_handle VisItGetMesh(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>visit_handle VisItGetMaterial(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>visit_handle VisItGetVariable(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>visit_handle VisItGetMixedVariable(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>visit_handle VisItGetCurve(<span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>visit_handle VisItGetDomainList(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>visit_handle VisItGetDomainBoundaries(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>visit_handle VisItGetDomainNesting(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">void</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre> ********* CONTROL INTERFACE FUNCTIONS
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre><span class="c">/*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre> **** THESE ARE CALLBACK FUNCTIONS WE REGISTER WITH THE CONTROL INTERFACE
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre> **** SO IT CAN PERFORM SIMULATION-SPECIFIC ACTIONS. WE HAVE THESE HERE SO
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre> **** WE CAN CALL INTO FORTRAN WHERE THE FUNCTIONS WILL BE DEFINED.
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre><span class="c">/* Functions to be provided by the FORTRAN simulation. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSLAVEPROCESSCALLBACK    F77_ID(visitslaveprocesscallback_,visitslaveprocesscallback,VISITSLAVEPROCESSCALLBACK)
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITBROADCASTINTFUNCTION    F77_ID(visitbroadcastintfunction_,visitbroadcastintfunction,VISITBROADCASTINTFUNCTION)
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITBROADCASTSTRINGFUNCTION F77_ID(visitbroadcaststringfunction_,visitbroadcaststringfunction,VISITBROADCASTSTRINGFUNCTION)
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITCOMMANDCALLBACK         F77_ID(visitcommandcallback_,visitcommandcallback,VISITCOMMANDCALLBACK)
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">void</span> F_VISITSLAVEPROCESSCALLBACK(<span class="pt">void</span>);
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span>  F_VISITBROADCASTINTFUNCTION(<span class="pt">int</span> *, <span class="pt">int</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span>  F_VISITBROADCASTSTRINGFUNCTION(<span class="pt">char</span> *, <span class="pt">int</span> *, <span class="pt">int</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">void</span> F_VISITCOMMANDCALLBACK(<span class="r">const</span> <span class="pt">char</span>*, <span class="pt">int</span>*, <span class="r">const</span> <span class="pt">char</span>*, <span class="pt">int</span> *);
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre><span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>f_visit_internal_slaveprocesscallback(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>    <span class="c">/* Call the fortran function. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre>    F_VISITSLAVEPROCESSCALLBACK();
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre><span class="pt">int</span>
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>f_visit_internal_broadcastintfunction(<span class="pt">int</span> *value, <span class="pt">int</span> sender)
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>    <span class="c">/* Call the fortran function. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITBROADCASTINTFUNCTION(value, &amp;sender);
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre><span class="pt">int</span>
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>f_visit_internal_broadcaststringfunction(<span class="pt">char</span> *str, <span class="pt">int</span> lstr, <span class="pt">int</span> sender)
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre>    <span class="c">/* Call the fortran function. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITBROADCASTSTRINGFUNCTION(str, &amp;lstr, &amp;sender);
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre><span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre>f_visit_internal_commandcallback(<span class="r">const</span> <span class="pt">char</span> *cmd, <span class="r">const</span> <span class="pt">char</span> *stringdata, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre>    <span class="c">/* Call the fortran function. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre>    <span class="pt">char</span> *realcmd = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre>    <span class="pt">int</span> lcmd;
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre>    <span class="pt">int</span> lstringdata = strlen(stringdata);
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>    <span class="c">/* See if the format of the message from the viewer contains a bunch of
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>     * Qt signal junk that has been added for new features. If that junk is
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>     * present and is for a push button then strip it out and send the
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>     * command string to the simulation for processing. Otherwise, pass along
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>     * the unmodified message.
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre>     */</span>
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre>    <span class="r">if</span>(strncmp(cmd, <span class="s"><span class="dl">&quot;</span><span class="k">clicked();</span><span class="dl">&quot;</span></span>, <span class="i">10</span>) == <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre>        <span class="pt">char</span> *end = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre>        <span class="r">if</span>((end = strstr(cmd, <span class="s"><span class="dl">&quot;</span><span class="k">;QPushButton;Simulations;NONE</span><span class="dl">&quot;</span></span>)) != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre>            lcmd = end - cmd - <span class="i">10</span>;
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre>            realcmd = ALLOC(<span class="pt">char</span>, lcmd + <span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre>            memset(realcmd, <span class="i">0</span>, lcmd + <span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre>            strncpy(realcmd, cmd + <span class="i">10</span>, lcmd);
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>    <span class="r">if</span>(realcmd == <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>        lcmd = strlen(cmd);
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>        realcmd = ALLOC(<span class="pt">char</span>, lcmd + <span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre>        strcpy(realcmd, cmd);
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre>    F_VISITCOMMANDCALLBACK(realcmd, &amp;lcmd, stringdata, &amp;lstringdata);
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre>    FREE(realcmd);
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre><span class="r">static</span> <span class="pt">void</span>
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre>f_visit_internal_InstallCallbacks(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre>    VisItSetActivateTimestep(VisItActivateTimestep, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre>    VisItSetGetMetaData(VisItGetMetaData, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre>    VisItSetGetMesh(VisItGetMesh, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>    VisItSetGetMaterial(VisItGetMaterial, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre>    VisItSetGetVariable(VisItGetVariable, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>    VisItSetGetMixedVariable(VisItGetMixedVariable, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>    VisItSetGetCurve(VisItGetCurve, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre>    VisItSetGetDomainList(VisItGetDomainList, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>    VisItSetGetDomainBoundaries(VisItGetDomainBoundaries, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>    VisItSetGetDomainNesting(VisItGetDomainNesting, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>    <span class="c">/* These functions need to be set up but they can't be set up until
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>     * after the VisItAttemptToCompleteConnection function completes.
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>     */</span>
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>    VisItSetSlaveProcessCallback(f_visit_internal_slaveprocesscallback);
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre>    VisItSetCommandCallback(f_visit_internal_commandcallback, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre><span class="c">/*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre> **** THESE ARE FORTRAN WRAPPERS FOR THE SIMULATION CONTROL INTERFACE
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITATTEMPTCONNECTION    F77_ID(visitattemptconnection_,visitattemptconnection,VISITATTEMPTCONNECTION)
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITCLOSETRACEFILE       F77_ID(visitclosetracefile_,visitclosetracefile,VISITCLOSETRACEFILE)
</pre></td></tr>


<tr><th class="line-num" id="L189"><a href="#L189">189</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDEBUG1               F77_ID(visitdebug1_,visitdebug1,VISITDEBUG1)
</pre></td></tr>


<tr><th class="line-num" id="L190"><a href="#L190">190</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDEBUG2               F77_ID(visitdebug2_,visitdebug2,VISITDEBUG2)
</pre></td></tr>


<tr><th class="line-num" id="L191"><a href="#L191">191</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDEBUG3               F77_ID(visitdebug3_,visitdebug3,VISITDEBUG3)
</pre></td></tr>


<tr><th class="line-num" id="L192"><a href="#L192">192</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDEBUG4               F77_ID(visitdebug4_,visitdebug4,VISITDEBUG4)
</pre></td></tr>


<tr><th class="line-num" id="L193"><a href="#L193">193</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDEBUG5               F77_ID(visitdebug5_,visitdebug5,VISITDEBUG5)
</pre></td></tr>


<tr><th class="line-num" id="L194"><a href="#L194">194</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDETECTINPUT          F77_ID(visitdetectinput_,visitdetectinput,VISITDETECTINPUT)
</pre></td></tr>


<tr><th class="line-num" id="L195"><a href="#L195">195</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDETECTINPUTWITHTIMEOUT F77_ID(visitdetectinputwithtimeout_,visitdetectinputwithtimeout,VISITDETECTINPUTWITHTIMEOUT)
</pre></td></tr>


<tr><th class="line-num" id="L196"><a href="#L196">196</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDISCONNECT           F77_ID(visitdisconnect_,visitdisconnect,VISITDISCONNECT)
</pre></td></tr>


<tr><th class="line-num" id="L197"><a href="#L197">197</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITENABLESYNCHRONIZE    F77_ID(visitenablesynchronize_,visitenablesynchronize,VISITENABLESYNCHRONIZE)
</pre></td></tr>


<tr><th class="line-num" id="L198"><a href="#L198">198</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITEXECUTECOMMAND       F77_ID(visitexecutecommand_,visitexecutecommand,VISITEXECUTECOMMAND)
</pre></td></tr>


<tr><th class="line-num" id="L199"><a href="#L199">199</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETLASTERROR         F77_ID(visitgetlasterror_,visitgetlasterror,VISITGETLASTERROR)
</pre></td></tr>


<tr><th class="line-num" id="L200"><a href="#L200">200</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETSOCKETS           F77_ID(visitgetsockets_,visitgetsockets,VISITGETSOCKETS)
</pre></td></tr>


<tr><th class="line-num" id="L201"><a href="#L201">201</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITINITIALIZESIM        F77_ID(visitinitializesim_,visitinitializesim,VISITINITIALIZESIM)
</pre></td></tr>


<tr><th class="line-num" id="L202"><a href="#L202">202</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITISCONNECTED          F77_ID(visitisconnected_,visitisconnected,VISITISCONNECTED)
</pre></td></tr>


<tr><th class="line-num" id="L203"><a href="#L203">203</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITOPENTRACEFILE        F77_ID(visitopentracefile_,visitopentracefile,VISITOPENTRACEFILE)
</pre></td></tr>


<tr><th class="line-num" id="L204"><a href="#L204">204</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITPROCESSENGINECOMMAND F77_ID(visitprocessenginecommand_,visitprocessenginecommand,VISITPROCESSENGINECOMMAND)
</pre></td></tr>


<tr><th class="line-num" id="L205"><a href="#L205">205</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSAVEWINDOW           F77_ID(visitsavewindow_,visitsavewindow,VISITSAVEWINDOW)
</pre></td></tr>


<tr><th class="line-num" id="L206"><a href="#L206">206</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETDIRECTORY         F77_ID(visitsetdirectory_,visitsetdirectory,VISITSETDIRECTORY)
</pre></td></tr>


<tr><th class="line-num" id="L207"><a href="#L207">207</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETMPICOMMUNICATOR   F77_ID(visitsetmpicommunicator_,visitsetmpicommunicator,VISITSETMPICOMMUNICATOR)
</pre></td></tr>


<tr><th class="line-num" id="L208"><a href="#L208">208</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPTIONS           F77_ID(visitsetoptions_,visitsetoptions,VISITSETOPTIONS)
</pre></td></tr>


<tr><th class="line-num" id="L209"><a href="#L209">209</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPARALLEL          F77_ID(visitsetparallel_,visitsetparallel,VISITSETPARALLEL)
</pre></td></tr>


<tr><th class="line-num" id="L210"><a href="#L210">210</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPARALLELRANK      F77_ID(visitsetparallelrank_,visitsetparallelrank,VISITSETPARALLELRANK)
</pre></td></tr>


<tr><th class="line-num" id="L211"><a href="#L211">211</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETUPENV             F77_ID(visitsetupenv_,visitsetupenv,VISITSETUPENV)
</pre></td></tr>


<tr><th class="line-num" id="L212"><a href="#L212">212</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETUPENV2            F77_ID(visitsetupenv2_,visitsetupenv2,VISITSETUPENV2)
</pre></td></tr>


<tr><th class="line-num" id="L213"><a href="#L213">213</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETENV               F77_ID(visitgetenv_,visitgetenv,VISITGETENV)
</pre></td></tr>


<tr><th class="line-num" id="L214"><a href="#L214">214</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSYNCHRONIZE          F77_ID(visitsynchronize_,visitsynchronize,VISITSYNCHRONIZE)
</pre></td></tr>


<tr><th class="line-num" id="L215"><a href="#L215">215</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITTIMESTEPCHANGED      F77_ID(visittimestepchanged_,visittimestepchanged,VISITTIMESTEPCHANGED)
</pre></td></tr>


<tr><th class="line-num" id="L216"><a href="#L216">216</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITUPDATEPLOTS          F77_ID(visitupdateplots_,visitupdateplots,VISITUPDATEPLOTS)
</pre></td></tr>


<tr><th class="line-num" id="L217"><a href="#L217">217</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L218"><a href="#L218">218</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITINITIALIZERUNTIME    F77_ID(visitinitializeruntime_,visitinitializeruntime,VISITINITIALIZERUNTIME)
</pre></td></tr>


<tr><th class="line-num" id="L219"><a href="#L219">219</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITADDPLOT              F77_ID(visitaddplot_,visitaddplot,VISITADDPLOT)
</pre></td></tr>


<tr><th class="line-num" id="L220"><a href="#L220">220</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITADDOPERATOR          F77_ID(visitaddoperator_,visitaddoperator,VISITADDOPERATOR)
</pre></td></tr>


<tr><th class="line-num" id="L221"><a href="#L221">221</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDRAWPLOTS            F77_ID(visitdrawplots_,visitdrawplots,VISITDRAWPLOTS)
</pre></td></tr>


<tr><th class="line-num" id="L222"><a href="#L222">222</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITDELETEACTIVEPLOTS    F77_ID(visitdeleteactiveplots_,visitdeleteactiveplots,VISITDELETEACTIVEPLOTS)
</pre></td></tr>


<tr><th class="line-num" id="L223"><a href="#L223">223</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETACTIVEPLOTS       F77_ID(visitsetactiveplots_,visitsetactiveplots,VISITSETACTIVEPLOTS)
</pre></td></tr>


<tr><th class="line-num" id="L224"><a href="#L224">224</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETMEMORY            F77_ID(visitgetmemory_,visitgetmemory,VISITGETMEMORY)
</pre></td></tr>


<tr><th class="line-num" id="L225"><a href="#L225">225</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITEXPORTDATABASE       F77_ID(visitexportdatabase_,visitexportdatabase,VISITEXPORTDATABASE)
</pre></td></tr>


<tr><th class="line-num" id="L226"><a href="#L226">226</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITEXPORTDATABASEWITHOPTIONS       F77_ID(visitexportdatabasewithoptions_,visitexportdatabasewithoptions,VISITEXPORTDATABASEWITHOPTIONS)
</pre></td></tr>


<tr><th class="line-num" id="L227"><a href="#L227">227</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITRESTORESESSION       F77_ID(visitrestoresession_,visitrestoresession,VISITRESTORESESSION)
</pre></td></tr>


<tr><th class="line-num" id="L228"><a href="#L228">228</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L229"><a href="#L229">229</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L230"><a href="#L230">230</a></th><td class="line-code"><pre> * Function: F_VISITSETDIRECTORY
</pre></td></tr>


<tr><th class="line-num" id="L231"><a href="#L231">231</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L232"><a href="#L232">232</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the directory.
</pre></td></tr>


<tr><th class="line-num" id="L233"><a href="#L233">233</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L234"><a href="#L234">234</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L235"><a href="#L235">235</a></th><td class="line-code"><pre> *   dir  : Fortran string containing the directory.
</pre></td></tr>


<tr><th class="line-num" id="L236"><a href="#L236">236</a></th><td class="line-code"><pre> *   ldir : Length of the directory string.
</pre></td></tr>


<tr><th class="line-num" id="L237"><a href="#L237">237</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L238"><a href="#L238">238</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L239"><a href="#L239">239</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L240"><a href="#L240">240</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L241"><a href="#L241">241</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L242"><a href="#L242">242</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L243"><a href="#L243">243</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L244"><a href="#L244">244</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L245"><a href="#L245">245</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L246"><a href="#L246">246</a></th><td class="line-code"><pre>F_VISITSETDIRECTORY(VISIT_F77STRING dir, VISIT_F77_MIXED_STRLEN(dir) <span class="pt">int</span> *ldir VISIT_F77_END_STRLEN(dir))
</pre></td></tr>


<tr><th class="line-num" id="L247"><a href="#L247">247</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L248"><a href="#L248">248</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_dir = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L249"><a href="#L249">249</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_dir, dir, ldir);
</pre></td></tr>


<tr><th class="line-num" id="L250"><a href="#L250">250</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L251"><a href="#L251">251</a></th><td class="line-code"><pre>    VisItSetDirectory(f_dir);
</pre></td></tr>


<tr><th class="line-num" id="L252"><a href="#L252">252</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L253"><a href="#L253">253</a></th><td class="line-code"><pre>    FREE(f_dir);
</pre></td></tr>


<tr><th class="line-num" id="L254"><a href="#L254">254</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L255"><a href="#L255">255</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L256"><a href="#L256">256</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L257"><a href="#L257">257</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L258"><a href="#L258">258</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L259"><a href="#L259">259</a></th><td class="line-code"><pre> * Function: F_VISITSETMPICOMMUNICATOR
</pre></td></tr>


<tr><th class="line-num" id="L260"><a href="#L260">260</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L261"><a href="#L261">261</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the MPI communicator.
</pre></td></tr>


<tr><th class="line-num" id="L262"><a href="#L262">262</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L263"><a href="#L263">263</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L264"><a href="#L264">264</a></th><td class="line-code"><pre> *   comm : An int representing the communicator. Really the address of the
</pre></td></tr>


<tr><th class="line-num" id="L265"><a href="#L265">265</a></th><td class="line-code"><pre> *          communicator.
</pre></td></tr>


<tr><th class="line-num" id="L266"><a href="#L266">266</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L267"><a href="#L267">267</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L268"><a href="#L268">268</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L269"><a href="#L269">269</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L270"><a href="#L270">270</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L271"><a href="#L271">271</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L272"><a href="#L272">272</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L273"><a href="#L273">273</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L274"><a href="#L274">274</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L275"><a href="#L275">275</a></th><td class="line-code"><pre>F_VISITSETMPICOMMUNICATOR(<span class="pt">int</span> *comm)
</pre></td></tr>


<tr><th class="line-num" id="L276"><a href="#L276">276</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L277"><a href="#L277">277</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret = VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L278"><a href="#L278">278</a></th><td class="line-code"><pre>    <span class="r">if</span>(comm != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L279"><a href="#L279">279</a></th><td class="line-code"><pre>        ret = VisItSetMPICommunicator_f(comm);
</pre></td></tr>


<tr><th class="line-num" id="L280"><a href="#L280">280</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L281"><a href="#L281">281</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L282"><a href="#L282">282</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L283"><a href="#L283">283</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L284"><a href="#L284">284</a></th><td class="line-code"><pre> * Function: F_VISITSETOPTIONS
</pre></td></tr>


<tr><th class="line-num" id="L285"><a href="#L285">285</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L286"><a href="#L286">286</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the options.
</pre></td></tr>


<tr><th class="line-num" id="L287"><a href="#L287">287</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L288"><a href="#L288">288</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L289"><a href="#L289">289</a></th><td class="line-code"><pre> *   dir  : Fortran string containing the options.
</pre></td></tr>


<tr><th class="line-num" id="L290"><a href="#L290">290</a></th><td class="line-code"><pre> *   ldir : Length of the options string.
</pre></td></tr>


<tr><th class="line-num" id="L291"><a href="#L291">291</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L292"><a href="#L292">292</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L293"><a href="#L293">293</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L294"><a href="#L294">294</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L295"><a href="#L295">295</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L296"><a href="#L296">296</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L297"><a href="#L297">297</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L298"><a href="#L298">298</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L299"><a href="#L299">299</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L300"><a href="#L300">300</a></th><td class="line-code"><pre>F_VISITSETOPTIONS(VISIT_F77STRING opt VISIT_F77_MIXED_STRLEN(opt), <span class="pt">int</span> *lopt VISIT_F77_END_STRLEN(opt))
</pre></td></tr>


<tr><th class="line-num" id="L301"><a href="#L301">301</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L302"><a href="#L302">302</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_opt = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L303"><a href="#L303">303</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_opt, opt, lopt);
</pre></td></tr>


<tr><th class="line-num" id="L304"><a href="#L304">304</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L305"><a href="#L305">305</a></th><td class="line-code"><pre>    VisItSetOptions(f_opt);
</pre></td></tr>


<tr><th class="line-num" id="L306"><a href="#L306">306</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L307"><a href="#L307">307</a></th><td class="line-code"><pre>    FREE(f_opt);
</pre></td></tr>


<tr><th class="line-num" id="L308"><a href="#L308">308</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L309"><a href="#L309">309</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L310"><a href="#L310">310</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L311"><a href="#L311">311</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L312"><a href="#L312">312</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L313"><a href="#L313">313</a></th><td class="line-code"><pre> * Function: F_VISITOPENTRACEFILE
</pre></td></tr>


<tr><th class="line-num" id="L314"><a href="#L314">314</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L315"><a href="#L315">315</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to open a trace file for debugging libsim.
</pre></td></tr>


<tr><th class="line-num" id="L316"><a href="#L316">316</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L317"><a href="#L317">317</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L318"><a href="#L318">318</a></th><td class="line-code"><pre> *   dir  : Fortran string containing the options.
</pre></td></tr>


<tr><th class="line-num" id="L319"><a href="#L319">319</a></th><td class="line-code"><pre> *   ldir : Length of the options string.
</pre></td></tr>


<tr><th class="line-num" id="L320"><a href="#L320">320</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L321"><a href="#L321">321</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L322"><a href="#L322">322</a></th><td class="line-code"><pre> * Date:       Fri Feb 19 15:47:02 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L323"><a href="#L323">323</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L324"><a href="#L324">324</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L325"><a href="#L325">325</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L326"><a href="#L326">326</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L327"><a href="#L327">327</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L328"><a href="#L328">328</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L329"><a href="#L329">329</a></th><td class="line-code"><pre>F_VISITOPENTRACEFILE(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L330"><a href="#L330">330</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L331"><a href="#L331">331</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L332"><a href="#L332">332</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L333"><a href="#L333">333</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L334"><a href="#L334">334</a></th><td class="line-code"><pre>    VisItOpenTraceFile(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L335"><a href="#L335">335</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L336"><a href="#L336">336</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L337"><a href="#L337">337</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L338"><a href="#L338">338</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L339"><a href="#L339">339</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L340"><a href="#L340">340</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L341"><a href="#L341">341</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L342"><a href="#L342">342</a></th><td class="line-code"><pre> * Function: F_VISITCLOSETRACEFILE
</pre></td></tr>


<tr><th class="line-num" id="L343"><a href="#L343">343</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L344"><a href="#L344">344</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to close the trace file.
</pre></td></tr>


<tr><th class="line-num" id="L345"><a href="#L345">345</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L346"><a href="#L346">346</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L347"><a href="#L347">347</a></th><td class="line-code"><pre> * Date:       Fri Feb 19 15:47:02 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L348"><a href="#L348">348</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L349"><a href="#L349">349</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L350"><a href="#L350">350</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L351"><a href="#L351">351</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L352"><a href="#L352">352</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L353"><a href="#L353">353</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L354"><a href="#L354">354</a></th><td class="line-code"><pre>F_VISITCLOSETRACEFILE(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L355"><a href="#L355">355</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L356"><a href="#L356">356</a></th><td class="line-code"><pre>    VisItCloseTraceFile();
</pre></td></tr>


<tr><th class="line-num" id="L357"><a href="#L357">357</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L358"><a href="#L358">358</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L359"><a href="#L359">359</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L360"><a href="#L360">360</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L361"><a href="#L361">361</a></th><td class="line-code"><pre> * Function: F_VISITSETUPENV
</pre></td></tr>


<tr><th class="line-num" id="L362"><a href="#L362">362</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L363"><a href="#L363">363</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to setup the VisIt environment variables.
</pre></td></tr>


<tr><th class="line-num" id="L364"><a href="#L364">364</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L365"><a href="#L365">365</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L366"><a href="#L366">366</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L367"><a href="#L367">367</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L368"><a href="#L368">368</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L369"><a href="#L369">369</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L370"><a href="#L370">370</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L371"><a href="#L371">371</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L372"><a href="#L372">372</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L373"><a href="#L373">373</a></th><td class="line-code"><pre>F_VISITSETUPENV(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L374"><a href="#L374">374</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L375"><a href="#L375">375</a></th><td class="line-code"><pre>    VisItSetupEnvironment();
</pre></td></tr>


<tr><th class="line-num" id="L376"><a href="#L376">376</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L377"><a href="#L377">377</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L378"><a href="#L378">378</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L379"><a href="#L379">379</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L380"><a href="#L380">380</a></th><td class="line-code"><pre> * Function: F_VISITSETUPENV2
</pre></td></tr>


<tr><th class="line-num" id="L381"><a href="#L381">381</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L382"><a href="#L382">382</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to setup the VisIt environment variables.
</pre></td></tr>


<tr><th class="line-num" id="L383"><a href="#L383">383</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L384"><a href="#L384">384</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L385"><a href="#L385">385</a></th><td class="line-code"><pre> * Date:       Tue Jun  4 09:27:04 PDT 2013
</pre></td></tr>


<tr><th class="line-num" id="L386"><a href="#L386">386</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L387"><a href="#L387">387</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L388"><a href="#L388">388</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L389"><a href="#L389">389</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L390"><a href="#L390">390</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L391"><a href="#L391">391</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L392"><a href="#L392">392</a></th><td class="line-code"><pre>F_VISITSETUPENV2(VISIT_F77STRING env VISIT_F77_MIXED_STRLEN(env), <span class="pt">int</span> *lenv VISIT_F77_END_STRLEN(env))
</pre></td></tr>


<tr><th class="line-num" id="L393"><a href="#L393">393</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L394"><a href="#L394">394</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L395"><a href="#L395">395</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_env = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L396"><a href="#L396">396</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_env, env, lenv);
</pre></td></tr>


<tr><th class="line-num" id="L397"><a href="#L397">397</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L398"><a href="#L398">398</a></th><td class="line-code"><pre>    ret = VisItSetupEnvironment2(f_env);
</pre></td></tr>


<tr><th class="line-num" id="L399"><a href="#L399">399</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L400"><a href="#L400">400</a></th><td class="line-code"><pre>    FREE(f_env);
</pre></td></tr>


<tr><th class="line-num" id="L401"><a href="#L401">401</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L402"><a href="#L402">402</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L403"><a href="#L403">403</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L404"><a href="#L404">404</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L405"><a href="#L405">405</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L406"><a href="#L406">406</a></th><td class="line-code"><pre> * Function: F_VISITGETENV
</pre></td></tr>


<tr><th class="line-num" id="L407"><a href="#L407">407</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L408"><a href="#L408">408</a></th><td class="line-code"><pre> * Purpose:   Get the VisIt environment variables as a buffer that can be passed
</pre></td></tr>


<tr><th class="line-num" id="L409"><a href="#L409">409</a></th><td class="line-code"><pre> *            to visitsetupenv2.
</pre></td></tr>


<tr><th class="line-num" id="L410"><a href="#L410">410</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L411"><a href="#L411">411</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L412"><a href="#L412">412</a></th><td class="line-code"><pre> * Date:       Tue Jun  4 09:27:04 PDT 2013
</pre></td></tr>


<tr><th class="line-num" id="L413"><a href="#L413">413</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L414"><a href="#L414">414</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L415"><a href="#L415">415</a></th><td class="line-code"><pre> *   Brad Whitlock, Tue Oct 27 11:01:11 PDT 2015
</pre></td></tr>


<tr><th class="line-num" id="L416"><a href="#L416">416</a></th><td class="line-code"><pre> *   Fixed potential memory issue.
</pre></td></tr>


<tr><th class="line-num" id="L417"><a href="#L417">417</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L418"><a href="#L418">418</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L419"><a href="#L419">419</a></th><td class="line-code"><pre><span class="pp">#define</span> FMINLENGTH(A,B) (((A) &lt; (B)) ? (A) : (B))
</pre></td></tr>


<tr><th class="line-num" id="L420"><a href="#L420">420</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L421"><a href="#L421">421</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L422"><a href="#L422">422</a></th><td class="line-code"><pre>F_VISITGETENV(VISIT_F77STRING env VISIT_F77_MIXED_STRLEN(env), <span class="pt">int</span> *lenv VISIT_F77_END_STRLEN(env))
</pre></td></tr>


<tr><th class="line-num" id="L423"><a href="#L423">423</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L424"><a href="#L424">424</a></th><td class="line-code"><pre>    <span class="r">if</span>(*lenv &lt;= <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L425"><a href="#L425">425</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L426"><a href="#L426">426</a></th><td class="line-code"><pre>        *lenv = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L427"><a href="#L427">427</a></th><td class="line-code"><pre>        <span class="r">return</span> VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L428"><a href="#L428">428</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L429"><a href="#L429">429</a></th><td class="line-code"><pre>    <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L430"><a href="#L430">430</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L431"><a href="#L431">431</a></th><td class="line-code"><pre>        <span class="pt">char</span> *src = VisItGetEnvironment();
</pre></td></tr>


<tr><th class="line-num" id="L432"><a href="#L432">432</a></th><td class="line-code"><pre>        <span class="r">if</span>(src != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L433"><a href="#L433">433</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L434"><a href="#L434">434</a></th><td class="line-code"><pre>            <span class="c">/* We have lenv which is the size of the destination buffer.
</pre></td></tr>


<tr><th class="line-num" id="L435"><a href="#L435">435</a></th><td class="line-code"><pre>               We have len which is the length of the string. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L436"><a href="#L436">436</a></th><td class="line-code"><pre>            size_t len, sz;
</pre></td></tr>


<tr><th class="line-num" id="L437"><a href="#L437">437</a></th><td class="line-code"><pre>            len = strlen(src);
</pre></td></tr>


<tr><th class="line-num" id="L438"><a href="#L438">438</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L439"><a href="#L439">439</a></th><td class="line-code"><pre>            <span class="c">/* Fill the output buffer with NULL characters */</span>
</pre></td></tr>


<tr><th class="line-num" id="L440"><a href="#L440">440</a></th><td class="line-code"><pre>            memset(env, <span class="i">0</span>, *lenv);
</pre></td></tr>


<tr><th class="line-num" id="L441"><a href="#L441">441</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L442"><a href="#L442">442</a></th><td class="line-code"><pre>            <span class="c">/* Copy the amount of string that will fit into the output buffer
</pre></td></tr>


<tr><th class="line-num" id="L443"><a href="#L443">443</a></th><td class="line-code"><pre>              (leaving 1 element for a NULL terminator).*/</span>
</pre></td></tr>


<tr><th class="line-num" id="L444"><a href="#L444">444</a></th><td class="line-code"><pre>            sz = FMINLENGTH(len, *lenv-<span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L445"><a href="#L445">445</a></th><td class="line-code"><pre>            <span class="r">if</span>(sz &gt; <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L446"><a href="#L446">446</a></th><td class="line-code"><pre>                memcpy(env, src, sz);
</pre></td></tr>


<tr><th class="line-num" id="L447"><a href="#L447">447</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L448"><a href="#L448">448</a></th><td class="line-code"><pre>            <span class="c">/* Return the length of the string in lenv */</span>
</pre></td></tr>


<tr><th class="line-num" id="L449"><a href="#L449">449</a></th><td class="line-code"><pre>            *lenv = (<span class="pt">int</span>)sz;
</pre></td></tr>


<tr><th class="line-num" id="L450"><a href="#L450">450</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L451"><a href="#L451">451</a></th><td class="line-code"><pre>            <span class="c">/* VisItGetEnvironment returns a strdup'd copy of the
</pre></td></tr>


<tr><th class="line-num" id="L452"><a href="#L452">452</a></th><td class="line-code"><pre>               environment now. Free it.*/</span>
</pre></td></tr>


<tr><th class="line-num" id="L453"><a href="#L453">453</a></th><td class="line-code"><pre>            free(src);
</pre></td></tr>


<tr><th class="line-num" id="L454"><a href="#L454">454</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L455"><a href="#L455">455</a></th><td class="line-code"><pre>        <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L456"><a href="#L456">456</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L457"><a href="#L457">457</a></th><td class="line-code"><pre>            *lenv = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L458"><a href="#L458">458</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L459"><a href="#L459">459</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L460"><a href="#L460">460</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L461"><a href="#L461">461</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L462"><a href="#L462">462</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L463"><a href="#L463">463</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L464"><a href="#L464">464</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L465"><a href="#L465">465</a></th><td class="line-code"><pre> * Function: F_VISITINITIALIZESIM
</pre></td></tr>


<tr><th class="line-num" id="L466"><a href="#L466">466</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L467"><a href="#L467">467</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to dump a sim file containing the information
</pre></td></tr>


<tr><th class="line-num" id="L468"><a href="#L468">468</a></th><td class="line-code"><pre> *            that VisIt needs to connect to the sim.
</pre></td></tr>


<tr><th class="line-num" id="L469"><a href="#L469">469</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L470"><a href="#L470">470</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L471"><a href="#L471">471</a></th><td class="line-code"><pre> *   name      : Name of the simulation
</pre></td></tr>


<tr><th class="line-num" id="L472"><a href="#L472">472</a></th><td class="line-code"><pre> *   comment   : Info about the simulation
</pre></td></tr>


<tr><th class="line-num" id="L473"><a href="#L473">473</a></th><td class="line-code"><pre> *   path      : Path to the simulation's data.
</pre></td></tr>


<tr><th class="line-num" id="L474"><a href="#L474">474</a></th><td class="line-code"><pre> *   inputfile : The name of the simulation's input deck.
</pre></td></tr>


<tr><th class="line-num" id="L475"><a href="#L475">475</a></th><td class="line-code"><pre> *   uifile    : The name of the simulation's UI file.
</pre></td></tr>


<tr><th class="line-num" id="L476"><a href="#L476">476</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L477"><a href="#L477">477</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L478"><a href="#L478">478</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L479"><a href="#L479">479</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L480"><a href="#L480">480</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L481"><a href="#L481">481</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L482"><a href="#L482">482</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L483"><a href="#L483">483</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L484"><a href="#L484">484</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L485"><a href="#L485">485</a></th><td class="line-code"><pre>F_VISITINITIALIZESIM(
</pre></td></tr>


<tr><th class="line-num" id="L486"><a href="#L486">486</a></th><td class="line-code"><pre>    VISIT_F77STRING name             VISIT_F77_MIXED_STRLEN(name),             <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L487"><a href="#L487">487</a></th><td class="line-code"><pre>    VISIT_F77STRING comment          VISIT_F77_MIXED_STRLEN(comment),          <span class="pt">int</span> *lcomment ,
</pre></td></tr>


<tr><th class="line-num" id="L488"><a href="#L488">488</a></th><td class="line-code"><pre>    VISIT_F77STRING path             VISIT_F77_MIXED_STRLEN(path),             <span class="pt">int</span> *lpath ,
</pre></td></tr>


<tr><th class="line-num" id="L489"><a href="#L489">489</a></th><td class="line-code"><pre>    VISIT_F77STRING inputfile        VISIT_F77_MIXED_STRLEN(inputfile),        <span class="pt">int</span> *linputfile ,
</pre></td></tr>


<tr><th class="line-num" id="L490"><a href="#L490">490</a></th><td class="line-code"><pre>    VISIT_F77STRING uifile           VISIT_F77_MIXED_STRLEN(uifile),           <span class="pt">int</span> *luifile ,
</pre></td></tr>


<tr><th class="line-num" id="L491"><a href="#L491">491</a></th><td class="line-code"><pre>    VISIT_F77STRING absoluteFilename VISIT_F77_MIXED_STRLEN(absoluteFilename), <span class="pt">int</span> *labsoluteFilename
</pre></td></tr>


<tr><th class="line-num" id="L492"><a href="#L492">492</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(name)
</pre></td></tr>


<tr><th class="line-num" id="L493"><a href="#L493">493</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(comment)
</pre></td></tr>


<tr><th class="line-num" id="L494"><a href="#L494">494</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(path)
</pre></td></tr>


<tr><th class="line-num" id="L495"><a href="#L495">495</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(inputfile)
</pre></td></tr>


<tr><th class="line-num" id="L496"><a href="#L496">496</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(uifile)
</pre></td></tr>


<tr><th class="line-num" id="L497"><a href="#L497">497</a></th><td class="line-code"><pre>    VISIT_F77_END_STRLEN(absoluteFilename))
</pre></td></tr>


<tr><th class="line-num" id="L498"><a href="#L498">498</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L499"><a href="#L499">499</a></th><td class="line-code"><pre>    <span class="pt">int</span> retval = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L500"><a href="#L500">500</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L501"><a href="#L501">501</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_comment = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L502"><a href="#L502">502</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_path = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L503"><a href="#L503">503</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_inputfile = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L504"><a href="#L504">504</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_uifile = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L505"><a href="#L505">505</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_absoluteFilename = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L506"><a href="#L506">506</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L507"><a href="#L507">507</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_comment, comment, lcomment);
</pre></td></tr>


<tr><th class="line-num" id="L508"><a href="#L508">508</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_path, path, lpath);
</pre></td></tr>


<tr><th class="line-num" id="L509"><a href="#L509">509</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_inputfile, inputfile, linputfile);
</pre></td></tr>


<tr><th class="line-num" id="L510"><a href="#L510">510</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_uifile, uifile, luifile);
</pre></td></tr>


<tr><th class="line-num" id="L511"><a href="#L511">511</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_absoluteFilename, absoluteFilename, labsoluteFilename);
</pre></td></tr>


<tr><th class="line-num" id="L512"><a href="#L512">512</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L513"><a href="#L513">513</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L514"><a href="#L514">514</a></th><td class="line-code"><pre>    retval = VisItInitializeSocketAndDumpSimFile(f_name, f_comment,
</pre></td></tr>


<tr><th class="line-num" id="L515"><a href="#L515">515</a></th><td class="line-code"><pre>                 f_path, f_inputfile, f_uifile,f_absoluteFilename);
</pre></td></tr>


<tr><th class="line-num" id="L516"><a href="#L516">516</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L517"><a href="#L517">517</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L518"><a href="#L518">518</a></th><td class="line-code"><pre>    FREE(f_comment);
</pre></td></tr>


<tr><th class="line-num" id="L519"><a href="#L519">519</a></th><td class="line-code"><pre>    FREE(f_path);
</pre></td></tr>


<tr><th class="line-num" id="L520"><a href="#L520">520</a></th><td class="line-code"><pre>    FREE(f_inputfile);
</pre></td></tr>


<tr><th class="line-num" id="L521"><a href="#L521">521</a></th><td class="line-code"><pre>    FREE(f_uifile);
</pre></td></tr>


<tr><th class="line-num" id="L522"><a href="#L522">522</a></th><td class="line-code"><pre>    FREE(f_absoluteFilename);
</pre></td></tr>


<tr><th class="line-num" id="L523"><a href="#L523">523</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L524"><a href="#L524">524</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L525"><a href="#L525">525</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L526"><a href="#L526">526</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L527"><a href="#L527">527</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L528"><a href="#L528">528</a></th><td class="line-code"><pre> * Function: F_VISITSETPARALLEL
</pre></td></tr>


<tr><th class="line-num" id="L529"><a href="#L529">529</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L530"><a href="#L530">530</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set whether it is a parallel sim.
</pre></td></tr>


<tr><th class="line-num" id="L531"><a href="#L531">531</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L532"><a href="#L532">532</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L533"><a href="#L533">533</a></th><td class="line-code"><pre> *   val : Whether the simulation is parallel.
</pre></td></tr>


<tr><th class="line-num" id="L534"><a href="#L534">534</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L535"><a href="#L535">535</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L536"><a href="#L536">536</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L537"><a href="#L537">537</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L538"><a href="#L538">538</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L539"><a href="#L539">539</a></th><td class="line-code"><pre> *   Brad Whitlock, Tue Jul 19 09:18:40 PDT 2011
</pre></td></tr>


<tr><th class="line-num" id="L540"><a href="#L540">540</a></th><td class="line-code"><pre> *   Set up parallel callbacks as suggested by Jens Henrik Goebbert.
</pre></td></tr>


<tr><th class="line-num" id="L541"><a href="#L541">541</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L542"><a href="#L542">542</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L543"><a href="#L543">543</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L544"><a href="#L544">544</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L545"><a href="#L545">545</a></th><td class="line-code"><pre>F_VISITSETPARALLEL(<span class="pt">int</span> *val)
</pre></td></tr>


<tr><th class="line-num" id="L546"><a href="#L546">546</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L547"><a href="#L547">547</a></th><td class="line-code"><pre>    VisItSetParallel(*val);
</pre></td></tr>


<tr><th class="line-num" id="L548"><a href="#L548">548</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L549"><a href="#L549">549</a></th><td class="line-code"><pre>    <span class="r">if</span>(*val)
</pre></td></tr>


<tr><th class="line-num" id="L550"><a href="#L550">550</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L551"><a href="#L551">551</a></th><td class="line-code"><pre>        VisItSetBroadcastIntFunction(f_visit_internal_broadcastintfunction);
</pre></td></tr>


<tr><th class="line-num" id="L552"><a href="#L552">552</a></th><td class="line-code"><pre>        VisItSetBroadcastStringFunction(f_visit_internal_broadcaststringfunction);
</pre></td></tr>


<tr><th class="line-num" id="L553"><a href="#L553">553</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L554"><a href="#L554">554</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L555"><a href="#L555">555</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L556"><a href="#L556">556</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L557"><a href="#L557">557</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L558"><a href="#L558">558</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L559"><a href="#L559">559</a></th><td class="line-code"><pre> * Function: F_VISITSETPARALLELRANK
</pre></td></tr>


<tr><th class="line-num" id="L560"><a href="#L560">560</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L561"><a href="#L561">561</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the current processor's parallel rank.
</pre></td></tr>


<tr><th class="line-num" id="L562"><a href="#L562">562</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L563"><a href="#L563">563</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L564"><a href="#L564">564</a></th><td class="line-code"><pre> *   rank : The rank of the current processor.
</pre></td></tr>


<tr><th class="line-num" id="L565"><a href="#L565">565</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L566"><a href="#L566">566</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L567"><a href="#L567">567</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L568"><a href="#L568">568</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L569"><a href="#L569">569</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L570"><a href="#L570">570</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L571"><a href="#L571">571</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L572"><a href="#L572">572</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L573"><a href="#L573">573</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L574"><a href="#L574">574</a></th><td class="line-code"><pre>F_VISITSETPARALLELRANK(<span class="pt">int</span> *rank)
</pre></td></tr>


<tr><th class="line-num" id="L575"><a href="#L575">575</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L576"><a href="#L576">576</a></th><td class="line-code"><pre>    VisItSetParallelRank(*rank);
</pre></td></tr>


<tr><th class="line-num" id="L577"><a href="#L577">577</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L578"><a href="#L578">578</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L579"><a href="#L579">579</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L580"><a href="#L580">580</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L581"><a href="#L581">581</a></th><td class="line-code"><pre> * Function: F_VISITDETECTINPUT
</pre></td></tr>


<tr><th class="line-num" id="L582"><a href="#L582">582</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L583"><a href="#L583">583</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to detect VisIt socket input and console input.
</pre></td></tr>


<tr><th class="line-num" id="L584"><a href="#L584">584</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L585"><a href="#L585">585</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L586"><a href="#L586">586</a></th><td class="line-code"><pre> *   blocking    : Whether or not to block.
</pre></td></tr>


<tr><th class="line-num" id="L587"><a href="#L587">587</a></th><td class="line-code"><pre> *   consoledesc : The console file descriptor.
</pre></td></tr>


<tr><th class="line-num" id="L588"><a href="#L588">588</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L589"><a href="#L589">589</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L590"><a href="#L590">590</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L591"><a href="#L591">591</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L592"><a href="#L592">592</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L593"><a href="#L593">593</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L594"><a href="#L594">594</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L595"><a href="#L595">595</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L596"><a href="#L596">596</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L597"><a href="#L597">597</a></th><td class="line-code"><pre>F_VISITDETECTINPUT(<span class="pt">int</span> *blocking, <span class="pt">int</span> *consoledesc)
</pre></td></tr>


<tr><th class="line-num" id="L598"><a href="#L598">598</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L599"><a href="#L599">599</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItDetectInput(*blocking, *consoledesc);
</pre></td></tr>


<tr><th class="line-num" id="L600"><a href="#L600">600</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L601"><a href="#L601">601</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L602"><a href="#L602">602</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L603"><a href="#L603">603</a></th><td class="line-code"><pre> * Function: F_VISITDETECTINPUTWITHTIMEOUT
</pre></td></tr>


<tr><th class="line-num" id="L604"><a href="#L604">604</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L605"><a href="#L605">605</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to detect VisIt socket input and console input
</pre></td></tr>


<tr><th class="line-num" id="L606"><a href="#L606">606</a></th><td class="line-code"><pre> *            with a timeout in micro secounds
</pre></td></tr>


<tr><th class="line-num" id="L607"><a href="#L607">607</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L608"><a href="#L608">608</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L609"><a href="#L609">609</a></th><td class="line-code"><pre> *   blocking    : Whether or not to block.
</pre></td></tr>


<tr><th class="line-num" id="L610"><a href="#L610">610</a></th><td class="line-code"><pre> *   micsec      : timeout if blocking
</pre></td></tr>


<tr><th class="line-num" id="L611"><a href="#L611">611</a></th><td class="line-code"><pre> *   consoledesc : The console file descriptor.
</pre></td></tr>


<tr><th class="line-num" id="L612"><a href="#L612">612</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L613"><a href="#L613">613</a></th><td class="line-code"><pre> * Programmer: Jens Henrik Goebbert
</pre></td></tr>


<tr><th class="line-num" id="L614"><a href="#L614">614</a></th><td class="line-code"><pre> * Date:       Wed Jul 20 11:17:51 PST 2011
</pre></td></tr>


<tr><th class="line-num" id="L615"><a href="#L615">615</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L616"><a href="#L616">616</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L617"><a href="#L617">617</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L618"><a href="#L618">618</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L619"><a href="#L619">619</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L620"><a href="#L620">620</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L621"><a href="#L621">621</a></th><td class="line-code"><pre>F_VISITDETECTINPUTWITHTIMEOUT(<span class="pt">int</span> *blocking, <span class="pt">int</span> *micsec, <span class="pt">int</span> *consoledesc)
</pre></td></tr>


<tr><th class="line-num" id="L622"><a href="#L622">622</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L623"><a href="#L623">623</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItDetectInputWithTimeout(*blocking, *micsec, *consoledesc);
</pre></td></tr>


<tr><th class="line-num" id="L624"><a href="#L624">624</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L625"><a href="#L625">625</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L626"><a href="#L626">626</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L627"><a href="#L627">627</a></th><td class="line-code"><pre> * Function: F_VISITGETSOCKETS
</pre></td></tr>


<tr><th class="line-num" id="L628"><a href="#L628">628</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L629"><a href="#L629">629</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to get at listen and client sockets
</pre></td></tr>


<tr><th class="line-num" id="L630"><a href="#L630">630</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L631"><a href="#L631">631</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L632"><a href="#L632">632</a></th><td class="line-code"><pre> *   lSocket : listen socket
</pre></td></tr>


<tr><th class="line-num" id="L633"><a href="#L633">633</a></th><td class="line-code"><pre> *   cSocket : engine/client socket
</pre></td></tr>


<tr><th class="line-num" id="L634"><a href="#L634">634</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L635"><a href="#L635">635</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L636"><a href="#L636">636</a></th><td class="line-code"><pre> * Date:       Wed Jul 27 10:52:04 PDT 2011
</pre></td></tr>


<tr><th class="line-num" id="L637"><a href="#L637">637</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L638"><a href="#L638">638</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L639"><a href="#L639">639</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L640"><a href="#L640">640</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L641"><a href="#L641">641</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L642"><a href="#L642">642</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L643"><a href="#L643">643</a></th><td class="line-code"><pre>F_VISITGETSOCKETS(<span class="pt">int</span> *lSocket, <span class="pt">int</span> *cSocket)
</pre></td></tr>


<tr><th class="line-num" id="L644"><a href="#L644">644</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L645"><a href="#L645">645</a></th><td class="line-code"><pre><span class="pp">#ifdef</span> _WIN32
</pre></td></tr>


<tr><th class="line-num" id="L646"><a href="#L646">646</a></th><td class="line-code"><pre>    <span class="pt">int</span> retval = VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L647"><a href="#L647">647</a></th><td class="line-code"><pre>    <span class="r">if</span>(lSocket != <span class="pc">NULL</span> &amp;&amp; cSocket == <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L648"><a href="#L648">648</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L649"><a href="#L649">649</a></th><td class="line-code"><pre>        *lSocket = *cSocket = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L650"><a href="#L650">650</a></th><td class="line-code"><pre>         retval = VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L651"><a href="#L651">651</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L652"><a href="#L652">652</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L653"><a href="#L653">653</a></th><td class="line-code"><pre><span class="pp">#else</span>
</pre></td></tr>


<tr><th class="line-num" id="L654"><a href="#L654">654</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItGetSockets(lSocket, cSocket);
</pre></td></tr>


<tr><th class="line-num" id="L655"><a href="#L655">655</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L656"><a href="#L656">656</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L657"><a href="#L657">657</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L658"><a href="#L658">658</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L659"><a href="#L659">659</a></th><td class="line-code"><pre> * Function: F_VISITATTEMPTCONNECTION
</pre></td></tr>


<tr><th class="line-num" id="L660"><a href="#L660">660</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L661"><a href="#L661">661</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to try and connect back to the VisIt viewer.
</pre></td></tr>


<tr><th class="line-num" id="L662"><a href="#L662">662</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L663"><a href="#L663">663</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L664"><a href="#L664">664</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L665"><a href="#L665">665</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L666"><a href="#L666">666</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L667"><a href="#L667">667</a></th><td class="line-code"><pre> *   Brad Whitlock, Tue Oct  2 11:42:03 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L668"><a href="#L668">668</a></th><td class="line-code"><pre> *   Move callback installation to f_visit_internal_InstallCallbacks.
</pre></td></tr>


<tr><th class="line-num" id="L669"><a href="#L669">669</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L670"><a href="#L670">670</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L671"><a href="#L671">671</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L672"><a href="#L672">672</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L673"><a href="#L673">673</a></th><td class="line-code"><pre>F_VISITATTEMPTCONNECTION(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L674"><a href="#L674">674</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L675"><a href="#L675">675</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L676"><a href="#L676">676</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L677"><a href="#L677">677</a></th><td class="line-code"><pre>    <span class="c">/* Set up some callbacks that will reference external FORTRAN functions. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L678"><a href="#L678">678</a></th><td class="line-code"><pre>    VisItSetBroadcastIntFunction(f_visit_internal_broadcastintfunction);
</pre></td></tr>


<tr><th class="line-num" id="L679"><a href="#L679">679</a></th><td class="line-code"><pre>    VisItSetBroadcastStringFunction(f_visit_internal_broadcaststringfunction);
</pre></td></tr>


<tr><th class="line-num" id="L680"><a href="#L680">680</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L681"><a href="#L681">681</a></th><td class="line-code"><pre>    ret = VisItAttemptToCompleteConnection();
</pre></td></tr>


<tr><th class="line-num" id="L682"><a href="#L682">682</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L683"><a href="#L683">683</a></th><td class="line-code"><pre>    <span class="c">/* Hook up the VisIt callback functions if VisIt connected. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L684"><a href="#L684">684</a></th><td class="line-code"><pre>    <span class="r">if</span>(ret == <span class="i">1</span>)
</pre></td></tr>


<tr><th class="line-num" id="L685"><a href="#L685">685</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L686"><a href="#L686">686</a></th><td class="line-code"><pre>        f_visit_internal_InstallCallbacks();
</pre></td></tr>


<tr><th class="line-num" id="L687"><a href="#L687">687</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L688"><a href="#L688">688</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L689"><a href="#L689">689</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L690"><a href="#L690">690</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L691"><a href="#L691">691</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L692"><a href="#L692">692</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L693"><a href="#L693">693</a></th><td class="line-code"><pre> * Function: F_VISITPROCESSENGINECOMMAND
</pre></td></tr>


<tr><th class="line-num" id="L694"><a href="#L694">694</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L695"><a href="#L695">695</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to process VisIt engine commands.
</pre></td></tr>


<tr><th class="line-num" id="L696"><a href="#L696">696</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L697"><a href="#L697">697</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L698"><a href="#L698">698</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L699"><a href="#L699">699</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L700"><a href="#L700">700</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L701"><a href="#L701">701</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L702"><a href="#L702">702</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L703"><a href="#L703">703</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L704"><a href="#L704">704</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L705"><a href="#L705">705</a></th><td class="line-code"><pre>F_VISITPROCESSENGINECOMMAND(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L706"><a href="#L706">706</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L707"><a href="#L707">707</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItProcessEngineCommand();
</pre></td></tr>


<tr><th class="line-num" id="L708"><a href="#L708">708</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L709"><a href="#L709">709</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L710"><a href="#L710">710</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L711"><a href="#L711">711</a></th><td class="line-code"><pre> * Function: F_VISITTIMESTEPCHANGED
</pre></td></tr>


<tr><th class="line-num" id="L712"><a href="#L712">712</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L713"><a href="#L713">713</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to notify VisIt that the time step changed.
</pre></td></tr>


<tr><th class="line-num" id="L714"><a href="#L714">714</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L715"><a href="#L715">715</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L716"><a href="#L716">716</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L717"><a href="#L717">717</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L718"><a href="#L718">718</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L719"><a href="#L719">719</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L720"><a href="#L720">720</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L721"><a href="#L721">721</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L722"><a href="#L722">722</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L723"><a href="#L723">723</a></th><td class="line-code"><pre>F_VISITTIMESTEPCHANGED(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L724"><a href="#L724">724</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L725"><a href="#L725">725</a></th><td class="line-code"><pre>    VisItTimeStepChanged();
</pre></td></tr>


<tr><th class="line-num" id="L726"><a href="#L726">726</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L727"><a href="#L727">727</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L728"><a href="#L728">728</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L729"><a href="#L729">729</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L730"><a href="#L730">730</a></th><td class="line-code"><pre> * Function: F_VISITUPDATEPLOTS
</pre></td></tr>


<tr><th class="line-num" id="L731"><a href="#L731">731</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L732"><a href="#L732">732</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to notify VisIt that that plots should be recreated.
</pre></td></tr>


<tr><th class="line-num" id="L733"><a href="#L733">733</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L734"><a href="#L734">734</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L735"><a href="#L735">735</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L736"><a href="#L736">736</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L737"><a href="#L737">737</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L738"><a href="#L738">738</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L739"><a href="#L739">739</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L740"><a href="#L740">740</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L741"><a href="#L741">741</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L742"><a href="#L742">742</a></th><td class="line-code"><pre>F_VISITUPDATEPLOTS(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L743"><a href="#L743">743</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L744"><a href="#L744">744</a></th><td class="line-code"><pre>    VisItUpdatePlots();
</pre></td></tr>


<tr><th class="line-num" id="L745"><a href="#L745">745</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L746"><a href="#L746">746</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L747"><a href="#L747">747</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L748"><a href="#L748">748</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L749"><a href="#L749">749</a></th><td class="line-code"><pre> * Function: F_VISITEXECUTECOMMAND
</pre></td></tr>


<tr><th class="line-num" id="L750"><a href="#L750">750</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L751"><a href="#L751">751</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to tell VisIt a command that should be interpreted.
</pre></td></tr>


<tr><th class="line-num" id="L752"><a href="#L752">752</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L753"><a href="#L753">753</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L754"><a href="#L754">754</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L755"><a href="#L755">755</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L756"><a href="#L756">756</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L757"><a href="#L757">757</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L758"><a href="#L758">758</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L759"><a href="#L759">759</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L760"><a href="#L760">760</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L761"><a href="#L761">761</a></th><td class="line-code"><pre>F_VISITEXECUTECOMMAND(VISIT_F77STRING command VISIT_F77_MIXED_STRLEN(command), <span class="pt">int</span> *lcommand VISIT_F77_END_STRLEN(command))
</pre></td></tr>


<tr><th class="line-num" id="L762"><a href="#L762">762</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L763"><a href="#L763">763</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_command = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L764"><a href="#L764">764</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_command, command, lcommand);
</pre></td></tr>


<tr><th class="line-num" id="L765"><a href="#L765">765</a></th><td class="line-code"><pre>    VisItExecuteCommand(f_command);
</pre></td></tr>


<tr><th class="line-num" id="L766"><a href="#L766">766</a></th><td class="line-code"><pre>    FREE(f_command);
</pre></td></tr>


<tr><th class="line-num" id="L767"><a href="#L767">767</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L768"><a href="#L768">768</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L769"><a href="#L769">769</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L770"><a href="#L770">770</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L771"><a href="#L771">771</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L772"><a href="#L772">772</a></th><td class="line-code"><pre> * Function: F_VISITDISCONNECT
</pre></td></tr>


<tr><th class="line-num" id="L773"><a href="#L773">773</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L774"><a href="#L774">774</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to disconnect VisIt from the simulation.
</pre></td></tr>


<tr><th class="line-num" id="L775"><a href="#L775">775</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L776"><a href="#L776">776</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L777"><a href="#L777">777</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L778"><a href="#L778">778</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L779"><a href="#L779">779</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L780"><a href="#L780">780</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L781"><a href="#L781">781</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L782"><a href="#L782">782</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L783"><a href="#L783">783</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L784"><a href="#L784">784</a></th><td class="line-code"><pre>F_VISITDISCONNECT(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L785"><a href="#L785">785</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L786"><a href="#L786">786</a></th><td class="line-code"><pre>    VisItDisconnect();
</pre></td></tr>


<tr><th class="line-num" id="L787"><a href="#L787">787</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L788"><a href="#L788">788</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L789"><a href="#L789">789</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L790"><a href="#L790">790</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L791"><a href="#L791">791</a></th><td class="line-code"><pre> * Function: F_VISITGETLASTERROR
</pre></td></tr>


<tr><th class="line-num" id="L792"><a href="#L792">792</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L793"><a href="#L793">793</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to retrieve the last error.
</pre></td></tr>


<tr><th class="line-num" id="L794"><a href="#L794">794</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L795"><a href="#L795">795</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L796"><a href="#L796">796</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L797"><a href="#L797">797</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L798"><a href="#L798">798</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L799"><a href="#L799">799</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L800"><a href="#L800">800</a></th><td class="line-code"><pre> *   Mark C. Miller, Wed Aug 22 19:05:30 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L801"><a href="#L801">801</a></th><td class="line-code"><pre> *   Fix leak of result returned from VisItGetLastError as well as invalid
</pre></td></tr>


<tr><th class="line-num" id="L802"><a href="#L802">802</a></th><td class="line-code"><pre> *   second call to VisItGetLastError (first call clears last error).
</pre></td></tr>


<tr><th class="line-num" id="L803"><a href="#L803">803</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L804"><a href="#L804">804</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L805"><a href="#L805">805</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L806"><a href="#L806">806</a></th><td class="line-code"><pre>F_VISITGETLASTERROR(<span class="pt">char</span> *dest VISIT_F77_MIXED_STRLEN(dest), <span class="pt">int</span> *bufsize VISIT_F77_END_STRLEN(dest))
</pre></td></tr>


<tr><th class="line-num" id="L807"><a href="#L807">807</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L808"><a href="#L808">808</a></th><td class="line-code"><pre>    <span class="pt">int</span> M = *bufsize-<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L809"><a href="#L809">809</a></th><td class="line-code"><pre>    <span class="pt">char</span> *vgle = VisItGetLastError();
</pre></td></tr>


<tr><th class="line-num" id="L810"><a href="#L810">810</a></th><td class="line-code"><pre>    <span class="pt">int</span> S = strlen(vgle)-<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L811"><a href="#L811">811</a></th><td class="line-code"><pre>    <span class="r">if</span>(S &lt; M)
</pre></td></tr>


<tr><th class="line-num" id="L812"><a href="#L812">812</a></th><td class="line-code"><pre>        M = S;
</pre></td></tr>


<tr><th class="line-num" id="L813"><a href="#L813">813</a></th><td class="line-code"><pre>    strncpy(dest, vgle, M);
</pre></td></tr>


<tr><th class="line-num" id="L814"><a href="#L814">814</a></th><td class="line-code"><pre>    dest[M] = <span class="ch">'\0'</span>;
</pre></td></tr>


<tr><th class="line-num" id="L815"><a href="#L815">815</a></th><td class="line-code"><pre>    free(vgle);
</pre></td></tr>


<tr><th class="line-num" id="L816"><a href="#L816">816</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L817"><a href="#L817">817</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L818"><a href="#L818">818</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L819"><a href="#L819">819</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L820"><a href="#L820">820</a></th><td class="line-code"><pre> * Function: F_VISITISCONNECTED
</pre></td></tr>


<tr><th class="line-num" id="L821"><a href="#L821">821</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L822"><a href="#L822">822</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to retrieve whether VisIt is connected
</pre></td></tr>


<tr><th class="line-num" id="L823"><a href="#L823">823</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L824"><a href="#L824">824</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L825"><a href="#L825">825</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L826"><a href="#L826">826</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L827"><a href="#L827">827</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L828"><a href="#L828">828</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L829"><a href="#L829">829</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L830"><a href="#L830">830</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L831"><a href="#L831">831</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L832"><a href="#L832">832</a></th><td class="line-code"><pre>F_VISITISCONNECTED()
</pre></td></tr>


<tr><th class="line-num" id="L833"><a href="#L833">833</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L834"><a href="#L834">834</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItIsConnected();
</pre></td></tr>


<tr><th class="line-num" id="L835"><a href="#L835">835</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L836"><a href="#L836">836</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L837"><a href="#L837">837</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L838"><a href="#L838">838</a></th><td class="line-code"><pre> * Function: F_VISITSYNCHRONIZE
</pre></td></tr>


<tr><th class="line-num" id="L839"><a href="#L839">839</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L840"><a href="#L840">840</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to cause a synchronize
</pre></td></tr>


<tr><th class="line-num" id="L841"><a href="#L841">841</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L842"><a href="#L842">842</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L843"><a href="#L843">843</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L844"><a href="#L844">844</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L845"><a href="#L845">845</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L846"><a href="#L846">846</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L847"><a href="#L847">847</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L848"><a href="#L848">848</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L849"><a href="#L849">849</a></th><td class="line-code"><pre><span class="pt">int</span>
</pre></td></tr>


<tr><th class="line-num" id="L850"><a href="#L850">850</a></th><td class="line-code"><pre>F_VISITSYNCHRONIZE(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L851"><a href="#L851">851</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L852"><a href="#L852">852</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItSynchronize();
</pre></td></tr>


<tr><th class="line-num" id="L853"><a href="#L853">853</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L854"><a href="#L854">854</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L855"><a href="#L855">855</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L856"><a href="#L856">856</a></th><td class="line-code"><pre> * Function: F_VISITENABLESYNCHRONIZE
</pre></td></tr>


<tr><th class="line-num" id="L857"><a href="#L857">857</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L858"><a href="#L858">858</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the synchronization mode.
</pre></td></tr>


<tr><th class="line-num" id="L859"><a href="#L859">859</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L860"><a href="#L860">860</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L861"><a href="#L861">861</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L862"><a href="#L862">862</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L863"><a href="#L863">863</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L864"><a href="#L864">864</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L865"><a href="#L865">865</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L866"><a href="#L866">866</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L867"><a href="#L867">867</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L868"><a href="#L868">868</a></th><td class="line-code"><pre>F_VISITENABLESYNCHRONIZE(<span class="pt">int</span> *val)
</pre></td></tr>


<tr><th class="line-num" id="L869"><a href="#L869">869</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L870"><a href="#L870">870</a></th><td class="line-code"><pre>    VisItEnableSynchronize(*val);
</pre></td></tr>


<tr><th class="line-num" id="L871"><a href="#L871">871</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L872"><a href="#L872">872</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L873"><a href="#L873">873</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L874"><a href="#L874">874</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L875"><a href="#L875">875</a></th><td class="line-code"><pre> * Function: F_VISITDEBUG1
</pre></td></tr>


<tr><th class="line-num" id="L876"><a href="#L876">876</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L877"><a href="#L877">877</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to write to debug1 logs.
</pre></td></tr>


<tr><th class="line-num" id="L878"><a href="#L878">878</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L879"><a href="#L879">879</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L880"><a href="#L880">880</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L881"><a href="#L881">881</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L882"><a href="#L882">882</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L883"><a href="#L883">883</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L884"><a href="#L884">884</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L885"><a href="#L885">885</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L886"><a href="#L886">886</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L887"><a href="#L887">887</a></th><td class="line-code"><pre>F_VISITDEBUG1(<span class="r">const</span> <span class="pt">char</span> *str VISIT_F77_MIXED_STRLEN(str), <span class="pt">int</span> *lstr VISIT_F77_END_STRLEN(str))
</pre></td></tr>


<tr><th class="line-num" id="L888"><a href="#L888">888</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L889"><a href="#L889">889</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_str = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L890"><a href="#L890">890</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_str, str, lstr);
</pre></td></tr>


<tr><th class="line-num" id="L891"><a href="#L891">891</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_str != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L892"><a href="#L892">892</a></th><td class="line-code"><pre>        VisItDebug1(<span class="s"><span class="dl">&quot;</span><span class="k">%s</span><span class="dl">&quot;</span></span>, f_str);
</pre></td></tr>


<tr><th class="line-num" id="L893"><a href="#L893">893</a></th><td class="line-code"><pre>    FREE(f_str);
</pre></td></tr>


<tr><th class="line-num" id="L894"><a href="#L894">894</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L895"><a href="#L895">895</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L896"><a href="#L896">896</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L897"><a href="#L897">897</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L898"><a href="#L898">898</a></th><td class="line-code"><pre> * Function: F_VISITDEBUG2
</pre></td></tr>


<tr><th class="line-num" id="L899"><a href="#L899">899</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L900"><a href="#L900">900</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to write to debug2 logs.
</pre></td></tr>


<tr><th class="line-num" id="L901"><a href="#L901">901</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L902"><a href="#L902">902</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L903"><a href="#L903">903</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L904"><a href="#L904">904</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L905"><a href="#L905">905</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L906"><a href="#L906">906</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L907"><a href="#L907">907</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L908"><a href="#L908">908</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L909"><a href="#L909">909</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L910"><a href="#L910">910</a></th><td class="line-code"><pre>F_VISITDEBUG2(<span class="r">const</span> <span class="pt">char</span> *str VISIT_F77_MIXED_STRLEN(str), <span class="pt">int</span> *lstr VISIT_F77_END_STRLEN(str))
</pre></td></tr>


<tr><th class="line-num" id="L911"><a href="#L911">911</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L912"><a href="#L912">912</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_str = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L913"><a href="#L913">913</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_str, str, lstr);
</pre></td></tr>


<tr><th class="line-num" id="L914"><a href="#L914">914</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_str != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L915"><a href="#L915">915</a></th><td class="line-code"><pre>        VisItDebug2(<span class="s"><span class="dl">&quot;</span><span class="k">%s</span><span class="dl">&quot;</span></span>, f_str);
</pre></td></tr>


<tr><th class="line-num" id="L916"><a href="#L916">916</a></th><td class="line-code"><pre>    FREE(f_str);
</pre></td></tr>


<tr><th class="line-num" id="L917"><a href="#L917">917</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L918"><a href="#L918">918</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L919"><a href="#L919">919</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L920"><a href="#L920">920</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L921"><a href="#L921">921</a></th><td class="line-code"><pre> * Function: F_VISITDEBUG3
</pre></td></tr>


<tr><th class="line-num" id="L922"><a href="#L922">922</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L923"><a href="#L923">923</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to write to debug3 logs.
</pre></td></tr>


<tr><th class="line-num" id="L924"><a href="#L924">924</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L925"><a href="#L925">925</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L926"><a href="#L926">926</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L927"><a href="#L927">927</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L928"><a href="#L928">928</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L929"><a href="#L929">929</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L930"><a href="#L930">930</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L931"><a href="#L931">931</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L932"><a href="#L932">932</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L933"><a href="#L933">933</a></th><td class="line-code"><pre>F_VISITDEBUG3(<span class="r">const</span> <span class="pt">char</span> *str VISIT_F77_MIXED_STRLEN(str), <span class="pt">int</span> *lstr VISIT_F77_END_STRLEN(str))
</pre></td></tr>


<tr><th class="line-num" id="L934"><a href="#L934">934</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L935"><a href="#L935">935</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_str = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L936"><a href="#L936">936</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_str, str, lstr);
</pre></td></tr>


<tr><th class="line-num" id="L937"><a href="#L937">937</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_str != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L938"><a href="#L938">938</a></th><td class="line-code"><pre>        VisItDebug3(<span class="s"><span class="dl">&quot;</span><span class="k">%s</span><span class="dl">&quot;</span></span>, f_str);
</pre></td></tr>


<tr><th class="line-num" id="L939"><a href="#L939">939</a></th><td class="line-code"><pre>    FREE(f_str);
</pre></td></tr>


<tr><th class="line-num" id="L940"><a href="#L940">940</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L941"><a href="#L941">941</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L942"><a href="#L942">942</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L943"><a href="#L943">943</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L944"><a href="#L944">944</a></th><td class="line-code"><pre> * Function: F_VISITDEBUG4
</pre></td></tr>


<tr><th class="line-num" id="L945"><a href="#L945">945</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L946"><a href="#L946">946</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to write to debug4 logs.
</pre></td></tr>


<tr><th class="line-num" id="L947"><a href="#L947">947</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L948"><a href="#L948">948</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L949"><a href="#L949">949</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L950"><a href="#L950">950</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L951"><a href="#L951">951</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L952"><a href="#L952">952</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L953"><a href="#L953">953</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L954"><a href="#L954">954</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L955"><a href="#L955">955</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L956"><a href="#L956">956</a></th><td class="line-code"><pre>F_VISITDEBUG4(<span class="r">const</span> <span class="pt">char</span> *str VISIT_F77_MIXED_STRLEN(str), <span class="pt">int</span> *lstr VISIT_F77_END_STRLEN(str))
</pre></td></tr>


<tr><th class="line-num" id="L957"><a href="#L957">957</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L958"><a href="#L958">958</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_str = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L959"><a href="#L959">959</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_str, str, lstr);
</pre></td></tr>


<tr><th class="line-num" id="L960"><a href="#L960">960</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_str != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L961"><a href="#L961">961</a></th><td class="line-code"><pre>        VisItDebug4(<span class="s"><span class="dl">&quot;</span><span class="k">%s</span><span class="dl">&quot;</span></span>, f_str);
</pre></td></tr>


<tr><th class="line-num" id="L962"><a href="#L962">962</a></th><td class="line-code"><pre>    FREE(f_str);
</pre></td></tr>


<tr><th class="line-num" id="L963"><a href="#L963">963</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L964"><a href="#L964">964</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L965"><a href="#L965">965</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L966"><a href="#L966">966</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L967"><a href="#L967">967</a></th><td class="line-code"><pre> * Function: F_VISITDEBUG5
</pre></td></tr>


<tr><th class="line-num" id="L968"><a href="#L968">968</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L969"><a href="#L969">969</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to write to debug5 logs.
</pre></td></tr>


<tr><th class="line-num" id="L970"><a href="#L970">970</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L971"><a href="#L971">971</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L972"><a href="#L972">972</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L973"><a href="#L973">973</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L974"><a href="#L974">974</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L975"><a href="#L975">975</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L976"><a href="#L976">976</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L977"><a href="#L977">977</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L978"><a href="#L978">978</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L979"><a href="#L979">979</a></th><td class="line-code"><pre>F_VISITDEBUG5(<span class="r">const</span> <span class="pt">char</span> *str VISIT_F77_MIXED_STRLEN(str), <span class="pt">int</span> *lstr VISIT_F77_END_STRLEN(str))
</pre></td></tr>


<tr><th class="line-num" id="L980"><a href="#L980">980</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L981"><a href="#L981">981</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_str = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L982"><a href="#L982">982</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_str, str, lstr);
</pre></td></tr>


<tr><th class="line-num" id="L983"><a href="#L983">983</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_str != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L984"><a href="#L984">984</a></th><td class="line-code"><pre>        VisItDebug5(<span class="s"><span class="dl">&quot;</span><span class="k">%s</span><span class="dl">&quot;</span></span>, f_str);
</pre></td></tr>


<tr><th class="line-num" id="L985"><a href="#L985">985</a></th><td class="line-code"><pre>    FREE(f_str);
</pre></td></tr>


<tr><th class="line-num" id="L986"><a href="#L986">986</a></th><td class="line-code"><pre>    <span class="r">return</span> VISIT_OKAY;
</pre></td></tr>


<tr><th class="line-num" id="L987"><a href="#L987">987</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L988"><a href="#L988">988</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L989"><a href="#L989">989</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L990"><a href="#L990">990</a></th><td class="line-code"><pre> * Function: F_VISITSAVEWINDOW
</pre></td></tr>


<tr><th class="line-num" id="L991"><a href="#L991">991</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L992"><a href="#L992">992</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to save a window.
</pre></td></tr>


<tr><th class="line-num" id="L993"><a href="#L993">993</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L994"><a href="#L994">994</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L995"><a href="#L995">995</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L996"><a href="#L996">996</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L997"><a href="#L997">997</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L998"><a href="#L998">998</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L999"><a href="#L999">999</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1000"><a href="#L1000">1000</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1001"><a href="#L1001">1001</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1002"><a href="#L1002">1002</a></th><td class="line-code"><pre>F_VISITSAVEWINDOW(<span class="r">const</span> <span class="pt">char</span> *filename VISIT_F77_MIXED_STRLEN(filename), <span class="pt">int</span> *lfilename,
</pre></td></tr>


<tr><th class="line-num" id="L1003"><a href="#L1003">1003</a></th><td class="line-code"><pre>                  <span class="pt">int</span> *width, <span class="pt">int</span> *height, <span class="pt">int</span> *format VISIT_F77_END_STRLEN(filename))
</pre></td></tr>


<tr><th class="line-num" id="L1004"><a href="#L1004">1004</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1005"><a href="#L1005">1005</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret = VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L1006"><a href="#L1006">1006</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_filename = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1007"><a href="#L1007">1007</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_filename, filename, lfilename);
</pre></td></tr>


<tr><th class="line-num" id="L1008"><a href="#L1008">1008</a></th><td class="line-code"><pre>    ret = VisItSaveWindow(f_filename, *width, *height, *format);
</pre></td></tr>


<tr><th class="line-num" id="L1009"><a href="#L1009">1009</a></th><td class="line-code"><pre>    FREE(f_filename);
</pre></td></tr>


<tr><th class="line-num" id="L1010"><a href="#L1010">1010</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L1011"><a href="#L1011">1011</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1012"><a href="#L1012">1012</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1013"><a href="#L1013">1013</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1014"><a href="#L1014">1014</a></th><td class="line-code"><pre> * Function: F_VISITINITIALIZERUNTIME
</pre></td></tr>


<tr><th class="line-num" id="L1015"><a href="#L1015">1015</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1016"><a href="#L1016">1016</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to force the runtime interface to load.
</pre></td></tr>


<tr><th class="line-num" id="L1017"><a href="#L1017">1017</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1018"><a href="#L1018">1018</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1019"><a href="#L1019">1019</a></th><td class="line-code"><pre> * Date:       Mon Oct  1 21:12:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1020"><a href="#L1020">1020</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1021"><a href="#L1021">1021</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1022"><a href="#L1022">1022</a></th><td class="line-code"><pre> *   Brad Whitlock, Tue Oct  2 11:42:28 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1023"><a href="#L1023">1023</a></th><td class="line-code"><pre> *   Install callbacks.
</pre></td></tr>


<tr><th class="line-num" id="L1024"><a href="#L1024">1024</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1025"><a href="#L1025">1025</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1026"><a href="#L1026">1026</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1027"><a href="#L1027">1027</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1028"><a href="#L1028">1028</a></th><td class="line-code"><pre>F_VISITINITIALIZERUNTIME(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L1029"><a href="#L1029">1029</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1030"><a href="#L1030">1030</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret = VisItInitializeRuntime();
</pre></td></tr>


<tr><th class="line-num" id="L1031"><a href="#L1031">1031</a></th><td class="line-code"><pre>    <span class="c">/* Make sure that fortran callbacks are installed. */</span>
</pre></td></tr>


<tr><th class="line-num" id="L1032"><a href="#L1032">1032</a></th><td class="line-code"><pre>    f_visit_internal_InstallCallbacks();
</pre></td></tr>


<tr><th class="line-num" id="L1033"><a href="#L1033">1033</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L1034"><a href="#L1034">1034</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1035"><a href="#L1035">1035</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1036"><a href="#L1036">1036</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1037"><a href="#L1037">1037</a></th><td class="line-code"><pre> * Function: F_VISITADDPLOT
</pre></td></tr>


<tr><th class="line-num" id="L1038"><a href="#L1038">1038</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1039"><a href="#L1039">1039</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to add a plot
</pre></td></tr>


<tr><th class="line-num" id="L1040"><a href="#L1040">1040</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1041"><a href="#L1041">1041</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1042"><a href="#L1042">1042</a></th><td class="line-code"><pre> * Date:       Mon Oct  1 21:12:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1043"><a href="#L1043">1043</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1044"><a href="#L1044">1044</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1045"><a href="#L1045">1045</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1046"><a href="#L1046">1046</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1047"><a href="#L1047">1047</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1048"><a href="#L1048">1048</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1049"><a href="#L1049">1049</a></th><td class="line-code"><pre>F_VISITADDPLOT(<span class="r">const</span> <span class="pt">char</span> *plotType VISIT_F77_MIXED_STRLEN(plotType), <span class="pt">int</span> *lplotType,
</pre></td></tr>


<tr><th class="line-num" id="L1050"><a href="#L1050">1050</a></th><td class="line-code"><pre>               <span class="r">const</span> <span class="pt">char</span> *var      VISIT_F77_MIXED_STRLEN(var),      <span class="pt">int</span> *lvar
</pre></td></tr>


<tr><th class="line-num" id="L1051"><a href="#L1051">1051</a></th><td class="line-code"><pre>               VISIT_F77_END_STRLEN(plotType) VISIT_F77_END_STRLEN(var))
</pre></td></tr>


<tr><th class="line-num" id="L1052"><a href="#L1052">1052</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1053"><a href="#L1053">1053</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret = VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L1054"><a href="#L1054">1054</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_plotType = <span class="pc">NULL</span>, *f_var = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1055"><a href="#L1055">1055</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_plotType, plotType, lplotType);
</pre></td></tr>


<tr><th class="line-num" id="L1056"><a href="#L1056">1056</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_var, var, lvar);
</pre></td></tr>


<tr><th class="line-num" id="L1057"><a href="#L1057">1057</a></th><td class="line-code"><pre>    ret = VisItAddPlot(f_plotType, f_var);
</pre></td></tr>


<tr><th class="line-num" id="L1058"><a href="#L1058">1058</a></th><td class="line-code"><pre>    FREE(f_plotType);
</pre></td></tr>


<tr><th class="line-num" id="L1059"><a href="#L1059">1059</a></th><td class="line-code"><pre>    FREE(f_var);
</pre></td></tr>


<tr><th class="line-num" id="L1060"><a href="#L1060">1060</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L1061"><a href="#L1061">1061</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1062"><a href="#L1062">1062</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1063"><a href="#L1063">1063</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1064"><a href="#L1064">1064</a></th><td class="line-code"><pre> * Function: F_VISITADDOPERATOR
</pre></td></tr>


<tr><th class="line-num" id="L1065"><a href="#L1065">1065</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1066"><a href="#L1066">1066</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to add an operator
</pre></td></tr>


<tr><th class="line-num" id="L1067"><a href="#L1067">1067</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1068"><a href="#L1068">1068</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1069"><a href="#L1069">1069</a></th><td class="line-code"><pre> * Date:       Mon Oct  1 21:12:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1070"><a href="#L1070">1070</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1071"><a href="#L1071">1071</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1072"><a href="#L1072">1072</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1073"><a href="#L1073">1073</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1074"><a href="#L1074">1074</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1075"><a href="#L1075">1075</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1076"><a href="#L1076">1076</a></th><td class="line-code"><pre>F_VISITADDOPERATOR(<span class="r">const</span> <span class="pt">char</span> *operatorType VISIT_F77_MIXED_STRLEN(operatorType), <span class="pt">int</span> *loperatorType,
</pre></td></tr>


<tr><th class="line-num" id="L1077"><a href="#L1077">1077</a></th><td class="line-code"><pre>                   <span class="pt">int</span> *applyToAll VISIT_F77_END_STRLEN(operatorType))
</pre></td></tr>


<tr><th class="line-num" id="L1078"><a href="#L1078">1078</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1079"><a href="#L1079">1079</a></th><td class="line-code"><pre>    <span class="pt">int</span> ret = VISIT_ERROR;
</pre></td></tr>


<tr><th class="line-num" id="L1080"><a href="#L1080">1080</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_operatorType = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1081"><a href="#L1081">1081</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_operatorType, operatorType, loperatorType);
</pre></td></tr>


<tr><th class="line-num" id="L1082"><a href="#L1082">1082</a></th><td class="line-code"><pre>    ret = VisItAddOperator(f_operatorType, *applyToAll);
</pre></td></tr>


<tr><th class="line-num" id="L1083"><a href="#L1083">1083</a></th><td class="line-code"><pre>    FREE(f_operatorType);
</pre></td></tr>


<tr><th class="line-num" id="L1084"><a href="#L1084">1084</a></th><td class="line-code"><pre>    <span class="r">return</span> ret;
</pre></td></tr>


<tr><th class="line-num" id="L1085"><a href="#L1085">1085</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1086"><a href="#L1086">1086</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1087"><a href="#L1087">1087</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1088"><a href="#L1088">1088</a></th><td class="line-code"><pre> * Function: F_VISITDRAWPLOTS
</pre></td></tr>


<tr><th class="line-num" id="L1089"><a href="#L1089">1089</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1090"><a href="#L1090">1090</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to draw a plot
</pre></td></tr>


<tr><th class="line-num" id="L1091"><a href="#L1091">1091</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1092"><a href="#L1092">1092</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1093"><a href="#L1093">1093</a></th><td class="line-code"><pre> * Date:       Mon Oct  1 21:12:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1094"><a href="#L1094">1094</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1095"><a href="#L1095">1095</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1096"><a href="#L1096">1096</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1097"><a href="#L1097">1097</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1098"><a href="#L1098">1098</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1099"><a href="#L1099">1099</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1100"><a href="#L1100">1100</a></th><td class="line-code"><pre>F_VISITDRAWPLOTS(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L1101"><a href="#L1101">1101</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1102"><a href="#L1102">1102</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItDrawPlots();
</pre></td></tr>


<tr><th class="line-num" id="L1103"><a href="#L1103">1103</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1104"><a href="#L1104">1104</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1105"><a href="#L1105">1105</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1106"><a href="#L1106">1106</a></th><td class="line-code"><pre> * Function: F_VISITDELETEACTIVEPLOTS
</pre></td></tr>


<tr><th class="line-num" id="L1107"><a href="#L1107">1107</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1108"><a href="#L1108">1108</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to delete a plot
</pre></td></tr>


<tr><th class="line-num" id="L1109"><a href="#L1109">1109</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1110"><a href="#L1110">1110</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1111"><a href="#L1111">1111</a></th><td class="line-code"><pre> * Date:       Mon Oct  1 21:12:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1112"><a href="#L1112">1112</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1113"><a href="#L1113">1113</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1114"><a href="#L1114">1114</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1115"><a href="#L1115">1115</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1116"><a href="#L1116">1116</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1117"><a href="#L1117">1117</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1118"><a href="#L1118">1118</a></th><td class="line-code"><pre>F_VISITDELETEACTIVEPLOTS(<span class="pt">void</span>)
</pre></td></tr>


<tr><th class="line-num" id="L1119"><a href="#L1119">1119</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1120"><a href="#L1120">1120</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItDeleteActivePlots();
</pre></td></tr>


<tr><th class="line-num" id="L1121"><a href="#L1121">1121</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1122"><a href="#L1122">1122</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1123"><a href="#L1123">1123</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1124"><a href="#L1124">1124</a></th><td class="line-code"><pre> * Function: F_VISITSETACTIVEPLOTS
</pre></td></tr>


<tr><th class="line-num" id="L1125"><a href="#L1125">1125</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1126"><a href="#L1126">1126</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to set the active plots
</pre></td></tr>


<tr><th class="line-num" id="L1127"><a href="#L1127">1127</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1128"><a href="#L1128">1128</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1129"><a href="#L1129">1129</a></th><td class="line-code"><pre> * Date:       Mon Feb  2 15:08:42 PST 2015
</pre></td></tr>


<tr><th class="line-num" id="L1130"><a href="#L1130">1130</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1131"><a href="#L1131">1131</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1132"><a href="#L1132">1132</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1133"><a href="#L1133">1133</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1134"><a href="#L1134">1134</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1135"><a href="#L1135">1135</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1136"><a href="#L1136">1136</a></th><td class="line-code"><pre>F_VISITSETACTIVEPLOTS(<span class="pt">int</span> *ids, <span class="pt">int</span> *nids)
</pre></td></tr>


<tr><th class="line-num" id="L1137"><a href="#L1137">1137</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1138"><a href="#L1138">1138</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItSetActivePlots(ids, *nids);
</pre></td></tr>


<tr><th class="line-num" id="L1139"><a href="#L1139">1139</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1140"><a href="#L1140">1140</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1141"><a href="#L1141">1141</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1142"><a href="#L1142">1142</a></th><td class="line-code"><pre> * Function: F_VISITGETMEMORY
</pre></td></tr>


<tr><th class="line-num" id="L1143"><a href="#L1143">1143</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1144"><a href="#L1144">1144</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to get memory of running simulation
</pre></td></tr>


<tr><th class="line-num" id="L1145"><a href="#L1145">1145</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1146"><a href="#L1146">1146</a></th><td class="line-code"><pre> * Programmer: Satheesh Maheswaran
</pre></td></tr>


<tr><th class="line-num" id="L1147"><a href="#L1147">1147</a></th><td class="line-code"><pre> * Date:       Tues Oct  2 17:04:01 PDT 2012
</pre></td></tr>


<tr><th class="line-num" id="L1148"><a href="#L1148">1148</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1149"><a href="#L1149">1149</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1150"><a href="#L1150">1150</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1151"><a href="#L1151">1151</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1152"><a href="#L1152">1152</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1153"><a href="#L1153">1153</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1154"><a href="#L1154">1154</a></th><td class="line-code"><pre>F_VISITGETMEMORY(<span class="pt">double</span> *m_size, <span class="pt">double</span> *m_rss)
</pre></td></tr>


<tr><th class="line-num" id="L1155"><a href="#L1155">1155</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1156"><a href="#L1156">1156</a></th><td class="line-code"><pre>    <span class="r">return</span> VisItGetMemory(m_size, m_rss);
</pre></td></tr>


<tr><th class="line-num" id="L1157"><a href="#L1157">1157</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1158"><a href="#L1158">1158</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1159"><a href="#L1159">1159</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1160"><a href="#L1160">1160</a></th><td class="line-code"><pre> * Function: F_VISITEXPORTDATABASEWITHOPTIONS
</pre></td></tr>


<tr><th class="line-num" id="L1161"><a href="#L1161">1161</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1162"><a href="#L1162">1162</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to export plots.
</pre></td></tr>


<tr><th class="line-num" id="L1163"><a href="#L1163">1163</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1164"><a href="#L1164">1164</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1165"><a href="#L1165">1165</a></th><td class="line-code"><pre> * Date:       Fri Sep 19 14:15:54 PDT 2014
</pre></td></tr>


<tr><th class="line-num" id="L1166"><a href="#L1166">1166</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1167"><a href="#L1167">1167</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1168"><a href="#L1168">1168</a></th><td class="line-code"><pre> *   Brad Whitlock, Fri Aug 14 11:57:57 PDT 2015
</pre></td></tr>


<tr><th class="line-num" id="L1169"><a href="#L1169">1169</a></th><td class="line-code"><pre> *   Added options.
</pre></td></tr>


<tr><th class="line-num" id="L1170"><a href="#L1170">1170</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1171"><a href="#L1171">1171</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1172"><a href="#L1172">1172</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1173"><a href="#L1173">1173</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1174"><a href="#L1174">1174</a></th><td class="line-code"><pre>F_VISITEXPORTDATABASEWITHOPTIONS(VISIT_F77STRING filename VISIT_F77_MIXED_STRLEN(filename), <span class="pt">int</span> *lfilename,
</pre></td></tr>


<tr><th class="line-num" id="L1175"><a href="#L1175">1175</a></th><td class="line-code"><pre>                                 VISIT_F77STRING format   VISIT_F77_MIXED_STRLEN(format),   <span class="pt">int</span> *lformat,
</pre></td></tr>


<tr><th class="line-num" id="L1176"><a href="#L1176">1176</a></th><td class="line-code"><pre>                                 visit_handle *vars, visit_handle *options
</pre></td></tr>


<tr><th class="line-num" id="L1177"><a href="#L1177">1177</a></th><td class="line-code"><pre>                                 VISIT_F77_END_STRLEN(filename) VISIT_F77_END_STRLEN(format) )
</pre></td></tr>


<tr><th class="line-num" id="L1178"><a href="#L1178">1178</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1179"><a href="#L1179">1179</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1180"><a href="#L1180">1180</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_filename = <span class="pc">NULL</span>, *f_format = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1181"><a href="#L1181">1181</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1182"><a href="#L1182">1182</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_filename, filename, lfilename);
</pre></td></tr>


<tr><th class="line-num" id="L1183"><a href="#L1183">1183</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_format, format, lformat);
</pre></td></tr>


<tr><th class="line-num" id="L1184"><a href="#L1184">1184</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1185"><a href="#L1185">1185</a></th><td class="line-code"><pre>    retval = VisItExportDatabaseWithOptions(f_filename, f_format, *vars, *options);
</pre></td></tr>


<tr><th class="line-num" id="L1186"><a href="#L1186">1186</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1187"><a href="#L1187">1187</a></th><td class="line-code"><pre>    FREE(f_filename);
</pre></td></tr>


<tr><th class="line-num" id="L1188"><a href="#L1188">1188</a></th><td class="line-code"><pre>    FREE(f_format);
</pre></td></tr>


<tr><th class="line-num" id="L1189"><a href="#L1189">1189</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1190"><a href="#L1190">1190</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1191"><a href="#L1191">1191</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1192"><a href="#L1192">1192</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1193"><a href="#L1193">1193</a></th><td class="line-code"><pre> * Function: F_VISITEXPORTDATABASE
</pre></td></tr>


<tr><th class="line-num" id="L1194"><a href="#L1194">1194</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1195"><a href="#L1195">1195</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to export plots.
</pre></td></tr>


<tr><th class="line-num" id="L1196"><a href="#L1196">1196</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1197"><a href="#L1197">1197</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1198"><a href="#L1198">1198</a></th><td class="line-code"><pre> * Date:       Fri Sep 19 14:15:54 PDT 2014
</pre></td></tr>


<tr><th class="line-num" id="L1199"><a href="#L1199">1199</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1200"><a href="#L1200">1200</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1201"><a href="#L1201">1201</a></th><td class="line-code"><pre> *   Brad Whitlock, Fri Aug 14 11:57:57 PDT 2015
</pre></td></tr>


<tr><th class="line-num" id="L1202"><a href="#L1202">1202</a></th><td class="line-code"><pre> *   Added options.
</pre></td></tr>


<tr><th class="line-num" id="L1203"><a href="#L1203">1203</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1204"><a href="#L1204">1204</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1205"><a href="#L1205">1205</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1206"><a href="#L1206">1206</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1207"><a href="#L1207">1207</a></th><td class="line-code"><pre>F_VISITEXPORTDATABASE(VISIT_F77STRING filename VISIT_F77_MIXED_STRLEN(filename), <span class="pt">int</span> *lfilename,
</pre></td></tr>


<tr><th class="line-num" id="L1208"><a href="#L1208">1208</a></th><td class="line-code"><pre>                      VISIT_F77STRING format   VISIT_F77_MIXED_STRLEN(format),   <span class="pt">int</span> *lformat,
</pre></td></tr>


<tr><th class="line-num" id="L1209"><a href="#L1209">1209</a></th><td class="line-code"><pre>                      visit_handle *vars
</pre></td></tr>


<tr><th class="line-num" id="L1210"><a href="#L1210">1210</a></th><td class="line-code"><pre>                      VISIT_F77_END_STRLEN(filename) VISIT_F77_END_STRLEN(format))
</pre></td></tr>


<tr><th class="line-num" id="L1211"><a href="#L1211">1211</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1212"><a href="#L1212">1212</a></th><td class="line-code"><pre>    <span class="pt">int</span> no_options = VISIT_INVALID_HANDLE;
</pre></td></tr>


<tr><th class="line-num" id="L1213"><a href="#L1213">1213</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITEXPORTDATABASEWITHOPTIONS(filename, lfilename, format, lformat, vars, &amp;no_options, strlen(filename), strlen(format));
</pre></td></tr>


<tr><th class="line-num" id="L1214"><a href="#L1214">1214</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1215"><a href="#L1215">1215</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1216"><a href="#L1216">1216</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1217"><a href="#L1217">1217</a></th><td class="line-code"><pre> * Function: F_VISITRESTORESESSION
</pre></td></tr>


<tr><th class="line-num" id="L1218"><a href="#L1218">1218</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1219"><a href="#L1219">1219</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to restore a session file.
</pre></td></tr>


<tr><th class="line-num" id="L1220"><a href="#L1220">1220</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1221"><a href="#L1221">1221</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1222"><a href="#L1222">1222</a></th><td class="line-code"><pre> * Date:       Fri Sep 19 14:15:54 PDT 2014
</pre></td></tr>


<tr><th class="line-num" id="L1223"><a href="#L1223">1223</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1224"><a href="#L1224">1224</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1225"><a href="#L1225">1225</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1226"><a href="#L1226">1226</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1227"><a href="#L1227">1227</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1228"><a href="#L1228">1228</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1229"><a href="#L1229">1229</a></th><td class="line-code"><pre>F_VISITRESTORESESSION(VISIT_F77STRING filename VISIT_F77_MIXED_STRLEN(filename), <span class="pt">int</span> *lfilename VISIT_F77_END_STRLEN(filename))
</pre></td></tr>


<tr><th class="line-num" id="L1230"><a href="#L1230">1230</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1231"><a href="#L1231">1231</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1232"><a href="#L1232">1232</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_filename = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1233"><a href="#L1233">1233</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1234"><a href="#L1234">1234</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_filename, filename, lfilename);
</pre></td></tr>


<tr><th class="line-num" id="L1235"><a href="#L1235">1235</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1236"><a href="#L1236">1236</a></th><td class="line-code"><pre>    retval = VisItRestoreSession(f_filename);
</pre></td></tr>


<tr><th class="line-num" id="L1237"><a href="#L1237">1237</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1238"><a href="#L1238">1238</a></th><td class="line-code"><pre>    FREE(f_filename);
</pre></td></tr>


<tr><th class="line-num" id="L1239"><a href="#L1239">1239</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1240"><a href="#L1240">1240</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1241"><a href="#L1241">1241</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1242"><a href="#L1242">1242</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1243"><a href="#L1243">1243</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1244"><a href="#L1244">1244</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSC    F77_ID(visitsetplotoptionsc_,visitsetplotoptionsc,VISITSETPLOTOPTIONSC)
</pre></td></tr>


<tr><th class="line-num" id="L1245"><a href="#L1245">1245</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSUC   F77_ID(visitsetplotoptionsuc_,visitsetplotoptionsuc,VISITSETPLOTOPTIONSUC)
</pre></td></tr>


<tr><th class="line-num" id="L1246"><a href="#L1246">1246</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSB    F77_ID(visitsetplotoptionsb_,visitsetplotoptionsb,VISITSETPLOTOPTIONSB)
</pre></td></tr>


<tr><th class="line-num" id="L1247"><a href="#L1247">1247</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSI    F77_ID(visitsetplotoptionsi_,visitsetplotoptionsi,VISITSETPLOTOPTIONSI)
</pre></td></tr>


<tr><th class="line-num" id="L1248"><a href="#L1248">1248</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSL    F77_ID(visitsetplotoptionsl_,visitsetplotoptionsl,VISITSETPLOTOPTIONSL)
</pre></td></tr>


<tr><th class="line-num" id="L1249"><a href="#L1249">1249</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSF    F77_ID(visitsetplotoptionsf_,visitsetplotoptionsf,VISITSETPLOTOPTIONSF)
</pre></td></tr>


<tr><th class="line-num" id="L1250"><a href="#L1250">1250</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSD    F77_ID(visitsetplotoptionsd_,visitsetplotoptionsd,VISITSETPLOTOPTIONSD)
</pre></td></tr>


<tr><th class="line-num" id="L1251"><a href="#L1251">1251</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSS    F77_ID(visitsetplotoptionss_,visitsetplotoptionss,VISITSETPLOTOPTIONSS)
</pre></td></tr>


<tr><th class="line-num" id="L1252"><a href="#L1252">1252</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSCV   F77_ID(visitsetplotoptionscv_,visitsetplotoptionscv,VISITSETPLOTOPTIONSCV)
</pre></td></tr>


<tr><th class="line-num" id="L1253"><a href="#L1253">1253</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSUCV  F77_ID(visitsetplotoptionsucv_,visitsetplotoptionsucv,VISITSETPLOTOPTIONSUCV)
</pre></td></tr>


<tr><th class="line-num" id="L1254"><a href="#L1254">1254</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSIV   F77_ID(visitsetplotoptionsiv_,visitsetplotoptionsiv,VISITSETPLOTOPTIONSIV)
</pre></td></tr>


<tr><th class="line-num" id="L1255"><a href="#L1255">1255</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSLV   F77_ID(visitsetplotoptionslv_,visitsetplotoptionslv,VISITSETPLOTOPTIONSLV)
</pre></td></tr>


<tr><th class="line-num" id="L1256"><a href="#L1256">1256</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSFV   F77_ID(visitsetplotoptionsfv_,visitsetplotoptionsfv,VISITSETPLOTOPTIONSFV)
</pre></td></tr>


<tr><th class="line-num" id="L1257"><a href="#L1257">1257</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSDV   F77_ID(visitsetplotoptionsdv_,visitsetplotoptionsdv,VISITSETPLOTOPTIONSDV)
</pre></td></tr>


<tr><th class="line-num" id="L1258"><a href="#L1258">1258</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETPLOTOPTIONSSV   F77_ID(visitsetplotoptionssv_,visitsetplotoptionssv,VISITSETPLOTOPTIONSSV)
</pre></td></tr>


<tr><th class="line-num" id="L1259"><a href="#L1259">1259</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1260"><a href="#L1260">1260</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSC(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">char</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1261"><a href="#L1261">1261</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1262"><a href="#L1262">1262</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1263"><a href="#L1263">1263</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1264"><a href="#L1264">1264</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1265"><a href="#L1265">1265</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsC(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1266"><a href="#L1266">1266</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1267"><a href="#L1267">1267</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1268"><a href="#L1268">1268</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1269"><a href="#L1269">1269</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSUC(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">unsigned</span> <span class="pt">char</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1270"><a href="#L1270">1270</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1271"><a href="#L1271">1271</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1272"><a href="#L1272">1272</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1273"><a href="#L1273">1273</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1274"><a href="#L1274">1274</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsUC(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1275"><a href="#L1275">1275</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1276"><a href="#L1276">1276</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1277"><a href="#L1277">1277</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1278"><a href="#L1278">1278</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSB(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">int</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1279"><a href="#L1279">1279</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1280"><a href="#L1280">1280</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1281"><a href="#L1281">1281</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1282"><a href="#L1282">1282</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1283"><a href="#L1283">1283</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsI(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1284"><a href="#L1284">1284</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1285"><a href="#L1285">1285</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1286"><a href="#L1286">1286</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1287"><a href="#L1287">1287</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSI(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">int</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1288"><a href="#L1288">1288</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1289"><a href="#L1289">1289</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1290"><a href="#L1290">1290</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1291"><a href="#L1291">1291</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1292"><a href="#L1292">1292</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsI(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1293"><a href="#L1293">1293</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1294"><a href="#L1294">1294</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1295"><a href="#L1295">1295</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1296"><a href="#L1296">1296</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSL(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">long</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1297"><a href="#L1297">1297</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1298"><a href="#L1298">1298</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1299"><a href="#L1299">1299</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1300"><a href="#L1300">1300</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1301"><a href="#L1301">1301</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsL(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1302"><a href="#L1302">1302</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1303"><a href="#L1303">1303</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1304"><a href="#L1304">1304</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1305"><a href="#L1305">1305</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSF(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">float</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1306"><a href="#L1306">1306</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1307"><a href="#L1307">1307</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1308"><a href="#L1308">1308</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1309"><a href="#L1309">1309</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1310"><a href="#L1310">1310</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsF(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1311"><a href="#L1311">1311</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1312"><a href="#L1312">1312</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1313"><a href="#L1313">1313</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1314"><a href="#L1314">1314</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSD(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">double</span> *v VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1315"><a href="#L1315">1315</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1316"><a href="#L1316">1316</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1317"><a href="#L1317">1317</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1318"><a href="#L1318">1318</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1319"><a href="#L1319">1319</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsD(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1320"><a href="#L1320">1320</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1321"><a href="#L1321">1321</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1322"><a href="#L1322">1322</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1323"><a href="#L1323">1323</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSS(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">char</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1324"><a href="#L1324">1324</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1325"><a href="#L1325">1325</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1326"><a href="#L1326">1326</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>, *f_value = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1327"><a href="#L1327">1327</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1328"><a href="#L1328">1328</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_value, v, lv);
</pre></td></tr>


<tr><th class="line-num" id="L1329"><a href="#L1329">1329</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsS(f_name, f_value);
</pre></td></tr>


<tr><th class="line-num" id="L1330"><a href="#L1330">1330</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1331"><a href="#L1331">1331</a></th><td class="line-code"><pre>    FREE(f_value);
</pre></td></tr>


<tr><th class="line-num" id="L1332"><a href="#L1332">1332</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1333"><a href="#L1333">1333</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1334"><a href="#L1334">1334</a></th><td class="line-code"><pre><span class="c">/* array/vector functions */</span>
</pre></td></tr>


<tr><th class="line-num" id="L1335"><a href="#L1335">1335</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSCV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">char</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1336"><a href="#L1336">1336</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1337"><a href="#L1337">1337</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1338"><a href="#L1338">1338</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1339"><a href="#L1339">1339</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1340"><a href="#L1340">1340</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsCv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1341"><a href="#L1341">1341</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1342"><a href="#L1342">1342</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1343"><a href="#L1343">1343</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1344"><a href="#L1344">1344</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSUCV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">unsigned</span> <span class="pt">char</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1345"><a href="#L1345">1345</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1346"><a href="#L1346">1346</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1347"><a href="#L1347">1347</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1348"><a href="#L1348">1348</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1349"><a href="#L1349">1349</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsUCv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1350"><a href="#L1350">1350</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1351"><a href="#L1351">1351</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1352"><a href="#L1352">1352</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1353"><a href="#L1353">1353</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSIV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">int</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1354"><a href="#L1354">1354</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1355"><a href="#L1355">1355</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1356"><a href="#L1356">1356</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1357"><a href="#L1357">1357</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1358"><a href="#L1358">1358</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsIv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1359"><a href="#L1359">1359</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1360"><a href="#L1360">1360</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1361"><a href="#L1361">1361</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1362"><a href="#L1362">1362</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSLV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">long</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1363"><a href="#L1363">1363</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1364"><a href="#L1364">1364</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1365"><a href="#L1365">1365</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1366"><a href="#L1366">1366</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1367"><a href="#L1367">1367</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsLv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1368"><a href="#L1368">1368</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1369"><a href="#L1369">1369</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1370"><a href="#L1370">1370</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1371"><a href="#L1371">1371</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSFV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">float</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1372"><a href="#L1372">1372</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1373"><a href="#L1373">1373</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1374"><a href="#L1374">1374</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1375"><a href="#L1375">1375</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1376"><a href="#L1376">1376</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsFv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1377"><a href="#L1377">1377</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1378"><a href="#L1378">1378</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1379"><a href="#L1379">1379</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1380"><a href="#L1380">1380</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSDV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">double</span> *v, <span class="pt">int</span> *lv VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1381"><a href="#L1381">1381</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1382"><a href="#L1382">1382</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1383"><a href="#L1383">1383</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1384"><a href="#L1384">1384</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1385"><a href="#L1385">1385</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsDv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1386"><a href="#L1386">1386</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1387"><a href="#L1387">1387</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1388"><a href="#L1388">1388</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1389"><a href="#L1389">1389</a></th><td class="line-code"><pre>FORTRAN F_VISITSETPLOTOPTIONSSV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname, <span class="pt">char</span> *v, <span class="pt">int</span> *lv, <span class="pt">int</span> *stringWidth VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1390"><a href="#L1390">1390</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1391"><a href="#L1391">1391</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1392"><a href="#L1392">1392</a></th><td class="line-code"><pre>    <span class="pt">int</span> i;
</pre></td></tr>


<tr><th class="line-num" id="L1393"><a href="#L1393">1393</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>, **f_values = <span class="pc">NULL</span>, *start = <span class="pc">NULL</span>, *tmp = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1394"><a href="#L1394">1394</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1395"><a href="#L1395">1395</a></th><td class="line-code"><pre>    f_values = (<span class="pt">char</span> **)malloc(*lv * <span class="r">sizeof</span>(<span class="pt">char</span>*));
</pre></td></tr>


<tr><th class="line-num" id="L1396"><a href="#L1396">1396</a></th><td class="line-code"><pre>    start = v;
</pre></td></tr>


<tr><th class="line-num" id="L1397"><a href="#L1397">1397</a></th><td class="line-code"><pre>    <span class="r">for</span>(i = <span class="i">0</span>; i &lt; *lv; ++i)
</pre></td></tr>


<tr><th class="line-num" id="L1398"><a href="#L1398">1398</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L1399"><a href="#L1399">1399</a></th><td class="line-code"><pre>        COPY_FORTRAN_STRING(tmp, start, stringWidth);
</pre></td></tr>


<tr><th class="line-num" id="L1400"><a href="#L1400">1400</a></th><td class="line-code"><pre>        f_values[i] = tmp;
</pre></td></tr>


<tr><th class="line-num" id="L1401"><a href="#L1401">1401</a></th><td class="line-code"><pre>        start += *stringWidth;
</pre></td></tr>


<tr><th class="line-num" id="L1402"><a href="#L1402">1402</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L1403"><a href="#L1403">1403</a></th><td class="line-code"><pre>    retval = VisItSetPlotOptionsSv(f_name, (<span class="r">const</span> <span class="pt">char</span> **)f_values, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1404"><a href="#L1404">1404</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1405"><a href="#L1405">1405</a></th><td class="line-code"><pre>    <span class="r">for</span>(i = <span class="i">0</span>; i &lt; *lv; ++i)
</pre></td></tr>


<tr><th class="line-num" id="L1406"><a href="#L1406">1406</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L1407"><a href="#L1407">1407</a></th><td class="line-code"><pre>        FREE(f_values[i]);
</pre></td></tr>


<tr><th class="line-num" id="L1408"><a href="#L1408">1408</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L1409"><a href="#L1409">1409</a></th><td class="line-code"><pre>    FREE(f_values);
</pre></td></tr>


<tr><th class="line-num" id="L1410"><a href="#L1410">1410</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1411"><a href="#L1411">1411</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1412"><a href="#L1412">1412</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1413"><a href="#L1413">1413</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1414"><a href="#L1414">1414</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1415"><a href="#L1415">1415</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSC    F77_ID(visitsetoperatoroptionsc_,visitsetoperatoroptionsc,VISITSETOPERATOROPTIONSC)
</pre></td></tr>


<tr><th class="line-num" id="L1416"><a href="#L1416">1416</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSUC   F77_ID(visitsetoperatoroptionsuc_,visitsetoperatoroptionsuc,VISITSETOPERATOROPTIONSUC)
</pre></td></tr>


<tr><th class="line-num" id="L1417"><a href="#L1417">1417</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSB    F77_ID(visitsetoperatoroptionsb_,visitsetoperatoroptionsb,VISITSETOPERATOROPTIONSB)
</pre></td></tr>


<tr><th class="line-num" id="L1418"><a href="#L1418">1418</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSI    F77_ID(visitsetoperatoroptionsi_,visitsetoperatoroptionsi,VISITSETOPERATOROPTIONSI)
</pre></td></tr>


<tr><th class="line-num" id="L1419"><a href="#L1419">1419</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSL    F77_ID(visitsetoperatoroptionsl_,visitsetoperatoroptionsl,VISITSETOPERATOROPTIONSL)
</pre></td></tr>


<tr><th class="line-num" id="L1420"><a href="#L1420">1420</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSF    F77_ID(visitsetoperatoroptionsf_,visitsetoperatoroptionsf,VISITSETOPERATOROPTIONSF)
</pre></td></tr>


<tr><th class="line-num" id="L1421"><a href="#L1421">1421</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSD    F77_ID(visitsetoperatoroptionsd_,visitsetoperatoroptionsd,VISITSETOPERATOROPTIONSD)
</pre></td></tr>


<tr><th class="line-num" id="L1422"><a href="#L1422">1422</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSS    F77_ID(visitsetoperatoroptionss_,visitsetoperatoroptionss,VISITSETOPERATOROPTIONSS)
</pre></td></tr>


<tr><th class="line-num" id="L1423"><a href="#L1423">1423</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSCV   F77_ID(visitsetoperatoroptionscv_,visitsetoperatoroptionscv,VISITSETOPERATOROPTIONSCV)
</pre></td></tr>


<tr><th class="line-num" id="L1424"><a href="#L1424">1424</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSUCV  F77_ID(visitsetoperatoroptionsucv_,visitsetoperatoroptionsucv,VISITSETOPERATOROPTIONSUCV)
</pre></td></tr>


<tr><th class="line-num" id="L1425"><a href="#L1425">1425</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSIV   F77_ID(visitsetoperatoroptionsiv_,visitsetoperatoroptionsiv,VISITSETOPERATOROPTIONSIV)
</pre></td></tr>


<tr><th class="line-num" id="L1426"><a href="#L1426">1426</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSLV   F77_ID(visitsetoperatoroptionslv_,visitsetoperatoroptionslv,VISITSETOPERATOROPTIONSLV)
</pre></td></tr>


<tr><th class="line-num" id="L1427"><a href="#L1427">1427</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSFV   F77_ID(visitsetoperatoroptionsfv_,visitsetoperatoroptionsfv,VISITSETOPERATOROPTIONSFV)
</pre></td></tr>


<tr><th class="line-num" id="L1428"><a href="#L1428">1428</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSDV   F77_ID(visitsetoperatoroptionsdv_,visitsetoperatoroptionsdv,VISITSETOPERATOROPTIONSDV)
</pre></td></tr>


<tr><th class="line-num" id="L1429"><a href="#L1429">1429</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSETOPERATOROPTIONSSV   F77_ID(visitsetoperatoroptionssv_,visitsetoperatoroptionssv,VISITSETOPERATOROPTIONSSV)
</pre></td></tr>


<tr><th class="line-num" id="L1430"><a href="#L1430">1430</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1431"><a href="#L1431">1431</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSC(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1432"><a href="#L1432">1432</a></th><td class="line-code"><pre>                                   <span class="pt">char</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1433"><a href="#L1433">1433</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1434"><a href="#L1434">1434</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1435"><a href="#L1435">1435</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1436"><a href="#L1436">1436</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1437"><a href="#L1437">1437</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1438"><a href="#L1438">1438</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsC(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1439"><a href="#L1439">1439</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1440"><a href="#L1440">1440</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1441"><a href="#L1441">1441</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1442"><a href="#L1442">1442</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSUC(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1443"><a href="#L1443">1443</a></th><td class="line-code"><pre>                                    <span class="pt">unsigned</span> <span class="pt">char</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1444"><a href="#L1444">1444</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1445"><a href="#L1445">1445</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1446"><a href="#L1446">1446</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1447"><a href="#L1447">1447</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1448"><a href="#L1448">1448</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1449"><a href="#L1449">1449</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsUC(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1450"><a href="#L1450">1450</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1451"><a href="#L1451">1451</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1452"><a href="#L1452">1452</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1453"><a href="#L1453">1453</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSB(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1454"><a href="#L1454">1454</a></th><td class="line-code"><pre>                                   <span class="pt">int</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1455"><a href="#L1455">1455</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1456"><a href="#L1456">1456</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1457"><a href="#L1457">1457</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1458"><a href="#L1458">1458</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1459"><a href="#L1459">1459</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1460"><a href="#L1460">1460</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsI(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1461"><a href="#L1461">1461</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1462"><a href="#L1462">1462</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1463"><a href="#L1463">1463</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1464"><a href="#L1464">1464</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSI(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1465"><a href="#L1465">1465</a></th><td class="line-code"><pre>                                   <span class="pt">int</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1466"><a href="#L1466">1466</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1467"><a href="#L1467">1467</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1468"><a href="#L1468">1468</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1469"><a href="#L1469">1469</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1470"><a href="#L1470">1470</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1471"><a href="#L1471">1471</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsI(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1472"><a href="#L1472">1472</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1473"><a href="#L1473">1473</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1474"><a href="#L1474">1474</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1475"><a href="#L1475">1475</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSL(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1476"><a href="#L1476">1476</a></th><td class="line-code"><pre>                                   <span class="pt">long</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1477"><a href="#L1477">1477</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1478"><a href="#L1478">1478</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1479"><a href="#L1479">1479</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1480"><a href="#L1480">1480</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1481"><a href="#L1481">1481</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1482"><a href="#L1482">1482</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsL(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1483"><a href="#L1483">1483</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1484"><a href="#L1484">1484</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1485"><a href="#L1485">1485</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1486"><a href="#L1486">1486</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSF(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1487"><a href="#L1487">1487</a></th><td class="line-code"><pre>                                   <span class="pt">float</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1488"><a href="#L1488">1488</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1489"><a href="#L1489">1489</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1490"><a href="#L1490">1490</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1491"><a href="#L1491">1491</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1492"><a href="#L1492">1492</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1493"><a href="#L1493">1493</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsF(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1494"><a href="#L1494">1494</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1495"><a href="#L1495">1495</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1496"><a href="#L1496">1496</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1497"><a href="#L1497">1497</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSD(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1498"><a href="#L1498">1498</a></th><td class="line-code"><pre>                                   <span class="pt">double</span> *v
</pre></td></tr>


<tr><th class="line-num" id="L1499"><a href="#L1499">1499</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1500"><a href="#L1500">1500</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1501"><a href="#L1501">1501</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1502"><a href="#L1502">1502</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1503"><a href="#L1503">1503</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1504"><a href="#L1504">1504</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsD(f_name, *v);
</pre></td></tr>


<tr><th class="line-num" id="L1505"><a href="#L1505">1505</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1506"><a href="#L1506">1506</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1507"><a href="#L1507">1507</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1508"><a href="#L1508">1508</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSS(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1509"><a href="#L1509">1509</a></th><td class="line-code"><pre>                                   VISIT_F77STRING v    VISIT_F77_MIXED_STRLEN(v), <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1510"><a href="#L1510">1510</a></th><td class="line-code"><pre>                                   VISIT_F77_END_STRLEN(name) VISIT_F77_END_STRLEN(v))
</pre></td></tr>


<tr><th class="line-num" id="L1511"><a href="#L1511">1511</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1512"><a href="#L1512">1512</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1513"><a href="#L1513">1513</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>, *f_value = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1514"><a href="#L1514">1514</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1515"><a href="#L1515">1515</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_value, v, lv);
</pre></td></tr>


<tr><th class="line-num" id="L1516"><a href="#L1516">1516</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsS(f_name, f_value);
</pre></td></tr>


<tr><th class="line-num" id="L1517"><a href="#L1517">1517</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1518"><a href="#L1518">1518</a></th><td class="line-code"><pre>    FREE(f_value);
</pre></td></tr>


<tr><th class="line-num" id="L1519"><a href="#L1519">1519</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1520"><a href="#L1520">1520</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1521"><a href="#L1521">1521</a></th><td class="line-code"><pre><span class="c">/* array/vector functions */</span>
</pre></td></tr>


<tr><th class="line-num" id="L1522"><a href="#L1522">1522</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSCV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1523"><a href="#L1523">1523</a></th><td class="line-code"><pre>                                    <span class="pt">char</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1524"><a href="#L1524">1524</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1525"><a href="#L1525">1525</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1526"><a href="#L1526">1526</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1527"><a href="#L1527">1527</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1528"><a href="#L1528">1528</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1529"><a href="#L1529">1529</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsCv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1530"><a href="#L1530">1530</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1531"><a href="#L1531">1531</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1532"><a href="#L1532">1532</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1533"><a href="#L1533">1533</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSUCV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1534"><a href="#L1534">1534</a></th><td class="line-code"><pre>                                     <span class="pt">unsigned</span> <span class="pt">char</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1535"><a href="#L1535">1535</a></th><td class="line-code"><pre>                                     VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1536"><a href="#L1536">1536</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1537"><a href="#L1537">1537</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1538"><a href="#L1538">1538</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1539"><a href="#L1539">1539</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1540"><a href="#L1540">1540</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsUCv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1541"><a href="#L1541">1541</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1542"><a href="#L1542">1542</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1543"><a href="#L1543">1543</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1544"><a href="#L1544">1544</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSIV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1545"><a href="#L1545">1545</a></th><td class="line-code"><pre>                                    <span class="pt">int</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1546"><a href="#L1546">1546</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1547"><a href="#L1547">1547</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1548"><a href="#L1548">1548</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1549"><a href="#L1549">1549</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1550"><a href="#L1550">1550</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1551"><a href="#L1551">1551</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsIv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1552"><a href="#L1552">1552</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1553"><a href="#L1553">1553</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1554"><a href="#L1554">1554</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1555"><a href="#L1555">1555</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSLV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1556"><a href="#L1556">1556</a></th><td class="line-code"><pre>                                    <span class="pt">long</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1557"><a href="#L1557">1557</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1558"><a href="#L1558">1558</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1559"><a href="#L1559">1559</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1560"><a href="#L1560">1560</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1561"><a href="#L1561">1561</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1562"><a href="#L1562">1562</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsLv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1563"><a href="#L1563">1563</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1564"><a href="#L1564">1564</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1565"><a href="#L1565">1565</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1566"><a href="#L1566">1566</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSFV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1567"><a href="#L1567">1567</a></th><td class="line-code"><pre>                                    <span class="pt">float</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1568"><a href="#L1568">1568</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1569"><a href="#L1569">1569</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1570"><a href="#L1570">1570</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1571"><a href="#L1571">1571</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1572"><a href="#L1572">1572</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1573"><a href="#L1573">1573</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsFv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1574"><a href="#L1574">1574</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1575"><a href="#L1575">1575</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1576"><a href="#L1576">1576</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1577"><a href="#L1577">1577</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSDV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1578"><a href="#L1578">1578</a></th><td class="line-code"><pre>                                    <span class="pt">double</span> *v, <span class="pt">int</span> *lv
</pre></td></tr>


<tr><th class="line-num" id="L1579"><a href="#L1579">1579</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1580"><a href="#L1580">1580</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1581"><a href="#L1581">1581</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1582"><a href="#L1582">1582</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1583"><a href="#L1583">1583</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1584"><a href="#L1584">1584</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsDv(f_name, v, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1585"><a href="#L1585">1585</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1586"><a href="#L1586">1586</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1587"><a href="#L1587">1587</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1588"><a href="#L1588">1588</a></th><td class="line-code"><pre>FORTRAN F_VISITSETOPERATOROPTIONSSV(VISIT_F77STRING name VISIT_F77_MIXED_STRLEN(name), <span class="pt">int</span> *lname,
</pre></td></tr>


<tr><th class="line-num" id="L1589"><a href="#L1589">1589</a></th><td class="line-code"><pre>                                    <span class="pt">char</span> *v, <span class="pt">int</span> *lv, <span class="pt">int</span> *stringWidth
</pre></td></tr>


<tr><th class="line-num" id="L1590"><a href="#L1590">1590</a></th><td class="line-code"><pre>                                    VISIT_F77_END_STRLEN(name))
</pre></td></tr>


<tr><th class="line-num" id="L1591"><a href="#L1591">1591</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1592"><a href="#L1592">1592</a></th><td class="line-code"><pre>    FORTRAN retval;
</pre></td></tr>


<tr><th class="line-num" id="L1593"><a href="#L1593">1593</a></th><td class="line-code"><pre>    <span class="pt">int</span> i;
</pre></td></tr>


<tr><th class="line-num" id="L1594"><a href="#L1594">1594</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_name = <span class="pc">NULL</span>, **f_values = <span class="pc">NULL</span>, *start = <span class="pc">NULL</span>, *tmp = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1595"><a href="#L1595">1595</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_name, name, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1596"><a href="#L1596">1596</a></th><td class="line-code"><pre>    f_values = (<span class="pt">char</span> **)malloc(*lv * <span class="r">sizeof</span>(<span class="pt">char</span>*));
</pre></td></tr>


<tr><th class="line-num" id="L1597"><a href="#L1597">1597</a></th><td class="line-code"><pre>    start = v;
</pre></td></tr>


<tr><th class="line-num" id="L1598"><a href="#L1598">1598</a></th><td class="line-code"><pre>    <span class="r">for</span>(i = <span class="i">0</span>; i &lt; *lv; ++i)
</pre></td></tr>


<tr><th class="line-num" id="L1599"><a href="#L1599">1599</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L1600"><a href="#L1600">1600</a></th><td class="line-code"><pre>        COPY_FORTRAN_STRING(tmp, start, stringWidth);
</pre></td></tr>


<tr><th class="line-num" id="L1601"><a href="#L1601">1601</a></th><td class="line-code"><pre>        f_values[i] = tmp;
</pre></td></tr>


<tr><th class="line-num" id="L1602"><a href="#L1602">1602</a></th><td class="line-code"><pre>        start += *stringWidth;
</pre></td></tr>


<tr><th class="line-num" id="L1603"><a href="#L1603">1603</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L1604"><a href="#L1604">1604</a></th><td class="line-code"><pre>    retval = VisItSetOperatorOptionsSv(f_name, (<span class="r">const</span> <span class="pt">char</span> **)f_values, *lv);
</pre></td></tr>


<tr><th class="line-num" id="L1605"><a href="#L1605">1605</a></th><td class="line-code"><pre>    FREE(f_name);
</pre></td></tr>


<tr><th class="line-num" id="L1606"><a href="#L1606">1606</a></th><td class="line-code"><pre>    <span class="r">for</span>(i = <span class="i">0</span>; i &lt; *lv; ++i)
</pre></td></tr>


<tr><th class="line-num" id="L1607"><a href="#L1607">1607</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L1608"><a href="#L1608">1608</a></th><td class="line-code"><pre>        FREE(f_values[i]);
</pre></td></tr>


<tr><th class="line-num" id="L1609"><a href="#L1609">1609</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L1610"><a href="#L1610">1610</a></th><td class="line-code"><pre>    FREE(f_values);
</pre></td></tr>


<tr><th class="line-num" id="L1611"><a href="#L1611">1611</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1612"><a href="#L1612">1612</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1613"><a href="#L1613">1613</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1614"><a href="#L1614">1614</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1615"><a href="#L1615">1615</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1616"><a href="#L1616">1616</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1617"><a href="#L1617">1617</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1618"><a href="#L1618">1618</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1619"><a href="#L1619">1619</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1620"><a href="#L1620">1620</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L1621"><a href="#L1621">1621</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L1622"><a href="#L1622">1622</a></th><td class="line-code"><pre> ********* DATA INTERFACE FUNCTIONS
</pre></td></tr>


<tr><th class="line-num" id="L1623"><a href="#L1623">1623</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L1624"><a href="#L1624">1624</a></th><td class="line-code"><pre> *********
</pre></td></tr>


<tr><th class="line-num" id="L1625"><a href="#L1625">1625</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1626"><a href="#L1626">1626</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1627"><a href="#L1627">1627</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1628"><a href="#L1628">1628</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1629"><a href="#L1629">1629</a></th><td class="line-code"><pre> ******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1630"><a href="#L1630">1630</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1631"><a href="#L1631">1631</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1632"><a href="#L1632">1632</a></th><td class="line-code"><pre><span class="c">/* Functions to be provided in the Fortran application */</span>
</pre></td></tr>


<tr><th class="line-num" id="L1633"><a href="#L1633">1633</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITACTIVATETIMESTEP F77_ID(visitactivatetimestep_,visitactivatetimestep,VISITACTIVATETIMESTEP)
</pre></td></tr>


<tr><th class="line-num" id="L1634"><a href="#L1634">1634</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETMETADATA      F77_ID(visitgetmetadata_,visitgetmetadata,VISITGETMETADATA)
</pre></td></tr>


<tr><th class="line-num" id="L1635"><a href="#L1635">1635</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETMESH          F77_ID(visitgetmesh_,visitgetmesh,VISITGETMESH)
</pre></td></tr>


<tr><th class="line-num" id="L1636"><a href="#L1636">1636</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETVARIABLE      F77_ID(visitgetvariable_,visitgetvariable,VISITGETVARIABLE)
</pre></td></tr>


<tr><th class="line-num" id="L1637"><a href="#L1637">1637</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETMIXEDVARIABLE F77_ID(visitgetmixedvariable_,visitgetmixedvariable,VISITGETMIXEDVARIABLE)
</pre></td></tr>


<tr><th class="line-num" id="L1638"><a href="#L1638">1638</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETMATERIAL      F77_ID(visitgetmaterial_,visitgetmaterial,VISITGETMATERIAL)
</pre></td></tr>


<tr><th class="line-num" id="L1639"><a href="#L1639">1639</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETCURVE         F77_ID(visitgetcurve_,visitgetcurve,VISITGETCURVE)
</pre></td></tr>


<tr><th class="line-num" id="L1640"><a href="#L1640">1640</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETDOMAINLIST    F77_ID(visitgetdomainlist_,visitgetdomainlist,VISITGETDOMAINLIST)
</pre></td></tr>


<tr><th class="line-num" id="L1641"><a href="#L1641">1641</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETDOMAINBOUNDS  F77_ID(visitgetdomainbounds_,visitgetdomainbounds,VISITGETDOMAINBOUNDS)
</pre></td></tr>


<tr><th class="line-num" id="L1642"><a href="#L1642">1642</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITGETDOMAINNESTING F77_ID(visitgetdomainnesting_,visitgetdomainnesting,VISITGETDOMAINNESTING)
</pre></td></tr>


<tr><th class="line-num" id="L1643"><a href="#L1643">1643</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1644"><a href="#L1644">1644</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITACTIVATETIMESTEP(<span class="pt">void</span>);
</pre></td></tr>


<tr><th class="line-num" id="L1645"><a href="#L1645">1645</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETMETADATA(<span class="pt">void</span>);
</pre></td></tr>


<tr><th class="line-num" id="L1646"><a href="#L1646">1646</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETMESH(<span class="pt">int</span> *, <span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1647"><a href="#L1647">1647</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETVARIABLE(<span class="pt">int</span> *, <span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1648"><a href="#L1648">1648</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETMIXEDVARIABLE(<span class="pt">int</span> *, <span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1649"><a href="#L1649">1649</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETMATERIAL(<span class="pt">int</span> *, <span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1650"><a href="#L1650">1650</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETCURVE(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1651"><a href="#L1651">1651</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETDOMAINLIST(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1652"><a href="#L1652">1652</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETDOMAINBOUNDS(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1653"><a href="#L1653">1653</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> F_VISITGETDOMAINNESTING(<span class="r">const</span> <span class="pt">char</span> *, <span class="pt">int</span> * VISIT_F77_END_STRLEN_DECL);
</pre></td></tr>


<tr><th class="line-num" id="L1654"><a href="#L1654">1654</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1655"><a href="#L1655">1655</a></th><td class="line-code"><pre><span class="pp">#define</span> F_VISITSTRCMP           F77_ID(visitstrcmp_,visitstrcmp,VISITSTRCMP)
</pre></td></tr>


<tr><th class="line-num" id="L1656"><a href="#L1656">1656</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1657"><a href="#L1657">1657</a></th><td class="line-code"><pre><span class="c">/*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1658"><a href="#L1658">1658</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1659"><a href="#L1659">1659</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1660"><a href="#L1660">1660</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L1661"><a href="#L1661">1661</a></th><td class="line-code"><pre> **** THESE ARE CALLBACK FUNCTIONS THAT CALL THEIR FORTRAN EQUIVALENTS,
</pre></td></tr>


<tr><th class="line-num" id="L1662"><a href="#L1662">1662</a></th><td class="line-code"><pre> **** ALLOWING THE SimV2 DATABASE PLUGIN TO OBTAIN DATA FROM THE SIMULATION.
</pre></td></tr>


<tr><th class="line-num" id="L1663"><a href="#L1663">1663</a></th><td class="line-code"><pre> ****
</pre></td></tr>


<tr><th class="line-num" id="L1664"><a href="#L1664">1664</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1665"><a href="#L1665">1665</a></th><td class="line-code"><pre> *****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1666"><a href="#L1666">1666</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1667"><a href="#L1667">1667</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1668"><a href="#L1668">1668</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1669"><a href="#L1669">1669</a></th><td class="line-code"><pre> * Function: VisItActivateTimestep
</pre></td></tr>


<tr><th class="line-num" id="L1670"><a href="#L1670">1670</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1671"><a href="#L1671">1671</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitactivatetimestep&quot; to activate the time step.
</pre></td></tr>


<tr><th class="line-num" id="L1672"><a href="#L1672">1672</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1673"><a href="#L1673">1673</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1674"><a href="#L1674">1674</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1675"><a href="#L1675">1675</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1676"><a href="#L1676">1676</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1677"><a href="#L1677">1677</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1678"><a href="#L1678">1678</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1679"><a href="#L1679">1679</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1680"><a href="#L1680">1680</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1681"><a href="#L1681">1681</a></th><td class="line-code"><pre>VisItActivateTimestep(<span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1682"><a href="#L1682">1682</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1683"><a href="#L1683">1683</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITACTIVATETIMESTEP();
</pre></td></tr>


<tr><th class="line-num" id="L1684"><a href="#L1684">1684</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1685"><a href="#L1685">1685</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1686"><a href="#L1686">1686</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1687"><a href="#L1687">1687</a></th><td class="line-code"><pre> * Function: VisItGetMetaData
</pre></td></tr>


<tr><th class="line-num" id="L1688"><a href="#L1688">1688</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1689"><a href="#L1689">1689</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetmetadata&quot; to populate a metadata object.
</pre></td></tr>


<tr><th class="line-num" id="L1690"><a href="#L1690">1690</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1691"><a href="#L1691">1691</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1692"><a href="#L1692">1692</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1693"><a href="#L1693">1693</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1694"><a href="#L1694">1694</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1695"><a href="#L1695">1695</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1696"><a href="#L1696">1696</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1697"><a href="#L1697">1697</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1698"><a href="#L1698">1698</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1699"><a href="#L1699">1699</a></th><td class="line-code"><pre>VisItGetMetaData(<span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1700"><a href="#L1700">1700</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1701"><a href="#L1701">1701</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETMETADATA();
</pre></td></tr>


<tr><th class="line-num" id="L1702"><a href="#L1702">1702</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1703"><a href="#L1703">1703</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1704"><a href="#L1704">1704</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1705"><a href="#L1705">1705</a></th><td class="line-code"><pre> * Function: VisItGetMesh
</pre></td></tr>


<tr><th class="line-num" id="L1706"><a href="#L1706">1706</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1707"><a href="#L1707">1707</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetmesh&quot; to populate a mesh object.
</pre></td></tr>


<tr><th class="line-num" id="L1708"><a href="#L1708">1708</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1709"><a href="#L1709">1709</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1710"><a href="#L1710">1710</a></th><td class="line-code"><pre> *   domain : The domain for which we want the scalar.
</pre></td></tr>


<tr><th class="line-num" id="L1711"><a href="#L1711">1711</a></th><td class="line-code"><pre> *   name   : The name of the mesh to return.
</pre></td></tr>


<tr><th class="line-num" id="L1712"><a href="#L1712">1712</a></th><td class="line-code"><pre> *   mesh   : The mesh object we're filling in.
</pre></td></tr>


<tr><th class="line-num" id="L1713"><a href="#L1713">1713</a></th><td class="line-code"><pre> *   cbdata : Programmer callback data.
</pre></td></tr>


<tr><th class="line-num" id="L1714"><a href="#L1714">1714</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1715"><a href="#L1715">1715</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1716"><a href="#L1716">1716</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1717"><a href="#L1717">1717</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1718"><a href="#L1718">1718</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1719"><a href="#L1719">1719</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1720"><a href="#L1720">1720</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1721"><a href="#L1721">1721</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1722"><a href="#L1722">1722</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1723"><a href="#L1723">1723</a></th><td class="line-code"><pre>VisItGetMesh(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1724"><a href="#L1724">1724</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1725"><a href="#L1725">1725</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1726"><a href="#L1726">1726</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETMESH(&amp;domain, name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1727"><a href="#L1727">1727</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1728"><a href="#L1728">1728</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1729"><a href="#L1729">1729</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1730"><a href="#L1730">1730</a></th><td class="line-code"><pre> * Function: VisItGetMaterial
</pre></td></tr>


<tr><th class="line-num" id="L1731"><a href="#L1731">1731</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1732"><a href="#L1732">1732</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetmaterial&quot; to populate a material object.
</pre></td></tr>


<tr><th class="line-num" id="L1733"><a href="#L1733">1733</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1734"><a href="#L1734">1734</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1735"><a href="#L1735">1735</a></th><td class="line-code"><pre> *   domain : The domain for which we want the material.
</pre></td></tr>


<tr><th class="line-num" id="L1736"><a href="#L1736">1736</a></th><td class="line-code"><pre> *   name   : The name of the material to return.
</pre></td></tr>


<tr><th class="line-num" id="L1737"><a href="#L1737">1737</a></th><td class="line-code"><pre> *   mat    : The material object we're filling in.
</pre></td></tr>


<tr><th class="line-num" id="L1738"><a href="#L1738">1738</a></th><td class="line-code"><pre> *   cbdata : Programmer callback data.
</pre></td></tr>


<tr><th class="line-num" id="L1739"><a href="#L1739">1739</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1740"><a href="#L1740">1740</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1741"><a href="#L1741">1741</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1742"><a href="#L1742">1742</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1743"><a href="#L1743">1743</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1744"><a href="#L1744">1744</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1745"><a href="#L1745">1745</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1746"><a href="#L1746">1746</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1747"><a href="#L1747">1747</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1748"><a href="#L1748">1748</a></th><td class="line-code"><pre>VisItGetMaterial(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1749"><a href="#L1749">1749</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1750"><a href="#L1750">1750</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1751"><a href="#L1751">1751</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETMATERIAL(&amp;domain, name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1752"><a href="#L1752">1752</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1753"><a href="#L1753">1753</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1754"><a href="#L1754">1754</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1755"><a href="#L1755">1755</a></th><td class="line-code"><pre> * Function: VisItGetVariable
</pre></td></tr>


<tr><th class="line-num" id="L1756"><a href="#L1756">1756</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1757"><a href="#L1757">1757</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetscalar&quot; to populate a scalar object.
</pre></td></tr>


<tr><th class="line-num" id="L1758"><a href="#L1758">1758</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1759"><a href="#L1759">1759</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1760"><a href="#L1760">1760</a></th><td class="line-code"><pre> *   domain : The domain for which we want the scalar.
</pre></td></tr>


<tr><th class="line-num" id="L1761"><a href="#L1761">1761</a></th><td class="line-code"><pre> *   name   : The name of the scalar to return.
</pre></td></tr>


<tr><th class="line-num" id="L1762"><a href="#L1762">1762</a></th><td class="line-code"><pre> *   var    : The variable object we're filling in.
</pre></td></tr>


<tr><th class="line-num" id="L1763"><a href="#L1763">1763</a></th><td class="line-code"><pre> *   cbdata : Programmer callback data.
</pre></td></tr>


<tr><th class="line-num" id="L1764"><a href="#L1764">1764</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1765"><a href="#L1765">1765</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1766"><a href="#L1766">1766</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1767"><a href="#L1767">1767</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1768"><a href="#L1768">1768</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1769"><a href="#L1769">1769</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1770"><a href="#L1770">1770</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1771"><a href="#L1771">1771</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1772"><a href="#L1772">1772</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1773"><a href="#L1773">1773</a></th><td class="line-code"><pre>VisItGetVariable(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1774"><a href="#L1774">1774</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1775"><a href="#L1775">1775</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1776"><a href="#L1776">1776</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETVARIABLE(&amp;domain, name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1777"><a href="#L1777">1777</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1778"><a href="#L1778">1778</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1779"><a href="#L1779">1779</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1780"><a href="#L1780">1780</a></th><td class="line-code"><pre> * Function: VisItGetMixedVariable
</pre></td></tr>


<tr><th class="line-num" id="L1781"><a href="#L1781">1781</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1782"><a href="#L1782">1782</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetscalar&quot; to populate a scalar object.
</pre></td></tr>


<tr><th class="line-num" id="L1783"><a href="#L1783">1783</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1784"><a href="#L1784">1784</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1785"><a href="#L1785">1785</a></th><td class="line-code"><pre> *   domain : The domain for which we want the scalar.
</pre></td></tr>


<tr><th class="line-num" id="L1786"><a href="#L1786">1786</a></th><td class="line-code"><pre> *   name   : The name of the scalar to return.
</pre></td></tr>


<tr><th class="line-num" id="L1787"><a href="#L1787">1787</a></th><td class="line-code"><pre> *   var    : The variable object we're filling in.
</pre></td></tr>


<tr><th class="line-num" id="L1788"><a href="#L1788">1788</a></th><td class="line-code"><pre> *   cbdata : Programmer callback data.
</pre></td></tr>


<tr><th class="line-num" id="L1789"><a href="#L1789">1789</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1790"><a href="#L1790">1790</a></th><td class="line-code"><pre> * Programmer: Jim Eliot
</pre></td></tr>


<tr><th class="line-num" id="L1791"><a href="#L1791">1791</a></th><td class="line-code"><pre> * Date:       Mon Dec 01 08:46:15 GMT 2014
</pre></td></tr>


<tr><th class="line-num" id="L1792"><a href="#L1792">1792</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1793"><a href="#L1793">1793</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1794"><a href="#L1794">1794</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1795"><a href="#L1795">1795</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1796"><a href="#L1796">1796</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1797"><a href="#L1797">1797</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1798"><a href="#L1798">1798</a></th><td class="line-code"><pre>VisItGetMixedVariable(<span class="pt">int</span> domain, <span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1799"><a href="#L1799">1799</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1800"><a href="#L1800">1800</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1801"><a href="#L1801">1801</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETMIXEDVARIABLE(&amp;domain, name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1802"><a href="#L1802">1802</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1803"><a href="#L1803">1803</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1804"><a href="#L1804">1804</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1805"><a href="#L1805">1805</a></th><td class="line-code"><pre> * Function: VisItGetCurve
</pre></td></tr>


<tr><th class="line-num" id="L1806"><a href="#L1806">1806</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1807"><a href="#L1807">1807</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetcurve&quot; to populate a curve object.
</pre></td></tr>


<tr><th class="line-num" id="L1808"><a href="#L1808">1808</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1809"><a href="#L1809">1809</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1810"><a href="#L1810">1810</a></th><td class="line-code"><pre> *   name   : The name of the curve to return.
</pre></td></tr>


<tr><th class="line-num" id="L1811"><a href="#L1811">1811</a></th><td class="line-code"><pre> *   curve  : The curve object we're filling in.
</pre></td></tr>


<tr><th class="line-num" id="L1812"><a href="#L1812">1812</a></th><td class="line-code"><pre> *   cbdata : Programmer callback data.
</pre></td></tr>


<tr><th class="line-num" id="L1813"><a href="#L1813">1813</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1814"><a href="#L1814">1814</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1815"><a href="#L1815">1815</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1816"><a href="#L1816">1816</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1817"><a href="#L1817">1817</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1818"><a href="#L1818">1818</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1819"><a href="#L1819">1819</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1820"><a href="#L1820">1820</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1821"><a href="#L1821">1821</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1822"><a href="#L1822">1822</a></th><td class="line-code"><pre>VisItGetCurve(<span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1823"><a href="#L1823">1823</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1824"><a href="#L1824">1824</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1825"><a href="#L1825">1825</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETCURVE(name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1826"><a href="#L1826">1826</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1827"><a href="#L1827">1827</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1828"><a href="#L1828">1828</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1829"><a href="#L1829">1829</a></th><td class="line-code"><pre> * Function: VisItGetDomainList
</pre></td></tr>


<tr><th class="line-num" id="L1830"><a href="#L1830">1830</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1831"><a href="#L1831">1831</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetdomainlist&quot; to populate a domain list object.
</pre></td></tr>


<tr><th class="line-num" id="L1832"><a href="#L1832">1832</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1833"><a href="#L1833">1833</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1834"><a href="#L1834">1834</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1835"><a href="#L1835">1835</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1836"><a href="#L1836">1836</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1837"><a href="#L1837">1837</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1838"><a href="#L1838">1838</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1839"><a href="#L1839">1839</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1840"><a href="#L1840">1840</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1841"><a href="#L1841">1841</a></th><td class="line-code"><pre>VisItGetDomainList(<span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1842"><a href="#L1842">1842</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1843"><a href="#L1843">1843</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1844"><a href="#L1844">1844</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETDOMAINLIST(name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1845"><a href="#L1845">1845</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1846"><a href="#L1846">1846</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1847"><a href="#L1847">1847</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1848"><a href="#L1848">1848</a></th><td class="line-code"><pre> * Function: VisItGetDomainBoundaries
</pre></td></tr>


<tr><th class="line-num" id="L1849"><a href="#L1849">1849</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1850"><a href="#L1850">1850</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetdomainbounds&quot; to populate a domain
</pre></td></tr>


<tr><th class="line-num" id="L1851"><a href="#L1851">1851</a></th><td class="line-code"><pre> *            boundaries object.
</pre></td></tr>


<tr><th class="line-num" id="L1852"><a href="#L1852">1852</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1853"><a href="#L1853">1853</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1854"><a href="#L1854">1854</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1855"><a href="#L1855">1855</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1856"><a href="#L1856">1856</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1857"><a href="#L1857">1857</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1858"><a href="#L1858">1858</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1859"><a href="#L1859">1859</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1860"><a href="#L1860">1860</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1861"><a href="#L1861">1861</a></th><td class="line-code"><pre>VisItGetDomainBoundaries(<span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1862"><a href="#L1862">1862</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1863"><a href="#L1863">1863</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1864"><a href="#L1864">1864</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETDOMAINBOUNDS(name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1865"><a href="#L1865">1865</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1866"><a href="#L1866">1866</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1867"><a href="#L1867">1867</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1868"><a href="#L1868">1868</a></th><td class="line-code"><pre> * Function: VisItGetDomainNesting
</pre></td></tr>


<tr><th class="line-num" id="L1869"><a href="#L1869">1869</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1870"><a href="#L1870">1870</a></th><td class="line-code"><pre> * Purpose:   Calls FORTRAN &quot;visitgetdomainnesting&quot; to populate a domain
</pre></td></tr>


<tr><th class="line-num" id="L1871"><a href="#L1871">1871</a></th><td class="line-code"><pre> *            nesting object.
</pre></td></tr>


<tr><th class="line-num" id="L1872"><a href="#L1872">1872</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1873"><a href="#L1873">1873</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1874"><a href="#L1874">1874</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1875"><a href="#L1875">1875</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1876"><a href="#L1876">1876</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1877"><a href="#L1877">1877</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1878"><a href="#L1878">1878</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1879"><a href="#L1879">1879</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1880"><a href="#L1880">1880</a></th><td class="line-code"><pre>visit_handle
</pre></td></tr>


<tr><th class="line-num" id="L1881"><a href="#L1881">1881</a></th><td class="line-code"><pre>VisItGetDomainNesting(<span class="r">const</span> <span class="pt">char</span> *name, <span class="pt">void</span> *cbdata)
</pre></td></tr>


<tr><th class="line-num" id="L1882"><a href="#L1882">1882</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1883"><a href="#L1883">1883</a></th><td class="line-code"><pre>    <span class="pt">int</span> lname = strlen(name);
</pre></td></tr>


<tr><th class="line-num" id="L1884"><a href="#L1884">1884</a></th><td class="line-code"><pre>    <span class="r">return</span> F_VISITGETDOMAINNESTING(name, &amp;lname, lname);
</pre></td></tr>


<tr><th class="line-num" id="L1885"><a href="#L1885">1885</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1886"><a href="#L1886">1886</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1887"><a href="#L1887">1887</a></th><td class="line-code"><pre><span class="c">/******************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L1888"><a href="#L1888">1888</a></th><td class="line-code"><pre> * Function: F_VISITSTRCMP
</pre></td></tr>


<tr><th class="line-num" id="L1889"><a href="#L1889">1889</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1890"><a href="#L1890">1890</a></th><td class="line-code"><pre> * Purpose:   Allows FORTRAN to do string comparison a la C's strcmp.
</pre></td></tr>


<tr><th class="line-num" id="L1891"><a href="#L1891">1891</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1892"><a href="#L1892">1892</a></th><td class="line-code"><pre> * Arguments:
</pre></td></tr>


<tr><th class="line-num" id="L1893"><a href="#L1893">1893</a></th><td class="line-code"><pre> *   s1  : The first Fortran string to compare.
</pre></td></tr>


<tr><th class="line-num" id="L1894"><a href="#L1894">1894</a></th><td class="line-code"><pre> *   lsl : Length of the first string
</pre></td></tr>


<tr><th class="line-num" id="L1895"><a href="#L1895">1895</a></th><td class="line-code"><pre> *   s2  : The second Fortran string to compare.
</pre></td></tr>


<tr><th class="line-num" id="L1896"><a href="#L1896">1896</a></th><td class="line-code"><pre> *   ls2 : Length of the second string
</pre></td></tr>


<tr><th class="line-num" id="L1897"><a href="#L1897">1897</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1898"><a href="#L1898">1898</a></th><td class="line-code"><pre> * Programmer: Brad Whitlock
</pre></td></tr>


<tr><th class="line-num" id="L1899"><a href="#L1899">1899</a></th><td class="line-code"><pre> * Date:       Thu Mar 11 11:17:51 PST 2010
</pre></td></tr>


<tr><th class="line-num" id="L1900"><a href="#L1900">1900</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1901"><a href="#L1901">1901</a></th><td class="line-code"><pre> * Modifications:
</pre></td></tr>


<tr><th class="line-num" id="L1902"><a href="#L1902">1902</a></th><td class="line-code"><pre> *
</pre></td></tr>


<tr><th class="line-num" id="L1903"><a href="#L1903">1903</a></th><td class="line-code"><pre> *****************************************************************************/</span>
</pre></td></tr>


<tr><th class="line-num" id="L1904"><a href="#L1904">1904</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1905"><a href="#L1905">1905</a></th><td class="line-code"><pre>FORTRAN
</pre></td></tr>


<tr><th class="line-num" id="L1906"><a href="#L1906">1906</a></th><td class="line-code"><pre>F_VISITSTRCMP(VISIT_F77STRING s1 VISIT_F77_MIXED_STRLEN(s1), <span class="pt">int</span> *ls1,
</pre></td></tr>


<tr><th class="line-num" id="L1907"><a href="#L1907">1907</a></th><td class="line-code"><pre>              VISIT_F77STRING s2 VISIT_F77_MIXED_STRLEN(s2), <span class="pt">int</span> *ls2
</pre></td></tr>


<tr><th class="line-num" id="L1908"><a href="#L1908">1908</a></th><td class="line-code"><pre>              VISIT_F77_END_STRLEN(s1) VISIT_F77_END_STRLEN(s2))
</pre></td></tr>


<tr><th class="line-num" id="L1909"><a href="#L1909">1909</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L1910"><a href="#L1910">1910</a></th><td class="line-code"><pre>    <span class="pt">int</span> retval = -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1911"><a href="#L1911">1911</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_s1 = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1912"><a href="#L1912">1912</a></th><td class="line-code"><pre>    <span class="pt">char</span> *f_s2 = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L1913"><a href="#L1913">1913</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_s1, s1, ls1);
</pre></td></tr>


<tr><th class="line-num" id="L1914"><a href="#L1914">1914</a></th><td class="line-code"><pre>    COPY_FORTRAN_STRING(f_s2, s2, ls2);
</pre></td></tr>


<tr><th class="line-num" id="L1915"><a href="#L1915">1915</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1916"><a href="#L1916">1916</a></th><td class="line-code"><pre>    <span class="r">if</span>(f_s1 != <span class="pc">NULL</span> &amp;&amp; f_s2 != <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L1917"><a href="#L1917">1917</a></th><td class="line-code"><pre>        retval = strcmp(f_s1, f_s2);
</pre></td></tr>


<tr><th class="line-num" id="L1918"><a href="#L1918">1918</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1919"><a href="#L1919">1919</a></th><td class="line-code"><pre>    FREE(f_s1);
</pre></td></tr>


<tr><th class="line-num" id="L1920"><a href="#L1920">1920</a></th><td class="line-code"><pre>    FREE(f_s2);
</pre></td></tr>


<tr><th class="line-num" id="L1921"><a href="#L1921">1921</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1922"><a href="#L1922">1922</a></th><td class="line-code"><pre>    <span class="r">return</span> retval;
</pre></td></tr>


<tr><th class="line-num" id="L1923"><a href="#L1923">1923</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L1924"><a href="#L1924">1924</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L1925"><a href="#L1925">1925</a></th><td class="line-code"><pre>
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
