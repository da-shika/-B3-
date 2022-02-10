import gab.opencv.*;
import processing.video.*;
import java.awt.Rectangle;
import ipcapture.*;

IPCapture cam;
OpenCV opencv;
Rectangle[] faces;

void setup(){
  size(320, 240);
  
  String[] cameras = Capture.list();
  
  for(int i=0; i<cameras.length; i++){
    println("[" + i + "] " + cameras[i]);
  }
  
  cam = new IPCapture(this, "http://192.168.1.1:8080/?action=stream", "", "");
  cam.start();
}

void draw(){
  if(cam.isAvailable() == true){
    cam.read();
    
    image(cam, 0, 0);
 
    opencv = new OpenCV(this, cam);
    opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);
    faces = opencv.detect();
    
    print(faces.length);
    
    for(int i=0; i<faces.length; i++){
      stroke(#ff0000);
      noFill();
      rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
    }
  }
}
