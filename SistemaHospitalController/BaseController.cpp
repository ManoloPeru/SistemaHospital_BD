#include "BaseController.h"

using namespace SistemaHospitalController;
using namespace System::IO;

BaseController::BaseController() {
	this->objConexion = gcnew SqlConnection();
}

SqlConnection^ BaseController::getObjConexion() {
	return this->objConexion;
}

void BaseController::abrirConexion() {
	/*Paso 1, establecer la cadena de conexion*/
	/*Local*/
	this->objConexion->ConnectionString = "Server=localhost;DataBase=lpoo_2024_2;User id=sa;Password=Passw0rd";
	/*AWS*/
	//this->objConexion->ConnectionString = "Server=lpoo2024.c1uehfrpd23g.us-east-1.rds.amazonaws.com;DataBase=lpoo2024;User id=lpoo2024;Password=Passw0rd2024#";
	/*Paso 2, abrir la conexion*/
	this->objConexion->Open();
}

void BaseController::cerrarConexion() {
	this->objConexion->Close();
}