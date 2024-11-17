#pragma once

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class CitaController {

	public:
		CitaController();
		List<Cita^>^ listarCitas();
		Cita^ buscarCitaById(int idCita);
		List<Cita^>^ listarCitasByFecha(int fecha);
	};
}