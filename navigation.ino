void setupNav(const int len, const char* str){
  char * pEnd; 
  pEnd = strtok (str," ,");
  len = strtol (pEnd, &pEnd, 10);
  pEnd = strtok (NULL," ,");
  nav_legs = new NavLeg[len];
  double v;
  for(int i=0;i<l;++i){
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
  if (len < 0) return;
  GPS_receive();
  double dmin = distance(latitude, longitude, nav_legs[0].e_lati, nav_legs[0].e_long);
  int newLegIdx=0;
  for (int i=1;i<len;++i){
    d = distance(latitude, longitude, nav_legs[i].e_lati, nav_legs[i].e_long)
    if(d < dmin){
      dmin = d;
      newLegIdx=i;
    }
  }
  if (cur_leg_id newLegIdx;
}

double distance(double x,double y,double t_x,double t_y) 
{ return pow(pow(x - t_x,2) + pow(t_y - y,2) , 0.5); }

void endNav(){
  delete[] nav_legs;
}
