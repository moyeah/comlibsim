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

if (NbSensors>0) {
  set term wxt 0 
  set title "Simulation map and AUV movement"
  set xlabel "x"
  set ylabel "y"
  set autoscale
  plot "log/simulation.log" u 2:3 t "AUV move" w lines lw 2, \
       "log/sensors.map" u 1:2:3 notitle w labels, \
       "log/sensors.map" u 1:2:(20) t "Max rate" w circles lc rgb "green" \
                            fs transparent solid 0.15, \
       "log/sensors.map" u 1:2:(33.863) t "1/2 rate" w circles lc rgb "blue" \
                            fs transparent solid 0.15, \
       "log/sensors.map" u 1:2:(60) t "Limit rate" w circles lc rgb "yellow" \
                            fs transparent solid 0.15 
  set term wxt 1
  set title "Sensors data versus simulation time"
  set xlabel "Simulation time"
  set ylabel "Sensor data"
  set autoscale
  plot for [i=2:(NbSensors+1)] "log/accumulator.log" u 1:i \
                                     w lines lw 2 lc i t "Sensor ".(i-1)
}
else {
  print "ERROR: Sensors number < 1"
}
