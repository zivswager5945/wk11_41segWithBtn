byte btn, pins[7]={13,12,11,10,9,8,7};
byte show[16][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0}, 
  {0,0,0,1,0,0,0},
  {1,1,0,0,0,0,0},
  {0,1,1,0,0,0,1},
  {1,0,0,0,0,1,0},
  {0,1,1,0,0,0,0},
  {0,1,1,1,0,0,0},
};

void setup()
{
  for  (byte i=0;i<7;++i){
  pinMode (pins[i],OUTPUT);
  }
  pinMode(6,INPUT_PULLUP);
}

void loop()
{
  for(int i=0; i<160;i++){
    delay(50);
    for (byte j=0;j<7;j++){
      btn=digitalRead(6);
      if (btn==HIGH){
        for(byte j=0;j<7;j++);{
        digitalWrite(pins[j],1);
      }
    }
    else{
      for (byte j=0;j<7;j++){
        digitalWrite(pins[j],show[(i/10)][j]);
      }
    }
  }
}
}
