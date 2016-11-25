#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>

#define IRQ   (2)
#define RESET (3)  

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

void setup(void) {
  Serial.begin(115200);
  Serial.println(">http://www.github.com/awangga/NFCReader");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print(">Didn't find PN53x board, please close and open serial monitor. If problem still exist please check your wiring");
    while (1); // halt
  }
  
  // Got ok data, print it out!
  Serial.print(">Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print(">Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  //nfc.setPassiveActivationRetries(0xFF);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
    
  //Serial.println("Waiting for an ISO14443A card");
}

void loop(void) {
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) {
    //Serial.println("Found a card!");
    //Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    //Serial.print("UID Value: ");
    nfc.PrintHex(uid, uidLength);
    uint8_t keya[6] = { 0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7 };
    success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
    //if (success)
    //{
    //  Serial.println("Authentication work");
    //}
    //uint8_t data[16];
    uint8_t data[16];
    success = nfc.mifareclassic_ReadDataBlock(4, data);
    //success = nfc.mifareultralight_ReadPage (32, data);
    nfc.PrintHexChar(data, 16);
    // Wait 1 second before continuing
    delay(1000);
  }

}
