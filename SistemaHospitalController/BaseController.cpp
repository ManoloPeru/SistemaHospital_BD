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
	this->objConexion->ConnectionString = "Server=localhost;DataBase=lpoo_2024_2;User id=sa;Password=Passw0rd";
	/*Paso 2, abrir la conexion*/
	this->objConexion->Open();
}

void BaseController::cerrarConexion() {
	this->objConexion->Close();
}