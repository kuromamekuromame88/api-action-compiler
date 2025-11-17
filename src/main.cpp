
#include <Arduino.h>
#include <driver/i2s.h>
#include <BluetoothA2DPSink.h>

// Define I2S pins for audio output
#define I2S_BCK_PIN  26  // Bit Clock (BCK)
#define I2S_WS_PIN   25  // Word Select (WS)
#define I2S_DOUT_PIN 27  // Data Output (DOUT)

BluetoothA2DPSink a2dpSink;

void setup() {
  Serial.begin(115200);
  Serial.println("Bluetooth Speaker");
  
  // Initialize I2S audio output
  i2s_pin_config_t pinConfig = {
    .bck_io_num = I2S_BCK_PIN,
    .ws_io_num = I2S_WS_PIN,
    .data_out_num = I2S_DOUT_PIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  
  // Set up Bluetooth A2DP sink
  a2dpSink.set_pin_config(pinConfig);
  a2dpSink.start("有線イヤホン");
  Serial.println("Device name: 有線イヤホン");
}

void loop() {
  // Main loop, nothing specific needed here
}
