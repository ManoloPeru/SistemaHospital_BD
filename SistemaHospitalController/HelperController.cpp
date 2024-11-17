#include "HelperController.h"

using namespace SistemaHospitalController;
using namespace System::IO;

HelperController::HelperController() {
	this->sMensaje = "";
}

String^ HelperController::pathBin(String^ pathExe) {
	// Obtiene la ruta de ejecuci�n
	// String^ rutaEjecucion = Application::StartupPath;
	// Navega hacia la carpeta padre dos niveles arriba para eliminar "x64\Debug"
	String^ rutaBase = Directory::GetParent(Directory::GetParent(pathExe)->FullName)->FullName;
	// A�ade la subcarpeta "bin"
	String^ rutaFinal = Path::Combine(rutaBase, "bin\\");
	return rutaFinal;
}

//Metodos Personales
String^ HelperController::imprimirFechaByInt(int iFecha) {
	// Extraer a�o, mes y d�a
	int anio = iFecha / 10000;
	int mes = (iFecha / 100) % 100;
	int dia = iFecha % 100;
	return String::Format("{0:D2}/{1:D2}/{2}", dia, mes, anio);
}

int HelperController::dateTimeTointFecha(DateTime dFecha) {
	// Extraer a�o, mes y d�a
	int iFecha = dFecha.Year * 10000 + dFecha.Month * 100 + dFecha.Day;
	return  iFecha;
}

DateTime HelperController::intFechaToDateTime(int iFecha) {
	// Extraer a�o, mes y d�a
	int anio = iFecha / 10000;
	int mes = (iFecha / 100) % 100;
	int dia = iFecha % 100;
	DateTime fecha = DateTime(anio, mes, dia);
	return  fecha;
}