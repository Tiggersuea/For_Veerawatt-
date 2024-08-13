void Pid() {
  error = setpoint - position;
  
//  if (abs(error) > 2800) {
//    KP = 0.0204;
//    KD = 0.19;
//  } else {
//    // KP and KD remain unchanged
//  }

  integral += error;
  differencial = (error * KP) + ((error - Last_error) * KD) + (integral * KI);
  Last_error = error;

  Lmotor = sp + differencial;
  Rmotor = sp - differencial;

  if (Lmotor > (sp + 35)) Lmotor = sp + 35;
  else if (Lmotor < -30) Lmotor = -30;

  if (Rmotor > (sp + 35)) Rmotor = sp + 35;
  else if (Rmotor < -30) Rmotor = -30;

  motor(1, Rmotor);
  motor(2, Lmotor);
}
