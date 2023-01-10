#include <SpresenseNeoPixel.h>

const uint16_t PIN = 3;
const uint16_t NUM_PIXELS = 58;
SpresenseNeoPixel<PIN, NUM_PIXELS> neopixel;

void setup()
{
    Serial.begin(115200);
    neopixel.clear();
    neopixel.framerate(60); //デフォルトだと40みたい

    delay(1);
}

void loop()
{
static uint32_t prev_ms = millis();
static uint8_t state = 0;
if (millis() > prev_ms + 15) //ここの値を変更することで光の速さを変えることができるので先生が変更してみてください。
{
for (int i = 0; i < NUM_PIXELS; i++) {
// 七色の光を設定
if (i == state) {
neopixel.set(i, 255, 0, 0); //赤
}
else if (i == (state + 1) % NUM_PIXELS) {
neopixel.set(i, 255, 165, 0); //オレンジ
}
else if (i == (state + 2) % NUM_PIXELS) {
neopixel.set(i, 255, 255, 0); //黄
}
else if (i == (state + 3) % NUM_PIXELS) {
neopixel.set(i, 0, 255, 0); //緑
}
else if (i == (state + 4) % NUM_PIXELS) {
neopixel.set(i, 0, 0, 255); //青
}
else if (i == (state + 5) % NUM_PIXELS) {
neopixel.set(i, 75, 0, 130); //紫
}
else if (i == (state + 6) % NUM_PIXELS) {
neopixel.set(i, 238, 130, 238); //シアン
}
else {
neopixel.set(i, 0, 0, 0); //消灯
}
}
state = (state + 1) % NUM_PIXELS;
prev_ms = millis();
}
neopixel.show();
}