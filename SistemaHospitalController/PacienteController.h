#pragma once

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class PacienteController {

	public:
		PacienteController();
		List<Paciente^>^ listarPacientes();
		Paciente^ buscarPacienteById(int idPaciente);
	};
}