#pragma once
#pragma once
namespace SistemaHospitalController {
	using namespace System;
	
	public ref class HelperController {
	private:
		String^ sMensaje;

	public:
		HelperController();
		String^ pathBin(String^ pathExe);
		//Metodos Personales
		String^ imprimirFechaByInt(int iFecha);
		int dateTimeTointFecha(DateTime dFecha);
		DateTime intFechaToDateTime(int iFecha);
		
	};
}