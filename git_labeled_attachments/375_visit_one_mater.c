<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>Silo - visit_one_mater.c - VisIt Bugs</title>
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
				
        <h2>visit_one_mater.c</h2>

<div class="attachments">
<p>
   <span class="author">Mark Miller, 11/01/2010 08:04 pm</span></p>
<p><a href="/attachments/download/23/visit_one_mater.c">Download</a>   <span class="size">(2.4 KB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent CodeRay">
<tbody>


<tr><th class="line-num" id="L1"><a href="#L1">1</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;silo.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L2"><a href="#L2">2</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;stdio.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L3"><a href="#L3">3</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;stdlib.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L4"><a href="#L4">4</a></th><td class="line-code"><pre><span class="pp">#include</span><span class="ic"> &lt;string.h&gt;</span>
</pre></td></tr>


<tr><th class="line-num" id="L5"><a href="#L5">5</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L6"><a href="#L6">6</a></th><td class="line-code"><pre><span class="c">/*
</pre></td></tr>


<tr><th class="line-num" id="L7"><a href="#L7">7</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L8"><a href="#L8">8</a></th><td class="line-code"><pre>Silo Version with compression features enabled
</pre></td></tr>


<tr><th class="line-num" id="L9"><a href="#L9">9</a></th><td class="line-code"><pre>export LD_LIBRARY_PATH=/tmp/visit/silo-4.8/lib:/tmp/visit/hdf5/1.8.4/linux-x86_64_gcc/lib:$LD_LIBRARY_PATH
</pre></td></tr>


<tr><th class="line-num" id="L10"><a href="#L10">10</a></th><td class="line-code"><pre>gcc -I/tmp/visit/silo-4.8/include -L/tmp/visit/silo-4.8/lib -L/tmp/visit/hdf5/1.8.4/linux-x86_64_gcc/lib visit_one_mater.c -lsiloh5 -lhdf5  -lstdc++ &amp;&amp; ./a.out
</pre></td></tr>


<tr><th class="line-num" id="L11"><a href="#L11">11</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L12"><a href="#L12">12</a></th><td class="line-code"><pre> */</span>
</pre></td></tr>


<tr><th class="line-num" id="L13"><a href="#L13">13</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L14"><a href="#L14">14</a></th><td class="line-code"><pre><span class="pt">int</span> main (<span class="pt">int</span> argc, <span class="pt">char</span> ** argv) {
</pre></td></tr>


<tr><th class="line-num" id="L15"><a href="#L15">15</a></th><td class="line-code"><pre>    DBfile         *dbfile = <span class="pc">NULL</span>;
</pre></td></tr>


<tr><th class="line-num" id="L16"><a href="#L16">16</a></th><td class="line-code"><pre>    <span class="pt">int</span> n = <span class="i">50</span> ;
</pre></td></tr>


<tr><th class="line-num" id="L17"><a href="#L17">17</a></th><td class="line-code"><pre>    <span class="pt">float</span> x[n] ;
</pre></td></tr>


<tr><th class="line-num" id="L18"><a href="#L18">18</a></th><td class="line-code"><pre>    <span class="pt">int</span> i,j,k,m ;
</pre></td></tr>


<tr><th class="line-num" id="L19"><a href="#L19">19</a></th><td class="line-code"><pre>    <span class="pt">char</span>           *coordnames[<span class="i">3</span>];
</pre></td></tr>


<tr><th class="line-num" id="L20"><a href="#L20">20</a></th><td class="line-code"><pre>    <span class="pt">int</span>             dims[<span class="i">3</span>];
</pre></td></tr>


<tr><th class="line-num" id="L21"><a href="#L21">21</a></th><td class="line-code"><pre>    <span class="pt">int</span> ndims = <span class="i">3</span> ;
</pre></td></tr>


<tr><th class="line-num" id="L22"><a href="#L22">22</a></th><td class="line-code"><pre>    <span class="pt">float</span>          *coords[<span class="i">3</span>];
</pre></td></tr>


<tr><th class="line-num" id="L23"><a href="#L23">23</a></th><td class="line-code"><pre>    <span class="pt">float</span> * field ;
</pre></td></tr>


<tr><th class="line-num" id="L24"><a href="#L24">24</a></th><td class="line-code"><pre>    <span class="pt">int</span> ier ;
</pre></td></tr>


<tr><th class="line-num" id="L25"><a href="#L25">25</a></th><td class="line-code"><pre>    <span class="pt">char</span> * gzopt = <span class="s"><span class="dl">&quot;</span><span class="k">METHOD=GZIP</span><span class="dl">&quot;</span></span> ; <span class="c">// &quot;METHOD=FPZIP&quot; &quot;METHOD=HZIP&quot; : OK</span>
</pre></td></tr>


<tr><th class="line-num" id="L26"><a href="#L26">26</a></th><td class="line-code"><pre>    <span class="pt">char</span> * szopt = <span class="s"><span class="dl">&quot;</span><span class="k">METHOD=SZIP BLOCK=10 MASK=NN</span><span class="dl">&quot;</span></span> ; <span class="c">// &quot;METHOD=SZIP MINRATIO=1.0&quot; &quot;MINRATIO=1.0 METHOD=SZIP&quot; : KO</span>
</pre></td></tr>


<tr><th class="line-num" id="L27"><a href="#L27">27</a></th><td class="line-code"><pre>    <span class="pt">int</span> nmat = <span class="i">2</span> ;
</pre></td></tr>


<tr><th class="line-num" id="L28"><a href="#L28">28</a></th><td class="line-code"><pre>    <span class="pt">int</span> matnos[nmat] ;
</pre></td></tr>


<tr><th class="line-num" id="L29"><a href="#L29">29</a></th><td class="line-code"><pre>    <span class="pt">int</span> * matlist ;
</pre></td></tr>


<tr><th class="line-num" id="L30"><a href="#L30">30</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L31"><a href="#L31">31</a></th><td class="line-code"><pre>    dbfile = DBCreate(<span class="s"><span class="dl">&quot;</span><span class="k">visit_one_mater_c_sz.silo</span><span class="dl">&quot;</span></span>, DB_CLOBBER, DB_LOCAL, <span class="s"><span class="dl">&quot;</span><span class="k">One Material</span><span class="dl">&quot;</span></span>, DB_HDF5);
</pre></td></tr>


<tr><th class="line-num" id="L32"><a href="#L32">32</a></th><td class="line-code"><pre>    DBSetCompression(szopt) ;
</pre></td></tr>


<tr><th class="line-num" id="L33"><a href="#L33">33</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L34"><a href="#L34">34</a></th><td class="line-code"><pre>    <span class="c">// Builds a uniform 3D Cartesian mesh:</span>
</pre></td></tr>


<tr><th class="line-num" id="L35"><a href="#L35">35</a></th><td class="line-code"><pre>    <span class="r">for</span> (i=<span class="i">0</span>; i&lt;= n;i++) {
</pre></td></tr>


<tr><th class="line-num" id="L36"><a href="#L36">36</a></th><td class="line-code"><pre>        x[i] = (<span class="pt">float</span>) i/(<span class="pt">float</span> )n ;
</pre></td></tr>


<tr><th class="line-num" id="L37"><a href="#L37">37</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L38"><a href="#L38">38</a></th><td class="line-code"><pre>    coordnames[<span class="i">0</span>] = strdup(<span class="s"><span class="dl">&quot;</span><span class="k">x</span><span class="dl">&quot;</span></span>); <span class="c">// On the fly allocate = &quot;x&quot; ;</span>
</pre></td></tr>


<tr><th class="line-num" id="L39"><a href="#L39">39</a></th><td class="line-code"><pre>    coordnames[<span class="i">1</span>] = strdup(<span class="s"><span class="dl">&quot;</span><span class="k">y</span><span class="dl">&quot;</span></span>); <span class="c">// strdup(&quot;y&quot;);</span>
</pre></td></tr>


<tr><th class="line-num" id="L40"><a href="#L40">40</a></th><td class="line-code"><pre>    coordnames[<span class="i">2</span>] = strdup(<span class="s"><span class="dl">&quot;</span><span class="k">z</span><span class="dl">&quot;</span></span>);
</pre></td></tr>


<tr><th class="line-num" id="L41"><a href="#L41">41</a></th><td class="line-code"><pre>    dims[<span class="i">0</span>] = n+<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L42"><a href="#L42">42</a></th><td class="line-code"><pre>    dims[<span class="i">1</span>] = n+<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L43"><a href="#L43">43</a></th><td class="line-code"><pre>    dims[<span class="i">2</span>] = n+<span class="i">1</span>;
</pre></td></tr>


<tr><th class="line-num" id="L44"><a href="#L44">44</a></th><td class="line-code"><pre>    coords[<span class="i">0</span>] = x ;
</pre></td></tr>


<tr><th class="line-num" id="L45"><a href="#L45">45</a></th><td class="line-code"><pre>    coords[<span class="i">1</span>] = x ;
</pre></td></tr>


<tr><th class="line-num" id="L46"><a href="#L46">46</a></th><td class="line-code"><pre>    coords[<span class="i">2</span>] = x ;
</pre></td></tr>


<tr><th class="line-num" id="L47"><a href="#L47">47</a></th><td class="line-code"><pre>    ier = DBPutQuadmesh (dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">quadmesh</span><span class="dl">&quot;</span></span>, coordnames, coords, dims, ndims, DB_FLOAT, DB_COLLINEAR, <span class="pc">NULL</span>);
</pre></td></tr>


<tr><th class="line-num" id="L48"><a href="#L48">48</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L49"><a href="#L49">49</a></th><td class="line-code"><pre>    <span class="c">// Sets a constant field value:</span>
</pre></td></tr>


<tr><th class="line-num" id="L50"><a href="#L50">50</a></th><td class="line-code"><pre>    field = (<span class="pt">float</span> *)malloc(n*n*n*<span class="r">sizeof</span>(<span class="pt">float</span>)) ;
</pre></td></tr>


<tr><th class="line-num" id="L51"><a href="#L51">51</a></th><td class="line-code"><pre>    <span class="r">for</span> (i=<span class="i">0</span>; i&lt; n*n*n;i++)
</pre></td></tr>


<tr><th class="line-num" id="L52"><a href="#L52">52</a></th><td class="line-code"><pre>        field[i] = <span class="fl">1</span>.E0 ;
</pre></td></tr>


<tr><th class="line-num" id="L53"><a href="#L53">53</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L54"><a href="#L54">54</a></th><td class="line-code"><pre>    dims[<span class="i">0</span>] = n;
</pre></td></tr>


<tr><th class="line-num" id="L55"><a href="#L55">55</a></th><td class="line-code"><pre>    dims[<span class="i">1</span>] = n;
</pre></td></tr>


<tr><th class="line-num" id="L56"><a href="#L56">56</a></th><td class="line-code"><pre>    dims[<span class="i">2</span>] = n;
</pre></td></tr>


<tr><th class="line-num" id="L57"><a href="#L57">57</a></th><td class="line-code"><pre>    DBPutQuadvar1 (dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">field</span><span class="dl">&quot;</span></span>, <span class="s"><span class="dl">&quot;</span><span class="k">quadmesh</span><span class="dl">&quot;</span></span>, field, dims, ndims, <span class="pc">NULL</span>, <span class="i">0</span>, DB_FLOAT, DB_ZONECENT, <span class="pc">NULL</span>) ;
</pre></td></tr>


<tr><th class="line-num" id="L58"><a href="#L58">58</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L59"><a href="#L59">59</a></th><td class="line-code"><pre>    <span class="c">// Sets a material:</span>
</pre></td></tr>


<tr><th class="line-num" id="L60"><a href="#L60">60</a></th><td class="line-code"><pre>    <span class="r">for</span> (i=<span class="i">0</span>; i&lt;= nmat;i++) {
</pre></td></tr>


<tr><th class="line-num" id="L61"><a href="#L61">61</a></th><td class="line-code"><pre>        matnos[i] = i ;
</pre></td></tr>


<tr><th class="line-num" id="L62"><a href="#L62">62</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L63"><a href="#L63">63</a></th><td class="line-code"><pre>    matlist = (<span class="pt">int</span> *)malloc(n*n*n*<span class="r">sizeof</span>(<span class="pt">int</span>)) ;
</pre></td></tr>


<tr><th class="line-num" id="L64"><a href="#L64">64</a></th><td class="line-code"><pre>    <span class="r">for</span> (i=<span class="i">0</span>; i&lt; n*n*n;i++)
</pre></td></tr>


<tr><th class="line-num" id="L65"><a href="#L65">65</a></th><td class="line-code"><pre>        matlist[i] = <span class="i">0</span> ;
</pre></td></tr>


<tr><th class="line-num" id="L66"><a href="#L66">66</a></th><td class="line-code"><pre>    <span class="r">for</span> (i=n/<span class="i">3</span>; i&lt; <span class="i">2</span>*n/<span class="i">3</span>;i++) {
</pre></td></tr>


<tr><th class="line-num" id="L67"><a href="#L67">67</a></th><td class="line-code"><pre>        <span class="r">for</span> (j=n/<span class="i">3</span>; j&lt; <span class="i">2</span>*n/<span class="i">3</span>;j++) {
</pre></td></tr>


<tr><th class="line-num" id="L68"><a href="#L68">68</a></th><td class="line-code"><pre>            <span class="r">for</span> (k=n/<span class="i">3</span>; k&lt; <span class="i">2</span>*n/<span class="i">3</span>;k++) {
</pre></td></tr>


<tr><th class="line-num" id="L69"><a href="#L69">69</a></th><td class="line-code"><pre>                matlist[i+j*n+k*n*n] = <span class="i">1</span> ;
</pre></td></tr>


<tr><th class="line-num" id="L70"><a href="#L70">70</a></th><td class="line-code"><pre>            }
</pre></td></tr>


<tr><th class="line-num" id="L71"><a href="#L71">71</a></th><td class="line-code"><pre>        }
</pre></td></tr>


<tr><th class="line-num" id="L72"><a href="#L72">72</a></th><td class="line-code"><pre>    }
</pre></td></tr>


<tr><th class="line-num" id="L73"><a href="#L73">73</a></th><td class="line-code"><pre>    <span class="c">//DBSetCompression(gzopt) ;</span>
</pre></td></tr>


<tr><th class="line-num" id="L74"><a href="#L74">74</a></th><td class="line-code"><pre>    ier = DBPutMaterial (dbfile, <span class="s"><span class="dl">&quot;</span><span class="k">materials</span><span class="dl">&quot;</span></span>, <span class="s"><span class="dl">&quot;</span><span class="k">quadmesh</span><span class="dl">&quot;</span></span>, nmat, matnos, matlist, dims, ndims, <span class="pc">NULL</span>, <span class="pc">NULL</span>, <span class="pc">NULL</span>, <span class="pc">NULL</span>, <span class="i">0</span>, DB_FLOAT, <span class="pc">NULL</span>) ;
</pre></td></tr>


<tr><th class="line-num" id="L75"><a href="#L75">75</a></th><td class="line-code"><pre>
</pre></td></tr>


<tr><th class="line-num" id="L76"><a href="#L76">76</a></th><td class="line-code"><pre>    DBClose(dbfile);
</pre></td></tr>


<tr><th class="line-num" id="L77"><a href="#L77">77</a></th><td class="line-code"><pre>    exit(<span class="i">0</span>) ;
</pre></td></tr>


<tr><th class="line-num" id="L78"><a href="#L78">78</a></th><td class="line-code"><pre>}
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
