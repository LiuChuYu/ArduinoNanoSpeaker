int buzzer = 17;
int GND = 14;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW);
}
void loop() {
  int tone_arr[] = {
    /* 1-C  2-D  3-E  4-F  5-G  6-A  7-B */
    0, 131, 147, 165, 175, 196, 220, 247, 0, 0,
    0, 261, 294, 330, 349, 392, 440, 494, 0, 0,
    0, 533, 587, 659, 699, 784, 880, 988, 0, 0,
  };
  /*little star melody
    int melody[] = {
    11, 11, 15, 15,
    16, 16, 15, -1,

    14, 14, 13, 13,
    12, 12, 11, -1,

    15, 15, 14, 14,
    13, 13, 12, -1,

    15, 15, 14, 14,
    13, 13, 12, -1,

    11, 11, 15, 15,
    16, 16, 15, -1,

    14, 14, 13, 13,
    12, 12, 11, -1,
    };
    int tempo = 500;
    /* little star end */
  /* edelweiss melody */
  int melody[] = {
    13, -1, 15,
    22, -1, -1,
    14, -1, -1,
    13, -1, 13,
    13, 14, 15,

    16, -1, -1,
    15, -1, -1,
    13, -1, 15,
    22, -1, -1,
    21, -1, 15,

    14, -1, -1,
    13, -1, 15,
    15, 16, 17,
    21, -1, -1,
    21, -1, -1,

    22, -2, 15, 15,
    13, -1, 15,
    21, -1, -1,
    16, -1, 21,
    22, -1, 21,

    17, -1, -1,
    15, -1, -1,
    13, -1, 15,
    22, -1, -1,
    21, -1, 15,

    14, -1, -1,
    13, -1, 15,
    15, 16, 17,
    21, -1, -1,
    21, -1, -1,
  };
  int tempos = 900;
  /* edelweiss end */
  int tempo = tempos;
  for (int i = 0; i < (sizeof(melody) / sizeof(int)); i++) {
    int tone_no = melody[i];
    /* debug */
    Serial.print("i=");
    Serial.print(i);
    Serial.print(",tone_no=");
    Serial.println(tone_no);
    /* end debug */
    if (melody[i] > 0) {
      noTone(buzzer);
      delay(50);
      tone(buzzer, tone_arr[tone_no]);
      delay(tempo - 50);
      tempo = tempos;
    } else if (melody[i] == 0) {
      noTone(buzzer);
      delay(tempo);
    } else if (melody[i] == -2) {
      tempo = tempos / 2;
      delay(tempo);
    } else {
      switch (melody[i]) {
        case 0:
          noTone(buzzer);
          delay(tempo);
          break;
        case -1:
          delay(tempo);
          break;
        case -2:
          tempo = tempos / 2;
          delay(tempo);
          break;
      }
    }
  }
  noTone(buzzer);
  delay(2000);
}
