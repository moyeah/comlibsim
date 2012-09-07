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

if (NbSensors>1) {
  set term wxt 0 
  set title "Simulation map and AVG movement"
  set xlabel "x"
  set ylabel "y"
  set autoscale
  plot "log/simulation.log" u 2:3 t "AGV move" w lines lw 2, \
       "log/sensors.map" u 1:2 t "Sensor" lw 2 lc rgb "black", \
       "log/sensors.map" u 1:2:(80) t "Com Map" w circles lc rgb "green" \
                            fs transparent solid 0.15 
  set term wxt 1
  set title "Sensors data versus simulation time"
  set xlabel "Simulation time"
  set ylabel "Sensor data"
  set autoscale
  plot for [i=2:(NbSensors+1)] "log/cluster.log" u 1:i \
                                     w lines lw 2 lc i t "Sensor ".(i-1)
}
else {
  print "ERROR: Sensors number < 1"
}
