var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://broker.mqtt-dashboard.com')

client.on('connect', function() {
  setInterval(() => {client.publish('caveira/action', '1')}, 1000);
})

client.on('message', function(topic, message) {
  // message is Buffer
  console.log(message.toString())
  client.end()
})

function randomInt(low, high) {
  return (Math.floor(Math.random() * (high - low) + low)).toString()
}