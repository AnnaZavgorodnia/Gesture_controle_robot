byte scan(byte direction_scan, int wait_timeee) {
  int dirrr = distance_by_direction(direction_scan, wait_timeee);
  if (dirrr < critical_distance) {
    return NONE;
  } else if (dirrr < very_close_distance) {
    return CRITICAL;
  } else if (dirrr < close_distance) {
    return VERY_CLOSE;
  } else if (dirrr < average_distance) {
    return CLOSE;
  } else if (dirrr < average_distance) {
    return AVERAGE;
  } else return LONG_AWAY;
}

int distance_by_direction(byte some_direction, int wait_time) {
  switch(some_direction) {
    case Forward: {
        return distance_at_angle(FORWARD_ANGLE, wait_time);
    }
    case Left: {
        return distance_at_angle(LEFT_ANGLE, wait_time);
    }
    case Right: {
        return distance_at_angle(RIGHT_ANGLE, wait_time);
    }
    case Forward_Left: {
        return distance_at_angle(FORWARD_LEFT_ANGLE, wait_time);
    }
    case Forward_Right: {
        return distance_at_angle(FORWARD_RIGHT_ANGLE, wait_time);
    }
    case Backward: {
        return distance_backward();
    }
    default: return 0;
  }
}

int distance_at_angle(byte angle, int wait_time) {  
  servo.write(angle);
  delay(wait_time);
  return main_scaner.Ranging(CM);
}

int distance_backward() {
  // return back_scaner.Ranging(CM); /* Not works correctly! Some errors with sensor. */
  return 500; // LONG_AWAY backward distance // always Ok!
}

