static void setupNav(char* str){
  char * pEnd; 
  pEnd = strtok (str," ,");
  len = strtol (pEnd, &pEnd, 10);
  pEnd = strtok (NULL," ,");
  nav_legs = new NavLeg[len];
  double v;
  for(int i=0;i<len;++i){
    // e_lati
    v = strtod (pEnd, &pEnd);
    nav_legs[i].e_lati = v;
    pEnd = strtok (NULL," ,");
    
    // e_long
    v = strtod (pEnd, &pEnd);
    nav_legs[i].e_long = v;
    pEnd = strtok (NULL," ,");
    
    // maneuver
    nav_legs[i].maneuver = pEnd;
    pEnd = strtok (NULL," ,");
  }
}

void navigate(){
  if (len < 0){return; }
  
  if(!GPS_receive()){ return; }
  double dmin = Radius;
  
  int newLegIdx = cur_leg_id;
  int begin = (cur_leg_id-3 > 0) ? cur_leg_id-3 : 0;
  int end = (cur_leg_id+3 < len+1) ? cur_leg_id-3 : len;
  
  for (int i=begin;i<end;++i){
    double d = distance(latitude, longitude, nav_legs[i].e_lati, nav_legs[i].e_long);
    if(d < 30 && d < dmin){
      dmin = d;
      newLegIdx=i;
    }
  }
  if (cur_leg_id != newLegIdx){
    setDisplay(String(nav_legs[newLegIdx].maneuver));
    cur_leg_id = newLegIdx;
  }
}

double distance(const double lat,const double lon,const double t_lat,const double t_lon) {
  /*  Haversine Formula */
  double phi1  = lat/180*3.14159;
  double phi2  = t_lat/180*3.14159;
  double d_phi = phi1-phi2;
  double d_lam   = (lon-t_lon)/180*3.14;
  double a = sin(d_phi/2) * sin(d_phi/2) + cos(phi1) * cos(phi2) * sin(d_lam/2) * sin(d_lam/2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  return Radius * c;
}

void endNav(){
  delete[] nav_legs;
}
