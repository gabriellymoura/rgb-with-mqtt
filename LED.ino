
void defineCor(int pwmRed, int pwmGreen, int pwmBlue){
  //setColor(pwmRed,pwmGreen,pwmBlue);
  /*
    if (msg == "1"){
      digitalWrite(Rele1, HIGH);
    }else if (msg == "2"){
      digitalWrite(Rele1, LOW);
    }else if (msg == "3"){
      digitalWrite(Rele2, HIGH);
    }else if (msg == "4"){
      digitalWrite(Rele2, LOW);
    }else if(msg == "5"){
      digitalWrite(Rele3, HIGH);
    }else if(msg == "6"){
      digitalWrite(Rele3, LOW);
    }else if (msg == "restart"){
      ESP.reset();
    }*/
}

void setColor(int vermelho, int verde, int azul){
  analogWrite(Rele1, vermelho); //
  analogWrite(Rele2, verde);
  analogWrite(Rele3, azul);
  

  
}
