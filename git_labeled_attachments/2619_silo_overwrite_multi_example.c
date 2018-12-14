<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>Silo - silo_overwrite_multi_example.c - VisIt Bugs</title>
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
        <form action="/search/index/silo" method="get">
        
        <a href="/search/index/silo" accesskey="4">Search</a>:
        <input accesskey="f" class="small" id="q" name="q" size="20" type="text" />
        </form>
        
    </div>
    
    <h1>Silo</h1>
    
    <div id="main-menu">
        <ul><li><a href="/projects/silo" class="overview">Overview</a></li>
<li><a href="/projects/silo/activity" class="activity">Activity</a></li>
<li><a href="/projects/silo/roadmap" class="roadmap">Roadmap</a></li>
<li><a href="/projects/silo/issues" class="issues">Issues</a></li>
<li><a href="/projects/silo/news" class="news">News</a></li>
<li><a href="/projects/silo/wiki" class="wiki">Wiki</a></li>
<li><a href="/projects/silo/boards" class="boards">Forums</a></li></ul>
    </div>
</div>

<div class="nosidebar" id="main">
    <div id="sidebar">        
        
        
    </div>
    
    <div id="content">
				
        <h2>silo_overwrite_multi_example.c</h2>

<div class="attachments">
<p>
   <span class="author">Mark Miller, 11/29/2016 02:00 pm</span></p>
<p><a href="/attachments/download/418/silo_overwrite_multi_example.c">Download</a>   <span class="size">(4 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre><span class="r">extern</span> <span class="pt">int</span> db_perror(<span class="pt">char</span> <span class="r">const</span> *s, <span class="pt">int</span> errorno, <span class="pt">char</span> <span class="r">const</span> *fname);
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre><span class="pt">int</span> DBOverwriteMultiObject(DBfile *dbfile, <span class="pt">char</span> <span class="r">const</span> *objname, <span class="pt">int</span> nblocks,
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre>    <span class="pt">char</span> <span class="r">const</span> * <span class="r">const</span> *block_names, <span class="pt">char</span> <span class="r">const</span> *block_names_comp_name,
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>    <span class="pt">int</span> <span class="r">const</span> *block_types, <span class="pt">char</span> <span class="r">const</span> *block_types_comp_name, DBoptlist <span class="r">const</span> *ol)
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>    <span class="r">static</span> <span class="pt">char</span> <span class="r">const</span> *me = <span class="s"><span class="dl">&quot;</span><span class="k">DBOverwriteMultiObject</span><span class="dl">&quot;</span></span>;
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>    <span class="pt">char</span> bnames_ds_name[<span class="i">256</span>], btypes_ds_name[<span class="i">256</span>];
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>    <span class="pt">int</span> i;
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>    <span class="pt">int</span> bnames_ds_len=-<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>    <span class="pt">char</span> msg[<span class="i">256</span>];
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre>    <span class="pt">int</span> oldow = DBSetAllowOverwrites(<span class="i">1</span>);
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>    DBobject *raw_obj;
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>    msg[<span class="i">0</span>] = <span class="ch">'\0'</span>;
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>    raw_obj = DBGetObject(dbfile, objname);
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>    <span class="r">if</span> (!raw_obj)
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>        snprintf(msg, <span class="r">sizeof</span>(msg),
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>            <span class="s"><span class="dl">&quot;</span><span class="k">unable to get raw object </span><span class="ch">\&quot;</span><span class="k">%s</span><span class="ch">\&quot;</span><span class="k"> in preparation for overwrite</span><span class="dl">&quot;</span></span>, objname);
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>        <span class="r">goto</span> done;
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>    <span class="r">for</span> (i = <span class="i">0</span>; i &lt; raw_obj-&gt;ncomponents; i++)
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>    {
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>        <span class="r">if</span> (!strcmp(raw_obj-&gt;comp_names[i], block_names_comp_name))
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>            <span class="pt">char</span> *bnames_list=<span class="i">0</span>;
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>            <span class="pt">int</span> bnames_list_len;
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>            <span class="pt">int</span> ndims=<span class="i">2</span>, dims[<span class="i">2</span>]={-<span class="i">1</span>,-<span class="i">1</span>};
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>            DBStringArrayToStringList(block_names, nblocks, &amp;bnames_list, &amp;bnames_list_len);
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>            strncpy(bnames_ds_name, &amp;(raw_obj-&gt;pdb_names[i])[<span class="i">4</span>], strlen(raw_obj-&gt;pdb_names[i])-<span class="i">5</span>);
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>            DBGetVarDims(dbfile, bnames_ds_name, ndims, dims);
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>            <span class="r">if</span> (dims[<span class="i">0</span>] &gt; bnames_list_len || dims[<span class="i">1</span>] != -<span class="i">1</span>)
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>                snprintf(msg, <span class="r">sizeof</span>(msg), <span class="s"><span class="dl">&quot;</span><span class="k">total names list len=%d &gt; </span><span class="ch">\&quot;</span><span class="k">%s.%s</span><span class="ch">\&quot;</span><span class="k">=%d</span><span class="dl">&quot;</span></span>,
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>                    bnames_list_len, objname, block_names_comp_name, dims[<span class="i">0</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>                free(bnames_list);
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>                <span class="r">goto</span> done;
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>            DBWrite(dbfile, bnames_ds_name, bnames_list, &amp;bnames_list_len, <span class="i">1</span>, DB_CHAR);
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>            free(bnames_list);
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>        <span class="r">else</span> <span class="r">if</span> (block_types_comp_name &amp;&amp; !strcmp(raw_obj-&gt;comp_names[i], block_types_comp_name))
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>        {
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>            <span class="pt">int</span> ndims=<span class="i">2</span>, dims[<span class="i">2</span>]={-<span class="i">1</span>,-<span class="i">1</span>};
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>            strncpy(btypes_ds_name, &amp;(raw_obj-&gt;pdb_names[i])[<span class="i">4</span>], strlen(raw_obj-&gt;pdb_names[i])-<span class="i">5</span>);
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>            DBGetVarDims(dbfile, btypes_ds_name, ndims, dims);
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>            <span class="r">if</span> (dims[<span class="i">0</span>] != nblocks || dims[<span class="i">1</span>] != -<span class="i">1</span>)
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>            {
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>                snprintf(msg, <span class="r">sizeof</span>(msg), <span class="s"><span class="dl">&quot;</span><span class="k">nblocks=%d != </span><span class="ch">\&quot;</span><span class="k">%s.%s.dims[0]</span><span class="ch">\&quot;</span><span class="k">=%d</span><span class="dl">&quot;</span></span>,
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>                    nblocks, objname, block_types_comp_name, dims[<span class="i">0</span>]);
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>                <span class="r">goto</span> done;
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>            DBWrite(dbfile, btypes_ds_name, block_types, &amp;nblocks, <span class="i">1</span>, DB_INT);
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre><span class="la">done:</span>
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>    DBSetAllowOverwrites(oldow);
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>    <span class="r">if</span> (raw_obj)
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>        DBFreeObject(raw_obj);
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>    <span class="r">if</span> (msg[<span class="i">0</span>])
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>        <span class="r">return</span> db_perror(msg, E_NOOVERWRITE, me);
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>    <span class="r">return</span> <span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre><span class="pt">int</span> DBPutMultimeshWithOverwrite(DBfile *dbfile, <span class="pt">char</span> <span class="r">const</span> *oname,
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>    <span class="pt">int</span> nblocks, <span class="pt">char</span> <span class="r">const</span> * <span class="r">const</span> *block_names,
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>    <span class="pt">int</span> <span class="r">const</span> *block_types, DBoptlist <span class="r">const</span> *ol)
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>    <span class="r">if</span> (!DBInqVarExists(dbfile, oname))
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>        <span class="r">return</span> DBPutMultimesh(dbfile, oname, nblocks, block_names, block_types, ol);
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>    <span class="r">return</span> DBOverwriteMultiObject(dbfile, oname, nblocks,
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>               block_names, <span class="s"><span class="dl">&quot;</span><span class="k">meshnames</span><span class="dl">&quot;</span></span>, block_types, <span class="s"><span class="dl">&quot;</span><span class="k">meshtypes</span><span class="dl">&quot;</span></span>, ol);
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre><span class="pt">int</span> DBPutMultivarWithOverwrite(DBfile *dbfile, <span class="pt">char</span> <span class="r">const</span> *oname,
</pre></td></tr>


<tr><th class="line-num" id="L79"><a href="#L79">79</a></th><td class="line-code"><pre>    <span class="pt">int</span> nblocks, <span class="pt">char</span> <span class="r">const</span> * <span class="r">const</span> *block_names,
</pre></td></tr>


<tr><th class="line-num" id="L80"><a href="#L80">80</a></th><td class="line-code"><pre>    <span class="pt">int</span> <span class="r">const</span> *block_types, DBoptlist <span class="r">const</span> *ol)
</pre></td></tr>


<tr><th class="line-num" id="L81"><a href="#L81">81</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L82"><a href="#L82">82</a></th><td class="line-code"><pre>    <span class="r">if</span> (!DBInqVarExists(dbfile, oname))
</pre></td></tr>


<tr><th class="line-num" id="L83"><a href="#L83">83</a></th><td class="line-code"><pre>        <span class="r">return</span> DBPutMultivar(dbfile, oname, nblocks, block_names, block_types, ol);
</pre></td></tr>


<tr><th class="line-num" id="L84"><a href="#L84">84</a></th><td class="line-code"><pre>    <span class="r">return</span> DBOverwriteMultiObject(dbfile, oname, nblocks,
</pre></td></tr>


<tr><th class="line-num" id="L85"><a href="#L85">85</a></th><td class="line-code"><pre>               block_names, <span class="s"><span class="dl">&quot;</span><span class="k">varnames</span><span class="dl">&quot;</span></span>, block_types, <span class="s"><span class="dl">&quot;</span><span class="k">vartypes</span><span class="dl">&quot;</span></span>, ol);
</pre></td></tr>


<tr><th class="line-num" id="L86"><a href="#L86">86</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L87"><a href="#L87">87</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L88"><a href="#L88">88</a></th><td class="line-code"><pre><span class="pt">int</span> DBPutMultimatWithOverwrite(DBfile *dbfile, <span class="pt">char</span> <span class="r">const</span> *oname,
</pre></td></tr>


<tr><th class="line-num" id="L89"><a href="#L89">89</a></th><td class="line-code"><pre>    <span class="pt">int</span> nblocks, <span class="pt">char</span> <span class="r">const</span> * <span class="r">const</span> *block_names, DBoptlist <span class="r">const</span> *ol)
</pre></td></tr>


<tr><th class="line-num" id="L90"><a href="#L90">90</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L91"><a href="#L91">91</a></th><td class="line-code"><pre>    <span class="r">if</span> (!DBInqVarExists(dbfile, oname))
</pre></td></tr>


<tr><th class="line-num" id="L92"><a href="#L92">92</a></th><td class="line-code"><pre>        <span class="r">return</span> DBPutMultimat(dbfile, oname, nblocks, block_names, ol);
</pre></td></tr>


<tr><th class="line-num" id="L93"><a href="#L93">93</a></th><td class="line-code"><pre>    <span class="r">return</span> DBOverwriteMultiObject(dbfile, oname, nblocks,
</pre></td></tr>


<tr><th class="line-num" id="L94"><a href="#L94">94</a></th><td class="line-code"><pre>               block_names, <span class="s"><span class="dl">&quot;</span><span class="k">matnames</span><span class="dl">&quot;</span></span>, <span class="i">0</span>, <span class="i">0</span>, ol);
</pre></td></tr>


<tr><th class="line-num" id="L95"><a href="#L95">95</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L96"><a href="#L96">96</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L97"><a href="#L97">97</a></th><td class="line-code"><pre><span class="pt">int</span> DBPutMultimatspeciesWithOverwrite(DBfile *dbfile, <span class="pt">char</span> <span class="r">const</span> *oname,
</pre></td></tr>


<tr><th class="line-num" id="L98"><a href="#L98">98</a></th><td class="line-code"><pre>    <span class="pt">int</span> nblocks, <span class="pt">char</span> <span class="r">const</span> * <span class="r">const</span> *block_names, DBoptlist <span class="r">const</span> *ol)
</pre></td></tr>


<tr><th class="line-num" id="L99"><a href="#L99">99</a></th><td class="line-code"><pre>{
</pre></td></tr>


<tr><th class="line-num" id="L100"><a href="#L100">100</a></th><td class="line-code"><pre>    <span class="r">if</span> (!DBInqVarExists(dbfile, oname))
</pre></td></tr>


<tr><th class="line-num" id="L101"><a href="#L101">101</a></th><td class="line-code"><pre>        <span class="r">return</span> DBPutMultimatspecies(dbfile, oname, nblocks, block_names, ol);
</pre></td></tr>


<tr><th class="line-num" id="L102"><a href="#L102">102</a></th><td class="line-code"><pre>    <span class="r">return</span> DBOverwriteMultiObject(dbfile, oname, nblocks,
</pre></td></tr>


<tr><th class="line-num" id="L103"><a href="#L103">103</a></th><td class="line-code"><pre>               block_names, <span class="s"><span class="dl">&quot;</span><span class="k">specnames</span><span class="dl">&quot;</span></span>, <span class="i">0</span>, <span class="i">0</span>, ol);
</pre></td></tr>


<tr><th class="line-num" id="L104"><a href="#L104">104</a></th><td class="line-code"><pre>}
</pre></td></tr>


<tr><th class="line-num" id="L105"><a href="#L105">105</a></th><td class="line-code"><pre>
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
