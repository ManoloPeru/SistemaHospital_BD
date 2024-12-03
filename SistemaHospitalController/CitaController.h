#pragma once
#include "BaseController.h"

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class CitaController : public BaseController {

	public:
		CitaController();
		List<Cita^>^ listarCitas();
		Cita^ buscarCitaById(int idCita);
		List<Cita^>^ listarCitasByFecha(int fecha);

		//BD
		List<Cita^>^ selectCita(String^ fecha);
		void insertCita(int idPaciente, int idMedico, String^ fecha, String^ hora);
	};
}