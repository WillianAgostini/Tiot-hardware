var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://191.52.140.35')

client.on('connect', function() {
  let interval = {min: 3, max: 6};
  console.log('connect');

  // setInterval(
  //     () => {client.publish('caveira/action', JSON.stringify(interval))},
  //     3000);
  client.publish('caveira/action', JSON.stringify(interval));
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
