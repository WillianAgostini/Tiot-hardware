var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://broker.hivemq.com')

client.on('connect', function() {
  let interval = {min: 3, max: 6};
  console.log('connect');

  // setInterval(
  //     () => {client.publish('caveira/action', JSON.stringify(interval))},
  //     3000);
  // client.publish('caveira/action', JSON.stringify(interval));
  // client.subscribe('caveira');
  // client.subscribe('caveira/min');
  // client.subscribe('caveira/max');
  client.subscribe('tcc/drone/#');

  // setInterval(() => client.publish('caveira', '12'), 3000);
})

client.on('message', function(topic, message) {
  // message is Buffer
  console.log(topic, message.toString());
})
