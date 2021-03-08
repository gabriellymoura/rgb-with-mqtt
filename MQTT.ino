void initMQTT() 
{
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(mqtt_callback);

}

void mqtt_callback(char* topic, byte* payload, unsigned int length){
    String msg;
        //obtem a string do payload recebido
    
    for(int i = 0; i < length; i++) {
       char c = (char)payload[i];
       msg += c;
    } 

    StringSplitter *splitter = new StringSplitter(msg, ',', 3);  // new StringSplitter(string_to_split, delimiter, limit)
    int itemCount = splitter->getItemCount();
    //Serial.println("Item count: " + String(itemCount));

    String item[itemCount];

    for(int i = 0; i < itemCount; i++){
      item[i] = splitter->getItemAtIndex(i);
    //Serial.println("Item @ index " + String(i) + ": " + String(item));
    }
    

    int pwmRed = map(item[0].toInt(),0,1023,0,255);
    int pwmGreen = map(item[1].toInt(),0,1023,0,255);
    int pwmBlue = map(item[2].toInt(),0,1023,0,255);

    Serial.print("Mensagem Recebida: ");
    Serial.println(msg);    
    Serial.print("RGB: ");
    Serial.println(String(pwmRed) +","+String(pwmGreen)+ "," +String(pwmBlue));

    
    setColor(pwmRed, pwmGreen, pwmBlue);
    
  
}
