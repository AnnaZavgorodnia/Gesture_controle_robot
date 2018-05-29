void Motors_set() {
  pinMode (ENA, OUTPUT);  //ШИМ выход 1
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB, OUTPUT);  //ШИМ выход 2
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void Motors_init(byte CURR_MODE) {
   switch (CURR_MODE) {
    case Off: {
          /* Not realized! */
        break;
    }
    case HandControl: {
      IN1 = 5; // !
      IN2 = 8;
      IN3 = 7;
      IN4 = 4;
      
      ENA = 10;  // ШИМ выход 1 // !
      ENB = 6;  // ШИМ выход 2

      Motors_set();
      break;
    }
    case Detour: {
      IN1 = 12; // 12 -> 5
      IN2 = 8;
      IN3 = 7;
      IN4 = 4;
      
      ENA = 11;  //ШИМ выход 1 // !
      ENB = 6;  //ШИМ выход 2
      
      Motors_set();
     break;
    }
    case Record: {
       /* Not realized! */   
      break;
    }
    }
}

