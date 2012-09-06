##
 #  map.p
 #
 #  Copyright (C) 2011-2012  Daniel Sousa   <da.arada@gmail.com>
 #  Copyright (C) 2011-2012  Jorge Estrela  <jes@isep.ipp.pt>
 #
 #  Created by:
 #    Daniel Sousa  <da.arada@gmail.com>
 #
 #  Sponsor:
 #    Jorge Estrela  <jes@isep.ipp.pt>
 ##

set title "Simulation map and AVG movement"
set xlabel "x"
set ylabel "y"
set autoscale
plot "log/simulation.log" u 2:3 t "AGV move" w lines lw 2, \
     "log/sensors.map" u 1:2 t "Sensor" lw 2 lc rgb "black", \
     "log/sensors.map" u 1:2:(80) t "Com Map" w circles lc rgb "green" \
                          fs transparent solid 0.15 
