<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>VisIt - big_quads.C - VisIt Bugs</title>
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
				
        <h2>big_quads.C</h2>

<div class="attachments">
<p>
   <span class="author">Mark Miller, 08/30/2017 06:38 pm</span></p>
<p><a href="/attachments/download/456/big_quads.C">Download</a>   <span class="size">(7 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre><span class="c">/*****************************************************************************
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>*
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre>* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
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


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;silo.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;stdio.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;math.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;string.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre><span class="c">// supress the following since silo uses char * in its API</span>
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre><span class="pp">#if</span> defined(__clang__)
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre><span class="pp"># pragma</span> GCC diagnostic ignored <span class="s"><span class="dl">&quot;</span><span class="k">-Wdeprecated-writable-strings</span><span class="dl">&quot;</span></span>
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre><span class="pp">#elif</span> defined(__GNUC__)
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre><span class="pp"># pragma</span> GCC diagnostic ignored <span class="s"><span class="dl">&quot;</span><span class="k">-Wwrite-strings</span><span class="dl">&quot;</span></span>
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre><span class="pp">#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre><span class="c">#if 0
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>    varnames[0] = &quot;u&quot;;
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>    vals[0] = dc;
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>    DBPutUcdvar(dbfile, &quot;ud_1d&quot;, &quot;ucd_1d&quot;, 1, varnames, (float**)vals,
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>        NX, NULL, 0, DB_DOUBLE, DB_NODECENT, 0);
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>    vals[0] = fc;
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>    DBPutUcdvar(dbfile, &quot;uf_1d&quot;, &quot;ucd_1d&quot;, 1, varnames, (float**)vals,
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>        NX, NULL, 0, DB_FLOAT, DB_NODECENT, 0);
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>#endif</span>
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre><span class="pt">int</span>
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>main(<span class="pt">int</span> argc, <span class="pt">char</span> *argv[])
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>    <span class="pt">int</span> i;
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>    <span class="pt">float</span> ucdx[] = {<span class="i">0</span>,<span class="i">1</span>,<span class="i">2</span>,<span class="i">0</span>,<span class="i">1</span>,<span class="i">2</span>,<span class="i">0</span>,<span class="i">1</span>,<span class="i">2</span>};
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>    <span class="pt">float</span> ucdy[] = {<span class="i">0</span>,<span class="i">0</span>,<span class="i">0</span>,<span class="i">1</span>,<span class="i">1</span>,<span class="i">1</span>,<span class="i">2</span>,<span class="i">2</span>,<span class="i">2</span>};
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>    <span class="pt">int</span> shapesize = <span class="i">4</span>;
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>    <span class="pt">int</span> shapecnt = <span class="i">4</span>;
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre>    <span class="pt">int</span> shapetype = DB_ZONETYPE_QUAD;
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>    <span class="pt">int</span> zonelist[] = {<span class="i">0</span>,<span class="i">1</span>,<span class="i">4</span>,<span class="i">3</span>,  <span class="i">1</span>,<span class="i">2</span>,<span class="i">5</span>,<span class="i">4</span>,  <span class="i">3</span>,<span class="i">4</span>,<span class="i">7</span>,<span class="i">6</span>,  <span class="i">4</span>,<span class="i">5</span>,<span class="i">8</span>,<span class="i">7</span>};
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>    <span class="pt">int</span> trishapesize = <span class="i">3</span>;
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>    <span class="pt">int</span> trishapecnt = <span class="i">8</span>;
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>    <span class="pt">int</span> trishapetype = DB_ZONETYPE_TRIANGLE;
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>    <span class="pt">int</span> trizonelist[] = {<span class="i">4</span>,<span class="i">3</span>,<span class="i">0</span>, <span class="i">4</span>,<span class="i">0</span>,<span class="i">1</span>,  <span class="i">4</span>,<span class="i">1</span>,<span class="i">2</span>, <span class="i">4</span>,<span class="i">2</span>,<span class="i">5</span>,  <span class="i">4</span>,<span class="i">6</span>,<span class="i">3</span>, <span class="i">4</span>,<span class="i">7</span>,<span class="i">6</span>,  <span class="i">4</span>,<span class="i">8</span>,<span class="i">7</span>, <span class="i">4</span>,<span class="i">5</span>,<span class="i">8</span>};
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>    <span class="pt">char</span> *coordnames[] = {<span class="s"><span class="dl">&quot;</span><span class="k">x</span><span class="dl">&quot;</span></span>,<span class="s"><span class="dl">&quot;</span><span class="k">y</span><span class="dl">&quot;</span></span>};
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>    <span class="pt">float</span> *ucdcoords[<span class="i">2</span>] = {ucdx,ucdy};
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>    <span class="pt">double</span> nodal_field[] = {<span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>, <span class="i">10</span>, <span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>};
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>    <span class="pt">float</span> qx[] = {<span class="i">0</span>,<span class="fl">.1</span>,<span class="fl">.2</span>,<span class="fl">.3</span>,<span class="fl">.4</span>,<span class="fl">.5</span>,<span class="fl">.6</span>,<span class="fl">.7</span>,<span class="fl">.8</span>,<span class="fl">.9</span>,<span class="fl">1</span><span class="fl">.0</span>,<span class="fl">1</span><span class="fl">.1</span>,<span class="fl">1</span><span class="fl">.2</span>,<span class="fl">1</span><span class="fl">.3</span>,<span class="fl">1</span><span class="fl">.4</span>,<span class="fl">1</span><span class="fl">.5</span>,<span class="fl">1</span><span class="fl">.6</span>,<span class="fl">1</span><span class="fl">.7</span>,<span class="fl">1</span><span class="fl">.8</span>,<span class="fl">1</span><span class="fl">.9</span>,<span class="fl">2</span><span class="fl">.0</span>};
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>    <span class="pt">float</span> *qcoords[] = {qx, qx};
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>    <span class="pt">int</span> qdims[] = {<span class="i">21</span>,<span class="i">21</span>};
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>    <span class="pt">double</span> nodal_field_highres[<span class="i">21</span>*<span class="i">21</span>];
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>    <span class="c">// Check for the right driver.</span>
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>    <span class="pt">int</span> driver = DB_PDB;
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>    <span class="r">for</span>(<span class="pt">int</span> j = <span class="i">1</span>; j &lt; argc; ++j)
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>        <span class="r">if</span> (strcmp(argv[j], <span class="s"><span class="dl">&quot;</span><span class="k">-driver</span><span class="dl">&quot;</span></span>) == <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre>            j++;
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre>            <span class="r">if</span> (strcmp(argv[j], <span class="s"><span class="dl">&quot;</span><span class="k">DB_HDF5</span><span class="dl">&quot;</span></span>) == <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>                driver = DB_HDF5;
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>            <span class="r">else</span> <span class="r">if</span> (strcmp(argv[j], <span class="s"><span class="dl">&quot;</span><span class="k">DB_PDB</span><span class="dl">&quot;</span></span>) == <span class="i">0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>                driver = DB_PDB;
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>            <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>               fprintf(stderr,<span class="s"><span class="dl">&quot;</span><span class="k">Uncrecognized driver name </span><span class="ch">\&quot;</span><span class="k">%s</span><span class="ch">\&quot;</span><span class="ch">\n</span><span class="dl">&quot;</span></span>,
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre>                   argv[j]);
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L106"><a href="#L106">106</a></th><td class="line-code"><pre>    <span class="c">// Open the Silo file</span>
</pre></td></tr>


<tr><th class="line-num" id="L107"><a href="#L107">107</a></th><td class="line-code"><pre>    DBfile *dbfile = DBCreate(<span class="s"><span class="dl">&quot;</span><span class="k">big_quads.silo</span><span class="dl">&quot;</span></span>, DB_CLOBBER, DB_LOCAL,
</pre></td></tr>


<tr><th class="line-num" id="L108"><a href="#L108">108</a></th><td class="line-code"><pre>        <span class="s"><span class="dl">&quot;</span><span class="k">2D mesh with large quads to demonstrate shading artifacts</span><span class="dl">&quot;</span></span>, driver);
</pre></td></tr>


<tr><th class="line-num" id="L109"><a href="#L109">109</a></th><td class="line-code"><pre>    <span class="r">if</span>(dbfile == <span class="pc">NULL</span>)
</pre></td></tr>


<tr><th class="line-num" id="L110"><a href="#L110">110</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L111"><a href="#L111">111</a></th><td class="line-code"><pre>        fprintf(stderr, <span class="s"><span class="dl">&quot;</span><span class="k">Could not create Silo file!</span><span class="ch">\n</span><span class="dl">&quot;</span></span>);
</pre></td></tr>


<tr><th class="line-num" id="L112"><a href="#L112">112</a></th><td class="line-code"><pre>        <span class="r">return</span> -<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L113"><a href="#L113">113</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L114"><a href="#L114">114</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L115"><a href="#L115">115</a></th><td class="line-code"><pre>    <span class="c">// Output mesh as 4 quads</span>
</pre></td></tr>


<tr><th class="line-num" id="L116"><a href="#L116">116</a></th><td class="line-code"><pre>    DBPutUcdmesh(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">quads</span><span class="dl">&quot;</span></span>, <span class="i">2</span>, coordnames, ucdcoords,
</pre></td></tr>


<tr><th class="line-num" id="L117"><a href="#L117">117</a></th><td class="line-code"><pre>                <span class="i">9</span>, <span class="i">4</span>, <span class="s"><span class="dl">&quot;</span><span class="k">quads_zl</span><span class="dl">&quot;</span></span>, <span class="pc">NULL</span>, DB_FLOAT, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L118"><a href="#L118">118</a></th><td class="line-code"><pre>    DBPutZonelist2(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">quads_zl</span><span class="dl">&quot;</span></span>, <span class="i">4</span>, <span class="i">2</span>, zonelist, (<span class="pt">int</span>) <span class="r">sizeof</span>(zonelist),
</pre></td></tr>


<tr><th class="line-num" id="L119"><a href="#L119">119</a></th><td class="line-code"><pre>                <span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>, &amp;shapetype, &amp;shapesize, &amp;shapecnt, <span class="i">1</span>, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L120"><a href="#L120">120</a></th><td class="line-code"><pre>    DBPutUcdvar1(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">quads_field</span><span class="dl">&quot;</span></span>, <span class="s"><span class="dl">&quot;</span><span class="k">quads</span><span class="dl">&quot;</span></span>, nodal_field,
</pre></td></tr>


<tr><th class="line-num" id="L121"><a href="#L121">121</a></th><td class="line-code"><pre>        <span class="i">9</span>, <span class="pc">NULL</span>, <span class="i">0</span>, DB_DOUBLE, DB_NODECENT, <span class="i">0</span>);
</pre></td></tr>


<tr><th class="line-num" id="L122"><a href="#L122">122</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L123"><a href="#L123">123</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L124"><a href="#L124">124</a></th><td class="line-code"><pre>    <span class="c">// Output mesh as 8 triangles with diagonals chosen &quot;coorectly&quot;</span>
</pre></td></tr>


<tr><th class="line-num" id="L125"><a href="#L125">125</a></th><td class="line-code"><pre>    DBPutUcdmesh(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">tris</span><span class="dl">&quot;</span></span>, <span class="i">2</span>, coordnames, ucdcoords,
</pre></td></tr>


<tr><th class="line-num" id="L126"><a href="#L126">126</a></th><td class="line-code"><pre>                <span class="i">9</span>, <span class="i">8</span>, <span class="s"><span class="dl">&quot;</span><span class="k">tris_zl</span><span class="dl">&quot;</span></span>, <span class="pc">NULL</span>, DB_FLOAT, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L127"><a href="#L127">127</a></th><td class="line-code"><pre>    DBPutZonelist2(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">tris_zl</span><span class="dl">&quot;</span></span>, <span class="i">8</span>, <span class="i">2</span>, trizonelist, (<span class="pt">int</span>) <span class="r">sizeof</span>(trizonelist),
</pre></td></tr>


<tr><th class="line-num" id="L128"><a href="#L128">128</a></th><td class="line-code"><pre>                <span class="i">0</span>, <span class="i">0</span>, <span class="i">0</span>, &amp;trishapetype, &amp;trishapesize, &amp;trishapecnt, <span class="i">1</span>, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L129"><a href="#L129">129</a></th><td class="line-code"><pre>    DBPutUcdvar1(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">tris_field</span><span class="dl">&quot;</span></span>, <span class="s"><span class="dl">&quot;</span><span class="k">tris</span><span class="dl">&quot;</span></span>, nodal_field,
</pre></td></tr>


<tr><th class="line-num" id="L130"><a href="#L130">130</a></th><td class="line-code"><pre>        <span class="i">9</span>, <span class="pc">NULL</span>, <span class="i">0</span>, DB_DOUBLE, DB_NODECENT, <span class="i">0</span>);
</pre></td></tr>


<tr><th class="line-num" id="L131"><a href="#L131">131</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L132"><a href="#L132">132</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L133"><a href="#L133">133</a></th><td class="line-code"><pre>    <span class="c">// Output much finer resolution version of 4 quad case by doing</span>
</pre></td></tr>


<tr><th class="line-num" id="L134"><a href="#L134">134</a></th><td class="line-code"><pre>    <span class="c">// bi-linear sampling of each quad, the interpolation function</span>
</pre></td></tr>


<tr><th class="line-num" id="L135"><a href="#L135">135</a></th><td class="line-code"><pre>    <span class="c">// VisIt should be using internally to describe the field variation</span>
</pre></td></tr>


<tr><th class="line-num" id="L136"><a href="#L136">136</a></th><td class="line-code"><pre>    <span class="c">// over a quad.</span>
</pre></td></tr>


<tr><th class="line-num" id="L137"><a href="#L137">137</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L138"><a href="#L138">138</a></th><td class="line-code"><pre>        <span class="r">for</span> (<span class="pt">int</span> i = <span class="i">0</span>; i &lt; <span class="i">21</span>; i++)
</pre></td></tr>


<tr><th class="line-num" id="L139"><a href="#L139">139</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L140"><a href="#L140">140</a></th><td class="line-code"><pre>            <span class="pt">double</span> h00, h10, h01, h11, xoff, yoff;
</pre></td></tr>


<tr><th class="line-num" id="L141"><a href="#L141">141</a></th><td class="line-code"><pre>            <span class="r">for</span> (<span class="pt">int</span> j = <span class="i">0</span>; j &lt; <span class="i">21</span>; j++)
</pre></td></tr>


<tr><th class="line-num" id="L142"><a href="#L142">142</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L143"><a href="#L143">143</a></th><td class="line-code"><pre>                <span class="r">if</span> (qx[i] &lt;= <span class="fl">1</span><span class="fl">.0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L144"><a href="#L144">144</a></th><td class="line-code"><pre>                {
</pre></td></tr>


<tr><th class="line-num" id="L145"><a href="#L145">145</a></th><td class="line-code"><pre>                    xoff = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L146"><a href="#L146">146</a></th><td class="line-code"><pre>                    <span class="r">if</span> (qx[j] &lt;= <span class="fl">1</span><span class="fl">.0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L147"><a href="#L147">147</a></th><td class="line-code"><pre>                    {
</pre></td></tr>


<tr><th class="line-num" id="L148"><a href="#L148">148</a></th><td class="line-code"><pre>                        yoff = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L149"><a href="#L149">149</a></th><td class="line-code"><pre>                        h00=<span class="i">0</span>; h10=<span class="i">0</span>; h01=<span class="i">0</span>; h11=<span class="i">10</span>;
</pre></td></tr>


<tr><th class="line-num" id="L150"><a href="#L150">150</a></th><td class="line-code"><pre>                    }
</pre></td></tr>


<tr><th class="line-num" id="L151"><a href="#L151">151</a></th><td class="line-code"><pre>                    <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L152"><a href="#L152">152</a></th><td class="line-code"><pre>                    {
</pre></td></tr>


<tr><th class="line-num" id="L153"><a href="#L153">153</a></th><td class="line-code"><pre>                        yoff = <span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L154"><a href="#L154">154</a></th><td class="line-code"><pre>                        h00=<span class="i">0</span>; h10=<span class="i">10</span>; h01=<span class="i">0</span>; h11=<span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L155"><a href="#L155">155</a></th><td class="line-code"><pre>                    }
</pre></td></tr>


<tr><th class="line-num" id="L156"><a href="#L156">156</a></th><td class="line-code"><pre>                }
</pre></td></tr>


<tr><th class="line-num" id="L157"><a href="#L157">157</a></th><td class="line-code"><pre>                <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L158"><a href="#L158">158</a></th><td class="line-code"><pre>                {
</pre></td></tr>


<tr><th class="line-num" id="L159"><a href="#L159">159</a></th><td class="line-code"><pre>                    xoff = <span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L160"><a href="#L160">160</a></th><td class="line-code"><pre>                    <span class="r">if</span> (qx[j] &lt;= <span class="fl">1</span><span class="fl">.0</span>)
</pre></td></tr>


<tr><th class="line-num" id="L161"><a href="#L161">161</a></th><td class="line-code"><pre>                    {
</pre></td></tr>


<tr><th class="line-num" id="L162"><a href="#L162">162</a></th><td class="line-code"><pre>                        yoff = <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L163"><a href="#L163">163</a></th><td class="line-code"><pre>                        h00=<span class="i">0</span>; h10=<span class="oc">00</span>; h01=<span class="i">10</span>; h11=<span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L164"><a href="#L164">164</a></th><td class="line-code"><pre>                    }
</pre></td></tr>


<tr><th class="line-num" id="L165"><a href="#L165">165</a></th><td class="line-code"><pre>                    <span class="r">else</span>
</pre></td></tr>


<tr><th class="line-num" id="L166"><a href="#L166">166</a></th><td class="line-code"><pre>                    {
</pre></td></tr>


<tr><th class="line-num" id="L167"><a href="#L167">167</a></th><td class="line-code"><pre>                        yoff = <span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L168"><a href="#L168">168</a></th><td class="line-code"><pre>                        h00=<span class="i">10</span>; h10=<span class="oc">00</span>; h01=<span class="i">0</span>; h11=<span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L169"><a href="#L169">169</a></th><td class="line-code"><pre>                    }
</pre></td></tr>


<tr><th class="line-num" id="L170"><a href="#L170">170</a></th><td class="line-code"><pre>                }
</pre></td></tr>


<tr><th class="line-num" id="L171"><a href="#L171">171</a></th><td class="line-code"><pre>                <span class="pt">double</span> dx = qx[i] - xoff;
</pre></td></tr>


<tr><th class="line-num" id="L172"><a href="#L172">172</a></th><td class="line-code"><pre>                <span class="pt">double</span> dy = qx[j] - yoff;
</pre></td></tr>


<tr><th class="line-num" id="L173"><a href="#L173">173</a></th><td class="line-code"><pre>                <span class="pt">double</span> h0x = dx*h10 + (<span class="i">1</span>-dx)*h00;
</pre></td></tr>


<tr><th class="line-num" id="L174"><a href="#L174">174</a></th><td class="line-code"><pre>                <span class="pt">double</span> h1x = dx*h11 + (<span class="i">1</span>-dx)*h01;
</pre></td></tr>


<tr><th class="line-num" id="L175"><a href="#L175">175</a></th><td class="line-code"><pre>                <span class="pt">double</span> h = dy*h1x + (<span class="i">1</span>-dy)*h0x;
</pre></td></tr>


<tr><th class="line-num" id="L176"><a href="#L176">176</a></th><td class="line-code"><pre>                nodal_field_highres[j*<span class="i">21</span>+i] = h; <span class="c">// [j*nx+i]</span>
</pre></td></tr>


<tr><th class="line-num" id="L177"><a href="#L177">177</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L178"><a href="#L178">178</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L179"><a href="#L179">179</a></th><td class="line-code"><pre>        DBPutQuadmesh(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">qmesh</span><span class="dl">&quot;</span></span>, coordnames, qcoords, qdims, <span class="i">2</span>,
</pre></td></tr>


<tr><th class="line-num" id="L180"><a href="#L180">180</a></th><td class="line-code"><pre>            DB_FLOAT, DB_COLLINEAR, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L181"><a href="#L181">181</a></th><td class="line-code"><pre>        DBPutQuadvar1(dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">highres_field</span><span class="dl">&quot;</span></span>, <span class="s"><span class="dl">&quot;</span><span class="k">qmesh</span><span class="dl">&quot;</span></span>, nodal_field_highres,
</pre></td></tr>


<tr><th class="line-num" id="L182"><a href="#L182">182</a></th><td class="line-code"><pre>            qdims, <span class="i">2</span>, <span class="pc">NULL</span>, <span class="i">0</span>, DB_DOUBLE, DB_NODECENT, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L183"><a href="#L183">183</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L184"><a href="#L184">184</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L185"><a href="#L185">185</a></th><td class="line-code"><pre>    <span class="c">// Close the Silo file.</span>
</pre></td></tr>


<tr><th class="line-num" id="L186"><a href="#L186">186</a></th><td class="line-code"><pre>    DBClose(dbfile);
</pre></td></tr>


<tr><th class="line-num" id="L187"><a href="#L187">187</a></th><td class="line-code"><pre>    <span class="r">return</span> <span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L188"><a href="#L188">188</a></th><td class="line-code"><pre>}
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
