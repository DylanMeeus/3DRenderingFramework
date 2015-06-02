#include "Camera.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "util/Quaternion.h"

Camera::Camera(AppConfiguration& appCfg){
	eye.x = std::atof(appCfg["camera.eye.x"].c_str());
	eye.y = std::atof(appCfg["camera.eye.y"].c_str());
	eye.z = std::atof(appCfg["camera.eye.z"].c_str());

	look.x = std::atof(appCfg["camera.look.x"].c_str());
	look.y = std::atof(appCfg["camera.look.y"].c_str());
	look.z = std::atof(appCfg["camera.look.z"].c_str());

	upV.x = std::atof(appCfg["camera.up.x"].c_str());
	upV.y = std::atof(appCfg["camera.up.y"].c_str());
	upV.z = std::atof(appCfg["camera.up.z"].c_str());

	distance = std::atof(appCfg["camera.worldwindow.distance"].c_str());
    width = std::atof(appCfg["camera.worldwindow.width"].c_str());
   //
    height = std::atof(appCfg["camera.worldwindow.height"].c_str());
   // implement uvn
    // n = eye - look.
    n = Vector(look,eye);
    n.normalize();
    u = upV.cross(n);
    u.normalize();
    v = n.cross(u);
}

void Camera::forward()
{
eye.z--;
}

void Camera::backward()
{
eye.z++;
}

void Camera::up()
{
   std::cout << "up" << std::endl;
   Quaternion p = Quaternion(eye);
   Quaternion q = Quaternion(-1,u);
   Quaternion paccent = q*p*q.conjugate();
   eye.x = paccent.b, eye.y = paccent.c; eye.z = paccent.d;
   n = Vector(look,eye);
   n.normalize();
   v = n.cross(u);
}


void Camera::down()
{
	std::cout << "down" << std::endl;
   Quaternion p = Quaternion(eye);
   Quaternion q = Quaternion(1,u);
   Quaternion paccent = q*p*q.conjugate();
   eye.x = paccent.b, eye.y = paccent.c; eye.z = paccent.d;
   n = Vector(look,eye);
   n.normalize();
   v = n.cross(u);
}

void Camera::left() // left moet u en n aanpassen, niet v.
{
	   Quaternion p = Quaternion(eye);
	   Quaternion q = Quaternion(-1,v);
	   Quaternion paccent = q*p*q.conjugate();
	   eye.x = paccent.b, eye.y = paccent.c; eye.z = paccent.d;
	   n = Vector(look,eye);
	   n.normalize();
	   u = v.cross(n);
	 //  u.normalize();
}

void Camera::right()
{
	   Quaternion p = Quaternion(eye);
	   Quaternion q = Quaternion(1,v);
	   Quaternion paccent = q*p*q.conjugate();
	   eye.x = paccent.b, eye.y = paccent.c; eye.z = paccent.d;
	   n = Vector(look,eye);
	   n.normalize();
	   u = v.cross(n);
}
