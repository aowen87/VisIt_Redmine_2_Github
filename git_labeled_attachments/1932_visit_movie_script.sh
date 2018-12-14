#!/bin/csh

if ($#argv < 5) then
    echo "Missing movie name and/or number of frames to generate ... exiting"
    echo "Usage: $0 <movie name> <start frame> <end frame> <frames per batch> <session file>"
    echo "       [-concurrent] or [-shotgun (to be deparcated)]"
    echo "       [-v version of VisIt to execute]"
    echo "       [-l launchMethod] [-queue <queue>]"
    echo "       [-geometry <width>x<height>] [-format <image format>]"
    echo "       [-nn <Number of nodes>] [-npn <Number of processors per node>] [-time <Maximum job run time>]"
    echo "       [-bank <Bank from which to draw resources>] [-partition <Partition to utilize>]"
    exit
endif

set movieName = $1
set startFrame = $2
set endFrame = $3
set framesPerBatch = $4
set sessionFile = $5

# Check for the session file to exist
if (! -e $sessionFile) then
    echo "The session file, $sessionFile does not exist ... exiting"
    exit
endif

# Check for the movie directory to exist
set movieRoot = $movieName:h

if ($movieRoot != $movieName) then
    if (! -e $movieRoot) then
        echo "The directory $movieRoot does not exist ... creating $movieRoot"
        mkdir -p $movieRoot

        if (! -e $movieRoot) then
            echo "The directory $movieRoot could not be created ... exiting"
            exit
        endif
    endif
endif

# Check for visit to exist
set visit = `which visit`

if ("$visit:t" != "visit") then
    if (${?VISITHOME}) then
        set visit = $VISITHOME/bin/visit

	if (! -e $visit) then
	    echo "Found the VISITHOME environment variable but can not find the visit executable ... exiting"
	    exit
        endif
    else
        if (${?UUFSCELL}) then
	    set visit = "/uufs/$UUFSCELL/sys/pkg/VisIt/Install/gcc/bin/visit"
	    if (! -e $visit) then
		echo "Can not find the visit executable ... exiting"
		exit
	    endif
	else
            echo "Can not find VISITHOME or the visit executable ... exiting"
	    exit
        endif
    endif
endif

# Process the the optional arguments to find whether running
# sequientially or concurrently.
set concurrent = "false"

set i = 6
set j = 7

while ($i <= $#argv)

    if (X${argv[$i]} =~ X-c* || X${argv[$i]} =~ X-s*) then
       set concurrent = true
       break
    endif

    @ i = $i + 1
    @ j = $j + 1
end

# Parse the session file and locate the Machine Profiles. If they exist
# parse the format, height, and width.

set hostmane = `/bin/hostname | sed -e 's/[1-9]*//g'`

#sed -e '1,/"hostNickname" type="string">ash/d' pal_session | sed -n '/\<LaunchProfile\>/,/\<\<parallel\>/{/\<LaunchProfile\>/{h;d};H;/\<\<parallel\>/{x;p}}'

set version = ""

if ($concurrent == false) then
    set queue = ""
    set launchMethod = ""
    set launchArgs = ""
    set nNodes = ""
    set nProcsPerNode = ""
    set time = ""
    set bank = ""
    set partition = ""
else
    set launchMethodSet = `grep '"launchMethodSetSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$launchMethodSet" == "true") then
	set launchMethod = `grep '"launchMethod"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    else
	set launchMethod = qsub/mpirun
    endif

    set queue = $launchMethod:h
    set launchMethod = $launchMethod:t

    set launchArgsSet = `grep '"launchArgsSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$launchArgsSet" == "true") then
	set launchArgs = `grep '"launchArgs"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//' -e 's/"//g'`
    else
	set launchArgs = ""
    endif

    set nNodesSet = `grep '"numNodesSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$nNodesSet" == "true") then
	set nNodes = `grep '"numNodes"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    else
	set nNodes = 8
    endif

    set nProcs = `grep '"numProcessors"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`

    if ("$nProcs" != "") then
	@ nProcsPerNode = $nProcs / $nNodes
    else
	set nProcsPerNode = 12
    endif

    set timeLimitSet = `grep '"timeLimitSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$timeLimitSet" == "true") then
	set time = `grep '"timeLimit"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    else
	set time = "4:00:00"
    endif

    set bankSet = `grep '"bankSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$bankSet" == "true") then
	set bank = `grep '"bank"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    else
	set bank = "smithp-ash"
    endif

    set partitionSet = `grep '"partitionSet"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    if ("$partitionSet" == "true") then
	set partition = `grep '"partition"' $sessionFile | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
    else
	set partition = ""
    endif
endif

# Parse the session file and locate the Save Window Attributes. If they exist
# parse the format, height, and width.
set format = ""
set height = ""
set width  = ""

set windowAttsSet = `grep '"SaveWindowAttributes"' $sessionFile`
if ("$windowAttsSet" != "") then
    set format = `sed -e '1,/SaveWindowAttributes"/d' -e '/<Object/,$d' $sessionFile | grep '"format"' | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//' -e 's/\(.*\)/\L\1/'`
    set height = `sed -e '1,/"SaveWindowAttributes"/d' -e '/<Object/,$d' $sessionFile | grep '"height"' | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`

    set width  = `sed -e '1,/"SaveWindowAttributes"/d' -e '/<Object/,$d' $sessionFile | grep '"width"'  | sed -e 's/<[^>]*>//g' -e 's/^[ \t]*//'`
else
    echo "Can not find SaveWindowAttributes, using internal defaults."
endif

# Rather than use the VisIt defaults use the following values.
if ("$format" == "") then
    set format = "tiff"
endif

if ("$height" == "") then
    set height = 512
endif

if ("$width" == "") then
    set width  = 1024
endif

set geometry = "${width}x${height}"

# Process the rest of the optional arguments.
set i = 6
set j = 7

while ($i <= $#argv)

    if (X${argv[$i]} =~ X-c* || X${argv[$i]} =~ X-s*) then
       set concurrent = true

    else if (X${argv[$i]} =~ X-*) then

        if (X${argv[$i]} =~ X-v) then              # version
	    set version = ${argv[$j]}
        else if (X${argv[$i]} =~ X-l) then         # launch method
	    set launchMethod = ${argv[$j]}
        else if (X${argv[$i]} =~ X-q) then         # queue
	    set queue = ${argv[$j]}
        else if (X${argv[$i]} =~ X-nn) then        # number of nodes
	    set nNodes = ${argv[$j]}
        else if (X${argv[$i]} =~ X-npn) then       # number of processors/nodes
	    set nProcsPerNode = ${argv[$j]}
        else if (X${argv[$i]} =~ X-t*) then        # time
	    set time = ${argv[$j]}
        else if (X${argv[$i]} =~ X-b*) then        # bank
	    set bank = ${argv[$j]}
        else if (X${argv[$i]} =~ X-p*) then        # partition
	    set partition = "${argv[$j]}"
        else if (X${argv[$i]} =~ X-g*) then        # geometry
	    set geometry = "${argv[$j]}"
        else if (X${argv[$i]} =~ X-g*) then        # format
	    set format = "${argv[$j]}"
	else
	  echo "Unknown option ${argv[$i]} ... exiting"
          echo "Usage: $0 <movie name> <start frame> <end frame> <frames per batch> <session file>"
          echo "       [-concurrent] or [-shotgun (to be deparcated)]"
          echo "       [-v version of VisIt to execute]"
          echo "       [-l launchMethod] [-queue <queue>]"
          echo "       [-geometry <width>x<height>] [-format <image format>]"
          echo "       [-nn <Number of nodes>] [-npn <Number of processors per node>] [-time <Maximum job run time>]"
          echo "       [-bank <Bank from which to draw resources>] [-partition <Partition to utilize>]"
	  exit
	endif

        @ i = $i + 1
        @ j = $j + 1
    endif

    @ i = $i + 1
    @ j = $j + 1

end

# If needed calculate the number of nodes, processors per node, etc.
if ($concurrent == "true") then
    @ nProcs = $nNodes * $nProcsPerNode
else
    if( $nNodes == "" && $nProcsPerNode == "") then
	set nProcs = ""
    else if ($nNodes == "") then
	set nNodes = 8
	@ nProcs = $nNodes * $nProcsPerNode
    else if ("$nProcsPerNode" == "") then
	set nProcsPerNode = 12
	@ nProcs = $nNodes * $nProcsPerNode
    else
        @ nProcs = $nNodes * $nProcsPerNode
    endif

    if ("$queue" != "" && $queue != $launchMethod) then
	set launchMethod = $queue/$launchMethod
        set queue = ""
    endif
endif

if ($concurrent == "true") then
    if (X"${launchArgs}" =~ X*-l*) then
      echo "The session file contains launch args ($launchArgs) that will conflict with $launchMethod. Edit the session file and set launchArgsSet to false."
      exit
    endif
endif

# Set some required default command line arguments
set sessionFile = "-sessionfile $sessionFile"

echo "Successfully parsed the session file and command line. The following parameters were found:"

if ($version != "")        echo "  VisIt version = $version"
if ($concurrent == "true") echo "  Queue = $queue"
if ($launchMethod != "")   echo "  Launch method = $launchMethod"
if ($launchArgs != "")     echo "  Launch method = $launchArgs"
if ($nNodes != "")         echo "  Number of nodes = $nNodes"
if ($nProcs != "")         echo "  Number of processors = $nProcs"
if ($nProcsPerNode != "")  echo "  Number of processors per node = $nProcsPerNode"
if ($bank != "")           echo "  Bank = $bank"
if ($time != "")           echo "  Time = $time"
if ($partition != "")      echo "  Partition = $partition"

if ($format != "")         echo "  Format = $format"
if ($geometry != "")       echo "  Image size = $geometry"

if ($version != "") set version = "-v $version"

if ($concurrent == "false") then
    if ($launchMethod != "") set launchMethod = "-l $launchMethod"
    if ($nNodes != "") set nNodes = "-nn $nNodes"
    if ($nProcs != "") set nProcs = "-np $nProcs"
    if ($bank != "") set bank = "-b $bank"
    if ($time != "") set time = "-t $time"
endif

if ($partition != "") set partition = "-p $partition"
if ($format != "")    set format = "-format $format"
if ($geometry != "")  set geometry = "-geometry $geometry"

# Calculate the number frames and batches to generate.
@ nFrames = $endFrame - $startFrame + 1

if ($nFrames <= 0) then
    echo "The number of frames is zero or negative ... exiting"
    exit
endif

@ nBatches = $nFrames / $framesPerBatch

if ($nBatches * $framesPerBatch != $nFrames) then
    @ nBatches = $nBatches + 1
endif

# Loop through and generate the jobs either sequientially or in parallel.
if( $concurrent == "true" ) then
    echo "Creating $nBatches concurrent jobs."
else
    echo "Creating $nBatches sequential jobs."
endif

set batch = 0

while ($batch < $nBatches)
    @ start = $startFrame + $batch * $framesPerBatch
    @ end   = $start + $framesPerBatch - 1

    if( $end > $endFrame ) set end = $endFrame

    set fullMovieName = "-output $movieName"
    set jobName = $movieName:t_job_$batch

    echo "Creating frames $start through $end using job name $jobName"

    # Concurrent
    if( $concurrent == "true" ) then

# No indentation because white spaces are passed to qsub and
# will screw up the EOF sentinal. 
     $queue -l nodes=${nNodes}:ppn=$nProcsPerNode,walltime=$time $launchArgs -A $bank -N $jobName << EOF

cd $cwd

$visit $version -l $launchMethod -nn $nNodes -np $nProcs -machinefile \${PBS_NODEFILE} -bank $bank $partition -movie -start $start -end $end $geometry -frame $start $format $fullMovieName $sessionFile

EOF

    # Sequential
    else
        echo "$visit $version $launchMethod $nNodes $nProcs $time $bank $partition -movie -start $start -end $end -frame $start $geometry $format $fullMovieName $sessionFile"

        $visit $version $launchMethod $nNodes $nProcs $time $bank $partition -movie -start $start -end $end -frame $start $geometry $format $fullMovieName $sessionFile >>&! $movieName$batch.script_log

    endif

    @ batch = $batch + 1
end
