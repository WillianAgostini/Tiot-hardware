var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://192.168.1.30')

client.on('connect', function() {
  let interval = {min: 4, max: 8};

  // setInterval(
  //     () => {client.publish('caveira/action', JSON.stringify(interval))},
  //     3000);
  client.publish('caveira/action', JSON.stringify(interval));
  client.subscribe('caveira/action');
  client.subscribe('caveira');
  client.subscribe('caveira/min');
  client.subscribe('caveira/max');
})

client.on('message', function(topic, message) {
  // message is Buffer
  console.log(topic, message.toString());
  if ('caveira/interval' != topic) return;


  console.log('-----');
})
