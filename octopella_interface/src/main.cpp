#include <Arduino.h>

typedef enum {
  CMD_VOLUME_UP = 3,
  CMD_VOLUME_DOWN = 4,
  CMD_PLAY = 5,
  CMD_PAUSE = 6,
  CMD_KEY = 7,
  CMD_BEAT_SELECT = 8,
  CMD_VOICE_SELECT = 9,
} cmd_id_t;

void cmd_send(cmd_id_t cmd_id, uint8_t value){
  uint8_t const command[2] = {(uint8_t)cmd_id, value};
  Serial.write(command, 2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  cmd_send(CMD_VOLUME_UP, 0);
  delay(500);
  cmd_send(CMD_BEAT_SELECT, 45u);
}