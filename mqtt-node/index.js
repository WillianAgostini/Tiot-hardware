var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://broker.mqtt-dashboard.com')

client.on('connect', function() {
  setInterval(() => {client.publish('caveira/action', '10-50')}, 1000);
  // setInterval(() => {client.publish('caveira/action/min', '1')}, 1000);
  client.subscribe('caveira');
  client.subscribe('caveira/interval');
})

client.on('message', function(topic, message) {
  // message is Buffer
  console.log(topic);
  if ('caveira/interval' != topic) return;


  console.log('-----');
})

function randomInt(low, high) {
  return (Math.floor(Math.random() * (high - low) + low)).toString()
}