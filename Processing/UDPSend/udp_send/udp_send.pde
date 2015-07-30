// import UDP library
import hypermedia.net.*;

UDP udp;  // define the UDP object

String ip       = "192.168.1.72";  // the remote IP address
int port        = 5683;    // the destination port

void setup() {
  size(100, 100);
  // create a new datagram connection on port 6000
  // and wait for incomming message
  udp = new UDP( this, 6000 );
  //udp.log( true ); 		// <-- printout the connection activity
}

//process events
void draw() {
  int num = int(map(mouseX, 1, 100, 0, 255));
  println(num);
  udp.send( str(num), ip, port );
}

