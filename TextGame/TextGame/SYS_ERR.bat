echo off
title SYS_ERROR_39
set i=1
:a
IF %i% LSS 100 (ECHO KILL YOUR DEMONS
) ELSE IF %i% LSS 200 (ECHO KILL DEMONS
) ELSE IF %i% LSS 400 (ECHO KILL DEMO
) ELSE IF %i% LSS 600 (ECHO KILL EM
) ELSE IF %i% LSS 750 (ECHO KILL ME
) ELSE (exit)
SET /a i=%i%+1
set /a rand1=(%random% + %random%) * 9 / 65536 + 1
set /a rand2=(%random% + %random%) * 9 / 65536 + 1
color %rand1%%rand2%
GOTO a