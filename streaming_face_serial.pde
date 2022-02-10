import gab.opencv.*;
import processing.video.*;
import java.awt.Rectangle;
import ipcapture.*;
import processing.serial.*;

IPCapture cam;
OpenCV opencv;
Rectangle[] faces;
Serial Port;

void setup(){
  size(320, 240);
  
  String[] cameras = Capture.list();
  
  for(int i=0; i<cameras.length; i++){
    println("[" + i + "] " + cameras[i]);
  }
  
  cam = new IPCapture(this, "http://192.168.1.1:8080/?action=stream", "", "");
  cam.start();
  
  
  //String portName = Serial.list()[0];
  //println(Serial.list());
  // Change the portname as your PC
  Port = new Serial(this, "COM4", 9600);
  Port.bufferUntil(10);
}

void draw(){
  if(cam.isAvailable() == true){
    cam.read();
    
    image(cam, 0, 0);
 
    opencv = new OpenCV(this, cam);
    opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);
    faces = opencv.detect();
   
    if(faces.length != 0){
      Port.write(49);
      print(1);
    }
    if(faces.length == 0){
      Port.write(48);
      print(0);
    }
    
    for(int i=0; i<faces.length; i++){
      stroke(#ff0000);
      noFill();
      rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
    }
  }
}
